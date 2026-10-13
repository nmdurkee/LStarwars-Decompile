import json,hashlib,struct,base64,time
from pathlib import Path
p=Path(__file__).with_name('world-phase16-20261013-verify.py');env={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('from unicorn import UC_HOOK_CODE')],str(p),'exec'),env)
rp=Path(__file__).with_name('world-phase17-20261013-verify.py');rt={'__file__':str(rp)};rs=rp.read_text();exec(compile(rs[:rs.index('n.mu.hook_add')],str(rp),'exec'),rt)
n=env['n'];B=env['B'];D=env['D'];io=env['io'];REGIONS=env['REGIONS'];ROWS=rt['ROWS'];ORIGIN=rt['ORIGIN'];SELECTED=rt['SELECTED'];EMITTER=D+0xe0000
REGIONS.extend([(ROWS,0xb010),(ORIGIN,12),(SELECTED,4),(0x29620a4,4)]);io['REGIONS']=REGIONS
base=json.loads((B/'reports/world-phase16-20261013-vectors.json').read_text());cases=[];excluded=[];originalservice=env['service'];oldload=env['load'];audio=env['audio'];assets={};ap=Path(__file__).with_name('world-phase15-20261013-verify.py');assets['__file__']=str(ap);asc=ap.read_text();exec(compile(asc[:asc.index('rng=random.Random')],str(ap),'exec'),assets)
def loaded_audio(m,q):
 env['audioCalls']+=1;env['audioHash'].update(struct.pack('<I',0x650e40)+q+struct.pack('<I',16));return assets['sound'](m,q,16)
env['audio']=loaded_audio
class Adapter:
 def __init__(self,image):self.m=image
 def W(self,a,v=None):return self.m.word(a) if v is None else self.m.word(a,v)
 def H(self,a,v=None):return self.m.half(a) if v is None else self.m.half(a,v)
 def B(self,a):return self.m.byte(a)
 def F(self,a):return env['f'](self.m.word(a))
for i,c in enumerate(base['cases']):
 io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;env['audioHash']=hashlib.sha256();env['audioCalls']=0;env['services']=[];im=env['Image'](c);oldload(im,c);bad=[]
 for kind,r in env['services']:
  if kind!='normalize':continue
  a=Adapter(im);L=a.F(r+0xa4);cycle=a.F(r+0x1c)+a.F(r+0x20);gap=a.F(r+0x24)
  if L>0 and (cycle<=0 or gap<0 or L/(cycle+gap)>9000):bad.append(dict(record=hex(r),lifetime=L,cycle=cycle,gap=gap))
 if bad:excluded.append(dict(case=i,authored=c.get('authored'),reason='nonpositive cycle, negative gap or more than9000 estimated cycle steps outside bounded projection',records=bad));continue
 c=dict(c);c['sourceCase']=i;c['writes']=list(c['writes']);c['writes'] += [env['wp'](SELECTED,0xffffffff),env['wp'](0x29620a4,EMITTER),env['patch'](ORIGIN,struct.pack('<3f',0,0,0))]
 for slot in range(512):c['writes'].append(env['wp'](ROWS+slot*0x58+16,0xffffffff))
 for slot,id,pos in [(0,0,[0.5,0,0]),(511,1,[2,0,0])]:c['writes'] += [env['wp'](ROWS+slot*0x58+16,id),env['patch'](ROWS+slot*0x58,struct.pack('<3f',*pos))]
 for id,particle in [(0,1),(1,2)]:c['writes'] += [env['patch'](EMITTER+id*0x330+0x182,struct.pack('<H',particle)),env['patch'](EMITTER+id*0x330+0x180,struct.pack('<H',0))]
 cases.append(c)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_ESI,UC_X86_REG_EIP,UC_X86_REG_EAX
entries={};allocations=[];services=[]
def observe(uc,a,z,data):
 entries[hex(a)]=entries.get(hex(a),0)+1;sp=uc.reg_read(UC_X86_REG_ESP)
 if a==0x650e40:
  q=n.read(n.unpack('<I',sp+4)[0],16);env['audioCalls']+=1;env['audioHash'].update(struct.pack('<I',a)+q+struct.pack('<I',n.unpack('<I',sp+8)[0]))
 elif a in [0x68cfd0,0x661f60]:services.append(['normalize' if a==0x68cfd0 else 'select',uc.reg_read(UC_X86_REG_ESI) if a==0x68cfd0 else n.unpack('<I',sp+4)[0]])
 elif a==0x683560:
  at=n.unpack('<I',sp+4)[0];allocations.append([at,n.unpack('<H',at+0x18c)[0],n.unpack('<H',at+0x18e)[0],n.unpack('<H',at+0x180)[0]]);uc.reg_write(UC_X86_REG_EAX,0);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x66a190,0x68df20,0x650e40,0x68cfd0,0x661f60,0x683e90,0x683560,0x5b3800,0x6e6b90]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def service(im,kind,r):
 services.append([kind,r]);rt['trace']=allocations;rt['case']={}
 if kind=='normalize':rt['R']=r;rt['normalize'](Adapter(im))
 else:rt['select'](Adapter(im),env['f'](r))
env['service']=service
checks=0;errors=[];rows=[];start=time.time()
for i,c in enumerate(cases):
 if i%40==0:print('progress',i,len(cases),flush=True)
 io['current']=c;im=env['Image'](c)
 for a,z in REGIONS:n.write(a,im.read(a,z))
 services=[];allocations=[];env['audioHash']=hashlib.sha256();env['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 result=n.call(0x68df20,[io['PATH'],c['mode'],c['scene']],count=10000000)
 actual=dict(result=result,sha256=io['vm'].digest(),services=services.copy(),allocations=allocations.copy(),audioSha256=env['audioHash'].hexdigest(),audioCalls=env['audioCalls'],trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 services=[];allocations=[];env['audioHash']=hashlib.sha256();env['audioCalls']=0;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0
 result=oldload(im,c);predicted=dict(result=result,sha256=im.digest(),services=services.copy(),allocations=allocations.copy(),audioSha256=env['audioHash'].hexdigest(),audioCalls=env['audioCalls'],trace=io['trace'].copy(),state=dict(filePosition=io['filepos'],opens=io['opens'],reads=io['reads'],closes=io['closes']))
 for k in actual:
  checks+=1
  if actual[k]!=predicted[k]:errors.append(dict(case=i,sourceCase=c['sourceCase'],key=k,actual=actual[k],model=predicted[k]))
 if errors:print(json.dumps(errors[:10]));break
 c['expected']=actual;rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=checks,mismatches=len(errors),errors=errors[:10],excludedCases=excluded,authoredFiles=[p for p in base['authoredFiles'] if any(c.get('authored')==p['path'] for c in rows)],entryCounts=entries,binarySha256=n.sha256,seconds=round(time.time()-start,3))
(B/'reports/world-phase17-20261013-composed-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase17-20261013-composed-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=167 if a==D else 0) for a,z in REGIONS],cases=rows),separators=(',',':'))+'\n')
print(json.dumps({k:v for k,v in report.items() if k not in ['authoredFiles','excludedCases']}));print('authored',len(report['authoredFiles']),'excluded',len(excluded));assert not errors
