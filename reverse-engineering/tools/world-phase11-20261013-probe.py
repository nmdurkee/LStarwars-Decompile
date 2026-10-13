import json,struct,hashlib,time
from pathlib import Path
peer=Path(__file__).with_name('world-phase7-20261013-verify.py');scope={'__file__':str(peer)};code=peer.read_text();exec(compile(code[:code.index('cases=[];provenance=[]')],str(peer),'exec'),scope)
n=scope['n'];B=scope['B'];D=scope['D'];vm=scope['vm'];records=0x2913a58
from unicorn import UC_HOOK_CODE
stats={}
def obs(uc,a,z,data):stats[hex(a)]=stats.get(hex(a),0)+1
for a in [0x64ba10,0x6488e0,0x658330,0x658490,0x650e40]:n.mu.hook_add(UC_HOOK_CODE,obs,begin=a,end=a)
files=[];start=time.time()
for f in sorted((B/'extracted').rglob('*.PAR')):
 payload=f.read_bytes();c=scope['make'](payload);scope['current']=c;scope['trace']=[];scope['filepos']=scope['opens']=scope['reads']=scope['closes']=0
 n.write(D,bytes(0xc0000));n.write(scope['BUF'],bytes(4096));n.pack('<I',scope['HANDLE'],0xffffffff);n.pack('<I',scope['ARCHIVE'],0);n.pack('<I',scope['WRITING'],0);n.pack('<I',scope['SWAP'],0);n.pack('<I',0x91ee88,0)
 n.write(D+0x5000,b'levels\\authored.par\0');n.write(records,bytes([167])*(128*376));n.write(0x291f688,bytes(128));n.write(0x29208d0,bytes(128));n.pack('<I',0x2947b74,D+0x50000);n.pack('<I',0x2962098,0);n.pack('<I',0x296209c,0);n.write(0x2924b10,bytes(32));n.pack('<I',0x8101b8,0xffffffff)
 n.call(0x6211c0,[1]);assert n.call(0x621270,[D+0x5000,0])==1
 version=n.call(0x6217e0);count=n.call(0x6217e0);assert 1<=version<=16 and count<=128,(f,version,count)
 for i in range(count):
  n.write(records+i*376+0x90,b'\xff'*16);n.call(0x64ba10,[records+i*376,version,1],count=30000000)
 position=n.unpack('<I',scope['POS'])[0];n.call(0x6213e0)
 files.append(dict(path=str(f.relative_to(B)).replace('\\','/'),bytes=len(payload),sha256=hashlib.sha256(payload).hexdigest(),version=version,recordCount=count,recordImageSha256=hashlib.sha256(n.read(records,128*376)).hexdigest(),bufferPosition=position,transportPosition=scope['filepos']))
report=dict(binarySha256=n.sha256,files=len(files),recordCalls=sum(f['recordCount'] for f in files),nativeLookupCalls=stats,seconds=round(time.time()-start,3),scope='actual64ba10 record decoding from whole retained PAR payload, before trailing instances/outer64c300 publication. Original lookup bodies execute on prepared scene-null sprite groups/empty particle registry/all-null1600audio name pointers. Only open/read/close transport adapted.',details=files)
(B/'reports/world-phase11-20261013-probe.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='details'}))
