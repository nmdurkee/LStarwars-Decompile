import importlib.util,json,struct,gzip,itertools,random,re
from pathlib import Path
s=importlib.util.spec_from_file_location('base',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.x.NativeX86();B=b.B;D=b.D;b.REGIONS=[(0x88ab4c,4),(D,0x10000)]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
PARSER=D+0x1000;LINE=D+0x2000;TOKEN=D+0x4000;SEPARATORS=D+0x5000;SINGLES=D+0x5100
visited=set();binaryCalls=0
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def setup(p):
 m=b.Image(p['seed']);m.text(LINE,p['line']);m.put(PARSER+0x50c,LINE);m.put(PARSER+0x510,TOKEN);m.put(PARSER+0x514,4096);m.put(PARSER+0x518,p['capacity']);m.put(PARSER+0x520,p['cursor']);m.write(PARSER+0x578,bytes([p['binary']]));m.put(PARSER+0x570,p['depth']);m.put(PARSER+0x57c,SEPARATORS if p['separators'] is not None else 0);m.put(PARSER+0x580,SINGLES if p['singles'] is not None else 0);m.text(SEPARATORS,p['separators'] or '');m.text(SINGLES,p['singles'] or '');return m
def string(m,a):
 if not a:return ''
 out=[]
 while m.read(a,1)!=b'\0':out.append(m.read(a,1)[0]);a+=1
 return bytes(out).decode('latin1')
def binary(m):m.put(PARSER+0x520,m.get(PARSER+0x520)+7);m.text(TOKEN,'binary')
def next_token(m):
 if m.read(PARSER+0x578,1)!=b'\0':binary(m);return
 count=0;quoted=False;saw=False;cursor=m.get(PARSER+0x520);m.put(0x88ab4c,cursor)
 if m.read(LINE+((m.get(PARSER+0x514)-1)&cursor),1)!=b'\0':
  while True:
   c=m.read(LINE+cursor,1).decode('latin1')
   if not quoted and c in string(m,m.get(PARSER+0x580)):
    if count==0:m.write(TOKEN,c.encode('latin1'));cursor+=1;m.put(PARSER+0x520,cursor);count=1
    break
   if not quoted and (c in string(m,m.get(PARSER+0x57c)) or c in '\t ,'):
    if count:break
   elif c=='"':quoted=not quoted;saw=True
   else:m.write(TOKEN+((m.get(PARSER+0x518)-1)&count),c.encode('latin1'));count+=1
   cursor+=1;m.put(PARSER+0x520,cursor)
   if (saw and not quoted and count==0) or m.read(LINE+((m.get(PARSER+0x514)-1)&cursor),1)==b'\0':break
 m.write(TOKEN+((m.get(PARSER+0x518)-1)&count),b'\0')
def push(m,table):
 depth=b.signed(m.get(PARSER+0x570))
 if depth>=7:return -1
 depth+=1;m.put(PARSER+0x570,depth);m.put(PARSER+0x530+depth*4,table);m.put(PARSER+0x550+m.get(PARSER+0x570)*4,0);return b.signed(m.get(PARSER+0x570))
def snapshot(m):return dict(cursor=m.get(PARSER+0x520),previous=m.get(0x88ab4c),buffer=m.read(TOKEN,128).hex())
def observe(mu,a,z,u):
 global binaryCalls
 if 0x4f7fb0<=a<=0x4f80fe or 0x4f10e0<=a<=0x4f111e:visited.add(a)
 if a!=0x4f7df0:return
 binaryCalls+=1;m=capture();binary(m);load(m);sp=mu.reg_read(UC_X86_REG_ESP);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for a,z in [(0x4f7fb0,0x4f80fe),(0x4f10e0,0x4f111e),(0x4f7df0,0x4f7df0)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=z)
def options(line='',**kw):
 p=dict(line=line,seed=17,capacity=128,cursor=0,binary=0,depth=-1,separators=None,singles=None,label='synthetic');p.update(kw);return p
def main():
 global binaryCalls
 rows=[];errors=[];rng=random.Random(0x4f7fb0);cases=[]
 lines=['',' ','a','a b','a,b',' a\t b ','""','"" x','a""b','"a b"c','"a,b" , d','"unterminated','a=b+c;d','a("x=y")','x'*127,'y'*128,'z'*255]
 for line,cap,sep,single in itertools.product(lines,[1,2,7,8,31,128],[None,'',';='],[None,'=+()',' ,']):cases.append(options(line,capacity=cap,separators=sep,singles=single,seed=rng.randrange(256)))
 for number,line in enumerate((B/'extracted/AUDIO/AUDIO.CFG').read_text(encoding='latin1').splitlines(),1):
  line=line.split(';',1)[0].strip()
  if re.match(r'^(sample|group)\s',line,re.I):cases.append(options(line,label='authored:'+str(number)))
 for flag in [1,2,255]:cases.append(options('ignored',binary=flag))
 for p in cases:
  m=setup(p);load(m);binaryCalls=0;expected=[];actual=[]
  for step in range(256):
   previous=m.get(PARSER+0x520);next_token(m);expected.append(snapshot(m));n.call(0x4f7fb0,[PARSER],count=1000000);actual.append(snapshot(capture()))
   if p['binary'] or m.get(PARSER+0x520)==previous:break
  got=capture();bad=[]
  if expected!=actual:bad.append(dict(snapshots=actual,want=expected))
  if got.sha()!=m.sha():bad.append(dict(sha=got.sha(),want=m.sha()))
  if binaryCalls!=int(bool(p['binary'])):bad.append('binary calls')
  if bad:errors.append(dict(index=len(rows),input=p,bad=bad))
  rows.append(dict(kind='tokens',input=p,nativeSha=got.sha(),snapshots=actual,binaryCalls=binaryCalls))
  if errors:break
 if not errors:
  for depth,table in itertools.product(range(-1,10),[0,0x810470,0xffffffff]):
   p=options(depth=depth);p['table']=table;m=setup(p);load(m);want=push(m,table);got=b.signed(n.call(0x4f10e0,[PARSER,table]));actual=capture()
   if got!=want or actual.sha()!=m.sha():errors.append(dict(depth=depth,got=got,want=want))
   rows.append(dict(kind='push',input=p,nativeSha=actual.sha(),result=got))
 report=dict(binarySha256=n.sha256,checks=len(rows),tokenCalls=sum(len(r.get('snapshots',[])) for r in rows),authoredLines=sum(r['input']['label'].startswith('authored:') for r in rows),mismatches=len(errors),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:1],method='Original4f7fb0 text token scanner and4f10e0 table stack execute unchanged. Only binary token branch4f7df0 is a mutable service. All128 output-buffer bytes, cursor/global previous cursor per token and entire prepared memory compare.',limits=['Disjoint valid parser/line/token/delimiter buffers; line length below4096 and readable raw cursor range. Text tokens preserve byte values; supplied delimiter strings are terminated. Binary encoding parser remains a service.','Token capacity mask is retained literally, including non-power-of-two capacities7/31. First punctuation character may be emitted as its own token; quotes suppress delimiters and empty quotes return an empty token.','1230 shipped sample/group source lines are fed to this token reader after externally stripping line comments; native file/line scanner is separate. Table stack depth starts-1..9; depths>=7 reject.','No authored command credit, managed execution pending.'])
 (B/'reports/native-text-tokens-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-text-tokens-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
