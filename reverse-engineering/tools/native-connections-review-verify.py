"""Persist the independent 587-case connection review; compile only, never launch C#."""
import importlib.util,itertools,json,hashlib,os,subprocess
from pathlib import Path
p=Path(__file__).with_name('native-connections-fixture.py');s=importlib.util.spec_from_file_location('review_fixture',p);f=importlib.util.module_from_spec(s);s.loader.exec_module(f);n=f.n;BASE=f.BASE
cases=[];errors=[];failures=[];counts={'force':0,'locator':0,'connection':0,'pathIndex':0}

def check(group,inputs,expected,actual):
 counts[group]+=1;row={'group':group,'input':inputs,'expected':expected,'native':actual};cases.append(row)
 if actual!=expected:errors.append(row)

try:
 for a,b,t,has,state in itertools.product([0,2,0x40,0x42],[0,0x40,0x800,0x840,0x2000,0x2040,0x2800,0x2840],[-.5,0.,.5],[False,True],[0,1,2]):
  f.setup(forceFlags=a,forceFlags2=b,forceTimer=t,forceHasObstacle=has,obstacleState=state)
  expected=int((a&2)==0 and(t<=0 or(b&0x2000)!=0)and((a&0x40)==0 or(b&0x800)!=0)and(not has or state==(0 if b&0x40 else 2)))
  check('force',{'forceFlags':a,'forceFlags2':b,'timer':t,'hasObstacle':has,'obstacleState':state},expected,n.call(0x467890,[f.OBJ]))
 for names,query,expected in [(['a','A','c'],'A',0),(['a','b','c'],'c',2),(['a','b','c'],'missing',-1),(['','b','c'],'',0),(['\xff','\xdf','c'],'\xdf',0),(['a','b','c'],None,-1)]:
  f.setup();n.pack('<B',f.PATH+0x10,3)
  for i,name in enumerate(names):
   address=f.NAMES+0x100*i;n.write(address,name.encode('latin1')+b'\0');n.pack('<I',f.LOCATORS+0x5c*i,address)
  qp=0 if query is None else f.TEXT
  if qp:n.write(qp,query.encode('latin1')+b'\0')
  got=n.call(0x51ad80,[f.NAV,0,qp]);got=(got-f.LOCATORS)//0x5c if got else -1
  check('locator',{'names':names,'query':query},expected,got)
 for endpoints,expectedIndex,expectedDirection in [([(0,0),(0,1),(1,0)],1,0),([(1,1),(0,1)],0,1),([(0,0),(0,0)],-1,77),([(1,0),(0,1)],0,1)]:
  f.setup();n.pack('<B',f.LOCATORS+0x28,len(endpoints));n.write(f.TEXT,b'a\0');n.write(f.TEXT+20,b'b\0');out=f.TEXT+40;n.pack('<I',out,77)
  for i,(a,b)in enumerate(endpoints):
   cnx=f.D+0x30000+i*32;n.pack('<BB',cnx+0x10,a,b);n.pack('<I',f.LOCLINKS+4*i,cnx)
  got=n.call(0x51adf0,[f.NAV,0,f.TEXT,f.TEXT+20,out]);index=(got-f.D-0x30000)//32 if got else -1;direction=n.unpack('<I',out)[0]
  check('connection',{'endpoints':[list(v)for v in endpoints],'initialDirection':77},[expectedIndex,expectedDirection],[index,direction])
 f.setup();n.pack('<B',f.NAVTABLE,3);n.pack('<3I',f.PATHLIST,f.D+0x30000,f.D+0x32000,f.PATH);n.write(f.TEXT,b'a\0');n.write(f.TEXT+20,b'b\0');n.write(f.TEXT+40,b'x\0')
 got=n.call(0x43cca0,[f.MANAGER,f.NAV,f.PATH,f.TEXT,f.TEXT+20,2,f.TEXT+40,-1,0])
 check('pathIndex',{'explicitPathIndex':2,'pathCount':3},2,n.read(got+0xa5,1)[0]if got else -1)
except Exception as e:failures.append(str(e))

def hashed(path):
 p=BASE/path;return {'path':path,'bytes':p.stat().st_size,'sha256':hashlib.sha256(p.read_bytes()).hexdigest()}

sourcePaths=['tools/native-connections-review-verify.py','tools/native-connections-fixture.py','tools/native-x86.py','reconstructed/navigation/ConnectionControllers.cs','reconstructed/navigation/ConnectionDifferential.cs','reports/native-connections-assembly.json']
compiler=Path(os.environ.get('WINDIR',r'C:\Windows'))/'Microsoft.NET/Framework64/v4.0.30319/csc.exe'
build=BASE/'reconstructed/navigation/review-build';build.mkdir(parents=True,exist_ok=True);compileResults=[]
if compiler.exists():
 for name,target,files,extra in [('Recovered.Navigation.dll','library',['ConnectionControllers.cs'],[]),('ConnectionReviewCompile.exe','exe',['ConnectionControllers.cs','ConnectionDifferential.cs'],['/main:ConnectionDifferential','/reference:System.Web.Extensions.dll'])]:
  command=[str(compiler),'/nologo','/optimize+','/platform:anycpu','/target:'+target,'/out:'+str(build/name)]+extra+[str(BASE/'reconstructed/navigation'/v)for v in files]
  result=subprocess.run(command,capture_output=True,text=True);entry={'command':command,'exitCode':result.returncode,'stdout':result.stdout,'stderr':result.stderr}
  if result.returncode==0:entry['artifact']=hashed((build/name).relative_to(BASE).as_posix())
  compileResults.append(entry)
else:compileResults.append({'status':'Compiler unavailable','path':str(compiler)})

report={'binarySha256':n.sha256,'nativeAddresses':{'force':'0x467890','locator':'0x51ad80','connection':'0x51adf0','pathIndex':'0x43cca0'},'counts':counts,'totalComparisons':len(cases),'mismatches':len(errors),'failures':failures,'cases':cases,'examples':errors,'sourceHashes':[hashed(p)for p in sourcePaths],'compile':compileResults,'managedExecution':'NOT RUN: Windows execution restriction; no bypass attempted.','method':'Original native routines in isolated Unicorn. The constructor retains existing explicit target-lookup adapters; its endpoint lookup, path-index assignment and list operations remain original. Compare independently specified predicate/query results.','apiChange':{'source':'reconstructed/navigation/ConnectionControllers.cs','method':'FindConnection','before':'out byte direction initialized to0 before lookup','after':'ref byte direction unchanged on failure; set1 for Endpoint0 match and0 for Endpoint1 match','caller':'Create initializes its local direction to0 then passes by ref. Existing documented null-connection fake-controller constructor normalization remains outside exact uninitialized-stack reproduction.'},'limits':['Native output at51adf0 is a32-bit dword; portable direction remains a byte-valued host API and preserves caller byte values.','Only the listed587 corner cases are added; the separate16443-case fixture remains intact.','Compilation is not a managed differential pass.']}
target=BASE/'reports/native-connections-review-tests.json';target.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({'counts':counts,'comparisons':len(cases),'mismatches':len(errors),'failures':failures,'compileExitCodes':[r.get('exitCode')for r in compileResults],'reportSha256':hashlib.sha256(target.read_bytes()).hexdigest()},indent=2))
if errors or failures or any(r.get('exitCode',1)!=0 for r in compileResults):raise SystemExit(1)
