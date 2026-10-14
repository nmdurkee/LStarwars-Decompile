import json,hashlib,struct,base64,gzip,time,os
from pathlib import Path
p=Path(__file__).with_name('world-phase25-20261013-verify.py');pool={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),pool)
p=Path(__file__).with_name('world-phase17-20261013-verify.py');rt={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('n.mu.hook_add')],str(p),'exec'),rt)
n=pool['n'];B=pool['B'];D=pool['D'];EM=pool['EM'];R=pool['R'];R2=pool['R2'];PTR=pool['PTR'];ROWS=rt['ROWS'];REGIONS=pool['REGIONS'];REGIONS[:]=[x for x in REGIONS if x[0]!=0x292fa00];REGIONS.append((ROWS,0x292fa00+0x600-ROWS,0));pool['rot']['REGIONS']=REGIONS;rt['R']=R;rt['allocate']=pool['transfer']
class Image(pool['Image']):
 def F(self,a):return pool['F'](self.W(a))
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI
entries={}
def observe(uc,a,z,user):
 if a in [0x683e90,0x68cfd0,0x6e6b90]:entries[hex(a)]=entries.get(hex(a),0)+1
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(kind='setcount',typ=0,current=0):
 c=pool['seed'](current,1,typ);c.update(kind=kind,count=17)
 c['writes'] += [pool['word'](0x8108e8,33),pool['word'](0x8108ec,33),pool['word'](0x29620a4,EM),pool['half'](EM+0x330+0x182,2)]
 for i in range(-133,0):c['writes'].append(pool['word'](EM+0x100+i*4,D+0x68000+(i+133)*0x100))
 for i in range(128,140):c['writes'] += [pool['word'](pool['RETURN']+i*4,pool['RETURNS']+i*0x20),pool['word'](pool['RETURNS']+i*0x20+4,pool['bits'](i*0.5)),pool['word'](pool['RETURNS']+i*0x20+0x10,0)]
 for i in range(512):c['writes'].append(pool['word'](ROWS+i*0x58+16,-1))
 return c
cases=[]
for typ in [0,7,255]:
 for current in [0,1,2]:
  for count in [-2147483648,-4096,-1024,-64,-33,-32,-12,-1,0,1,12,13,17,32,33,383,384,385,1023,1024,1025,4096,32767,32768,65535,65536,2147483647]:
   c=seed(typ=typ,current=current);c['count']=count;cases.append(c)
for typ in range(256):c=seed(typ=typ);cases.append(c)
for typ in [0,7]:
 for lifetime in [0,0.125,1,4]:
  for rate in [0,1,17,64]:
   for frames in [0,1,127,128,255]:
    for profile in ['none','one','duplicate','mismatch']:
     c=seed('normalize',typ);c['writes'] += [pool['word'](R+0xa4,pool['bits'](lifetime)),pool['word'](R+0x1c,pool['bits'](0.25)),pool['word'](R+0x20,0),pool['word'](R+0x24,pool['bits'](0.125)),pool['half'](R+0x16,rate),pool['byte'](R+0x410,frames)]
     if profile!='none':c['writes'].append(pool['word'](ROWS+16,0))
     if profile=='duplicate':c['writes'].append(pool['word'](ROWS+511*0x58+16,0))
     if profile=='mismatch':c['writes'].append(pool['word'](ROWS+511*0x58+16,1))
     cases.append(c)
for frames in range(256):
 c=seed('normalize',7);c['writes'] += [pool['word'](R+0xa4,0),pool['word'](R+0x1c,pool['bits'](0.25)),pool['word'](R+0x20,0),pool['word'](R+0x24,pool['bits'](0.125)),pool['half'](R+0x16,17),pool['byte'](R+0x410,frames),pool['word'](ROWS+16,0)];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 if i%100==0:(B/'reports/world-phase25-20261013-composed-progress.json').write_text(json.dumps(dict(status='unsealed running',pid=os.getpid(),case=i,total=len(cases),seconds=round(time.time()-start,2)))+'\n')
 im=Image(c)
 if c['kind']=='setcount':rt['setcount'](im,EM,c['count'])
 else:rt['normalize'](im)
 initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 if c['kind']=='setcount':n.call(0x683e90,[EM,pool['U'](c['count'])],count=10000000)
 else:n.call(0x68cfd0,regs={UC_X86_REG_ESI:R},count=10000000)
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash():
  errors.append(dict(case=i,kind=c['kind'],actual=actual,model=im.hash()))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows),mismatches=len(errors),errors=errors[:10],callerEntries=entries,poolEntries=pool['entries'],binarySha256=n.sha256,nativeAdapters=0,seconds=round(time.time()-start,3))
(B/'reports/world-phase25-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase25-20261013-composed-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
