import importlib.util,json,struct,copy,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('actors',Path(__file__).with_name('gameplay-actor-state-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
n=a.n;B=a.BASE;D=n.DATA;EXTRA=D+0x60000
ADDR={'CannotDropIn':0x44fa90,'NotWithParty':0x44fb90,'SetAIOverrideControl':0x445910}
rows=[];errors=[];groups={};memory=0
fields=[('field1008',0x1008,'I'),('timer1010',0x1010,'I'),('source107e',0x107e,'B'),('copy107f',0x107f,'B'),('stateE38',0xe38,'B'),('stateE39',0xe39,'B'),('blocked',0x28b,'B')]
def context(o):
 c=a.context(o)
 for i,x in enumerate(c['actors']):
  x['life']=dict(field1008=0x12340000+i,timer1010=0x40000000+i,source107e=10+i,copy107f=90+i,stateE38=30+i,stateE39=40+i,blocked=i%3,linked=1 if i==0 else -1,defaultE38=70+x['definition'])
  x['life'].update(o.get('lifeOverrides',{}).get(str(i),{}))
 return c

def setup(c,tokens,cached):
 a.setup(c,tokens);n.write(EXTRA,bytes(0x2000));n.pack('<I',a.PACK+0x6c,a.actor(cached))
 for i,x in enumerate(c['actors']):
  life=x['life'];p=a.actor(i)
  for key,off,fmt in fields:n.pack('<'+fmt,p+off,life[key])
  n.pack('<I',p+0xcd0,a.actor(life['linked']));definition=x['definition'];n.pack('<I',a.DEF+definition*0x4c+0x24,EXTRA+definition*0x100);n.pack('<B',EXTRA+definition*0x100+0xf5,life['defaultE38'])

def readstate():
 state=[]
 for i in range(8):
  p=a.actor(i);x=dict(flags1fc=n.unpack('<I',p+0x1fc)[0],eec=n.unpack('<I',p+0xeec)[0],ef0=n.unpack('<I',p+0xef0)[0])
  for key,off,fmt in fields:x[key]=n.unpack('<'+fmt,p+off)[0]
  state.append(x)
 return state

def model(command,tokens,c,first,cached,state):
 state=copy.deepcopy(state);ev=[];enabled=True;reference=c['reference'] if c['creature'] else -1
 if command!='SetAIOverrideControl' and not first:return dict(result=1,cached=cached,state=state,events=ev)
 target=reference if command=='SetAIOverrideControl' else c['actors'][reference]['world'] if reference>=0 else -1
 if first:
  for raw in tokens:
   token=raw.split('\0')[0];low=token.lower();key='character' if command=='SetAIOverrideControl' else 'character='
   if key in low:
    name=token[low.index(key)+10:]
    if c['callback']:
     ev.append(['name',name]);found=a.resolve_name(c,name);target=found if command=='SetAIOverrideControl' else c['actors'][found]['world'] if found>=0 else -1
    elif command!='SetAIOverrideControl':target=-1
   elif command=='CannotDropIn' and 'tag_to=' in low:
    if c['callback']:ev.append(['name',token[low.index('tag_to=')+7:]])
   elif low=='false':enabled=False
  if command=='SetAIOverrideControl':cached=target
 if command=='SetAIOverrideControl':
  if cached>=0:
   actor=c['actors'][cached]['world']
   if enabled and actor>=0:
    linked=c['actors'][actor]['life']['linked']
    for i in [actor]+([linked] if linked>=0 else []):
     x=state[i];x['timer1010']=x['field1008']=0
     if x['blocked']:
      x['copy107f']=x['source107e'];x['blocked']=0;x['stateE38']=c['actors'][i]['life']['defaultE38'];x['stateE39']=4
   state[cached]['flags1fc']=(state[cached]['flags1fc']&~0x100)|(0x100 if enabled else 0)
 elif target>=0:
  field,bit=('eec',0x4000000) if command=='CannotDropIn' else ('ef0',0x1000000);state[target][field]=(state[target][field]&~bit)|(bit if enabled else 0)
 return dict(result=1,cached=cached,state=state,events=ev)

def run(command,ticks,o=None,source=None):
 global memory
 o=o or {};c=context(o);cached=o.get('cached',3);setup(c,ticks[0]['tokens'],cached);start=readstate();sequence=[]
 for tick in ticks:
  tokens=tick['tokens'];first=tick['first'];a.events.clear();n.write(a.ARGS,bytes(0x7000))
  for i,t in enumerate(tokens):n.pack('<I',a.ARGS+i*4,a.TEXT+i*256);n.write(a.TEXT+i*256,t.encode()+b'\0')
  expected=model(command,tokens,c,first,cached,start);mem=bytearray(n.read(D,0x57000));struct.pack_into('<I',mem,a.PACK+0x6c-D,a.actor(expected['cached']))
  for i,x in enumerate(expected['state']):
   p=a.actor(i)-D
   for key,off in [('flags1fc',0x1fc),('eec',0xeec),('ef0',0xef0)]:struct.pack_into('<I',mem,p+off,x[key])
   for key,off,fmt in fields:struct.pack_into('<'+fmt,mem,p+off,x[key])
  result=n.call(ADDR[command],[a.SYS if c['system'] else 0,a.PACK,a.CRE if c['creature'] else 0,a.ARGS,len(tokens),int(first)],count=1000000)
  got=dict(result=result,cached=a.aid(n.unpack('<I',a.PACK+0x6c)[0]),state=readstate(),events=a.events.copy());memory+=1;bad=[]
  if got!=expected:bad.append(dict(got=got,want=expected))
  if n.read(D,0x57000)!=mem:bad.append('collateral input write')
  if bad:errors.append(dict(command=command,tick=tick,options=o,bad=bad))
  sequence.append(dict(tokens=tokens,first=first,native=got));groups[command]=groups.get(command,0)+1;cached=expected['cached'];start=expected['state']
 rows.append(dict(command=command,context=c,initialCached=o.get('cached',3),ticks=sequence,source=source))

def main():
 ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses={r['name']:r['uses'] for r in ledger['rows'] if r['name'] in ADDR}
 for command,authored in uses.items():
  for source in authored:
   for scenario in range(3):run(command,[dict(tokens=source['args'],first=scenario!=2)],dict(callback=scenario!=1),source)
 tokenlists=[[],['FALSE'],['FALSE','TRUE'],['TRUE','FALSE'],['character=Alpha'],['character=missing'],['character=player'],['character=player_2'],['character=Player7'],['character=Beta','character=Alpha'],['character=Alpha','character=missing'],['tag_to=Beta'],['tag_to=missing','FALSE'],['tag_to=player','character=Beta'],['xcharacter=Beta','FALSE'],['characterXBeta'],['FALSE','character=Alpha','TRUE'],['character=Alpha\0tail']]
 for command in ADDR:
  for tokens in tokenlists:
   for o in [{},{'creature':False},{'reference':-1},{'callback':False},{'system':False},{'actorOverrides':{'0':{'world':2},'1':{'world':-1}},'lifeOverrides':{'2':{'linked':2,'blocked':3}}},{'lifeOverrides':{'0':{'linked':2,'blocked':0},'2':{'blocked':7}}}]:run(command,[dict(tokens=tokens,first=True)],o)
 for initial in range(8):
  ticks=[dict(tokens=['FALSE','character=Beta'],first=True)]+[dict(tokens=['FALSE','character=missing'],first=False) for i in range(15)];run('SetAIOverrideControl',ticks,dict(cached=initial))
 for cached in [-1,0,3,7]:
  for linked in [-1,0,1,3]:run('SetAIOverrideControl',[dict(tokens=['FALSE'],first=False)],dict(cached=cached,lifeOverrides={'0':{'linked':linked,'blocked':1},'3':{'linked':linked,'blocked':2},'7':{'linked':linked,'blocked':1}}))
 report=dict(binarySha256=n.sha256,checks=sum(groups.values()),mismatches=len(errors),groups=groups,fullRegionComparisons=memory,authoredUses={k:len(v) for k,v in uses.items()},persistentSequences=8,persistentTicks=128,examples=errors[:6],method='Original handlers and registered43c220 name resolver execute unchanged; only CRT Player%d formatting uses the existing bounded adapter. Full actor/controller/packet/source memory compared, including persistent callback state.',limits=['Attached finite actor/definition/tag state with valid pointer chains and ASCII operands. Actor allocation, lifecycle scheduling and downstream party/input consumers remain external.','AI override preserves native cached reference vs world-object distinction and first-call FALSE only. Runtime fields retain offsets until broader lifecycle meaning is proven.','Managed replay pending.'])
 (B/'reports/native-party-control-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-party-control-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
