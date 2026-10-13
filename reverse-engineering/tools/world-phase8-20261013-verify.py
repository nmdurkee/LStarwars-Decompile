import json,struct,hashlib,base64,random,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase7-20261013-verify.py');scope={'__file__':str(peer)};code=peer.read_text();exec(compile(code[:code.index('cases=[];provenance=[]')],str(peer),'exec'),scope)
n=scope['n'];D=scope['D'];B=scope['B'];Image=scope['Image'];vm=scope['vm'];REGIONS=scope['REGIONS'];make=scope['make'];wp=scope['wp'];patch=scope['patch'];spl=scope['spl'];S=scope['S'];U=scope['U'];SCENE=D+0x4000;ST=D+0x30000;SN=D+0x31000;QUERY=D+0x7000;OUT=D+0x8000;OUT2=D+0x8100
from unicorn import UC_HOOK_CODE
counts={}
def observe(uc,a,z,data):counts[hex(a)]=counts.get(hex(a),0)+1
for a in [0x5b2110,0x5b21f0,0x5b22a0,0x5d0690,0x4f8b10,0x4f8b80,0x4f8a70]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def text(m,p):return None if not p else m.text(p)
def equal(a,b):return a is not None and b is not None and a.lower()==b.lower()
def prefix(q,name):
 if q is None:return False
 return name.lower().startswith(q.lower()) if q else not name
def contains(name,q):return bool(name) and q.lower() in name.lower()
def model_queries(m,c):
 scene=c['scene'];q=text(m,c['query']);cap=c['capacity'];cat=m.word(scope['BASE']);count=S(m.word(scope['COUNT']));pub=[cat+i*12 for i in range(max(0,count))] if cat else []
 sceneRecords=[m.word(scene+0x34)+i*12 for i in range(max(0,S(m.word(scene+0x30))))] if scene else []
 found=next((at for at in pub+sceneRecords if equal(text(m,m.word(at+4)),q)),0)
 matched=[at for at in pub+sceneRecords if prefix(q,text(m,m.word(at+4)))][:max(0,cap)]
 for i,at in enumerate(matched):m.word(OUT+i*4,at)
 sub=[at for at in pub+sceneRecords if contains(text(m,m.word(at+4)),q)][:max(0,cap)] if q is not None else None
 if sub is not None:
  for i,at in enumerate(sub):m.word(OUT2+i*4,at)
 return [found,len(matched),None if sub is None else len(sub)]
def addscene(c,names,scene=True,count=None):
 c['scene']=SCENE if scene else 0;c['writes'].extend([wp(SCENE+0x30,len(names) if count is None else count),wp(SCENE+0x34,ST)])
 for i,name in enumerate(names):c['writes'].extend([patch(ST+i*12,struct.pack('<HHII',i*7,12,SN+i*32,D+0x32000+i*32)),patch(SN+i*32,name.encode()+b'\0')])
 return c
cases=[];files=[]
for f in sorted((B/'extracted').rglob('*.SPL')):
 blob=f.read_bytes();files.append(dict(path=str(f.relative_to(B)).replace('\\','/'),sha256=hashlib.sha256(blob).hexdigest(),bytes=len(blob)))
 for sceneNames in [[],['Spline 1','Spline 1','GROUP1','TEL1',''],['extra','spline 10','GROUP1']]:
  for query in ['Spline 1','spline','GROUP1','TEL','1','',None,'missing']:
   for cap in [-1,0,1,2,8]:
    c=addscene(make(blob,mis=len(cases)%4),sceneNames);c['authored']=str(f.relative_to(B)).replace('\\','/');c['capacity']=cap;c['query']=0 if query is None else QUERY;c['writes'].append(patch(QUERY,(query or '').encode()+b'\0'));cases.append(c)
rng=random.Random(0x5b2110)
for i in range(220):
 names=[rng.choice(['ALpha','alpha2','ALPHA','beta','','Delta']) for j in range(rng.randrange(6))];payload=spl([(name.encode()+b'\0',0,[]) for name in names]);q=rng.choice(['Alpha','al','ALPHA2','beta','','a','missing',None]);c=addscene(make(payload,mis=i%4,space=0 if i%13==0 else 0x18000),[rng.choice(['ALpha','alpha2','beta','','none']) for j in range(rng.randrange(7))],scene=i%7!=0,count=-1 if i%17==0 else None);c['query']=0 if q is None else QUERY;c['capacity']=rng.choice([-3,0,1,2,5,12]);c['writes'].append(patch(QUERY,(q or '').encode()+b'\0'));cases.append(c)
start=time.time();outrows=[];fail=[]
for i,c in enumerate(cases):
 scope['current']=c;m=Image(c)
 for a,z in REGIONS:n.write(a,m.read(a,z))
 scope['trace']=[];scope['filepos']=scope['opens']=scope['reads']=scope['closes']=0
 loaded=n.call(0x5b1ee0,[scope['PATH'],scope['CR'],scope['ER']],count=6000000)
 results=[loaded,n.call(0x5b2110,[c['scene'],c['query']]),n.call(0x5b21f0,[c['scene'],c['query'],OUT,c['capacity']])]
 results.append(n.call(0x5b22a0,[c['scene'],c['query'],OUT2,c['capacity']]) if c['query'] else None)
 native=dict(results=results,sha256=vm.digest(),trace=scope['trace'].copy(),state=dict(filePosition=scope['filepos'],opens=scope['opens'],reads=scope['reads'],closes=scope['closes']))
 scope['trace']=[];scope['filepos']=scope['opens']=scope['reads']=scope['closes']=0
 loadResult=scope['load'](m);predicted=dict(results=[loadResult]+model_queries(m,c),sha256=m.digest(),trace=scope['trace'].copy(),state=dict(filePosition=scope['filepos'],opens=scope['opens'],reads=scope['reads'],closes=scope['closes']))
 if native!=predicted:fail.append(dict(case=i,native=native,prediction=predicted));print(json.dumps(fail[-1]));break
 c['expected']=native;outrows.append(c)
report=dict(binarySha256=n.sha256,cases=len(outrows),mismatches=len(fail),nativeConsumerCalls=counts,nativeProducerCalls=scope['calls'],authoredFiles=files,seconds=round(time.time()-start,3),failures=fail)
(B/'reports/world-phase8-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not fail:(B/'reports/world-phase8-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z) for a,z in REGIONS],authoredFiles=files,cases=outrows),separators=(',',':'))+'\n')
print(json.dumps(report));assert not fail
