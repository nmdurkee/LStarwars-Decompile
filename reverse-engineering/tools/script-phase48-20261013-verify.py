"""Unchangedoriginal4f7df0 wide token reader: fullwords, lowbyte delimiters, doubledquotedquotes."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase24-20261013-verify.py').read_text().split('\nfor custom,name')[0])
n=nm.NativeX86();P48=D+0x1000;L48=D+0x2000;T48=D+0x4000;S48=D+0x5000;I48=D+0x5100;segments=[(D,0x10000),(0x88ab4c,4)]
def rw(p):return rb(p)|(rb(p+1)<<8)
def ww48(p,v):wb(p,v);wb(p+1,v>>8)
def mask48(size):return (((size if size<0x80000000 else size-0x100000000)>>1)-1)&0xffffffff
def contains48(p,c):
 if not p:return False
 while rb(p):
  if rb(p)==c:return True
  p+=1
 return False

def next48():
 line=rd(P48+0x50c);token=rd(P48+0x510);count=0;quote=False;cursor=rd(P48+0x520);wd(0x88ab4c,cursor)
 if rw(line+2*(mask48(rd(P48+0x514))&cursor)):
  while True:
   cursor=rd(P48+0x520);at=line+2*cursor;c=rw(at)
   if not quote and contains48(rd(P48+0x580),c&255):
    if not count:ww48(token,c);count=1;wd(P48+0x520,cursor+1)
    break
   if not quote and contains48(rd(P48+0x57c),c&255):c=32
   if not quote and c&255 in [9,32,44]:
    if count:break
   elif c==34:
    if quote and rw(at+2)==34:ww48(token+2*(mask48(rd(P48+0x518))&count),34);count+=1;wd(P48+0x520,rd(P48+0x520)+1)
    else:quote=not quote
   else:ww48(token+2*(mask48(rd(P48+0x518))&count),c);count+=1
   wd(P48+0x520,rd(P48+0x520)+1)
   if not rw(line+2*(mask48(rd(P48+0x514))&rd(P48+0x520))):break
 ww48(token+2*(mask48(rd(P48+0x518))&count),0);return count

def execute48(c):
 global shadow,checks
 n.write(D,bytes([0xa5])*0x10000);payload=c['line'].encode('utf-16le')+b'\0\0';n.write(L48,payload);n.pack('<4I',P48+0x50c,L48,T48,4096,c['capacity']);n.pack('<I',P48+0x520,c.get('cursor',0));n.pack('<II',P48+0x57c,S48 if c['separator']is not None else 0,I48 if c['single']is not None else 0);n.write(S48,(c['separator']or'').encode()+b'\0');n.write(I48,(c['single']or'').encode()+b'\0');initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};want=next48();mf=snapshot(True);got=n.call(0x4f7df0,[P48],count=2000000);nf=snapshot()
 for group,a,b in [('return',got,want),('images',nf,mf)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(parser=P48),initial=initial,returnValue=got,final=nf))
texts48=['',' ','a','a b','a,b',' a\t b ','"" x','a""b','"a b"c','"a""b" c','"unterminated','a=b+c;d','x'*255,'y'*256,'z'*511,'\u0120x','\u012cx','\u0109x','\u0122x','\u013dx','\u03b1\u4e2d\uffff']
for line,capacity,separator,single in itertools.product(texts48,[2,4,14,16,62,256,512],[None,';='],[None,'=+()',' ,']):execute48(dict(line=line,capacity=capacity,separator=separator,single=single))
for line,cursor in [('a b',2),(' ""x',1),('abc',3)]:execute48(dict(line=line,capacity=512,separator=None,single=None,cursor=cursor))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=1,ports=[])
(nm.BASE/'reports/script-phase48-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase48-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
