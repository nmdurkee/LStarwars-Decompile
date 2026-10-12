"""Compare decoded ANI4 scalar samples with isolated original x86 instructions.
Does not launch the game, call OS APIs, or emulate gameplay.
"""
import sys,struct,json,hashlib,math,time
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
sys.path.insert(0,str(BASE/'tools/python-packages'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
from unicorn.x86_const import *
blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes()
u16=lambda o:struct.unpack_from('<H',blob,o)[0]
u32=lambda o:struct.unpack_from('<I',blob,o)[0]
p=u32(0x3c);opt=p+24;imagebase=u32(opt+28);size=u32(opt+56)
mu=Uc(UC_ARCH_X86,UC_MODE_32);mu.mem_map(imagebase,(size+4095)&~4095);mu.mem_write(imagebase,blob[:u32(opt+60)])
for i in range(u16(p+6)):
 q=opt+u16(p+20)+40*i;rva,rawsize,rawoff=u32(q+12),u32(q+16),u32(q+20)
 if rawsize:mu.mem_write(imagebase+rva,blob[rawoff:rawoff+rawsize])
STACK=0x10000000;DATA=0x11000000;BUF=0x12000000;OUT=BUF+0x1000;FLAGS=BUF+0x10000;STOP=0x13000000
mu.mem_map(STACK,0x10000);mu.mem_map(DATA,0x400000);mu.mem_map(BUF,0x20000);mu.mem_map(STOP,0x1000)
mu.mem_write(0x9737de,b'\0') # Choose the observed Euler scalar branch, no quaternion accumulation.
mu.reg_write(UC_X86_REG_FPCW,0x37f);mu.reg_write(UC_X86_REG_FPSW,0);mu.reg_write(UC_X86_REG_FPTAG,0xffff);context=mu.context_save()
def prepare(raw):
 data=bytearray(raw)
 if struct.unpack_from('<I',data,0)[0]!=0x414e4934:
  if struct.unpack_from('<I',data,4)[0]!=0x414e4935:raise ValueError('unknown format')
  table=struct.unpack_from('<I',data,0)[0];count=struct.unpack_from('<I',data,table)[0]
  for i in range(count):
   slot=table+4+4*i;field=slot+struct.unpack_from('<i',data,slot)[0];v=struct.unpack_from('<i',data,field)[0]
   if v:struct.pack_into('<I',data,field,field+v-4)
  data=data[4:]
 for off in [36,40,44,48,52,56]:
  v=struct.unpack_from('<I',data,off)[0]
  if v:struct.pack_into('<I',data,off,v+DATA)
 mu.mem_write(DATA,bytes(data))
def run(frame,nodes):
 mu.context_restore(context);mu.mem_write(BUF,struct.pack('<I HBB II',nodes,nodes,0,0,OUT,FLAGS));mu.mem_write(OUT,bytes(nodes*48));sp=STACK+0xf000
 mu.mem_write(sp,struct.pack('<IIfIII',STOP,DATA,frame,BUF,nodes,0));mu.reg_write(UC_X86_REG_ESP,sp)
 mu.emu_start(0x5cc0d0,STOP,count=1000000)
 if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('instruction budget reached')
 data=mu.mem_read(OUT,nodes*48);return[[struct.unpack_from('<f',data,j*48+(c//3)*16+(c%3)*4)[0]for c in range(9)]for j in range(nodes)]
inventory=json.loads((BASE/'reports/animation-export.json').read_text())['success'];report={'binarySha256':hashlib.sha256(blob).hexdigest(),'procedure':'0x5cc0d0','method':'Original x86 function and original float-to-int callee executed in isolated Unicorn x86 emulator; no OS API or game process. Raw ANI4/ANI5 pointers relocated in scratch memory. Euler-path control byte explicitly zero.','files':0,'poses':0,'scalars':0,'maxAbsoluteError':0,'maxRelativeError':0,'mismatchCount':0,'mismatchExamples':[],'failures':[]};start=time.time()
for item in inventory:
 if not item['format'].startswith('ANI'):continue
 try:
  animation=json.loads((BASE/item['output']).read_text());h=animation['header'];prepare((BASE/'extracted'/item['path']).read_bytes())
  frames=sorted(set([h['firstFrame'],h['firstFrame']+(h['frameCount']-1)*.317,h['firstFrame']+(h['frameCount']-1)*.731,h['firstFrame']+h['frameCount']-1]))
  for frame in frames:
   frame=struct.unpack('<f',struct.pack('<f',frame))[0];actual=run(frame,h['nodeCount']);key=0 if h['keyCount']==1 else max(0,min(h['keyCount']-1,(frame-h['firstFrame'])*(h['keyCount']-1)/(h['frameCount']-1)));whole=int(key);fraction=key-whole
   for node in animation['nodes']:
    for ci,curve in enumerate(node['curves']):
     if not curve['active']:expected=1 if ci>=6 else 0
     elif curve['type']>=16:expected=curve['value']
     else:
      a=curve['values'][whole];z=curve['values'][min(whole+1,h['keyCount']-1)];expected=a+(z-a)*(0 if curve['interpolation']=='STEP' else fraction)
     observed=actual[node['index']][ci];error=abs(observed-expected);relative=error/max(1,abs(expected));report['maxAbsoluteError']=max(report['maxAbsoluteError'],error);report['maxRelativeError']=max(report['maxRelativeError'],relative);report['scalars']+=1
     if not math.isfinite(observed)or error>2e-5*max(1,abs(expected)):
      report['mismatchCount']+=1
      if len(report['mismatchExamples'])<40:report['mismatchExamples'].append({'path':item['path'],'frame':frame,'node':node['index'],'channel':ci,'expected':expected,'native':observed,'absoluteError':error})
   report['poses']+=1
  report['files']+=1
 except Exception as e:report['failures'].append({'path':item['path'],'error':str(e),'eip':hex(mu.reg_read(UC_X86_REG_EIP))})
 if (report['files']+len(report['failures']))%200==0:
  print(report['files'],'files,',report['mismatchCount'],'mismatches,',len(report['failures']),'failures',flush=True)
report['elapsedSeconds']=time.time()-start;report['limits']=['This validates four bounded sample times per carrier, not every possible frame or blend state.','The decoder uses exact division by63 and host double math; original instructions use a float32 reciprocal and x87 intermediates. Tolerance2e-5*max(1,abs(value)).','Pose transforms, animation blending, callbacks, and rendered gameplay are outside this scalar emulation.'];(BASE/'reports/animation-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
