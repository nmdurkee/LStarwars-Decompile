"""Full original5e0390 and CPU dependencies; only COM virtual methods supplied."""
from pathlib import Path
import importlib.util,struct,json,base64,gzip,hashlib,collections
B=Path(__file__).resolve().parent.parent
s=importlib.util.spec_from_file_location('morph_packet_math',B/'tools/animation-morph-fixture.py');f=importlib.util.module_from_spec(s);s.loader.exec_module(f);n=f.native.NativeX86();D=n.DATA;SIZE=0x100000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EDI
M=D+0x100;WEIGHT=D+0x1000;MATRIX=D+0x2000;GPU=D+0x7000;VTABLE=D+0x8000;TARGETS=D+0x9000;CONTROL=D+0xa000;OWNER=D+0xc000;TABLE=D+0xc100;RECORD=D+0xc200;CMD=D+0xc300;SRC=D+0xc400;CACHE=D+0xc500;OUT=D+0xc510;SCALE=D+0xc600;TRANS=D+0xc640;ARENA=D+0x40000;BASEVERTEX=0x30000000;DELTA=0x31000000
LOCK=n.STOP+0x100;UNLOCK=n.STOP+0x200
for at in[BASEVERTEX,DELTA]:n.mu.mem_map(at,0x1000000)
fixturePath=B/'reports/animation-morph-mesh-native-fixtures.json.gz';fixture=json.loads(gzip.decompress(fixturePath.read_bytes()));matrices=base64.b64decode(fixture['jointMatrices']);meshes=[dict(r,descriptor=base64.b64decode(r['descriptor']),vertices=base64.b64decode(r['vertices']),deltas=[base64.b64decode(v)if v is not None else None for v in r['deltas']])for r in fixture['meshes']]
matrixFixture=B/'reports/geometry-ordinary-packets-fixtures.json.gz';matrixRows=[r for r in json.loads(gzip.decompress(matrixFixture.read_bytes()))['cases']if r['kind']=='matrix'];events=[];calls=[];current=None
def sha(b):return hashlib.sha256(b).hexdigest()
def u(b,p):return struct.unpack_from('<I',b,p-D)[0]
def w(b,p,v):struct.pack_into('<I',b,p-D,v)
def put(b,p,v):b[p-D:p-D+len(v)]=v
def align(p,unit):return(p+unit-1)&~(unit-1)
def service(mu,a,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if a==LOCK:
  resource,offset,count,out,flags=n.unpack('<5I',sp+4);assert resource==GPU and offset==current['offset']and count==len(current['vertices']);events.append(['lock',offset,count,flags]);n.pack('<I',out,BASEVERTEX);pop=20
 else:assert n.unpack('<I',sp+4)[0]==GPU;events.append(['unlock']);pop=4
 ip=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4+pop);mu.reg_write(UC_X86_REG_EIP,ip)
for address in[LOCK,UNLOCK]:n.mu.hook_add(UC_HOOK_CODE,service,begin=address,end=address)
def observe(mu,address,size,user):calls.append(address)
for address in[0x5e0390,0x603530,0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610,0x603710,0x6e5b90,0x4ef660,0x6e5bc0,0x603ad0,0x603b10]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def initial(mesh,weights,index,matrix):
 b=bytearray(SIZE);b[0x40000:]=bytes((i*37+index*17)&255 for i in range(256))*((SIZE-0x40000)//256);put(b,M,mesh['descriptor']);put(b,MATRIX,matrices);put(b,SRC,matrix);w(b,GPU,VTABLE);w(b,VTABLE+0x2c,LOCK);w(b,VTABLE+0x30,UNLOCK);w(b,CONTROL,ARENA+index%32);w(b,RECORD,OWNER);w(b,OWNER+0x50,TABLE);w(b,TABLE,0x12345678);w(b,RECORD+0x14,D+0xc700);w(b,RECORD+0x18,D+0xc720);w(b,CMD+4,M);w(b,CACHE,0xdeadbeef);put(b,OUT,b'\xa5'*12)
 if weights is not None:put(b,WEIGHT+8,struct.pack('<'+'f'*len(weights),*weights))
 at=DELTA
 for j,delta in enumerate(mesh['deltas']):w(b,TARGETS+4*j,at if delta is not None else 0);at+=len(delta)+16 if delta is not None else 0
 return b
def model(before,mesh,weights,metadata,uv):
 b=bytearray(before);trace=[0x5e0390,0x603530];ev=[];start=align(u(b,CONTROL),16);w(b,u(b,RECORD+0x14)+4,start);w(b,RECORD+0x24,start);tail=start+48;b[tail-D]=0x8d;b[tail-D+1]=1;w(b,tail+4,u(b,RECORD+0x18)+16);w(b,RECORD+0x14,tail);cursor=tail+16
 put(b,SCALE,struct.pack('<16I',uv[0],0,0,0,0,uv[1],0,0,0,0,0x3f800000,0,0,0,0,0x3f800000));put(b,TRANS,struct.pack('<16I',0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000,0,uv[2],uv[3],0,0x3f800000));transform=align(cursor,4);raw=u
 for i in range(4):
  for j in range(4):w(b,transform+(i*4+j)*4,u(b,SRC+(j*4+i)*4))
 cursor=transform+64;w(b,CACHE,transform);trace.extend([0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610])
 def cmd(op,value):
  p=u(b,RECORD+0x24);b[p-D]=op;b[p-D+1]=3;w(b,p+4,value);w(b,RECORD+0x24,p+16);return p
 first=cmd(0x8c,transform);w(b,OUT,first);trace.append(0x603710);deform=weights is not None and u(b,M+40)!=0;descriptor=M
 if deform:
  descriptor=align(cursor,32);cursor=descriptor+56;put(b,descriptor,b[M-D:M-D+56]);vertexAddress=align(cursor,32);cursor=vertexAddress+len(mesh['vertices']);w(b,descriptor+52,vertexAddress);vertices=bytearray(mesh['vertices']);stride=struct.unpack_from('<H',mesh['descriptor'],8)[0]
  for i in range(u(b,M+24)):
   for j,delta in enumerate(mesh['deltas']):
    if delta is None or weights[j]==0:continue
    for k in range(3):
     p=i*stride+k*4;value=struct.unpack_from('<f',vertices,p)[0];d=struct.unpack_from('<f',delta,(i*3+k)*4)[0];struct.pack_into('<f',vertices,p,(f.W(d)*f.W(weights[j])+f.W(value)).store())
  put(b,vertexAddress,vertices);trace.extend([0x6e5b90,0x4ef660,0x6e5bc0]);ev=[['lock',mesh['offset'],len(vertices),16],['unlock']]
 else:w(b,M+52,0)
 ids=[]
 for joint in mesh['descriptor'][10:18]:
  if joint==255:break
  ids.append(joint)
 palette=struct.pack('<I',len(ids))+b''.join(matrices[i*64:i*64+64]for i in ids);paletteAddress=cursor;put(b,cursor,palette);cursor+=len(palette);w(b,CONTROL,cursor);w(b,OUT+4,cmd(0x99,paletteAddress));w(b,OUT+4,cmd(0x98,descriptor));w(b,transform+60,0x3f800000);put(b,transform+56,struct.pack('<f',metadata));trace.extend([0x603ad0,0x603b10]);assert cursor<D+SIZE
 return b,trace,ev
def original(before,mesh,weights,metadata,uv):
 global current
 current=mesh;n.write(D,before);n.write(BASEVERTEX,mesh['vertices']);at=DELTA
 for delta in mesh['deltas']:
  if delta is not None:n.write(at,delta);at+=len(delta)+16
 n.pack('<I',0x9736e0,CONTROL);n.pack('<4I',0x80e258,*uv);n.write(0x2857230,before[SCALE-D:SCALE-D+64]);n.write(0x28571f0,before[TRANS-D:TRANS-D+64]);calls.clear();events.clear();n.call(0x5e0390,[CMD,SRC,CACHE,MATRIX,WEIGHT if weights is not None else 0,metadata&0xffffffff],regs={UC_X86_REG_EAX:RECORD,UC_X86_REG_EDI:OUT},count=30000000)
 actual=bytearray(n.read(D,SIZE));put(actual,SCALE,n.read(0x2857230,64));put(actual,TRANS,n.read(0x28571f0,64));return actual,calls.copy(),events.copy()
cases=[];errors=[];counts=collections.Counter();uv=[0x3f000000,0x40000000,0x80000000,0xbf800000]
for mi,mesh in enumerate(meshes):
 matrixRow=matrixRows[mi%len(matrixRows)];matrix=bytes.fromhex(matrixRow['before'])[0x600:0x640];metadata=[0,-2147483648,2147483647,16777217,-1][mi%5]
 for mode in[0,1]:
  weights=None if mode==0 else[f.f32((j%7-2)*.125)for j in range(len(mesh['deltas']))];index=mi*2+mode;before=initial(mesh,weights,index,matrix);want,trace,ev=model(before,mesh,weights,metadata,uv);got,actualTrace,actualEvents=original(before,mesh,weights,metadata,uv);counts['authored'if 'path'in mesh['source']else'synthetic']+=1
  if got!=want or trace!=actualTrace or ev!=actualEvents:
   if len(errors)<12:errors.append(dict(mesh=mi,mode=mode,offsets=[i for i,(a,b)in enumerate(zip(got,want))if a!=b][:20],expectedTrace=trace,actualTrace=actualTrace,expectedEvents=ev,actualEvents=actualEvents))
   counts['mismatches']+=1
  cases.append(dict(mesh=mi,index=index,weights=None if weights is None else[f.bits(v)for v in weights],matrix=matrix.hex(),matrixOrigin=matrixRow['label'],metadata=metadata,nativeSha256=sha(got),calls=actualTrace,events=actualEvents))
 if mi%100==0:print('morph packets',mi,'meshes',counts['mismatches'],'mismatches',flush=True)
out=B/'reports/animation-morph-packets-native-fixtures.json.gz';out.write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,meshFixture=dict(path=fixturePath.relative_to(B).as_posix(),sha256=sha(fixturePath.read_bytes())),matrixFixture=dict(path=matrixFixture.relative_to(B).as_posix(),sha256=sha(matrixFixture.read_bytes())),addresses=dict(base=D,size=SIZE,mesh=M,weights=WEIGHT,joints=MATRIX,gpu=GPU,vtable=VTABLE,targets=TARGETS,control=CONTROL,owner=OWNER,table=TABLE,record=RECORD,command=CMD,matrix=SRC,cache=CACHE,output=OUT,scale=SCALE,translation=TRANS,arena=ARENA,lock=LOCK,unlock=UNLOCK,delta=DELTA),scratchInputs=uv,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(binarySha256=n.sha256,comparisons=len(cases),counts=dict(counts),mismatches=counts['mismatches'],examples=errors,fixture=dict(path=out.relative_to(B).as_posix(),bytes=out.stat().st_size,sha256=sha(out.read_bytes())),checkedBytes=len(cases)*SIZE,method='Original5e0390 and reserve,transpose,scratch,morph,memcpy,COM-wrapper,alpha/metadata dependencies run unchanged. Only successful COM Lock/Unlock virtual methods are service callbacks. Full1MiB state image, both scratch matrices, nested call order and device-service events compared.',limits=['Valid disjoint allocated state, no pointer wrap, finite deformation and successful buffer lock.','Full CPU packet output only; no shader execution or GPU draw.','Joint matrices are opaque byte patterns; authored transform matrices are copied from prior source-bound geometry fixtures.'])
(B/'reports/animation-morph-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not counts['mismatches']
