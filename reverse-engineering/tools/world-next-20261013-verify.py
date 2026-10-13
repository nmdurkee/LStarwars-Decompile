import importlib.util,json,struct,itertools,hashlib,re
from pathlib import Path
B=Path(__file__).resolve().parent.parent
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
base=module('native','native-x86.py');lines=module('lines','native-text-lines-verify.py');tokens=module('tokens','native-text-tokens-verify.py');n=base.NativeX86();D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
WORLD=D;PARSER=D+0x6000;BUFFER=D+0x7000;LINE=D+0x8000;TOKEN=D+0x9000;TEXT=D+0xe000;ARENA=D+0x10000;SCENE=D+0x20000;DISPLAY=D+0x21000;STATIC=D+0x23000;DYNAMIC=D+0x24000;NAMES=D+0x26000;SIZE=0x30000;HANDLE=0x12345678
lines.PARSER=PARSER;lines.BUFFER=BUFFER;lines.LINE=LINE;lines.HANDLE=HANDLE;tokens.PARSER=PARSER;tokens.LINE=LINE;tokens.TOKEN=TOKEN
class Image:
 def __init__(self,data=None):self.data=bytearray([0x6d])*SIZE if data is None else bytearray(data);self.extra=0
 def read(self,a,z):
  if a==0x88ab4c:return struct.pack('<I',self.extra)[:z]
  o=a-D;assert 0<=o and o+z<=SIZE,(hex(a),z);return bytes(self.data[o:o+z])
 def write(self,a,b):
  if a==0x88ab4c:self.extra=struct.unpack('<I',b)[0];return
  o=a-D;assert 0<=o and o+len(b)<=SIZE;self.data[o:o+len(b)]=b
 def get(self,a):return struct.unpack('<I',self.read(a,4))[0]
 def put(self,a,v):self.write(a,struct.pack('<I',v&0xffffffff))
 def text(self,a,t):self.write(a,t.encode('latin1')+b'\0')
 def sha(self):return hashlib.sha256(struct.pack('<I',self.extra)+self.data).hexdigest()
def options(o):
 p=dict(text='portaldoor door 1 trigger_at_end\n',scene=True,open=True,dynamic=False,cursorOffset=1,names=['door','Door space','DUP','dup'],chunk=4096,binary=0,capacity=4096,failAfter=0x7fffffff,label='synthetic',kind='Load',resetCount=3,resetFlags=7,tablePresent=True);p.update(o);return p
def setup(p):
 m=Image();m.extra=0x17;m.put(WORLD+0x104,ARENA+p['cursorOffset']);m.put(WORLD+0x108,ARENA+0x4000);m.put(WORLD+0x13c,SCENE if p['scene'] else 0);m.put(WORLD+0x5048,0xdeadbeef);m.put(WORLD+0x504c,0x7fffffff)
 m.write(PARSER,bytes(0x584));m.put(PARSER,BUFFER);m.put(PARSER+4,HANDLE);m.put(PARSER+0x50c,LINE);m.put(PARSER+0x510,TOKEN);m.put(PARSER+0x514,4096);m.put(PARSER+0x518,512);m.put(PARSER+0x51c,0xffffffff);m.put(PARSER+0x52c,0xffffffff);m.put(PARSER+0x574,len(p['text']));m.put(PARSER+0x570,0xffffffff)
 m.write(SCENE,bytes(0x114));m.put(SCENE+0x110,DISPLAY if p['dynamic'] else 0);m.put(SCENE+0x24,len(p['names']));m.put(SCENE+0x28,STATIC);m.write(DISPLAY,bytes(0x74));m.put(DISPLAY+0x6c,len(p['names']));m.put(DISPLAY+0x70,DYNAMIC)
 for i,name in enumerate(p['names']):m.text(NAMES+i*0x100,name);m.put(STATIC+i*0x4c+0x44,NAMES+i*0x100);m.put(DYNAMIC+i*0xd0+0xb4,NAMES+i*0x100)
 return m
def load(m):n.write(D,m.data);n.pack('<I',0x88ab4c,m.extra);n.pack('<I',0x97388c,0)
def capture():m=Image(n.read(D,SIZE));m.extra=n.unpack('<I',0x88ab4c)[0];return m
current=None;state=None;calls=[]
def hook(mu,a,z,u):
 if a not in [0x4fc900,0x4fb550,0x4fa300]:return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==0x4fc900:
  args=list(n.unpack('<3I',sp+4));calls.append(dict(address=hex(a),name=n.read(args[0],20).split(b'\0')[0].decode(),args=args[1:]));value=PARSER if current['open'] else 0
 elif a==0x4fb550:
  image=capture();value=lines.read_file(image,current,state,n.unpack('<3I',sp+4));load(image)
 else:
  args=list(n.unpack('<I',sp+4));calls.append(dict(address=hex(a),args=args));n.pack('<I',PARSER,0);value=0
 mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x4fc900,0x4fb550,0x4fa300]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=a,end=a)
def fresh():return dict(position=0,events=[],binaryCalls=0)
def integer(s):
 if s.startswith('$') or s[:2].lower()=='0x':
  s=s[1:] if s.startswith('$') else s[2:];v=0
  for c in s:
   if c not in '0123456789abcdefABCDEF':return 0
   v=((v<<4)|int(c,16))&0xffffffff
  return v
 match=re.match(r'-?\d*',s).group();return(int(match) if match not in ['', '-'] else 0)&0xffffffff
def next_token(m):tokens.next_token(m);return tokens.string(m,TOKEN)
def model(m,p):
 out=[];s=fresh();m.put(WORLD+0x5048,0);m.put(WORLD+0x504c,0)
 if not p['scene']:return out,s
 out.append(dict(address='0x4fc900',name='portaldoors',args=[TEXT,0xffff]))
 if not p['open']:return out,s
 cursor=(m.get(WORLD+0x104)+3)&0xfffffffc;m.put(WORLD+0x104,cursor);m.put(WORLD+0x5048,cursor)
 while lines.line(m,p,s):
  if next_token(m).lower()!='portaldoor':continue
  m.write(cursor,bytes(16));name=next_token(m)
  if name=='':continue
  index=next((i for i,n in enumerate(p['names']) if n.lower()==name.lower()),-1)
  if index<0:continue
  m.put(cursor,SCENE);m.put(cursor+4,0 if p['dynamic'] else STATIC+index*0x4c);m.put(cursor+8,DYNAMIC+index*0xd0 if p['dynamic'] else 0)
  m.write(cursor+0xe,bytes([integer(next_token(m))&255]))
  while True:
   token=next_token(m)
   if not token:break
   if token.lower()=='trigger_at_end':m.write(cursor+0xc,struct.pack('<H',struct.unpack('<H',m.read(cursor+0xc,2))[0]|1))
  m.put(WORLD+0x504c,m.get(WORLD+0x504c)+1);cursor+=16
 out.append(dict(address='0x4fa300',args=[PARSER]));m.put(PARSER,0)
 if m.get(WORLD+0x504c)>0:m.put(WORLD+0x104,(cursor+15)&0xfffffff0)
 else:m.put(WORLD+0x5048,0)
 return out,s
rows=[];errors=[]
def run(p):
 global current,state,calls
 p=options(p);current=p;state=fresh();calls=[];m=setup(p)
 if p['kind']=='Reset':
  pointer=ARENA+p['cursorOffset'];m.put(WORLD+0x5048,pointer if p['tablePresent'] else 0);m.put(WORLD+0x504c,p['resetCount'])
  for i in range(max(0,p['resetCount'])):m.write(pointer+i*16+12,struct.pack('<H',p['resetFlags']))
 load(m);expected=Image(m.data);expected.extra=m.extra
 if p['kind']=='Load':wantCalls,wantState=model(expected,p);n.call(0x55f960,[WORLD,TEXT],count=10000000)
 else:
  wantCalls=[];wantState=fresh()
  if p['tablePresent']:
   for i in range(max(0,p['resetCount'])):expected.write(ARENA+p['cursorOffset']+i*16+12,struct.pack('<H',p['resetFlags']&0xfff9))
  n.call(0x55fbb0,[WORLD])
 actual=capture();bad=[]
 if actual.sha()!=expected.sha():bad.append(dict(memoryDifferences=[hex(D+i) for i,(x,y) in enumerate(zip(actual.data,expected.data)) if x!=y][:20],extra=[actual.extra,expected.extra]))
 if calls!=wantCalls:bad.append(dict(calls=calls,want=wantCalls))
 if state!=wantState:bad.append(dict(stream=state,want=wantState))
 if bad:errors.append(dict(index=len(rows),input=p,bad=bad))
 rows.append(dict(input=p,nativeSha=actual.sha(),count=actual.get(WORLD+0x504c),table=actual.get(WORLD+0x5048),cursor=actual.get(WORLD+0x104),calls=calls.copy(),events=state['events']))
def main():
 texts=['','portaldoor','portaldoor "" 1','portaldoor missing 2 trigger_at_end','PORTALDOOR DOOR 1 TRIGGER_AT_END','portaldoor "Door space" -1 ignored trigger_at_end','portaldoor dup 256 trigger_at_end trigger_at_end','portaldoor door $1ff','portaldoor door 0x100','portaldoor door -257','portaldoor door +2','portaldoor door 2147483648','portaldoor door 1 "" trigger_at_end','notportaldoor door 2\nportaldoor door\nportaldoor missing 2\nportaldoor "Door space" 3',';comment\r\nportaldoor door 4;tail\r\nportaldoor dup 2','portaldoor door 1\rportaldoor dup 2','portaldoor door 1\0portaldoor dup 2','portaldoor_start\nportaldoor door 1\nportaldoor_end\n']
 for text,dynamic,offset,scene,opened in itertools.product(texts,[False,True],[0,1,3,15],[False,True],[False,True]):run(dict(text=text,dynamic=dynamic,cursorOffset=offset,scene=scene,open=opened,chunk=7))
 #Preserve every active authored definition line exactly; comment stripping is the prior loader's responsibility.
 authored=[]
 for file in sorted((B/'extracted/LEVELS').rglob('*.TXT')):
  for no,line in enumerate(file.read_bytes().decode('latin1').splitlines(),1):
   if re.match(r'^\s*portaldoor\s',line,re.I):authored.append(dict(path=str(file.relative_to(B)),line=no,text=line))
 for source in authored:
  match=re.match(r'^\s*portaldoor\s+(?:"([^"]*)"|(\S+))',source['text'],re.I);name=(match.group(1) if match.group(1) is not None else match.group(2)) if match else ''
  for dynamic in [False,True]:run(dict(text=source['text']+'\n',dynamic=dynamic,names=[name],label='authored:'+source['path']+':'+str(source['line'])))
 for present,count,flags in itertools.product([False,True],[-1,0,1,3],[0,1,2,3,4,7,0xffff]):run(dict(kind='Reset',tablePresent=present,resetCount=count,resetFlags=flags))
 report=dict(binarySha256=n.sha256,groups={k:sum(r['input']['kind']==k for r in rows) for k in ['Load','Reset']},checks=len(rows),mismatches=len(errors),authoredLines=len(authored),authoredCases=len(authored)*2,bytesComparedPerCase=SIZE+4,examples=errors[:3],method='Original55f960 and55fbb0 reset with original4fc5b0/4fc2d0 line/refill reader,4f7fb0 token parser,4f9e70 integer reader,4f8b10 case comparison and5cf5b0/5cf510 static/dynamic scene lookup. Only parser-open4fc900, file read4fb550 and parser-close4fa300 are services. Full prepared image, arena writes, stream consumption and service trace compare.',limits=['Disjoint prepared byte image and scene records; optional diagnostic lookup global97388c disabled. No scene carrier loading or animation/portal visibility execution.','Text-mode parser only, capacities4096/512, numeric tokens<64bytes, lines/tokens fit backing. Input is post-comment-stripping caller text; active authored definition lines are retained exactly.','Prepared matching scene names provide controlled bind success; authored operand coverage does not prove binding to live shipped scene objects.','No arena end/capacity checks exist in55f960; fixtures provide enough backing. No managed replay claim.'])
 (B/'reports/world-next-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/world-next-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');(B/'reports/world-next-20261013-authored-lines.json').write_text(json.dumps(authored,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
