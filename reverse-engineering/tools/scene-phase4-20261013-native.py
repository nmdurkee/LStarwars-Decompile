"""Actual finite plane producers, stack provenance and populated tree->clip controls."""
import sys,json,gzip,struct,hashlib,random,math,importlib.util
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase4-20261013'
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE,UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
word=lambda v:struct.unpack('<I',struct.pack('<f',v))[0]
words=lambda a:[word(v)for v in a]
errors=[];checks=0;rng=random.Random(0x5d86f0);producerCases=[];transformCases=[];composedCases=[];visits=[];lastWrites={};stackTracking=False;matrixCalls=0
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'native':a,'expected':e})
def writeHook(mu,access,address,size,value,_):
 if stackTracking:
  for offset in range(size):lastWrites[address+offset]=hex(mu.reg_read(UC_X86_REG_EIP))
def hook(mu,address,size,_):
 global matrixCalls
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x5c1240:
  ret,out,a,b=n.unpack('<4I',sp);aa=n.unpack('<16f',a);bb=n.unpack('<16f',b);product=[f32(sum(float(aa[i*4+k])*bb[k*4+j]for k in range(4)))for i in range(4)for j in range(4)];n.pack('<16f',out,*product);mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);matrixCalls+=1
 elif address==0x5d8b60:
  _,center,extent,far,individual=n.unpack('<5I',sp);scratch=((sp-4)&~15)-4;visits.append({'center':list(n.unpack('<3f',center)),'extent':list(n.unpack('<3f',extent)),'farWord':far,'individual':individual,'scratchWord':n.unpack('<I',scratch)[0],'scratchAddress':hex(scratch),'lastWrite':({'instruction':','.join(sorted(set(lastWrites.get(scratch+i,'external seed')for i in range(4)))),'byteInstructions':[lastWrites.get(scratch+i)for i in range(4)]}if any(scratch+i in lastWrites for i in range(4))else None),'returnAddress':hex(n.unpack('<I',sp)[0])})
 elif address in(0x5d8e97,0x5d8f5e):visits[-1]['nativeResult']=mu.reg_read(UC_X86_REG_EAX)
 elif address in(0x5d8c73,0x5d8d7c):
  if visits:visits[-1].setdefault('residueReadWords',[]).append(n.unpack('<I',sp+0x3c)[0])
n.mu.hook_add(UC_HOOK_MEM_WRITE,writeHook,begin=n.STACK,end=n.STACK+0xffff)
for a in[0x5c1240,0x5d8b60,0x5d8e97,0x5d8f5e,0x5d8c73,0x5d8d7c]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def modelBuild(near,scales,template):
 ns=f32(near*near);pairs=[]
 for w,h in[(f32(near*scales[0]),f32(near*scales[1])),(f32(near*scales[2]),f32(near*scales[3]))]:
  rw=f32(1/f32(math.sqrt(x87.store(x87.add(x87.mul(x87.wide(w),x87.wide(w)),x87.wide(ns))))));rh=f32(1/f32(math.sqrt(x87.store(x87.add(x87.mul(x87.wide(h),x87.wide(h)),x87.wide(ns))))));a=list(template);a[0]=f32(-near*rw);a[1]=-a[0];a[8]=f32(-w*rw);a[9]=a[8];a[6]=f32(near*rh);a[7]=-a[6];a[10]=f32(-h*rh);a[11]=a[10];pairs.append(a)
 return pairs

def modelTransform(view,local,direction,position):
 mul=lambda a,b:[f32(sum(float(a[i*4+k])*b[k*4+j]for k in range(4)))for i in range(4)for j in range(4)]
 outer,inner=[mul(view,a)for a in local];q=x87.store(x87.add(x87.add(x87.mul(x87.wide(direction[1]),x87.wide(position[1])),x87.mul(x87.wide(direction[0]),x87.wide(position[0]))),x87.mul(x87.wide(direction[2]),x87.wide(position[2]))));q=-0. if all(a==0 or b==0 for a,b in zip(direction,position))and all((word(a)^word(b))&0x80000000 for a,b in zip(direction,position))else q;return {'outer':outer,'inner':inner,'absOuter':[abs(v)for v in outer[:12]]+[0.]*4,'absInner':[abs(v)for v in inner[:12]]+[0.]*4,'depth':direction+[-q],'absDepth':[abs(v)for v in direction]+[0.]}
def nativePlanes():return {k:list(n.unpack('<'+str(c)+'f',a))for k,a,c in[('outer',0x96e4f0,16),('inner',0x96d940,16),('absOuter',0x971ac0,16),('absInner',0x971660,16),('depth',0x971880,4),('absDepth',0x96e540,4)]}
def setup(near,far,scales,template,view,direction,position):
 n.pack('<2f',0x973730,near,far);n.pack('<16f',0x95e600,*template);n.pack('<16f',0x80b708,*view);n.pack('<3f',0x973708,*direction);n.pack('<3f',0x973718,*position)
 for a,v in zip([0x966378,0x97313c,0x966270,0x96dce4],scales):n.pack('<f',a,v)
PLANE_START=0x96d800;PLANE_END=0x973a00
BUILD_WRITES=[(0x96d8b0,64),(0x96d980,64),(0x973984,4)]
TRANSFORM_WRITES=[(0x96e4f0,64),(0x96d940,64),(0x971ac0,64),(0x971660,64),(0x971880,16),(0x96e540,16)]
def confinement(before,ranges):
 after=bytearray(n.read(PLANE_START,PLANE_END-PLANE_START))
 for address,size in ranges:after[address-PLANE_START:address-PLANE_START+size]=before[address-PLANE_START:address-PLANE_START+size]
 return after==before
for case in range(1600):
 near=f32([.0001,.1,1.,3.,100.,100000.][case%6]if case<100 else 2**rng.uniform(-14,15));scales=[f32(rng.uniform(-8,8))for _ in range(4)];
 if case<100:scales[case%4]=0.
 template=[0.]*16 if case%3==0 else[1. if i%5==0 else 0. for i in range(16)]if case%3==1 else[f32(rng.uniform(-4,4))for _ in range(16)]
 view=[f32(rng.uniform(-4,4))for _ in range(16)];direction=[f32(rng.uniform(-2,2))for _ in range(3)];position=[f32(rng.uniform(-100,100))for _ in range(3)];far=f32(near+1000);setup(near,far,scales,template,view,direction,position);n.pack('<I',0x973984,0x1234)
 beforePlane=n.read(PLANE_START,PLANE_END-PLANE_START);n.call(0x5d86f0);ck(confinement(beforePlane,BUILD_WRITES),True,['buildWriteConfinement',case]);actual=[list(n.unpack('<16f',a))for a in[0x96d8b0,0x96d980]];expected=modelBuild(near,scales,template);ck([words(a)for a in actual],[words(a)for a in expected],['build',case]);ck(n.unpack('<I',0x973984)[0],1,['initialized',case]);producerCases.append({'near':near,'scales':scales,'template':template,'nativeLocalWords':[words(a)for a in actual]})
 beforePlane=n.read(PLANE_START,PLANE_END-PLANE_START);n.call(0x5d8950);ck(confinement(beforePlane,TRANSFORM_WRITES),True,['transformWriteConfinement',case]);actualP=nativePlanes();expectedP=modelTransform(view,expected,direction,position);ck({k:words(v)for k,v in actualP.items()},{k:words(v)for k,v in expectedP.items()},['transform',case]);transformCases.append({'view':view,'local':expected,'direction':direction,'position':position,'nativePlaneWords':{k:words(v)for k,v in actualP.items()}})

# Exact signed-zero depth dot and unary-negation boundary, word-encoded inputs.
for case in range(32):
 view=[1. if i%5==0 else 0. for i in range(16)];local=modelBuild(1.,[1.,1.,1.,1.],[0.]*16);zeros=[struct.unpack('<f',struct.pack('<I',0x80000000 if case&(1<<i)else 0))[0]for i in range(3)]
 direction,position=(zeros,[1.,-2.,3.])if case<8 else([1.,-2.,3.],zeros)if case<16 else(zeros,[0.,-0.,0.])if case<24 else([-0.,0.,-0.],zeros)
 setup(1.,100.,[1.]*4,[0.]*16,view,direction,position)
 for address,values in zip([0x96d8b0,0x96d980],local):n.pack('<16f',address,*values)
 n.call(0x5d8950);actualP=nativePlanes();expectedP=modelTransform(view,local,direction,position);ck({k:words(v)for k,v in actualP.items()},{k:words(v)for k,v in expectedP.items()},['signedZeroTransform',case]);transformCases.append({'view':view,'local':local,'direction':direction,'position':position,'directionWords':words(direction),'positionWords':words(position),'nativePlaneWords':{k:words(v)for k,v in actualP.items()}})

def classify(p,c,e,far,ind,stale):
 dot=lambda v,m,j,d:x87.dot3_plus_constant(*v,m[j],m[j+4],m[j+8],d)
 radius=x87.dot3_plus_constant(*e,*p['absDepth'][:3],0);depth=f32(x87.dot3_plus_constant(*c,*p['depth'][:3],0)+p['depth'][3]);fo=f32(depth-far);no=f32(depth-p['near'])
 if not(fo<=radius and-radius<=no):return 0
 for name,absname in[('outer','absOuter')]+([('inner','absInner')]if ind else[]):
  d=[dot(c,p[name],j,p[name][12+j])for j in range(4)];r=[dot(e,p[absname],j,p[absname][12+j])for j in range(3)]+[struct.unpack('<f',struct.pack('<I',stale))[0]]
  if not all(a<=b for a,b in zip(d,r)):return 0
  if all(a<=-b for a,b in zip(d,r)):return 2 if name=='outer'and not ind and(-radius<fo or no<radius)else 1
 return 2
CTX=n.DATA;TREE=CTX+0x1000;NODES=CTX+0x2000;NODEB=CTX+0x3000;ITEMB=CTX+0x5000;LIST=CTX+0x7000;ROOTS=CTX+0x8000;FARS=CTX+0x9000;BITS=CTX+0xa000;PREV=CTX+0xb000;SCENE=CTX+0xc000;ITEMS=CTX+0xd000;CLIPS=CTX+0xf000;COUNTS=CTX+0x11000

def orbits(a,i,v):a[i>>2]|=v<<((i&3)*2)
for case in range(192):
 logical=case//4;rng=random.Random(0x5d8fb0+logical)
 near=.1;far=[25.,100.,300.][logical%3];scales=[1.2,.8,.9,.6];scales=[f32(v)for v in scales];template=[0.]*16;position=[float(logical%5-2),float(logical%3-1),float(logical%7-3)];direction=[0.,0.,1.];view=[1.,0,0,0,0,1.,0,0,0,0,1.,0,-position[0],-position[1],-position[2],1.];near=f32(near);setup(near,far,scales,template,view,direction,position)
 initialized=case%2!=0;n.call(0x5d86f0);n.pack('<I',0x973984,int(initialized));n.pack('<I',0x80ba14,1);n.pack('<I',0x973988,0);flags=rng.randrange(1<<32);n.write(CTX,bytes(0x40));n.pack('<I',CTX+0x14,TREE);n.pack('<I',CTX+0x20,BITS);n.pack('<I',CTX+0x28,flags)
 members=list(range(32));roots=[0,4,5,6,7];farLimits=[0.,50.,0.,100.,25.];nodes=[];nodeBounds=[];itemBounds=[]
 for i in range(8):
  nodes.append([i,4,3 if i==0 else 0,1 if i==0 else 0,4,4*i]);nodeBounds.append({'center':[0.,0.,30.]if i==0 else[float(rng.randrange(-40,41)),0.,float(rng.randrange(-5,141))],'extent':[40.,40.,40.]if i==0 else[float(rng.randrange(11))]*3})
 for i in range(32):itemBounds.append({'center':[float(rng.randrange(-30,31)),float(rng.randrange(-20,21)),float(rng.randrange(-10,161))],'extent':[float(rng.randrange(6))]*3})
 tree={'nodes':nodes,'nodeBounds':nodeBounds,'itemBounds':itemBounds,'members':members,'roots':roots,'far':farLimits};n.write(TREE,bytes(0x40));n.pack('<I',TREE+8,LIST);n.pack('<I',TREE+12,ITEMB);n.pack('<I',TREE+0x14,NODES);n.pack('<I',TREE+0x18,NODEB);n.pack('<H',TREE+0x1c,len(roots));n.pack('<I',TREE+0x20,ROOTS);n.pack('<I',TREE+0x24,FARS);n.pack('<32H',LIST,*members);n.pack('<5H',ROOTS,*roots);n.pack('<5f',FARS,*farLimits)
 for i,v in enumerate(nodes):n.pack('<6H',NODES+12*i,*v)
 for addr,records in[(NODEB,nodeBounds),(ITEMB,itemBounds)]:
  for i,b in enumerate(records):n.pack('<8f',addr+32*i,*b['center'],0,*b['extent'],0)
 before=bytes(rng.randrange(256)for _ in range(8));previous=before if logical%4==0 else bytes(rng.randrange(256)for _ in range(8));n.write(BITS,before);n.write(PREV,previous);n.write(n.STACK,struct.pack('<f',[-100.,0.,1.,100.][case%4])*0x4000);lastWrites.clear();visits.clear();stackTracking=True;n.call(0x5d8fb0,[CTX]);stackTracking=False;actualBits=n.read(BITS,8);p=nativePlanes();p.update(near=near,globalFar=far);bits=bytearray(before);at=0
 for ri in range(4,-1,-1):
  rootFar=farLimits[ri]or far;stack=[roots[ri]]
  while stack:
   node=nodes[stack.pop()];b=nodeBounds[node[0]];v=visits[at];at+=1;result=classify(p,b['center'],b['extent'],rootFar,0,v['scratchWord']);ck(result,v['nativeResult'],['composedNode',case,at]);ck([v['center'],v['extent'],v['farWord'],v['individual']],[b['center'],b['extent'],word(rootFar),0],['nodeOrder',case,at])
   if not result:continue
   if result==1:
    for i in members[node[5]:node[5]+node[1]]:orbits(bits,i,1)
   else:
    stack.extend(range(node[3],node[3]+node[2]))
    for li in range(node[5],node[5]+node[4]):
     b=itemBounds[li];v=visits[at];at+=1;result=classify(p,b['center'],b['extent'],rootFar,1,v['scratchWord']);ck(result,v['nativeResult'],['composedLeaf',case,at]);ck([v['center'],v['extent'],v['farWord'],v['individual']],[b['center'],b['extent'],word(rootFar),1],['leafOrder',case,at]);orbits(bits,members[li],result)
 ck(at,len(visits),['traceCount',case]);ck(actualBits.hex(),bits.hex(),['composedBits',case]);ck(n.unpack('<I',CTX+0x28)[0],flags|16,['wrapperFlags',case]);ck(n.unpack('<I',0x973984)[0],1,['wrapperInit',case]);ck(n.unpack('<I',0x973988)[0],CTX,['wrapperContext',case])
 for vi,v in enumerate(visits):
  for got in v.get('residueReadWords',[]):ck(got,v['scratchWord'],['residueUnwritten',case,vi])
 # Actual downstream consumer uses the same packed buffer, no visibility oracle.
 parity=logical%2;n.write(SCENE,bytes(0x100));n.pack('<I',SCENE+8,ITEMS);n.pack('<I',SCENE+0x10,32);n.pack('<I',SCENE+0x14,CLIPS);n.pack('<I',SCENE+0x18,COUNTS);n.pack('<2I',SCENE+0x30,*([BITS,PREV]if parity==0 else[PREV,BITS]));n.pack('<I',SCENE+0x74,parity*0x8000);itemBefore=bytes(rng.randrange(256)for _ in range(1024));n.write(ITEMS,itemBefore);expectedItems=bytearray(itemBefore)
 for i in range(32):
  pointer=CLIPS+0x800+i*4;n.pack('<I',pointer,i*2+1);n.pack('<3I',CLIPS+i*12,0,0,pointer);n.pack('<H',COUNTS+i*2,1)
  w=i//16*4
  if bits[w:w+4]!=previous[w:w+4]:control=3 if(bits[i>>2]>>((i&3)*2))&3 else 0;expectedItems[32*i+1]=control;expectedItems[32*i+17]=control
 n.call(0x5df910,regs={UC_X86_REG_ESI:SCENE});nativeItems=n.read(ITEMS,1024);ck(nativeItems.hex(),expectedItems.hex(),['clipControls',case]);ck(n.read(BITS,8).hex(),bits.hex(),['consumerPreservesBits',case]);composedCases.append({'near':near,'far':far,'scales':scales,'template':template,'view':view,'direction':direction,'position':position,'initialPlanesInitialized':initialized,'stackSeed':[-100.,0.,1.,100.][case%4],'sameGeometryGroup':logical,'flags':flags,'tree':tree,'beforeHex':before.hex(),'previousHex':previous.hex(),'parity':parity,'nativeHex':actualBits.hex(),'nativeFlags':flags|16,'nativeVisits':list(visits),'itemBeforeHex':itemBefore.hex(),'nativeItemHex':nativeItems.hex()})
sameGeometryChanged=sum(len({c['nativeHex']for c in composedCases if c['sameGeometryGroup']==g})>1 for g in range(48));ck(sameGeometryChanged>0,True,'sameGeometryStackSeedChangesOutput')
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly={hex(a):[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in md.disasm(n.read(a,size),a)]for a,size in[(0x5d86f0,0x1e5),(0x5d8950,0x20f),(0x5b44c0,0x15),(0x5c1600,0x5a),(0x5c1240,0x15),(0x5d8fb0,0x6b),(0x5d8e20,0x186),(0x5d8b60,0x2b5),(0x5df910,0x180)]}
(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'functions':assembly},indent=2)+'\n')
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'producerCases':producerCases,'transformCases':transformCases,'composedCases':composedCases},f)
provenance={};residueWords={}
for c in composedCases:
 for v in c['nativeVisits']:
  key=(v['lastWrite']or{}).get('instruction','initial stack seed');provenance[key]=provenance.get(key,0)+1;w=hex(v['scratchWord']);residueWords[w]=residueWords.get(w,0)+1
report={'schema':'original-plane-producer-tree-consumer-v1','passed':not errors,'checks':checks,'binarySHA256':n.sha256,'counts':{'producerCases':len(producerCases),'transformCases':len(transformCases),'composedTreeToClipCases':len(composedCases),'retainedPortableReplayCases':len(producerCases)+len(transformCases)+len(composedCases),'nestedPredicateCalls':sum(len(c['nativeVisits'])for c in composedCases),'externalMatrixAdapterCalls':matrixCalls,'sameGeometryStackGroups':48,'sameGeometryGroupsWithChangedBits':sameGeometryChanged},'errors':errors[:30],'adapters':{'0x5c1240':'Explicit finite scalar D3DX 4x4 multiply: each dot evaluated in binary64 then spilled to float32. Platform D3DX implementation is not recovered; original wrappers/producers/predicate/tree/clip-control instructions execute unchanged.'},'stackResidue':{'lastWriteInstructions':provenance,'wordCounts':residueWords,'scope':'Whole actual0x5d8fb0->0x5d8e20->0x5d8b60 call chain with seeded prior stack. Writer provenance observes only this chain; seed reflects external prior stack. Fourth-radius dependence remains explicit, not replaced by zero.'},'limits':['Finite near>0;finite coefficients/matrix/direction/position with finite nonzero norm and finite intermediate outputs. Runtime0x95e600 copied template supplied explicitly;initialization/lifetime of template outside scope.','D3DX arithmetic remains explicit matrix adapter; not an assertion of imported D3DX CPU/GPU numerical equivalence.','Populated valid synthetic u16 trees,finite nonnegative extents,acyclic/pendingstack<=100. Exact finite fourth-radius residue supplied perpredicate. No live camera or authored tree loader claim.','Tree packed output is intentionally bound to selected scene clip buffer for original5df910 consumption; this verifies these contracts composed, not complete5f3c80/context resolver or scene submission.','Native/Python own-state contract verified; C# compiled replay remains separate and pending.'],'fixtureFile':PREFIX+'-native-fixtures.json.gz'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
