"""Actual provider registration→unregistered selector4eff40→provider-root read. No hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase113-20261013-verify.py').read_text().split('\nfor text,sep,alias')[0])
segments=[(D,0xc000),(R,0x234*17),(C,4),(G,4)];cases=[];errors=[];checks=0

def select(kind,qualifier):
 if kind==0xfffffffd:return rd(G)
 if kind in[1,3]:kind=2
 count=rd(C);count=count if count<0x80000000 else count-0x100000000
 for i in range(max(0,count)):
  row=R+i*0x234
  if rd(row)==kind and (qualifier>=0x80000000 or rd(row+4)==qualifier):return row
 return 0

def run115(c):
 global shadow,checks
 for p,z in segments:n.write(p,b'\xa5'*z)
 n.pack('<I',C,0);n.pack('<I',G,P);n.write(P+16,b'\\');
 for off in[0xac,0x12c,0x1ac]:n.write(P+off,b'current/\0')
 templates=[]
 for i,(kind,q)in enumerate(c['rows']):
  t=D+0x4000+i*0x234;templates.append(t);n.write(t,bytes((i*53+j*37+11)&255 for j in range(0x234)));n.pack('<2I',t,kind,q)
 initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};mr=[register(t)for t in templates]
 if 'countOverride'in c:wd(C,c['countOverride'])
 wanted=select(c['kind'],c['qualifier']);rootResult=None
 if wanted:wd(G,wanted);rootResult=getroot(DST,c['seed'])
 model=snap(True);nr=[n.call(0x4f6820,[t],count=4000000)for t in templates]
 if 'countOverride'in c:n.pack('<I',C,c['countOverride'])
 actual=n.call(0x4eff40,[c['kind'],c['qualifier']],count=4000000);nativeRoot=None
 if actual:n.pack('<I',G,actual);nativeRoot=n.call(0x4f6900,[DST],regs={UC_X86_REG_EAX:c['seed']})
 final=snap()
 for group,a,b in[('return',actual,wanted),('rootReturn',nativeRoot,rootResult),('registrations',nr,mr),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group!='images'else'diff'))
 cases.append(dict(method='RegisterSelectAndReadRoot',context=c,inputs=dict(templates=templates,kind=c['kind'],qualifier=c['qualifier'],destination=DST,seed=c['seed']),initial=initial,final=final,returnValue=actual,rootReturn=nativeRoot,registrationReturns=nr))
rows=[[0,7],[2,0],[2,7],[2,0xffffffff],[1,7],[3,7],[0xffffffff,0],[0xfffffffd,9]]
for kind,q,count,seed in itertools.product([0,1,2,3,4,0xffffffff,0xfffffffd],[0,7,9,0xffffffff,0x80000000],[0,1,3,8],[0,0x12345678]):run115(dict(rows=rows[:count],kind=kind,qualifier=q,seed=seed))
for count in[0,0xffffffff,0x80000000]:run115(dict(rows=rows,kind=2,qualifier=0xffffffff,seed=0xffffffff,countOverride=count))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,rawEntryConsumers=['0x4eff40'],ports=[],closure='Whole216byte provider registration→whole99byte rawselector4eff40→root getter; selector3/1aliases2, negative qualifier wildcard andminus3 currentcontext; nohooks')
(nm.BASE/'reports/script-phase115-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase115-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
