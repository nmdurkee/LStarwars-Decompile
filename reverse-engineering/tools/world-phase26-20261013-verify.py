import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase24-20261013-verify.py');base={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),base)
n=base['rot']['Native']();B=base['B'];D=n.DATA;HEAD=D+0x800;NEW=D+0x3000;NODES=D+0x4000;FIFO=D+0x2000
REGIONS=[(D,0x20000,167),(0x292fbfc,8,0),(0x2947b00,0x200,0),(0x2923180,0x80,0)];base['rot']['REGIONS']=REGIONS;base['rot']['common']=[];U=base['U'];patch=base['patch'];word=base['word'];Image=base['Image']
def priority(im,node,head):
 if im.W(head)==node:
  next=im.W(node+0x5c);im.W(head,next)
  if next:im.W(next+0x58,0)
 else:
  prev=im.W(node+0x58)
  if prev:
   next=im.W(node+0x5c);im.W(prev+0x5c,next);next=im.W(node+0x5c)
   if next:im.W(next+0x58,im.W(node+0x58))
 im.W(node+0x58,0);im.W(node+0x5c,0)
def timed(im,node,head):
 cursor=head
 if im.W(cursor):
  while True:
   current=im.W(cursor)
   if current==node:im.W(cursor,im.W(node+0x10));break
   cursor=current+0x10
   if not im.W(cursor):break
 im.W(node+0x10,0)
def cancel(im,chunk):
 for head in [0x292fbfc,0x292fc00]:
  cur=im.W(head)
  while cur:
   match=im.W(cur)==chunk;next=im.W(cur+0x10)
   if match:
    timed(im,cur,head);count=im.W(0x2947b70);table=im.W(0x2923198);count=U(count-1);im.W(0x2947b70,count);im.W(U(table+count*4),cur);im.W(cur,0)
   cur=next
from unicorn import UC_HOOK_CODE
entries={}
def observe(uc,a,z,user):
 if a in [0x654ea0,0x655210,0x655250]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind='priority',count=3):
 c=dict(kind=kind,node=NEW,head=HEAD,chunk=0x12345678,writes=[word(HEAD,NODES if count else 0),word(NEW+0x58,0),word(NEW+0x5c,NODES),word(NEW+0x10,NODES)])
 for i in range(64):
  at=NODES+i*0x80;c['writes'] += [word(at+0x58,NODES+(i-1)*0x80 if i and i<count else 0),word(at+0x5c,NODES+(i+1)*0x80 if i+1<count else 0),word(at+0x10,NODES+(i+1)*0x80 if i+1<count else 0),word(at,0x12345678)]
 return c
cases=[]
for kind in ['priority','timed']:
 for count in [0,1,2,3,7,31]:
  for index in [-1,0,max(0,count-1),count//2,count,count+1]:
   c=seed(kind,count);c['node']=NEW if index==-1 else NODES+index*0x80;cases.append(c)
for kind,field in [('priority',0x58),('priority',0x5c),('timed',0x10)]:
 for value in [0,NEW,NODES]:
  c=seed(kind);c['head']=NEW+field;c['writes'].append(word(NEW+field,value));cases.append(c)
c=seed();c['writes'] += [word(NEW+0x58,NEW-4),word(NEW+0x5c,NODES)];cases.append(c)
c=seed();c['writes'] += [word(HEAD,NEW),word(NEW+0x58,NEW),word(NEW+0x5c,NEW)];cases.append(c)
c=seed('timed');c['writes'] += [word(HEAD,NEW),word(NEW+0x10,NEW)];cases.append(c)
rng=random.Random(2026101326)
for kind in ['priority','timed']:
 for i in range(192):
  count=rng.randrange(32);c=seed(kind,count);c['node']=NODES+rng.randrange(count+2)*0x80;cases.append(c)
def queue(a,b,mask,key=0x12345678):
 c=seed('cancel',0);c['chunk']=key;c['writes'] += [word(0x292fbfc,NODES if a else 0),word(0x292fc00,NODES+a*0x80 if b else 0),word(0x2947b70,a+b),word(0x2923198,FIFO)]
 for i in range(a+b):
  at=NODES+i*0x80;stop=(i+1==a or i+1==a+b);c['writes'] += [word(at,key if i in mask else key^0xffffffff),word(at+0x10,0 if stop else at+0x80)]
 return c
for a in [0,1,2,7,31]:
 for b in [0,1,2,7,31]:
  for pattern in ['none','all','first','last','alternating']:
   count=a+b;mask=[] if pattern=='none' else list(range(count)) if pattern=='all' else [0] if pattern=='first' else [count-1] if pattern=='last' else list(range(0,count,2));cases.append(queue(a,b,mask))
for i in range(192):
 a=rng.randrange(32);b=rng.randrange(32);key=rng.randrange(1<<32);cases.append(queue(a,b,[j for j in range(a+b) if rng.randrange(2)],key))
for key in [0,1,0xffffffff]:
 c=queue(1,0,[0],key);c['writes'] += [word(0x292fc00,NODES),word(0x2947b70,1)];cases.append(c)
c=queue(1,0,[0],0);c['writes'] += [word(NODES+0x10,NODES),word(0x2947b70,0)];cases.append(c)
# Final tag clear aliases count/table globals; table capture before decrement remains observable.
c=queue(0,0,[]);c['chunk']=2;c['writes'] += [word(0x292fbfc,0x2947b70),word(0x2947b70,2),word(0x2947b80,0)];cases.append(c)
c=queue(0,0,[]);c['chunk']=FIFO;c['writes'] += [word(0x292fbfc,0x2923198),word(0x2923198,FIFO),word(0x29231a8,0),word(0x2947b70,1)];cases.append(c)
# A free-array store changes the next candidate tag after its pointer was captured.
c=queue(2,0,[0],NODES);c['writes'] += [word(0x2923198,NODES+0x80-4),word(NODES+0x80,7)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 im=Image(c)
 if c['kind']=='priority':priority(im,c['node'],c['head'])
 elif c['kind']=='timed':timed(im,c['node'],c['head'])
 else:cancel(im,c['chunk'])
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(dict(priority=0x654ea0,timed=0x655210,cancel=0x655250)[c['kind']],[c['chunk']] if c['kind']=='cancel' else [c['node'],c['head']])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase26-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase26-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
