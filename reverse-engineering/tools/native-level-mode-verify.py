import importlib.util,json,struct,itertools,copy,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
WORLD=D;CHAPTER=D+0x3000;LEVELS=D+0x4000;SAVE=D+0x10000;MISSION=D+0x30000;EXPLICIT=D+0x30100;QUERY=D+0x31000;OUT=D+0x32000
HUB=json.loads((B/'reports/native-hub-area-names.json').read_text())['names'];NAMES=['Maul_A','Maul_B','alpha','ALPHA','Dagobah',''];rows=[];errors=[];excluded=[];groups={}
ADDR={'ResolveMission':0x58a900,'MissionMode':0x442aa0,'InMiniCut':0x442bb0,'BindHubArea':0x491b30,'InHubArea':0x491b70,'BindVisitedLevel':0x442320,'BeenToLevel':0x4423b0}
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def options(o):
 p=dict(current=True,currentEnabled=1,currentMission=0x1110,explicit=False,explicitEnabled=1,explicitMission=0x2220,mini=0,secondaryMini=0,fourth=False,hub=2,bound=2,chapter=True,system=True,count=6,levelIds=[3,1,0,3,5,2],levelNames=NAMES,visited=[0,1,2,3,0xffffffff,0x80000000],name='Maul_B');p.update(o);return p
def setup(o):
 n.write(D,bytes(0x32004));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x12c,CHAPTER if o['chapter'] else 0);n.pack('<I',0x951b78,LEVELS);n.pack('<I',0x87b2cc,SAVE);n.pack('<I',0x9553d4,MISSION if o['current'] else 0);n.pack('<I',MISSION+4,o['currentMission']);n.pack('<B',MISSION+0x1d,o['currentEnabled']);n.pack('<I',EXPLICIT+4,o['explicitMission']);n.pack('<B',EXPLICIT+0x1d,o['explicitEnabled']);n.pack('<i',0x855de0,o['mini']);n.pack('<i',0x9514e4,o['secondaryMini']);n.pack('<i',0x87b460,o['hub']);n.pack('<B',CHAPTER+0x7d,o['count'])
 for i,index in enumerate(o['levelIds']):n.pack('<h',CHAPTER+0x60+i*2,index)
 for i,name in enumerate(o['levelNames']):n.write(LEVELS+i*0x130+0x40,name.encode()+b'\0')
 for i,flags in enumerate(o['visited']):n.pack('<I',SAVE+i*0x2e28+0x2800,flags)
 if o['name'] is not None:n.write(QUERY,o['name'].encode()+b'\0')
def model(kind,o):
 if kind in ['ResolveMission','MissionMode']:
  explicit=kind=='ResolveMission' and o['explicit'];value=o['explicitMission'] if explicit and o['explicitEnabled'] else o['currentMission'] if not explicit and o['current'] and o['currentEnabled'] else 0
  return value if kind=='ResolveMission' else bits(float(value!=0))
 if kind=='InMiniCut':return bits(float(o['mini']!=0 or o['fourth'] and o['secondaryMini']!=0))
 if kind=='BindHubArea':return next((i for i,name in enumerate(HUB) if o['name'] is not None and name.lower()==o['name'].split('\0')[0].lower()),-1)
 if kind=='InHubArea':return bits(float(((o['hub']&0xffff)^0x8000)-0x8000==o['bound']))
 if kind=='BindVisitedLevel':
  if o['name'] is None or not o['chapter'] or not o['system']:return -1
  for i in range(o['count']):
   index=o['levelIds'][i]
   if index<0 or index>=len(o['levelNames']):return None
   if o['levelNames'][index].lower()==o['name'].split('\0')[0].lower():return i
  return -1
 if o['bound']==-1:return 0
 if o['bound']<0 or o['bound']>=len(o['visited']):return None
 return bits(float(o['visited'][o['bound']]&1))
def run(kind,inputs=None,source=None):
 o=options(inputs or {});want=model(kind,o)
 if want is None:excluded.append(dict(kind=kind,options=o));return
 setup(o);before=n.read(D,0x32000);query=QUERY if o['name'] is not None else 0
 if kind=='ResolveMission':got=n.call(ADDR[kind],[EXPLICIT if o['explicit'] else 0])
 elif kind in ['BindVisitedLevel','BindHubArea']:v=n.call(ADDR[kind],[WORLD if o['system'] else 0,query]);got=v if v<0x80000000 else v-0x100000000
 else:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(ADDR[kind],[0,0,0,int(o['fourth']),o['bound']]);n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',OUT)[0]
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x32000)!=before:bad.append('Input memory changed')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad))
 rows.append(dict(kind=kind,options=o,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 for kind in ['ResolveMission','MissionMode']:
  for current,explicit,ce,ee,cm,em in itertools.product([False,True],[False,True],[0,1,128],[0,1,255],[0,0x1110],[0,0x2220]):run(kind,dict(current=current,explicit=explicit,currentEnabled=ce,explicitEnabled=ee,currentMission=cm,explicitMission=em))
 for mini,secondary,fourth in itertools.product([0,1,-1,0x7fffffff],[0,1,-1,0x7fffffff],[False,True]):run('InMiniCut',dict(mini=mini,secondaryMini=secondary,fourth=fourth))
 for name in [None,'','unknown']+HUB+[x.lower() for x in HUB]+['EPISODE3\0ignored']:run('BindHubArea',dict(name=name))
 for hub,bound in itertools.product([-32768,-2,-1,0,1,2,3,9,10,32767,32768,65535,65538,0x7fffffff],repeat=2):run('InHubArea',dict(hub=hub,bound=bound))
 for name,count,chapter,system in itertools.product([None,'','Maul_A','maul_b','alpha','ALPHA','Dagobah','missing','MAUL_B\0ignored'],[0,1,2,4,6],[False,True],[False,True]):run('BindVisitedLevel',dict(name=name,count=count,chapter=chapter,system=system))
 for bound,flags in itertools.product([-2,-1,0,1,2,3,4,5,6],[0,1,2,3,0x80000000,0xfffffffe,0xffffffff]):run('BeenToLevel',dict(bound=bound,visited=[flags]*6))
 for count,name in itertools.product([0,1,2,6],['alpha','Maul_B',None]):run('BindVisitedLevel',dict(count=count,name=name,levelIds=[3,-1,0,3,5,2]))
 uses={r['name']:r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name'] in ['MissionMode','InMiniCut','InHubArea','BeenToLevel']}
 for kind,authored in uses.items():
  for source in authored:
   if kind in ['InHubArea','BeenToLevel']:run('BindHubArea' if kind=='InHubArea' else 'BindVisitedLevel',dict(name=source['args'][0]),source)
   else:
    for enabled in [0,1]:run(kind,dict(currentEnabled=enabled,mini=enabled),source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),excludedInvalidPointerCases=len(excluded),authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:4],correctionHistory=['Initial int32 hub-global model produced2 mismatches. Disassembly491b70 is MOVSX word, and the source/model now preserve signed16-bit width with expanded upper-word regressions.'],method='Original7 helper/condition entries execute with actual case-folded string comparison and native fixed hub-name table. Exact opaque mission handle, float/index returns and complete input memory; no replacements.',limits=['Prepared chapter table with signed-short global-level IDs and unsigned-byte local count; readable nonnegative referenced level IDs and save-record indexes except native sentinel-1.','Hub global is signed16-bit, compared to the full32-bit bound; upper stored bits do not participate. Mission pointer remains opaque. Mini-cut globals and save/chapter producers remain external.','Authored condition operands preserved on prepared runtime records, not loaded save-file or level execution. Managed replay pending.'])
 (B/'reports/native-level-mode-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-level-mode-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,hubNames=HUB,cases=rows,excluded=excluded),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
