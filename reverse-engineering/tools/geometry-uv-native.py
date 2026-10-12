"""Differential validation of decoded UV updates against original PC0x5dfbd0."""
import importlib.util,json,struct,hashlib,time
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=nx.NativeX86();cases=json.loads((B/'reports/geometry-uv-programs.json').read_text());trig=(B/cases['sineTable']['file']).read_bytes();assert hashlib.sha256(trig).hexdigest()==cases['sineTable']['sha256'];n.write(0x29899a0,trig)
SET=n.DATA;SCENE=SET+0x100;INDEX=SET+0x200;TABLE=SET+0x300;MAT=SET+0x1000
n.pack('<4I',SET,SCENE,1,INDEX,0);n.pack('<I',INDEX,0);n.pack('<I',SCENE+0x50,TABLE);n.pack('<I',TABLE,MAT)
def hook(mu,addr,size,data):
 if addr in [0x4ffaa0,0x4ffac0]:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
errors=[];checks=0;ticks=0;maximum=0;exact=0;signedZero=0;rows=[]
for ci,c in enumerate(cases['configurations']):
 import base64
 raw=base64.b64decode(c['rawRecordBase64']);n.pack('<I',0x973fa8,SET if c['member'] else 0);local=0
 for scenario in c['scenarios']:
  n.write(MAT,raw);n.pack('<f',0x97add0,scenario['timeBefore'])
  for step in scenario['steps']:
   n.call(0x5dfbd0,[struct.unpack('<I',struct.pack('<f',step['delta']))[0]])
   actual=list(n.unpack('<8f',MAT+0x1d0))+[n.unpack('<f',0x97add0)[0]];expected=step['offsets']+[step['timeAfter']]
   for idx,(a,b) in enumerate(zip(actual,expected)):
    err=abs(a-b)/max(1,abs(a),abs(b));maximum=max(maximum,err);checks+=1
    if struct.pack('<f',a)==struct.pack('<f',b):exact+=1
    elif a==0 and b==0:signedZero+=1
    if err>1e-7:
     local+=1
     if len(errors)<30:errors.append({'configuration':c['key'],'slot':idx,'actual':a,'expected':b,'delta':step['delta'],'expectedTime':step['timeAfter'],'normalizedError':err})
   ticks+=1
 rows.append({'configuration':c['key'],'authoredCount':c.get('authoredCount',0),'synthetic':c.get('synthetic',False),'mismatches':local})
 if ci%100==0:print(json.dumps({'configurations':ci,'ticks':ticks,'errors':sum(x['mismatches'] for x in rows)}),flush=True)
wrapper=[]
for reset in [0,1]:
 for speed in [0,.5,1,-2]:
  delta=.03125;n.pack('<I',0x973fa8,0);n.pack('<I',0x9739b8,2);n.pack('<I',0x80e9e4,reset);n.pack('<f',0x80bac4,speed);n.pack('<f',0x97add0,8);n.pack('<f',0x28571e8,12)
  for j in range(2):
   scene=n.DATA+0x5000+j*0x2000;header=scene+0x100;table=scene+0x400;mat=scene+0x500
   n.pack('<I',0x9739bc+j*4,scene);n.pack('<I',scene+0x78,header);n.pack('<I',header+0x158,j);n.pack('<I',scene+0x4c,1);n.pack('<I',scene+0x50,table);n.pack('<I',table,mat);n.pack('<8f',mat+0x1d0,*[.125*(k+1)for k in range(8)])
  n.call(0x601330,[struct.unpack('<I',struct.pack('<f',delta))[0]])
  values=[list(n.unpack('<8f',n.DATA+0x5000+j*0x2000+0x500+0x1d0))for j in range(2)]
  expected=[[.125*(k+1)for k in range(8)],[0]*8 if reset else [.125*(k+1)for k in range(8)]]
  clocks=[n.unpack('<f',0x97add0)[0],n.unpack('<f',0x28571e8)[0]];expectedClocks=[8+speed*delta,12+delta];ok=values==expected and clocks==expectedClocks and n.unpack('<I',0x80e9e4)[0]==0
  wrapper.append({'resetRequested':reset,'speed':speed,'offsets':values,'clocks':clocks,'passed':ok})
n.pack('<f',0x80bac4,1)
report={'binarySHA256':n.sha256,'function':'0x5dfbd0','uniformSetter':'0x601210','roundTowardZeroHelper':'0x5b7cc0 ->0x6e6b90','publicWrapper':'0x601330','defaultWrapperTimeScale':n.unpack('<f',0x80bac4)[0],'sineTable':cases['sineTable'],'originalSineInitializer':'0x5bdd50, reused from animation-scene-pose-native-verification evidence','authoredMaterials':cases['materialCount'],'uniqueAuthoredConfigurations':cases['uniqueAuthoredConfigurations'],'syntheticConfigurations':cases['syntheticConfigurations'],'scenarios':sum(len(x['scenarios'])for x in cases['configurations']),'nativeTicks':ticks,'scalarChecks':checks,'floatBitExactChecks':exact,'signedZeroOnlyDifferences':signedZero,'wrapperCases':wrapper,'wrapperPassed':all(x['passed'] for x in wrapper),'maxNormalizedError':maximum,'mismatches':sum(x['mismatches'] for x in rows),'passed':not any(x['mismatches'] for x in rows) and all(x['passed'] for x in wrapper),'errors':errors,'rows':rows,'scope':'Original evaluator, original arithmetic/rounding helpers and original UV setter. Only critical-section boundaries are intercepted. Original sine table bytes retained. Sequential updates compare every UV offset and shared time.','mode128':'All44 authored mode128 records are members with layer handle0. The original evaluator takes its default branch and writes zero to that axis; no special oscillation or flag masking occurs.','limits':['Authored membership lists are decoded, but live creation/destruction and global frame scheduling remain game state.','Eight original-wrapper cases also verify scaled primary time, unscaled secondary time and the one-shot zeroing of offsets for registered scenes whose header+0x158 is nonzero. Live scheduling of that request remains separate.']}
(B/'reports/geometry-uv-native-validation.json').write_text(json.dumps(report,indent=2)+'\n')
asm='\n'.join(f'{x.address:08x} {x.mnemonic} {x.op_str}'for x in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x5dfbd0,0x268),0x5dfbd0))
(B/'reports/geometry-uv-native-assembly.txt').write_text(asm+'\n');print(json.dumps({k:v for k,v in report.items()if k!='rows'},indent=2))
