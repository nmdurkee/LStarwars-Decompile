import importlib.util,json,struct,gzip,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('base',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.x.NativeX86();B=b.B;D=b.D;b.REGIONS=[(0x91eec4,4),(D,0x50000)]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
PARSER=D+0x1000;TOKEN=D+0x4000;FIRST=D+0x5000;SECOND=D+0x6000;PRIMARY=D+0x8000;SECONDARY=D+0x8400;NAMES=D+0x9000;WIDE=D+0x10000;OUTPUT=D+0x40000;CALLBACKS=[D+0xf000+i*16 for i in range(8)]
events=[];visited=set()
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def string(m,a):
 if not a:return []
 out=[]
 while m.read(a,1)!=b'\0':out.append(m.read(a,1)[0]);a+=1
 return out
 def_unused=0
def fold(c):
 if ((c+0x9f)&255)<26 or c>223:c=(c-32)&255
 return c if c<128 else c-256
def compare(m,a,c):
 if not a:return -1
 if not c:return 1
 while True:
  x,y=fold(m.read(a,1)[0]),fold(m.read(c,1)[0]);a+=1;c+=1
  if x!=y:return 1 if x>y else -1
  if x==0:return 0
def narrow(c):return c if c<256 else {0x2019:0x92,0x2013:0x96,0x2018:0x91,0x2026:0x85,0x2122:0x99}.get(c,63)
def convert(m,target,source):
 if not target or not source:return
 m.write(target,b'\0');i=0
 while True:
  c=struct.unpack('<H',m.read(source+i*2,2))[0]
  if not c:break
  m.write(target+i,bytes([narrow(c)]));i+=1
 m.write(target+i,b'\0')
def callback(m,target,parser):
 m.put(D+0x3000,target);m.put(parser+0x570,7);m.write(TOKEN,b'!');m.put(0x91eec4,0)
def dispatch(m,p):
 source=m.get(PARSER+0x510);token=[]
 if p['wide']:
  i=0
  while True:
   c=struct.unpack('<H',m.read(source+i*2,2))[0]
   if not c:break
   token.append(narrow(c));i+=1
 else:token=string(m,source)
 if not token or token[0]==59:return []
 depth=b.signed(m.get(PARSER+0x570));target=0
 if depth>=0:
  for table in [m.get(PARSER+0x530+depth*4),m.get(PARSER+0x550+depth*4)]:
   if not table:continue
   i=0
   while m.get(table+i*8):
    name=string(m,m.get(table+i*8))
    if list(map(fold,name))==list(map(fold,token)):target=m.get(table+i*8+4);break
    i+=1
   if target:break
 if not target:target=m.get(0x91eec4)
 if not target:return []
 result=[dict(target=target,parser=PARSER)];callback(m,target,PARSER);return result
def setup(p):
 m=b.Image(p['seed']);kind=p['kind']
 if kind=='compare':m.write(FIRST,bytes(p['first']+[0]));m.write(SECOND,bytes(p['second']+[0]))
 elif kind=='convert':m.write(WIDE,struct.pack('<'+str(len(p['words'])+1)+'H',*(p['words']+[0])))
 else:
  m.put(PARSER+0x510,TOKEN if not p['nullToken'] else 0);m.write(PARSER+0x578,bytes([int(p['wide'])]));m.put(PARSER+0x570,p['depth']);m.put(0x91eec4,CALLBACKS[7] if p['fallback'] else 0)
  if p['wide']:m.write(TOKEN,struct.pack('<'+str(len(p['token'])+1)+'H',*(p['token']+[0])))
  else:m.write(TOKEN,bytes(p['token']+[0]))
  for depth in range(8):m.put(PARSER+0x530+depth*4,PRIMARY);m.put(PARSER+0x550+depth*4,SECONDARY if p['secondary'] else 0)
  for table,names,offset in [(PRIMARY,p['primary'],0),(SECONDARY,p['secondary'] or [],3)]:
   for i,name in enumerate(names):ptr=NAMES+(offset+i)*128;m.write(ptr,bytes(name+[0]));m.put(table+i*8,ptr);m.put(table+i*8+4,CALLBACKS[offset+i])
   m.put(table+len(names)*8,0)
 return m
def observe(mu,a,z,u):
 if 0x4fa020<=a<0x4fa190 or 0x4f8b10<=a<0x4f8ba0 or 0x4f2dc0<=a<0x4f2e60:visited.add(a)
 if a not in CALLBACKS:return
 sp=mu.reg_read(UC_X86_REG_ESP);parser=n.unpack('<I',sp+4)[0];events.append(dict(target=a,parser=parser));m=capture();callback(m,a,parser);load(m);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for a,z in [(0x4fa020,0x4fa18f),(0x4f8b10,0x4f8b9f),(0x4f2dc0,0x4f2e5f)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=z)
for a in CALLBACKS:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def byte(s):return list(s.encode('latin1'))
def main():
 global events
 cases=[];rows=[];errors=[]
 for first,second in itertools.product(range(256),[0,65,97,223,224,255]):cases.append(dict(kind='compare',first=[first] if first else [],second=[second] if second else [],nullFirst=False,nullSecond=False,seed=17))
 for a,c in itertools.product([False,True],repeat=2):cases.append(dict(kind='compare',first=byte('aBc'),second=byte('AbC'),nullFirst=a,nullSecond=c,seed=31))
 for source,target in itertools.product([False,True],repeat=2):cases.append(dict(kind='convert',words=[65,0x2013,0x2018,0x2019,0x2026,0x2122,0x0100,0xffff,255],nullSource=source,nullTarget=target,seed=7))
 cases.append(dict(kind='convert',words=list(range(1,65536)),nullSource=False,nullTarget=False,seed=19))
 for token,depth,secondary,fallback,wide in itertools.product(['Sample','sAmPlE','Group','Unknown',';Sample','','\xe0','\xc0'],[-1,0,7],[False,True],[False,True],[False,True]):cases.append(dict(kind='dispatch',token=byte(token),depth=depth,secondary=[byte('Group'),byte('Sample'),byte('\xc0')] if secondary else None,primary=[byte('Sample'),byte('sample'),byte('Other')],fallback=fallback,wide=wide,nullToken=False,seed=23))
 for c in [0x2013,0x2018,0x2019,0x2026,0x2122,0x1234]:cases.append(dict(kind='dispatch',token=[c],depth=0,secondary=None,primary=[[narrow(c)]],fallback=True,wide=True,nullToken=False,seed=27))
 cases.append(dict(kind='dispatch',token=[],depth=0,secondary=None,primary=[],fallback=True,wide=False,nullToken=True,seed=13))
 for index,p in enumerate(cases):
  m=setup(p);load(m);events=[];kind=p['kind'];wanted=None;ev=[]
  if kind=='compare':args=[0 if p['nullFirst'] else FIRST,0 if p['nullSecond'] else SECOND];wanted=compare(m,*args);got=b.signed(n.call(0x4f8b10,args))
  elif kind=='convert':args=[0 if p['nullTarget'] else OUTPUT,0 if p['nullSource'] else WIDE];convert(m,*args);n.call(0x4f2dc0,args,count=5000000);got=None
  else:ev=dispatch(m,p);n.call(0x4fa020,[PARSER],count=1000000);got=None
  actual=capture();bad=[]
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(hex(a+i) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:20]))
  if wanted!=got:bad.append(dict(result=got,want=wanted))
  if events!=ev:bad.append(dict(events=events,want=ev))
  if bad:errors.append(dict(index,input=p,bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),result=got,events=events))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),groups={k:sum(r['input']['kind']==k for r in rows) for k in ['compare','convert','dispatch']},examples=errors[:1],method='Original4fa020 command dispatch calls real4f8b10 byte comparator and4f2dc0 narrow conversion. Only selected command/fallback handlers are mutable services. Full memory, exact comparison returns and callback identity/order compare.',limits=['Command token length below64bytes, stack depth-1..7 with terminated valid primary/optional secondary tables, disjoint readable string backing. Binary-mode null source has native uninitialized local behavior and is excluded.','Comparator foldsASCIIa-z ande0-ff by subtracting32, then uses signed byte order; null-first returns-1 including bothnull. Conversion preserves00-ff, maps five explicit punctuation codepoints, substitutes?otherwise. All65535nonzeroUTF16words exercised.','Callback producer semantics remain explicit. No native file opening or full audio loader composition claimed in this slice. Managed execution pending.'])
 (B/'reports/native-text-dispatch-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-text-dispatch-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
