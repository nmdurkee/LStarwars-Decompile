"""Actual MoveForward and OriginRange with original yaw/intent/RNG/numeric/distance helpers."""
from pathlib import Path
src=Path(__file__).with_name('movement-phase4-20261013-native.py').read_text().split('# Guards, flags, formation byte boundaries')[0]
exec(compile(src,str(Path(__file__).with_name('movement-phase4-20261013-native.py')),'exec'))
n=m.NativeX86();n.write(SIN,struct.pack('<32768f',*table));OBJECT=D+0x9000;OTHER=D+0xc000;RESULT=D+0xe000;RANGE=n.STOP+0x500;vectors=[];errors=[];groups={};events=[];options={};SCALE=182.04444885253906
code=b'\xff\x74\x24\x0c'*3;callsite=RANGE+len(code);code+=b'\xe8'+struct.pack('<i',0x515360-(callsite+5))+b'\x83\xc4\x0c\xd9\x1d'+struct.pack('<I',RESULT)+b'\xc3';n.write(RANGE,code)
def callback(mu,a,s,u):
 if a not in[TOKEN,ORIGIN]:return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==TOKEN:
  text=readstr(n.unpack('<I',sp+4)[0]);mode={'walk':17,'run':34}.get(text.lower());handled=mode is not None or text=='mutate';events.append(['token',text,handled])
  if mode is not None:n.pack('<B',n.unpack('<I',sp+8)[0],mode)
  if text=='mutate':
   n.pack('<I',R,OTHER);n.pack('<3f',OBJECT+0x5c,10.125,-5.5,2.375);n.pack('<f',P+0x70,1234.5);n.pack('<B',C+0x166,1);n.pack('<I',C+0x160,0x1234cafe)
  ret(mu,int(handled))
 else:
  events.append(['origin',options.get('origin',False)])
  if options.get('originMutate'):
   n.pack('<3f',C+0x14c,2.125,-1.25,3.375);n.pack('<B',C+0x138,255 if options.get('mutateSpawn255')else 0)
  ret(mu,O if options.get('origin')else 0)
n.mu.hook_add(UC_HOOK_CODE,callback)
def prepare(o,tokens):
 setup(o,tokens);events.clear();options.clear();options.update(o);n.pack('<I',R,0 if o.get('missing')=='object'else OBJECT)
 n.pack('<3f',OBJECT+0x5c,*o.get('actorPosition',[4.125,-2.5,1.375]));n.pack('<3f',OTHER+0x5c,-20.,30.,-40.);n.pack('<H',OBJECT+0x27a,o.get('heading',12345));n.pack('<B',C+0x166,o.get('nodeFlags',1));n.pack('<f',P+0x70,o.get('cachedHeading',-2345.5));n.pack('<I',0x93d810,1 if o.get('player',True)else 0);n.pack('<I',0x8066c0,o.get('integerSeed',123))
 n.pack('<I',P+4,0);n.pack('<4f',P+0x14,.5,2.,-1.,7.)
 for j in range(4):n.pack('<B',F+0x54+j*0x34+0x2d,0)
 return bytearray(n.read(D,SIZE))
def parse(t,image):
 if'param'in t.lower():return val(struct.unpack_from('<I',image,P-D+0x14)[0])
 sign=-1 if t.startswith('-')else 1;t=t[1:]if t.startswith(('-','+'))else t;whole=decimal=0.;divisor=1.;after=False
 for c in t:
  if c=='.':after=True;continue
  if c<'0'or c>'9':break
  if after:decimal=f32(decimal*10+int(c));divisor=f32(divisor*10)
  else:whole=f32(whole*10+int(c))
 return f32(sign*f32(whole+f32(decimal/divisor)))
def integer_rng(seed):
 x=seed^0x075bd924;sv=x if x<0x80000000 else x-0x100000000;q=abs(sv)//0x1f31d*(-1 if sv<0 else 1);v=(x*0x41a7-q*0x7fffffff)&0xffffffff
 if v&0x80000000:v=(v+0x7fffffff)&0xffffffff
 return v^0x075bd924

def oracle(kind,o,tokens,first,image):
 ev=[];fr=o.get('seed',123);ir=o.get('integerSeed',123)
 def u(p):return struct.unpack_from('<I',image,p-D)[0]
 def fl(p):return val(u(p))
 def setu(p,v):struct.pack_into('<I',image,p-D,v&0xffffffff)
 def setf(p,v):setu(p,bits(v))
 def vec(p):return[fl(p+j*4)for j in range(3)]
 def put(p,v):
  for j,x in enumerate(v):setf(p+j*4,x)
 def rot(v,h):
  si=X.fl(table[(h>>1)&32767]);co=X.fl(table[((h+0x4000)>>1)&32767]);x,y,z=map(X.fl,v);return[(si*z+co*x).flstore(),v[1],(z*co-x*si).flstore()]
 def add(a,b):return[(X.fl(x)+X.fl(y)).flstore()for x,y in zip(a,b)]
 if kind=='range':
  if o.get('missing')=='creature':return bits(0),fr,ir,ev
  if o.get('originCallback',True):
   ev.append(['origin',bool(o.get('origin',False))])
   if o.get('originMutate'):put(C+0x14c,[2.125,-1.25,3.375]);image[C-D+0x138]=255 if o.get('mutateSpawn255')else 0
  point=vec(O)if o.get('origin')and o.get('originCallback',True)else None
  if point is None:
   if o.get('worldNull')or image[C-D+0x138]==255:return bits(0),fr,ir,ev
   point=vec(S+0x20)
  dif=[(X.fl(a)-X.fl(b)).flstore()for a,b in zip(vec(C+0x14c),point)];x,y,z=map(X.fl,dif);square=(x*x+y*y+z*z).flstore();answer=f32(math.sqrt(square));return bits(answer),fr,ir,ev
 if not o.get('player',True)or o.get('missing')in['creature','reference','object']:return 0,fr,ir,ev
 if first:
  setf(P+0x70,o.get('heading',12345))
  if tokens:
   mn=mx=turn=0;random=False
   def units(text):return int((X(int(parse(text,image)))*X(SCALE)).v)
   for t in tokens:
    lo=t.lower();mode={'walk':17,'run':34}.get(lo);handled=mode is not None or t=='mutate'
    if o.get('tokenCallback',True):
     ev.append(['token',t,handled])
     if mode is not None:image[C-D+0x13f]=mode
     if t=='mutate':setu(R,OTHER);put(OBJECT+0x5c,[10.125,-5.5,2.375]);setf(P+0x70,1234.5);image[C-D+0x166]=1;setu(C+0x160,0x1234cafe)
     if handled:continue
    if'min_turn'in lo:mn=units(t[lo.index('min_turn')+9:])
    elif'max_turn'in lo:mx=units(t[lo.index('max_turn')+9:])
    elif'rand_turn_dir'in lo:random=True
    elif'turn'in lo:turn=units(t[lo.index('turn')+5:])
   if mx:
    fr=(fr*0x19660d+0x3c6ef35f)&0xffffffff;rnd=(fr&0x7fffff)/8388608;turn=int((X.fl(rnd)*X(mx-mn)).v)+mn
   if turn:
    if random:ir=integer_rng(ir);turn=-turn if ir&1 else turn
    angle=(int(fl(P+0x70))+turn)&65535;angle=angle-65536 if angle>=32768 else angle;setf(P+0x70,angle)
 if image[C-D+0x166]&1:
  point=add(rot([0.,0.,10.],int(fl(P+0x70))),vec(OBJECT+0x5c));formation=u(C+0x144)
  if formation and image[formation-D+0x50]&8:
   if u(formation)==u(C+0xd0):setu(formation+0x50,u(formation+0x50)&~16)
   row=formation+0x54+image[C-D+0x14a]*0x34
   if image[formation-D+6]>image[C-D+0x14a]:
    slot=image[C-D+0x149];spacing=fl(formation+0x128)
    if image[C-D+0x1eb]&1:x=0. if image[formation-D+8]&1 else -(X.fl(spacing)*X.fl(.5)).flstore()
    else:x=(X.fl(spacing)*X.fl((slot+1)//2)).flstore();x=-x if slot&1 else x
    if image[formation-D+0x50]&4:x=-x
    h=u(row+0x24);pos=vec(row+0x18);put(C+0x1b4,add(rot([x,0.,0.],h),pos));image[C-D+0x1cc:C-D+0x1e4]=image[row-D:row-D+24];setu(C+0x1c0,0);setu(C+0x1c4,0);setu(C+0x1e8,((u(C+0x1e8)|8)&~7)|1);put(C+0x78,add(rot([0.,0.,100.],h),pos));setu(C+0x1e4,C+0x78)
  else:put(C+0x1b4,point);image[C-D+0x1cc:C-D+0x1e4]=image[C-D+0x158:C-D+0x170];setu(C+0x1c0,0);setf(C+0x1c4,.01);setu(C+0x1e8,(u(C+0x1e8)&~7)|1)
 return 0,fr,ir,ev

def run(kind,o=None,tokens=None,first=True,group='synthetic'):
 o=o or {};tokens=tokens or [];before=prepare(o,tokens);expected=bytearray(before);want,wfr,wir,wev=oracle(kind,o,tokens,first,expected)
 creature=0 if o.get('missing')=='creature'else C
 if kind=='range':n.call(RANGE,[0 if o.get('worldNull')else W,P,creature]);result=n.unpack('<I',RESULT)[0];struct.pack_into('<I',expected,RESULT-D,result)
 else:result=n.call(0x4527e0,[W,P,creature,A,len(tokens),int(first)])
 after=n.read(D,SIZE);fr=n.unpack('<I',0x95e5d4)[0];ir=n.unpack('<I',0x8066c0)[0];groups[group]=groups.get(group,0)+1
 if after!=expected or fr!=wfr or ir!=wir or events!=wev or result!=want:errors.append({'kind':kind,'input':o,'tokens':tokens,'first':first,'result':[result,want],'rng':[fr,wfr,ir,wir],'events':[list(events),wev],'diff':[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:20]})
 vectors.append({'kind':kind,'input':dict(o),'tokens':tokens,'first':first,'before':base64.b64encode(gzip.compress(before)).decode(),'after':base64.b64encode(gzip.compress(after)).decode(),'result':result,'floatRng':fr,'integerRng':ir,'events':list(events)})
for missing,player,first,node in itertools.product([None,'creature','reference','object'],[False,True],[False,True],[0,1]):run('forward',dict(missing=missing,player=player,nodeFlags=node),[],first,'forward-guards')
for turn,mn,mx,direction,heading,callback,form,owner in itertools.product([-90,0,45],[0,10],[-30,0,60],[False,True],[0,32768,65535],[False,True],[False,True],[False,True]):
 tokens=['min_turn='+str(mn),'max_turn='+str(mx),'turn='+str(turn)]+(['rand_turn_dir']if direction else[])+['walk'];run('forward',dict(heading=heading,tokenCallback=callback,formation=form,owner=owner),tokens,group='heading-range-formation')
for tokens in [['mutate','turn=45'],['turn=45','mutate'],['min_turn=10','max_turn=0','rand_turn_dir'],['min_turn=60','max_turn=-30','rand_turn_dir'],['xxturn=45'],['turn=12.9'],['min_turn=param3','max_turn=60'],['run','turn=0']]:run('forward',{},tokens,group='ordered-callback-turn')
for missing,worldNull,origin,callback,spawn,mutate in itertools.product([None,'creature','reference','object'],[False,True],[False,True],[False,True],[0,255],[False,True]):run('range',dict(missing=missing,worldNull=worldNull,origin=origin,originCallback=callback,spawn=spawn,originMutate=mutate,mutateSpawn255=True),group='origin-fallback-callback-gates')
rr=random.Random(20261013)
for j in range(512):run('range',dict(position=[f32(rr.uniform(-10000,10000))for k in range(3)],spawnPosition=[f32(rr.uniform(-10000,10000))for k in range(3)]),group='origin-distance-rounding')
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());authored={r['name']:r for r in ledger['rows']if r['name']in['MoveForward','OriginRange']and r['kind']in['scp-action','scp-condition']}
for name,row in authored.items():
 for u in row['uses']:run('forward'if name=='MoveForward'else'range',{},u.get('args',[]),True,'authored-'+name)
report={'binarySha256':n.sha256,'cases':len(vectors),'assertionGroups':5*len(vectors),'mismatches':len(errors),'errors':errors,'groups':groups,'authoredOccurrences':{k:r['sourceUses']for k,r in authored.items()},'method':'Original4527e0/515360 with unmodified numeric resolver/FTOL/RNG/yaw/angle/intent/formation scheduler/expansion/distance/sqrt helpers. Full65536byte image plus returns,RNG,callbackorder compared. OriginRange return spilled by explicit ABI wrapper only.','adapters':['Movement-token callback consumes walk/run/mutate; mutate changes referencefirstword,captured actorposition,packetheading,nodeflag/orientationword.','Origin-position callback returns preparedpoint ornull, optionally mutates creatureposition/spawnbyte. No computationalcallee replaced.'],'limits':['Finite representable heading/numeric domains; degree integerbounded ±1000000 before exact qword182.04444885253906 scaling and signedconversion.','Prepared valid actor/world/formation with scheduler rowsdisabled; actual rowdispatch executes with no rowcallback calls.','Supplied runtime sine table; actual trig tableproducer and motion/path consumers remain external.','OriginRange authored forms retained as direct body inputs; full condition-loader/default comparison execution not inferred.']}
(B/'reports/movement-phase10-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(B/'reports/movement-phase10-20261013-fixtures.json.gz','wt',encoding='utf-8')as out:json.dump({'table':[bits(v)for v in table],'vectors':vectors},out,separators=(',',':'))
print(json.dumps({'cases':len(vectors),'checks':report['assertionGroups'],'mismatches':len(errors),'examples':errors[:5]}))
