"""Differential check against isolated original PC ATS compiler/evaluator code.

Does not start the game or Windows APIs. Parser integer reads are supplied by
hooks for compiler tests; original RNG executes for seeded traces.
"""
import importlib.util,json,struct,re
from pathlib import Path
root=Path('reverse-engineering').resolve()
spec=importlib.util.spec_from_file_location('native_x86',root/'tools/native-x86.py')
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
n=native.NativeX86();program=n.DATA;env=n.DATA+0x4000;material=n.DATA+0x5000;texids=n.DATA+0x6000
def u32(p):return n.unpack('<I',p)[0]
def string(p):return n.read(p,64).split(b'\0',1)[0].decode('ascii')
table={}
for i in range(32):
    name,fn=n.unpack('<II',0x80b620+i*8)
    if not name:break
    table[string(name)]=fn
parser_values=[]
def parser_hook(mu,address,size,user):
    if not parser_values:raise RuntimeError('Unexpected native parser read')
    sp=mu.reg_read(UC_X86_REG_ESP);ret=u32(sp)
    mu.reg_write(UC_X86_REG_EAX,parser_values.pop(0)&0xffffffff)
    mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,parser_hook,begin=0x4f9e70,end=0x4f9e70)
# Do not patch executable bytes: a conditional hook bypasses minimum-bound RNG.
# Seeded mode executes the original instructions and mutates the native state.
current_random='minimum'
def rng_hook(mu,address,size,user):
    if current_random=='minimum':
        sp=mu.reg_read(UC_X86_REG_ESP);ret=u32(sp)
        mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,rng_hook,begin=0x5b9e90,end=0x5b9e90)
events=[];tick=0;last=-1
def texture_write(mu,access,address,size,value,user):
    global last
    if value!=last:events.append({'tick':tick,'texture':value});last=value
n.mu.hook_add(UC_HOOK_MEM_WRITE,texture_write,begin=material+0x74,end=material+0x75)
programs=json.loads((root/'reports/geometry-texture-programs.json').read_text(encoding='utf-8'))['programs']
compiler_checks=[];checks=[];errors=[];total_ticks=0
for row in programs:
    p=json.loads((root/row['output']).read_text(encoding='utf-8'))
    for source in p['sourceLines']:
        tokens=re.split(r'[\s,]+',source['text'].strip());command=tokens[0].lower()
        if command not in ('rate','wait'):continue
        args=[int(x) for x in tokens[1:]];args=(args+[0,0])[:2];parser_values[:]=args
        n.write(program,b'\0'*0x1000);n.pack('<I',0x971580,program)
        n.call(table[command],[0])
        actual=list(n.unpack('<hhh',program+0x1ba));expected=p['instructions'][source['wordOffset']:source['wordOffset']+3]
        compiler_checks.append({'program':p['name'],'line':source['line'],'command':command,'arguments':args,'nativeWords':actual,'decodedWords':expected,'pass':actual==expected})
    for scenario in p['scenarios']:
        if scenario['random'] not in ('minimum','native-seeded'):continue
        current_random=scenario['random']
        n.pack('<I',0x96e56c,scenario.get('seed',1))
        n.write(program,b'\0'*0x1000);n.write(env,b'\0'*0xec);n.write(material,b'\0'*0x2c4)
        n.pack('<'+'h'*len(p['instructions']),program+0x1ba,*p['instructions']);n.pack('<h',program+0x1b4,len(p['instructions']));n.pack('<H',program+0x1b8,p['mask'])
        for side,offset,maskoff in [('on',0x28,0x128),('off',0xa8,0x12c)]:
            mask=0
            for sig,pc in p[side].items():n.pack('<I',program+offset+int(sig)*4,pc);mask|=1<<int(sig)
            n.pack('<I',program+maskoff,mask)
        n.pack('<I',env,program);n.pack('<III',env+0xdc,material,texids,0)
        for i in range(512):n.pack('<H',texids+i*2,i)
        n.pack('<H',0x9736e4,0xffff);n.pack('<I',0x963f50,scenario['frameTicks'])
        events=[];last=-1
        signal=re.search(r'(?:signal|off)_(\d+)_',scenario['name']);sig=int(signal[1]) if signal else None
        for tick in range(scenario['ticks']):
            n.pack('<I',0x96d8f4,(1<<sig) if sig is not None and tick==10 else 0)
            n.pack('<I',0x96e534,(1<<sig) if sig is not None and scenario['name'].startswith('off_') and tick==500 else 0)
            n.call(0x5d2d10,[env],count=10000);total_ticks+=1
        pc=u32(env+4);passed=events==scenario['events'] and pc==scenario['finalPC']
        if scenario['random']=='native-seeded':passed=passed and u32(0x96e56c)==scenario['finalRandomState']
        record={'program':p['name'],'scenario':scenario['name'],'ticks':scenario['ticks'],'events':len(events),'finalPC':pc,'random':scenario['random'],'finalRandomState':u32(0x96e56c) if scenario['random']=='native-seeded' else None,'pass':passed}
        if not passed:record.update(expectedEvents=scenario['events'],actualEvents=events,expectedPC=scenario['finalPC'])
        checks.append(record)
    print(json.dumps({'program':p['name'],'compilerChecks':len(compiler_checks),'scenarios':len(checks),'ticks':total_ticks}),flush=True)
report={'executableSHA256':n.sha256,'scope':'Isolated original PC instructions; no game/OS execution. Native integer parser hook supplies authored Rate/Wait arguments. RNG stub returns zero only for minimum-random boundary scenarios; seeded scenarios execute original 0x5b9e90 and compare complete texture events, final PC and RNG state.',
        'entryPoints':{'programCompiler':'0x5d26d0','evaluator':'0x5d2d10','integerParserHook':'0x4f9e70','rngHook':'0x5b9e90','commandTable':'0x80b620'},
        'commandFunctions':{k:hex(v) for k,v in table.items()},'compilerChecks':compiler_checks,'checks':checks,'totalTicks':total_ticks,
        'passed':all(c['pass'] for c in compiler_checks+checks),'errors':errors}
(root/'reports/geometry-texture-native-validation.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
print(json.dumps({'compilerChecks':len(compiler_checks),'scenarios':len(checks),'totalTicks':total_ticks,'passed':report['passed']}))
