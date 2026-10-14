"""Original packet publication/stats/cloning; only virtual listener supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase21-20261013-verify.py').read_text().split('\nfor free in range')[0])
n.mu.hook_del(next(iter([])))if False else None
PUB=D+0x100;STATE=D+0x200;STATS=D+0x500;LISTENERS=D+0x1000;VTS=D+0x1800;LISTENER_CB=n.STOP+0x700
packet=None
# Phase21 hook only intercepts its callbackaddresses/60f190. Fresh emulator removes that transport adapter.
n=nm.NativeX86()
def rb(p):
 if p in shadow:return shadow[p]
 if POOL<=p<LIMIT:return 0x5a
 raise ValueError('unmapped '+hex(p))
def wb(p,v):
 if p not in shadow and not POOL<=p<LIMIT:raise ValueError('unmapped write '+hex(p))
 shadow[p]=v&255

def delivery(listener,words,model):
 name='Deliver';ordinal[name]=ordinal.get(name,0)+1;read=rd if model else lambda p:n.unpack('<I',p)[0];events.append(dict(name=name,listener=listener,packet=words,observed=[read(words[1]+0x4b0)if words[1]else 0,read(POOL+0x4b0),read(MODE+0x34)]))
 for key in ['Deliver','Deliver#'+str(ordinal[name])]:
  for p,size,v in config.get('patches',{}).get(key,[]):
   if model:
    for i in range(size):wb(p+i,v>>(i*8))
   else:n.write(p,int(v).to_bytes(size,'little'))
 if config.get('consume')and words[1]:
  if model:release(words[1])
  else:
   p=words[1]+0x4b0;value=n.unpack('<I',p)[0];n.pack('<I',p,value-1 if value>1 else 0)
def listenerhook(mu,address,size,data):
 if address!=LISTENER_CB:return
 sp=mu.reg_read(UC_X86_REG_ESP);words=list(n.unpack('<6I',sp+4));delivery(mu.reg_read(UC_X86_REG_ECX),words,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+28);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,listenerhook)
def fallback():wd(rd(0x28572e0)+0x34,0xa0001000)
def stats(p,channel):
 node=rd(PUB+4)
 while node:
  if rb(node+12)==channel&255:wd(node+0x38,rd(node+0x38)+((p[3]-p[2])if p[1]else 0));wd(node+0x40,rd(node+0x40)+1);break
  node=rd(node)
 release(p[1])
def clone(p):
 nxt=allocation()[1];old=p[1]
 if old and nxt:
  length=(p[3]-p[2])&0xffffffff
  for i in range(length):wb((nxt+p[2]+i)&0xffffffff,rb((old+p[2]+i)&0xffffffff))
 else:fallback()
 release(p[1]);p[1]=nxt

def publish(p,channel):
 p=p.copy();buffer=p[1]
 if not buffer:return
 length=(p[3]-p[2])&0xffffffff
 if 0<length<0x80000000:
  p[2]=(p[2]-1)&0xffffffff;wb((buffer+p[2])&0xffffffff,channel);wd(buffer+0x4b0,rd(buffer+0x4b0)+1);stats(p,channel);listener=rd(rd(0x28fec04)+0x94)
  while listener:
   clone(p);buffer=p[1]
   if buffer:wd(buffer+0x4b0,rd(buffer+0x4b0)+1)
   else:fallback()
   delivery(listener,p+[0,0],True);listener=rd(listener+4)
 release(buffer)
def setup22(c):
 global segments,poolOriginal,packet
 n.write(D,bytes(0x5000));poolOriginal=bytearray([0x5a])*(LIMIT-POOL)
 for i in range(512):struct.pack_into('<I',poolOriginal,i*STRIDE+0x4b0,c.get('occupied',1))
 for i in c.get('freeList',[1,2,3,4]):struct.pack_into('<I',poolOriginal,i*STRIDE+0x4b0,0)
 slot=c.get('bufferSlot',0);buffer=0 if slot is None else POOL+slot*STRIDE
 if buffer:struct.pack_into('<I',poolOriginal,slot*STRIDE+0x4b0,c.get('counter',2));poolOriginal[slot*STRIDE+32:slot*STRIDE+64]=bytes(range(32))
 n.write(POOL,poolOriginal);n.pack('<I',0x28572e0,MODE);n.pack('<I',MODE+0x34,0x89abcdef);n.pack('<I',0x28fec04,STATE);n.pack('<I',PUB+4,STATS if c.get('stats',True)else 0)
 for i,ch in enumerate(c.get('channels',[10,11,10])):node=STATS+i*0x80;n.pack('<I',node,STATS+(i+1)*0x80 if i+1<len(c.get('channels',[10,11,10]))else 0);n.write(node+12,bytes([ch]));n.pack('<I',node+0x38,c.get('bytesCount',0xfffffffe));n.pack('<I',node+0x40,c.get('packetsCount',0xffffffff))
 listeners=c.get('listeners',2);n.pack('<I',STATE+0x94,LISTENERS if listeners else 0)
 for i in range(listeners):node=LISTENERS+i*0x80;vt=VTS+i*0x40;n.pack('<II',node,vt,LISTENERS+(i+1)*0x80 if i+1<listeners else 0);n.pack('<I',vt+12,LISTENER_CB)
 packet=[c.get('mode',1),buffer,c.get('start',32),c.get('end',64)];n.pack('<4I',OUT,*packet)
 slots=set(c.get('freeList',[1,2,3,4]))
 if slot is not None:slots.add(slot)
 segments=[(D,0x5000),(0x28572e0,4),(0x28fec04,4)]+[(POOL+i*STRIDE,STRIDE)for i in sorted(slots)]+[(POOL+i*STRIDE+0x4b0,4)for i in range(512)]
 for p,size,value in c.get('initialPatches',[]):n.write(p,int(value).to_bytes(size,'little'))
def execute22(c,method='Publish'):
 global config,events,ordinal,shadow,checks
 config=c;setup22(c);initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal={};p=packet.copy();channel=c.get('channel',10)
 if method=='Publish':publish(p,channel)
 elif method=='Clone':clone(p);wd(OUT+4,p[1])
 else:stats(p,channel)
 modelFinal=snapshot(True);modelEvents=events.copy();modelHash=poolhash(True);events=[];ordinal={}
 if method=='Publish':n.call(0x60f190,packet+[channel],regs={UC_X86_REG_ECX:PUB})
 elif method=='Clone':n.call(0x60ee80,regs={UC_X86_REG_ECX:OUT})
 else:n.call(0x60e590,packet+[channel],regs={UC_X86_REG_ECX:PUB})
 nativeFinal=snapshot();nativeEvents=events.copy();nativeHash=poolhash()
 for group,a,b in [('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents),('poolHash',nativeHash,modelHash)]:
  checks+=1
  if a!=b:errors.append(dict(method=method,group=group,context=c,native=a,model=b))
 cases.append(dict(method=method,context=c,packet=packet,channel=channel,initial=initial,final=nativeFinal,nativeEvents=nativeEvents,poolSha256=nativeHash))
for free in range(512):execute22(dict(freeList=[free],counter=2),'Clone')
for channel in range(256):execute22(dict(channel=channel,channels=[13,channel,channel]),'Statistics')
for bufferSlot,counter,statsFlag,listeners,consume in itertools.product([None,0],[0,1,2,0xffffffff],[False,True],[0,1,3],[False,True]):execute22(dict(bufferSlot=bufferSlot,counter=counter,stats=statsFlag,listeners=listeners,consume=consume))
for freeList,counter,listeners in itertools.product([[],[0],[1],[1,2],[1,2,3]],[0,1,2,0xffffffff],[1,2,4]):execute22(dict(freeList=freeList,counter=counter,listeners=listeners))
for method in ['Publish','Statistics']:
 for start,end in [(32,32),(33,32),(32,64),(64,32),(32,0x80000020),(0x80000020,32)]:execute22(dict(start=start,end=end,listeners=0),method)
for c in [dict(patches={'Deliver#1':[[LISTENERS+4,4,0]]}),dict(patches={'Deliver#1':[[LISTENERS+4,4,LISTENERS+0x100]]},listeners=3),dict(patches={'Deliver#1':[[POOL+STRIDE+0x4b0,4,0]]}),dict(patches={'Deliver#1':[[POOL+STRIDE+0x4b0,4,0xffffffff]]}),dict(patches={'Deliver#1':[[0x28fec04,4,0]]}),dict(freeList=[],counter=1,consume=True,listeners=4),dict(freeList=[],counter=0,listeners=3),dict(bufferSlot=None,freeList=[],listeners=3),dict(mode=0),dict(mode=0xffffffff)]:execute22(c)
for channel,start,end in itertools.product([0,10,255],[32,64],[32,64]):execute22(dict(bufferSlot=None,channel=channel,start=start,end=end),'Statistics')
for freeList,mode in itertools.product([[],[0],[1],[1,2]],[0,1,0xffffffff]):execute22(dict(bufferSlot=None,freeList=freeList,mode=mode),'Clone')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],actualBodies=['0x60f190','0x60e590','0x60ee80','0x4ef660','0x60f2d0'],remainingPorts=['Virtual listener vtable0c'],limits=['Packetstruct disjoint frompool; bounded copyingpayload; acyclic listener andstatistics chains.','StandaloneStatistics allowsallrawintegerdelta/count/countervalues. Publish signedwrappedlength gates.','Same originalfixed512pool fullSHA, allcounters andchosenrecords compared; finalvirtualcallbackonlysupplied.'])
(nm.BASE/'reports/script-phase22-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase22-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
