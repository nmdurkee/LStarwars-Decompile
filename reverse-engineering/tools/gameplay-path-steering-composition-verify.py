"""Actual steering -> neighboring-path and game-mode callback compositions."""
import importlib.util,json,copy,struct,itertools,random
from pathlib import Path
def load(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
st=load('steering','gameplay-path-steering-verify.py');dp=load('dispatch','gameplay-path-dispatch-verify.py');tr=load('transition','gameplay-path-transition-verify.py');r=st.r;n=r.x.NativeX86();BASE=r.BASE;D=n.DATA;A=st.A;P=st.P;REF=st.REF;PATH=st.PATH;NODES=st.NODES;EDGES=st.EDGES;QUERY=st.QUERY;NEXT=PATH+0x100;NEXTNODES=D+0x80000;NEXTEDGES=D+0x81000;NEXTADJ=D+0x82000;CAND=D+0x83000;NEXTCAND=D+0x84000;CTX=D+0x85000;SYS=D+0x86000;GROUPS=D+0x87000;LIST=D+0x88000;MASKS=D+0x89000;ATTACH=D+0x96000;CHAR=D+0x97000;TUNING=D+0x97100
from unicorn import UC_HOOK_CODE
st.n=n;st.rt.n=n;st.CTX=CTX;dp.n=n;dp.A=A;dp.P=P;dp.REF=REF;dp.QUERY=QUERY;tr.PATHS=PATH
events=[];options={};calls={};cases=[];errors=[];counts={}
def hook(mu,address,size,user):
 global events
 sp=mu.reg_read(st.UC_X86_REG_ESP);calls[hex(address)]=calls.get(hex(address),0)+1
 if address in [0x4078d0,0x4813d0,0x4cbba0]:events.append(['special',*n.unpack('<III',sp+4)]);dp.EDGE=n.unpack('<I',P+0x15c)[0]
 elif address==0x51d5e0:events.append(['transition',*n.unpack('<II',sp+4)])
 else:dp.hook(mu,address,size,user)
for address in dp.handlers|{0x52c790,0x43c9a0,0x4078d0,0x4813d0,0x4cbba0,0x51d5e0}:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
for address in [0x51a7c0,0x51d1f0,0x51d750]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,p,s,u:calls.__setitem__(hex(p),calls.get(hex(p),0)+1),begin=address,end=address)
def actionOptions(z,o):
 v=copy.deepcopy(o.get('dispatch',{}));actor=z['actor'];edge=z['edges'][st.eptr(r.u(actor,0x2c8+0x15c))];v.update(flags=r.u(actor,0x2c8+0x1e8),capabilities=r.u(actor,0x2c8+0x1f4),direction=actor[0x2c8+0x160],requirements=[r.u(edge,0),r.u(edge,4)],endpoints=list(edge[0x10:0x12]));return v
def setupSpecial(o,mode):
 global events,options
 st.tg.PATH=PATH;st.tg.EDGES=EDGES;before=st.setup(o);n.pack('<I',0x9238fc,mode);actor=before['actor'];reference=before['reference'];v=o.get('dispatch',{})
 for offset,value,size in [(0x54,CHAR,4),(0xca4,ATTACH,4),(0x7b5,v.get('state',0),1),(0x7c5,v.get('actorFlags',0),1),(0xea4,v.get('link',0),4)]:r.put(actor,offset,value,size)
 r.put(reference,0,A);r.put(reference,4,P);r.put(reference,0x292,v.get('referenceFlags',0x4321),2);n.write(A,actor);n.write(REF,reference);n.pack('<I',CHAR+0x24,TUNING);n.pack('<B',TUNING+0x90,v.get('tuning',0));n.pack('<I',ATTACH+8,v.get('attachment',0x1234));n.pack('<I',0x802278,v.get('specialMask',0x240));n.pack('<f',0x876ce4,r.f(v.get('gate',1)));before['attachment']=v.get('attachment',0x1234);events=[];dp.events=events;options=o;dp.options=v;return before
def specialModel(z,o,ev):
 mode=int(o['mode'],16);v=actionOptions(z,o);dp.NODES=NODES;result,actor,reference,attachment,subevents=dp.model((z['actor'],z['reference']),v,mode);z['actor'][:]=actor;z['reference'][:]=reference;z['attachment']=attachment;ev.extend(subevents);return result
def transitionSetup(o):
 global events
 st.tg.PATH=PATH;st.tg.EDGES=EDGES;before=st.setup(o);n.pack('<I',0x9238fc,0);n.pack('<I',CTX+0x10,SYS);n.pack('<I',SYS+0xc,GROUPS);n.pack('<B',GROUPS,1);n.pack('<I',GROUPS+4,LIST);n.pack('<I',LIST,NEXT);n.pack('<BI',PATH+0x7a,2,0);n.pack('<I',PATH+0x7c,NODES);n.pack('<I',PATH+0x8c,CAND)
 for i in range(3):n.pack('<BBh',CAND+4*i,i,0,0)
 for i,p in enumerate(before['nodes']):p[0x30]=0;n.pack('<B',NODES+i*0x5c+0x30,0)
 before['g']['candidateCount']=2;before['g']['candidates']=[0,1,2]
 n.write(NEXT,bytes(0x100));n.pack('<B',NEXT+0x10,4);n.pack('<B',NEXT+0x14,3);n.pack('<B',NEXT+0x7a,2);n.pack('<I',NEXT+0x7c,NEXTNODES);n.pack('<I',NEXT+0x80,NEXTEDGES);n.pack('<I',NEXT+0x88,MASKS);n.pack('<I',NEXT+0x8c,NEXTCAND)
 for i,mask in enumerate([1,2,0x100000000]):n.pack('<Q',MASKS+0x28*i+0x18,mask)
 for i in range(3):n.pack('<BBh',NEXTCAND+4*i,i,0,0);n.write(NEXTEDGES+i*0x24,before['edges'][i])
 position=o.get('neighborOffset',[30,0,0]);nextg=copy.deepcopy(before['g']);nextg['candidateCount']=2;nextg['candidates']=[0,1,2];ad=NEXTADJ
 for i,p in enumerate(nextg['points']):
  p['position']=[r.f(a+b) for a,b in zip(p['position'],position)];p['radius']=r.f(o.get('neighborRadius',2));node=bytearray(0x5c);st.storevec(node,4,p['position']);r.put(node,0x10,r.bits(p['radius']));r.put(node,0x28,len(p['edges']),1);r.put(node,0x34,ad);n.write(NEXTNODES+i*0x5c,node)
  for e in p['edges']:n.pack('<I',ad,NEXTEDGES+e*0x24);ad+=4
 before['nextg']=nextg;events=[];return before
def transitionModel(z,o):
 pp=[[p['position'] for p in z['g']['points']],[p['position'] for p in z['nextg']['points']]];query=st.floats(z['actor'],0x2c8+0x1b4);options=dict(position=st.floats(z['reference'],0x5c),links=[0,0,0],groupIndices=[0,0],groups={'0':[1]},target=-1);result,actor,_=tr.model(z['actor'],pp,[[0,1],[0,1]],query,options)
 if result!=1:raise AssertionError('Expected neighboring path selection')
 z['actor'][:]=actor;z['g']=z['nextg'];st.tg.PATH=NEXT;st.tg.EDGES=NEXTEDGES
def runSpecial(mode,o):
 o=dict(o,callback=True,mode=hex(mode));before=setupSpecial(o,mode);expected,ev=st.model(before,o,special=specialModel)
 for i,p in enumerate(expected['q']['nodes']):
  c=p['cache'];r.put(expected['nodes'][i],0x2e,c[0],1);r.put(expected['nodes'][i],0x2f,c[1],1);r.put(expected['nodes'][i],0x38,r.bits(c[2]));r.put(expected['nodes'][i],0x3c,r.bits(c[3]))
 n.call(0x51d7b0,[CTX,P,REF,QUERY],count=500000);got=st.summary(before,st.snapshot(before),events);want=st.summary(before,expected,ev);got['attachment']=n.unpack('<I',ATTACH+8)[0];want['attachment']=expected['attachment'];record('special',o,got,want)
def runTransition(o):
 o=dict(newTarget=True,targetFlags=4,target=[0,0,0],position=[0,0,0],**o);before=transitionSetup(o);expected,ev=st.model(before,o,transition=transitionModel);n.call(0x51d7b0,[CTX,P,REF,QUERY],count=500000);got=st.summary(before,st.snapshot(before),events);want=st.summary(before,expected,ev);record('transition',o,got,want);st.tg.PATH=PATH;st.tg.EDGES=EDGES
def record(kind,o,got,want):
 cases.append(dict(kind=kind,options=o,native=got));counts[kind]=counts.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,options=o,got=got,want=want))
def main():
 for mode in [0x4078d0,0x4813d0,0x4cbba0]:
  for requirement,permission,state,tuning,ret in itertools.product([0,1,4,8,0x10,0x18,0x23,0x40,0x400,0x1000,0x8000,0xc0000,0x300000,0x20000000,0x80000000],[0,0xffffffff],[0,91],[0,0x40],[0,1]):runSpecial(mode,dict(current=0,targetEdge=0,requirements=[[requirement,requirement],[0,0],[0,0]],permission=permission,dispatch=dict(state=state,tuning=tuning,handlerReturn=ret)))
  for actorFlags,gate,tailReturn in itertools.product([0,2],[-1,0,1],[0,1]):runSpecial(mode,dict(current=0,targetEdge=2,dispatch=dict(actorFlags=actorFlags,gate=gate,tailReturn=tailReturn)))
 for offset,radius,current in itertools.product([[30,0,0],[-30,0,0],[0,3,10]],[1,2,3.5],[0,1,2]):runTransition(dict(neighborOffset=offset,neighborRadius=radius,current=current))
 report=dict(binarySha256=n.sha256,checks=len(cases),counts=counts,mismatches=len(errors),examples=errors[:3],actualCalls=calls,newNativeEntryCredits=0,limits=['Special action bodies,52c790 state switch and43c9a0 relocation are explicit return/event adapters; actual three registered callbacks execute.','Neighboring-path selection,51a7c0 rebind and both target ensures execute original code. Static finite test graphs; no live game.']);(BASE/'reports/gameplay-path-steering-composition-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-path-steering-composition-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
