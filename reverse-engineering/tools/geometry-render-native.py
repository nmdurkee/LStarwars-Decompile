"""Bounded original-x86 renderer dispatch/queue tests; no graphics or OS execution."""
import importlib.util, json, struct, hashlib
from pathlib import Path
P=Path(__file__).resolve().parent; B=P.parent
sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py'); nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX
n=nx.NativeX86(); intercepted={}; events=[]
def hook(mu,address,size,data):
 if address in intercepted:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];argc,action=intercepted[address];args=n.unpack('<'+'I'*argc,sp+4) if argc else ()
  result=action(args) if action else 0
  mu.reg_write(UC_X86_REG_EAX,result or 0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook)
tests=[]; tables=[]
def check(name,actual,expected,details=None):
 passed=actual==expected;tests.append({'name':name,'passed':passed,'details':details or {},**({} if passed else {'actual':actual,'expected':expected})})
def capture(address,argc):
 intercepted[address]=(argc,lambda a:events.append([hex(address),list(a)]))
def packet(address,opcode,control,arg=0):n.write(address,struct.pack('<BBHI8x',opcode,control,0,arg))

# Exact original callback tables, including null entries. Native callbacks are
# intercepted solely to observe the interpreter's chosen target and argument.
for table in [0x80e6d0,0x80e798]:
 vals=n.unpack('<49I',table);tables.append({'address':hex(table),'entries':[{'opcode':hex(0x80+i),'target':hex(v) if v else None}for i,v in enumerate(vals)]})
 intercepted.clear();events.clear()
 for target in set(vals)-{0}:capture(target,1)
 base=n.DATA
 for i in range(49):packet(base+i*16,0x80+i,3,0xcafe0000+i)
 packet(base+49*16,0x84,4)
 n.call(0x5e0f90,[base,table])
 check('interpreter-all-opcodes-'+hex(table),events,[[hex(v),[0xcafe0000+i]]for i,v in enumerate(vals)if v])
 # Skipped callback, linked branch, unreachable data, then termination. Dispatch
 # is driven by byte1, not by the symbolic opcode labels in serialized assets.
 events.clear();packet(base,0x80,0,11);packet(base+16,0x8d,1,base+256);packet(base+32,0x80,3,99)
 packet(base+256,0x82,3,22);packet(base+272,0xb0,4,0x1234)
 n.call(0x5e0f90,[base,table]);check('interpreter-control-flow-'+hex(table),events,[[hex(vals[2]),[22]]])

# Native selector writes exact table pointers, no guessed render-pass naming.
intercepted.clear()
for mode,table in [(0,0x80e6d0),(1,0x80e798)]:
 n.call(0x603aa0,[mode]);check('callback-table-selection-'+str(mode),n.unpack('<I',0x80e794)[0],table)

# Native render-bucket playback preserves the prepared order, then plays the
# bucket's inline tail list. Lock/unlock and downstream playback are observed.
intercepted.clear();capture(0x6033d0,1);intercepted[0x4ffaa0]=(1,None);intercepted[0x4ffac0]=(1,None)
n.pack('<I',0x973fc4,0)
for count in [0,1,3,8]:
 events.clear();bucket=n.DATA+0x1000;ptrs=bucket+0x100;n.pack('<2I',bucket,count,ptrs);n.pack('<I',0x973f34+7*4,bucket)
 expected=[]
 for i in range(count):
  entry=bucket+0x200+(count-i)*0x40;stream=0x10180000+i*0x100;n.pack('<I',ptrs+i*4,entry);n.pack('<2I',entry,i,stream);expected.append(['0x6033d0',[stream]])
 expected.append(['0x6033d0',[bucket+8]])
 n.call(0x5f02e0,[7]);check('bucket-playback-'+str(count),events,expected)

# View contexts are byte-exact 536-byte snapshots. The queue-ID producer is
# stubbed; context copying and the optional nested-capture branch execute.
intercepted.clear()
for address in [0x5f3950,0x5f39e0]:
 for result in [-1,0,7]:
  for nested in [False,True]:
   intercepted[0x5efff0]=(0,lambda a,r=result:r)
   raw=bytearray((i*13+29)%256 for i in range(536));struct.pack_into('<I',raw,0x38,1 if nested else 0)
   nestedBase=n.DATA+0x3000;struct.pack_into('<II',raw,0x3c,nestedBase,1)
   n.write(0x9718a0,raw);n.pack('<I',0x95fbb8,2);n.pack('<I',nestedBase+0x808,1);n.pack('<I',nestedBase+0x380+0x374,0)
   n.call(address)
   expected=bytearray(raw);struct.pack_into('<I',expected,0,0xffffffff if nested or result==-1 else result)
   check('view-context-copy-'+hex(address)+'-'+str(result)+'-'+str(nested),n.read(0x9640f0+536*2,536).hex(),expected.hex())
   check('view-context-count-'+hex(address)+'-'+str(result)+'-'+str(nested),n.unpack('<I',0x95fbb8)[0],3)
   if nested and result!=-1:
    check('view-nested-capture-'+hex(address)+'-'+str(result),list(n.unpack('<I',nestedBase+0x380+0x354))+list(n.unpack('<I',nestedBase+0x380+0x374)),[result,1])

# Snapshot 24 submission-bucket pointers from producer to consumer list. All
# helper calls are stubbed so this test claims only the observed snapshot copy.
intercepted.clear()
for address in [0x4ffaa0,0x4ffac0,0x5de440,0x603920,0x5e0bd0,0x5e0d00]:intercepted[address]=(0,None)
n.pack('<I',0x9739b8,0);sources=[n.DATA+0x20000+i*0x100 for i in range(24)];n.pack('<24I',0x973ed4,*sources)
n.call(0x5f0d70);check('24-bucket-snapshot',list(n.unpack('<24I',0x973f34)),sources)

# Matrix callback: metadata temporarily stored in matrix slots +0x2c/+0x3c is
# uploaded separately, and normalized affine slots are supplied to worldMatrix.
intercepted.clear();matrix=n.DATA+0x4000;uploads=[];n.pack('<I',0x2854c20,n.DATA+0x5000)
intercepted[0x7412e0]=(2,lambda a:uploads.append({'semantic':a[0],'bits':n.read(a[1],64 if a[0]==0x11 else 16).hex()}))
intercepted[0x5f8930]=(0,None);intercepted[0x6e5340]=(2,None)
matrixCases=0
for alpha in [0.0,0.25,1.0,1.5]:
 for fog in [-2.0,0.0,3.5]:
  values=[1.,2.,3.,4.,5.,6.,7.,8.,9.,10.,11.,fog,13.,14.,15.,alpha];raw=struct.pack('<16f',*values);n.write(matrix,raw)
  n.pack('<4f',0x986ea0,.2,.4,.6,.8);n.pack('<f',0x80e198,-999);n.pack('<f',0x80e194,-999);n.pack('<I',0x2974d1c,1);uploads.clear()
  n.call(0x5fd6b0,[matrix]);values[11]=0.;values[15]=1.
  expectedMatrix=struct.pack('<16f',*values).hex();actualMatrix=[u['bits']for u in uploads if u['semantic']==0x11]
  check('matrix-affine-upload-'+str((alpha,fog)),actualMatrix,[expectedMatrix]);check('matrix-source-restored-'+str((alpha,fog)),n.read(matrix,64).hex(),raw.hex());matrixCases+=1

# Mesh submission callback. GPU/API helpers are replaced by event collectors;
# all native guards, packet field reads, topology/count selection run original.
intercepted.clear();mat=n.DATA+0x5000;mesh=n.DATA+0x6000;shader=n.DATA+0x7000
n.pack('<I',0x2854c20,mat)
for address,argc in [(0x6e5590,4),(0x6e51d0,1),(0x6e48e0,6),(0x6e49b0,4),(0x6e5340,2),(0x5fde60,0)]:capture(address,argc)
meshCount=0
for shaderEnabled in [False,True]:
 intercepted[0x741610]=(0,lambda a,on=shaderEnabled:shader if on else 0)
 for flags in [0,0x4000000]:
  n.pack('<I',mat+0x26c,flags)
  for kind in [6,12,13,14,15,17,18,0x777]:
   for count in [0,1,2,3,5,17]:
    raw=bytearray(56);struct.pack_into('<IIH',raw,0,kind,11,36);struct.pack_into('<5I',raw,20,7,count,13,0xa001,0xa002);n.write(mesh,raw);events.clear()
    n.call(0x607880,[mesh]);expected=[]
    if shaderEnabled and count:
     if flags:expected.append(['0x5fde60',[]])
     if kind==6:expected += [['0x6e5590',[0,0xa002,0,36]],['0x6e51d0',[0xa001]],['0x6e48e0',[5,7,0,count,13,11]]]
     elif kind in [12,13,14,15,17,18]:
      topology={12:4,13:5,14:2,15:3,17:6,18:1}[kind]
      prims={12:count//3,13:count-2,14:count//2,15:count-1,17:count-2,18:count}[kind]
      if kind==18:expected.append(['0x6e5340',[0x9a,0x42000000]])
      if kind not in [13,17]or count>2:expected.append(['0x6e49b0',[topology,prims,mesh+56,24]])
      if kind==18:expected.append(['0x6e5340',[0x9a,0x3f800000]])
    check('mesh-submit-'+str((shaderEnabled,flags,kind,count)),events,expected);meshCount+=1

r={'schema':'original-render-contract-tests-v1','binarySHA256':n.sha256,'tests':len(tests),'meshSubmissionCases':meshCount,'matrixSubmissionCases':matrixCases,'passed':all(t['passed']for t in tests),'failures':[t for t in tests if not t['passed']],'callbackTables':tables,'testCases':tests,'scope':'Original interpreter, selector, bucket playback, view-context copy, bucket snapshot, matrix slot normalization/restoration and mesh guards/topology run in isolated x86. Callback endpoints, queue allocation, locks and GPU APIs are intercepted as described. No original process or D3D device.','limits':['No GPU shader execution, rasterization, device lifetime or full-frame emulation.','The dynamic morph-buffer upload branch is not part of mesh submission tests.','Matrix tests compare normalized matrix upload and source restoration; separate alpha/fog state uploads are recorded but not asserted.','Invalid interpreter controls intentionally loop in native code and are excluded from runnable fixtures.','Queue capacity and producer sort construction are statically traced, not exercised end to end here.']}
(B/'reports/geometry-render-native-validation.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k]for k in ['tests','meshSubmissionCases','passed','failures']},indent=2))
if not r['passed']:raise SystemExit(1)
