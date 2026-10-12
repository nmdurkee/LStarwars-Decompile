"""Native connection-controller differential tests and compact portable oracles."""
import importlib.util,json,itertools,random,math,struct,hashlib
from pathlib import Path
s=importlib.util.spec_from_file_location('fixture',Path(__file__).with_name('native-connections-fixture.py'));f=importlib.util.module_from_spec(s);s.loader.exec_module(f)
n=f.n;BASE=f.BASE;cases=[];errors=[];counts={};active=None

def check(group,want,got,inputs,source=None):
 counts[group]=counts.get(group,0)+1
 if want!=got:errors.append({'group':group,'input':inputs,'expected':want,'native':got})
 cases.append({'group':group,'input':inputs,'native':got,'source':source})
def expected_command(tokens,first,opts):
 p=f.parse(tokens,opts);got={'result':1,'created':False,'record':None,'calls':[],'ranges':[]}
 if not first:return got
 got['calls']=p['calls'].copy();edge=p['from']is not None and p['to']is not None and p['from'].lower()!=p['to'].lower()and not opts.get('connectionMissing',False)
 if edge and p['kind']!=5 and(p['target']is not None or p['kind']!=0):got['calls'].append(['target',p['kind'],p['target']])
 if not f.valid_creation(p,opts):return got
 kind=p['kind'];mask=[0]*32
 for start,stop in p['ranges']:f.mask_range(mask,kind,opts.get('end',60.),start,stop,opts.get('noAnimation',False))
 direction=int(opts.get('reverse',False))
 target=[f.SCENE,f.INSTANCE,0]if kind==0 else[p['fake']&0xffffffff,0,0]if kind==5 else[f.OBJ,0,0]
 got.update(created=True,record={'on':p['on'],'off':p['off'],'mask':mask,'kind':kind,'pathIndex':0,'flags':direction|int(p['both'])*2|int(p['visible'])*4|int(p['onObstacle'])*8|int(p['offObstacle'])*16,'connection':edge,'targetWords':target,'output':p['output']},ranges=p['ranges'])
 return got

def command(tokens,first=1,source=None,**opts):
 global active
 parsed=f.parse(tokens,opts)
 # Author-supplied endpoint names are resolved to two fixture locator records.
 a,b=parsed['from']or'a',parsed['to']or'b'
 opts=dict(opts,fromName=b if opts.get('reverse')else a,toName=a if opts.get('reverse')else b)
 active={'tokens':tokens,'first':first,'options':opts};got=f.command(tokens,first,**opts);check('command',expected_command(tokens,first,opts),got,active,source)

def record_target(kind):
 n.pack('<B',f.POOL+0xa4,kind);n.pack('<3I',f.POOL+12,*([f.SCENE,f.INSTANCE,0]if kind==0 else[0,0,0]if kind==5 else[f.OBJ,0,0]))

def enabled(kind,opts,mask,flags):
 if kind in[0,1,5]:
  if kind==0 and flags&4 and not opts.get('visible',True):return False
  end=min(1024,math.trunc(opts.get('end',60.)));current=math.trunc(opts.get('frame',1.))
  index=0 if kind==0 and opts.get('noAnimation')else(1 if current<1 else min(end,current))-1
  return bool(mask[index//32]&(1<<(index%32)))
 if kind==2:return opts.get('buildState',2)==2
 if kind==3:return opts.get('output',0)!=0
 if kind==4:return opts.get('blowupFlags',0)&1==0
 if kind==6:return bool(opts.get('flowFlags',2)&2)
 if kind==7:
  a,b,t=opts.get('forceFlags',0),opts.get('forceFlags2',0),opts.get('forceTimer',0.)
  return a&2==0 and(t<=0 or b&0x2000!=0)and(a&0x40==0 or b&0x800!=0)and(not opts.get('forceHasObstacle',False)or opts.get('obstacleState',2)==(0 if b&0x40 else 2))
 if kind==8:return opts.get('obstacleState',2)==2
 if kind==9:return opts.get('zipFlags',0xc0)&0xc0==0xc0
 return True

def update(kind,flags,on,off,mask,**opts):
 global active
 active={'kind':kind,'flags':flags,'on':on,'off':off,'mask':mask,'options':opts};f.setup(**opts)
 n.pack('<II',f.MANAGER+16,f.POOL,f.POOL);n.pack('<II',f.POOL,0,0);n.pack('<I',f.POOL+8,f.CNX);record_target(kind);n.pack('<II',f.POOL+0x1c,on,off);n.pack('<32I',f.POOL+0x24,*mask);n.pack('<H',f.POOL+0xa6,flags);n.pack('<I',f.POOL+0x18,opts.get('outputIndex',0))
 before=n.read(f.POOL,0xa8);edge_before=n.read(f.CNX,0x18);n.call(0x43d0c0,[f.MANAGER]);after=n.read(f.POOL,0xa8);edge_after=n.read(f.CNX,0x18)
 state=enabled(kind,opts,mask,flags);newflags=(flags&~0x20)|(0x20 if state else 0);edge=list(opts.get('edgeFlags',(0x12345678,0x87654321)));side=flags&1
 for i in([side,side^1]if flags&2 else[side]):edge[i]=(edge[i]&~(off if state else on))|(on if state else off)
 want={'flags':newflags,'edgeFlags':edge,'edgeObstacle':int(bool(flags&(8 if state else 16))),'calls':[['output',opts.get('outputIndex',0)]]if kind==3 else[],'unexpectedRecordBytes':[],'unexpectedEdgeBytes':[]}
 got={'flags':n.unpack('<H',f.POOL+0xa6)[0],'edgeFlags':list(n.unpack('<II',f.CNX)),'edgeObstacle':n.read(f.CNX+0x16,1)[0],'calls':f.calls.copy(),'unexpectedRecordBytes':[i for i,(a,b)in enumerate(zip(before,after))if a!=b and i not in[0xa6,0xa7]],'unexpectedEdgeBytes':[i for i,(a,b)in enumerate(zip(edge_before,edge_after))if a!=b and i not in list(range(8))+[0x16]]}
 check('update',want,got,active)

try:
 allnames=sorted(set().union(*[set(t)for t in f.TABLES]))+['BLOCK','BIGJUMP','REQUIRESPERMISSION','NO_DESTINATION_CHECK','unknown','DBLJUMP\0extra']
 for mode,name,fallback in itertools.product(range(3),allnames,[(4,0x1000000,0x4000000),(0xaaaa5555,0x80000000,0xffffffff)]):
  f.setup(mode=mode,fallback=fallback);n.write(f.TEXT,name.encode()+b'\0');got=n.call(0x44d870,regs={f.UC_X86_REG_ESI:f.TEXT});check('flag_lookup',f.flag(name,mode,fallback),got,{'mode':mode,'name':name,'fallback':list(fallback)})
 forms=[[],['from=a','to=b'],['from=a','to=b','obj=x'],['from=a','to=b','fakeanimid=0'],['from=a','to=b','fakeanimid=-1'],['from=a','to=b','fakeanimid=1'],['from=a','to=b','obj=x','bothways','checkvisible','on_flag=BLOCK','off_flag=JUMP','on_frames=1tolastframe'],['from=a','to=b','on_flag=OBSTACLE_OPEN','off_flag=OBSTACLE_CLOSED','gizmo=x'],['from=a','to=b','cutscene=x','on_frames=lastframe-1TOlastframe'],['from=a','to=b','pathname=x','flowbox=x','gizmo_output=3'],['from=a','to=b','obj=x','on_frames=5to2','on_frames=8tolastframe-1','on_frames=1to1'],['from=a','to=b','on_flag=BLOCK','on_flag=JUMP','off_flag=OBSTACLE_OPEN','on_flag=OBSTACLE_OPEN','on_flag=OBSTACLE_CLOSED','blowup=x'],['from=a','to=b','obj=x','fakeanimid=0','force=x'],['from=a','to=b','fakeanimid=0','obj=x'],['prefixFROM=a','prefixTO=b','prefixOBJ=x','prefixON_FLAG=BLOCK'],['from=a','to=b','obj=x','on_frames=alphaTOgamma'],['from=a','to=b','obj=x\0gizmo=y','checkvisible\0ignored']]
 forms.extend([['from=a','to=b',key+'=x','on_frames=1tolastframe']for key in['obj','cutscene','buildit','gizmo','flowbox','blowup','force','obstacle','zipup']])
 for tokens,first,mode,reverse in itertools.product(forms,[0,1],range(3),[False,True]):command(tokens,first,mode=mode,reverse=reverse)
 for kind in ['obj=x','cutscene=x','buildit=x','gizmo=x','flowbox=x','blowup=x','force=x','obstacle=x','zipup=x','fakeanimid=0']:
  for missing,capacity in itertools.product([False,True],[0,1]):command(['from=a','to=b',kind],targetMissing=missing,capacity=capacity)
 for tokens in [['from=a','to=b','obj=x'],['from=a','to=b','fakeanimid=-1'],['from=a','to=b','fakeanimid=0'],['from=a','to=b','fakeanimid=1']]:command(tokens,connectionMissing=True)
 rng=random.Random(0x43d0c0)
 for kind in range(10):
  for flags,variant in itertools.product(range(64),range(8)):
   opts={'visible':bool(variant&1),'noAnimation':bool(variant&2),'end':[1.,2.,31.,32.,33.,60.9,1024.,2000.][variant],'frame':[-3.2,.5,1.,2.,32.9,64.,1024.,3000.][variant],'buildState':variant,'output':variant&1,'blowupFlags':variant,'flowFlags':variant,'forceFlags':[0,2,0x40,0x42,0,0x40,0,0][variant],'forceFlags2':[0,0,0x800,0x2000,0x40,0x840,0x2000,0][variant],'forceTimer':[-1.,0.,1.,0.,3.,0.,1.,0.][variant],'forceHasObstacle':bool(variant&4),'obstacleState':variant%3,'zipFlags':[0,0x40,0x80,0xc0,0xffff,0xffbf,0xff7f,0x100][variant],'outputIndex':variant,'edgeFlags':[rng.getrandbits(32),rng.getrandbits(32)]}
   mask=[rng.getrandbits(32)for _ in range(32)];update(kind,flags|0xa500,rng.getrandbits(32),rng.getrandbits(32),mask,**opts)
 for kind,end,start,stop in itertools.product(range(10),[0.,1.,2.,31.,32.,33.,60.5,1024.,1200.],[-3,-2,-1,0,1,2,32,33,1024,2000],[-2,-1,0,1,2,32,33,1024,2000]):
  f.setup(end=end);record_target(kind);mask=[0]*32;f.mask_range(mask,kind,end,start,stop);n.call(0x43cfb0,[f.POOL,start,stop]);check('frame_mask',mask,list(n.unpack('<32I',f.POOL+0x24)),{'kind':kind,'end':end,'start':start,'stop':stop})
 # Pool release/reset/reuse verifies the original list helpers without adapters.
 for capacity in range(1,9):
  f.setup(capacity=capacity);free=list(range(capacity));active_ids=[];steps=[]
  def lists():
   result={}
   for name,off in [('free',8),('active',16)]:
    ids=[];ptr=n.unpack('<I',f.MANAGER+off)[0]
    while ptr:
     if len(ids)>capacity:raise ValueError('Native list cycle')
     ids.append((ptr-f.POOL)//0xa8);ptr=n.unpack('<I',ptr)[0]
    result[name]=ids
   return result
  for iteration in range(40):
   op='reset'if iteration%17==16 else'release'if iteration%3==2 and active_ids else'create'
   if op=='reset':n.call(0x43cc30,[f.MANAGER]);free=list(range(capacity));active_ids=[];step={'op':op}
   elif op=='release':
    selected=active_ids.pop(0);n.call(0x43cf70,[f.MANAGER,f.POOL+0xa8*selected]);free.append(selected);step={'op':op,'index':selected}
   else:
    n.write(f.TEXT,b'a\0');n.write(f.TEXT+32,b'b\0');n.write(f.TEXT+64,b'x\0');value=n.call(0x43cca0,[f.MANAGER,f.NAV,0,f.TEXT,f.TEXT+32,2,f.TEXT+64,-1,0]);selected=free.pop(0)if free else-1
    if selected>=0:active_ids.append(selected)
    step={'op':op,'returned':(value-f.POOL)//0xa8 if value else-1};check('pool-allocation-return',selected,step['returned'],{'capacity':capacity,'iteration':iteration})
   got=lists();check('pool-list-order',{'free':free.copy(),'active':active_ids.copy()},got,{'capacity':capacity,'step':step,'iteration':iteration});steps.append(dict(step,native=got))
  # Save one compact multi-operation sequence as an additional oracle record.
  cases.append({'group':'pool_sequence','input':{'capacity':capacity,'steps':steps},'native':lists()});counts['pool_sequence']=counts.get('pool_sequence',0)+1
 # Two controllers on one edge are deliberately order-sensitive. Exercise the
 # original parser, allocator, range mask, updater and release as one chain.
 for on_a,off_a,on_b,off_b in [(0x80000000,0,1,0x80000000),(3,7,7,3),(0xffffffff,0,0,0xffffffff)]:
  f.setup(capacity=2);n.write(f.TEXT,b'a\0');n.write(f.TEXT+32,b'b\0');n.write(f.TEXT+64,b'x\0');controllers=[]
  for on,off in[(on_a,off_a),(on_b,off_b)]:
   record=n.call(0x43cca0,[f.MANAGER,f.NAV,0,f.TEXT,f.TEXT+32,2,f.TEXT+64,-1,0]);n.pack('<II',record+0x1c,on,off);n.pack('<H',record+0xa6,2);controllers.append(record)
  n.call(0x43d0c0,[f.MANAGER]);want=list((0x12345678,0x87654321))
  for on,off in[(on_a,off_a),(on_b,off_b)]:want=[(x&~off)|on for x in want]
  check('shared-edge-update-order',want,list(n.unpack('<II',f.CNX)),{'onA':on_a,'offA':off_a,'onB':on_b,'offB':off_b})
 ledger=json.loads((BASE/'reports/gameplay-command-semantic-coverage.json').read_text());uses=next(r['uses']for r in ledger['rows']if r['name']=='CnxController')
 for use in uses:
  for first,target_missing in itertools.product([0,1],[False,True]):command(use['args'],first,source={'path':use.get('source'), 'line':use.get('line')},targetMissing=target_missing)
except Exception as e:errors.append({'fixtureFailure':str(e),'input':active})
report={'binarySha256':n.sha256,'groups':counts,'totals':{'cases':len(cases),'mismatches':len([e for e in errors if'fixtureFailure'not in e]),'failures':len([e for e in errors if'fixtureFailure'in e]),'authoredUses':len(uses)if'uses'in globals()else 0},'examples':errors[:24],'method':'Original CnxController, flag decoders, constructor, path/connection matching, pool/list operations, range mask builder and connection updater execute in isolated x86. World target/path lookups and generic gizmo-output callback are explicit adapters; original duration, force condition and visibility helpers execute unchanged.','limits':['Synthetic world/locator/target bindings, not whole-level reachability.','Bounded finite numeric fields, valid target pointers, NUL-terminated byte strings and on_frames suffix shorter than native64-byte buffer.','Update fixtures require end frame>=1 and a nonnull connection; observed invalid fake-ID/null-connection constructor behavior is recorded but not executed in updater.','No live navigation/pathfinder or character locomotion.','Compiled portable execution must be reported separately.']}
(BASE/'reports/native-connections-tests.json').write_text(json.dumps(report,indent=2)+'\n');(BASE/'reports/native-connections-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'cases':cases},separators=(',',':'))+'\n');print(json.dumps(report['totals']));print(json.dumps(errors[:3]))
raise SystemExit(1 if errors else 0)
