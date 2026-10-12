"""Original top-level frame dispatcher branch/call ordering, with explicit subsystem adapters."""
import importlib.util,json,re,struct,itertools,random,hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ECX
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();B=m.BASE;WORLD=n.DATA;LEVEL=WORLD+0x10000;AREA=WORLD+0x11000;SCENE=WORLD+0x12000;RES=WORLD+0x13000;VOBJ=WORLD+0x14000;VTABLE=WORLD+0x14100;CAMERA=WORLD+0x15000;MATRIX=WORLD+0x16000;VIRTUAL=n.STOP+0x100
code=(B/'decompiled/corpus-expanded/FUN_491d50.c').read_text();body=code[code.index('{'):];targets={int(a,16)for a in re.findall(r'FUN_([0-9a-fA-F]{6,8})\s*\(',body)};events=[];options={};timers=[0x951000,0x879364,0x87b8c0,0x924ddc,0x876830,0x876834]
def boundary(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 record={'callee':hex(address),'site':hex(ret),'args':list(n.unpack('<8I',sp+4)),'ecx':mu.reg_read(UC_X86_REG_ECX)}
 if address==0x5b1220:record['selectedState']=n.unpack('<i',record['args'][0])[0]
 if address in [0x546380,0x545a80]:record['playerPositions']=list(n.unpack('<8I',record['args'][0]))
 events.append(record)
 if address in options.get('allowOriginal',set()):return
 value=options.get('returns',{}).get(address,options.get('overridePause',0)if address==0x565bf0 else options.get('extraEnabled',0)if address==0x56e160 else 0)
 cleanup=8 if address in [VIRTUAL,0x5b11b0]else 12 if address==0x5b1220 else 4
 mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+cleanup);mu.reg_write(UC_X86_REG_EIP,ret)
for address in targets|{VIRTUAL}:n.mu.hook_add(UC_HOOK_CODE,boundary,begin=address,end=address)
def setup(paused,force,override,cut,mute,levelFlags,delta):
 n.write(WORLD,bytes(0x17000));events.clear();options.clear();options.update(overridePause=override,extraEnabled=0);n.pack('<I',WORLD,0xabcdef);n.pack('<I',WORLD+0x16500,0xdeadbeef);n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x128,LEVEL);n.pack('<I',WORLD+0x12c,AREA);n.pack('<I',WORLD+0x134,SCENE);n.pack('<I',SCENE+8,RES);n.pack('<I',LEVEL+0x64,levelFlags);n.pack('<I',0x95e418,VOBJ);n.pack('<I',VOBJ,VTABLE);n.pack('<I',VTABLE+0x20,VIRTUAL);n.pack('<I',0x8021b4,CAMERA);n.pack('<I',0x925164,MATRIX);n.pack('<16I',CAMERA+0xb8,*range(16));n.pack('<I',0x93b328,paused);n.pack('<I',0x950744,force);n.pack('<I',0x951be0,cut);n.pack('<I',0x2962034,mute);n.pack('<f',0x925018,delta);n.pack('<I',0x800944,0);n.pack('<h',0x921454,-1);n.write(0x93d7f0,bytes(32))
 for address in [0x921e58,0x921dfc,0x87658c,0x951b80,0x950780,0x87b4d8,0x926bd4,0x855de0,0x951c58,0x947bbc,0x951364,0x951b88,0x951b98,0x951b9c]:n.pack('<I',address,0)
 for address,value in zip(timers,[1,.01,0,-1,5,100]):n.pack('<f',address,value)
def expected(paused,force,override,cut,mute,flags):
 seq=[0x549450,0x55fac0,0x5f9e90]
 if not paused:seq+=[0x43b940]
 seq+=[0x4c00c0,0x46c7d0,0x54b0b0,VIRTUAL]
 if not mute:seq+=[0x698820,0x698e70,0x548690,0x698930,0x698920,0x653460,0x548c40]
 if paused and not force:seq+=[0x565bf0]
 if not paused or force or override:
  seq +=[0x5d4770,0x63dcd0,0x552ac0,0x5d3490,0x57ed70]
  if paused:seq+=[0x565bf0]
  seq+=[0x57ef50,0x428a40]
  if flags&8:seq+=[0x68ed90]
  seq+=[0x59f740,0x5a1780,0x686950,0x544420,0x637860,0x58baf0,0x471650,0x4d4980,0x559c60]
  if flags&8:seq+=[0x66cc60]
  seq+=[0x5b1b10,0x4ce5f0]
  if not cut:seq+=[0x430430,0x434a20]
  seq+=[0x58b3a0]
  if not cut:seq+=[0x56e160,0x4ce630,0x5a3050,0x426fa0,0x405ac0,0x408af0,0x57a4d0,0x583030,0x64eb00,0x56ee80,0x59ff80,0x5488a0,0x559cd0,0x4bcb10,0x5769d0,0x56e570]
  seq+=[0x495310,0x690610]
  if not cut:seq+=[0x42f4a0]
  seq+=[0x5a25e0,0x5a82c0,0x5e4e00,0x5e4ea0,0x40ade0,0x55d1e0,0x54a0d0]
  if not cut:seq+=[0x5a3bd0]
  if flags&0x400:seq+=[0x564ac0]
 else:seq+=[0x5e4e00,0x5d3490,0x5d4770,0x603cc0,0x495310,0x690610]
 seq+=[0x5606d0,0x565670,0x5f9940,0x5f9530,0x549050,0x4b71a0,0x565230]
 return [hex(x)for x in seq]
report={'binarySha256':n.sha256,'sourceEvidence':{'file':'decompiled/corpus-expanded/FUN_491d50.c','sha256':hashlib.sha256((B/'decompiled/corpus-expanded/FUN_491d50.c').read_bytes()).hexdigest(),'id':re.search(r'ev_[0-9a-f]+',code).group()},'method':'Original dispatcher0x491d50 with explicit no-op subsystem adapters. Only dispatcher control flow and its own writes execute; this does not prove subsystem behavior or whole-frame correctness.','cases':0,'mismatches':[],'failures':[],'fixtures':[],'stateAssertions':0,'stateMismatches':[],'boundaryCallees':[hex(x)for x in sorted(targets)],'virtualAdapter':hex(VIRTUAL)}
def main():
 try:
  for paused,force,override,cut,mute,flags,delta in itertools.product([0,1],[0,1],[0,1],[0,1],[0,1],[0,8,0x400,0x408],[0,1/60,.1]):
   setup(paused,force,override,cut,mute,flags,delta);n.call(0x491d50,[WORLD,WORLD+0x16500],count=1000000);actual=[x['callee']for x in events];want=expected(paused,force,override,cut,mute,flags);meta={'paused':paused,'forceUpdate':force,'overridePause':override,'cutscene':cut,'audioDisabled':mute,'levelFlags':flags,'delta':delta};report['cases']+=1
   if actual!=want and len(report['mismatches'])<8:report['mismatches'].append({'input':meta,'expected':want,'actual':actual})
 
   f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
   expectedTimers=[f32(f32(x)-f32(delta)) if (not paused or force or override)and not cut and x>0 else f32(x)for x in[1,.01,0,-1,5,100]]
   expectedCamera=list(range(16))if paused and not force and not override else[0]*16
   effects=next(x for x in events if x['callee']=='0x5f9940')['args'][0];wantEffects=struct.unpack('<I',struct.pack('<f',f32(delta)/f32(1/60) if not paused else 0))[0]
   expectedState=expectedTimers+[0xabcdef,0]+expectedCamera+[wantEffects]
   actualState=[n.unpack('<f',x)[0]for x in timers]+[n.unpack('<I',WORLD)[0],n.unpack('<I',WORLD+0x16500)[0]]+list(n.unpack('<16I',MATRIX))+[effects]
   report['stateAssertions']+=len(expectedState)
   if expectedState!=actualState and len(report['stateMismatches'])<8:report['stateMismatches'].append({'input':meta,'expected':expectedState,'actual':actualState})
 
   report['fixtures'].append({'input':meta,'calls':events,'timers':[n.unpack('<f',x)[0]for x in timers],'worldFirstWord':n.unpack('<I',WORLD)[0],'cameraMatrix':list(n.unpack('<16I',MATRIX))})
 except Exception as e:report['failures'].append({'error':str(e),'completed':report['cases'],'nearFailure':[{'address':hex(i.address),'instruction':i.mnemonic+' '+i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x491d50,0xa00),0x491d50) if 0x492648<=i.address<=0x492670]})
 report['signatureCorrection']={'observed':'Original requires world pointer and separate output/state pointer. Instruction0x49265d clears the second argument target; world first word remains unchanged. Ghidra listing conflates these.','instructions':[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x491d50,0xa00),0x491d50) if 0x492648<=i.address<=0x492670]}
 report['limits']=['All direct subsystem callees are boundary adapters, including gameplay, graphics, audio and input. No inference of their behavior from these traces.','No players, custom level callback, populated secondary world managers, menu requests or area transition request in this fixture.','The virtual callback uses the observed callee-cleanup convention and supplies no delta mutation.','Global names are descriptive hypotheses except fields already covered by subsystem evidence.']
 (B/'reports/native-frame-dispatch.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({'cases':report['cases'],'mismatches':report['mismatches'][:1],'failures':report['failures'],'stateAssertions':report['stateAssertions'],'stateMismatches':report['stateMismatches'][:1]}));return 1 if report['mismatches']or report['stateMismatches']or report['failures']else 0
 

if __name__=='__main__':raise SystemExit(main())
