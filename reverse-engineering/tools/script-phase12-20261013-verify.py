"""Native55d2b0 hydration/fault-order bridge evidence; existing numeric source reused."""
import json,struct,hashlib,itertools,base64
from pathlib import Path
B=Path(__file__).resolve().parent.parent
old=B/'tools/animation-character-bounds-verify.py';ctx={'__file__':str(old)};exec(old.read_text().split('for i in range(1200):')[0],ctx)
n=ctx['n'];D=ctx['D'];SIZE=ctx['SIZE'];DATA=ctx['DATA'];MODEL=ctx['MODEL'];GAME=ctx['GAME'];INFO=ctx['INFO'];f=ctx['f'];model=ctx['model'];setup=ctx['setup'];cases=[];checks={};errors=[]
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);code=list(cs.disasm(n.read(0x55d2b0,1800),0x55d2b0));end=0x55d691 # Last native body return55d690; following55d6a0 is a different function.
# Actual boundary from retained original numeric report; trim exactly to last bodyret.
assembly=[dict(address='0x55d2b0',size=end-0x55d2b0,bytes=n.read(0x55d2b0,end-0x55d2b0).hex(),instructions=[dict(address=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x55d2b0,end-0x55d2b0),0x55d2b0)])]
def check(k,a,b,c):
 checks[k]=checks.get(k,0)+1
 if a!=b:errors.append(dict(group=k,got=a,want=b,input=c))
def execute(index,mode,c):
 before,e=setup(index,mode);before=bytearray(before);e=dict(e);e['enabled']=list(e['enabled']);c=dict(c)
 if 'pose'in c:before[0x1079]=c['pose']
 if 'primary'in c:e['primary']=c['primary']
 if 'fallback'in c:e['fallback']=c['fallback']
 if 'd30Bits'in c:ctx['w'](before,0xd30,c['d30Bits'])
 if 'fallbackGate'in c:before[0x28c]=c['fallbackGate']
 if c.get('primaryDisabled')and e['primary']!=-1:e['enabled'][e['primary']]=0
 if c.get('fallbackDisabled')and e['fallback']!=-1:e['enabled'][e['fallback']]=0
 if c.get('nullModel'):ctx['w'](before,0x50,0)
 if c.get('nullDef'):ctx['w'](before,0x54,0)
 before[0x7b5]=c.get('context',index%100)&255;e['contextFlags']=c.get('contextFlags',e['contextFlags']);ctx['w'](before,0x7bc,c.get('objectContextBits',ctx['u'](before,0x7bc)))
 if c.get('inactiveTailNonfinite'):
  for p in [0xd7c,0x21c,0xb4]:ctx['w'](before,p,0x7fc12345)
 n.write(D,bytes(0x10000));n.write(D,before);n.pack('<I',DATA+0x24,0 if c.get('nullClass')else GAME);n.write(GAME+0x10f,bytes([e['primary']&255]));n.write(GAME+0x10d,bytes([e['fallback']&255]));n.pack('<16I',MODEL+0x14,*e['enabled']);n.pack('<I',0x7fb0e4,0 if c.get('nullRegistry')else INFO);signed=struct.unpack_from('<b',before,0x7b5)[0];n.pack('<II',INFO+signed*16+8,e['contextFlags'],0x12345678);n.pack('<I',0x925018,e['dt'])
 if 'contextAliasField'in c:n.pack('<I',0x7fb0e4,(D+c['contextAliasField']-signed*16-8)&0xffffffff)
 segs=[dict(address=p,bytes=n.read(p,z).hex())for p,z in [(D,SIZE),(DATA,0x100),(MODEL,0x100),(GAME,0x200),(INFO-0x800,0x1000),(0x7fb0e4,4),(0x925018,4)]]
 external=[n.read(p,z).hex()for p,z in [(DATA,0x100),(MODEL,0x100),(GAME,0x200),(INFO-0x800,0x1000)]];actor=0 if c.get('nullActor')else D;expectedFault=None;want=None
 if c.get('nullActor'):expectedFault='initialactor';want=before
 elif before[0x1079]and(c.get('nullDef')or c.get('nullClass')):expectedFault='earlytype';want=bytearray(before);ctx['w'](want,0x1f8,ctx['u'](want,0x1f8)|0x100)
 elif before[0x1079]and c.get('nullModel')and struct.unpack_from('<f',before,0xd30)[0]==1 and e['fallback']!=-1:expectedFault='earlyfallbackmodel';want=bytearray(before);ctx['w'](want,0x1f8,ctx['u'](want,0x1f8)|0x100)
 else:
  if c.get('nullRegistry'):
   neutral=dict(e,contextFlags=0);dummy=bytearray(before)
   for p in [0xd7c,0x21c,0xb4]:ctx['w'](dummy,p,0)
   want,trace,branch=model(dummy,neutral)
   for p in [0xd7c,0x21c,0xb4]:want[p:p+4]=before[p:p+4]
   want[0x414:0x420]=want[0x1a8:0x1b4];expectedFault='latecontext'
  else:
   if 'contextAliasField'in c:
    neutral=dict(e,contextFlags=0);dummy=bytearray(before)
    for p in [0xd7c,0x21c,0xb4]:ctx['w'](dummy,p,0)
    pre,_,_=model(dummy,neutral);e['contextFlags']=ctx['u'](pre,c['contextAliasField'])
   want,trace,branch=model(before,e)
 fault=None
 try:n.call(0x55d2b0,[actor])
 except RuntimeError as exc:fault=str(exc)
 got=n.read(D,SIZE).hex();check('bridge-original-fault-gate',fault is not None,expectedFault is not None,c);check('bridge-complete-state-before-fault',got,want.hex(),c);check('bridge-external-input-confinement',[n.read(p,z).hex()for p,z in [(DATA,0x100),(MODEL,0x100),(GAME,0x200),(INFO-0x800,0x1000)]],external,c);cases.append(dict(context=c,actor=actor,initial=segs,nativeActor=got,nativeFault=fault,faultStage=expectedFault,environment=e))
# Reuse the earlier genuine numeric branches, while resolving all pointers lazily.
for index,mode,contextFlags,objectBits in itertools.product(range(12),range(10),[0,0x80000,0x100000,0x180000],[0,0x800]):execute(index,mode,dict(contextFlags=contextFlags,objectContextBits=objectBits))
# All signed context byte rows select prepared backing, not host unsigned indices.
for context in range(-128,128):execute(211,0,dict(context=context,contextFlags=0x100000))
for pose,flag,d30,primary,fallback,gate in itertools.product([0,1],['nullDef','nullClass','nullModel','nullRegistry'],[0,f.bits(1.),0x7fc12345],[-1,0],[-1,1],[0,1]):execute(317,0,{flag:True,'pose':pose,'d30Bits':d30,'primary':primary,'fallback':fallback,'fallbackGate':gate})
execute(77,1,dict(nullActor=True))
# Actual direct/raised context gates must skip unneeded nonfinite tail fields.
for mode,flags,bit in itertools.product([0,1,2,3],[0x100000,0x180000],[0,0x800]):execute(411,mode,dict(contextFlags=flags,objectContextBits=bit,inactiveTailNonfinite=True))
for mode,field,bit in itertools.product([0,1,2,3],[0x80,0x17c,0x1ac],[0,0x800]):execute(913,mode,dict(contextAliasField=field,objectContextBits=bit))
report=dict(binarySha256=n.sha256,nativeChecks=sum(checks.values()),checks=checks,mismatches=len(errors),errors=errors,cases=len(cases),adapters=[],limits=['Numeric math reused from original animation-character-bounds oracle; new cases resolve actual heap pointers and preserve early/late fault state.','Valid point indices-1 or0..15; complete mapped actorimage. Active finite numeric data/stores; skipped tail NaN fields explicitlytested.'])
for suffix,obj in [('tests',report),('native-fixtures',dict(binarySha256=n.sha256,cases=cases)),('assembly',dict(binarySha256=n.sha256,functions=assembly))]:(B/'reports'/('script-phase12-20261013-'+suffix+'.json')).write_text(json.dumps(obj,indent=2))
print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
