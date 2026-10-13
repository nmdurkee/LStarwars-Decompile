import importlib.util,json,struct,itertools,hashlib,math
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
WORLD=D;ENTRIES=D+0x6000;SCENE=D+0x20000;SPECIAL=D+0x21000;MATRIX=D+0x22000;STATE=D+0x23000;DSPECIAL=D+0x24000;CLIPS=D+0x25000;CLIP=D+0x26000;PORTALS=D+0x28000;OTHER_SCENE=D+0x30000;OTHER_PORTALS=D+0x31000;OUT=D+0x3f000;SIZE=0x40000
calls=[];rows=[];errors=[]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def f32(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def signed(v):return v if v<0x80000000 else v-0x100000000
class Image:
 def __init__(self):self.data=bytearray([0x6d])*SIZE
 def get(self,a):return struct.unpack_from('<I',self.data,a-D)[0]
 def put(self,a,v):struct.pack_into('<I',self.data,a-D,v&0xffffffff)
 def half(self,a):return struct.unpack_from('<H',self.data,a-D)[0]
 def sethalf(self,a,v):struct.pack_into('<H',self.data,a-D,v&0xffff)
 def byte(self,a):return self.data[a-D]
 def setbyte(self,a,v):self.data[a-D]=v&255
 def sha(self):return hashlib.sha256(self.data).hexdigest()
def opts(o):
 p=dict(kind='Update',doorCount=1,tablePresent=True,refKind='static',flags=0,id=1,header=bits(2.0),override=0,wordA=3,wordB=4,clipIndex=0,worldSceneOther=False,portalIds=[1,1,2,127,-128,-1],portalFlags=[2,0x80000000,3,4,7,0xffffffff],portalCount=6,targetId=1,mode=1,timesBits=[bits(2.0)]);p.update(o);return p
def setup(p):
 image=Image();image.put(WORLD+0x5048,ENTRIES if p['tablePresent'] else 0);image.put(WORLD+0x504c,p['doorCount']);image.put(WORLD+0x13c,OTHER_SCENE if p['worldSceneOther'] else SCENE)
 for scene,portals in [(SCENE,PORTALS),(OTHER_SCENE,OTHER_PORTALS)]:
  image.put(scene+0x54,CLIPS);image.put(scene+0x6c,p['portalCount']);image.put(scene+0x70,portals)
  for i,(id,flags) in enumerate(zip(p['portalIds'],p['portalFlags'])):image.setbyte(portals+i*32+0x1a,id);image.put(portals+i*32+0x1c,flags)
 image.put(CLIPS+p['clipIndex']*4,CLIP);image.put(CLIP,p['header']);image.sethalf(CLIP+0x16,p['override']);image.sethalf(CLIP+0xa,p['wordA']);image.sethalf(CLIP+0xe,p['wordB'])
 for i in range(max(0,p['doorCount'])):
  entry=ENTRIES+i*16;normal=SPECIAL+i*0x80;matrix=MATRIX+i*0x80;state=STATE+i*0x80;dynamic=DSPECIAL+i*0xd0
  image.put(entry,SCENE);image.put(entry+4,normal if p['refKind'] in ['static','both','static-zero'] else 0);image.put(entry+8,dynamic if p['refKind'] in ['dynamic','both','dynamic-zero','dynamic-minus1'] else 0);image.sethalf(entry+12,p['flags'] if i%2==0 else p['flags']^1);image.setbyte(entry+14,p['id'] if i%2==0 else p['id']+1)
  image.put(normal+0x40,matrix);image.put(matrix+0x48,0 if p['refKind']=='static-zero' else state);image.put(dynamic+0xc4,0 if p['refKind']=='dynamic-zero' else 0xffffffff if p['refKind']=='dynamic-minus1' else state);image.put(state+0x4c,p['timesBits'][0]);image.sethalf(state+0x5c,p['clipIndex'])
 return image
def duration(image,clip):
 header=image.get(clip)
 if header in [0x414e4934,0x414e4935]:return float(image.half(clip+0x16) or image.half(clip+0xa)+image.half(clip+0xe))
 return f32(header)
def mutate(image,scene,id,mode,trace):
 trace.append(dict(address='0x5d9060',args=[scene,id&0xffffffff,mode&0xffffffff]))
 for i in range(image.get(scene+0x6c)):
  p=image.get(scene+0x70)+i*32;stored=image.byte(p+0x1a);stored=stored-256 if stored>=128 else stored
  if stored==id:image.put(p+0x1c,0 if mode==0 else image.get(p+0x1c)|1)
def update(image,p,trace):
 entry=image.get(WORLD+0x5048)
 if not entry:return
 for i in range(max(0,signed(image.get(WORLD+0x504c)))):
  e=entry+i*16;normal=image.get(e+4);dynamic=image.get(e+8)
  if normal:animation=image.get(image.get(normal+0x40)+0x48)
  else:
   animation=image.get(dynamic+0xc4) if dynamic else 0
   if animation==0xffffffff:animation=0
  if not animation:continue
  clip=image.get(image.get(image.get(e)+0x54)+image.half(animation+0x5c)*4);end=duration(image,clip);time=f32(image.get(animation+0x4c));flags=image.half(e+12)
  open=time>=end if flags&1 else time>1.0
  if open:
   if not(flags&2):mutate(image,image.get(WORLD+0x13c),image.byte(e+14),1,trace);image.sethalf(e+12,(image.half(e+12)&0xfffb)|2)
  elif flags&2 or not(flags&4):mutate(image,image.get(WORLD+0x13c),image.byte(e+14),0,trace);image.sethalf(e+12,(image.half(e+12)&0xfffd)|4)
def observe(mu,address,size,user):
 if address==0x5d9060:calls.append(dict(address=hex(address),args=list(n.unpack('<3I',mu.reg_read(UC_X86_REG_ESP)+4))))
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x5d9060,end=0x5d9060)
n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT))
def run(inputs):
 global calls
 p=opts(inputs);expected=setup(p);n.write(D,expected.data);snapshots=[];bad=[]
 for frame,time in enumerate(p['timesBits'] if p['kind']=='Update' else [0]):
  calls=[];trace=[];wantResult=None
  if p['kind']=='Update':
   for i in range(max(0,p['doorCount'])):expected.put(STATE+i*0x80+0x4c,time);n.pack('<I',STATE+i*0x80+0x4c,time)
   update(expected,p,trace);n.call(0x55fac0,[WORLD])
  elif p['kind']=='Mutate':mutate(expected,SCENE,p['targetId'],p['mode'],trace);n.call(0x5d9060,[SCENE,p['targetId'],p['mode']])
  else:
   wantResult=bits(duration(expected,CLIP));expected.put(OUT,wantResult);n.call(0x5ca4b0,[CLIP]);n.mu.emu_start(n.STOP,n.STOP+6)
  actual=n.read(D,SIZE);actualSha=hashlib.sha256(actual).hexdigest()
  if actual!=expected.data:bad.append(dict(frame=frame,differences=[hex(D+i) for i,(a,b) in enumerate(zip(actual,expected.data)) if a!=b][:16]))
  if calls!=trace:bad.append(dict(frame=frame,calls=calls,want=trace))
  gotResult=n.unpack('<I',OUT)[0] if wantResult is not None else None
  snapshots.append(dict(nativeSha=actualSha,calls=calls.copy(),durationBits=gotResult))
 if bad:errors.append(dict(index=len(rows),options=p,bad=bad))
 rows.append(dict(options=p,snapshots=snapshots))
def main():
 times=[bits(-1.0),0x80000000,0,bits(1.0)-1,bits(1.0),bits(1.0)+1,bits(2.0)-1,bits(2.0),bits(2.0)+1,0x7fc01234,0x7f800000,0xff800000]
 for flags,ref,time in itertools.product([0,1,2,3,4,5,6,7,0xffff],['static','dynamic','none','dynamic-zero','dynamic-minus1','static-zero','both'],times):run(dict(flags=flags,refKind=ref,timesBits=[time]))
 headers=[0,0x80000000,bits(1.0),bits(2.0),bits(-1.0),0x414e4933,0x414e4934,0x414e4935,0x414e4936,0x7fc01234,0xffc01234,0x7f800000,0xff800000]
 for header,override,(a,b) in itertools.product(headers,[0,1,65535],[(0,0),(3,4),(65535,65535)]):run(dict(kind='Duration',header=header,override=override,wordA=a,wordB=b))
 for header,override,a,b,flags,ref in itertools.product([0x414e4934,0x414e4935],[0,2,65535],[0,3],[0,4],[1,3,5,7,0xffff],['static','dynamic']):
  end=override or a+b;mid=bits(float(end));run(dict(header=header,override=override,wordA=a,wordB=b,flags=flags,refKind=ref,clipIndex=7,timesBits=[mid-1 if mid else 0x80000001,mid,mid+1]))
 for id,mode,count in itertools.product([-129,-128,-1,0,1,2,127,128,255,0x7fffffff],[0,1,-1],[0,1,6]):run(dict(kind='Mutate',targetId=id,mode=mode,portalCount=count))
 for header,flags,time in itertools.product([0x7fc01234,0xffc01234,0x7f800000,0xff800000,0x80000000,0],[1,3,5],[0,0x7f800000,0xff800000,0x7fc01234]):run(dict(header=header,flags=flags,timesBits=[time]))
 for flags,other in itertools.product(range(8),[False,True]):run(dict(doorCount=3,flags=flags,worldSceneOther=other,timesBits=[bits(0.0),bits(2.0),bits(2.0),bits(0.0),bits(0.0),bits(2.0)]))
 for present,count in itertools.product([False,True],[-1,0,3]):run(dict(tablePresent=present,doorCount=count))
 for id in [127,128,255]:run(dict(id=id,timesBits=[bits(2.0),bits(0.0)],portalIds=[127,-128,-1,1,1,1]))
 report=dict(binarySha256=n.sha256,cases=len(rows),nativeCalls=sum(len(r['snapshots']) for r in rows),mismatches=len(errors),groups={k:sum(r['options']['kind']==k for r in rows) for k in ['Update','Mutate','Duration']},bytesComparedPerNativeCall=SIZE,examples=errors[:3],method='Original55fac0 updater composes unchanged5d0420 scene animation selection,5ca4b0 duration decoder and5d9060 portal mutation. Standalone duration/mutator cases execute original entries. No computational adapters;5d9060 observational hook only records actual arguments while execution proceeds. Complete prepared memory compared byte-for-byte after every call.',limits=['Prepared valid scene/reference/animation/portal backing; signed door count may<=0, portal count unsigned bounded0..6. No actual scene loading, animation advancement or rendered portal visibility.','Normal reference points through valid matrix+48; dynamic0/-1 animation means unavailable. Clip indices0/7 have prepared tables.','Quiet NaNs/infinities and signed zero preserve native comparison behavior; signalingNaN payload/exception semantics are outside fixtures.','Other caller/environment portal producers are external. State cache intentionally suppresses redundant mutations even if portal state is changed elsewhere.','Managed comparison harness compilation is separate; execution remains pending.'])
 (B/'reports/world-phase3-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/world-phase3-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
