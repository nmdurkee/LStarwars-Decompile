import importlib.util,json,struct,gzip,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('base',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.x.NativeX86();B=b.B;D=b.D;b.REGIONS=[(D,0x10000)]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
PARSER=D+0x1000;BUFFER=D+0x2000;LINE=D+0x4000;HANDLE=0x12345678
current=None;state=None;visited=set()
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def setup(p):
 m=b.Image(p['seed']);m.put(PARSER,BUFFER);m.put(PARSER+4,HANDLE);m.put(PARSER+0x50c,LINE);m.put(PARSER+0x514,p['capacity']);m.put(PARSER+0x51c,p['lineNumber']);m.put(PARSER+0x520,99);m.put(PARSER+0x524,0);m.put(PARSER+0x528,0);m.put(PARSER+0x52c,0xffffffff);m.put(PARSER+0x574,len(p['text']));m.write(PARSER+0x578,bytes([p['binary']]));return m
def read_file(m,p,s,args):
 handle,buffer,requested=args;assert handle==HANDLE and buffer==BUFFER and 0<=requested<=4096
 data=p['text'].encode('latin1');count=min(requested,p['chunk'],max(0,len(data)-s['position']))
 if s['position']>=p['failAfter']:count=0
 m.write(buffer,data[s['position']:s['position']+count]);s['events'].append(dict(args=list(args),position=s['position'],count=count));s['position']+=count;return count
def read_byte(m,p,s):
 end=b.signed(m.get(PARSER+0x52c));result=(end+1)&0xffffffff
 if b.signed(m.get(PARSER+0x524))>end:
  total=b.signed(m.get(PARSER+0x574))
  if b.signed(result)>total:return result&0xffffff00
  count=read_file(m,p,s,[m.get(PARSER+4),m.get(PARSER),min(4096,total-max(end,0))]);prior=m.get(PARSER+0x52c);m.put(PARSER+0x528,prior+1);m.put(PARSER+0x52c,prior+count)
  if not count:return 0
 pos=m.get(PARSER+0x524);offset=(pos-m.get(PARSER+0x528))&0xffffffff;c=m.read(m.get(PARSER)+offset,1)[0];m.put(PARSER+0x524,pos+1);return(offset&0xffffff00)|c
def binary(m,s):s['binaryCalls']+=1;m.put(PARSER+0x51c,m.get(PARSER+0x51c)+3);m.text(LINE,'binary');return 0xabcdef12
def line(m,p,s):
 if p['binary']:return binary(m,s)
 count=0;quoted=False;visible=False;restart=True
 while True:
  if restart:count=0;m.put(PARSER+0x51c,m.get(PARSER+0x51c)+1);m.put(PARSER+0x520,0);restart=False
  c=read_byte(m,p,s)&255
  if c==0:break
  if c in [10,13]:
   if c==13:read_byte(m,p,s)
   if count and visible:break
   m.put(PARSER+0x51c,m.get(PARSER+0x51c)+1);visible=False;continue
  if c==59 and not quoted:
   discard=count==0 or not visible
   while True:
    c=read_byte(m,p,s)&255
    if c in [0,10,13]:break
   if c==13:read_byte(m,p,s)
   if discard:visible=False;restart=True;continue
   break
  if c==34:quoted=not quoted;visible=True
  elif c not in [9,32]:visible=True
  m.write(LINE+((p['capacity']-1)&count),bytes([c]));count+=1
 m.write(LINE+count,b'\0');return count
def observe(mu,a,z,u):
 if 0x4fc2d0<=a<=0x4fc358 or 0x4fc5b0<=a<=0x4fc6f6:visited.add(a)
 if a not in [0x4fb550,0x4fc390]:return
 sp=mu.reg_read(UC_X86_REG_ESP);m=capture();result=read_file(m,current,state,n.unpack('<3I',sp+4)) if a==0x4fb550 else binary(m,state);load(m);mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for a,z in [(0x4fc2d0,0x4fc358),(0x4fc5b0,0x4fc6f6),(0x4fb550,0x4fb550),(0x4fc390,0x4fc390)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=z)
def options(text='',**kw):
 p=dict(text=text,seed=17,capacity=4096,chunk=4096,lineNumber=0,binary=0,failAfter=0x7fffffff,kind='lines',label='synthetic');p.update(kw);return p
def fresh():return dict(position=0,events=[],binaryCalls=0)
def main():
 global current,state
 rows=[];errors=[];rng=random.Random(0x4fc5b0);cases=[]
 lines=['','a','a\nb','a\r\nb','a\rb','\n \t\n x\n',';comment',' ;comment\n x ;tail\n','"semi;colon" next;tail\r\nx','"unclosed\nnext\n','x;tail','\n\n\n',' \n \n','\r\r\n\n','\x80\xff\t\n','\0after','a\0after']
 for text,cap,chunk in itertools.product(lines,[1,7,8,4096],[1,3,4096]):cases.append(options(text,capacity=cap,chunk=chunk,seed=rng.randrange(256),lineNumber=rng.choice([0,0xffffffff])))
 for z in [4095,4096,4097,8191]:cases.append(options('x'*(z-2)+'\ny',kind='bytes',byteCalls=z+3))
 for chunk in [17,4096]:cases.append(options((B/'extracted/AUDIO/AUDIO.CFG').read_bytes().decode('latin1'),chunk=chunk,label='authored-complete-file'))
 for flag in [1,2,255]:cases.append(options('ignored',binary=flag))
 for stop in [0,3,7]:cases.append(options('a b\nsecond\nthird',chunk=3,failAfter=stop))
 for index,p in enumerate(cases):
  current=p;state=fresh();m=setup(p);load(m);modelState=fresh();want=[];got=[];bad=[]
  if p['kind']=='bytes':
   for i in range(p['byteCalls']):want.append(read_byte(m,p,modelState));got.append(n.call(0x4fc2d0,[PARSER]))
  else:
   for i in range(10000):
    w=line(m,p,modelState);r=n.call(0x4fc5b0,[PARSER],count=10000000);a=capture();want.append(dict(result=w,sha=m.sha()));got.append(dict(result=r,sha=a.sha()))
    if w!=r or a.sha()!=m.sha():bad.append(dict(step=i,result=r,want=w));break
    if w==0 or p['binary']:break
  actual=capture()
  if want!=got:bad.append('results')
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(hex(a+i) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:20]))
  if state!=modelState:bad.append(dict(state=state,want=modelState))
  if bad:errors.append(dict(index,input={k:v for k,v in p.items() if k!='text'},bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),results=got,events=state['events'],binaryCalls=state['binaryCalls']))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),lineCalls=sum(len(r['results']) for r in rows if r['input']['kind']=='lines'),byteCalls=sum(len(r['results']) for r in rows if r['input']['kind']=='bytes'),mismatches=len(errors),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:2],method='Original4fc2d0 buffered byte reader and4fc5b0 line parser compose unchanged. Only file-read4fb550 and binary-line4fc390 are services. Full memory after each line, exact rawDWORD byte returns, file requests and refill consumption compare.',limits=['Disjoint valid4096-byte refill storage, bounded line backing and positive capacity; service returns0..requested bytes. Two complete raw authoredAUDIO.CFG runs use17-byte and4096-byte service chunks, no external comment stripping.','Semicolon comments are active outside quotes, CR always consumes next byte, whitespace-only lines may retain accumulated whitespace, final terminator uses unmasked line count. Unterminated quoted lines retain native behavior.','ReadByte preserves offset bits above low8; callers consume low byte. No binary format/file system backend implementation or managed execution claimed.'])
 (B/'reports/native-text-lines-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-text-lines-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
