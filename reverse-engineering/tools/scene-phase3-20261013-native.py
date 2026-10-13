"""Actual PC tree predicate/root traversal using original-generated prepared planes."""
import sys,json,gzip,struct,hashlib,random,importlib.util
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports';PREFIX='scene-phase3-20261013'
sys.path.insert(0,str(P/'python-packages'))
def load(name,file):
 s=importlib.util.spec_from_file_location(name,P/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
nx=load('nx','native-x86.py');x87=load('x87','animation-x87.py');n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0]
CTX=n.DATA;TREE=CTX+0x1000;NODES=CTX+0x2000;NODEB=CTX+0x3000;ITEMB=CTX+0x6000;LIST=CTX+0x9000;ROOTS=CTX+0xa000;FARS=CTX+0xb000;BITS=CTX+0xc000;BOUND=CTX+0xd000
checks=0;errors=[];predicateCases=[];walkCases=[];planeCases=[];visits=[];matrixCalls=0;rng=random.Random(0x5d8e20)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e:errors.append({'label':label,'native':a,'expected':e})
def hook(mu,address,size,_):
 global matrixCalls
 if address==0x5c1240:
  sp=mu.reg_read(UC_X86_REG_ESP);ret,out,a,b=n.unpack('<4I',sp);aa=n.unpack('<16f',a);bb=n.unpack('<16f',b);product=[f32(sum(float(aa[i*4+k])*bb[k*4+j]for k in range(4)))for i in range(4)for j in range(4)];n.pack('<16f',out,*product);mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);matrixCalls+=1
 elif address==0x5d8b60:
  sp=mu.reg_read(UC_X86_REG_ESP);_,center,extent,far,individual=n.unpack('<5I',sp);scratch=((sp-4)&~15)-4;visits.append({'center':list(n.unpack('<3f',center)),'extent':list(n.unpack('<3f',extent)),'farWord':far,'individual':individual,'scratchWord':n.unpack('<I',scratch)[0]})
n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x5c1240,end=0x5c1240);n.mu.hook_add(UC_HOOK_CODE,hook,begin=0x5d8b60,end=0x5d8b60)
def planes():return {'outer':list(n.unpack('<16f',0x96e4f0)),'inner':list(n.unpack('<16f',0x96d940)),'absOuter':list(n.unpack('<16f',0x971ac0)),'absInner':list(n.unpack('<16f',0x971660)),'depth':list(n.unpack('<4f',0x971880)),'absDepth':list(n.unpack('<4f',0x96e540)),'near':n.unpack('<f',0x973730)[0],'globalFar':n.unpack('<f',0x973734)[0]}
def prepare(k):
 near=[.1,1,3,8][k%4];far=[25,100,300][k%3];position=[float(k%5-2),float(k%3-1),float(k%7-3)];view=[1.,0,0,0,0,1.,0,0,0,0,1.,0,-position[0],-position[1],-position[2],1.]
 n.pack('<16f',0x80b708,*view);n.pack('<3f',0x973708,0,0,1);n.pack('<3f',0x973718,*position);n.pack('<2f',0x973730,near,far)
 for addr,v in[(0x966378,1.2),(0x97313c,.8),(0x966270,.9),(0x96dce4,.6)]:n.pack('<f',addr,v)
 n.pack('<I',0x973984,0);n.call(0x5d86f0);n.call(0x5d8950);out=planes();planeCases.append({'position':position,'view':view,'planes':out});return out
def dot(p,m,j,d):return x87.dot3_plus_constant(*p,m[j],m[j+4],m[j+8],d)
def classify(p,c,e,far,individual,scratchWord):
 radius=x87.dot3_plus_constant(*e,*p['absDepth'][:3],0);depth=f32(x87.dot3_plus_constant(*c,*p['depth'][:3],0)+p['depth'][3]);farOffset=f32(depth-far);nearOffset=f32(depth-p['near'])
 if not(farOffset<=radius and -radius<=nearOffset):return 0
 d=[dot(c,p['outer'],j,p['outer'][12+j])for j in range(4)];r=[dot(e,p['absOuter'],j,p['absOuter'][12+j])for j in range(3)]+[struct.unpack('<f',struct.pack('<I',scratchWord))[0]]
 if not all(a<=b for a,b in zip(d,r)):return 0
 if all(a<=-b for a,b in zip(d,r)):
  return 2 if not individual and(-radius<farOffset or nearOffset<radius)else 1
 if individual:
  d=[dot(c,p['inner'],j,p['inner'][12+j])for j in range(4)];r=[dot(e,p['absInner'],j,p['absInner'][12+j])for j in range(3)]+[struct.unpack('<f',struct.pack('<I',scratchWord))[0]]
  if not all(a<=b for a,b in zip(d,r)):return 0
  if all(a<=-b for a,b in zip(d,r)):return 1
 return 2
for k in range(12):
 p=prepare(k)
 for j in range(200):
  c=[f32(rng.uniform(-40,40)),f32(rng.uniform(-30,30)),f32(rng.uniform(-20,340))];e=[f32(rng.uniform(0,20))for _ in range(3)];far=f32(rng.choice([p['globalFar'],20.,50.,150.]));ind=j&1;n.pack('<8f',BOUND,*c,0,*e,0);visits.clear();a=n.call(0x5d8b60,[BOUND,BOUND+16,struct.unpack('<I',struct.pack('<f',far))[0],ind]);residue=visits[-1]['scratchWord'];evalue=classify(p,c,e,far,ind,residue);ck(a,evalue,['predicate',k,j]);predicateCases.append({'planeIndex':k,'center':c,'extent':e,'far':far,'individual':ind,'native':a,'scratchWord':visits[-1]['scratchWord']})
# Controlled finite prior-stack words prove this is a state dependency.
p=prepare(0)
for x in[-20.,0.,20.]:
 for y in[-5.,5.]:
  for z in[.1,20.]:
   for extent in[0.,5.]:
    for stale in[-100.,-1.,0.,1.,100.]:
     c=[x,y,z];e=[extent]*3;far=50.;n.pack('<8f',BOUND,*c,0,*e,0);n.pack('<f',n.STACK+0xdfec,stale);a=n.call(0x5d8b60,[BOUND,BOUND+16,struct.unpack('<I',struct.pack('<f',far))[0],1]);word=visits[-1]['scratchWord'];ck(a,classify(p,c,e,far,1,word),['seededResidue',x,y,z,extent,stale]);ck(word,struct.unpack('<I',struct.pack('<f',stale))[0],['residueUnwritten',stale]);predicateCases.append({'planeIndex':0,'center':c,'extent':e,'far':far,'individual':1,'native':a,'scratchWord':word,'seededResidue':True})
# Ordered predicates at exact near/far/side tangency,including zero extents.
for k,p in enumerate([x['planes']for x in planeCases[:12]]):
 for z in[p['near']-1,p['near'],p['near']+1,p['globalFar']-1,p['globalFar'],p['globalFar']+1]:
  for radius in[0.,1.]:
   for ind in[0,1]:
    c=[0.,0.,z];e=[radius]*3;far=p['globalFar']
    for addr,key,count in[(0x96e4f0,'outer',16),(0x96d940,'inner',16),(0x971ac0,'absOuter',16),(0x971660,'absInner',16),(0x971880,'depth',4),(0x96e540,'absDepth',4)]:n.pack('<'+str(count)+'f',addr,*p[key])
    n.pack('<2f',0x973730,p['near'],p['globalFar']);n.pack('<8f',BOUND,*c,0,*e,0);a=n.call(0x5d8b60,[BOUND,BOUND+16,struct.unpack('<I',struct.pack('<f',far))[0],ind]);ck(a,classify(p,c,e,far,ind,visits[-1]['scratchWord']),['boundary',k,z,radius,ind]);predicateCases.append({'planeIndex':k,'center':c,'extent':e,'far':far,'individual':ind,'native':a,'scratchWord':visits[-1]['scratchWord']})
def packed_or(bits,i,value):bits[i>>2]|=value<<((i&3)*2)
def model(tree,p,before,enabled,present,nativeTrace):
 bits=bytearray.fromhex(before);trace=[]
 if not enabled or not present:return bytes(bits),trace
 for ri in range(len(tree['roots'])-1,-1,-1):
  far=tree['far'][ri]or p['globalFar'];stack=[tree['roots'][ri]]
  while stack:
   ni=stack.pop();node=tree['nodes'][ni];b=tree['nodeBounds'][node[0]];scratchWord=nativeTrace[len(trace)]['scratchWord'];result=classify(p,b['center'],b['extent'],far,0,scratchWord);trace.append({'center':b['center'],'extent':b['extent'],'farWord':struct.unpack('<I',struct.pack('<f',far))[0],'individual':0,'scratchWord':scratchWord})
   if not result:continue
   if result==1:
    for i in tree['members'][node[5]:node[5]+node[1]]:packed_or(bits,i,1)
   else:
    stack.extend(range(node[3],node[3]+node[2]))
    for li in range(node[5],node[5]+node[4]):
     b=tree['itemBounds'][li];scratchWord=nativeTrace[len(trace)]['scratchWord'];result=classify(p,b['center'],b['extent'],far,1,scratchWord);trace.append({'center':b['center'],'extent':b['extent'],'farWord':struct.unpack('<I',struct.pack('<f',far))[0],'individual':1,'scratchWord':scratchWord});packed_or(bits,tree['members'][li],result)
 return bytes(bits),trace
for k in range(160):
 p=prepare(k%12);nodes=[];nodeBounds=[];itemBounds=[];members=[]
 for ni in range(8):
  start=len(members);number=rng.randrange(1,5)
  for q in range(number):members.append(rng.randrange(256));itemBounds.append({'center':[f32(rng.uniform(-30,30)),f32(rng.uniform(-20,20)),f32(rng.uniform(-10,160))],'extent':[f32(rng.uniform(0,5))for _ in range(3)]})
  nodes.append([ni,number,3 if ni==0 else 0,1 if ni==0 else 0,number,start]);nodeBounds.append({'center':[0.,0.,30.]if ni==0 else[f32(rng.uniform(-40,40)),0.,f32(rng.uniform(-5,140))],'extent':[40.,40.,40.]if ni==0 else[f32(rng.uniform(0,10))for _ in range(3)]})
 tree={'nodes':nodes,'nodeBounds':nodeBounds,'itemBounds':itemBounds,'members':members,'roots':[0,4,5,6,7],'far':[0.,50.,0.,100.,25.]};enabled=k%5!=0;present=k%7!=0;before=bytes(rng.randrange(256)for _ in range(64));flags=rng.randrange(1<<32);n.write(CTX,bytes(0x40));n.pack('<I',CTX+0x14,TREE if present else 0);n.pack('<I',CTX+0x20,BITS);n.pack('<I',CTX+0x28,flags);n.write(TREE,bytes(0x40));n.pack('<I',TREE+8,LIST);n.pack('<I',TREE+12,ITEMB);n.pack('<I',TREE+0x14,NODES);n.pack('<I',TREE+0x18,NODEB);n.pack('<H',TREE+0x1c,len(tree['roots']));n.pack('<I',TREE+0x20,ROOTS);n.pack('<I',TREE+0x24,FARS);n.pack('<'+str(len(members))+'H',LIST,*members);n.pack('<5H',ROOTS,*tree['roots']);n.pack('<5f',FARS,*tree['far'])
 for i,v in enumerate(nodes):n.pack('<6H',NODES+12*i,*v)
 for address,records in[(NODEB,nodeBounds),(ITEMB,itemBounds)]:
  for i,b in enumerate(records):n.pack('<8f',address+32*i,*b['center'],0,*b['extent'],0)
 n.write(BITS-1,b'\xac'+before+b'\xbd');n.pack('<I',0x80ba14,int(enabled));n.pack('<I',0x973988,0x12345678);n.pack('<I',0x973984,k%2);visits.clear();n.call(0x5d8fb0,[CTX]);output=n.read(BITS,64);expected,trace=model(tree,p,before.hex(),enabled,present,visits);ck(output.hex(),expected.hex(),['treeBits',k]);ck(visits,trace,['treeOrder',k]);ck(n.unpack('<I',CTX+0x28)[0],(flags|16)if enabled and present else(flags&~16),['treeFlags',k]);ck(n.unpack('<I',0x973988)[0],CTX if enabled and present else 0x12345678,['activeContext',k]);ck(n.read(BITS-1,1).hex()+n.read(BITS+64,1).hex(),'acbd',['canaries',k]);ck(bool(n.unpack('<I',0x973984)[0]),bool(k%2)or(enabled and present),['planesInitialized',k]);walkCases.append({'planes':p,'tree':tree,'enabled':enabled,'present':present,'flags':flags,'beforeHex':before.hex(),'nativeHex':output.hex(),'nativeFlags':n.unpack('<I',CTX+0x28)[0],'nativeVisits':list(visits),'nativeCurrentContextChanged':n.unpack('<I',0x973988)[0]==CTX,'initialPlanesInitialized':bool(k%2),'nativePlanesInitialized':bool(n.unpack('<I',0x973984)[0])})
# Empty root arrays still initialize/transform planes on active tree entry.
for enabled in[False,True]:
 for present in[False,True]:
  for initialized in[False,True]:
   p=prepare(0);tree={'nodes':[],'nodeBounds':[],'itemBounds':[],'members':[],'roots':[],'far':[]};flags=0x76543210;before=bytes([0xa5])*64;n.write(CTX,bytes(0x40));n.pack('<I',CTX+0x14,TREE if present else 0);n.pack('<I',CTX+0x20,BITS);n.pack('<I',CTX+0x28,flags);n.pack('<H',TREE+0x1c,0);n.write(BITS,before);n.pack('<I',0x80ba14,int(enabled));n.pack('<I',0x973988,0x12345678);n.pack('<I',0x973984,int(initialized));visits.clear();n.call(0x5d8fb0,[CTX]);active=enabled and present;ck(n.read(BITS,64).hex(),before.hex(),'emptyBits');ck(visits,[],'emptyVisits');ck(n.unpack('<I',CTX+0x28)[0],(flags|16)if active else flags&~16,'emptyFlags');ck(n.unpack('<I',0x973988)[0],CTX if active else 0x12345678,'emptyContext');ck(bool(n.unpack('<I',0x973984)[0]),initialized or active,'emptyInitialization');walkCases.append({'planes':p,'tree':tree,'enabled':enabled,'present':present,'flags':flags,'beforeHex':before.hex(),'nativeHex':n.read(BITS,64).hex(),'nativeFlags':n.unpack('<I',CTX+0x28)[0],'nativeVisits':[],'nativeCurrentContextChanged':n.unpack('<I',0x973988)[0]==CTX,'initialPlanesInitialized':initialized,'nativePlanesInitialized':bool(n.unpack('<I',0x973984)[0])})
md=Cs(CS_ARCH_X86,CS_MODE_32);assembly={hex(a):[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in md.disasm(n.read(a,size),a)]for a,size in[(0x5d8b60,0x2b5),(0x5d8e20,0x186),(0x5d8fb0,0x6b),(0x5b30a0,0x6c),(0x5c1aa0,0x6f)]};(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'functions':assembly},indent=2)+'\n')
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt',encoding='utf8')as f:json.dump({'planeCases':planeCases[:12],'predicateCases':predicateCases,'walkCases':walkCases},f)
report={'schema':'original-prepared-tree-visibility-v1','passed':not errors,'checks':checks,'binarySHA256':n.sha256,'counts':{'predicateCases':len(predicateCases),'treeCases':len(walkCases),'retainedPortableReplayCases':len(predicateCases)+len(walkCases),'originalPredicateEntries':len(predicateCases)+sum(len(c['nativeVisits'])for c in walkCases),'externalMatrixAdapterCalls':matrixCalls,'explicitFiniteStackSeedCases':sum(bool(c.get('seededResidue'))for c in predicateCases),'distinctRetainedStackWords':len(set(c['scratchWord']for c in predicateCases)|set(v['scratchWord']for c in walkCases for v in c['nativeVisits']))},'errors':errors[:20],'adapters':{'0x5c1240':'Explicit finite scalar D3DX4x4 multiply used only in native plane preparation; matrices derived by actual0x5d86f0/0x5d8950 retained as prepared input to portable tree predicate/walker. No predicate/root/wrapper hooks replace return/state.'},'limits':['Synthetic trees and finite nonnegative extents;valid u16indices,acyclic graphs and native100-entry pending-node stack.','Native predicate reads an uninitialized fourth radius at local+0x3c because0x5b30a0 writes only XYZ. Exact prior-stack word captured percall and supplied explicitly to portable model; no initialized intended4D radius invented.','No authored tree loader or live camera producer claim.','Prepared-plane portable projection excludes reconstruction of0x5d86f0/0x5d8950 numeric producers;original producers run in native fixture generation.'],'preparedManagedAssertions':len(predicateCases)+5*len(walkCases)+sum(len(c['nativeVisits'])for c in walkCases),'fixtureFile':PREFIX+'-native-fixtures.json.gz'};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));sys.exit(0 if not errors else 1)
