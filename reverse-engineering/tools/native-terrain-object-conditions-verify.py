import importlib.util,json,struct,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
WORLD=D;SCENE=D+0x4000;STATIC=D+0x5000;INST=D+0x6000;DISPLAY=D+0x8000;DYNAMIC=D+0x9000;TEXT=D+0xa000;REFERENCE=D+0xb000;TERR=D+0x10000;RECORDS=D+0x20000;TRANSFORMS=D+0x24000;PLAYER=D+0x30000;OUT=D+0x32000
ADDR={'index':0x5cffb0,'terrain':0x67c760,'bind':0x4418c0,'condition':0x441910};rows=[];errors=[];groups={};memory=0;excluded=0
names=['Alpha','Beta','alpha','Gamma']
def options(o):
 p=dict(terrain=True,scene=True,dynamic=False,sceneCount=4,instanceCount=4,terrainCount=8,instanceIds=[2,0,1,-1],dynamicIds=[2,0,-1,32767],sceneIds=[2,0,2,-1,32767,-32768,3,1],transforms=[True,True,True,True,False,True,True,True],heights=[0.,1.,2.,3.,4.,5.,6.,7.],referenceKind='static',referenceIndex=0,name='Alpha',index=2,primary=True,ground281=1,ground282=0,groundIndex=0,bound=0,y=1.);p.update(o);return p
def setup(o):
 n.write(D,bytes(0x33000));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x13c,SCENE if o['scene'] else 0);n.pack('<I',0x292fc68,TERR if o['terrain'] else 0);n.pack('<I',0x97388c,0);n.pack('<I',0x93d810,PLAYER if o['primary'] else 0)
 n.pack('<iI',SCENE+0x24,o['sceneCount'],STATIC);n.pack('<iI',SCENE+0x1c,o['instanceCount'],INST);n.pack('<I',SCENE+0x110,DISPLAY if o['dynamic'] else 0);n.pack('<iI',DISPLAY+0x6c,o['sceneCount'],DYNAMIC)
 for i,name in enumerate(names):
  n.write(TEXT+i*128,name.encode()+b'\0');n.pack('<II',STATIC+i*0x4c+0x40,INST+o['instanceIds'][i]*0x50 if o['instanceIds'][i]>=0 else 0,TEXT+i*128);n.pack('<I',DYNAMIC+i*0xd0+0xb4,TEXT+i*128);n.pack('<i',DYNAMIC+i*0xd0+0xc0,o['dynamicIds'][i])
 n.pack('<I',TERR+0x68,RECORDS);n.pack('<i',TERR+0xa48c,o['terrainCount'])
 for i in range(8):n.pack('<I',RECORDS+i*0x6c+0x40,TRANSFORMS+i*0x50 if o['transforms'][i] else 0);n.pack('<h',RECORDS+i*0x6c+0x4a,o['sceneIds'][i]);n.pack('<f',TRANSFORMS+i*0x50+0x34,o['heights'][i])
 kind=o['referenceKind'];i=o['referenceIndex'];n.pack('<III',REFERENCE,SCENE,STATIC+i*0x4c if kind=='static' else 0,DYNAMIC+i*0xd0 if kind=='dynamic' else 0)
 n.pack('<h',PLAYER+0x27e,o['groundIndex']);n.pack('<BB',PLAYER+0x281,o['ground281'],o['ground282']);n.pack('<f',PLAYER+0x60,o['y'])
 if o['name'] is not None:n.write(TEXT+0x400,o['name'].encode()+b'\0')
def scene_index(o,kind,i):
 if kind=='none':return -1
 if kind=='dynamic':return o['dynamicIds'][i]
 identity=o['instanceIds'][i];return identity if 0<=identity<o['instanceCount'] else -1
def terrain_index(o,index):
 if index==-1:return -1
 return next((i for i in range(max(0,o['terrainCount'])) if o['transforms'][i] and o['sceneIds'][i]==index),-1)
def run(kind,inputs=None,source=None):
 global memory,excluded
 o=options(inputs or {})
 if kind=='terrain' and not o['terrain'] and o['index']!=-1:excluded+=1;return
 if kind=='condition' and o['primary'] and o['bound']!=-1 and (o['ground281'] or o['ground282']) and o['groundIndex']==o['bound'] and (not o['terrain'] or o['groundIndex']<0 or o['groundIndex']>=8 or not o['transforms'][o['groundIndex']]):excluded+=1;return
 setup(o);before=n.read(D,0x32000)
 if kind=='index':got=n.call(ADDR[kind],[REFERENCE]);want=scene_index(o,o['referenceKind'],o['referenceIndex'])
 elif kind=='terrain':got=n.call(ADDR[kind],[o['index']&0xffffffff]);want=terrain_index(o,o['index'])
 elif kind=='bind':
  got=n.call(ADDR[kind],[0,TEXT+0x400 if o['name'] is not None else 0]);which=next((i for i in range(max(0,o['sceneCount'])) if names[i].lower()==o['name'].split('\0')[0].lower()),-1) if o['name'] is not None and o['scene'] and o['terrain'] else -1;want=terrain_index(o,scene_index(o,'dynamic' if o['dynamic'] else 'static',which)) if which>=0 else -1
 else:
  n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(ADDR[kind],[0,0,0,0,o['bound']&0xffffffff]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT)[0];yes=o['primary'] and o['bound']!=-1 and (o['ground281'] or o['ground282']) and o['groundIndex']==o['bound'] and o['heights'][o['groundIndex']]<=o['y'];want=0x3f800000 if yes else 0
 if kind!='condition':got=struct.unpack('<i',struct.pack('<I',got))[0]
 bad=[];memory+=1
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x32000)!=before:bad.append('input memory changed')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 rows.append(dict(kind=kind,options=o,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 for kind,index,count in itertools.product(['static','dynamic','none'],range(4),[-1,0,1,2,3,4]):run('index',dict(referenceKind=kind,referenceIndex=index,instanceCount=count))
 for index,count,present in itertools.product([-32769,-32768,-1,0,1,2,3,32767,32768],[-1,0,1,3,8],[False,True]):run('terrain',dict(index=index,terrainCount=count,terrain=present))
 for name,dynamic,scene,terrain,count in itertools.product([None,'','Alpha','ALPHA','beta','gamma','missing','alpha\0later'],[False,True],[False,True],[False,True],[-1,0,1,4]):run('bind',dict(name=name,dynamic=dynamic,scene=scene,terrain=terrain,sceneCount=count))
 for primary,ground,bound,index,y in itertools.product([False,True],[(0,0),(1,0),(0,128),(255,255)],[-1,0,1,3,6,7],[-1,0,1,3,6,7],[-1.,0.,0.5,1.,6.,7.,8.]):run('condition',dict(primary=primary,ground281=ground[0],ground282=ground[1],bound=bound,groundIndex=index,y=y))
 rng=random.Random(441910)
 for i in range(512):
  which=rng.randrange(8);height=struct.unpack('<f',struct.pack('<f',rng.uniform(-10000,10000)))[0];heights=[height]*8;transforms=[True]*8
  run('condition',dict(bound=which,groundIndex=which,heights=heights,transforms=transforms,y=height if i%2 else struct.unpack('<f',struct.pack('<f',height+rng.uniform(-1,1)))[0]))
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());authored=next(r['uses'] for r in ledger['rows'] if r['name']=='PlayerOnObject')
 for source in authored:
  for dynamic in [False,True]:run('bind',dict(name=source['args'][0],dynamic=dynamic),source)
  for i in range(3):run('condition',dict(bound=i,groundIndex=i,y=float(i)),source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,authoredUses=len(authored),excludedInvalidPointerChains=excluded,examples=errors[:6],method='Original scene lookup, scene-index projection, terrain lookup and PlayerOnObject condition all execute unchanged without replacements; exact returns and full source/player/terrain memory compared.',limits=['Valid finite matrices/heights and readable terrain backing for matching grounded-player indexes. Invalid native pointer chains explicitly excluded.','Prepared static-instance identities, signed-short terrain links and current-scene records; actual scene/terrain loader association remains external. Dynamic diagnostic fallback97388c is disabled.','Authored name probes retain literal names against prepared tables; they are not claims that each real level binding has been loaded. Managed replay pending.'])
 (B/'reports/native-terrain-object-conditions-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-terrain-object-conditions-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,names=names,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
