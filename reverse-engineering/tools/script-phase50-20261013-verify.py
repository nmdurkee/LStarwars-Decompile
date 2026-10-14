"""Actualpublicbinary line/token wrappers plus numeric narrow conversion and integer parser; finalrawIO."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase49-20261013-verify.py').read_text().split('\nfor file,capacity,chunk')[0])
src48=Path(__file__).with_name('script-phase48-20261013-verify.py').read_text();exec(src48[src48.index('\ndef rw'):src48.index('\ndef execute48')]);P48=PARSER;L48=RAWLINE;T48=TOKEN;numbers=module('wide_numbers50','native-text-numbers-verify.py');n=nm.NativeX86();n.mu.hook_add(UC_HOOK_CODE,hook49)
def narrow50():
 p=rd(PARSER+0x510);result='';i=0
 while rw(p+i*2):
  c=rw(p+i*2);result+=chr(c if c<256 else {0x2019:0x92,0x2013:0x96,0x2018:0x91,0x2026:0x85,0x2122:0x99}.get(c,63));i+=1
 return result

def execute50(c):
 global config,shadow,stream,checks
 config=c;setup26(dict(c,file=''));n.pack('<I',PARSER+0x574,len(payload49()));n.pack('<I',PARSER+0x518,512);n.write(PARSER+0x578,bytes([c['binary']]));initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};stream=fresh_stream();want=[next49()];want.append(next48())
 for i in range(3):
  next48();v=narrow50();r=numbers.hexadecimal(v[1:])if v.startswith('$')else numbers.hexadecimal(v[2:])if v[:2].lower()=='0x'else numbers.decimal(v);want.append(r&0xffffffff)
 mf=snapshot(True);ms=stream.copy();stream=fresh_stream();got=[n.call(0x4fc5b0,[PARSER],count=4000000),n.call(0x4f7fb0,[PARSER],count=2000000)];got+=[n.call(0x4f9e70,[PARSER],count=2000000)for i in range(3)];nf=snapshot();ns=stream.copy()
 for group,a,b in [('return',got,want),('images',nf,mf),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a,model=b))
 cases.append(dict(context=c,inputs=dict(parser=PARSER),initial=initial,returnValue=got,final=nf,nativeStream=ns))
for file,chunk,binary in itertools.product(['CMD 1 2 3\n','""CMD -1 $ff 0x100\n','"a""b" 2147483648 -2147483649 +3\n','\u4e2d 12x $g 0x\n',';comment\nCMD 3 4 5\r\n','CMD \u012031 22 33\n','CMD "12" ""34 56\n'],[1,3,4096],[1,2,255]):execute50(dict(file=file,capacity=512,chunk=chunk,binary=binary))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=0,ports=['4fb550 finalrawbytes'],closure='4fc5b0→4fc390→4fc2d0 /4f7fb0→4f7df0 /4f9e70→token→4f2dc0→decimal/hex')
(nm.BASE/'reports/script-phase50-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase50-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
