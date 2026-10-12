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
TIME=BUF+0x100;TRAMP=STOP+0x100
mu.mem_write(TRAMP,b'\xd9\x1d'+struct.pack('<I',OUT)+b'\xe9'+struct.pack('<i',STOP-(TRAMP+11)))
mu.mem_write(0x971760,bytes(bin(i).count('1')for i in range(256)))
def prepare(raw,a):
 data=bytearray(raw);h=a['header'];base=h['originalPointerBase'];ho=h['headerOffset']
 fields=[ho+12,ho+16,ho+20]
 for c in a['curves']:
  if c['type']:
   fields.append(h['curveOffset']+(c['node']*h['curveCount']+c['curve'])*4);o=c['sourceOffsets']['descriptor'];fields.extend([o,o+4,o+8])
 for off in set(fields):
  v=struct.unpack_from('<I',data,off)[0]
  if v:struct.pack_into('<I',data,off,v-base+DATA)
 mu.mem_write(DATA,bytes(data))
def run(frame,a,c):
 mu.context_restore(context);sp=STACK+0xf000;h=a['header'];mu.mem_write(TIME,bytes(24));mu.mem_write(sp,struct.pack('<IIfI',STOP,DATA+h['headerOffset'],frame,TIME));mu.reg_write(UC_X86_REG_ESP,sp);mu.emu_start(0x5c9c40,STOP,count=100000)
 actualTime=struct.unpack('<f',mu.mem_read(TIME,4))[0];entry=DATA+h['curveOffset']+(c['node']*h['curveCount']+c['curve'])*4
 mu.mem_write(sp,struct.pack('<IIII',TRAMP,entry,TIME,c['type']));mu.reg_write(UC_X86_REG_ESP,sp);mu.emu_start(0x5c9520,STOP,count=100000)
 if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('instruction budget reached')
 return struct.unpack('<f',mu.mem_read(OUT,4))[0],actualTime
def sample(c,t):
 keys=c['keys']
 if t<=keys[0]['frame']:return keys[0]['value']
 if t>=keys[-1]['frame']:return keys[-1]['value']
 j=0
 while j+1<len(keys)and keys[j+1]['frame']<=t:j+=1
 a,z=keys[j],keys[j+1];span=z['frame']-a['frame'];u=(t-a['frame'])/span;return(2*u**3-3*u*u+1)*a['value']+(u**3-2*u*u+u)*span*a['tangent']+(-2*u**3+3*u*u)*z['value']+(u**3-u*u)*span*z['tangent']
report={'procedure':'0x5c9520','timeProcedure':'0x5c9c40','binarySha256':hashlib.sha256(blob).hexdigest(),'method':'Original PC time clamp and cubic scalar evaluator in isolated Unicorn; original packed-pointer data relocated; known byte-popcount lookup table initialized; no OS API or game process.','carriers':0,'animations':0,'curves':0,'samples':0,'types':{},'maxAbsoluteError':0,'maxRelativeError':0,'mismatchCount':0,'mismatchExamples':[],'failures':[]};start=time.time()
items=[]
for i in json.loads((BASE/'reports/animation-bsa-export.json').read_text())['success']:items.append((i['path'],BASE/'exports/animation'/(i['path']+'.json'),False))
for i in json.loads((BASE/'reports/animation-cutscene-export.json').read_text())['success']:
 if i['format']=='CU2-PC':items.append((i['path'],BASE/'exports/cutscenes'/(i['path']+'.json'),True))
for rel,export,cu2 in items:
 try:
  raw=(BASE/'extracted'/rel).read_bytes();document=json.loads(export.read_text());animations=[a for a in document['animations']if a.get('format')=='legacy-embedded']if cu2 else[document]
  for a in animations:
   prepare(raw,a);h=a['header'];curves=[c for c in a['curves']if c['type']]
   for c in curves:
    for frame in sorted(set([1,1+(h['duration']-1)*.317,1+(h['duration']-1)*.731,h['duration']])):
     actual,t=run(frame,a,c);expected=sample(c,t);error=abs(actual-expected);relative=error/max(1,abs(expected));report['maxAbsoluteError']=max(report['maxAbsoluteError'],error);report['maxRelativeError']=max(report['maxRelativeError'],relative);report['samples']+=1;report['types'][str(c['type'])]=report['types'].get(str(c['type']),0)+1
     if not math.isfinite(actual)or relative>2e-5:
      report['mismatchCount']+=1
      if len(report['mismatchExamples'])<40:report['mismatchExamples'].append({'path':rel,'headerOffset':h['headerOffset'],'node':c['node'],'curve':c['curve'],'type':c['type'],'frame':t,'expected':expected,'actual':actual,'error':error})
    report['curves']+=1
   report['animations']+=1
  report['carriers']+=1
 except Exception as e:report['failures'].append({'path':rel,'error':str(e),'eip':hex(mu.reg_read(UC_X86_REG_EIP))})
 if report['carriers']%200==0:print(report['carriers'],'carriers',report['mismatchCount'],'mismatches',len(report['failures']),'failures',flush=True)
report['elapsedSeconds']=time.time()-start;report['limits']=['Four sample times per dynamic curve, not every frame. Constants decoded directly from file.','Original time routine clamps end to duration-0.01; comparison uses returned frame.','Tolerance2e-5*max(1,abs(expected)); original float32/x87 versus double Hermite arithmetic.'];(BASE/'reports/animation-legacy-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k not in ['mismatchExamples','failures']},indent=2))
