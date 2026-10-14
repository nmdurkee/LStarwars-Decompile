import json,hashlib,struct,base64,gzip,random,time,math
from pathlib import Path
def load(num,marker):
 p=Path(__file__).with_name('world-phase%d-20261013-verify.py'%num);x={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index(marker)],str(p),'exec'),x);return x
rot=load(20,'cases=[];rng=');links=load(24,'\ncases=[]');ctor=load(21,'\ncases=[]');unlinks=load(26,'\ncases=[]');events=load(33,'\ncases=[]');scalar=load(34,'choices=')
n=rot['Native']();B=rot['B'];D=n.DATA;EM=D+0x8000;PTR=D+0x1000;FIFO=D+0x2000;R=D+0x3000;POS=D+0x4000;VEL=D+0x4100;DELTA=D+0x4200;PRIMARY=D+0x4400;SECONDARY=D+0x4500;CUE=D+0x4600;FREE7=D+0x12000;FREE=D+0x13000;RETURN=D+0x14000;RETURNS=D+0x16000;PACKETS=D+0x18000;INIT=0x10302000
REGIONS=[(D,0x80000,167),(0x2961f00,0x400,0),(0x2921100,0x1200,167),(0x2923180,0x80,167),(0x2947b70,4,0),(0x2947d00,0x400,0),(0x2948e00,0x600,0),(0x810710,0x434,167),(0x8104b4,4,0),(0x292fa00,0x600,0),(0x806680,64,0),(0x29a9c48,4,0)];rot['REGIONS']=REGIONS;rot['common']=[];U=rot['U'];F=rot['F'];bits=rot['bits'];patch=rot['patch'];word=rot['word'];N=rot['N'];S16=rot['signed16'];S8=lambda v:v-256 if v&128 else v;S=lambda v:struct.unpack('<i',struct.pack('<I',U(v)))[0]
class Image(rot['Image']):
 def read(self,a,z):return super().read(U(a),z)
 def write(self,a,v):return super().write(U(a),v)
 def H(self,a,v=None):
  if v is None:return struct.unpack('<H',self.read(a,2))[0]
  self.write(a,struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return self.read(a,1)[0]
  self.write(a,bytes([v&255]))
def half(a,v):return patch(a,struct.pack('<H',v&65535))
def byte(a,v):return patch(a,bytes([v&255]))
case={};trace=[]
def service(im,address,args):
 trace.append([address,args])
 if address==0x5d69a0:
  if case.get('visibilityMutate'):im.W(0x810908,bits(0.5))
  return case.get('visibility',1)
 e,r,t=args;im.W(e+0x324,case.get('fixedTime',t))
 if case.get('mutateClock'):im.W(0x296205c,bits(80));im.W(0x2962060,bits(90))
 if case.get('mutateRecord'):im.B(r+0x410,2);im.W(r+0x414,bits(0.75));im.W(r+0xa4,bits(2))
 if case.get('retargetBase'):im.W(0x29620a4,EM+0x8000)
 if case.get('alterChunks'):im.H(e+0x180,1)
 return CUE if case.get('cue') else 0
def returntime(im,r,clock):
 product=N.word(im.W(r+0x414))*N(S8(im.B(r+0x410)));return (N.word(im.W(r+0xa4))+N.word(clock)+product).store()
def burst(im,c):
 physical=c['physical'];pos=c['position'];vel=c['velocity'];delta=c['delta'];count=c['count'];duration=c['duration'];secondary=c['secondary'];primary=c['primary'];priority=c['priority'];flags=c['flags']
 if im.W(0x2962050) or not im.W(0x8104b4) or physical in [0,0xffffffff] or S(physical)>=S(im.W(0x2962098)):return
 r=im.W(im.W(0x296209c)+physical*4)
 if not r or im.B(r+0x13) or count<=0:return
 if im.B(r+0x2f1)!=4:
  if not service(im,0x5d69a0,[im.W(pos),im.W(pos+4),im.W(pos+8),bits(1),bits(1),bits(1),im.W(r+0x38)]):return
 scale=im.W(0x810908)
 if not im.W(0x29620b8) and F(im.W(r+0x2f4))<F(scale):scale=im.W(r+0x2f4)
 step=scalar['divide'](bits(float(count)),scale);step=scalar['divide'](bits(1),step);secondary=secondary or 0x806680;primary=primary or 0x806680
 bank=int(im.B(r+0x2f1)==4);clock=im.W(0x2962060 if bank else 0x296205c);end=(N.word(clock)+N.word(duration)).store();q=F(scalar['divide'](clock,step));cycle=-2147483648 if not math.isfinite(q) or q>=2147483648 or q< -2147483648 else math.trunc(q)
 previous=(N(cycle)*N.word(step)).store();first=(N.word(previous)+N.word(step)).store();scan=first;eventsCount=0;iterations=0
 if not F(scan)<=F(end):return
 while True:
  iterations+=1
  if iterations>=100:break
  scan=(N.word(scan)+N.word(step)).store();eventsCount+=1
  if not F(scan)<=F(end):break
 if not eventsCount:return
 particles=S((S8(im.B(r+0x410))+1)*eventsCount);e=0;cachedBase=im.W(0x29620a4);selected=-1
 for slot in range(8):
  id=im.H(r+0x3d0+slot*2)
  if id!=65535:
   e=U(cachedBase+S16(id)*0x330);total=S(S16(im.H(e+0x186))+particles)
   if total<=(384 if im.B(r+0x2e)==7 else 1024):selected=slot;break
  elif S(im.W(0x29211e8))<S(im.W(0x2962094)):
   allocated=ctor['allocate'](im);im.H(r+0x3d0+slot*2,allocated);e=U(im.W(0x29620a4)+S16(allocated&65535)*0x330);im.H(e+0x182,physical);im.W(e+0x1d4,0);im.W(e+0x1c0,im.W(0x810910+S8(im.B(r+0x2c))*4));im.W(e+0x1c4,im.W(0x810944+S8(im.B(r+0x2d))*4))
   for i in range(0,64,4):im.W(e+0x40+i,im.W(primary+i))
   for i in [0x70,0x74,0x78]:im.W(e+i,0)
   ctor['position'](im,U(S16(im.H(r+0x3d0+slot*2))),[0,0,0]);im.H(e+0x328,priority);im.B(e+0x2f8,flags);selected=slot;break
 if not e:return
 special=im.B(r+0x2e)==7;unit=12 if special else 32;total=S(particles+S16(im.H(e+0x186)));current=S16(im.H(e+0x180))
 if total>current*unit:
  if current<0:im.H(e+0x180,0)
  added=S(total+unit-1);desired=abs(added)//unit*(1 if added>=0 else -1);additional=S(desired-S16(im.H(e+0x180)));used=0x2947d84 if special else 0x2948e98;cap=0x8108ec if special else 0x8108e8;free=0x29211fc if special else 0x2921200
  if S(im.W(used)+additional)>=S(im.W(cap)) or desired>32:return
  for i in range(additional):
   p=im.W(im.W(free)+im.W(used)*4);im.W(e+0x100+S16(im.H(e+0x180))*4,p);im.W(used,im.W(used)+1)
   for j in range(unit):
    p=im.W(e+0x100+S16(im.H(e+0x180))*4);im.W(p+0x2c+j*32,0);p=im.W(e+0x100+S16(im.H(e+0x180))*4);im.W(p+0x3c+j*32,0x47000000)
   im.H(e+0x180,im.H(e+0x180)+1)
  im.H(e+0x180,desired);links['commands'](im,e+0x100,desired)
  if desired==additional:
   limit=S(im.W(0x8108ec)+im.W(0x8108e8));table=im.W(0x2961fec)
   for index in range(max(0,limit)):
    if not im.W(table+index*0x64):
     off=index*0x64;im.W(table+off,im.W(e+0x100));im.W(im.W(0x2961fec)+off+4,r);im.W(im.W(0x2961fec)+off+8,e);im.H(im.W(0x2961fec)+off+0x60,priority);links['priority'](im,im.W(0x2961fec)+off,U(0x292fd30+S8(im.B(r+0x2f1))*4));break
 im.H(e+0x186,im.H(e+0x186)+particles)
 for i in range(3):im.W(e+0x1a8+i*4,0 if not vel else im.W(vel+i*4))
 # Real655b30 forward raw copy, with fresh live base and final reset.
 id=S16(im.H(U(r+0x3d0+selected*2)));off=U(id*0x330)
 if U(id)!=0xffffffff:
  dest=U(im.W(0x29620a4)+off+0x80)
  for i in range(0,64,4):im.W(dest+i,im.W(secondary+i))
  for f in [0xb0,0xb4,0xb8,0x300]:im.W(im.W(0x29620a4)+off+f,0)
 im.W(e+0x324,previous);t=first;iterations=0
 if F(t)<=F(end):
  while True:
   iterations+=1
   if iterations>=100:break
   if delta:
    scaled= (N.word(t)+N(-N.word(end).v,not N.word(end).neg)).store();scalar['scaled'](im,dict(scale=scaled,delta=delta,basis=pos,destination=e+0x19c))
   else:
    for i in range(3):im.W(e+0x19c+i*4,im.W(pos+i*4))
   im.W(e+0x1e0,t);cue=service(im,im.W(e+0x1c0),[e,r,t])
   if im.B(r+0x2f0) and iterations==1 and cue:events['produce'](im,dict(emitter=e,cue=cue,physical=r,time=t,latch=1))
   t=(N.word(step)+N.word(im.W(e+0x324))).store()
   if not F(t)<=F(end):break
 assert not im.W(0x2962058);im.W(0x2962058,1);scheduled=S16(im.H(e+0x188));chunks=S16(im.H(e+0x180))
 if scheduled<chunks:
  i=scheduled;cursor=U(e+0x100+i*4);cachedCount=im.W(0x2947b70)
  while i<S16(im.H(e+0x180)):
   maximum=S((im.W(0x8108ec)+im.W(0x8108e8))*2)
   if S(cachedCount)<maximum:
    node=im.W(im.W(0x2923198)+cachedCount*4);im.W(node,im.W(cursor));life=im.W(r+0x414);frames=S8(im.B(r+0x410));deadline=(N.word(im.W(r+0xa4))+N.word(clock)+N.word(life)*N(frames)).store();node=im.W(im.W(0x2923198)+im.W(0x2947b70)*4);im.W(node+4,deadline)
    node=im.W(im.W(0x2923198)+im.W(0x2947b70)*4);im.W(node+8,1);node=im.W(im.W(0x2923198)+im.W(0x2947b70)*4);im.W(node+12,e);node=im.W(im.W(0x2923198)+im.W(0x2947b70)*4);links['timed'](im,node,0x292fbfc+bank*4);im.W(0x2947b70,im.W(0x2947b70)+1);im.H(e+0x188,im.H(e+0x188)+1);cachedCount=im.W(0x2947b70)
   i+=1;cursor+=4
 chunks=im.H(e+0x180)
 if im.H(e+0x188)==chunks:
  head=0x292fbfc+bank*4;node=im.W(head)
  if node:
   last=im.W(e+0xfc+S16(chunks)*4)
   while node and im.W(node)!=last:node=im.W(node+16)
   if node:unlinks['timed'](im,node,head);im.W(node+4,returntime(im,r,clock));links['timed'](im,node,head)
 active=im.H(e+0x186);allocated=im.H(e+0x180);im.H(e+0x18e,active);im.H(e+0x18c,allocated);im.W(0x2962058,0)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n.mu.mem_map(INIT,0x1000);n.write(INIT,b'\xc3');entries={};nativeTrace=[]
class NativeImage:
 def W(self,a,v=None):
  if v is None:return n.unpack('<I',U(a))[0]
  n.write(U(a),struct.pack('<I',U(v)))
 def H(self,a,v=None):
  if v is None:return n.unpack('<H',U(a))[0]
  n.write(U(a),struct.pack('<H',v&65535))
 def B(self,a,v=None):
  if v is None:return n.read(U(a),1)[0]
  n.write(U(a),bytes([v&255]))
NI=NativeImage()
def observe(uc,a,z,user):
 if a in [0x6561d0,0x653940,0x64fde0,0x5b3860,0x6550b0,0x655940,0x5ffea0,0x654e00,0x655b30,0x656080,0x6551d0,0x655210,0x6e6b90]:entries[hex(a)]=entries.get(hex(a),0)+1
 if a not in [0x5d69a0,INIT]:return
 sp=uc.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if a==0x5d69a0:
  p,v,rad=n.unpack('<3I',sp+4);args=list(n.unpack('<3I',p))+list(n.unpack('<3I',v))+[rad]
 else:args=list(n.unpack('<3I',sp+4))
 start=len(trace);value=service(NI,a,args);nativeTrace.extend(trace[start:]);del trace[start:]
 uc.reg_write(UC_X86_REG_EAX,U(value));uc.reg_write(UC_X86_REG_ESP,sp+4);uc.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,observe)
def seed(count=4,duration=1,typ=0,bank=4,current=None):
 c=dict(physical=1,position=POS,velocity=VEL,delta=DELTA,count=count,duration=bits(duration),secondary=SECONDARY,primary=PRIMARY,priority=30000,flags=0x56,visibility=1,cue=False,writes=[word(0x2962050,0),word(0x8104b4,1),word(0x2962098,4),word(0x296209c,PTR),word(PTR+4,R),word(0x2962094,16),word(0x2962084,FIFO),word(0x29211e8,0),word(0x29620a4,EM),word(0x29620b8,0),word(0x810908,bits(1)),byte(R+0x13,0),byte(R+0x2f1,bank),byte(R+0x2e,typ),byte(R+0x2c,0),byte(R+0x2d,0),word(R+0x2f4,bits(1)),word(R+0x38,bits(1)),byte(R+0x410,0),byte(R+0x2f0,0),word(R+0x414,bits(0.25)),word(R+0xa4,bits(5)),word(0x296205c,bits(10)),word(0x2962060,bits(20)),patch(POS,struct.pack('<3f',1.25,-2.5,-0.0)),patch(VEL,struct.pack('<3f',0.5,0.25,-0.0)),patch(DELTA,struct.pack('<3f',0.25,-0.5,0.125)),patch(PRIMARY,struct.pack('<16I',*[i*0x01010101 for i in range(16)])),patch(SECONDARY,struct.pack('<16I',*[i*0x1001001 for i in range(16)])),patch(0x806680,n.read(0x806680,64)),patch(EM-0x330,bytes(0x8000)),word(0x29211fc,FREE7),word(0x2921200,FREE),word(0x2923198,RETURN),word(0x2961fec,PACKETS),word(0x2947b70,0),word(0x2947d84,0),word(0x2948e98,0),word(0x8108e8,33),word(0x8108ec,33),word(0x2962058,0),patch(0x292fa00,bytes(0x600)),patch(CUE,struct.pack('<3f',0.5,0.25,-0.0)),patch(CUE+0x10,struct.pack('<3I',0x12345678,0x87654321,0x00112233))])
 for i in range(-128,128):c['writes'] += [word(0x810910+i*4,INIT)]
 # Restore globals overlapped by selector preparation.
 c['writes'] += [word(0x810908,bits(1)),word(0x8108e8,33),word(0x8108ec,33)]
 for i in range(16):c['writes'] += [half(FIFO+i*2,i),half(EM+i*0x330+0x2c8,0),half(EM+i*0x330+0x2ca,0),word(EM+i*0x330+0x2cc,bits(0)),word(EM+i*0x330+0x1c0,INIT)]
 for i in range(8):c['writes'] += [half(R+0x3d0+i*2,65535)]
 for i in range(-4,64):c['writes'] += [word(FREE7+i*4,D+0x20000+(i+4)*0x500),word(FREE+i*4,D+0x40000+(i+4)*0x500)]
 for i in range(132):c['writes'] += [word(RETURN+i*4,RETURNS+i*0x20),word(RETURNS+i*0x20,0),word(RETURNS+i*0x20+4,bits(i*0.5)),word(RETURNS+i*0x20+0x10,0)]
 for i in range(66):c['writes'] += [word(PACKETS+i*0x64,0),half(PACKETS+i*0x64+0x60,i),word(PACKETS+i*0x64+0x58,0),word(PACKETS+i*0x64+0x5c,0)]
 if current is not None:
  c['writes'] += [half(R+0x3d0,1),half(EM+0x330+0x180,current),half(EM+0x330+0x186,current*(12 if typ==7 else 32)),half(EM+0x330+0x188,current),half(EM+0x330+0x328,30000)]
  for i in range(32):c['writes'] += [word(EM+0x330+0x100+i*4,D+0x40000+(i+4)*0x500)]
 return c
cases=[]
for typ in [0,7]:
 for count in [1,2,4,12,32,100,1024]:
  for duration in [0,0.125,0.25,0.5,1,2,30]:
   for bank in [0,4]:cases.append(seed(count,duration,typ,bank))
for typ in [0,7]:
 for current in [0,1,2,7,31]:
  for active in [0,1,11,31,383,1023]:
   c=seed(4,1,typ,current=current);c['writes'] += [half(EM+0x330+0x186,active)];cases.append(c)
for frames in range(256):c=seed();c['writes'] += [byte(R+0x410,frames)];cases.append(c)
for gate in ['disabled','paused','id0','id-1','pastcap','null','recorddisabled','count0','countnegative','visibility','noallocate','zeroglobalscale','zerorecordscale']:
 c=seed(bank=0)
 if gate=='disabled':c['writes'] += [word(0x2962050,1)]
 elif gate=='paused':c['writes'] += [word(0x8104b4,0)]
 elif gate=='id0':c['physical']=0
 elif gate=='id-1':c['physical']=0xffffffff
 elif gate=='pastcap':c['physical']=4
 elif gate=='null':c['writes'] += [word(PTR+4,0)]
 elif gate=='recorddisabled':c['writes'] += [byte(R+0x13,1)]
 elif gate=='count0':c['count']=0
 elif gate=='countnegative':c['count']=-1
 elif gate=='visibility':c['visibility']=0
 elif gate=='noallocate':c['writes'] += [word(0x29211e8,16)]
 elif gate=='zeroglobalscale':c['writes'] += [word(0x810908,0)]
 else:c['writes'] += [word(R+0x2f4,0)]
 cases.append(c)
for bank in [0,1,4,127,128,255]:
 for nullmask in range(16):
  c=seed(bank=bank)
  if nullmask&1:c['velocity']=0
  if nullmask&2:c['delta']=0
  if nullmask&4:c['primary']=0
  if nullmask&8:c['secondary']=0
  cases.append(c)
for cap in [0,1,2,3,4,33]:
 for used in [0,1,2,32]:
  for typ in [0,7]:c=seed(100,1,typ);c['writes'] += [word(0x8108e8 if typ==0 else 0x8108ec,cap),word(0x2948e98 if typ==0 else 0x2947d84,used)];cases.append(c)
for rate in [1,2,4,127,128,255]:
 for bank in [0,4]:c=seed(bank=bank);c['cue']=True;c['writes'] += [byte(R+0x2f0,rate)];cases.append(c)
for feature in ['visibilityMutate','mutateClock','mutateRecord','retargetBase','alterChunks','fixedTime']:
 c=seed(bank=0);c[feature]=True if feature!='fixedTime' else bits(20);cases.append(c)
for coef in [0,0x80000000,bits(0.5),bits(2),bits(-0.5)]:
 for mode in [0,1]:c=seed();c['writes'] += [word(R+0x2f4,coef),word(0x29620b8,mode)];cases.append(c)
# Selection captures the pool base, accepts signed16 emitter IDs and preserves the all-full last-emitter fallthrough.
for ready in range(9):
 c=seed();c['writes'] += [half(R+0x3ce,8)]
 for j in range(8):c['writes'] += [half(R+0x3d0+j*2,j+1),half(EM+(j+1)*0x330+0x186,0 if j==ready else 1024),half(EM+(j+1)*0x330+0x180,1),half(EM+(j+1)*0x330+0x188,1),word(EM+(j+1)*0x330+0x100,D+0x40000+(j+4)*0x500)]
 cases.append(c)
for ready in range(8):
 c=seed()
 for j in range(ready):c['writes'] += [half(R+0x3d0+j*2,j+1),half(EM+(j+1)*0x330+0x186,1024)]
 cases.append(c)
# Live signed selectors and signed priority banks consume their physically prepared entries.
for selector in [0,1,12,127,128,255]:
 c=seed();c['writes'] += [byte(R+0x2c,selector),byte(R+0x2d,selector),word(0x810910+S8(selector)*4,INIT),word(0x810944+S8(selector)*4,INIT)];cases.append(c)
# Real secondary forward REP copy overlaps its own emitter and can retarget the live reset base.
for shift in [-8,-4,0,4,8]:
 c=seed(current=1);c['secondary']=EM+0x330+0x80+shift;cases.append(c)
# Cached emitter survives callback replacement of live global base; cached clock survives mutation.
for feature in ['mutateClock','mutateRecord','retargetBase']:
 c=seed(current=1,bank=0);c[feature]=True;c['cue']=True;c['writes'] += [byte(R+0x2f0,4)];cases.append(c)
# Queue availability uses signed count and live capacity while scheduling count advances only after insertion.
for count in [0,1,65,66,131,132,133]:
 c=seed(100,1);c['writes'] += [word(0x2947b70,count)];cases.append(c)
# Packet searches use a cached base; subsequent stores reload the global pointer.
for kind in ['full','second','priority-count-clear']:
 c=seed()
 if kind=='full':
  for i in range(66):c['writes'] += [word(PACKETS+i*0x64,D+0x70000+i*4)]
 elif kind=='second':c['writes'] += [word(PACKETS,D+0x70000)]
 else:
  base=0x2948e98-0x5c;c['writes'] += [word(0x2961fec,base),word(base,0),word(0x8108e8,2),word(0x8108ec,0)]
 cases.append(c)
# Attribute and position source aliases preserve sequential stores at exact integer/float boundaries.
for anchor in [0x1a8,0x19c]:
 for shift in [-4,0,4]:
  c=seed(current=1);c['velocity']=EM+0x330+anchor+shift;c['position']=EM+0x330+anchor+shift;c['delta']=0;c['writes'] += [patch(EM+0x330+anchor-4,struct.pack('<5f',1,2,3,4,5))];cases.append(c)
rows=[];errors=[];start=time.time()
for i,c in enumerate(cases):
 case=c;trace=[];im=Image(c)
 try:burst(im,c)
 except Exception as ex:errors.append(dict(case=i,stage='model',error=str(ex)));break
 modelTrace=trace[:];trace=[];nativeTrace=[];initial=Image(c)
 for a,z,_ in REGIONS:n.write(a,initial.read(a,z))
 try:n.call(0x6561d0,[c['physical'],c['position'],c['velocity'],c['delta'],U(c['count']),c['duration'],c['secondary'],c['primary'],c['priority'],c['flags']],count=2000000)
 except Exception as ex:errors.append(dict(case=i,stage='native',error=str(ex)));break
 actual=hashlib.sha256(b''.join(n.read(a,z) for a,z,_ in REGIONS)).hexdigest()
 if actual!=im.hash() or nativeTrace!=modelTrace:
  errors.append(dict(case=i,actual=actual,model=im.hash(),nativeTrace=nativeTrace[:8],modelTrace=modelTrace[:8]))
  for a,z,_ in REGIONS:
   if n.read(a,z)!=im.read(a,z):errors.append(dict(region=hex(a),diffs=[dict(address=hex(a+j),native=n.read(a+j,4).hex(),model=im.read(a+j,4).hex()) for j in range(0,z,4) if n.read(a+j,4)!=im.read(a+j,4)][:15]))
  break
 c['expected']=dict(sha256=actual,trace=nativeTrace);rows.append(c)
report=dict(status='sealed bounded' if not errors else 'draft mismatch',cases=len(rows),checks=len(rows)*2,mismatches=len(errors),errors=errors[:8],entries=entries,binarySha256=n.sha256,nativeAdapters=['0x5d69a0 copied visibility arguments','selected initializer 0x10302000'],seconds=round(time.time()-start,3))
(B/'reports/world-phase35-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n')
if not errors:(B/'reports/world-phase35-20261013-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,regions=[dict(address=a,length=z,fill=f) for a,z,f in REGIONS],cases=rows),separators=(',',':'))+'\n').encode(),compresslevel=9,mtime=0))
print(json.dumps(report));assert not errors
