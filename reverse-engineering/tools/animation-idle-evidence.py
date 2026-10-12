"""Durable native byte, recovered source, and idle oracle contract ledger."""
import importlib.util,hashlib,json,re
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();BASE=native.BASE;dis=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
for address,name in [(0x415050,'SelectBaseIdleAction'),(0x4150d0,'ResetIdleSchedule'),(0x4151c0,'ChooseIdleVariation'),(0x415370,'FinalizeIdleSelection')]:
 instructions=[]
 for ins in dis.disasm(n.read(address,0x4000),address):
  if ins.mnemonic=='int3':break
  instructions.append({'address':hex(ins.address),'bytes':ins.bytes.hex(),'mnemonic':ins.mnemonic,'operands':ins.op_str})
 raw=b''.join(bytes.fromhex(i['bytes'])for i in instructions);path=f'decompiled/corpus/FUN_{address:x}.c';text=(BASE/path).read_text()
 functions.append({'address':hex(address),'csharpMethod':'Recovered.Animation.IdleScheduling.'+name,'pseudocode':path,'evidenceId':re.search('ev_[0-9a-f]+',text)[0],'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest(),'linearExtentMethod':'Until first INT3 padding; not a reachability proof.','instructions':instructions})
paths=['reconstructed/animation/IdleScheduling.cs','reconstructed/animation/AnimationPlayback.cs','reconstructed/animation/DifferentialHarness.cs','tools/animation-idle-model.py','tools/animation-idle-native-verify.py','tools/animation-x87.py','reports/animation-idle-cases.bin','reports/animation-idle-native-verification.json']
sources=[{'path':p,'bytes':(BASE/p).stat().st_size,'sha256':hashlib.sha256((BASE/p).read_bytes()).hexdigest()}for p in paths]
verification=json.loads((BASE/'reports/animation-idle-native-verification.json').read_text())
fields=[(0x40,'i16','previousAction'),(0x42,'i16','requestedAction'),(0x2b8,'f32','totalIdleSeconds'),(0x2bc,'f32','currentIdleSeconds'),(0x2c0,'f32','idleLimitSeconds'),(0x2c4,'i16','currentIdleAction'),(0x2c6,'i16','previousIdleVariation')]
report={'binarySha256':n.sha256,'functions':functions,'sources':sources,'objectSize':0x10d8,'fields':[{'offset':hex(o),'type':t,'name':name}for o,t,name in fields],'adapterFacts':{'modelPresent':'object+0x50 !=0','variant':'object+0x54 -> +0x24 -> byte+0x116','characterFlags':'object+0x54 -> u32+4','throwHeld':'object+0xcc0 nonnull and pointed byte+0x7d nonzero','durationLookupValid':'character ID object+0x1064 resolves through global0x29130e4 model set; invalid mapping preserves global blend-out'},'globals':{'0x80253c':'LCG state','0x29a99a4':'most recent valid duration clip blend-out','0x925018':'seconds per frame'},'verification':{k:verification[k]for k in ['counts','totalComparisons','mismatches','failures','oracle','limits']},'authoredConfigurations':len(verification['authored']),'portableStatus':'Library and harness compile; managed differential execution pending Windows execution restriction. No managed behavior pass claimed.'}
(BASE/'reports/animation-idle-contract.json').write_text(json.dumps(report,indent=2));print(json.dumps({'functions':len(functions),'instructions':sum(len(f['instructions'])for f in functions),'comparisons':verification['totalComparisons'],'mismatches':verification['mismatches'],'oracleBytes':(BASE/'reports/animation-idle-cases.bin').stat().st_size},indent=2))
