"""Actual registered CRT provider existence thunk/body→gameOpen/defaultformatter→releaseclose. No hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase117-20261013-verify.py').read_text().split('\nfor root,separator,path,mode')[0])
GLOBAL=0x91ee88;segments+=[(GLOBAL,12)];cases=[];checks=0;errors=[]

def run118(c):
 global shadow,checks
 for p,z in segments:n.write(p,b'\xa5'*z)
 n.pack('<I',C,0);n.pack('<I',G,P);n.pack('<I',FLAG,0);n.pack('<3I',GLOBAL,0,0xabcdef01,c['saved']);n.write(0x75c044,b':\0\0\0');setup117(P,b'def:',b'CUR/',92);n.write(P+0xac,b'old/\0');n.write(P+0x12c,b'user/\0');n.write(P+0x1ac,b'save/\0');templates=[]
 for i in range(c['count']):
  t=D+0x1000+i*0x234;templates.append(t);setup117(t,[b'pc:',b'net:'][i],b'BASE/',92)
 n.write(SRC,c['root'].encode('ascii')+b'\0');n.write(PATH,(c['path']or'').encode('ascii')+b'\0');path=0 if c['path']is None else PATH;initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for p,z in[(LOCAL97,512),(FILENAME,256)]:
  for i in range(z):shadow[p+i]=0
 setroot(SRC);mr=[register(t)for t in templates];wanted=0
 if path and rb(path):
  saved=rd(GLOBAL+8);wd(GLOBAL+8,0);provider=provider90(path)or rd(G);formatter97(provider,FILENAME,path,256);wd(GLOBAL+8,saved);wanted=1
 model=snap(True);n.call(0x4f6930,[SRC],count=4000000);nr=[n.call(0x4f6820,[t],count=4000000)for t in templates];actual=n.call(0x4ff120 if c['thunk']else 0x4fa610,[path],count=4000000);final=snap()
 for group,a,b in[('return',actual,wanted),('registrations',nr,mr),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group!='images'else'diff'))
 cases.append(dict(method='Exists',context=c,inputs=dict(root=SRC,path=path,templates=templates,privateSeparator=D+0x7000,privateFilename=FILENAME,privateFormatter=LOCAL97),initial=initial,final=final,returnValue=actual,registrationReturns=nr))
for root,path,saved,thunk,count in itertools.product(['','folder','folder/'],[None,'','missing.dat','pc:missing.dat'],[0,1,0xffffffff,0xdeadbeef],[False,True],[0,2]):run118(dict(root=root,path=path,saved=saved,thunk=thunk,count=count))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,ports=[],closure='Actualroot/template registration→4ff120/4fa610→4fa3f0/providerprefix/defaultformatter→CRTopenzero→publicclose/CRTclosezero; container-free type1domain, nohooks/noOS')
(nm.BASE/'reports/script-phase118-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase118-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
