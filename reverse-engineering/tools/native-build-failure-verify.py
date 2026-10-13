import importlib.util,json,struct,itertools,copy,gzip,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
OBJ=D;GROUP=D+0x100;NODES=D+0x200;DESCS=D+0x1000;EFFECTS=D+0x4000;CONST=n.unpack('<d',0x751700)[0];rows=[];errors=[];groups={};events=[];current={};callIndex=0;fast=False;visited=set()
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def flt(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def node(i):return 0 if i<0 else NODES+i*0x40
def effect(i):return 0 if i<0 else EFFECTS+i*0x300
def options(o):
 p=dict(present=True,group=True,count=3,seed=1,allocations=[0,1,2],mutation='none',time=0x3d888889,origin=[0,0x80000000,0x7fc12345],template=[(0x12345678+i*0x76543)&0xffffffff for i in range(50)],matrices=[[(0x80000000+(i+1)*0x10000+j*0x33333)&0xffffffff for j in range(16)] for i in range(3)],lifetimes=[0x3f800000,0xbf800000,0x7fc12345],flags=[0,1,255]);p.update(copy.deepcopy(o));return p
def setup(o):
 global callIndex
 current.clear();current.update(o);events.clear();callIndex=0;n.write(D,bytes((i*37+13)&255 for i in range(0x5000)));n.pack('<I',OBJ+0x10,GROUP if o['group'] else 0);n.pack('<I',GROUP+0x18,NODES if o['count'] else 0);n.pack('<I',0x80253c,o['seed']);n.pack('<I',0x925018,o['time']);n.pack('<3I',0x93b0cc,*o['origin']);n.pack('<50I',0x810210,*o['template'])
 for i in range(3):n.pack('<I',node(i),node(i+1) if i+1<o['count'] else 0);n.pack('<I',node(i)+0x24,DESCS+i*0x100);n.pack('<16I',DESCS+i*0x100+0x40,*o['matrices'][i]);n.pack('<I',effect(i)+0x100,o['lifetimes'][i]);n.pack('<B',effect(i)+0x20a,o['flags'][i])
def capture():return dict(seed=n.unpack('<I',0x80253c)[0],time=n.unpack('<I',0x925018)[0],origin=list(n.unpack('<3I',0x93b0cc)),template=list(n.unpack('<50I',0x810210)),next=[-1 if not n.unpack('<I',node(i))[0] else (n.unpack('<I',node(i))[0]-NODES)//0x40 for i in range(3)],matrices=[list(n.unpack('<16I',DESCS+i*0x100+0x40)) for i in range(3)],lifetimes=[n.unpack('<I',effect(i)+0x100)[0] for i in range(3)],flags=[n.unpack('<B',effect(i)+0x20a)[0] for i in range(3)])
def observe(mu,address,size,user):
 global callIndex
 if address!=0x64d270:
  if not fast:visited.add(address)
  return
 sp=mu.reg_read(UC_X86_REG_ESP);request=n.unpack('<I',sp+4)[0];words=list(n.unpack('<50I',request));index=(words[9]-NODES-4)//0x40
 if not fast:
  normalized=words.copy();normalized[0]=normalized[2]=normalized[9]=0;events.append(dict(node=index,words=normalized,matrix=list(n.unpack('<16I',words[0])),origin=list(n.unpack('<3I',words[2]))))
 if callIndex==0:
  mode=current['mutation']
  if mode=='template':n.pack('<I',0x810214,0xfedcba98);n.pack('<I',0x925018,0x3f400000)
  elif mode=='origin-global':n.pack('<3I',0x93b0cc,0x11111111,0x22222222,0x33333333)
  elif mode=='origin-local':n.pack('<3I',words[2],0x44444444,0x55555555,0x66666666)
  elif mode=='skip':n.pack('<I',node(index),node(2) if current['count']>2 else 0)
  elif mode=='stop':n.pack('<I',node(index),0)
  elif mode=='matrix':n.pack('<I',DESCS+0x100+0x40,0xabcdef01)
  elif mode=='random':n.pack('<I',0x80253c,0x12345678)
 allocation=current['allocations'][callIndex%len(current['allocations'])];callIndex+=1;mu.reg_write(UC_X86_REG_EAX,effect(allocation));mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x64d270,end=0x64d270)
for start,end in [(0x590690,0x5907af),(0x571c50,0x571c75),(0x571c80,0x571ceb)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=start,end=end)
def model(kind,o,flags=0,life=0,frame=0):
 state=dict(seed=o['seed'],time=o['time'],origin=o['origin'].copy(),template=o['template'].copy(),next=[i+1 if i+1<o['count'] else -1 for i in range(3)],matrices=copy.deepcopy(o['matrices']),lifetimes=o['lifetimes'].copy(),flags=o['flags'].copy());ev=[];result=None
 if kind in ['reset','visible']:
  state['lifetimes'][0]=life;state['flags'][0]=flags
  if kind=='reset':state['lifetimes'][0]=bits(2.5 if flags&1 else 5)
  else:result=int(not(flt(life)>0 and frame%6>=3 and flt(life)<(1 if flags&1 else 2)))
 else:
  i=0 if o['present'] and o['group'] and o['count'] else -1;origin=o['origin'].copy();index=0
  while i>=0:
   words=state['template'].copy();words[0]=words[2]=words[9]=0;words[5]=words[6]=0x3e4ccccd;words[7]=0xc0800000;words[11]=0x90;words[15]=0x571ba0;words[19]=0x571c50;words[21]=0x571c80;words[35]=state['time'];words[49]=(words[49]&0xffffff00)|1;ev.append(dict(node=i,words=words,matrix=state['matrices'][i].copy(),origin=origin.copy()))
   if index==0:
    mode=o['mutation']
    if mode=='template':state['template'][1]=0xfedcba98;state['time']=0x3f400000
    elif mode=='origin-global':state['origin']=[0x11111111,0x22222222,0x33333333]
    elif mode=='origin-local':origin=[0x44444444,0x55555555,0x66666666]
    elif mode=='skip':state['next'][i]=2 if o['count']>2 else -1
    elif mode=='stop':state['next'][i]=-1
    elif mode=='matrix':state['matrices'][1][0]=0xabcdef01
    elif mode=='random':state['seed']=0x12345678
   allocation=o['allocations'][index%len(o['allocations'])];index+=1
   if allocation>=0:state['seed']=(state['seed']*0x24cd+1)&65535;state['lifetimes'][allocation]=bits(7+2*state['seed']*CONST)
   i=state['next'][i]
 return dict(events=ev,state=state,result=result)
def run(kind='create',inputs=None,flags=0,life=0,frame=0):
 o=options(inputs or {});setup(o)
 if kind!='create':n.pack('<I',effect(0)+0x100,life);n.pack('<B',effect(0)+0x20a,flags);n.pack('<I',0x925068,frame)
 before=n.read(D,0x5000);want=model(kind,o,flags,life,frame);gotReturn=n.call({'create':0x590690,'reset':0x571c50,'visible':0x571c80}[kind],[OBJ if kind=='create' and o['present'] else 0 if kind=='create' else effect(0)]);got=dict(events=copy.deepcopy(events),state=capture(),result=gotReturn if kind=='visible' else None);expected=bytearray(before)
 for i in range(3):struct.pack_into('<I',expected,node(i)-D,node(want['state']['next'][i]));struct.pack_into('<16I',expected,DESCS+i*0x100+0x40-D,*want['state']['matrices'][i]);struct.pack_into('<I',expected,effect(i)+0x100-D,want['state']['lifetimes'][i])
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x5000)!=bytes(expected):bad.append('Complete data image differs')
 if bad:errors.append(dict(kind=kind,options=o,flags=flags,life=life,frame=frame,bad=bad))
 rows.append(dict(kind=kind,options=o,flags=flags,life=life,frame=frame,native=got));groups[kind]=groups.get(kind,0)+1

def main():
 global fast
 for present,group,count,alloc,mutation in itertools.product([False,True],[False,True],[0,1,2,3],[[-1],[0],[0,1,2],[-1,0,-1],[2,2,1]],['none','template','origin-global','origin-local','skip','stop','matrix','random']):run(inputs=dict(present=present,group=group,count=count,allocations=alloc,mutation=mutation))
 for flags in range(256):run('reset',flags=flags,life=0x7fa01234)
 for flags,frame,life in itertools.product([0,1,2,255],[0,1,2,3,4,5,6,7,0x7fffffff,0x80000000,0xfffffffe,0xffffffff],[0,0x80000000,0x3f000000,0x3f7fffff,0x3f800000,0x3f800001,0x3fffffff,0x40000000,0x40000001,0xbf800000,0x7f800000,0xff800000,0x7fc12345,0x7fa12345]):run('visible',flags=flags,frame=frame,life=life)
 fast=True;o=options(dict(count=1,seed=0,allocations=[0]));setup(o);state=0;lifetimes=[]
 for i in range(65536):
  state=(state*0x24cd+1)&65535;n.call(0x590690,[OBJ]);got=n.unpack('<I',effect(0)+0x100)[0];want=bits(7+2*state*CONST)
  if got!=want or n.unpack('<I',0x80253c)[0]!=state:errors.append(dict(cycleIndex=i,got=got,want=want,state=state))
  lifetimes.append(got)
 report=dict(binarySha256=n.sha256,checks=len(rows)+len(lifetimes),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),randomCycleCases=len(lifetimes),randomFinalState=state,visitedInstructions=len(visited),examples=errors[:3],method='Original590690,571c50,571c80 and54fa60 execute. Effect allocator64d270 is a declared mutable service; complete normalized200-byte requests,16 matrix words,3 origin words, ordered node identities, copied state and full20KiB data image compare. Separate full65,536-state original producer cycle verifies lifetime bits and random state at every step.',limits=['Valid readable3-node-or-shorter acyclic fixture lists with shared effect return identities; portable list size is not capped. Request pointer slots are typed references and cleared in normalized template words; other template bytes preserve identity.','Finite time/global925018 metadata; template/matrix/origin words are raw bits including signed zero and NaN payloads. Stack request buffers are synchronous, not retained by allocation service.','Allocation may mutate template/global time, origin source versus local copy, next links, later matrices and shared random state. Group head capture and next-node reread preserve original order.','Allocation64d270 and callback571ba0 physical/sound implementation remain external; ResetLifetime571c50 and visibility571c80 are included. Unsigned frame modulo6 and masked NaN comparisons verified.','Exact original double constant is0x3ef0001000000000, not mathematical1/65535. All16-bit random outputs are covered by one complete state cycle. Managed execution pending.'])
 (B/'reports/native-build-failure-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-build-failure-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=rows,cycleLifetimes=lifetimes),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
