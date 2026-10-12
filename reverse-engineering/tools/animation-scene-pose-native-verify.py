"""Isolate original x86 scene pose consumer and trig initialization, never the game."""
from pathlib import Path
_base=Path(__file__).resolve().parent
exec((_base/'animation-scene-native-verify.py').read_text().split('inventory=json.loads')[0])
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
dis=Cs(CS_ARCH_X86,CS_MODE_32)
(BASE/'reports/animation-scene-pose-native-assembly.txt').write_text('\n'.join(f'{i.address:08x}: {i.mnemonic} {i.op_str}' for a,n in [(0x5bdd50,100),(0x5ea390,250)] for i in dis.disasm(bytes(mu.mem_read(a,n)),a)))
mu.context_restore(context);sp=STACK+0xf000;mu.mem_write(sp,struct.pack('<I',STOP));mu.reg_write(UC_X86_REG_ESP,sp)
mu.emu_start(0x5bdd50,STOP,count=20000000)
if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('trig initialization instruction budget')
trig=bytes(mu.mem_read(0x29899a0,32768*4));(BASE/'references/native-animation-sine-table.f32').write_bytes(trig)
table=struct.unpack('<32768f',trig)
report={'binarySha256':hashlib.sha256(blob).hexdigest(),'trigTableSha256':hashlib.sha256(trig).hexdigest(),'radiansToAngleMultiplier':struct.unpack('<d',mu.mem_read(0x755d18,8))[0],'tableAngleStep':struct.unpack('<d',mu.mem_read(0x7640a8,8))[0],'trigInitialization':'Original 0x5bdd50 and original math callees; no OS imports, scratch stack and mapped PE only.','trigComparedToIdealMaxAbsoluteError':max(abs(v-math.sin(i*2*math.pi/32768))for i,v in enumerate(table)),'procedure':'0x5ea390','samples':0,'matrixScalars':0,'mismatches':0,'maxAbsoluteError':0,'maxNormalizedError':0,'examples':[],'failures':[]}
(BASE/'reports/animation-scene-trig-native.json').write_text(json.dumps(report,indent=2))
print('Original trig table',report['trigTableSha256'],'max ideal error',report['trigComparedToIdealMaxAbsoluteError'],flush=True)
if '--trig-only'in sys.argv:sys.exit(0)
mu.mem_write(0x973880,struct.pack('<I',BUF));mu.mem_write(BUF+8,struct.pack('<I',OUT));MATRIX=BUF+0x4000
cases=json.loads((BASE/'reports/animation-scene-pose-cases.json').read_text());current=None
for case in cases:
 try:
  if case['source']!=current:
   current=case['source'];raw=(BASE/'extracted'/current).read_bytes()
  h=case['header'];off=case['sourceOffset'];prepare(raw[off:off+h['flagsOffset']+h['nodeCount']+16]);mu.context_restore(context)
  mu.mem_write(OUT,bytes(36));mu.mem_write(MATRIX,bytes(64));sp=STACK+0xf000
  mu.mem_write(sp,struct.pack('<IIIfI',STOP,DATA,0,case['frame']+1,MATRIX));mu.reg_write(UC_X86_REG_ESP,sp)
  mu.emu_start(0x5ea390,STOP,count=1000000)
  if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('instruction budget')
  actual=struct.unpack('<16f',mu.mem_read(MATRIX,64));report['samples']+=1
  for i,(a,e)in enumerate(zip(actual,case['matrix'])):
   err=abs(a-e);report['maxAbsoluteError']=max(report['maxAbsoluteError'],err);report['matrixScalars']+=1;report['maxNormalizedError']=max(report['maxNormalizedError'],err/max(1,abs(a),abs(e)))
   # Scalar compression may differ a float ulp at angle quantization boundaries.
   tol=0.00002*max(1,abs(a),abs(e))
   if not math.isfinite(a)or err>tol:
    report['mismatches']+=1
    if len(report['examples'])<40:report['examples'].append({'source':current,'animationIndex':case['animationIndex'],'frame':case['frame'],'component':i,'expected':e,'actual':a,'error':err})
 except Exception as e:report['failures'].append({'source':current,'animationIndex':case['animationIndex'],'error':str(e),'eip':hex(mu.reg_read(UC_X86_REG_EIP))})
report['limits']=['Bounded sample times, not every frame or state.','Matrix tolerance 0.00002*max(1,abs(expected),abs(actual)) covers scalar rounding near quantized angle boundaries.','Native matrix consumer does not include special-object base translation addition, script state or visibility.']
(BASE/'reports/animation-scene-pose-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
