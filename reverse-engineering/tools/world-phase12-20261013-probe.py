import json,struct,hashlib,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase11-20261013-verify.py');ns={'__file__':str(peer)};src=peer.read_text();exec(compile(src[:src.rindex('cases=[];provenance=[]')],str(peer),'exec'),ns)
n=ns['n'];B=ns['B'];D=ns['D'];REC=ns['REC'];io=ns['scope'];events=[];IN=0x291f7a8
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
# Runtime activation/selection is explicit; physical reader/decoder/lookups stay original.
def runtime(uc,a,z,data):
 sp=uc.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4+i*4)[0]
 if a==0x64ae50:
  i=arg(0);events.append(['activate',i,arg(1)]);n.pack('<II',IN+i*108+32,0,0x3f800000)
 else:events.append(['select',arg(0)]);n.pack('<I',0x2920888,0xffffffff);n.pack('<II',0x292096c,0,0)
 uc.reg_write(UC_X86_REG_EAX,0);uc.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);uc.reg_write(UC_X86_REG_ESP,sp+4)
for a in [0x64ae50,0x644000]:n.mu.hook_add(UC_HOOK_CODE,runtime,begin=a,end=a)
files=[];start=time.time()
for f in sorted((B/'extracted').rglob('*.PAR')):
 payload=f.read_bytes();c=ns['seed'](payload);io['current']=c;io['trace']=[];io['filepos']=io['opens']=io['reads']=io['closes']=0;ns['assetHash']=hashlib.sha256();ns['assetCounts']={};events=[]
 m=ns['Image'](c)
 for a,z in ns['REGIONS']:n.write(a,m.read(a,z))
 n.write(REC-376,bytes(376))
 for i in range(128):n.write(REC+i*376,b'\0');n.write(REC+i*376+144,b'\xff'*16)
 n.write(IN,bytes(40*108))
 for i in range(40):n.pack('<I',IN+i*108+12,0xffffffff)
 n.write(0x2920888,bytes(0x230));n.pack('<I',0x2920888,0xffffffff);n.pack('<I',0x2913a2c,0);n.pack('<I',0x8109d0,0xdeadbeef);n.pack('<I',0x296292c,0x12345678)
 n.pack('<II',D+0x90000,D+0x94000,0)
 ret=n.call(0x64c300,[io['PATH'],1,D+0x90000,1],count=100000000)
 files.append(dict(path=str(f.relative_to(B)).replace('\\','/'),bytes=len(payload),sha256=hashlib.sha256(payload).hexdigest(),result=ret,records=n.unpack('<I',0x2920a94)[0],instances=n.unpack('<I',0x2920a98)[0],bufferPosition=n.unpack('<I',io['POS'])[0],transportPosition=io['filepos'],runtimeCalls=events.copy(),registrySha256=hashlib.sha256(n.read(REC,128*376)+n.read(IN,40*108)).hexdigest()))
report=dict(binarySha256=n.sha256,files=len(files),records=sum(f['records'] for f in files),instances=sum(f['instances'] for f in files),runtimeCalls=sum(len(f['runtimeCalls']) for f in files),seconds=round(time.time()-start,3),scope='whole original64c300 PAR own-state loader and original64ba10/byte readers/asset lookups; open/read/close and runtimeactivation64ae50/selection644000 are explicit prepared services; no graphics/audio simulation claim',details=files)
(B/'reports/world-phase12-20261013-probe.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='details'}))
