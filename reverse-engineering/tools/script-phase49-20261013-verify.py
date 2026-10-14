"""Originalwide line4fc390 +rawbyte/refill4fc2d0 +word4fc360, only4fb550 finalIO."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase26-20261013-verify.py').read_text().split('\nfiles=')[0])
n=nm.NativeX86()
def payload49():return config['file'].encode('utf-16le')+(bytes([config['oddByte']])if 'oddByte'in config else b'')
def read49(m,p,s,args):
 handle,buffer,requested=args;data=payload49();pos=stream['position'];count=min(requested,config['chunk'],max(0,len(data)-pos));m.write(buffer,data[pos:pos+count]);stream['position']+=count;stream['events'].append(dict(args=list(args),position=pos,count=count));return count
lines.read_file=read49
def word49():
 first=lines.read_byte(Image(),{},stream);second=lines.read_byte(Image(),{},stream);return(second&0xffff0000)|((second&255)<<8)|(first&255)
def next49():
 line=rd(PARSER+0x50c);count=0;quote=False;visible=False;restart=True
 while True:
  if restart:count=0;visible=False;wd(PARSER+0x51c,rd(PARSER+0x51c)+1);wd(PARSER+0x520,0);restart=False
  c=word49()&65535
  if not c:break
  if c in[10,13]:
   if c==13:word49()
   if count and visible:break
   wd(PARSER+0x51c,rd(PARSER+0x51c)+1);visible=False;continue
  if c==59 and not quote:
   discard=not count or not visible
   while True:
    c=word49()&65535
    if c in[0,10,13]:break
   if c==13:word49()
   if discard:restart=True;continue
   break
  if c==34:quote=not quote;visible=True
  elif c not in[9,32]:visible=True
  size=rd(PARSER+0x518);mask=(((size if size<0x80000000 else size-0x100000000)>>1)-1)&0xffffffff;p=line+2*(mask&count);wb(p,c);wb(p+1,c>>8);count+=1
 wb(line+2*count,0);wb(line+2*count+1,0);return count

def hook49(mu,address,size,data):
 if address!=0x4fb550:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<3I',sp+4));handle,buffer,requested=args;payload=payload49();pos=stream['position'];count=min(requested,config['chunk'],max(0,len(payload)-pos));n.write(buffer,payload[pos:pos+count]);stream['position']+=count;stream['events'].append(dict(args=args,position=pos,count=count));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,count);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook49)
def execute49(c,method='Line'):
 global config,shadow,stream,checks
 config=c;setup26(dict(c,file=''));n.pack('<I',PARSER+0x574,len(payload49()));n.pack('<I',PARSER+0x514,c.get('lineCapacity',4096));n.pack('<I',PARSER+0x518,c['capacity']);n.pack('<I',PARSER+0x520,0x12345678);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};stream=fresh_stream();want=word49()if method=='Word'else next49();mf=snapshot(True);ms=stream.copy();stream=fresh_stream();got=n.call(0x4fc360 if method=='Word'else 0x4fc390,[PARSER],count=4000000);nf=snapshot();ns=stream.copy()
 for group,a,b in [('return',got,want),('images',nf,mf),('stream',ns,ms)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,inputs=dict(parser=PARSER),initial=initial,returnValue=got,final=nf,nativeStream=ns))
for file,capacity,chunk in itertools.product(['','a','a\nb','a\r\nb','a\rb','\n \t\n x\n',';comment',' ;comment\n x ;tail\n','"semi;colon" next;tail\r\nx','"unclosed\nnext\n','x;tail','\n\n\n',' \n \n','\r\r\n\n','\u03b1\u4e2d\t\n','\0after','a\0after','x'*255,'z'*256],[2,14,16,62,512],[1,3,4096]):execute49(dict(file=file,capacity=capacity,chunk=chunk))
for file,chunk in itertools.product(['','A','\u1234','\uffff'],[1,3,4096]):execute49(dict(file=file,capacity=512,chunk=chunk),'Word')
for oddByte in [1,127,255]:execute49(dict(file='',oddByte=oddByte,capacity=512,chunk=1),'Word')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],managedExecution=False,newEntries=2,ports=['4fb550 finalrawbytes'])
(nm.BASE/'reports/script-phase49-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase49-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
