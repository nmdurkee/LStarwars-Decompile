"""Extend original 0x491d50 paused-frame evidence to populated players.
Imports existing no-op subsystem adapters; no original OS APIs are executed.
"""
import importlib.util, json, hashlib, itertools, struct
from pathlib import Path
spec=importlib.util.spec_from_file_location('frame_base',Path(__file__).with_name('native-frame-dispatch.py'))
f=importlib.util.module_from_spec(spec);spec.loader.exec_module(f)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=f.n;B=f.B;callback=n.STOP+0x200;captures={}
def hook(mu,address,size,user):
 if address==0x492173:captures['cameraAtApply']=list(n.unpack('<16I',f.MATRIX))
 if address==callback:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
  captures['levelCallbackWorld']=n.unpack('<I',sp+4)[0]
  captures['levelCallbackMatrix']=list(n.unpack('<16I',f.MATRIX))
  captures['outputBeforeTail']=n.unpack('<I',f.WORLD+0x16500)[0]
  mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for address in [0x492173,callback]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
raw=[0,0x80000000,0x7fc12345,0xff812345,0x3f800000,0xffffffff]+[(0x12345678+i*0x1020304)&0xffffffff for i in range(10)]
selected={0x5e4e00:1,0x5d3490:1,0x5d4770:1,0x603cc0:1,0x495310:2,0x570a80:3,0x690610:1}
def normalized(events):
 out=[]
 for e in events:
  va=int(e['callee'],16)
  if va not in selected:continue
  args=e['args'][:selected[va]]
  if va==0x603cc0:args=[0] # host camera-array identity, separately verified contents
  if va==0x570a80:args[2]=struct.unpack('<i',struct.pack('<I',args[2]))[0]
  out.append([hex(va),args])
 return out
report={'updated':'2026-10-13','address':'0x491d50','range':'0x492115-0x4921cc','binarySha256':n.sha256,'sourceEvidence':f.report['sourceEvidence'],'method':'Original complete dispatcher with existing explicit no-op subsystem adapters. Compare selected paused block order/arguments and matrix copy; populated player projections and optional level callback. Does not prove renderer, player context update, audio or whole frame behavior.','cases':0,'assertions':0,'failures':[],'vectors':[],'gateVectors':[]}
def check(label,actual,want,input):
 report['assertions']+=1
 if actual!=want:report['failures'].append({'check':label,'input':input,'actual':actual,'expected':want})
for paused,force,override in itertools.product([0,2],[0,3],[0,1,0x100,0x101]):
 f.setup(paused,force,override,0,1,0,1/60);captures.clear()
 n.call(0x491d50,[f.WORLD,f.WORLD+0x16500],count=1000000)
 got=any(e['callee']=='0x603cc0' for e in f.events);want=paused!=0 and force==0 and (override&255)==0
 calls=sum(e['callee']=='0x565bf0'for e in f.events)
 check('pause gate',got,want,[paused,force,override]);check('override lazy call count',calls,0 if paused==0 else 1 if force==0 and want else 2 if force==0 else 1,[paused,force,override])
 # In active branch paused causes a second override query after update entry.
 report['gateVectors'].append({'input':{'paused':paused,'forceUpdate':force,'override':override},'native':got,'nativeFirstGateCallbackCount':0 if paused==0 or force!=0 else 1})
 report['cases']+=1
for mask,flagKind,variant,hasCallback in itertools.product(range(4),range(4),[-128,-1,0,1,127,64],[0,1]):
 f.setup(1,0,0,0,1,0,.1);captures.clear();flags=[0,0x80,0xffffffff,0x80000000][flagKind]
 n.pack('<16I',f.CAMERA+0xb8,*raw)
 for i in range(8):
  actor=f.WORLD+0x18000+i*0x1000;n.write(actor,bytes(0x1000))
  n.pack('<I',actor+0x1fc,flags^(0x80 if i==1 else 0));n.pack('<I',actor+0x7fc,0xf0001000+i*17);n.pack('<b',actor+0x280,variant if i!=1 else -variant-1)
  n.pack('<I',0x93d7f0+i*4,actor if i>=2 or mask&(1<<i)else 0)
 if hasCallback:n.pack('<I',f.LEVEL+0x78,callback)
 n.call(0x491d50,[f.WORLD,f.WORLD+0x16500],count=1000000)
 players=[{'renderObject':0xf0001000+i*17,'flags':flags^(0x80 if i==1 else 0),'variant':variant if i==0 else -variant-1}if mask&(1<<i)else None for i in range(2)]
 want=[['0x5e4e00',[0]],['0x5d3490',[2]],['0x5d4770',[1]],['0x603cc0',[0]],['0x495310',[0x9253b0,1]]]
 want +=[['0x570a80',[p['renderObject'],(p['flags']>>7)&1,p['variant']]]for p in players if p]
 want +=[['0x690610',[1]]]
 meta={'players':players,'cameraWords':raw,'levelCallback':hasCallback}
 actual=normalized(f.events);check('paused boundary order and args',actual,want,{'mask':mask,'flagKind':flagKind,'variant':variant,'levelCallback':hasCallback})
 check('matrix at apply',captures.get('cameraAtApply'),raw,mask);check('matrix retained',list(n.unpack('<16I',f.MATRIX)),raw,mask)
 check('world identity unchanged',n.unpack('<I',f.WORLD)[0],0xabcdef,mask);check('separate output cleared',n.unpack('<I',f.WORLD+0x16500)[0],0,mask)
 if hasCallback:
  check('level callback world',captures.get('levelCallbackWorld'),f.WORLD,mask);check('callback after paused matrix',captures.get('levelCallbackMatrix'),raw,mask);check('callback before output clear',captures.get('outputBeforeTail'),0xdeadbeef,mask)
 report['vectors'].append({'input':meta,'native':{'calls':actual,'matrix':list(n.unpack('<16I',f.MATRIX))}});report['cases']+=1
report['assembly']=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x491d50,0xa40),0x491d50)if 0x492115<=i.address<=0x4921cc]
report['limits']=['C# fragment covers pause gate and presentation branch only. Full dispatcher/transition integration remains incomplete.','Players two through seven are populated sentinels and must not be presented by this two-slot loop.','All direct subsystem callees are adapted; level callback only records state and returns. Callback mutation and rendering semantics are not established.','C# objects/arrays are host projections, not recovered complete native layouts. Valid disjoint camera storage is required.','Native original comparisons are independent of executing compiled C#.']
report['toolSha256']=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
(B/'reports/frame-paused-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:report[k]for k in ['cases','assertions','failures']}));raise SystemExit(bool(report['failures']))
