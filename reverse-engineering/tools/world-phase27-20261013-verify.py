import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase25-20261013-verify.py');pool={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),pool)
p=Path(__file__).with_name('world-phase26-20261013-verify.py');unlink={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),unlink)
n=pool['n'];B=pool['B'];D=pool['D'];EM=pool['EM'];PTR=pool['PTR'];R=pool['R'];R2=pool['R2'];REF=D+0x800;REGIONS=pool['REGIONS'];REGIONS[:]=[(a,0x40 if a==0x2947b70 else z,f) for a,z,f in REGIONS];pool['rot']['REGIONS']=REGIONS;U=pool['U'];word=pool['word'];half=pool['half'];byte=pool['byte'];patch=pool['patch'];bits=pool['bits'];Image=pool['Image'];S16=pool['S16'];S=pool['S'];S8=pool['S8'];Base=0x29620a4;Packets=0x2961fec;ReturnTable=0x2923198;ReturnCount=0x2947b70
at=lambda base,id,field:U(base+id*0x330+field)
def cleanup(im,ref):
 route=im.W(Base);id=im.W(ref);physical=im.H(at(route,id,0x182))
 if not physical:return
 empty=im.H(at(route,id,0x180))==0;original=im.W(im.W(0x296209c)+S16(physical)*4)
 if empty:return
 assert im.W(0x2962058)==0;id=im.W(ref);route=im.W(Base);positive=S16(im.H(at(route,id,0x180)))>0;im.W(0x2962058,1)
 if positive:
  i=0
  while True:
   chunk=im.W(at(route,id,0x100+i*4));unlink['cancel'](im,chunk);id=im.W(ref);table=im.W(ReturnTable);count=im.W(ReturnCount);node=im.W(table+count*4);route=im.W(Base);im.W(node,im.W(at(route,id,0x100+i*4)))
   node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+8,9 if im.B(original+0x2e)==7 else 2);node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+12,0);cb=im.B(original+0x2f1)==4;node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+4,im.W(0x2962060 if cb else 0x296205c));node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);pool['links']['timed'](im,node,0x292fc00 if cb else 0x292fbfc);im.W(ReturnCount,im.W(ReturnCount)+1)
   id=im.W(ref);route=im.W(Base);current=S16(im.H(at(route,id,0x180)));i+=1
   if i>=current:break
 limit=pool['limit'](im);im.W(0x2962058,0)
 if limit>0:
  i=off=0
  while True:
   id=im.W(ref);emitter=at(route,id,0);packet=U(im.W(Packets)+off);first=im.W(packet)
   if first==im.W(emitter+0x100):
    if im.B(emitter+0x2f6):unlink['priority'](im,packet,U(0x292fd30+S8(im.B(original+0x2f1))*4))
    im.W(im.W(Packets)+off,0);im.W(im.W(Packets)+off+4,0);route=im.W(Base)
   i+=1;off+=0x64
   if i>=pool['limit'](im):break
 id=im.W(ref)
 if S16(im.H(at(route,id,0x180)))>0:
  i=0
  while True:
   im.W(at(route,id,0x100+i*4),0);id=im.W(ref);route=im.W(Base);count=S16(im.H(at(route,id,0x180)));i+=1
   if i>=count:break
 im.H(at(route,im.W(ref),0x186),0)
 for field in [0x180,0x18e,0x18c,0x188,0x18a]:id=im.W(ref);route=im.W(Base);im.H(at(route,id,field),0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x6553f0,0x655250]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(cur=2,typ=0):
 c=pool['seed'](max(0,cur),1,typ);c.update(idPointer=REF);c['writes'] += [word(REF,0),word(Base,EM),half(EM+0x180,cur),half(EM+0x330+0x180,0),half(EM+0x330+0x182,2),word(EM+0x330+0x100,0),byte(EM+0x330+0x2f6,0)]
 for i in range(64):c['writes'] += [word(pool['PACKETS']+i*0x64+0x58,0),word(pool['PACKETS']+i*0x64+0x5c,0)]
 return c
cases=[]
for typ in [0,2,3,7,255]:
 for count in [-32768,-1,0,1,2,7,31,32]:
  for flag in [0,1]:
   c=seed(count,typ);c['writes'].append(byte(EM+0x2f6,flag));cases.append(c)
for typ in range(256):cases.append(seed(2,typ))
for bank in range(256):c=seed(2,7);c['writes'].append(byte(R+0x2f1,bank));cases.append(c)
for count in [1,2,7]:
 for pattern in ['none','first','all','both']:
  for bank in [0,4]:
   c=seed(count);c['writes'].append(byte(R+0x2f1,bank));mask=[] if pattern=='none' else [0] if pattern=='first' else list(range(count));existing=mask+mask if pattern=='both' else mask
   c['writes'].append(word(ReturnCount,len(existing)))
   for i,slot in enumerate(existing):c['writes'] += [word(pool['RETURNS']+i*0x20,D+0x40000+(slot+4)*0x500),word(pool['RETURNS']+i*0x20+0x10,pool['RETURNS']+(i+1)*0x20 if i+1<len(existing) else 0)]
   c['writes'].append(word(0x292fbfc,pool['RETURNS'] if existing else 0));cases.append(c)
for id in [-2,-1,0,1,31]:
 c=seed();c['writes'] += [word(REF,id),word(Base,U(EM-id*0x330))];cases.append(c)
for physical in [-32768,-2,-1,0,1,32767]:
 c=seed();c['writes'] += [half(EM+0x182,physical),word(0x296209c,U(PTR-physical*4)),word(PTR,R)];cases.append(c)
for limit in [-2,-1,0,1,2,32]:
 c=seed();c['writes'] += [word(0x8108e8,limit),word(0x8108ec,0)];cases.append(c)
for clock in [0,0x80000000,1,0x80000001,bits(-3.75),bits(10),0x7f800000,0xff800000,0x7fc12345,0xffc12345]:
 for bank in [0,4]:
  c=seed(2);c['writes'] += [word(0x296205c,clock),word(0x2962060,clock),byte(R+0x2f1,bank),word(0x292fbfc,pool['RETURNS']+0x40),word(0x292fc00,pool['RETURNS']+0x40)];cases.append(c)
# ID reference aliases the lock or queue count; original cached first route differs from later rereads.
c=seed(1);c['idPointer']=0x2962058;cases.append(c)
c=seed(1);c['idPointer']=ReturnCount;cases.append(c)
# A matched packet clear aliases reference storage; high ID multiplication wraps to the same emitter.
c=seed(-1);c['idPointer']=ReturnCount;c['writes'] += [word(ReturnCount,0x80000000),word(EM+0x100,0x80000000),word(Packets,ReturnCount),word(0x8108e8,1),word(0x8108ec,0),byte(EM+0x2f6,0)];cases.append(c)
# Packet clear changes the live scan limit rather than continuing with initial capacity.
c=seed(1);c['writes'] += [word(EM+0x100,32),word(Packets,0x8108e8),byte(EM+0x2f6,0)];cases.append(c)
# Queued header write mutates fields of the cached original physical record before tag/clock reads.
c=seed(1,7);c['writes'].append(word(pool['RETURN'],R+0x2e));cases.append(c)
c=seed(2,7);c['writes'] += [byte(R+0x2f1,4),word(pool['RETURN'],R+0x2f1-4)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);cleanup(im,c['idPointer']);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x6553f0,[c['idPointer']],count=2000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase27-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase27-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
