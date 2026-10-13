"""CreatePod native composition, only terminal type and actor-creation services adapted."""
from pathlib import Path
p22=Path(__file__).with_name('movement-phase22-20261013-native.py').read_text();exec(p22[:p22.index('for mode,factor,delta in itertools.product')])
curve={'__file__':__file__};p20=Path(__file__).with_name('movement-phase20-20261013-native.py');exec(compile(p20.read_text().split('for count,param in itertools.product')[0],str(p20),'exec'),curve)
from unicorn import UC_HOOK_CODE
SIZE=0x40000;C=D+0x1000;P=D+0x1800;ACT=D+0x5000;A=D+0xd000;T=D+0xe000;RACE=D+0x10000;ALT=D+0x20000;CB1=n.STOP+0x100;CB2=n.STOP+0x200;CB3=0x43d890;vectors=[];errors=[];groups={};events=[];cfg={};entryCounts={}
originalTemplate=list(n.unpack('<16I',0x8065c0));step=n.unpack('<f',0x7f15e0)[0]
def u32(p):return n.unpack('<I',p)[0]
def text(p):
 b=bytearray()
 while n.read(p,1)!=b'\0':b.extend(n.read(p,1));p+=1
 return b.decode('ascii')
def typevalue(name):return 0x123400ff if name.lower()=='unknown' else 0xabcdef01 if name.lower()in['miscpod','mutate'] else 2

def hook23(mu,a,s,user):
 if a in[0x4dd810,0x5147c0,0x4d94b0,0x40f450,0x40eff0,0x4d8280,0x4d94f0,0x5b3470,0x5be2d0]:entryCounts[hex(a)]=entryCounts.get(hex(a),0)+1
 if a not in[CB1,CB2,CB3]:return
 sp=mu.reg_read(m.UC_X86_REG_ESP);args=list(n.unpack('<11I',sp+4))if a==CB3 else [u32(sp+4)]
 if a==CB1:
  name=text(args[0]);result=typevalue(name);events.append(['definition',name,result])
  if name.lower()=='mutate':n.pack('<f',C+0x14,.25);n.pack('<f',RACE+0xb00c,5.);n.pack('<I',0x882a6c,ALT if cfg.get('switchRace')else RACE)
 elif a==CB2:result=cfg.get('type',0x12348002);events.append(['type',args[0],result])
 else:
  result=0 if cfg.get('noActor')else ACT;pod=mu.reg_read(m.UC_X86_REG_ESI);events.append(['create',args,result,n.read(pod,0xa0).hex()])
  if cfg.get('spawnMutation'):n.pack('<I',pod+0x88,0xcafe1234);n.pack('<I',ACT+0xef4,0x2468ace0);n.pack('<I',pod+0x90,ACT+0x100)
 mu.reg_write(m.UC_X86_REG_EAX,result);mu.reg_write(m.UC_X86_REG_ESP,sp+4);mu.reg_write(m.UC_X86_REG_EIP,u32(sp))
n.mu.hook_add(UC_HOOK_CODE,hook23)
def setup23(c,tokens):
 n.write(D,bytes([0xa5])*SIZE);n.pack('<I',C+4,0);n.pack('<4f',C+0x14,.2,2.,3.,4.);n.pack('<I',P+4,0);n.pack('<4f',P+0x14,.75,7.,8.,9.);n.pack('<I',ACT+0xef4,c.get('flags',0x11223344));n.pack('<I',0x882a68,0x76543210);n.pack('<I',0x882a6c,0 if c.get('nullRace')else RACE);n.pack('<f',0x925018,c.get('delta',f32(1/60)));n.pack('<16I',0x8065c0,*c.get('template',originalTemplate));
 for race in[RACE,ALT]:
  n.pack('<f',race+0xb00c,c.get('time',20.))
  for j in range(32):
   q=race+j*0x530
   count=c.get('count',4)
   for k in range(count+2):n.pack('<4f',q+k*16,f32(k*1.125),f32(k*k*.375),f32(k*-2.5),f32(.125+k*.25))
   n.pack('<I',q+0x400,0 if c.get('empty')else count);n.pack('<f',q+0x410,count*10.);n.pack('<'+'f'*count,q+0x414,*[(k+1)*10. for k in range(count)]);n.pack('<I',q+0x524,99 if c.get('noMatch')else j)
  for j in range(16):n.pack('<I',race+0xa694+j*0xa0,0 if j==c.get('free',0)else 1);n.pack('<f',race+0xa65c+j*0xa0,c.get('curve',1234.5))
 n.pack('<I',0x923884,CB1 if c.get('definition',True)else 0);n.pack('<I',0x923894,CB2 if c.get('typeCallback',True)else 0);pos=T
 for j,t in enumerate(tokens):n.write(pos,t.encode()+b'\0');n.pack('<I',A+j*4,pos);pos+=len(t)+4
 events.clear();cfg.clear();cfg.update(c);return bytearray(n.read(D,SIZE))
def parse23(t,img,context):
 if context and'param'in t.lower():return struct.unpack_from('<f',img,context-D+0x14)[0]
 i=1 if t.startswith('-')else 0;div=-1. if i else 1.;v=0.
 while i<len(t)and'0'<=t[i]<='9':v=f32(f32(v*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':div=f32(div*10);v=f32(f32(v*10)+int(t[i]));i+=1
 return f32(v/div)
def oracle23(c,tokens,first,img):
 global POD,MATRIX
 ev=[];pace=0x76543210;race=0 if c.get('nullRace')else RACE;start=0.;end=1.;tf=1.;ident=0xffffffff;ty=65535;pacemaker=damaged=False;context=0 if c.get('nullContext')else C
 def fl(p):return struct.unpack_from('<f',img,p-D)[0]
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 if not first or not tokens:return pace,ev
 for t in tokens:
  lo=t.lower()
  if'spline_id='in lo:ident=int(parse23(t[lo.index('spline_id=')+10:],img,context))&0xffffffff
  elif'type='in lo:
   if c.get('definition',True)and c.get('typeCallback',True):
    name=t[lo.index('type=')+5:];v=typevalue(name);ev.append(['definition',name,v]);ty=v&255
    if name.lower()=='mutate':struct.pack_into('<f',img,C-D+0x14,.25);struct.pack_into('<f',img,RACE-D+0xb00c,5.);race=ALT if c.get('switchRace')else RACE
    if ty!=255:v=c.get('type',0x12348002);ev.append(['type',ty,v]);ty=v&65535
  elif'spline_start='in lo:start=parse23(t[lo.index('spline_start=')+13:],img,context)
  elif'spline_end='in lo:end=parse23(t[lo.index('spline_end=')+11:],img,context)
  elif'time_factor='in lo:tf=parse23(t[lo.index('time_factor=')+12:],img,context)
  elif lo=='pacemaker':pacemaker=True
  elif lo=='damaged':damaged=True
 if ident>31 or ty==65535:return pace,ev
 spline=race
 for j in range(32):
  spline=race+j*0x530
  if u(spline+0x524)==ident:break
 start=max(0.,min(1.,start));end=max(0.,min(1.,end))
 if not spline or not u(spline+0x400)or start==end:return pace,ev
 pod=0
 for j in range(16):
  if not u(race+0xa694+j*0xa0):pod=race+0xa600+j*0xa0;break
 if not pod:return pace,ev
 struct.pack_into('<f',img,pod-D+0x84,start);struct.pack_into('<H',img,pod-D+0x88,ty);put(pod+0x94,1);put(pod+0x80,spline);time=quant(Fraction(fl(race+0xb00c))*Fraction(tf),64);rate=1.
 if time>0:rate=f32(float(quant(quant(Fraction((X.fl(end)-X.fl(start)).flstore())*Fraction(fl(spline+0x410)),64)/time,64)))
 struct.pack_into('<f',img,pod-D+0x7c,rate);img.extend(bytes(256));scratch=D+SIZE;curve['CURVE']=spline
 curve['model']('distance',{},img,scratch,(X.fl(start)*X.fl(fl(spline+0x410))).flstore());curve['model']('distance',{},img,scratch+16,((X.fl(step)+X.fl(start))*X.fl(fl(spline+0x410))).flstore());struct.pack_into('<16I',img,pod-D,*c.get('template',originalTemplate));img[pod-D+0x30:pod-D+0x40]=img[SIZE:SIZE+16]
 for j in range(3):struct.pack_into('<f',img,SIZE+32+j*4,(X.fl(fl(scratch+16+j*4))-X.fl(fl(scratch+j*4))).flstore())
 POD=MATRIX=pod;heading(dict(source=scratch+32,delta=c.get('delta',f32(1/60)),factor=1,mode=0),img);struct.pack_into('<4f',img,pod-D+0x40,0,0,0,1);img[pod-D+0x50:pod-D+0x60]=img[SIZE:SIZE+16];struct.pack_into('<f',img,pod-D+0x8c,start);signed=short(u(pod+0x88));actor=0 if c.get('noActor')else ACT;ev.append(['create',[signed&0xffffffff,spline,0,0,0,0,1,0,0,0,0],actor,bytes(img[pod-D:pod-D+0xa0]).hex()])
 if c.get('spawnMutation'):put(pod+0x88,0xcafe1234);put(ACT+0xef4,0x2468ace0);put(pod+0x90,ACT+0x100)
 put(pod+0x90,actor)
 if actor:
  put(actor+0xef4,u(actor+0xef4)|0x4000000);img[u(pod+0x90)-D+0x107a]=5
  if pacemaker:actor=u(pod+0x90);put(actor+0xef4,u(actor+0xef4)|0x20);pace=actor
  if damaged:actor=u(pod+0x90);put(actor+0xef4,u(actor+0xef4)|0x8000000)
 del img[SIZE:];return pace,ev

def run23(c,tokens,first=True,group='synthetic'):
 before=setup23(c,tokens);expected=bytearray(before);pace,ev=oracle23(c,tokens,first,expected);result=n.call(0x4dd810,[0,P,0 if c.get('nullContext')else C,A,len(tokens),int(first)],count=1000000);after=n.read(D,SIZE);actualpace=u32(0x882a68);groups[group]=groups.get(group,0)+1
 if after!=expected or actualpace!=pace or events!=ev or result!=1:errors.append(dict(input=c,tokens=tokens,first=first,pace=[actualpace,pace],events=[events.copy(),ev],result=result,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:16]))
 vectors.append(dict(input=c,tokens=tokens,first=first,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),pace=actualpace,events=events.copy(),result=result))
base=['spline_id=1','type=MiscPod']
for first,definition,typecb,tokens in itertools.product([False,True],[False,True],[False,True],[[],base,['type=MiscPod'],['spline_id=-1','type=MiscPod'],['spline_id=32','type=MiscPod']]):run23(dict(definition=definition,typeCallback=typecb),tokens,first,'guards-type-prerequisites')
for free,time,tf,start,end in itertools.product([0,7,15,16],[-1,0,20],[-1,0,1,2],[0,.2,1],[-.5,.8,2]):run23(dict(free=free,time=time),base+['time_factor='+str(tf),'spline_start='+str(start),'spline_end='+str(end)],group='slots-clamps-positive-time-grid')
for noMatch,empty,noActor,flags,tokens in itertools.product([False,True],[False,True],[False,True],[0,0xffffffff],[base,base+['pacemaker','damaged']]):run23(dict(noMatch=noMatch,empty=empty,noActor=noActor,flags=flags),tokens,group='last-row-fallback-count-actor-flags')
for switch,spawn,tokens in itertools.product([False,True],[False,True],[['spline_id=1','type=mutate','spline_start=param3'],['spline_id=1','spline_start=param3','type=mutate'],['spline_id=param3','type=mutate','pacemaker','damaged'],base+['type=unknown'],base+['type=unknown','type=MiscPod']]):run23(dict(switchRace=switch,spawnMutation=spawn),tokens,group='callback-mutation-numeric-context-order')
for count,start,end in itertools.product([2,3,8,16,63,64],[0,.2,.875],[.125,.8,1]):run23(dict(count=count),base+['spline_start='+str(start),'spline_end='+str(end)],group='curve-backing-count-edge-composition')
for typ,context in itertools.product([0,255,65535,0x12348001],[False,True]):run23(dict(type=typ,nullContext=context),base+['spline_start=param3'],group='signed-type-null-numeric-context')
for j in range(128):
 template=originalTemplate[:]
 for row in range(3):
  for col in range(3):template[row*4+col]=bits(f32(r.uniform(-2,2)))
 run23(dict(template=template,delta=f32(r.uniform(-.125,.125)),time=f32(r.uniform(.01,200)),curve=f32(r.uniform(-65536,65536))),base+['spline_start='+str(f32(r.uniform(0,1))),'spline_end='+str(f32(r.uniform(0,1)))],group='runtime-template-nonorthogonal-bank-rounding')
ledger=json.loads((m.BASE/'reports/gameplay-command-semantic-coverage.json').read_text());row=next(v for v in ledger['rows']if v['name']=='CreatePod'and v['kind']=='scp-action')
for use in row['uses']:run23({},use.get('args',[]),group='authored-CreatePod')
report=dict(nativeEntryCounts=entryCounts,binarySha256=n.sha256,cases=len(vectors),assertionGroups=4*len(vectors),groups=groups,mismatches=len(errors),errors=errors[:20],authoredOccurrences={'CreatePod':row['sourceUses']},nativeAdapters=['Definition ID callback 923884, actor type callback 923894, and terminal actor creation 43d890 only. Original parser/numeric/curve/matrix/heading bodies execute.'],limits=['Finite prepared valid 2..64 control backing and runtime template/sine/angle data; representable numeric conversions.','Actor allocation/initialization remains an explicit service; no full game frame claim.'])
(m.BASE/'reports/movement-phase23-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase23-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(table=[bits(v)for v in table],angles=angles,template=originalTemplate,stepBits=bits(step),vectors=vectors),f,separators=(',',':'))
print(json.dumps(dict(cases=len(vectors),checks=4*len(vectors),mismatches=len(errors),errors=errors[:3])))

from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);ins=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(0x4dd810,0x4ddc7f-0x4dd810),0x4dd810)]
(m.BASE/'reports/movement-phase23-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=[dict(address='0x4dd810',size=0x4ddc7f-0x4dd810,instructions=ins)]),indent=2)+'\n')
