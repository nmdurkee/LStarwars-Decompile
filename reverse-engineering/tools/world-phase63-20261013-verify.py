import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;OUT=D+0x2000;P=D+0x1000;REGIONS=[(D,0x10000,167),(0x2961f00,0x400,0),(0x8108e4,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];word=rot['word'];patch=rot['patch'];Image=rot['Image'];trace=[];case={}
def half(a,v):return patch(a,struct.pack('<H',v&65535))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
R=D+0x4000;TABLE=D+0x2000
class NI:
 def write(self,a,v):n.write(a,v)
def spill(w):return w|0x400000 if w&0x7f800000==0x7f800000 and w&0x7fffff else w
def S(w):return struct.unpack('<i',struct.pack('<I',U(w)))[0]
def service(im,a,args):
 trace.append([a,args])
 for x in case.get('serviceWrites',[]):im.write(x['address'],base64.b64decode(x['data']))
 return 0xdeadbeef
def apply(im,c):
 args=c['args']
 if c['entry']==0x656e40:im.W(0x29620b4,args[0]);return
 physical=S(args[0])
 if physical<0:return
 record=im.W(U(im.W(0x296209c)+physical*4))
 if not record:return
 type=im.read(record+0x2e,1)[0];priority={2:40000,3:30000,7:10000}.get(type,20000)
 if c['entry']==0x656d40:count=args[3];duration=spill(args[4]);secondary=args[5];primary=args[6]
 else:count=U(args[3]*30);duration=spill(im.W(0x8108e4));secondary=args[4];primary=args[5]
 service(im,0x6561d0,[args[0],args[1],args[2],0,count,duration,secondary,primary,priority,0])
entries={}
def observe(uc,a,z,user):
 if a in [0x656d40,0x656dc0,0x656e40]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a!=0x6561d0:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];args=list(n.unpack('<10I',sp+4));value=service(NI(),a,args);uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(entry=0x656d40,type=0,duration=0x3f800000,count=4):return dict(entry=entry,args=[1,0x12345678,0x87654321,U(count),duration,0xabcdef01,0x76543210] if entry==0x656d40 else [1,0x12345678,0x87654321,U(count),0xabcdef01,0x76543210],writes=[word(0x296209c,TABLE),word(TABLE+4,R),patch(R+0x2e,bytes([type])),word(0x8108e4,duration)])
choices=[0,0x80000000,0x3f800000,0x7f800000,0xff800000,0x7f800001,0xff800001,0x7fc12345]
cases=[seed(entry,type,choices[type%8]) for entry in [0x656d40,0x656dc0] for type in range(256)]
for entry in [0x656d40,0x656dc0]:
 for duration in choices+[1,0x80000001,0x7fffffff,0xffffffff]:
  for count in [-2147483648,-1,0,1,2,71582788,71582789,2147483647]:cases.append(seed(entry,7,duration,count))
 for id in [0,1,0x7fffffff,0x80000000,0xffffffff]:
  c=seed(entry);c['args'][0]=id;c['writes'] += [word(0x296209c,U(TABLE-U(id*4))),word(TABLE,R)];cases.append(c)
 c=seed(entry);c['writes'].append(word(TABLE+4,0));cases.append(c)
rng=random.Random(2026101363)
for i in range(256):
 c=seed(rng.choice([0x656d40,0x656dc0]),rng.randrange(256),rng.getrandbits(32),rng.getrandbits(32));c['serviceWrites']=[word(0x8108e4,rng.getrandbits(32)),word(R+0x2c,rng.getrandbits(32))];cases.append(c)
for value in [0,1,0xffffffff,0x7f800001]+[rng.getrandbits(32) for i in range(256)]:c=seed();c.update(entry=0x656e40,args=[value]);cases.append(c)
for entry in [0x656d40,0x656dc0]:
 for type in range(256):cases.append(seed(entry,type,0x3f800000))
rows=[];errors=[];excluded=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 if c["entry"]!=0x656e40 and S(c["args"][0])>=0 and im.W(U(im.W(0x296209c)+c["args"][0]*4)):
  duration=c["args"][4] if c["entry"]==0x656d40 else im.W(0x8108e4)
  if duration&0x7f800000==0x7f800000 and duration&0x7fffff and not duration&0x400000:excluded.append(dict(case=i,reason="consumed signaling NaN duration: Unicorn load/store preserves signaling payload; x87 masked-invalid quieting not qualified"));continue
 apply(im,c);modelTrace=trace[:];trace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(c['entry'],c['args']);actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or trace!=modelTrace:errors.append(dict(case=i,native=actual,model=im.hash(),nativeTrace=trace,modelTrace=modelTrace));break
 c['expected']=dict(sha256=actual,trace=trace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=sum(1 if c['entry']==0x656e40 else 2 for c in rows),mismatches=len(errors),errors=errors,entries=entries,binarySha256=n.sha256,nativeAdapters=['0x6561d0 mutable burst child'],seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase63-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase63-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
