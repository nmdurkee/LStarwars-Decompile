import importlib.util,json,struct,itertools,random,copy,gzip
from pathlib import Path
s=importlib.util.spec_from_file_location('gizmo',Path(__file__).with_name('native-gizmo-conditions-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q)
n=q.n;B=q.B;D=q.D;BASE_NAMES=copy.deepcopy(q.names)
ACT=D+0x20000;PACK=D+0x22000;CRE=D+0x23000;REF=D+0x24000;INPUT=D+0x25000;DEF=D+0x26000;CLASS=D+0x27000;CAP=D+0x28000;ARGS=D+0x29000;STR=D+0x2a000;GROUP=D+0x30000;OUT=D+0x40000
rows=[];errors=[];groups={};memory=0;sequenceTicks=0
ADDR={'UseForce':0x450030,'IsComplete':0x467890,'HasCapability':0x55bc80,'BindComplete':0x441570,'ForceComplete':0x4415a0}
def obj(pair):return 0 if pair is None else q.OBJECTS+pair[0]*0x1000+pair[1]*0x100
def identity(p):return None if not p else [(p-q.OBJECTS)//0x1000,((p-q.OBJECTS)%0x1000)//0x100]
def f(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def options(o):
 p=q.options(dict(forceType=0,creature=True,reference=True,actor=True,first=True,tokens=['alpha'],seed=42,selected=[0,1],throwable=0,inrange=0,timer=.125,delta=.125,attachment=False,goal=[1,1],forceTarget=[1,0],input8=0x1010,input5a=0xa0,definition=True,classPresent=True,inputPresent=True,definitionFlags=0xffffffff,class90=0xffffffff,class94=0,retry=True,retryMask=0x10000,capabilityCount=2,capabilities=[[8,1],[16,2]],capabilityIndex=0,bound=[0,0],objectFlags=[3]*20,flags74=[0]*20,timers4c=[0.]*20,groupPresent=[True]*20,groupState=[1]*20,names=copy.deepcopy(BASE_NAMES)));p.update(o);p['timerBits']=q.bits(p['timer']);p['deltaBits']=q.bits(p['delta']);return p
def setup(o,name):
 q.names=o['names'];q.setup(o,name);n.write(D+0x1b000,bytes(0x25004));n.pack('<i',0x7f8cc4,o['forceType']);n.pack('<I',0x80253c,o['seed']);n.pack('<i',0x93b2a4,int(o['retry']));n.pack('<I',0x80228c,o['retryMask']);n.pack('<iI',0x93b26c,o['capabilityCount'],0);n.pack('<I',0x93b280,CAP)
 n.pack('<I',CRE+0xd0,REF if o['reference'] else 0);n.pack('<I',REF,ACT if o['actor'] else 0);n.pack('<I',CRE+0xd4,1 if o['attachment'] else 0);n.pack('<I',CRE+0x1e4,obj(o['goal'])+0x1c if o['goal'] is not None else 0);n.pack('<I',ACT+0x10cc,obj(o['forceTarget']));n.pack('<I',ACT+0xca4,INPUT if o['inputPresent'] else 0);n.pack('<I',ACT+0x54,DEF if o['definition'] else 0);n.pack('<I',DEF+4,o['definitionFlags']);n.pack('<I',DEF+0x24,CLASS if o['classPresent'] else 0);n.pack('<II',CLASS+0x90,o['class90'],o['class94']);n.pack('<I',INPUT+8,o['input8']);n.pack('<H',INPUT+0x5a,o['input5a']);n.pack('<2B',PACK+0x68,o['throwable'],o['inrange']);n.pack('<I',PACK+0x6c,obj(o['selected']));n.pack('<f',PACK+0x9c,o['timer'])
 for i,(a,b) in enumerate(o['capabilities']):n.pack('<II',CAP+i*12+4,a,b)
 for t in range(5):
  for i in range(4):
   j=t*4+i;p=obj([t,i]);n.pack('<I',p+0xa0,o['objectFlags'][j]);n.pack('<I',p+0x74,o['flags74'][j]);n.pack('<f',p+0x4c,o['timers4c'][j]);n.pack('<I',p+0x28,GROUP+j*0x20 if o['groupPresent'][j] else 0);n.pack('<i',GROUP+j*0x20+0xc,o['groupState'][j])
 tokens(o['tokens'])
def tokens(values):
 q.events.clear()
 for i,value in enumerate(values):n.pack('<I',ARGS+i*4,STR+i*0x100);n.write(STR+i*0x100,value.encode()+b'\0')
def complete(o,target):
 j=target[0]*4+target[1];flags=o['objectFlags'][j];kind=o['flags74'][j]
 return int(not(kind&2) and (o['timers4c'][j]<=0 or flags&0x2000) and (not(kind&0x40) or flags&0x800) and (not o['groupPresent'][j] or o['groupState'][j]==(0 if flags&0x40 else 2)))
def capable(o,index):
 if index<0 or index>=o['capabilityCount']:return 0
 a,b=o['capabilities'][index]
 return int((a==0 or (not(a&8 and o['class94']&0x8000) and o['definitionFlags']&a==a)) and (b==0 or o['class90']&b==b))
def state(o):return dict(selected=o['selected'],throwable=o['throwable'],inrange=o['inrange'],timer=q.bits(o['timer']),seed=o['seed'],goal=o['goal'],forceTarget=o['forceTarget'],input8=o['input8'],input5a=o['input5a'],objectFlags=o['objectFlags'].copy())
def readstate():
 p=n.unpack('<I',CRE+0x1e4)[0]
 return dict(selected=identity(n.unpack('<I',PACK+0x6c)[0]),throwable=n.unpack('<B',PACK+0x68)[0],inrange=n.unpack('<B',PACK+0x69)[0],timer=n.unpack('<I',PACK+0x9c)[0],seed=n.unpack('<I',0x80253c)[0],goal=identity(p-0x1c) if p else None,forceTarget=identity(n.unpack('<I',ACT+0x10cc)[0]),input8=n.unpack('<I',INPUT+8)[0],input5a=n.unpack('<H',INPUT+0x5a)[0],objectFlags=[n.unpack('<I',obj([t,i])+0xa0)[0] for t in range(5) for i in range(4)])
def model(kind,o,name):
 events=[]
 if kind=='BindComplete':return q.model('bindBlowup',dict(o,blowupType=o['forceType']),name)
 if kind=='IsComplete':return dict(result=complete(o,o['bound']),events=[])
 if kind=='ForceComplete':return dict(result=q.bits(float(complete(o,o['bound']) if o['bound'] is not None else 0)),events=[])
 if kind=='HasCapability':return dict(result=capable(o,o['capabilityIndex']),events=[])
 if not(o['creature'] and o['reference'] and o['actor']):return dict(result=1,events=[],state=state(o))
 triggered=False
 if o['first']:
  o['selected']=None;choices=[]
  for token in o['tokens']:
   text=token.split('\0')[0];lower=text.lower()
   if lower=='throwable':o['throwable']=1
   elif lower=='inrange':o['inrange']=1
   elif lower=='triggered_by_hit':triggered=True
   elif len(choices)<16:
    at=lower.find('name=');found=q.model('bindBlowup',dict(o,blowupType=o['forceType']),text if at<0 else text[at+5:]);events+=found['events'];target=found['result']
    if target is not None:
     flags=o['objectFlags'][target[0]*4+target[1]]
     if flags&2 and not flags&0x10000:choices.append(target)
  if choices:o['seed']=(o['seed']*0x24cd+1)&0xffff;o['selected']=choices[o['seed']//(65535//len(choices)+1)]
 result=0;selected=o['selected']
 if selected is None:result=1
 else:
  j=selected[0]*4+selected[1]
  if o['objectFlags'][j]&1:
   allow=capable(o,1 if o['flags74'][j]&0x10 else 0)
   if triggered:o['objectFlags'][j]|=0x8000
   elif allow:
    o['goal']=selected;o['input5a']|=4;o['forceTarget']=selected
    if o['throwable']:
     if not o['attachment']:o['input5a']&=0xfffb;o['forceTarget']=None
     result=1
    elif complete(o,selected):result=1
   elif o['retry']:
    o['timer']=f(o['timer']-o['delta'])
    if o['timer']<0:o['timer']=.5;o['input8']|=o['retryMask']
 return dict(result=result,events=events,state=state(o))
def expectedmemory(before,o):
 e=bytearray(before)
 def p(fmt,a,*v):struct.pack_into(fmt,e,a-D,*v)
 p('<2B',PACK+0x68,o['throwable'],o['inrange']);p('<I',PACK+0x6c,obj(o['selected']));p('<f',PACK+0x9c,o['timer']);p('<I',CRE+0x1e4,obj(o['goal'])+0x1c if o['goal'] is not None else 0);p('<I',ACT+0x10cc,obj(o['forceTarget']));p('<I',INPUT+8,o['input8']);p('<H',INPUT+0x5a,o['input5a'])
 for j,flags in enumerate(o['objectFlags']):p('<I',obj([j//4,j%4])+0xa0,flags)
 return bytes(e)
def execute(kind,o,name):
 if kind=='UseForce':result=n.call(ADDR[kind],[0,PACK,CRE if o['creature'] else 0,ARGS,len(o['tokens']),int(o['first']),q.bits(o['delta'])]);return dict(result=result,events=q.events.copy(),state=readstate())
 if kind=='BindComplete':result=identity(n.call(ADDR[kind],[0,q.TEXT if name is not None else 0]))
 elif kind=='IsComplete':result=n.call(ADDR[kind],[obj(o['bound'])])
 elif kind=='HasCapability':result=n.call(ADDR[kind],[ACT,o['capabilityIndex']])
 else:n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.call(ADDR[kind],[0,0,0,0,obj(o['bound'])]);n.mu.emu_start(n.STOP,n.STOP+6);result=n.unpack('<I',OUT)[0]
 return dict(result=result,events=q.events.copy())
def run(kind,inputs=None,name=None,source=None,sequence=None):
 global memory,sequenceTicks
 o=options(inputs or {});setup(o,name);initial=copy.deepcopy(o);native=[];steps=sequence or [{}]
 for step in steps:
  if 'delta' in step:step['deltaBits']=q.bits(step['delta'])
  o.update(step);tokens(o['tokens']);before=n.read(D,0x40000);modeloptions=copy.deepcopy(o);want=model(kind,modeloptions,name);got=execute(kind,o,name);bad=[]
  if got!=want:bad.append(dict(got=got,want=want))
  expected=expectedmemory(before,modeloptions) if kind=='UseForce' else before
  if n.read(D,0x40000)!=expected:bad.append('Complete memory projection mismatch')
  if bad:errors.append(dict(kind=kind,inputs=o,bad=bad))
  o=modeloptions;native.append(got);groups[kind]=groups.get(kind,0)+1;memory+=1
 if sequence:sequenceTicks+=len(steps)
 rows.append(dict(kind=kind,options=initial,name=name,native=native if sequence else native[0],source=source,sequence=sequence))
def main():
 for flags,kind,timer,present,status in itertools.product([0,0x40,0x800,0x2000,0x2840,0xffffffff],[0,2,0x10,0x40,0x42],[-1.,-0.,0.,.125,10.],[False,True],[-1,0,1,2,3]):
  o=dict(objectFlags=[flags]*20,flags74=[kind]*20,timers4c=[timer]*20,groupPresent=[present]*20,groupState=[status]*20)
  for fn in ['IsComplete','ForceComplete']:run(fn,o)
 run('ForceComplete',dict(bound=None))
 for index,count,a,b,primary,secondary,special in itertools.product([-1,0,1,2],[0,1,2],[0,8,0x18],[0,2],[0,8,0x18,0xffffffff],[0,2,0xffffffff],[0,0x8000]):run('HasCapability',dict(capabilityIndex=index,capabilityCount=count,capabilities=[[a,b],[a,b]],definitionFlags=primary,class90=secondary,class94=special))
 tokenSets=[[],['alpha'],['name=alpha'],['junkNAME=ALPHA'],['missing'],['beta','alpha','ALPHA'],['alpha','throwable'],['throwable','inrange','alpha'],['alpha','triggered_by_hit'],['alpha','triggered_by_hit','throwable'],['alpha']*18+['inrange','throwable'],['ALPHA\0ignored']]
 for args,first,flags,definition,attachment in itertools.product(tokenSets,[False,True],[0,1,2,3,0x10003],[0,0xffffffff],[False,True]):run('UseForce',dict(tokens=args,first=first,objectFlags=[flags]*20,definitionFlags=definition,attachment=attachment))
 for flags,kind,timer,status in itertools.product([3,0x43,0x2003,0x803],[0,2,0x10,0x40],[0.,.5],[0,1,2]):run('UseForce',dict(objectFlags=[flags]*20,flags74=[kind]*20,timers4c=[timer]*20,groupState=[status]*20))
 for timer,delta,retry,seed in itertools.product([-1.,-0.,0.,.125,.5],[0.,.125,.5,1.],[False,True],[0,1,65535,0xffffffff]):run('UseForce',dict(definitionFlags=0,timer=timer,delta=delta,retry=retry,seed=seed))
 for throwable,inrange,first in itertools.product([0,1,255],[0,1,128],[False,True]):run('UseForce',dict(throwable=throwable,inrange=inrange,first=first,tokens=['alpha']))
 for seed in [0,1,2,32767,32768,65534,65535,0xffffffff]:
  for count in [1,2,3,15,16,17,40]:run('UseForce',dict(tokens=(['alpha','beta','ALPHA']*14)[:count],seed=seed,objectFlags=[3,0x10003,3,0]+[3]*16))
 for gate in ['creature','reference','actor']:
  for first in [False,True]:run('UseForce',{gate:False,'first':first})
 for kind in ['BindComplete']:
  for name,typ in itertools.product([None,'','alpha','ALPHA','beta','gamma','missing','alpha\0ignored'],[-1,0,1,3,4,7]):run(kind,dict(forceType=typ),name)
 uses={r['name']:r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name'] in ['UseForce','ForceComplete']}
 for use in uses['UseForce']:
  names=copy.deepcopy(BASE_NAMES);literal=next((x for x in use['args'] if x.lower() not in ['throwable','inrange','triggered_by_hit']),None)
  if literal is not None:names[0][0]=literal.split('=',1)[-1] if 'name=' in literal.lower() else literal
  for defFlags in [0,0xffffffff]:run('UseForce',dict(names=names,tokens=use['args'],definitionFlags=defFlags),source=use)
 for use in uses['ForceComplete']:run('BindComplete',name=use['args'][0],source=use)
 for args in [['alpha'],['alpha','triggered_by_hit'],['alpha','throwable'],['alpha','inrange']]:
  for definition in [0,0xffffffff]:run('UseForce',dict(tokens=args,definitionFlags=definition),sequence=[dict(first=i==0,tokens=args if i==0 else ['missing','throwable','triggered_by_hit'],delta=.125) for i in range(16)])
 report=dict(binarySha256=n.sha256,checks=sum(groups.values()),fixtureRows=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,persistentSequenceTicks=sequenceTicks,authoredUses={k:len(v) for k,v in uses.items()},examples=errors[:4],method='Unchanged450030,467890,55bc80,441570,4415a0 with actual55a020/558770/string helpers/54fa60. Compare full fixture memory, return values, callback order, cached target and global RNG; persistent sequences retain native/model memory.',limits=['Finite timer values, valid packet/actor/definition/class/input backing and bounded type/capability tables. Physical Force animation/update producers and controller consumers remain external.','Authored action operands use prepared name tables with one literal target binding; these are controlled compositions, not loaded-level replay.','Flags68/69 persist. triggered_by_hit is local to first-call parsing. inrange has no consumer in this routine. Managed replay pending.'])
 (B/'reports/native-force-action-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-force-action-vectors.json.gz').write_bytes(gzip.compress((json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n').encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
