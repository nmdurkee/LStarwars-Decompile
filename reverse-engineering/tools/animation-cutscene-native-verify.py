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
 for off in [36,40,44,48,52,56]:
  v=struct.unpack_from('<I',data,off)[0]
  if v:struct.pack_into('<I',data,off,v+DATA)
 mu.mem_write(DATA,bytes(data))
def run(frame,node,curves):
 mu.context_restore(context);mu.mem_write(OUT,bytes(curves*4));sp=STACK+0xf000
 mu.mem_write(sp,struct.pack('<IIfIII',STOP,DATA,frame,OUT,node,0));mu.reg_write(UC_X86_REG_ESP,sp)
 mu.emu_start(0x5ce350,STOP,count=1000000)
 if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('instruction budget reached')
 data=mu.mem_read(OUT,curves*4);return struct.unpack('<'+'f'*curves,data),struct.unpack('<'+'I'*curves,data)
inventory=json.loads((BASE/'reports/animation-cutscene-export.json').read_text())['success'];report={'binarySha256':hashlib.sha256(blob).hexdigest(),'procedure':'0x5ce350','method':'Original PC generic scalar extractor and original callees 0x5ca830/0x6e6b90 executed in isolated Unicorn x86 emulator, no OS API or game process. All consumed pointers relocated in scratch memory.','files':0,'animations':0,'nodeSamples':0,'scalars':0,'types':{},'legacyExcluded':0,'packedBitComparisons':0,'maxAbsoluteError':0,'maxRelativeError':0,'mismatchCount':0,'mismatchExamples':[],'failures':[]};start=time.time()
for item in inventory:
 if item['format']!='CU2-PC':continue
 scene=json.loads((BASE/'exports/cutscenes'/(item['path']+'.json')).read_text());raw=(BASE/'extracted'/item['path']).read_bytes()
 for animation in scene['animations']:
  try:
   if animation['format']!='ANI4-PC':
    report['legacyExcluded']+=1;continue
   h=animation['header'];prepare(raw[animation['sourceOffset']:]);frames=sorted(set([h['firstFrame'],h['firstFrame']+(h['frameCount']-1)*.317,h['firstFrame']+(h['frameCount']-1)*.731,h['firstFrame']+h['frameCount']-1]))
   for frame in frames:
    frame=struct.unpack('<f',struct.pack('<f',frame))[0];key=0 if h['keyCount']==1 else max(0,min(h['keyCount']-1,(frame-h['firstFrame'])*(h['keyCount']-1)/(h['frameCount']-1)));whole=int(key);fraction=key-whole
    for node in animation['nodes']:
     actual,actualBits=run(frame,node['index'],h['curveCount']);report['nodeSamples']+=1
     for ci,curve in enumerate(node['curves']):
      if curve['type']==10:
       report['packedBitComparisons']+=1;expected=curve['rawBits'][whole];observed=actualBits[ci];report['scalars']+=1;report['types']['10']=report['types'].get('10',0)+1
       if observed!=expected:
        report['mismatchCount']+=1
        if len(report['mismatchExamples'])<40:report['mismatchExamples'].append({'path':item['path'],'animationOffset':animation['sourceOffset'],'frame':frame,'node':node['index'],'channel':ci,'type':10,'expectedBits':expected,'nativeBits':observed})
       continue
      if curve['type']>=16:expected=curve['value']
      else:
       a=curve['values'][whole];z=curve['values'][min(whole+1,h['keyCount']-1)];expected=a+(z-a)*(0 if curve['interpolation']=='STEP' else fraction)
      observed=actual[ci];error=abs(observed-expected);relative=error/max(1,abs(expected));report['maxAbsoluteError']=max(report['maxAbsoluteError'],error);report['maxRelativeError']=max(report['maxRelativeError'],relative);report['scalars']+=1;ct=str(curve['type'] if curve['type']<16 else 'constant');report['types'][ct]=report['types'].get(ct,0)+1
      magnitude=max(1,abs(expected),abs(curve.get('minimum',h['minimum'])),abs(curve.get('scale',0))*(65535 if curve['type']==7 else 255));tolerance=2e-5*magnitude
      if not math.isfinite(observed)or error>tolerance:
       report['mismatchCount']+=1
       if len(report['mismatchExamples'])<40:report['mismatchExamples'].append({'path':item['path'],'animationOffset':animation['sourceOffset'],'frame':frame,'node':node['index'],'channel':ci,'type':curve['type'],'expected':expected,'native':observed,'absoluteError':error,'tolerance':tolerance})
   report['animations']+=1
  except Exception as e:report['failures'].append({'path':item['path'],'animationOffset':animation['sourceOffset'],'error':str(e),'eip':hex(mu.reg_read(UC_X86_REG_EIP))})
 report['files']+=1
 if report['files']%10==0:print(report['files'],'files,',report['animations'],'animations,',report['mismatchCount'],'mismatches,',len(report['failures']),'failures',flush=True)
report['elapsedSeconds']=time.time()-start;report['limits']=['Four bounded sample times per carrier, all nodes and channels; not every time or blend state.','Decoder double math differs from native float32/x87; tolerance2e-5*max(1,abs(value),abs(minimum),abs(scale)*endpointMaximum), accounting for cancellation in offset curves; type10 requires exact uint32 equality.','Pose transforms, actor binding, state callbacks, and rendered cutscene playback are outside scalar emulation.'];(BASE/'reports/animation-cutscene-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items() if k not in ['mismatchExamples','failures']},indent=2))
