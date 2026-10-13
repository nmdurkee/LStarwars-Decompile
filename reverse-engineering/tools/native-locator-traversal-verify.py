import importlib.util,json,copy,random,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('reserve',Path(__file__).with_name('native-locator-reservations-verify.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r);a=r.a;n=r.n;B=r.B
from unicorn.x86_const import UC_X86_REG_EDI
rows=[];errors=[];groups={};memory=0

def model(c,o,indices,owners):
 out=dict(selected=[x['selected'] for x in c['actors']],owners=owners[:],flags=[x['state'][1] for x in c['actors']],random=o.get('random',12345))
 if not o.get('set',True) or o.get('setCount',8)<=1 or not o.get('actor',True):return out
 if o.get('ignoreAssigned',False) and o.get('indexCallback',True):
  for i in range(o.get('setCount',8)):
   owner=out['owners'][i]
   if owner in [128,255]:continue
   ix=r.find(c,owner);selected=255
   if ix>=0 and c['actors'][ix]['packet'] and c['actors'][ix]['selected'] is not None:selected=c['actors'][ix]['selected']&255
   if selected!=indices[i]:out['owners'][i]=255
 ix=o.get('target',0);actor=c['actors'][ix];count=o.get('setCount',8);index=count;direction=-1 if actor['state'][1]&0x100000 else 1
 if actor['selected'] is not None:
  for i in range(count):
   if indices[i]==actor['selected']:out['owners'][i]=255;index=i;break
 if index==count:out['random']=(out['random']*0x24cd+1)&65535;index=out['random']//(65535//count+1)
 start=index;returns=0
 for step in range(1000):
  index+=direction
  if index>=count:
   if o.get('finishAtEnd',False):out['selected'][ix]=None;return out
   if o.get('looping',False):index=0
   else:index=count-2;direction=-1;out['flags'][ix]|=0x100000
  elif index<0:
   if o.get('looping',False):index=count-1
   else:index=1;direction=1;out['flags'][ix]&=0xffefffff
  if index==start:
   if o.get('looping',False):break
   returns+=1
   if returns>=2:break
  elif not o.get('ignoreAssigned',False) or out['owners'][index]==255:break
 else:raise RuntimeError('model cycle limit')
 out['selected'][ix]=indices[index];out['owners'][index]=actor['ownerId'];return out

def run(o):
 global memory
 c=r.case_context(o);indices,owners=r.setup(c,[],o);n.pack('<I',0x80253c,o.get('random',12345));want=model(c,o,indices,owners)
 regions=[(a.ACT,8*0x10d8),(r.OWN,len(owners)),(r.PK,8*0x100)]
 expected=[bytearray(n.read(p,z)) for p,z in regions]
 for i in range(8):struct.pack_into('<I',expected[0],i*0x10d8+0x1fc,want['flags'][i]);struct.pack_into('<I',expected[2],i*0x100+0xa4,0 if want['selected'][i] is None else r.LOC+want['selected'][i]*0x3c)
 expected[1][:]=bytes(want['owners'])
 n.call(0x440660,[a.SYS,r.SET if o.get('set',True) else 0,int(o.get('looping',False)),int(o.get('finishAtEnd',False)),int(o.get('ignoreAssigned',False))],{UC_X86_REG_EDI:a.actor(o.get('target',0)) if o.get('actor',True) else 0})
 got=dict(selected=[None if n.unpack('<I',r.PK+i*0x100+0xa4)[0]==0 else (n.unpack('<I',r.PK+i*0x100+0xa4)[0]-r.LOC)//0x3c for i in range(8)],owners=list(n.read(r.OWN,len(owners))),flags=[n.unpack('<I',a.actor(i)+0x1fc)[0] for i in range(8)],random=n.unpack('<I',0x80253c)[0])
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 for i,(p,z) in enumerate(regions):
  memory+=1
  if n.read(p,z)!=expected[i]:bad.append(dict(region=i))
 if bad:errors.append(dict(options=o,bad=bad))
 rows.append(dict(kind='next',options=o,context=c,indices=indices,owners=owners,native=got));groups['next']=groups.get('next',0)+1

def lookup(names,name,count,system):
 global memory
 n.write(a.D,bytes(0x1000));array=a.D+0x90000;text=a.D+0x91000;n.write(array,bytes(0x1000));n.pack('<iI',a.SYS+0x2c,count,array)
 for i,s in enumerate(names):assert len(s)<16;n.write(array+i*0x1c,s.encode('latin1')+b'\0')
 n.write(text,name.encode('latin1')+b'\0');want=next((i for i,s in enumerate(names[:max(0,count)]) if s.split('\0')[0].lower()==name.split('\0')[0].lower()),-1) if system else -1
 before=n.read(array,0x1000);ptr=n.call(0x51ac70,[a.SYS if system else 0,text]);got=(ptr-array)//0x1c if ptr else -1;memory+=1
 if got!=want or before!=n.read(array,0x1000):errors.append(dict(kind='find',names=names,name=name,count=count,got=got,want=want))
 rows.append(dict(kind='find',names=names,name=name,count=count,system=system,native=got));groups['find']=groups.get('find',0)+1

def main():
 for count in [-128,-1,0,1,2,3,8,127]:
  for selected in [None,0,1,count-1,255]:
   for flags in [0x1001,0x101001]:
    for looping in [False,True]:
     for finish in [False,True]:
      for ignore in [False,True]:
       run(dict(setCount=count,indices=list(range(max(8,count))),owners=[128]*max(8,count),looping=looping,finishAtEnd=finish,ignoreAssigned=ignore,reservationOverrides={'0':dict(selected=selected,ownerId=255)},actorOverrides={'0':dict(active=flags)}))
 for opts in [{'set':False},{'actor':False},{'indexCallback':False}]:
  for ignore in [False,True]:run(dict(opts,ignoreAssigned=ignore))
 rng=random.Random(440660)
 for j in range(400):
  count=rng.randrange(2,20);run(dict(setCount=count,indices=[rng.randrange(12) for _ in range(count)],owners=[rng.choice([0,1,2,3,7,128,255]) for _ in range(count)],target=rng.randrange(8),looping=bool(rng.randrange(2)),finishAtEnd=bool(rng.randrange(2)),ignoreAssigned=bool(rng.randrange(2)),random=rng.randrange(2**32),reservationOverrides={str(i):dict(selected=rng.choice([None]+list(range(13))),ownerId=rng.randrange(256)) for i in range(8)},actorOverrides={str(i):dict(active=rng.choice([1,0x1001,0x101001])) for i in range(8)}))
 for names in [[],['Alpha'],['Alpha','ALPHA','Beta','target'],['','Space name','a_b']]:
  for name in ['', 'alpha','BETA','missing','target','space NAME','a_b','xxalpha','ALPHA\0tail']:
   for count in [-1,0,len(names)]:
    for system in [False,True]:lookup(names,name,count,system)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,examples=errors[:10],method='Original next-locator routine with native EDI actor convention, actual reservation callback/cleanup and shared QRandom; original set lookup and string comparison. No helper replacements.',limits=['Valid attached actor packet for active traversal; signed set count and byte indices/owners with backing arrays.','Finite locator pointer identities and no address wrap; name lookup uses terminated ASCII inline names.','No new authored command credit until GetLocatorFromSet orchestration is recovered; managed execution remains pending.'])
 (B/'reports/native-locator-traversal-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-locator-traversal-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
