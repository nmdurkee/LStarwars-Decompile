"""Actual provider root+registration→type1 gameOpen+default formatter→CRT public lifecycle, no hooks."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase97-20261013-verify.py').read_text().split('\npaths=')[0])
text113=Path(__file__).with_name('script-phase113-20261013-verify.py').read_text();exec(text113[text113.index('def setroot(s):'):text113.index('\ndef run(c):')]);copy=copy96;n=nm.NativeX86()
from unicorn.x86_const import UC_X86_REG_EDX
P=D+0x2000;SRC=D+0x300;PATH=D+0x400;R=0x29803e0;C=0x297e064;G=0x800478;PCOUNT=C;PROVIDERS=R;FILENAME=D+0xf000;BUFFER=D+0x6000
segments=[(D,0x8000),(R,0x234*4),(C,4),(G,4),(FLAG,4),(0x75c044,4)];cases=[];errors=[];checks=0

def setup117(provider,prefix,base,separator):
 n.write(provider,b'\0'*0x234);n.pack('<I',provider,1);n.write(provider+16,bytes([separator]));n.write(provider+52,prefix+b'\0');n.pack('<I',provider+68,len(prefix));n.pack('<I',provider+72,4);n.write(provider+76,base+b'\0');n.pack('<I',provider+0x22c,0x4ff130);n.pack('<I',provider+0x230,0x6dee90)

def run117(c):
 global shadow,checks
 for p,z in segments:n.write(p,b'\xa5'*z)
 n.pack('<I',C,0);n.pack('<I',G,P);n.pack('<I',FLAG,c['preserve']);n.write(0x75c044,b':\0\0\0');setup117(P,b'def:',b'CUR/',c['separator']);n.write(P+0xac,b'old/\0');n.write(P+0x12c,b'user/\0');n.write(P+0x1ac,b'save/\0');templates=[]
 for i in range(c['count']):
  t=D+0x1000+i*0x234;templates.append(t);setup117(t,[b'pc:',b'net:',b'foo:',b'last:'][i],b'BASE/',c['separator'])
 n.write(SRC,c['root'].encode('ascii')+b'\0');n.write(PATH,c['path'].encode('ascii')+b'\0');initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for p,z in[(LOCAL97,512),(FILENAME,256)]:
  for i in range(z):shadow[p+i]=0
 setroot(SRC);mr=[register(t)for t in templates];provider=provider90(PATH)or rd(G);formatter97(provider,FILENAME,PATH,256);model=snap(True);n.call(0x4f6930,[SRC],count=4000000);nr=[n.call(0x4f6820,[t],count=4000000)for t in templates];handle=n.call(0x4fa3f0,[PATH,c['mode'],0,c['quiet']],count=4000000);size=n.call(0x4f6b40,[handle]);size|=n.mu.reg_read(UC_X86_REG_EDX)<<32;read=n.call(0x4fb550,[handle,BUFFER,c['readCount']]);seek=n.call(0x4f6de0,[handle,c['low'],c['high'],c['origin']]);seek|=n.mu.reg_read(UC_X86_REG_EDX)<<32;close=n.call(0x4f99e0,[handle]);final=snap();returns=[handle,size,read,seek,close]
 for group,a,b in[('returns',returns,[0x1000,0,0,0,0]),('registrations',nr,mr),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else [dict(address=x['address']+i,native=u,model=v)for x,y in zip(a,b)for i,(u,v)in enumerate(zip(bytes.fromhex(x['bytes']),bytes.fromhex(y['bytes'])))if u!=v][:8],model=b if group!='images'else'diff'))
 cases.append(dict(method='OpenRegisteredCrt',context=c,inputs=dict(root=SRC,path=PATH,templates=templates,destination=BUFFER,privateSeparator=D+0x7000,privateFilename=FILENAME,privateFormatter=LOCAL97),initial=initial,final=final,returns=returns,registrationReturns=nr))
for root,separator,path,mode in itertools.product(['','folder','folder/','C:\\base'],[47,92],['','file.dat','pc:file.dat','PC:root/a/../b','net:file.dat','C:\\root\\..\\file'],[0,1,2,3,0xffffffff]):run117(dict(root=root,separator=separator,path=path,mode=mode,count=2,preserve=len(cases)&1,quiet=len(cases)&1,readCount=[0,17,0xffffffff][len(cases)%3],low=0xffffffff,high=0x80000000,origin=len(cases)%4))
for count in[0,1,4]:run117(dict(root='folder',separator=92,path='last:file',mode=0,count=count,preserve=0,quiet=0,readCount=100,low=0,high=0,origin=0))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,ports=[],closure='Actualroot+registration→providerprefix4f98c0→whole4fa3f0→wholedefaultformatter4ff130→realCRTopen6dee30→publicsize/read/seek/close→zero leaves; nohooks/noOS')
(nm.BASE/'reports/script-phase117-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase117-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
