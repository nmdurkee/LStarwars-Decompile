import importlib.util,json,struct,copy,itertools,gzip
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
g=load('graph','native-graph-actor-verify.py');e=load('effects','native-build-failure-verify.py');q=g.q;n=e.m.NativeX86();B=e.B;D=n.DATA;g.n=q.n=e.n=n;e.D=D+0x60000;e.OBJ=e.D;e.GROUP=e.D+0x100;e.NODES=e.D+0x200;e.DESCS=e.D+0x1000;e.EFFECTS=e.D+0x4000
from unicorn import UC_HOOK_CODE
originalNames=copy.deepcopy(q.names);rows=[];errors=[];fallbackCalls=0;allocations=0
for address in [0x558770,0x558780,q.SERVICE]:n.mu.hook_add(UC_HOOK_CODE,q.observe,begin=address,end=address)
for address in [0x41f6d0,0x414c50,0x4882d0,0x55f450]:n.mu.hook_add(UC_HOOK_CODE,g.observe,begin=address,end=address)
n.mu.hook_add(UC_HOOK_CODE,g.observe,begin=0x4648e0,end=0x464ad1)
n.mu.hook_add(UC_HOOK_CODE,e.observe,begin=0x64d270,end=0x64d270)
def observe(mu,address,size,user):
 global fallbackCalls
 fallbackCalls+=1
n.mu.hook_add(UC_HOOK_CODE,observe,begin=0x590690,end=0x590690)
def run(tokens,inputs=None,effects=None,source=None):
 global allocations
 go=g.options(inputs or {});go['tokens']=tokens;eo=e.options(effects or {});q.names=copy.deepcopy(originalNames);names=[]
 for raw in tokens:
  token=raw.split('\0')[0];low=token.lower()
  if 'name=' in low or low in ['true','false'] or 'buildit=' not in low:continue
  name=token[low.index('buildit=')+8:]
  if len(name)<16 and name not in names:names.append(name)
 for i,name in enumerate(names[:3]):q.names[0][i]=name
 g.setup(go);e.setup(eo)
 for typ in range(5):
  for i in range(4):n.pack('<I',g.obj(typ,i)+0x10,e.GROUP if eo['group'] else 0)
 beforeGraph=n.read(D,0x50000);beforeEffects=n.read(e.D,0x5000);wantGraph=g.model(go)
 if wantGraph is None:raise RuntimeError('Unexpected unsafe graph fixture')
 calls=sum(event[0]=='effects' for event in wantGraph['events']);wantGraph['events']=[event for event in wantGraph['events'] if event[0]!='effects'];wantEffects=e.model('create',dict(eo,present=bool(calls)),0,0,0);beforeCalls=fallbackCalls
 n.call(0x4648e0,[g.GIT,0,g.ARGS,len(tokens)]);gotGraph=dict(events=copy.deepcopy(q.events),players=[g.aid(p) for p in n.unpack('<II',0x93d7f0)],world=go['world'],flags=[n.unpack('<I',g.actor(i)+0x1fc)[0] for i in range(3)],changedSpawn=None,changedPlacement=None);gotEffects=dict(events=copy.deepcopy(e.events),state=e.capture(),result=None);got=dict(graph=gotGraph,effects=gotEffects);want=dict(graph=wantGraph,effects=wantEffects);allocations+=len(e.events);expectedEffects=bytearray(beforeEffects)
 for i in range(3):struct.pack_into('<I',expectedEffects,e.node(i)-e.D,e.node(wantEffects['state']['next'][i]));struct.pack_into('<16I',expectedEffects,e.DESCS+i*0x100+0x40-e.D,*wantEffects['state']['matrices'][i]);struct.pack_into('<I',expectedEffects,e.effect(i)+0x100-e.D,wantEffects['state']['lifetimes'][i])
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x50000)!=beforeGraph or n.read(e.D,0x5000)!=bytes(expectedEffects):bad.append('Complete persistent image differs')
 if fallbackCalls-beforeCalls!=calls:bad.append(dict(actualFallbacks=fallbackCalls-beforeCalls,expected=calls))
 if bad:errors.append(dict(graphOptions=go,effectOptions=eo,bad=bad))
 rows.append(dict(graphOptions=go,effectOptions=eo,names=copy.deepcopy(q.names),native=got,source=source))
def main():
 for success,count,group,mutation,alloc in itertools.product([False,True],[0,1,3],[False,True],['none','template','origin-local','origin-global','skip','stop','matrix','random'],[[-1],[0,1,0]]):run(['buildit=alpha','name=beta'],dict(success=success),dict(count=count,group=group,mutation=mutation,allocations=alloc))
 for tokens in [[],['name=alpha'],['buildit=alpha'],['buildit=alpha','buildit=absent','name=alpha'],['buildit=beta','name=alpha','FALSE'],['name=alpha','FALSE','buildit=gamma','TRUE'],['buildit=alphaNAME=beta'],['buildit=','name=']]:run(tokens,dict(success=False))
 uses=next(r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name']=='ActivateChar' and r['kind']=='git-action')
 for source in uses:
  for success in [False,True]:run(source['args'],dict(success=success),source=source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),fullRegionComparisons=len(rows)*2,checkedBytes=len(rows)*(0x50000+0x5000),fallbackCalls=fallbackCalls,allocationCalls=allocations,authoredGraphLists=len(uses),additionalAuthoredUseCredit=0,additionalNativeMappings=0,examples=errors[:3],method='Original4648e0 executes through actual55f450,scenery lookup,590690 effect producer and54fa60 RNG. Named lifecycle and player release remain graph services; only64d270 allocation remains adapted inside the fallback. Exact graph service/name trace and complete effect requests/state plus340KiB persistent memory compare per chain.',limits=['Prepared physical buildit group links. Up to3 parsed short buildit names (<16 ASCII bytes) are made available in real name buckets; longer authored names remain absent in this bounded runtime scene. All134 authored token lists execute twice, without new authored-use credit.','Named41f6d0/414c50 and release4882d0 are explicit services here; separate graph-lifecycle evidence composes their recovered bodies. This batch specifically closes590690 fallback.','Effect allocator is mutable and may change template/time, local/global origin, next links, matrices and RNG. Callback lifetime/sound simulation after creation is outside this chain. Managed execution pending.'])
 (B/'reports/native-graph-build-failure-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-graph-build-failure-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
