import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase27-20261013-verify.py');env={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),env)
n=env['n'];B=env['B'];D=env['D'];EM=env['EM'];R=env['R'];R2=env['R2'];pool=env['pool'];unlink=env['unlink'];Image=env['Image'];REGIONS=env['REGIONS'];U=env['U'];word=env['word'];half=env['half'];byte=env['byte'];patch=env['patch'];bits=env['bits'];S8=env['S8'];Packets=0x2961fec;ReturnTable=0x2923198;ReturnCount=0x2947b70
REGIONS[:]=[(0x810800,0x200,f) if a==0x8108e8 else (a,z,f) for a,z,f in REGIONS]
limit=pool['limit']
def cleanup(im,physical):
 assert im.W(0x2962058)==0;lim=limit(im);im.W(0x2962058,1)
 if lim>0:
  route=im.W(Packets);off=i=0
  while True:
   packet=U(route+off)
   if not im.W(packet+8) and im.W(packet+4)==physical:
    chunk=im.W(packet);unlink['cancel'](im,chunk);node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node,im.W(im.W(Packets)+off));node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+8,9 if im.B(physical+0x2e)==7 else 2);node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+12,0)
    cb=im.B(physical+0x2f1)==4;node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);im.W(node+4,im.W(0x2962060 if cb else 0x296205c));node=im.W(im.W(ReturnTable)+im.W(ReturnCount)*4);pool['links']['timed'](im,node,0x292fc00 if cb else 0x292fbfc);im.W(ReturnCount,im.W(ReturnCount)+1)
    bank=S8(im.B(physical+0x2f1));packet=U(im.W(Packets)+off);unlink['priority'](im,packet,U(0x292fd30+bank*4));im.W(im.W(Packets)+off,0);im.W(im.W(Packets)+off+4,0);route=im.W(Packets)
   i+=1;off+=0x64
   if i>=limit(im):break
 im.W(0x2962058,0)
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x655730,0x655250]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(typ=0,profile='one'):
 c=env['seed'](0,typ);c.update(physical=R);p=pool['PACKETS']
 for i in range(64):c['writes'] += [word(p+i*0x64,0),word(p+i*0x64+4,0),word(p+i*0x64+8,0),word(p+i*0x64+0x58,0),word(p+i*0x64+0x5c,0)]
 if profile=='one':c['writes'] += [word(p,D+0x41400),word(p+4,R)]
 elif profile=='owned':c['writes'] += [word(p,D+0x41400),word(p+4,R),word(p+8,EM)]
 elif profile=='mismatch':c['writes'] += [word(p,D+0x41400),word(p+4,R2)]
 elif profile=='zerochunk':c['writes'].append(word(p+4,R))
 elif profile=='many':
  for i in [0,1,7,31,63]:c['writes'] += [word(p+i*0x64,D+0x41400+i*0x500),word(p+i*0x64+4,R)]
 return c
cases=[]
for typ in range(256):cases.append(seed(typ))
for bank in range(256):c=seed(7);c['writes'].append(byte(R+0x2f1,bank));cases.append(c)
for profile in ['one','owned','mismatch','zerochunk','many','none']:
 for capacity in [-2,-1,0,1,2,32]:
  c=seed(0,profile);c['writes'] += [word(0x8108e8,capacity),word(0x8108ec,0)];cases.append(c)
for profile in ['one','zerochunk','many']:
 for pattern in ['none','same','both','other']:
  c=seed(7,profile);key=0 if profile=='zerochunk' else D+0x41400;pending=0 if pattern=='none' else 2 if pattern=='both' else 1;c['writes'].append(word(ReturnCount,pending))
  for i in range(pending):c['writes'] += [word(pool['RETURNS']+i*0x20,key if pattern!='other' else key+1),word(pool['RETURNS']+i*0x20+0x10,pool['RETURNS']+(i+1)*0x20 if i+1<pending else 0)]
  c['writes'].append(word(0x292fbfc,pool['RETURNS'] if pending else 0));cases.append(c)
for clock in [0,0x80000000,1,0x80000001,bits(-3.75),bits(10),0x7f800000,0xff800000,0x7fc12345,0xffc12345]:
 for bank in [0,4]:
  c=seed();c['writes'] += [word(0x296205c,clock),word(0x2962060,clock),byte(R+0x2f1,bank),word(0x292fbfc,pool['RETURNS']+0x40),word(0x292fc00,pool['RETURNS']+0x40)];cases.append(c)
c=seed(7);c['writes'].append(word(pool['RETURN'],R+0x2e));cases.append(c)
c=seed(7);c['writes'] += [byte(R+0x2f1,4),word(pool['RETURN'],R+0x2f1-4)];cases.append(c)
# Cancellation free-table store retargets packet base to a returned node; later packet/queue fields use that base.
c=seed();c['writes'] += [word(ReturnCount,1),word(0x292fbfc,pool['RETURNS']),word(pool['RETURNS'],D+0x41400),word(pool['RETURNS']+0x10,0),word(ReturnTable,Packets),word(pool['RETURNS']+0x58,0),word(pool['RETURNS']+0x5c,0)];cases.append(c)
# Clearing a matched packet changes the live capacity sum and ends the scan.
c=seed();base=0x8108e8-4;c['writes'] += [word(Packets,base),word(base,1234),word(base+4,R),word(base+8,0),word(base+0x58,0),word(base+0x5c,0),word(0x8108ec,0)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c);cleanup(im,c['physical']);initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(0x655730,[c['physical']],count=2000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase29-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase29-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
