import json,hashlib,struct,base64,gzip,time
from pathlib import Path
p=Path(__file__).with_name('world-phase27-20261013-verify.py');env={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),env)
n=env['n'];B=env['B'];D=env['D'];EM=env['EM'];PTR=env['PTR'];R=env['R'];pool=env['pool'];REGIONS=env['REGIONS'];U=env['U'];word=env['word'];half=env['half'];byte=env['byte'];patch=env['patch'];REF=D+0x800;SCRATCH=0x10600000
class Image(env['Image']):
 def __init__(self,c):super().__init__(c);self.regions[SCRATCH]=bytearray(4)
def emitter(im,reference,state):
 id=im.W(reference)
 if id!=0xffffffff:im.B(U(im.W(0x29620a4)+id*0x330+0x2f4),state)
def physical(im,id,state):
 if id!=0xffffffff:im.B(U(im.W(U(im.W(0x296209c)+id*4))+0x2f),state)
def cleanupall(im):
 i=0
 while i<env['S'](im.W(0x2962094)):
  e=U(im.W(0x29620a4)+i*0x330)
  if im.H(e+0x182):im.W(SCRATCH,i);env['cleanup'](im,SCRATCH)
  i+=1
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x6552c0,0x6552e0,0x655300,0x655320,0x655340,0x655360,0x6558f0,0x6553f0,0x655250]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
cases=[]
for kind in ['emitter','physical']:
 for state in [0,2,1]:
  for id in [0xffffffff,0xfffffffe,0xffff8000,0,1,31,0x7fffffff,0x80000000]:
   c=env['seed'](0);c.update(kind=kind,state=state,id=id,reference=REF);c['writes'] += [word(REF,id),word(0x29620a4,U(EM-id*0x330)),word(0x296209c,U(PTR-id*4)),word(PTR,R)];cases.append(c)
  if kind=='emitter':
   for id in [0,1,31]:
    c=env['seed'](0);c.update(kind=kind,state=state,id=id,reference=REF);c['writes'] += [word(REF,id),word(0x29620a4,U(REF-id*0x330-0x2f4))];cases.append(c)
    c=env['seed'](0);c.update(kind=kind,state=state,id=id,reference=REF);c['writes'] += [word(REF,id),word(0x29620a4,U(0x29620a4-id*0x330-0x2f4))];cases.append(c)
  else:
   c=env['seed'](0);c.update(kind=kind,state=state,id=1,reference=REF);c['writes'] += [word(0x296209c,PTR),word(PTR+4,0x296209c-0x2f)];cases.append(c)
for cap in [-2147483648,-1,0,1,2,7,16,32]:
 for profile in ['none','all','even','last']:
  for typ in [0,7]:
   c=env['seed'](0,typ);c.update(kind='all',state=0,id=0,reference=REF);c['writes'].append(word(0x2962094,cap))
   for i in range(max(0,cap)):
    e=EM+i*0x330;active=profile=='all' or profile=='even' and not i%2 or profile=='last' and i+1==cap
    c['writes'] += [half(e+0x182,1 if active else 0),half(e+0x180,1 if active else 0),word(e+0x100,D+0x70000+i*0x100),byte(e+0x2f6,0)]
   cases.append(c)
# Child packet clear updates bulk capacity; second emitter remains untouched.
c=env['seed'](1);c.update(kind='all',state=0,id=0,reference=REF);base=0x2962094-4;c['writes'] += [word(0x2962094,2),word(0x2961fec,base),word(base,D+0x41400),half(EM+0x330+0x182,1),half(EM+0x330+0x180,1),word(EM+0x330+0x100,D+0x41900),byte(EM+0x2f6,0),word(0x8108e8,1),word(0x8108ec,0)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 if c['kind']=='emitter':emitter(im,c['reference'],c['state'])
 elif c['kind']=='physical':physical(im,c['id'],c['state'])
 else:cleanupall(im)
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 address={0:0x6552c0,2:0x6552e0,1:0x655300}[c['state']] if c['kind']=='emitter' else {0:0x655320,2:0x655340,1:0x655360}[c['state']] if c['kind']=='physical' else 0x6558f0
 n.call(address,[] if c['kind']=='all' else [c['reference']] if c['kind']=='emitter' else [c['id']],count=5000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),newOwnBodies=5,existingPhysical0And2RefinementWithoutDuplicateCredit=True)
(B/'reports/world-phase30-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase30-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],temporaryId=SCRATCH,cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
