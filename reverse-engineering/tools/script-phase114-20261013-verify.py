"""Full original provider template registration→inventory→original status callback bodies. No hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase113-20261013-verify.py').read_text().split('\nfor text,sep,alias')[0])
WORD=0x91eea4;CHOSEN=0x29838d0;OUTPUT=0x297e080;OUT=D+0x80;segments=[(D,0xc000),(R,0x234*17),(OUTPUT,0x234*16),(C,4),(G,4),(WORD,4),(CHOSEN,4)];cases=[];checks=0;errors=[];callbacks=[0x4eff30,0x6dee90,0x6dee70,0x4ef790,0x4ef7b0,0x512850,0x512860,0x512870]
def status(callback):
 if callback==0x4eff30:return rd(WORD)
 if callback in[0x6dee90,0x6dee70]:return 0
 return callback

def inventory():
 chosen=0;index=0;destination=OUTPUT
 while index<rd(C):
  provider=R+index*0x234
  if(status(rd(provider+0x230))&2)==0:
   for j in range(0x8d):wd(destination+j*4,rd(provider+j*4))
   destination+=0x234;chosen+=1
  index+=1
 wd(OUT,OUTPUT);wd(CHOSEN,chosen);return chosen

def run114(c):
 global shadow,checks
 for p,z in segments:n.write(p,b'\xa5'*z)
 n.pack('<I',C,0);n.pack('<I',G,P);n.pack('<I',WORD,c['word']);n.write(P+16,bytes([c['separator']]));
 for off,text in[(0xac,b'ROOT/'),(0x12c,b'USER/'),(0x1ac,b'SAVE/')]:n.write(P+off,text+b'\0')
 templates=[]
 for i,callback in enumerate(c['callbacks']):
  template=D+0x4000+i*0x234;templates.append(template);n.write(template,bytes((i*53+j*37+11)&255 for j in range(0x234)));n.pack('<I',template+0x230,callback);n.pack('<I',template,i)
 source=D+0x300;n.write(source,c['root'].encode('latin1')+b'\0');initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};setroot(source);mr=[register(t)for t in templates];wanted=inventory();model=snap(True)
 n.call(0x4f6930,[source],count=4000000);nr=[n.call(0x4f6820,[t],count=4000000)for t in templates];actual=n.call(0x4effb0,[OUT],count=4000000);final=snap()
 for group,a,b in[('return',actual,wanted),('registrations',nr,mr),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group!='images'else'diff'))
 cases.append(dict(method='RegisterAndEnumerate',context=c,inputs=dict(templates=templates,output=OUT,root=source,privateSeparator=D+0x900),initial=initial,final=final,returnValue=actual,registrationReturns=nr))
for word,root,sep in itertools.product([0,1,2,3,0xffffffff,0x80000000],['','folder','folder/','folder\\'],[47,92]):
 for count in[0,1,2,8,16]:run114(dict(word=word,root=root,separator=sep,callbacks=[callbacks[i%len(callbacks)]for i in range(count)]))
for callback in callbacks:
 for word in[0,2]:run114(dict(word=word,root='test',separator=92,callbacks=[callback]*16))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,ports=[],closure='Actualroot setter/append→fullprovider registration→4effb0inventory→4eff30/6dee70/6dee90/releaseRET callback bodies; nohooks')
(nm.BASE/'reports/script-phase114-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase114-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
