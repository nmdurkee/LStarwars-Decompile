"""Differential native evidence for script obstacle controls and scene-animation groups."""
import importlib.util,json,itertools,random,copy,hashlib,re
from pathlib import Path
s=importlib.util.spec_from_file_location('obstacle_fixture',Path(__file__).with_name('native-obstacle-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;groups={};cases=[];examples=[];mismatches=failures=0

def run(group,record,execute,expected):
 global mismatches,failures
 groups[group]=groups.get(group,0)+1
 try:actual=execute()
 except Exception as e:
  failures+=1
  if len(examples)<12:examples.append(dict(group=group,input=record,error=str(e)))
  return
 if actual!=expected:
  mismatches+=1
  if len(examples)<12:examples.append(dict(group=group,input=record,expected=expected,actual=actual))
 def input_bits(value):
  if isinstance(value,dict):
   result={key:input_bits(v)for key,v in value.items()}
   for key,v in value.items():
    if isinstance(v,float):result[key+'Bits']=f.bits(v)
   return result
  return [input_bits(x)for x in value]if isinstance(value,list)else value
 cases.append(dict(group=group,input=input_bits(record),expected=actual))

def command(kind,tokens,options,first=True,authored=None):
 nodes=f.setup(tokens,**options);expected=f.parse_command(kind,tokens,options,nodes,first)
 def execute():
  if kind=='scp':result=n.call(0x44ea70,[0,0,0,f.ARGS,len(tokens),int(first)])
  else:n.call(0x465720 if kind=='special'else 0x465590,[f.WORLD+0x2ac8,0,f.ARGS,len(tokens)]);result=1
  return dict(result=result,state=f.state(nodes))
 run('command',dict(kind=kind,tokens=tokens,options=options,first=first,authored=authored),execute,dict(result=1,state=expected))

forms=[[],['name=a'],['name=b'],['name=missing'],['name=nullobject'],['name=a','name=missing'],['name=a','name=nullobject'],['name=a','name=b'],['noiseNAME=a'],['name=a','BACKWARD','FORWARD'],['name=a','backwards'],['name=a','NAME=b'],['name=a','Snap','STAYOPEN','STAYSHUT'],['name=a','xxBACKWARD'],['name=a\0name=b'],['name=a','stayshut','FORWARD'],['Name=a','FORWARD','BACKWARD'],['NAME=a','sTaYoPeN']]
for kind,tokens,first,missing in itertools.product(['scp','obstacle','special'],forms,[False,True],[False,True]):command(kind,tokens,dict(targetMissing=missing),first)
for kind,backward,snap,stayopen,stayshut,state,negative in itertools.product(['scp','obstacle','special'],[False,True],[False,True],[False,True],[False,True],[0,1,2,3,4],[False,True]):
 tokens=['name=a']+(['backwards'if kind=='scp'else'BACKWARD']if backward else[])+(['SNAP']if snap else[])+(['STAYOPEN']if stayopen else[])+(['STAYSHUT']if stayshut else[])
 command(kind,tokens,dict(state=state,speed=-.75 if negative else .75,obstacleFlags=0xffffffff if snap else 0))

operations={'play':0x5a1030,'refresh':0x5a0670,'loop':0x5a11b0,'stop':0x5a1170,'start':0x5a1230,'end':0x5a11f0,'seek':0x5a1270}
rng=random.Random(0x5a1030)
for k in range(1500):
 options=dict(state=rng.randrange(-1,6),controlFlags=rng.randrange(65536),queue=bool(rng.randrange(2)))
 nodes=[]
 for j in range(rng.randrange(5)):
  values=[f.f32(rng.uniform(-100,100)) for z in range(5)]
  nodes.append(dict(start=values[0],end=values[1],frame=values[2],rate=values[3],scale=values[4]if k%3 else 0.,flags=rng.randrange(1<<32),present=bool(rng.randrange(2)),reference=True,owner=bool(rng.randrange(2))))
 options['nodes']=nodes;argument=f.f32(rng.uniform(-3,3));evaluate=bool(k%2)
 for operation,address in operations.items():
  f.setup(**options);expected=f.model_state(nodes,options);f.control(expected,nodes,options,operation,argument=argument if operation!='loop'else k-400,evaluate=evaluate)
  def execute(operation=operation,address=address):
   args=[f.ANIMS]
   if operation in ['play','seek']:args.append(f.bits(argument))
   elif operation=='loop':args.append((k-400)&0xffffffff)
   if operation=='play':args.append(int(evaluate))
   n.call(address,args);return f.state(nodes)
  run('scene-control',dict(operation=operation,options=options,argument=argument if operation!='loop'else k-400,evaluate=evaluate),execute,expected)

for backwards,snap,present,mode,speed,fr,br in itertools.product([False,True],[False,True],[False,True],[0,1,2,255],[-3.,-.0,0.,.5,3.],[-2.,0.,1.25],[-1.,0.,2.5]):
 options=dict(animationPresent=present,loopMode=mode,speed=speed,forwardRate=fr,backwardRate=br);nodes=f.setup(**options);expected=f.model_state(nodes,options);f.obstacle(expected,nodes,options,0,backwards,snap)
 address=(0x558970 if backwards else 0x558990)if snap else(0x5579d0 if backwards else 0x557960)
 run('obstacle-helper',dict(options=options,backwards=backwards,snap=snap),lambda:(n.call(address,[f.OBJECTS]),f.state(nodes))[1],expected)

def output_model(special,index,include,options,nodes,model):
 if options.get('recordMissing')or options.get('registryMissing')or options.get('typesMissing')or options.get('outputMissing')or options.get('typeCount',2)<=int(special):return 0
 if options.get('objectMissing'):return 0
 if special:
  if not options.get('animationPresent',True):return None # native dereference outside contract
  if options.get('memberCount',len(nodes))==0 or not nodes or not nodes[0].get('reference',True)or(not(options.get('specialFlags',2)&2)and not include):return 0
  f.refresh(model['targets'][0],nodes);state=model['targets'][0]['state']
  return int(state==2)if index==0 else int(state!=0)if index==1 else 0
 if ((options.get('obstacleStatus',3)&3)!=3 and not include)or not options.get('animationPresent',True):return 0
 state=options.get('state',4)
 return int(state==2)if index==0 else int(state!=0)if index==1 else int(options.get('proximity',0)!=0)if index==2 else int(state==0)if index==3 else int(state==1)if index==4 else 0

for special,index,include,state,status,gate in itertools.product([False,True],range(6),[0,1],range(5),[0,1,2,3,255],['ordinary','registryMissing','typesMissing','outputMissing','objectMissing','recordMissing']):
 options=dict(state=state,obstacleStatus=status,specialFlags=status,proximity=state,controlFlags=4)
 if gate!='ordinary':options[gate]=True
 nodes=f.setup(**options);n.pack('<B',f.RECORDS+6,int(special))
 if options.get('objectMissing'):n.pack('<I',f.RECORDS,0)
 model=f.model_state(nodes,options);expected=output_model(special,index,include,options,nodes,model)
 def execute():
  value=n.call(0x55a1b0,[0 if options.get('registryMissing')else f.REG,0 if options.get('recordMissing')else f.RECORDS,index,include]);return dict(value=value,state=f.state(nodes))
 run('gizmo-output',dict(special=special,index=index,include=include,options=options),execute,dict(value=expected,state=model))

for special,atEnd,state,record,missingOutput in itertools.product([False,True],[False,True],range(5),[False,True],[False,True]):
 options=dict(state=state,controlFlags=4,outputMissing=missingOutput);nodes=f.setup(**options);n.pack('<B',f.RECORDS+6,int(special));model=f.model_state(nodes,options);out=output_model(special,0 if atEnd else 1,1,options,nodes,model)
 expected=f.bits(float(record and(bool(out)if atEnd else not out)))
 run('condition',dict(special=special,atEnd=atEnd,record=record,options=options),lambda:f.floating(0x440940 if atEnd else 0x440910,[0,0,0,0,f.RECORDS if record else 0]),expected)
for flag in range(256):
 nodes=f.setup(obstacleFlags=flag)
 run('locked-condition',dict(flags=flag),lambda:f.floating(0x440970,[0,0,0,0,f.OBJECTS]),f.bits(float(bool(flag&8))))
for special,name in itertools.product([False,True],[None,'','a','b','missing','nullobject','A\0b','\xe0']):
 f.setup();pointer=0
 if name is not None:n.write(f.TEXT,name.encode('latin1')+b'\0');pointer=f.TEXT
 expected=f.lookup(name,special);expected=0 if expected is None else expected+1
 run('initializer',dict(special=special,name=name),lambda:(lambda r:0 if r==0 else (r-f.RECORDS)//0x20+1)(n.call(0x4408e0 if special else 0x4408b0,[0,pointer,0])),expected)


# Arithmetic boundaries, signed zero and finite values with float-store overflow.
edgeValues=[f.f32(v)for v in [0.,-0.,f.value(1),-f.value(1),1.,-1.,1.e-30,-1.e-30,f.value(0x7f7fffff),-f.value(0x7f7fffff)]]
for k,(start,end,fraction)in enumerate(itertools.product(edgeValues,edgeValues,[-2.,-0.,0.,.5,1.,2.])):
 options=dict(nodes=[dict(start=start,end=end,frame=0.,flags=7,rate=0.,scale=1.)],state=4);nodes=f.setup(**options);model=f.model_state(nodes,options);f.control(model,nodes,options,'seek',argument=fraction)
 run('scene-boundary',dict(operation='seek',options=options,argument=fraction,evaluate=False),lambda:(n.call(0x5a1270,[f.ANIMS,f.bits(fraction)]),f.state(nodes))[1],model)

ledger=json.loads((f.BASE/'reports/gameplay-command-semantic-coverage.json').read_text(encoding='utf-8'));authoredCounts={};sourceFormOmissions=[]
for row in ledger['rows']:
 if row['name']not in ['PlayObstacle','PlayGizObstacle','PlaySpecial','ObstacleAtStart','ObstacleAtEnd','SpecialAtStart','SpecialAtEnd','ObstacleLockedShut']:continue
 authoredCounts[row['kind']+':'+row['name']]=row['sourceUses']
 for use in row['uses']:
  authored=dict(name=row['name'],kind=row['kind'],source=use['source'],line=use['line'],text=use['text'])
  if row['kind'].endswith('action'):
   kind='scp'if row['kind']=='scp-action'else 'special'if row['name']=='PlaySpecial'else'obstacle'
   for missing in [False,True]:command(kind,use['args'],dict(targetMissing=missing),authored=authored)
  else:
   quoted=re.findall(r'"([^"]*)"',use['text'])
   if not quoted:sourceFormOmissions.append(dict(authored=authored,reason='Missing quoted operand; initializer/loader interpretation is not inferred.'));continue
   name=quoted[0];special=row['name'].startswith('Special');atEnd=row['name'].endswith('End')
   for missing in [False,True]:
    options=dict(targetMissing=missing,state=use['line']%5,controlFlags=4);nodes=f.setup([name],**options);initializer=0x4409b0 if row['name']=='ObstacleLockedShut'else 0x4408e0 if special else 0x4408b0;pointer=n.call(initializer,[0,f.TEXT,0]);model=f.model_state(nodes,options)
    if row['name']=='ObstacleLockedShut':
     if not pointer:continue # native crashes; record as excluded in report
     address=0x440970;expected=f.bits(float(bool(options.get('obstacleFlags',0xf0f0a5a5)&8)))
    else:address=0x440940 if atEnd else 0x440910;out=output_model(special,0 if atEnd else 1,1,options,nodes,model);expected=f.bits(float(bool(pointer)and(bool(out)if atEnd else not out)))
    run('authored-condition',dict(authored=authored,special=special,atEnd=atEnd,name=name,options=options),lambda:f.floating(address,[0,0,0,0,pointer]),expected)

report=dict(binarySha256=n.sha256,groups=groups,comparisonRecords=len(cases),mismatches=mismatches,failures=failures,examples=examples,catalogUses=sum(authoredCounts.values()),authoredUses=sum(authoredCounts.values())-len(sourceFormOmissions),authoredCounts=authoredCounts,sourceFormOmissions=sourceFormOmissions,adapters=['0x55a020 named registry lookup; all scene-control, list, obstacle helper, output dispatch and condition bodies execute original bytes.'],limits=['Finite scalar inputs and valid linked records. Names resolved to synthetic world bindings. No renderer, animation tick or collision world integration.','LockedShut requires successful initialized object; failed lookup would dereference null and is excluded.','Native/Python comparison only; managed execution pending.'])
(f.BASE/'reports/native-obstacle-tests.json').write_text(json.dumps(report,indent=2)+'\n');(f.BASE/'reports/native-obstacle-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':'))+'\n');print(json.dumps({k:v for k,v in report.items()if k!='examples'},indent=2));print(json.dumps({'examples':examples[:2]},indent=2));assert not mismatches and not failures
