"""Extract original PC context/action registries and validate actual action lookup."""
import importlib.util,json,re,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_MEM,X86_OP_IMM
n=native.NativeX86();BASE=native.BASE
def cstr(p):return n.read(p,128).split(b'\0')[0].decode('ascii')
def evidence(a):
 p=BASE/f'decompiled/corpus/FUN_{a:x}.c';t=p.read_text();return {'function':hex(a),'file':str(p.relative_to(BASE)),'evidenceId':re.search('ev_[a-f0-9]+',t)[0],'sha256':hashlib.sha256(p.read_bytes()).hexdigest()}
cp=n.unpack('<I',0x7fb0e4)[0];ap=n.unpack('<I',0x7fbec8)[0];contexts=[];actions=[];aliases=[]
for i in range(-1,100):
 va=cp+i*16;name,action,flags,parameter=n.unpack('<IiIi',va);contexts.append({'id':i,'name':cstr(name),'address':hex(va),'nameAddress':hex(name),'actionAtImageLoad':action,'flags':flags,'flagsHex':f'0x{flags:08x}','parameter':parameter,'rawHex':n.read(va,16).hex()})
for i in range(-1,233):
 va=ap+i*8;name,flags=n.unpack('<II',va);actions.append({'id':i,'name':cstr(name),'address':hex(va),'nameAddress':hex(name),'flags':flags,'rawHex':n.read(va,8).hex()})
va=0x7fbed0
while True:
 name,index=n.unpack('<Ii',va)
 if not name:break
 aliases.append({'name':cstr(name),'actionId':index,'address':hex(va),'canonicalName':actions[index+1]['name']});va+=8
sourcepath=BASE/'references/opensaga-source/saga-ab97911d162d896d8f4b20e9df8e7d23a2f81557/src/legoapi/characters/motion/move.cpp';source=sourcepath.read_text()
reference_contexts=re.findall(r'\{"([^"]+)",\s*(-?\d+),\s*(0x[0-9a-f]+),\s*(\d+)\}',source[source.index('static CHARACTER_CONTEXT_INFO_s'):source.index('static ACTIONINFO_s')])
reference_actions=re.findall(r'\{"([^"]+)",\s*(0x[0-9a-f]+)\}',source[source.index('static ACTIONINFO_s'):source.index('CHARACTER_CONTEXT_INFO_s *CInfo')])
assert [(r['name'],r['actionAtImageLoad'],r['flags'],r['parameter'])for r in contexts]==[(a,int(b),int(c,16),int(d))for a,b,c,d in reference_contexts]
assert [(r['name'],r['flags'])for r in actions]==[(a,int(b,16))for a,b in reference_actions]
# Save static immediate writes in the actual PC initializer; do not execute it.
decoder=Cs(CS_ARCH_X86,CS_MODE_32);decoder.detail=True
nextfn=min(int(p.stem[4:],16)for p in(BASE/'decompiled/corpus').glob('FUN_*.c')if int(p.stem[4:],16)>0x42e160)
initializers=[]
for ins in decoder.disasm(n.read(0x42e160,nextfn-0x42e160),0x42e160):
 op=ins.operands
 if ins.mnemonic!='mov'or len(op)!=2 or op[0].type!=X86_OP_MEM or op[1].type!=X86_OP_IMM or op[0].mem.base or op[0].mem.index:continue
 address=op[0].mem.disp;value=op[1].imm
 if 0x802814<=address<=0x8028b0 or 0x804bec<=address<=0x804d28:
  iscontext=address<0x804000;rows=contexts if iscontext else actions;match=next((r for r in rows if r['id']==value),None)
  initializers.append({'instructionVA':hex(ins.address),'instructionHex':ins.bytes.hex(),'destinationVA':hex(address),'size':op[0].size,'value':value,'kind':'contextId'if iscontext else'actionId','registryName':match['name']if match else None})
consumers=[]
for p in sorted((BASE/'decompiled/corpus').glob('FUN_*.c')):
 t=p.read_text()
 if '007fb0e4'in t:consumers.append({'function':'0x'+p.stem[4:],'file':str(p.relative_to(BASE)),'lines':[i+1 for i,line in enumerate(t.splitlines())if '007fb0e4'in line]})
SET=n.DATA;TOKEN=SET+0x1000;n.pack('<I',0x29130e4,SET);n.pack('<I',SET+8,233);n.call(0x6306e0,[ap,0x7fbed0])
def expected(name):
 for r in actions[1:]:
  if r['name'].lower()==name.lower():return r['id']
 for r in aliases:
  if r['name'].lower()==name.lower():return r['actionId']
 return -1
tests={'cases':0,'mismatches':0,'examples':[]}
def lookup(name):
 n.write(TOKEN,name.encode('ascii')+b'\0');result=n.call(0x630740,[TOKEN]);result=result if result<0x80000000 else result-0x100000000;tests['cases']+=1
 if result!=expected(name):tests['mismatches']+=1;tests['examples'].append({'name':name,'expected':expected(name),'actual':result})
 return result
for r in actions[1:]+aliases:
 for name in[r['name'],r['name'].upper(),r['name'].swapcase()]:lookup(name)
for name in['','unknown_animation','?','block0','jump_speed_double']:lookup(name)
catalog=json.loads((BASE/'reports/gameplay-catalog/characters.json').read_text());bindings=[]
for config in catalog['configs']:
 for animation in config['animations']:
  name=animation.get('action')
  if name is None:continue
  result=lookup(name);bindings.append({'source':config['source'],'line':animation['line'],'animationName':animation['name'],'actionText':name,'actionId':result,'canonicalAction':actions[result+1]['name']if result>=0 else None,'basis':'original PC name resolver, explicit action directive only'})
report={'binarySha256':n.sha256,'contextPointerVA':'0x7fb0e4','contextTableVA':hex(cp),'contextCount':100,'contextSentinelId':-1,'actionPointerVA':'0x7fbec8','actionTableVA':hex(ap),'actionCount':233,'aliasCount':len(aliases),'contexts':contexts,'actions':actions,'aliases':aliases,'initializerFunction':evidence(0x42e160),'initializerWrites':initializers,'nameResolver':evidence(0x630740),'registration':evidence(0x6306e0),'actionCountEvidence':'FUN_4c9fb0 passes0xe9 as action count to0x630b40; names table begins one8-byte entry after ? sentinel.','referenceComparison':{'source':str(sourcepath.relative_to(BASE)),'sha256':hashlib.sha256(sourcepath.read_bytes()).hexdigest(),'contextRowsExact':len(contexts),'actionRowsExact':len(actions)},'contextConsumers':consumers,'validation':tests,'limitations':['Context actionAtImageLoad is -1 throughout; no runtime mutation of that field is assumed.','Context flags and parameter bits are retained raw; only separately traced consumers assign behavior.','Registry indices do not prove every context is reachable or every action has a clip for a given character.','Catalog action bindings include only explicit action directives; omitted/default directives and configuration replacement rules are separate.']}
(BASE/'reports/animation-context-registry.json').write_text(json.dumps(report,indent=2));(BASE/'reports/animation-context-action-bindings.json').write_text(json.dumps({'binarySha256':n.sha256,'records':bindings,'matched':sum(r['actionId']>=0 for r in bindings),'unmatched':sum(r['actionId']<0 for r in bindings),'nativeVerification':tests},indent=2));print(json.dumps({k:report[k]for k in['contextCount','actionCount','aliasCount','referenceComparison','validation']},indent=2));print('bindings',len(bindings),'matched',sum(r['actionId']>=0 for r in bindings),'initializer writes',len(initializers),'consumers',len(consumers))
if tests['mismatches']:raise SystemExit(1)
