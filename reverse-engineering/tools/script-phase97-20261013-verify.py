"""Original335-byte default provider formatter through real byte/path/prefix helpers, no adapters."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase96-20261013-verify.py').read_text().split('\nfor a,b')[0])
import random
PROV97=D+0x80000;INPUT97=D+0x81000;OUT97=D+0x82000;LOCAL97=D+0x83000;FLAG=0x91ee84;segments=[(PROV97,0x234),(INPUT97,512),(OUT97,512),(FLAG,4),(0x75c044,4)];cases=[];checks=0;errors=[]
def formatter97(provider,out,input,capacity):
 prefix=provider+52;length=length96(prefix)
 if substring91(input,0x75c044):copy96(LOCAL97,input)
 elif compare90(input,prefix,length)==0:
  tail=input+length96(prefix);first=rb(tail)
  if first in[47,92]:copy96(LOCAL97,input)
  else:copy96(LOCAL97,provider+76);append96(LOCAL97,provider+172);append96(LOCAL97,tail)
 else:copy96(LOCAL97,provider+76);append96(LOCAL97,provider+172);append96(LOCAL97,input)
 base=length96(provider+76);normalize90(provider,LOCAL97+base);compact96(provider,LOCAL97);length=length96(LOCAL97)
 if signed(length)>=signed(capacity):return 0
 copy96(out,LOCAL97);return 1

def execute97(c):
 global shadow,checks
 for p,z in segments:n.write(p,bytes(z))
 n.write(OUT97,bytes([0xa5])*512);n.write(PROV97+16,bytes([c.get('separator',92)]));n.write(PROV97+52,c['prefix'].encode('ascii')+b'\0');n.write(PROV97+76,c['base'].encode('ascii')+b'\0');n.write(PROV97+172,c['sub'].encode('ascii')+b'\0');n.write(INPUT97,bytes.fromhex(c['input'])+b'\0');n.pack('<I',FLAG,c.get('preserve',0));n.write(0x75c044,b':\0\0\0');output=INPUT97 if c.get('alias')=='input'else PROV97+76 if c.get('alias')=='base'else OUT97;initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(512):shadow[LOCAL97+i]=0
 want=formatter97(PROV97,output,INPUT97,c['capacity']);model=snap(True);actual=n.call(0x4ff130,[PROV97,output,INPUT97,c['capacity']],count=2000000);final=snap()
 for group,a,b in [('return',actual,want),('images',final,model)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group=='return'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group=='return'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(provider=PROV97,output=output,input=INPUT97,capacity=c['capacity']),initial=initial,returnValue=actual,final=final))
paths=[b'',b'file.dat',b'PCfile.dat',b'pc/file.dat',b'/file.dat',b'C:\\root\\..\\file.dat',b'PC\\file.dat',b'netfile',b'root/a/../b',b'C:\\xffa\\file']
for path,prefix,capacity in itertools.product(paths,['','PC'],[0,1,16,256]):execute97(dict(input=path.hex(),prefix=prefix,base='Base/',sub='Sub/',capacity=capacity))
rng=random.Random(0x4ff130)
for i in range(160):execute97(dict(input=rng.choice(paths).hex(),prefix=rng.choice(['','PC','net']),base=rng.choice(['','Base/']),sub=rng.choice(['','Sub/']),capacity=rng.choice([0,1,7,16,256,0xffffffff]),separator=rng.choice([0,47,92]),preserve=rng.randrange(2)))
for alias,path in itertools.product(['input','base'],paths[:4]):execute97(dict(input=path.hex(),prefix='PC',base='Base/',sub='Sub/',capacity=256,alias=alias))
execute97(dict(input=(b'C:'+bytes([255])+b'a/file').hex(),prefix='PC',base='',sub='',capacity=256))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=1,ports=[],closure='Whole4ff130→original4f1ff0/4f20a0/4f8b80/4f1f10/4f1e80/4efdf0/4efec0/cookie, no adapters')
(nm.BASE/'reports/script-phase97-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase97-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
