import importlib.util,json,struct,gzip,hashlib,itertools,random,re,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('setup',Path(__file__).with_name('native-sound-initialization-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);b.REGIONS=[(0x2920000,0x44000),(b.D,0x80000)];n=b.x.NativeX86();B=b.B;D=b.D
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
TABLE=D+0x1000;HEADS=D+0x2000;RECORDS=D+0x4000;BANKS=D+0x20000;BACKUP=D+0x30000;TOKENS=D+0x50000;PARSER=D+0x60000;TEMP=D+0x61000
TABLEWORDS=[]
for i in range(256):
 v=i<<24
 for j in range(8):v=((v<<1)^(0x04c11db7 if v&0x80000000 else 0))&0xffffffff
 TABLEWORDS.append(v)
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def flt(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def text(m,a):
 out=[]
 while m.read(a,1)!=b'\0':out.append(m.read(a,1)[0]);a+=1
 return bytes(out).decode('ascii')
def token(s):
 try:f=bits(float(s))
 except (ValueError,OverflowError):f=0
 q=re.match(r'^[+-]?\d+',s);integer=int(q[0]) if q else 0
 return dict(text=s,integer=integer,real=f)
def options(tokens,**kw):
 p=dict(tokens=[token(t) for t in tokens],seed=17,index=3,bankNames=[],nameCount=0,builtinCount=0,flags=0,head=-1,label='synthetic');p.update(kw);return p
def setup(p):
 m=b.Image(p['seed']);m.put(0x2947d80,TABLE);m.write(TABLE,struct.pack('<256I',*TABLEWORDS));m.put(0x292fda0,HEADS);m.write(HEADS,struct.pack('<256h',*([p['head']]*256)));m.put(0x2947b74,RECORDS);m.put(0x292fda4,BACKUP);m.put(0x2947d70,BANKS);m.put(0x296201c,p['index']);m.put(0x2962014,len(p['bankNames']));m.put(0x2962018,p['nameCount']);m.put(0x296202c,p['builtinCount']);m.put(RECORDS+p['index']*64+4,p['flags']);m.put(PARSER+0x510,TOKENS);m.text(TOKENS,'')
 for i,name in enumerate(p['bankNames']):m.put(BANKS+i*28,0x2948f10+i*64);m.text(0x2948f10+i*64,name);m.put(0x2921888+i*4,0xfffffffe+i)
 return m
def initialize(m,index):
 r=RECORDS+index*64;m.put(r,(0x293b318+m.get(0x296201c)*32)&0xffffffff);m.put(r+4,(m.get(r+4)&0xff880000)|0x7fff);m.put(r+8,0x5622);m.write(r+12,b'\0');m.write(r+0x12,struct.pack('<3H',0x3fff,0xffff,0));m.write(r+0x18,bytes(0x24));m.write(BACKUP+index*64,m.read(r,64))
def bounded(m,a,s,size):m.text(a,s.split('\0')[0][:size-1])
def hash_name(s):
 h=0
 for c in s.upper().encode('ascii'):h=((h<<8)^TABLEWORDS[c^(h>>24)])&0xffffffff
 return h
def model(p,m=None,reader=None):
 m=setup(p) if m is None else m;initialize(m,p['index']);r=RECORDS+p['index']*64;cursor=-1;events=[]
 def take(kind='next'):
  nonlocal cursor
  if reader is not None:return reader(kind)
  cursor+=1;t=p['tokens'][cursor] if cursor<len(p['tokens']) else token('');a=TOKENS+cursor*256;m.text(a,t['text']);m.put(PARSER+0x510,a);events.append([kind,cursor,t['text']]);
  if kind=='real':m.put(TEMP,t['real']);return flt(t['real'])
  if kind=='integer':return t['integer']
  return t['text'] if cursor<len(p['tokens']) else None
 def flag(f):m.put(r+4,m.get(r+4)|f)
 def clamp(v,lo,hi):return lo if v<lo else hi if v>hi else v
 t=take()
 while t is not None:
  key=t.lower()
  if key in ['disable','comment','loop','nofade','global']:flag({'disable':0x40000,'comment':0x80000,'loop':0x8000,'nofade':0x400000,'global':0x20000}[key])
  elif key=='name':
   value=take();a=0x293b318+p['index']*32;bounded(m,a,value,32);m.put(r,a);bucket=hash_name(text(m,a))&255;head=HEADS+bucket*2;m.write(r+0x10,m.read(head,2));m.write(head,struct.pack('<H',p['index']))
  elif key=='fname':
   value=take()+'.wav';m.text(m.get(PARSER+0x510),value);disabled=m.get(r+4)&0xc0000;bank=0;count=m.get(0x2962014)
   if disabled:flag(0x7fff)
   while bank<count and text(m,m.get(BANKS+bank*28)).upper()!=value.upper():bank+=1
   if bank<count:
    if not disabled:m.put(r+4,(m.get(r+4)&~0x7fff)|(bank&0x7fff))
    m.put(r+0x3c,m.get(BANKS+bank*28));m.put(0x2921888+bank*4,m.get(0x2921888+bank*4)+1)
   else:
    nameIndex=m.get(0x2962018);target=0x2948f10+nameIndex*64
    if not disabled:
     at=BANKS+bank*28;m.put(at,target);m.put(at+4,0x75a);m.put(at+12,bank-p['builtinCount']+0x1000);m.put(at+8,0)
    m.put(0x2962018,nameIndex+1);bounded(m,target,value,64);m.put(r+0x3c,target)
    if not disabled:m.put(0x2921888+bank*4,1);m.put(r+4,(m.get(r+4)&~0x7fff)|(bank&0x7fff));m.put(0x2962014,bank+1)
  elif key=='pitch':m.put(r+8,take('integer'))
  elif key in ['pri','volume','fcat']:
   off,lo,hi,fmt=dict(pri=(12,-128,127,'<b'),volume=(0x12,0,16383,'<H'),fcat=(0x16,0,65535,'<H'))[key];m.write(r+off,struct.pack(fmt,clamp(take('integer'),lo,hi)))
  elif key in ['pan','pitch_rnd','volume_rnd','near','far']:
   off,lo,hi=dict(pan=(0x18,-1.,1.),pitch_rnd=(0x1c,0.,1.),volume_rnd=(0x20,-1.,0.),near=(0x24,0.,250.),far=(0x28,0.,250.))[key];m.put(r+off,bits(clamp(take('real'),lo,hi)))
  elif key=='rumble':
   buzz=take('real');strength=take('integer');m.put(r+0x2c,bits(clamp(buzz,0.,5.)));m.put(r+0x30,clamp(strength,0,255));m.put(r+0x34,bits(clamp(take('real'),0.,5.)));m.put(r+0x38,bits(clamp(take('real'),0.,5.)))
  t=take()
 m.put(r+4,(m.get(r+4)&~0x100000)|0x200000);m.write(BACKUP+p['index']*64,m.read(r,64));m.put(0x296201c,p['index']+1);return m,events
current=None;cursor=-1;events=[];visited=set()
def observe(mu,a,size,user):
 global cursor
 if 0x6516a0<=a<0x652008:visited.add(a)
 if a not in [0x4f7fb0,0x4f9e70,0x4f8100]:return
 sp=mu.reg_read(UC_X86_REG_ESP);assert n.unpack('<I',sp+4)[0]==PARSER;cursor+=1;t=current['tokens'][cursor] if cursor<len(current['tokens']) else token('');ptr=TOKENS+cursor*256;n.write(ptr,t['text'].encode('ascii')+b'\0');n.pack('<I',PARSER+0x510,ptr);kind={0x4f7fb0:'next',0x4f9e70:'integer',0x4f8100:'real'}[a];events.append([kind,cursor,t['text']])
 if kind=='real':n.pack('<I',TEMP,t['real']);mu.reg_write(UC_X86_REG_EIP,n.STOP+0x100);return
 mu.reg_write(UC_X86_REG_EAX,(t['integer'] if kind=='integer' else int(cursor<len(current['tokens'])))&0xffffffff);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.write(n.STOP+0x100,b'\xd9\x05'+struct.pack('<I',TEMP)+b'\xc3');n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x6516a0,end=0x652007)
for a in [0x4f7fb0,0x4f9e70,0x4f8100]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def main():
 global current,cursor,events
 cases=[options([]),options(['name','LegoSingle','fname','Audio/Test','pitch','22050','pan','-0','pri','-200','loop','pitch_rnd','1.5','volume','20000','nofade','volume_rnd','-2','near','-2','far','300','global','rumble','6','300','-1','2','fcat','70000'])]
 for disabled,names,tokenName,head in itertools.product([[],['disable'],['comment'],['disable','comment']],[[],['Test.wav'],['Other.wav','TEST.WAV']],['Test','Missing'],[-1,0,2]):
  cases.append(options(disabled+['fname',tokenName,'name','n'*40],bankNames=names,nameCount=len(names),builtinCount=len(names),head=head,flags=0xfff00000))
 for key in ['pan','pitch_rnd','volume_rnd','near','far']:
  for value in ['-1000','-1','-0','0','0.5','1','5','250','1000','1e-40','-1e-40']:cases.append(options([key,value]))
 for key in ['pitch','pri','volume','fcat']:
  for value in ['-2147483648','-100000','-129','-128','-1','0','127','128','16383','16384','65535','65536','2147483647']:cases.append(options([key,value]))
 for x in ['-100','-0','0','0.25','5','100']:
  for strength in ['-100','0','255','1000']:cases.append(options(['rumble',x,strength,x,x]))
 for tokens in [['name','a','name','b'],['name','same','name','same'],['fname','first','fname','first'],['fname','first','disable','fname','second'],['disable','fname','first','comment','fname','first'],['fname','z'*80],['Unrecognized','SEQ','Group']]:cases.append(options(tokens))
 cfg=B/'extracted/AUDIO/AUDIO.CFG';authored=0
 for lineNumber,line in enumerate(cfg.read_text(encoding='latin1').splitlines(),1):
  line=line.split(';',1)[0].strip()
  if not re.match(r'^Sample\s',line,re.I):continue
  tokens=[a if a is not None and a!='' else c for a,c in re.findall(r'"([^"]*)"|([^\s]+)',line)][1:]
  cases.append(options(tokens,seed=lineNumber%256,label='authored:'+str(lineNumber)));authored+=1
 rows=[];errors=[]
 for index,p in enumerate(cases):
  current=p;cursor=-1;events=[];before=setup(p);want,wantEvents=model(p)
  for a,data in before.r.items():n.write(a,data)
  n.call(0x6516a0,[PARSER],count=1000000);actual=b.Image(0)
  for a,size in b.REGIONS:actual.r[a]=bytearray(n.read(a,size))
  bad=[]
  if events!=wantEvents:bad.append(dict(events=events,wantEvents=wantEvents))
  if actual.sha()!=want.sha():
   diff=[]
   for a,data in want.r.items():diff.extend(dict(address=hex(a+i),got=actual.r[a][i],want=v) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diff[:20]))
  if bad:errors.append(dict(index=index,input=p,bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),events=events))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),authoredSampleLines=authored,authoredCompared=sum(r['input']['label'].startswith('authored:') for r in rows),visitedInstructions=len(visited),bytesComparedPerCase=sum(size for a,size in b.REGIONS),examples=errors[:2],method='Original6516a0 with original651530, CRC hash, ASCII comparators, append/bounded-copy and final memmove. Only parser next-token/integer/real readers are declared services. Exact token-read sequence and complete prepared sound/global/arena image compare after each sample.',limits=['Finite float32 numeric-service returns and terminated ASCII tokens, adequate disjoint sound/bank/name/hash buffers; one sample processed per case, with prepared prior bank/head state.','Shipped1130 sample lines are independently tokenized into explicit inputs; native scanner and numeric text parsing are not claimed. Group declarations and audio backend remain outside this handler.','Existing signed-short bucket heads are preserved; repeated name tokens can create native self-links. This batch does not follow such malformed cyclic chains.','Runtime memory uses virtual addresses in owned byte arrays. Managed replay pending.'])
 (B/'reports/native-sound-definition-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-definition-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,table=TABLEWORDS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
