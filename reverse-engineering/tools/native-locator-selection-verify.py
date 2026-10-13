import importlib.util,json,random,struct,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('reserve',Path(__file__).with_name('native-locator-reservations-verify.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r);a=r.a;n=r.n;B=r.B
s=importlib.util.spec_from_file_location('cull',Path(__file__).with_name('native-locator-culling-verify.py'));v=importlib.util.module_from_spec(s);s.loader.exec_module(v)
P=r.SET+0x17000;S=P+0x10
rows=[];errors=[];groups={};memory=0

def distance(a,b):
 d=[v.f(v.add(x,-y)) for x,y in zip(a,b)];return v.f(v.add(v.add(v.mul(d[0],d[0]),v.mul(d[1],d[1])),v.mul(d[2],d[2])))
def defaults(o):
 out=dict(range=0.,primary=[0.,0.,0.],secondary=None,radius=0.,positions=[[float(i*2),float(i%3),float(i)] for i in range(16)],view=v.I[:],planes=v.PLANES[:],object=v.I[:],near=1.,far=10.,random=7);out.update(o);return out

def model(c,o,indices,owners,kind):
 out=dict(selected=[x['selected'] for x in c['actors']],owners=owners[:],random=o['random'])
 target=o.get('target',0)
 if not o.get('set',True) or not o.get('actor',True) or not c['actors'][target]['packet'] or kind=='nearest' and o['primary'] is None:return out
 count=max(0,o.get('setCount',8));ignore=o.get('ignoreAssigned',False)
 if ignore and o.get('indexCallback',True):
  for i in range(count):
   owner=out['owners'][i]
   if owner in [128,255]:continue
   ix=r.find(c,owner);selected=255
   if ix>=0 and c['actors'][ix]['packet'] and c['actors'][ix]['selected'] is not None:selected=c['actors'][ix]['selected']&255
   if selected!=indices[i]:out['owners'][i]=255
 def candidate(i,cull=True):
  if ignore and out['owners'][i]!=255:return False
  if cull and o['radius']!=0 and not v.outside(dict(o,point=o['positions'][indices[i]])):return False
  return True
 index=-1
 if kind=='random':
  limit=v.f(o['range']*o['range']) if o['range']>0 else v.f(3.4028234663852886e38)
  eligible=sum(candidate(i) and distance(o['primary'],o['positions'][indices[i]])<=limit for i in range(count))
  if eligible:
   out['random']=(out['random']*0x19660d+0x3c6ef35f)&0xffffffff;choice=out['random']%eligible;ordinal=0
   for i in range(count):
    if candidate(i,False) and distance(c['actors'][target]['position'],o['positions'][indices[i]])<=limit:
     if ordinal==choice:index=i;break
     ordinal+=1
 elif kind=='nearest':
  best=v.f(o['range']*o['range']) if o['range']>0 else v.f(3.4028234663852886e38)
  for i in range(count):
   if not candidate(i):continue
   d=distance(o['primary'],o['positions'][indices[i]])
   if d<best:best=d;index=i
   if o['secondary'] is not None:
    d=distance(o['secondary'],o['positions'][indices[i]])
    if d<best:best=d;index=i
 else:
  best=0.
  for i in range(count):
   if not candidate(i):continue
   d=distance(o['primary'],o['positions'][indices[i]])
   if d<=best:continue
   if o['secondary'] is not None:
    other=distance(o['secondary'],o['positions'][indices[i]])
    if other<=best:continue
    d=min(d,other)
   if o['range']==0 or d<o['range']*o['range']:best=d;index=i
 if index>=0:out['selected'][target]=indices[index];out['owners'][index]=c['actors'][target]['ownerId']
 return out

def run(kind,options={}):
 global memory
 o=defaults(options);c=r.case_context(dict(o,primary=o.get('primaryPlayer',1)));indices,owners=r.setup(c,[],o)
 for i,p in enumerate(o['positions']):n.pack('<3f',r.LOC+i*0x3c+0x10,*p)
 if o['primary'] is not None:n.pack('<3f',P,*o['primary'])
 if o['secondary'] is not None:n.pack('<3f',S,*o['secondary'])
 n.pack('<16f',0x806680,*o['object']);n.pack('<16f',0x80b708,*o['view']);n.pack('<16f',0x80b988,*o['planes']);n.pack('<2f',0x973730,o['near'],o['far']);n.pack('<I',0x95e5d4,o['random'])
 want=model(c,o,indices,owners,kind);regions=[(a.ACT,8*0x10d8),(r.OWN,len(owners)),(r.PK,8*0x100),(r.LOC,len(o['positions'])*0x3c),(P,32),(0x806680,64),(0x80b708,64),(0x80b988,64)];expected=[bytearray(n.read(p,z)) for p,z in regions]
 for i in range(8):struct.pack_into('<I',expected[2],i*0x100+0xa4,0 if want['selected'][i] is None else r.LOC+want['selected'][i]*0x3c)
 expected[1][:]=bytes(want['owners']);args=[a.SYS,r.SET if o.get('set',True) else 0,a.actor(o.get('target',0)) if o.get('actor',True) else 0,v.bits(o['range']),P if o['primary'] is not None else 0]
 if kind!='random':args.append(S if o['secondary'] is not None else 0)
 args +=[v.bits(o['radius']),int(o.get('ignoreAssigned',False))];n.call({'nearest':0x51fef0,'farthest':0x520080,'random':0x520220}[kind],args)
 got=dict(selected=[None if n.unpack('<I',r.PK+i*0x100+0xa4)[0]==0 else (n.unpack('<I',r.PK+i*0x100+0xa4)[0]-r.LOC)//0x3c for i in range(8)],owners=list(n.read(r.OWN,len(owners))),random=n.unpack('<I',0x95e5d4)[0]);bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 for i,(p,z) in enumerate(regions):
  memory+=1
  if n.read(p,z)!=expected[i]:bad.append(dict(region=i))
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 rows.append(dict(kind=kind,options=o,context=c,indices=indices,owners=owners,native=got));groups[kind]=groups.get(kind,0)+1

def main():
 for kind in ['nearest','farthest','random']:
  for ran in [-5.,0.,1.,2.,5.,20.]:
   for secondary in [None,[15.,0.,0.]]:
    for radius in [-1.,0.,1.,20.]:
     for ignore in [False,True]:run(kind,dict(range=ran,secondary=secondary,radius=radius,ignoreAssigned=ignore))
  for gate in [{'set':False},{'actor':False},{'reservationOverrides':{'0':{'packet':False}}},{'setCount':0},{'setCount':-128}]:run(kind,gate)
  for positions in [[[0.,0.,0.]]*16,[[1.,0.,0.]]*16,[[v.f(1+2**-23),0.,0.]]*16]:
   for ran in [1.,v.f(1+2**-23),0.]:run(kind,dict(positions=positions,range=ran,owners=[255]*8))
 run('nearest',dict(primary=None))
 rng=random.Random(520220)
 for i in range(900):
  count=rng.randrange(1,16);points=[[v.f(rng.uniform(-20,20)) for _ in range(3)] for _ in range(16)]
  options=dict(setCount=count,indices=[rng.randrange(16) for _ in range(count)],owners=[rng.choice([0,1,7,128,255]) for _ in range(count)],positions=points,target=rng.randrange(8),primary=[v.f(rng.uniform(-10,10)) for _ in range(3)],secondary=None if i%2 else [v.f(rng.uniform(-10,10)) for _ in range(3)],range=v.f(rng.uniform(-10,30)),radius=rng.choice([0.,1.,5.]),ignoreAssigned=bool(i%2),random=rng.randrange(2**32),reservationOverrides={str(j):dict(ownerId=rng.randrange(256),selected=rng.choice([None]+list(range(16)))) for j in range(8)})
  run(['nearest','farthest','random'][i%3],options)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,examples=errors[:8],method='Original selectors, reservation cleanup/index callback, distance scratch routine, sphere culling and both matrix helpers execute unchanged. Actual integer LCG state retained. Complete actor/owner/packet/locator/reference/camera input regions compared.',limits=['Valid finite prepared world, locators, actor packet, view matrices and reference vectors. Float32 distance/range-square outputs stay finite.','Farthest/random require primary vector on active candidates; nearest has native null-primary gate.','No authored command credit until dispatcher integration; managed replay pending.'])
 (B/'reports/native-locator-selection-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-locator-selection-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
