"""Actual53db30 recorder through actual60f190 transport body, final listener supplied."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase22-20261013-verify.py').read_text().split('\nfor free in range(512)')[0])
REC=D+0x2800;VT=D+0x2900;PUB=0x28572e8
oldport=port
def port(name,args,model):
 if name=='Publish':publish(args[:4],args[4]);return 0
 return oldport(name,args,model)
def recordhook(mu,address,size,data):
 if address not in [CB,CB+0x10]:return
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==CB:name='Allowed';args=[];argc=0
 else:name='Identifier';args=[mu.reg_read(UC_X86_REG_ECX),n.unpack('<I',sp+4)[0]];argc=1
 value=port(name,args,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4+argc*4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,recordhook)
for gate,allowed,listeners,freeList in itertools.product([False,True],[0,1],[0,1,3],[[],[1],[1,2,3]]):
 config=dict(gate=gate,allowed=allowed,listeners=listeners,freeList=freeList,bufferSlot=None,tokens=['alpha','beta'],count=2,consume=True)
 setup22(config);n.pack('<I',0x9242c0,REC);n.pack('<I',0x876d88,CB if gate else 0);n.pack('<I',REC,VT);n.pack('<I',VT+0x30,CB+0x10);n.pack('<II',ACTION+8,PTRS,2);n.pack('<I',ACTION+0x10,DESC);n.pack('<H',DESC+10,0x1234);n.write(DESC+9,b'\xab');n.pack('<II',PTRS,TOKENS,TOKENS+0x500);n.write(TOKENS,b'alpha\0');n.write(TOKENS+0x500,b'beta\0');segments+=[(0x9242c0,4),(0x876d88,4),(PUB+4,4)];initial=snapshot();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))};events=[];ordinal={};model_record(REC);modelFinal=snapshot(True);modelEvents=events.copy();modelHash=poolhash(True);events=[];ordinal={};n.call(0x53db30,[ACTION,ACTOR]);nativeFinal=snapshot();nativeEvents=events.copy();nativeHash=poolhash()
 for group,a,b in [('images',nativeFinal,modelFinal),('events',nativeEvents,modelEvents),('poolHash',nativeHash,modelHash)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=config,native=a,model=b))
 cases.append(dict(method='RecordingPipeline',context=config,initial=initial,final=nativeFinal,nativeEvents=nativeEvents,poolSha256=nativeHash))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:3],actualBodies=['0x53db30','0x53d940','0x53d5d0','0x60f190','0x60e590','0x60ee80'],remainingPorts=['Optional876d88 gate','Recorder vtable30 actorID','Finallistener vtable0c'],managedExecution=False)
(nm.BASE/'reports/script-phase22-20261013-pipeline-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase22-20261013-pipeline-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
