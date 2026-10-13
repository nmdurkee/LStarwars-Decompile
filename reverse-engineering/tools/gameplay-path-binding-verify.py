"""Original PC connection binding/route selection, plus41c120 composition."""
import importlib.util,json,struct,copy,itertools,gzip,random
from pathlib import Path
s=importlib.util.spec_from_file_location('reinit',Path(__file__).with_name('gameplay-reinitialization-verify.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
n=r.x.NativeX86();BASE=r.BASE;A=r.A;P=A+0x2c8;PATH=r.PATH;CON=A+0x31000;NODES=A+0x33000;POSITION=A+0x34000
from unicorn import UC_HOOK_CODE
checks={};errors=[];vectors=[];composed=[];executed=set();authored=[]
def trace(mu,addr,size,user):executed.add(addr)
for a,z in [(0x51b7f0,0x97),(0x51b890,0x17d)]:n.mu.hook_add(UC_HOOK_CODE,trace,begin=a,end=a+z-1)
def edge(o,old=False):
 b=bytearray(0x24);flags=o.get('oldFlags',[0]*4) if old else o.get('flags',[0]*4)
 for i,v in enumerate(flags):r.put(b,i*4,v)
 b[0x10]=o.get('point',0);b[0x11]=1;r.put(b,0x12,o.get('angle',0x2345),2);r.put(b,0x14,o.get('oldMask',5) if old else o.get('routeMask',3),2);r.put(b,0x1c,r.bits(o.get('length',2.75)));return b
def setup(o):
 n.write(A,bytes(0x35000));b=r.pattern(0x10d8,o.get('seed',1));current=o.get('current',0);r.put(b,0x420,PATH);r.put(b,0x424,CON+0x24*current if current>=0 else 0);r.put(b,0x398,A if o.get('reference',True) else 0);r.put(b,0x428,o.get('oldDirection',0),1);r.put(b,0x42e,o.get('stateFlags',1),2);r.put(b,0x402,o.get('membership',0xffff),2);r.put(b,0x404,o.get('selected',255),1);r.put(b,0x405,o.get('cursor',0),1);r.put(b,0x4bc,o.get('permission',0xffffffff))
 z=dict(actor=b,edges=[edge(o,True),edge(o)],points=o.get('points',[[1.25,2.5,-3.75],[6.25,7.5,8.75]]),count=o.get('routeCount',6),position=o.get('position',[9.25,19.5,7.75]))
 n.write(A,b);n.write(0x29899a0,r.SINE_BYTES);n.pack('<I',PATH+0x7c,NODES);n.pack('<B',PATH+0x14,z['count'])
 for i,e in enumerate(z['edges']):n.write(CON+0x24*i,e)
 for i,p in enumerate(z['points']):n.pack('<3f',NODES+0x5c*i+4,*p)
 n.pack('<3f',POSITION,*z['position']);return z
def select(b,z):
 count=z['count'];current=r.u(b,0x424)
 if not count or not current:return
 e=z['edges'][(current-CON)//0x24];mask=r.h(e,0x14)&r.h(b,0x402)
 if not mask:return
 start=b[0x405] if b[0x405]<count else 0;i=start
 while True:
  if (r.shift(i)&65535)&mask:b[0x404]=i;b[0x405]=(i+1)&255;return
  i=(i+1)%count
  if i==start:return
def bind(b,z,identity,direction,x,zpos):
 if not identity or not r.u(b,0x398):r.put(b,0x424,identity);b[0x404]=255;b[0x405]=0;return
 old=r.u(b,0x424);flags=r.h(b,0x42e)
 if old==identity and b[0x428]==direction and (not flags&1 or flags&4):return
 e=z['edges'][(identity-CON)//0x24];required=r.u(e,direction*4)
 if required:
  if required&0x98000000:select(b,z);return
  if not required&r.u(b,0x4bc):return
 if old!=identity or b[0x428]!=direction:
  b[0x428]=direction&255;r.put(b,0x424,identity);b[0x401]=0;point=z['points'][e[0x10]];dx=r.add(x,-r.f(point[0]));dz=r.add(zpos,-r.f(point[2]));angle=(-struct.unpack_from('<h',e,0x12)[0])&0xffffffff;sin=r.SINE[(angle>>1)&32767];cos=r.SINE[((angle+16384)>>1)&32767];rx=r.products(sin,dz,cos,dx);rz=r.products(dz,cos,-dx,sin);divisor=r.fl(r.u(e,0x1c));value=r.fl((r.bits(rz)^r.bits(divisor))&0x80000000) if rz==0 else r.wide.store(r.wide.div(r.wide.wide(rz),r.wide.wide(divisor)));r.put(b,0x42e,r.h(b,0x42e)&~4,2);r.put(b,0x430,r.bits(value));r.put(b,0x434,r.bits(rx))
 flags=r.h(b,0x42e)
 if flags&1 and not flags&4:
  selected=b[0x404];e=z['edges'][(r.u(b,0x424)-CON)//0x24]
  if selected!=255 and not (r.shift(selected)&65535)&r.h(e,0x14):b[0x404]=255
  if b[0x404]==255:select(b,z)
  r.put(b,0x42e,r.h(b,0x42e)|4,2)
def run(o,kind='bind',source=None):
 z=setup(o);before=z['actor'];b=bytearray(before);target=o.get('target',1);identity=CON+0x24*target if target>=0 else 0
 if kind=='select':n.call(0x51b7f0,[P]);select(b,z)
 else:n.call(0x51b890,[P,POSITION,identity,o.get('direction',0)]);bind(b,z,identity,o.get('direction',0),r.f(z['position'][0]),r.f(z['position'][2]))
 got=r.changes(before,n.read(A,0x10d8));want=r.changes(before,b);group='authored' if source else kind;checks[group]=checks.get(group,0)+1
 if got!=want:errors.append(dict(kind=kind,options=o,source=source,got=got,want=want))
 vectors.append(dict(kind=kind,options=o,source=source,native=got))
def composition(o):
 # Existing independent caller model gets a recovered BindPath implementation;
 # original native41c120 calls original51b890 and51b7f0 without interception.
 r.n=n;before=r.setup(o);z=dict(count=6,edges=[edge({}),edge({})],points=[[1.25,2.5,-3.75],[6.25,7.5,8.75]])
 for i,e in enumerate(z['edges']):n.write(CON+i*0x24,e)
 n.pack('<I',PATH+0x7c,NODES)
 for i,p in enumerate(z['points']):n.pack('<3f',NODES+0x5c*i+4,*p)
 for i,s in enumerate(before['spawns']):r.put(s,0x34,CON);s[0x38]=0;n.write(r.SPAWN+0xa4*i,s)
 r.put(before['locator'],0x24,CON+0x24);before['locator'][0x28]=1;n.write(r.LOC,before['locator'])
 r.put(before['actor'],0x398,A);n.pack('<I',A+0x398,A)
 old_effects=r.effects
 def combined_effects(b,name,op):
  old_effects(b,name,op)
  if name=='BindPath':bind(b,z,CON+0x24 if o.get('locator') and o.get('count') else CON,1 if o.get('locator') and o.get('count') else 0,r.fl(r.u(b,0x5c)),r.fl(r.u(b,0x64)))
 r.effects=combined_effects
 try:
  # Callback effects run only at remaining services; BindPath is unhooked.
  n.call(0x41c120,[A,r.SYS]);out,ev=r.model(before,o);ev=[e for e in ev if e[0]!='BindPath'];after=dict(actor=n.read(A,0x10d8),formation=n.read(r.FORM,len(before['formation'])),origin=list(n.unpack('<III',0x93d620)));got=r.summarize(before,after,r.events);want=r.summarize(before,out,ev)
 finally:r.effects=old_effects
 checks['reinitializationComposition']=checks.get('reinitializationComposition',0)+1
 if got!=want:errors.append(dict(kind='composition',options=o,got=got,want=want))
 composed.append(dict(options=o,native=got))
def main():
 for target,reference,current,direction,flags in itertools.product([-1,0,1],[False,True],[-1,0,1],[0,1],[0,1,4,5,0xffff]):run(dict(target=target,reference=reference,current=current,direction=direction,stateFlags=flags))
 for required,permission in itertools.product([0,1,4,0x8000000,0x10000000,0x80000000,0x20000000,0xffffffff],[0,1,4,0xffffffff]):run(dict(flags=[required]*4,permission=permission,selected=2,cursor=1))
 for direction,oldDirection in itertools.product(range(9),[0,1,8,255]):run(dict(direction=direction,oldDirection=oldDirection))
 for count,cursor,member in itertools.product([0,1,2,15,16,17,32,64,65,255],[0,1,15,16,31,63,254,255],[0,1,2,0x8000,0xffff]):run(dict(routeCount=count,cursor=cursor,membership=member,oldMask=0xffff),'select')
 for current in [-1,0,1]:run(dict(current=current),'select')
 for selected,routeMask,stateFlags in itertools.product([0,1,15,16,31,32,63,64,128,255],[0,1,2,0x8000,0xffff],[0,1,4,5]):run(dict(selected=selected,routeMask=routeMask,stateFlags=stateFlags))
 for angle,length,position in itertools.product([0,16384,32768,49152,65535],[.125,-.125,3.75],[[1.25,999,-3.75],[0,0,0],[-100.25,0,200.5]]):run(dict(angle=angle,length=length,position=position))
 # Bounded authored sample: first/middle/last valid edge of every saved path.
 for file in sorted((BASE/'reports/gameplay-navigation/data').rglob('*.json.gz')):
  doc=json.loads(gzip.decompress(file.read_bytes()))
  for path in doc['paths']:
   edges=path['connections']
   for ix in sorted(set([0,len(edges)//2,len(edges)-1])) if edges else []:
    e=edges[ix];length=e['distanceCandidates'][1]
    if length==0 or not (0<=e['to']<len(path['points'])):continue
    point=path['points'][e['to']]['position'];position=path['points'][e['from']]['position'];source=dict(source=doc['source'],sha256=doc['sha256'],path=path['index'],connection=ix,offset=e['offset'])
    for direction in [0,1]:run(dict(flags=[e['toFlags'],e['fromFlags'],e['toFlags'],e['fromFlags']],angle=e['unknownShorts'][0],routeMask=e['unknownShorts'][1],length=length,points=[point,point],position=position,direction=direction),source=source)
    authored.append(source)
 # Add the remaining lifecycle adapters only after direct helper fixtures.
 for addr in r.OPERATIONS:
  if addr!=0x51b890:n.mu.hook_add(UC_HOOK_CODE,r.hook,begin=addr,end=addr)
 for loc,count,col,row in itertools.product([False,True],[0,1],[0,1,7],[0,1,7]):composition(dict(locator=loc,count=count,column=col,row=row,formation=True,slot=row*3+col))
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,size in [(0x51b7f0,0x97),(0x51b890,0x17d)]:functions.append(dict(address=hex(start),endExclusive=hex(start+size),instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed) for i in d.disasm(n.read(start,size),start)]))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:5],authoredSampleConnections=len(authored),authoredFiles=len(set(e['source'] for e in authored)),authoredPaths=len(set((e['source'],e['path']) for e in authored)),method='Unmodified51b890/51b7f0 with actual rotation and CRT shift, independent64-significand finite arithmetic model, all actor bytes compared. Additionally original41c120 executes both helpers as a chain; other lifecycle service boundaries remain recorded. Authored edges sampled first/middle/last per saved path and both direction flags.',instructionCoverage={p['address']:dict(total=len(p['instructions']),executed=sum(i['executed'] for i in p['instructions']),missing=[i['address'] for i in p['instructions'] if not i['executed']]) for p in functions},limits=['Prepared finite loaded records; zero connection length, malformed pointers, nonfinite values and direction-word reads outside36-byte record excluded.','Native uninitialized local Y is copied by rotation but never consumed by either persistent X/Z result; source intentionally computes only defined X/Z.','Authored samples use source node/edge coordinates and flags, with synthetic route membership/permission state; no live path traversal or collision is claimed.','Managed compile only; independent-model native validation is distinct from pending managed replay.'])
 (BASE/'reports/gameplay-path-binding-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-binding-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors,compositions=composed),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-path-binding-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report));
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
