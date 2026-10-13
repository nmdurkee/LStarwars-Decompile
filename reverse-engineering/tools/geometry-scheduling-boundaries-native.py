"""Original normal-scheduler gates and null-workspace visibility preparation."""
import importlib.util,json,struct,itertools,hashlib
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
scene=n.DATA;display=scene+0x1000;shader=scene+0x2000;flags=scene+0x3000;specials=scene+0x4000;remote=scene+0x8000;alternate=scene+0x9000;calls=[];events=[];errors=[];cases=[];prepareCases=[]
def hook(mu,address,size,_):
 calls.append(hex(address))
 if address==0x5f0f00:
  sp=mu.reg_read(UC_X86_REG_ESP);ret,handle,matrix,a,b,c=n.unpack('<6I',sp);owner,unused,special=n.unpack('<3I',handle);events.append([(special-specials)//208,matrix==remote,owner==scene,a,b,c]);mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for a in [0x5f5830,0x5fd0d0,0x5f3c80,0x5f5380,0x603960,0x5f0f00,0x5c12f0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def check(a,e,context):
 if a!=e and len(errors)<30:errors.append({'context':context,'native':a,'expected':e})
def reset():
 n.write(scene,bytes(0x10000));n.pack('<I',scene+0x110,display);n.pack('<I',scene+0x1c,8);n.pack('<I',scene+0xf4,8);n.pack('<I',scene+0x13c,0x280a2f0);n.pack('<I',display+0x48,flags);n.pack('<I',display+0x78,scene);n.pack('<I',display+0x80,shader);n.pack('<2I',display+0x6c,8,specials);n.pack('<I',0x973fcc,0);n.pack('<I',0x973fd0,0);n.pack('<I',0x9718dc,0);n.pack('<I',0x80b6f4,1);n.pack('<I',0x80b6f8,0);n.pack('<I',0x80ba14,0);n.pack('<I',0x973940,0);n.pack('<I',0x97394c,0);n.pack('<I',0x97393c,0);n.write(0x280a2f0,bytes([0x24])+bytes(624));n.write(flags,bytes([0,8,0,0,8,0,0,0]));n.pack('<I',scene+0x148,0xffffffff)
 for i in range(8):
  a=specials+208*i;n.pack('<I',a+184,2 if i%4!=3 else 0);n.pack('<I',a+192,i);n.pack('<i',a+196,[0,-1,remote][i%3])
 n.write(shader,bytes([0xa5])*420);n.write(0x9868a0,bytes([0x19])*420);calls.clear();events.clear()
for skip,dirty,skipDynamic,flag16,marker,portalsEnabled,filtering in itertools.product([False,True],repeat=7):
 reset();word=0x4000|(4 if dirty else 0)|(0x10000 if flag16 else 0);n.pack('<I',display+0x74,word);n.pack('<I',0x973fcc,int(skip));n.pack('<I',0x973fd0,int(skipDynamic));n.pack('<I',scene+0x138,int(marker));n.pack('<I',0x80ba58,int(portalsEnabled));n.pack('<I',0x80bab4,int(filtering));n.call(0x5f5830,[display],count=1000000)
 expectedEvents=[]
 if not(skip or dirty or skipDynamic or flag16):
  for i in range(8):
   if i%4==3:continue
   if filtering and marker and portalsEnabled and not(i in[1,4]or i in[2,5]):continue
   expectedEvents.append([i,i%3==2,True,0,0,0])
 expectedCalls=['0x5f5830']+([]if skip else['0x5c12f0']if dirty else['0x5fd0d0','0x5f3c80','0x5f5380','0x603960']+['0x5f0f00']*len(expectedEvents));expectedShader=bytearray(bytes([0xa5 if skip or dirty else 0x19])*420)
 if not(skip or dirty):
  for at in[0x168,0x110,0x34,0x180]:expectedShader[at:at+4]=bytes(4)
 actual={'calls':list(calls),'events':list(events),'displayFlags':n.unpack('<I',display+0x74)[0],'shaderSHA256':hashlib.sha256(n.read(shader,420)).hexdigest()};expected={'calls':expectedCalls,'events':expectedEvents,'displayFlags':word,'shaderSHA256':hashlib.sha256(expectedShader).hexdigest()};check(actual,expected,[skip,dirty,skipDynamic,flag16,marker,portalsEnabled,filtering]);cases.append({'input':[skip,dirty,skipDynamic,flag16,marker,portalsEnabled,filtering],'native':actual})
# Direct5f3c80 gates leave every context/global byte untouched; eligible branch
#uses either legacy scene+1c or the alternate record+1c as its count source.
for workspace,enabled,alternateCount in itertools.product([False,True],[False,True],[None,0,17]):
 reset();n.pack('<I',scene+0x138,0);n.pack('<I',0x80ba58,1);n.pack('<I',scene+0x120,0x12345678);n.pack('<2I',scene+0x140,0x77777777,0x88888888);n.pack('<I',scene+0x128,alternate if alternateCount is not None else 0)
 if alternateCount is not None:n.pack('<i',alternate+28,alternateCount)
 n.pack('<I',0x80b6f4,int(enabled));returned=n.call(0x5f3c80,[scene,remote if workspace else 0]);eligible=workspace and enabled;actual=[returned,n.unpack('<I',scene+0x120)[0],*n.unpack('<2I',scene+0x140),n.unpack('<I',scene+0x148)[0],n.unpack('<I',0x97393c)[0]];expected=[scene+0x120 if eligible else 0,(8 if alternateCount is None else alternateCount)if eligible else 0x12345678,0 if eligible else 0x77777777,0 if eligible else 0x88888888,0xffffffea if eligible else 0xffffffff,int(eligible)];check(actual,expected,[workspace,enabled,alternateCount]);prepareCases.append({'workspace':workspace,'enabled':enabled,'alternateCount':alternateCount,'native':actual})
report={'schema':'original-scheduling-boundaries-v1','passed':not errors,'binarySHA256':n.sha256,'counts':{'schedulerGates':len(cases),'preparationGates':len(prepareCases)},'errors':errors,'cases':cases,'prepareCases':prepareCases,'limits':['Only5f0f00 is a recorded return 0 boundary; all tested scheduler/preparation/static-empty/portal-ineligible code executes original instructions.','Normal camera mode only; no grid/tree/shadow behavior claimed.','Eight synthetic dynamic records cover inactive flags,bypass flags,portal bits,and0/-1/valid transform overrides.','Zero static clip count deliberately does not set display dirty bit4.','Managed execution remains pending.']}
(R/'geometry-scheduling-boundaries-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in ['passed','counts','errors']},indent=2))
if errors:raise SystemExit(1)
