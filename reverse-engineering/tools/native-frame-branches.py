"""Original frame player/menu/transition paths, with explicit subsystem adapters."""
import importlib.util,json,itertools,struct,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('frame',Path(__file__).with_name('native-frame-dispatch.py'));f=importlib.util.module_from_spec(spec);spec.loader.exec_module(f)
from unicorn import UC_HOOK_CODE
n=f.n;B=f.B;WORLD=f.WORLD;LEVEL=f.LEVEL;AREA=f.AREA
PLAYERS=WORLD+0x20000;PADS=WORLD+0x40000;DEST=WORLD+0x50000;SPECIAL=DEST+0x200;TABLE=DEST+0x1000;STATES=DEST+0x2000
QUERY=n.STOP+0x200;LEVELCALL=n.STOP+0x210;STATECALL=n.STOP+0x220
for address in [QUERY,LEVELCALL,STATECALL]:n.mu.hook_add(UC_HOOK_CODE,f.boundary,begin=address,end=address)
report={'binarySha256':n.sha256,'contracts':{},'failures':[],'vectors':[],'method':'Original complete0x491d50 in bounded worlds. Default direct subsystem callees are no-op adapters; transition suites also execute original0x5b1220 and0x5b11b0, with only their virtual state callback adapted.'}

def group(name):
 r={'cases':0,'assertions':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r

def check(r,meta,want,got,vector=False):
 r['cases']+=1;r['assertions']+=len(want)
 if got!=want:
  r['mismatches']+=1
  if len(r['examples'])<12:r['examples'].append({'input':meta,'expected':want,'actual':got})
 if vector:report['vectors'].append({'contract':next(k for k,v in report['contracts'].items()if v is r),'input':meta,'native':got})

def setup(paused=0,cut=0,flags=0):
 f.setup(paused,0,0,cut,0,flags,1/60);n.write(PLAYERS,bytes(0x40000));n.write(0x95077c,bytes(0x28));n.pack('<i',0x9507a0,-1);n.pack('<I',0x951354,TABLE);n.pack('<I',0x951b94,0);n.pack('<I',0x93b2a8,0);n.pack('<I',0x802e14,0x1234);n.pack('<I',WORLD+0x120,0)

def player(i,present=True,flags=0x80,pad=True):
 p=PLAYERS+i*0x2000;pd=PADS+i*0x60;n.pack('<I',0x93d7f0+i*4,p if present else 0)
 n.pack('<I',p+0x1fc,flags);n.pack('<I',p+0xca4,pd);n.pack('<I',p+0x7fc,p+0x1200);n.pack('<b',p+0x280,i if i<2 else -1);n.pack('<I',pd,0x123000+i if pad else 0)
 return p,pd

def call():n.call(0x491d50,[WORLD,WORLD+0x16500],count=1000000)
def events(addr):return [x for x in f.events if x['callee']==hex(addr)]

try:
 r=group('eight_player_cutscene_pad_dispatch')
 for mask,mode in itertools.product(range(256),range(3)):
  setup(cut=1);want=[]
  for i in range(8):
   present=bool(mask&(1<<i));flags=0x80 if mode!=1 or i%2 else 1;pad=mode!=2 or i%3!=0;p,pd=player(i,present,flags,pad)
   if present and flags&0x80 and pad:want.append(pd+0x40)
  call();got=[x['args'][0]for x in events(0x54a810)];check(r,{'mask':mask,'mode':mode},[want],[got])
 r=group('paused_wallet_callbacks_first_two_players')
 for mask,playerMask in itertools.product(range(256),range(4)):
  setup(paused=1);want=[]
  for i in range(8):
   p,pd=player(i,bool(mask&(1<<i)),0x80 if playerMask&(1<<(i%2))else 1)
   if i<2 and mask&(1<<i):want.append([p+0x1200,int(bool(playerMask&(1<<i))),i])
  call();got=[x['args'][:3]for x in events(0x570a80)];check(r,{'presentMask':mask,'playerMask':playerMask},[want],[got])
 r=group('player_position_array_and_secondary_managers')
 for mask,managerMask in itertools.product(range(256),range(4)):
  setup();positions=[]
  for i in range(8):
   p,pd=player(i,bool(mask&(1<<i)));positions.append(p+0x19c if mask&(1<<i)else 0)
  n.pack('<I',0x947bbc,1);n.pack('<I',WORLD+0x4670,0x10190000 if managerMask&1 else 0);n.pack('<I',WORLD+0x13c,0x10191000 if managerMask&2 else 0)
  call();got=[x['playerPositions']for x in events(0x546380)+events(0x545a80)]
  check(r,{'mask':mask,'managerMask':managerMask},[positions,positions,int(bool(managerMask&1)),int(bool(managerMask&2))],got+[len(events(0x43d0c0)),len(events(0x5f4b90))])
 r=group('menu_request_gate_and_controller_selection')
 for paused,gate,menu,query,cutPass,presence in itertools.product([0,1],range(11),[-1,0,1,4],[0,1],[0,1],range(3)):
  setup(paused=paused,cut=1);n.pack('<I',0x921e58,1);n.pack('<I',0x921dfc,1);n.pack('<h',0x921454,menu);n.pack('<I',0x926bd4,QUERY);f.options['returns']={QUERY:query,0x57cf70:cutPass,0x50b310:0}
  # Menu0 has class0; menu1 class1; menu4 class4.
  n.pack('<I',0x800aa8,0);n.pack('<I',0x800aa8+28,1);n.pack('<I',0x800aa8+112,4)
  for i in range(2):
   p,pd=player(i,presence==i+1);n.pack('<I',p+0xca4,0x9253b0+i*0x60)
  blocked={1:0x921e58,2:0x921dfc,3:AREA+0x7a,4:0x87658c,5:0x951b80,6:0x950780,7:0x87b4d8,8:0x855de0,9:0x951c58}
  if gate in blocked:
   addr=blocked[gate]
   if gate in [1,2]:n.pack('<I',addr,0)
   elif gate==3:n.pack('<B',addr,2)
   elif gate==6:n.pack('<f',addr,1)
   elif gate==5:n.pack('<I',addr,DEST);n.pack('<b',DEST+0xa3,-1)
   else:n.pack('<I',addr,1)
  if gate==10:f.options['returns'][0x50b310]=1
  # Suppress unrelated transition tail while checking menu entry gates.
  if gate in [4,5]:n.pack('<f',0x950780,1)
  call();allowed=(gate in [0,10]and not query and cutPass)
  expectedOpen=[presence-1]if allowed and menu==-1 and not paused and presence else []
  expectedSound=int(allowed and menu==0 and gate!=10)
  clear=allowed and menu!=-1 and(menu in [1,4]or gate==10)
  got=[[x['args'][0]for x in events(0x55c120)],len(events(0x509830)),n.unpack('<I',0x921dfc)[0],n.unpack('<I',0x921e58)[0]]
  check(r,{'paused':paused,'gate':gate,'menu':menu,'query':query,'cutPass':cutPass,'presence':presence},[expectedOpen,expectedSound,0 if clear or gate==2 else 1,0 if clear or gate==1 else 1],got)
 r=group('transition_tail_state_choice_and_native_state_helpers')
 for request,flags,destKind,areaId,sameArea,activeMode,areaFlag,slotEnabled in itertools.product([0,1],[0,0x400],range(6),[-1,0,1],[0,1],[0,1],[0,2],[0,1]):
  setup(flags=flags);destination=[0,LEVEL,DEST,SPECIAL,DEST+0x400,DEST+0x600][destKind]
  n.pack('<I',0x87658c,request);n.pack('<I',0x951b80,destination);n.pack('<I',0x951b94,SPECIAL);n.pack('<I',0x951b88,DEST+0x400);n.pack('<I',0x951b9c,DEST+0x600);n.pack('<I',0x93b2a8,activeMode);n.pack('<i',WORLD+0x120,areaId if sameArea else 9);n.pack('<B',AREA+0x7a,areaFlag)
  if destination:n.pack('<b',destination+0xa3,areaId)
  # Include index-1 as a readable preceding table row; valid-byte domain only.
  for aid in [-1,0,1]:n.pack('<B',TABLE+aid*0x9c+0x7a,areaFlag)
  n.pack('<I',0x950794,STATES if slotEnabled else 0);n.pack('<I',0x950798,STATES+0x20 if slotEnabled else 0)
  for p in [STATES,STATES+0x20]:n.pack('<I',p,STATES+0x40)
  n.pack('<I',STATES+0x48,STATECALL);f.options['allowOriginal']={0x5b1220,0x5b11b0}
  enabled=bool(request or destination);early=bool(enabled and flags&0x400 and destination and destination!=SPECIAL and areaId!=-1 and not areaFlag&2)
  selected=None
  if enabled and not early:
   if destination and destination!=LEVEL and(destination in[SPECIAL,DEST+0x400,DEST+0x600]or(activeMode and flags&0x400 and areaFlag&2)):selected=1
   elif destination and not sameArea and(not activeMode or areaFlag&2):selected=1
   else:selected=2
  call();gotSelected=[x['selectedState']for x in events(0x5b1220)];got=[gotSelected,n.unpack('<f',0x950780)[0],n.unpack('<I',0x802e14)[0],n.unpack('<i',0x9507a0)[0],n.unpack('<i',0x95078c)[0],len(events(STATECALL)),n.unpack('<I',WORLD+0x16500)[0]]
  want=[[selected]if selected is not None else [],1.0 if early else 0.0,0 if early else 0x1234,selected if selected is not None and slotEnabled else -1,2 if selected is not None else 0,int(selected is not None and slotEnabled),0]
  meta={'request':request,'levelFlags':flags,'destinationKind':destKind,'areaId':areaId,'sameArea':sameArea,'activeMode':activeMode,'areaFlags':areaFlag,'slotEnabled':slotEnabled}
  check(r,meta,want,got,True)
 r=group('transition_state_select_and_begin')
 for mask,initial,index,argument,phase in itertools.product(range(16),range(-1,4),range(-1,4),[0,0xffffffff],[-128,-1,0,2,127]):
  setup();f.options['allowOriginal']={0x5b1220,0x5b11b0};n.pack('<I',0x95077c,0xdeadbeef);n.pack('<f',0x950788,7.25);n.pack('<i',0x9507a0,initial)
  for i in range(4):
   p=STATES+0x20*i;n.pack('<I',0x950790+4*i,p if mask&(1<<i)else 0);n.pack('<I',p,STATES+0x100)
  n.pack('<I',STATES+0x108,STATECALL);n.pack('<i',TABLE,index)
  returned=n.call(0x5b1220,[TABLE,argument],regs={f.UC_X86_REG_ECX:0x95077c})
  n.call(0x5b11b0,[phase],regs={f.UC_X86_REG_ECX:0x95077c})
  accepted=index!=-1 and bool(mask&(1<<index));want=[int(accepted),index if accepted else -1,argument if accepted else 0xdeadbeef,phase,0.0,int(accepted)]
  got=[returned,n.unpack('<i',0x9507a0)[0],n.unpack('<I',0x95077c)[0],n.unpack('<i',0x95078c)[0],n.unpack('<f',0x950788)[0],len(events(STATECALL))]
  check(r,{'mask':mask,'initial':initial,'index':index,'argument':argument,'phase':phase},want,got,True)
except Exception as e:report['failures'].append({'error':str(e),'contracts':{k:v['cases']for k,v in report['contracts'].items()}})
report['totals']={'cases':sum(v['cases']for v in report['contracts'].values()),'assertions':sum(v['assertions']for v in report['contracts'].values()),'mismatches':sum(v['mismatches']for v in report['contracts'].values()),'failures':len(report['failures'])}
report['limits']=['Subsystem calls outside5b1220/5b11b0 remain explicit no-op adapters. This is not a live frame or a complete game.','Menu, secondary manager and player tests verify dispatcher calls/argument selection only.','Transition state objects are synthetic; their virtual callbacks are recorded and return without side effects.','Finite delta/timers and valid record layouts; malformed pointers excluded.']
(B/'reports/native-frame-branches.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({'totals':report['totals'],'failures':report['failures'],'examples':{k:v['examples'][:2]for k,v in report['contracts'].items()if v['mismatches']}},indent=2));raise SystemExit(1 if report['totals']['mismatches']or report['failures']else 0)
