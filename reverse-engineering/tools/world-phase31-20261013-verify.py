import json,hashlib,struct,base64,gzip,random,time
from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');rot={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('cases=[];rng=')],str(p),'exec'),rot)
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;SRC=D+0x2000;ALT=D+0x14000;GLOBAL=0x29620a4
REGIONS=[(D,0x20000,167),(0x2961800,0x1800,167)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];Image=rot['Image'];consumed=[]
SN=lambda w:(w&0x7f800000)==0x7f800000 and (w&0x7fffff)!=0 and not(w&0x400000)
def transform(im,c):
 if c['id']==0xffffffff:return
 off=U(c['id']*0x330);at=lambda f:U(im.W(GLOBAL)+off+f)
 if c['kind'].startswith('vector'):
  field=0x1b4 if c['kind']=='vector1b4' else 0x1a8
  for i,w in enumerate(c['xyz']):consumed.append(w);im.W(at(field+i*4),w)
 else:
  field=0x80 if c['kind']=='secondary' else 0x40;dest=at(field)
  for i in range(0,64,4):im.W(dest+i,im.W(c['source']+i))
  if c['kind']=='position':
   for i in range(3):w=im.W(c['source']+0x30+i*4);consumed.append(w);im.W(at(0x190+i*4),w)
  for f in [field+0x30,field+0x34,field+0x38,0x300]:im.W(at(f),0)
from unicorn import UC_HOOK_CODE
entries={}
addresses=dict(vector1b4=0x6559a0,vector1a8=0x6559f0,position=0x655a40,primary=0x655ad0,secondary=0x655b30)
def observe(uc,a,z,user):
 if a in addresses.values():entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind):return dict(kind=kind,id=1,source=SRC,xyz=[bits(1),bits(-0.0),bits(0.125)],writes=[word(GLOBAL,EM),patch(SRC,struct.pack('<16I',*[bits(i/8) for i in range(16)]))])
cases=[]
words=[(sign<<31)|(exp<<23)|frac for sign in [0,1] for exp in range(256) for frac in [0,1,0x3fffff,0x400000,0x7fffff] if exp!=255 or frac==0 or frac&0x400000]
for kind in ['vector1b4','vector1a8']:
 for i in range(0,len(words),3):c=seed(kind);c['xyz']=(words[i:i+3]+[0,0])[:3];cases.append(c)
for kind in addresses:
 for id in [0xffffffff,0xfffffffe,0xffff8000,0,1,31,0x7fffffff,0x80000000]:c=seed(kind);c['id']=id;c['writes'].append(word(GLOBAL,U(EM-id*0x330)));cases.append(c)
raw=[(sign<<31)|(exp<<23)|frac for sign in [0,1] for exp in range(256) for frac in [0,1,0x3fffff,0x400000,0x7fffff]]
for kind in ['primary','secondary','position']:
 for i in range(0,len(raw),16):
  c=seed(kind);chunk=raw[i:i+16];chunk+=[0]*(16-len(chunk))
  if kind=='position':chunk[12:15]=[bits(1),bits(-0.0),bits(0.125)]
  c['writes'].append(patch(SRC,struct.pack('<16I',*chunk)));cases.append(c)
rng=random.Random(2026101331)
for kind in ['primary','secondary','position']:
 field=0x80 if kind=='secondary' else 0x40
 for shift in [-20,-12,-8,-4,-3,-2,-1,0,1,2,3,4,8,12,20]:
  c=seed(kind);c['writes'] += [word(GLOBAL,U(SRC+shift-field-0x330)),patch(SRC-24,bytes(rng.randrange(256) for _ in range(128)))];cases.append(c)
 for shift in [-8,-4,0,4,8]:
  c=seed(kind);c['source']=EM+0x330+field+shift;c['writes'].append(patch(c['source'],struct.pack('<16I',*[rng.randrange(1<<32) for _ in range(16)])));cases.append(c)
 c=seed(kind);c['id']=0;c['writes'] += [word(GLOBAL,GLOBAL-field),word(SRC,ALT)];cases.append(c)
for kind,field in [('vector1b4',0x1b4),('vector1a8',0x1a8)]:
 c=seed(kind);c['id']=0;c['xyz'][0]=ALT;c['writes'].append(word(GLOBAL,GLOBAL-field));cases.append(c)
rows=[];excluded=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 consumed=[];im=Image(c);transform(im,c)
 if any(SN(w) for w in consumed):excluded.append(dict(case=i,kind=c['kind'],reason='consumed signaling NaN after actual forward overlap propagation'));continue
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 n.call(addresses[c['kind']],[c['id']]+c['xyz'] if c['kind'].startswith('vector') else [c['id'],c['source']])
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],entries=entries,binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3),syntheticExcluded=len(excluded),excluded=excluded)
(B/'reports/world-phase31-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase31-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
