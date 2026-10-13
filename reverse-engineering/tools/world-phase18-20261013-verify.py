import json,hashlib,struct,base64,time,random,gzip
from pathlib import Path
p=Path(__file__).with_name('world-phase17-20261013-composed-verify.py');src=p.read_text();exec(compile(src[:src.index('base=json.loads')],str(p),'exec'))
REGIONS.extend([(0x2962a2c,4),(0x2962a3c,4),(0x8109cc,4)]);io['REGIONS']=REGIONS
base=json.loads((B/'reports/world-phase16-20261013-vectors.json').read_text());cases=[];provenance=base['authoredFiles'];env['audioHash']=hashlib.sha256();env['audioCalls']=0
assets={};ap=Path(__file__).with_name('world-phase15-20261013-verify.py');assets['__file__']=str(ap);asc=ap.read_text();exec(compile(asc[:asc.index('rng=random.Random')],str(ap),'exec'),assets)
class Adapter:
 def __init__(self,image):self.m=image
 def W(self,a,v=None):return self.m.word(a) if v is None else self.m.word(a,v)
 def H(self,a,v=None):return self.m.half(a) if v is None else self.m.half(a,v)
 def B(self,a):return self.m.byte(a)
 def F(self,a):return env['f'](self.m.word(a))
services=[];allocations=[];effects=[]
def audio(im,q):
 env['audioCalls']+=1;env['audioHash'].update(struct.pack('<I',0x650e40)+q+struct.pack('<I',16));return assets['sound'](im,q,16)
def effect(im,q,bank):effects.append([base64.b64encode(q).decode(),bank]);return assets['particle'](im,q,bank,True,-1)
env['audio']=audio
# Typed wire operations are the sealed phase16 reader model, used without changing its files.
w=env['word'];h=env['half'];b=env['byte'];f=env['flt'];S=env['S'];U=env['U'];bits=env['bits'];patch=env['patch'];wp=env['wp']
def instance(im,at,v,bank):
 im.write(at+0x51,bytes([bank]));
 for off in [0,4,8]:im.word(at+off,f(im))
 if v<7:im.half(at+0x14,0);im.half(at+0x16,0);im.half(at+0x18,w(im));im.half(at+0x1a,w(im))
 else:
  for off in [0x14,0x16,0x18,0x1a]:im.half(at+off,h(im))
 im.half(at+0x1c,0 if v<22 else h(im));im.word(at+0x20,0 if v<8 else bits(env['round32'](S(w(im))/60.0)) if v<34 else f(im));q=env['name'](im);im.write(at+0x24,q);im.word(at+0x10,99999);physical=effect(im,q,bank);im.word(at+0xc,physical)
 if physical==0xffffffff:im.word(0x2962a3c,im.word(0x2962a3c)+1)
 if v<9:im.word(at+0x34,0);im.word(at+0x38,0xffffffff);im.word(at+0x3c,0)
 else:
  for off in [0x34,0x38]:im.word(at+off,w(im))
  im.word(at+0x3c,f(im))
 if v<12:im.half(at+0x40,0);im.half(at+0x42,0);im.word(at+0x44,0)
 else:im.half(at+0x40,h(im));im.half(at+0x42,h(im));im.word(at+0x44,f(im))
 im.word(at+0x48,bits(0.9) if v<13 else f(im));im.half(at+0x4c,0 if v<15 else h(im))
 if v<27:
  value=20000
  if physical!=0xffffffff:value={2:40000,3:30000,7:10000}.get(im.byte(im.word(im.word(0x296209c)+physical*4)+0x2e),20000)
  im.half(at+0x4e,value);im.write(at+0x50,b'\0')
 else:im.half(at+0x4e,h(im));im.write(at+0x50,bytes([b(im)]))
 im.write(at+0x52,bytes([7 if v<36 else b(im)]))
 if v<38:im.write(at+0x53,b'\0');im.half(at+0x54,0);im.half(at+0x56,0)
 else:im.write(at+0x53,bytes([b(im)]));im.half(at+0x54,h(im));im.half(at+0x56,h(im))
def service(im,kind,arg):
 services.append([kind,arg]);rt['trace']=allocations;rt['case']={}
 if kind=='normalize':rt['R']=arg;rt['normalize'](Adapter(im))
 else:rt['select'](Adapter(im),env['f'](arg))
env['service']=service;env['instance']=instance
ls=Path(__file__).with_name('world-phase16-20261013-verify.py').read_text();ls=ls[ls.index('def load(m,c):'):ls.index('def seed(')]
ls=ls.replace("io['close_read'](m);service(m,'select',0x3f800000)","""if original in [1,2]:
  count=S(word(m));used=S(m.word(0x2962a2c))
  if used+count>512:count=512-used
  m.word(0x2962a3c,0);row=0
  for i in range(max(0,count)):
   while m.word(0x2924b60+row*0x58)!=0xffffffff:row+=1
   instance(m,0x2924b50+row*0x58,version,bank);m.word(0x2962a2c,m.word(0x2962a2c)+1)
 io['close_read'](m);service(m,'select',0x3f800000)""").replace("elif original==5:m.word(0x8109c8,bank)","""elif original==5:m.word(0x8109c8,bank)
 elif original==1:m.word(0x8109cc,bank)""")
exec(compile(ls,str(p),'exec'),env);load=env['load']
def prepare(c,used=0,occupied=None):
 c=dict(c);c['writes']=list(c['writes']);c['writes'] += [wp(SELECTED,-1),wp(0x29620a4,EMITTER),patch(ORIGIN,bytes(12)),wp(0x2962a2c,used),wp(0x2962a3c,0x12345678),wp(0x8109cc,0x87654321)]
 for i in range(512):c['writes'].append(wp(ROWS+i*0x58+16,99999 if occupied is not None and i in occupied else 0xffffffff))
 return c
for i,pv in enumerate(provenance):
 raw=(B/pv['path']).read_bytes();assert hashlib.sha256(raw).hexdigest()==pv['sha256'];original=next(c for c in base['cases'] if c.get('authored')==pv['path']);c=prepare(original);c['mode']=1+i%2;cases.append(c)
def wire(v,swap=0,names=None):
 names=names or [b'Present',b'Missing',b'PRESENT'];fmt='>' if swap else '<';data=bytearray(struct.pack(fmt+'III',v,0,len(names)))
 W=lambda x:data.extend(struct.pack(fmt+'I',x&0xffffffff));H=lambda x:data.extend(struct.pack(fmt+'H',x&65535));F=lambda x:W(bits(x));B=lambda x:data.append(x&255)
 for i,name in enumerate(names):
  F(-0.0 if i==0 else 1.25*i);F(-2.75);F(3.5)
  if v<7:W(0x12345678);W(0xabcdef01)
  else:
   for x in [0,65535,32768,0x7fff]:H(x)
  if v>=22:H(0x8001)
  if v>=34:F(0.3125)
  elif v>=8:W([-2147483648,2147483647,-31][i%3])
  data.extend(name.ljust(16,b'\0'))
  if v>=9:W(0x80000001);W(0xffffffff);F(-0.0)
  if v>=12:H(65535);H(32768);F(0.015625)
  if v>=13:F(1.125)
  if v>=15:H(0xfeed)
  if v>=27:H(40000);B(0xf3)
  if v>=36:B(0xd5)
  if v>=38:B(0x80);H(0xabcd);H(0x8123)
 return bytes(data)
for v in range(5,42):
 for swap in [0,1]:
  for mode in [1,2]:
   for typ in [0,2,3,7]:
    c=prepare(env['seed'](wire(v,swap),mode=mode,swap=swap));c['writes'] += [wp(env['PTR']+4,env['RECORDS']+1064),patch(env['RECORDS']+1064,b'Present\0'.ljust(16,b'\0')),patch(env['RECORDS']+1064+17,bytes([2])),patch(env['RECORDS']+1064+0x2e,bytes([typ]))];cases.append(c)
for used in [0,1,510,511,512]:
 for mode in [1,2]:
  for occupied in [set(range(used)),set(range(512-used,512)) if used else set()]:
   c=prepare(env['seed'](wire(41,names=[b'Unknown']*8),mode=mode),used,occupied);cases.append(c)
for count in [0,-1,-2147483648]:
 for used in [0,512]:
  c=prepare(env['seed'](struct.pack('<IIi',41,0,count),mode=1),used,set(range(used)));c['skipInvalidCount']=True;cases.append(c)
# Avoid malformed requests requiring wire rows not present: maxpositive count is only retained with used512.
cases=[c for c in cases if not(c.get('skipInvalidCount') and struct.unpack_from('<i',base64.b64decode(c['payload']),8)[0]==2147483647 and not any(p['address']==0x2962a2c and base64.b64decode(p['data'])==struct.pack('<I',512) for p in c['writes']))]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ESI,UC_X86_REG_EAX,UC_X86_REG_EIP
entries={}
def observe(uc,a,z,user):
 entries[hex(a)]=entries.get(hex(a),0)+1;sp=uc.reg_read(UC_X86_REG_ESP)
 if a==0x650e40:q=n.read(n.unpack('<I',sp+4)[0],16);env['audioCalls']+=1;env['audioHash'].update(struct.pack('<I',a)+q+struct.pack('<I',n.unpack('<I',sp+8)[0]))
 elif a==0x658490:q=n.read(n.unpack('<I',sp+4)[0],16);effects.append([base64.b64encode(q).decode(),n.unpack('<I',sp+8)[0]])
 elif a in [0x68cfd0,0x661f60]:services.append(['normalize' if a==0x68cfd0 else 'select',uc.reg_read(UC_X86_REG_ESI) if a==0x68cfd0 else n.unpack('<I',sp+4)[0]])
 elif a==0x683560:at=n.unpack('<I',sp+4)[0];allocations.append([at,n.unpack('<H',at+0x18c)[0],n.unpack('<H',at+0x18e)[0],n.unpack('<H',at+0x180)[0]]);uc.reg_write(UC_X86_REG_EAX,0);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x68df20,0x66a190,0x68cfd0,0x661f60,0x658490,0x650e40,0x683e90,0x683560,0x6e6b90,0x5b3800]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
rows=[];errors=[];checks=0;start=time.time()
for i,c in enumerate(cases):
 if i%40==0:print('progress',i,len(cases),flush=True)
 io['current']=c;im=env['Image'](c)
 for a,z in REGIONS:n.write(a,im.read(a,z))
 services=[];allocations=[];effects=[];env['audioHash']=hashlib.sha256();env['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 result=n.call(0x68df20,[io['PATH'],c['mode'],c['scene']],count=10000000)
 actual=dict(result=result,sha256=io['vm'].digest(),services=services.copy(),allocations=allocations.copy(),effects=effects.copy(),audioSha256=env['audioHash'].hexdigest(),audioCalls=env['audioCalls'],trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 services=[];allocations=[];effects=[];env['audioHash']=hashlib.sha256();env['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 result=load(im,c);predicted=dict(result=result,sha256=im.digest(),services=services.copy(),allocations=allocations.copy(),effects=effects.copy(),audioSha256=env['audioHash'].hexdigest(),audioCalls=env['audioCalls'],trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,authored=c.get('authored'),key=k,actual=actual[k],model=predicted[k]))
 if errors:
  for a,z in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  print(json.dumps(errors[:10]));break
 c['expected']=actual;rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:10],entryCounts=entries,authoredFiles=provenance,seconds=round(time.time()-start,3),binarySha256=n.sha256)
(B/'reports/world-phase18-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase18-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==D else 0) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps({k:v for k,v in report.items() if k!='authoredFiles'}));assert not errors
