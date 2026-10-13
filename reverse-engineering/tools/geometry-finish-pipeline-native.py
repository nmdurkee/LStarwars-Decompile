"""Populated original normal finish: queue, static patches, shader completion."""
import ast,importlib.util,json,gzip,struct,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';BASE=0x973dbc;GLOBAL=0x9868a0
s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
def functions(path,names,ns):
 text=(B/path).read_text();tree=ast.parse(text)
 for node in tree.body:
  if isinstance(node,ast.FunctionDef)and node.name in names:exec(compile(ast.Module(body=[node],type_ignores=[]),path,'exec'),ns)
 return text,tree
qn={'BASE':BASE,'struct':struct};functions('tools/geometry-dynamic-queue-native.py',{'u','h','w','wh','signed','hs','key','refresh','construct','flush'},qn)
en={'BASE':BASE,'struct':struct};functions('tools/geometry-shader-emission-native.py',{'u','w','hh','wh','align','payload','append','emit'},en)
sn={'BASE':BASE,'struct':struct};st,tree=functions('tools/geometry-sorted-packets-native.py',{'u','h','w','resetctx','resetshader','complete_model'},sn)
old="     if get(get(record+8)+0x20)!=get(shader+0x20):raise ValueError('Fixture crosses unknown shader emission gate')"
node=next(t for t in tree.body if isinstance(t,ast.FunctionDef)and t.name=='complete_model');model=ast.get_source_segment(st,node)
assert model.count(old)==1
sn['emit_cpu']=en['emit'];exec(model.replace(old,"     changed,inner=emit_cpu(b,record,shader,allocator,descriptor,tokenBase);b[:]=changed;trace.extend([[address]for address in inner[1:]])"),sn)
u=qn['u'];h=qn['h'];w=qn['w'];wh=qn['wh'];memory=bytearray();calls=[];cases=[];errors=[];counts={'cases':0,'sources':0,'queuedAdds':0,'clipPatches':0,'alphaPatches':0,'materialPatches':0,'changedShaderCalls':0,'appendCalls':0,'checkedBytes':0}
def alloc(size,seed=0):
 p=(BASE+len(memory)+15)&~15;memory.extend(bytes(p-BASE-len(memory)));memory.extend(bytes(((i*37+seed*19)^(i>>3))&255 for i in range(size))if seed else bytes(size));return p
def observe(mu,address,size,_):calls.append(address)
for address in [0x5f0d70,0x4ffaa0,0x4ffac0,0x5de440,0x5de390,0x5de100,0x603440,0x603450,0x603460,0x603480,0x603490,0x603920,0x5df910,0x5df880,0x5e0bd0,0x5e0d00,0x5fca40,0x5fca70,0x5fca80,0x607590,0x5fd100,0x6034b0,0x5fcdf0,0x5fcef0,0x5fcf30,0x5fcf60,0x5fcfd0]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def patchmaterials(b,owner,mode):
 count=u(b,owner+0x4c);mt=u(b,owner+0x50)
 if not mt or not count or not u(b,mt):return
 parity=(u(b,owner+0x74)>>15)&1;curr=u(b,owner+0x58+parity*4);prev=u(b,owner+0x58+(1-parity)*4)
 for i in range(count):
  if b[curr-BASE+i//8]==b[prev-BASE+i//8]:continue
  record=u(b,u(b,owner+0x54)+i*4);material=u(b,mt+u(b,record+4)*4);active=bool(b[curr-BASE+i//8]&(1<<(i&7)))
  if material:
   a,bb,c=b[material-BASE+248:material-BASE+251];active=active and(a!=255 if mode!=1 else a==255 or a+bb+c==0)
  b[u(b,record+12)-BASE+1]=0 if active else 1
def patchclips(b,owner):
 count=u(b,owner+0x10);parity=(u(b,owner+0x74)>>15)&1;curr=u(b,owner+0x30+parity*4);prev=u(b,owner+0x30+(1-parity)*4);items=u(b,owner+8)
 for i in range(count):
  word=(i//16)*4
  if b[curr-BASE+word:curr-BASE+word+4]==b[prev-BASE+word:prev-BASE+word+4]:continue
  value=3 if((b[curr-BASE+i//4]>>((i&3)*2))&3)else 0;indices=u(b,u(b,owner+0x14)+i*12+8)
  for j in range(h(b,u(b,owner+0x18)+i*2)):
   p=items+u(b,indices+j*4)*16;b[p-BASE+1]=value;b[p-BASE-15]=value
def patchalpha(b,owner):
 alpha=u(b,owner+0x68)
 if not alpha:return
 for i in range(u(b,owner+0x10)):
  indices=u(b,u(b,owner+0x14)+i*12+8);value=struct.unpack_from('<f',b,alpha-BASE+i*4)[0];word=0 if value<0 else 0x3f800000 if value>1 else u(b,alpha+i*4)
  for j in range(h(b,u(b,owner+0x18)+i*2)):
   p=u(b,owner+8)+u(b,indices+j*4)*16
   if b[p-BASE]==0x82 and b[p-BASE+1]:w(b,u(b,p-12)+60,word)
def finish(before,registered,control,descriptor,token,mode):
 b,inner=qn['flush'](before);b=bytearray(b);trace=[0x5f0d70,0x4ffaa0]+inner+[0x603920,0x5e0bd0];patchmaterials(b,BASE,mode)
 for owner in registered:
  flags=u(b,owner+0x74)
  if flags&4:trace.extend([0x5df910,0x5df880]);patchclips(b,owner);patchalpha(b,owner)
  if flags&6:trace.append(0x5e0bd0);patchmaterials(b,owner,mode)
 b[0x973f34-BASE:0x973f94-BASE]=b[0x973ed4-BASE:0x973f34-BASE]
 sn.update(allocator=control,descriptor=descriptor,tokenBase=token);b,inner,processed=sn['complete_model'](b,u(b,BASE+0x110),registered,GLOBAL);trace.extend(row[0]for row in inner);trace.append(0x4ffac0);return b,trace,processed
def setupqueue():
 cap=4;mt=alloc(cap*4);rt=alloc(cap*4);nodes=alloc(600*36);adds=alloc(cap*4);refs=alloc(cap);pool=alloc(cap*128);used=alloc(cap);bits=[alloc(4),alloc(4)]
 for offset,value in [(0x4c,cap),(0x50,mt),(0x54,rt),(0x58,bits[0]),(0x5c,bits[1]),(0x64,nodes),(0x90,cap),(0x94,adds),(0xa0,refs),(0xa4,0x1234),(0xa8,pool),(0xb0,used)]:w(memory,BASE+offset,value)
 memory[bits[0]-BASE]=15;memory[bits[1]-BASE]=0
 for i in range(cap):
  record=alloc(68);material=alloc(708);w(memory,rt+i*4,record);w(memory,adds+i*4,material);wh(memory,material,(i-2&255)<<4);wh(memory,material+0x76,i);memory[material-BASE+248:material-BASE+251]=bytes([[0,0,0],[255,0,0],[1,0,0],[0,1,0]][i])
def staticscene(raw,render,metadata,pattern):
 a=render['address'];ru=lambda p:struct.unpack_from('<I',raw,p)[0];rh=lambda p:struct.unpack_from('<H',raw,p)[0]
 def ptr(p):
  d=struct.unpack_from('<i',raw,p)[0];return p+d if d else 0
 mc=ru(a+0x4c);mt=ptr(a+0x50);rt=ptr(a+0x54);dc=ru(a+0x60);dp=ptr(a+0x64)
 owner=alloc(0x94);table=alloc(mc*4);records=alloc(mc*4);shader=alloc(420,pattern+3);bitbytes=(mc+7)//8;bits=[alloc(bitbytes+16),alloc(bitbytes+16)];flags=[2,4,6][pattern%3]|((pattern&1)<<15)|([0,1,0x55,255][pattern%4]<<5)
 for off,value in[(0x4c,mc),(0x50,table),(0x54,records),(0x58,bits[0]),(0x5c,bits[1]),(0x74,flags),(0x80,shader)]:w(memory,owner+off,value)
 w(memory,shader+0x20,0x76543210)
 for off in[0x34,0x110,0x168,0x180,0x198]:w(memory,shader+off,0)
 parity=(flags>>15)&1
 for i in range(bitbytes):memory[bits[parity]-BASE+i]=[0xff,0x55,0x81][(i+pattern)%3];memory[bits[1-parity]-BASE+i]=0 if i%2 else memory[bits[parity]-BASE+i]
 for i in range(mc):
  srcmat=ptr(mt+i*4);srcrecord=ptr(rt+i*4);material=alloc(708);record=alloc(68);context=alloc(52,pattern+5);control=alloc(16,i+1);first=alloc(32,i+2);tail=alloc(16,i+3);saved=alloc(32,i+4);start0=alloc(32,i+5);start1=alloc(32,i+6);current=alloc(16,i+7);slot=(i+pattern)&1
  memory[material-BASE:material-BASE+708]=raw[srcmat:srcmat+708];w(memory,material+0x3c,record);w(memory,table+i*4,material);w(memory,records+i*4,record)
  for off,value in[(0,owner),(4,ru(srcrecord+4)),(8,context),(12,control),(16,first),(20,tail if i&1 else first),(24,saved),(40,start0),(44,start1),(48,current if i&2 else[start0,start1][slot]),(52,slot)]:w(memory,record+off,value)
  w(memory,context+0x20,0x12345678);memory[control-BASE+1]=[0,1,0,255][i%4]
  for off in[0x24,0x2c,0x2e,0x1e,0x32,0x30]:wh(memory,context+off,h(memory,shader+off)^1)
 nodes=[]
 for i in range(dc):
  node=alloc(36);w(memory,node,ru(dp+i*36));w(memory,node+0x1c,owner);wh(memory,node+0x20,rh(dp+i*36+0x20));wh(memory,node+0x22,rh(dp+i*36+0x22));nodes.append(node)
 nodes.sort(key=lambda p:qn['signed'](u(memory,p)))
 for i,p in enumerate(nodes):w(memory,p+8,nodes[i+1]if i+1<len(nodes)else 0)
 # Authored clip -> item indices and predecessor -> matrix aliases retained.
 commandCount=ru(a+4);start=ptr(a+8);items=alloc(commandCount*16);memory[items-BASE:items-BASE+commandCount*16]=raw[start:start+commandCount*16];clips=metadata['models'];defs=alloc(len(clips)*12);sizes=alloc(len(clips)*2);alpha=alloc(len(clips)*4);cbits=[alloc(((len(clips)+15)//16)*4),alloc(((len(clips)+15)//16)*4)];matrices={}
 for off,value in[(4,commandCount),(8,items),(0x10,len(clips)),(0x14,defs),(0x18,sizes),(0x30,cbits[0]),(0x34,cbits[1]),(0x68,alpha if pattern%2 else 0)]:w(memory,owner+off,value)
 for i in range(((len(clips)+15)//16)*4):memory[cbits[parity]-BASE+i]=(i*17+0xe4)&255;memory[cbits[1-parity]-BASE+i]=memory[cbits[parity]-BASE+i]if(i//4)%2 else 0
 aw=[0xbf800000,0x80000000,0,0x3e800000,0x3f800000,0x40000000,0x7fc12345,0x7f800000,0xff800000]
 for ci,clip in enumerate(clips):
  count=render['clipItemCounts'][ci];cp=ptr(clip['address']+8);indices=alloc(count*4);w(memory,defs+ci*12+8,indices);wh(memory,sizes+ci*2,count);w(memory,alpha+ci*4,aw[(ci+pattern)%len(aw)])
  for j in range(count):
   ix=ru(cp+j*4);assert 1<=ix<commandCount;w(memory,indices+j*4,ix)
   if raw[start+ix*16]!=0x82:continue
   resource=ptr(start+(ix-1)*16+4)
   if resource not in matrices:matrices[resource]=alloc(64);memory[matrices[resource]-BASE:matrices[resource]-BASE+64]=raw[resource:resource+64]
   w(memory,items+(ix-1)*16+4,matrices[resource])
 return owner,nodes,mc
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};sourceRows=json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources'];sources=[]
for si,src in enumerate(sourceRows):
 row=index[src['source']];raw=(B/'extracted'/src['source']).read_bytes();render=json.loads((B/'exports/geometry/scene-runtime'/(src['source']+'.json')).read_text())['renderState'];metadata=json.loads((B/row['report']).read_text());pattern=si%6
 memory=bytearray(GLOBAL-BASE+0x400);memory[GLOBAL-BASE:GLOBAL-BASE+420]=bytes((i*19+si)&255 for i in range(420));setupqueue();owner,nodes,mc=staticscene(raw,render,metadata,pattern);w(memory,BASE+0x110,nodes[0]if nodes else 0);w(memory,BASE+0x10c,len(nodes));registered=[owner];control=alloc(4);descriptor=alloc(8);source=alloc(256,si+1);memory[descriptor-BASE]=[0,3,255][si%3];memory[descriptor-BASE+2]=si;w(memory,descriptor+4,source);arena=alloc(mc*1408+4096,si+1);w(memory,control,arena+(si&15));token=(0x98765432+si*37)&0xffffffff;mode=si%3
 for i in range(24):w(memory,0x973ed4+i*4,(0xface0000+si*7+i*37)&0xffffffff)
 w(memory,0x973fa4,0);before=bytes(memory);expected,trace,processed=finish(before,registered,control,descriptor,token,mode)
 n.write(BASE,before);n.pack('<I',0x9739b8,len(registered));n.pack('<I',0x9739bc,owner);n.pack('<I',0x9736e0,control);n.pack('<I',0x9738a4,descriptor);n.pack('<I',0x297dc00,token);n.pack('<I',0x2974d1c,mode);n.pack('<3I',0x80baa8,8,6,7);calls.clear();n.call(0x5f0d70,count=20000000);actual=n.read(BASE,len(before))
 for field,a,e in [('memory',actual,expected),('calls',calls,trace)]:
  if a!=e and len(errors)<20:errors.append({'source':src['source'],'field':field,'offsets':[i for i,(v,x)in enumerate(zip(a,e))if v!=x][:24],'nativeLength':len(a),'modelLength':len(e)})
 counts['cases']+=1;counts['queuedAdds']+=4;counts['clipPatches']+=calls.count(0x5df910);counts['alphaPatches']+=calls.count(0x5df880);counts['materialPatches']+=calls.count(0x5e0bd0);counts['changedShaderCalls']+=calls.count(0x607590);counts['appendCalls']+=calls.count(0x6034b0);counts['checkedBytes']+=len(actual)
 cases.append({'source':src['source'],'before':before.hex(),'registered':registered,'global':GLOBAL,'control':control,'descriptor':descriptor,'tokenBase':token,'gateMode':mode,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeCalls':list(calls)});sources.append({'source':src['source'],'sha256':hashlib.sha256(raw).hexdigest(),'pattern':pattern,'materials':mc,'sortRecords':len(nodes)})
 print('finish integration',si+1,'bytes',len(actual),'errors',len(errors),flush=True)
 if errors:break
counts['sources']=len(sources);fp=R/'geometry-finish-pipeline-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-finish-pipeline-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'boundaries':['Entire original5f0d70 and called CPU helpers execute unchanged; observation hooks only. Lock handle0 selects original no-lock path.','Each case combines4 new dynamic material additions with actual authored clip-item/predecessor-matrix alias maps, material flag/gate records, control material indexes and sort ranges. Runtime packet links,visibility bits,shader contexts and registry are controlled valid fixtures, not a recorded game frame.','Dynamic groups have native null-owner branch; finite static registry has1 authored owner per case.','CPU memory and call order only; managed execution and GPU consumption unclaimed.'],'dependencies':[{'file':p,'sha256':hashlib.sha256((B/p).read_bytes()).hexdigest()}for p in ['tools/geometry-dynamic-queue-native.py','tools/geometry-sorted-packets-native.py','tools/geometry-shader-emission-native.py']]};(R/'geometry-finish-pipeline-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in ['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

