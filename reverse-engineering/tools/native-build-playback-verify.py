import importlib.util,json,struct,gzip,hashlib,itertools,random,copy,math
from pathlib import Path
s=importlib.util.spec_from_file_location('playback',Path(__file__).with_name('native-sound-playback-verify.py'));p=importlib.util.module_from_spec(s);s.loader.exec_module(p);n=p.n;b=p.b;d=p.d;g=p.g;B=p.B;D=p.D
b.REGIONS=sorted(b.REGIONS+[(0x951000,4)]);EFFECT=p.POSITION-0x30;NAMES=D+0x63000
SINE=(B/'references/native-animation-sine-table.f32').read_bytes();SINEWORDS=list(struct.unpack('<32768I',SINE));n.write(0x29899a0,SINE)
base_mutate=p.mutate
def mutation(m,o):
 base_mutate(m,o)
 if o['mutation']!='none':m.put(0x951000,p.bits(-1))
p.mutate=mutation

def options(**kw):
 o=p.options();o.update(dict(cooldown=0,velocity=[p.bits(.25),0,0],head=0,heads=True,names=['LegoSingle','other','LEGOSINGLE'],next=[1,2,-1]));o.update(copy.deepcopy(kw));return o
def setup(o):
 m=p.setup(o);m.put(0x951000,o['cooldown']);m.write(EFFECT+0x80,struct.pack('<3I',*o['velocity']));position=o['position'] or [p.bits(1),p.bits(2),p.bits(3)];m.write(p.POSITION,struct.pack('<3I',*position));m.put(0x292fda0,d.HEADS if o['heads'] else 0);m.write(d.HEADS,struct.pack('<256h',*([o['head']]*256)))
 for i,name in enumerate(o['names']):m.put(d.RECORDS+i*64,NAMES+i*256 if name is not None else 0);g.half(m,d.RECORDS+i*64+0x10,o['next'][i]);m.text(NAMES+i*256,name or '')
 return m
def model(m,o):
 if not p.flt(o['cooldown'])<=0:return [],None
 x,y,z=map(p.flt,o['velocity']);squared=p.q.store(p.v.add(p.v.add(p.v.mul(y,y),p.v.mul(x,x)),p.v.mul(z,z)));speed=p.flt(p.bits(math.sqrt(squared)))
 if not speed>0:return [],None
 index=int(p.v.add(p.v.mul(p.v.add(1,-min(speed,1.)),16384),16384));volume=SINEWORDS[(index>>1)&32767];id=g.find(m,'LegoSingle') if o['heads'] else -1;play=copy.deepcopy(o);play.update(id=id,position=list(struct.unpack('<3I',m.read(p.POSITION,12))),volume=volume,scale=p.bits(1));ev=p.model(m,play);m.put(0x951000,0x3dcccccd);return ev,dict(id=id,volume=volume)
def main():
 rows=[];errors=[];rng=random.Random(0x571ba0);cases=[]
 for cooldown,head,heads,speed,mutation in itertools.product([0,0x80000000,p.bits(-1),p.bits(.1),0x7fc12345],[-1,0,1,2],[False,True],[0.,.25,1.,1.5],['none','restore']):cases.append(options(cooldown=cooldown,head=head,heads=heads,velocity=[p.bits(speed),0,0],mutation=mutation))
 for seed,flags,head,mutation in itertools.product([0,1,2,0xffffffff],[0,0x8000,0x400000,0x40000],[0,2],['none','restore','clear-distance','redirect']):
  records=[p.record(group=0,flags=0x10000,priority=7),p.record(bank=3,flags=flags,near=1,far=30,pitchRandom=.5,volumeRandom=-.5),p.record(bank=4,flags=flags,near=2,far=20,pitchRandom=.25,volumeRandom=-.25)];cases.append(options(records=records,seed=seed,head=head,mutation=mutation,position=[p.bits(1),p.bits(2),p.bits(3)],velocity=[p.bits(.4),p.bits(.3),0]))
 for exp in [-149,-126,-100,-75,-50,-25,-10,-1,0]:cases.append(options(velocity=[p.bits(2.**exp),0,0]))
 for i in range(256):cases.append(options(velocity=[p.bits(rng.uniform(-.9,.9)) for _ in range(3)],head=i%3,seed=rng.getrandbits(32),position=[p.bits(rng.uniform(-30,30)) for _ in range(3)]))
 for index,o in enumerate(cases):
  m=setup(o);g.load(m);n.pack('<I',0x29a9c48,0);want,call=model(m,o);native_options=copy.deepcopy(o);native_options['position']=list(struct.unpack('<3I',n.read(p.POSITION,12)));p.current=native_options;p.events=[];n.call(0x571ba0,[EFFECT],count=1000000);actual=g.capture();bad=[]
  if p.events!=want:bad.append(dict(events=p.events,want=want))
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(dict(address=hex(a+i),got=actual.r[a][i],want=value) for i,value in enumerate(data) if actual.r[a][i]!=value)
   bad.append(dict(differences=diffs[:15]))
  if bad:errors.append(dict(index=index,input=o,bad=bad))
  rows.append(dict(input=o,nativeSha=actual.sha(),events=p.events,playback=call))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),effectPlaybackCalls=sum(r['playback'] is not None for r in rows),backendCalls=sum(len(r['events']) for r in rows),bytesComparedPerCase=sum(z for a,z in b.REGIONS),examples=errors[:2],method='Original571ba0 calls real speed/sqrt, hash/lookup,681eb0,650f20, group/random/context/listener/vector helpers and exact preserved sine table. Only final audio-device calls are mutable services. Complete prepared image and raw backend argument/position/range/random observations compare; callback always rewrites cooldown after an attempted sound.',limits=['Finite velocity and squared speed, numeric domain inherited from sound playback; cooldown additionally permits quietNaN because it gates without arithmetic. Valid typed registry/effect snapshots correspond to owned byte image, and disjoint position/record storage.','This is zero-new-address composition evidence; direct helpers and earlier standalone cases are not recounted. Native audio device and resource loading remain outside scope.','Managed bridge restores the host Play delegate after the synchronous callback and synchronizes position/cooldown values; no managed execution claimed.'])
 (B/'reports/native-build-playback-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-build-playback-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,table=d.TABLEWORDS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
