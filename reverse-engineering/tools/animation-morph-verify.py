"""Exact original legacy morph scalar, single/blended weights and packet branch."""
from pathlib import Path
import importlib.util,struct,random,json,hashlib,base64,gzip,collections,time
s=importlib.util.spec_from_file_location('morph_fixture',Path(__file__).with_name('animation-morph-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f);B=f.B;o=f.Oracle();rng=random.Random(0x5d3dc0);started=time.time();clips=[];sources=[];cases=[];errors=[];counts=collections.Counter();mismatches=0
def sha(b):return hashlib.sha256(b).hexdigest()
def rows(values):return None if values is None else[[f.bits(v)for v in row]for row in values]
def check(kind,inputs,want,got):
 global mismatches
 counts[kind]+=1
 if want!=got:
  mismatches+=1
  if len(errors)<12:errors.append({'kind':kind,'input':inputs,'expected':want,'native':got})
 cases.append({'kind':kind,'input':inputs,'native':got})
def synthetic(seed):
 nodes=1+seed%4;channels=1+seed%7;count=nodes*channels;raw=bytearray(48+5*count+nodes);base=0x16000000;types=48+4*count;flags=types+count
 struct.pack_into('<III',raw,0,2,base,base+16);struct.pack_into('<fhhh',raw,16,1. if seed<8 else 70.,nodes,channels,1 if seed<8 else 3);struct.pack_into('<III',raw,28,base+48,base+types,base+flags)
 def append(blob):at=len(raw);raw.extend(blob);return at
 for i in range(count):
  kind=0 if seed<8 else(seed+i)%3;raw[types+i]=kind
  if kind==0:struct.pack_into('<f',raw,48+4*i,rng.choice([-0.,0.,f.f32(rng.uniform(-5,5))]));continue
  times=[1,10,32,33,50,65,70];descriptor=append(bytes(12));struct.pack_into('<I',raw,48+4*i,base+descriptor);keys=b''
  if kind==1:
   for j,t in enumerate(times):keys+=struct.pack('<4f',float(t),f.f32(1/(times[j+1]-t))if j+1<len(times)else 0.,f.f32(rng.uniform(-10,10)),f.f32(rng.uniform(-1,1)))
  else:
   keys=struct.pack('<ff',f.f32(rng.uniform(-.02,.02)),f.f32(rng.uniform(-.001,.001)))
   for t in times:keys+=struct.pack('<hbB',rng.randrange(-32768,32768),rng.randrange(-128,128),t-1)
  keydata=append(keys);masks=[sum(1<<((t-1)%32)for t in times if(t-1)//32==j)for j in range(3)];offsets=[sum(m.bit_count()for m in masks[:j])for j in range(3)];ma=append(struct.pack('<3I',*masks));off=append(struct.pack('<3H',*offsets));struct.pack_into('<3I',raw,descriptor,base+ma,base+off,base+keydata)
 return bytes(raw)
for seed in range(120):clips.append(f.Clip(synthetic(seed)));sources.append({'synthetic':seed})
inventory=json.loads((B/'reports/animation-bsa-export.json').read_text())['success']
for row in inventory:
 raw=(B/'extracted'/row['path']).read_bytes();assert sha(raw)==row['sha256'];clips.append(f.Clip(raw,row['headerOffset'],row['originalPointerBase']));sources.append({'path':row['path'],'sha256':row['sha256']})
for ci,c in enumerate(clips):
 frames=[0.,1.,f.f32(1+(c.duration-1)*.317),f.f32(1+(c.duration-1)*.731),c.duration,f.f32(c.duration+10)]
 for frame in frames:
  layers=list(range(c.nodes))+[c.nodes];want=rows(f.single(c,frame,layers));got=o.evaluate(c,frame,layers);check('single',{'clip':ci,'frame':f.bits(frame),'layers':layers},want,got)
 for frame in[0.,c.duration,f.f32(c.duration+.125)]:
  t=c.time(frame);want=[f.bits(t[0]),f.bits(t[1]),*t[2:]];defined=[0,2,3,4]if c.duration==1 and frame>=1 else list(range(6));got=o.get_time(c,frame)
  check('time',{'clip':ci,'frame':f.bits(frame),'defined':defined},[want[i]for i in defined],[got[i]for i in defined])
 if ci<120 and c.duration>1:
  for frame in[9.999,10.,10.001,31.999,32.,32.001,33.,64.,65.,69.999]:
   frame=f.f32(frame);check('single',{'clip':ci,'frame':f.bits(frame),'layers':None},rows(f.single(c,frame,None)),o.evaluate(c,frame,None))
 for index in range(c.nodes*c.channels):
  if c.raw[c.types+index]:
   frame=f.f32(1+(c.duration-1)*.537);check('scalar',{'clip':ci,'curve':index,'frame':f.bits(frame)},f.bits(c.sample(index,c.time(frame))),o.scalar(c,index,frame))
 if ci%400==0:print(ci,'clips',mismatches,'mismatches',flush=True)
for i in range(2500):
 ai=rng.randrange(len(clips));bi=rng.randrange(len(clips));a=clips[ai];b=clips[bi];af=f.f32(rng.uniform(-2,a.duration+5));bf=f.f32(rng.uniform(-2,b.duration+5));weight=f.f32(rng.choice([0.,-0.,1.,.5,-.5,1.5,1e-18,rng.random()]));layers=rng.choice([None,[],[0],[0,1,3,7],[2,0,2]])
 if i%5==0:a=None;ai=None
 if i%7==0:b=None;bi=None
 check('blend',{'source':ai,'target':bi,'sourceFrame':f.bits(af),'targetFrame':f.bits(bf),'weight':f.bits(weight),'layers':layers},rows(f.blend(a,af,b,bf,weight,layers)),o.evaluate(a,af,layers,b,bf,weight,True))
for i in range(1400):
 ids=[rng.randrange(len(clips))if rng.randrange(3)else None for _ in range(3)];selected=[None if j is None else clips[j]for j in ids];packet=bytearray(72);packet[49]=rng.choice([0,1,255]);a=rng.randrange(-1,4);b=rng.randrange(-1,4);current=rng.randrange(-1,4);struct.pack_into('<3h',packet,50,a,b,current);af=f.f32(rng.uniform(1,50));bf=f.f32(rng.uniform(1,50));frame=f.f32(rng.uniform(1,50));weight=f.f32(rng.uniform(-.2,1.2));struct.pack_into('<6f',packet,0,frame,0.,weight,1.,af,bf);layerCount=rng.choice([0,1,2,4,8]);mask=rng.choice([0,1,2,7,0xffffffff]);layers=[j for j in range(layerCount)if mask&(1<<j)];valid=lambda k:0<=k<3 and selected[k]is not None
 if not layers:want={'untouched':True,'rows':None}
 else:
  result=None
  if packet[49]:
   if valid(a)and valid(b):result=f.blend(selected[a],af,selected[b],bf,weight,layers)
   elif valid(b):result=f.single(selected[b],bf,layers)
   elif valid(a):result=f.single(selected[a],af,layers)
  elif valid(current):result=f.single(selected[current],frame,layers)
  want={'untouched':False,'rows':rows(result)}
 check('packet',{'clips':ids,'packet':packet.hex(),'layerCount':layerCount,'mask':mask},want,o.packet(bytes(packet),selected,layerCount,mask))
for clip in[None,clips[0]]:
 for layers in[None,[],[0]]:check('single',{'clip':None if clip is None else 0,'frame':f.bits(1.),'layers':layers},rows(f.single(clip,1.,layers)),o.evaluate(clip,1.,layers))
out=B/'reports/animation-morph-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps({'binarySha256':o.n.sha256,'clips':[{'source':source,'raw':base64.b64encode(c.raw).decode()}for source,c in zip(sources,clips)],'cases':cases},separators=(',',':')).encode(),mtime=0));report={'binarySha256':o.n.sha256,'comparisons':len(cases),'counts':dict(counts),'mismatches':mismatches,'examples':errors,'authoredCarriers':len(inventory),'syntheticCarriers':120,'fixture':{'path':out.relative_to(B).as_posix(),'bytes':out.stat().st_size,'sha256':sha(out.read_bytes())},'elapsedSeconds':time.time()-started};(B/'reports/animation-morph-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not mismatches
