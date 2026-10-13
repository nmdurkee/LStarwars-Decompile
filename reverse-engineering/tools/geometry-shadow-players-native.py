"""Original two-player position and light-direction aggregate queries."""
import importlib.util,json,struct,gzip,hashlib,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();D=n.DATA;SIZE=0x2000;OUT=D+0x100;STRENGTH=D+0x120;PLAYERS=[D+0x400,D+0xc00]
from unicorn.x86_const import UC_X86_REG_EDI
f32=lambda v:struct.unpack('<f',struct.pack('<f',v))[0];cases=[];counts=collections.Counter()
def execute(kind,index,states,positions,directions,strengths,seed):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));pointers=[PLAYERS[i]if states[i]!=0 else 0 for i in range(2)];pack=lambda b,p,values:struct.pack_into('<'+'f'*len(values),b,p-D,*values)
 for i,p in enumerate(PLAYERS):before[p+0x1fc-D]=0x80 if states[i]==2 else 0;pack(before,p+0x5c,positions[i]);pack(before,p+0x5fc,directions[i]);pack(before,p+0x608,[strengths[i]])
 expected=bytearray(before);active=[i for i in range(2)if states[i]==2];value=[0.,0.,0.]if kind=='position'else seed.copy();strength=-1.
 for i in active:
  point=positions[i]if kind=='position'else directions[i];value=[f32(value[j]+point[j])for j in range(3)]
  if strength<=strengths[i]:strength=strengths[i]
 if active:value=[f32(q*f32(1/len(active)))for q in value]
 if kind=='direction' or active:pack(expected,OUT,value)
 if kind=='direction':pack(expected,STRENGTH,[strength])
 n.write(D,before);n.pack('<2I',0x93d7f0,*pointers);n.pack('<3f',0x95e5c8,*seed);address=0x55e340 if kind=='position'else 0x5967b0;got=n.call(address,[OUT,0]if kind=='position'else[STRENGTH],{}if kind=='position'else{UC_X86_REG_EDI:OUT},count=100000);actual=n.read(D,SIZE);want=int(bool(active))if kind=='position'else len(active)
 if actual!=expected or got!=want:raise AssertionError(dict(kind=kind,index=index,native=got,expected=want,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:20]))
 counts['cases']+=1;counts[kind]+=1;counts['active'+str(len(active))]+=1;counts['persistentBytes']+=SIZE;cases.append(dict(kind=kind,index=index,before=bytes(before).hex(),players=pointers,seedWords=list(struct.unpack('<3I',struct.pack('<3f',*seed))),nativeReturn=got,nativeSHA256=hashlib.sha256(actual).hexdigest()))
rng=random.Random(0x5967b0)
for i in range(768):
 states=[i%3,i//3%3];positions=[[f32(rng.uniform(-10000,10000))for j in range(3)]for k in range(2)];directions=[[f32(rng.uniform(-100,100))for j in range(3)]for k in range(2)];strengths=[[-10.,-1.,-0.,0.,.5,1.,100.][(i+j)%7]for j in range(2)];seed=[f32(rng.uniform(-1,1))for j in range(3)]if i&1 else[0.,-0.,0.]
 if i%11==0:positions=[[-0.,0.,-0.],[0.,-0.,0.]];directions=[[0.,-0.,0.],[-0.,0.,-0.]]
 for kind in ['position','direction']:execute(kind,i,states,positions,directions,strengths,seed)
fp=R/'geometry-shadow-players-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,output=OUT,strength=STRENGTH,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-players-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Actual55e340/5967b0 and original vectoradd/scale helpers execute, no computational replacements.','Exactly two resolved player slots, null/inactive/active combinations; actor+1fc bit80 controls inclusion. Position+5c, direction+5fc,strength+608 are exact observed fields.','55e340 scope is nullauxiliary, as used by596a30; collision query541bc0 auxiliarybranch is excluded. Noactive player leaves positionoutput untouched.','5967b0 seeds output from95e5c8 even withzeroactive, strength starts-1, equality selects latestcandidate strength including signedzero. Seed is included before dividingbyactivecount.','Finite stored arithmetic and disjointrecords/output; managed runtime equality and outer596a30 remain separate.']);(R/'geometry-shadow-players-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))

