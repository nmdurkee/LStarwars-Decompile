"""Summarize observed original-code outcomes in the portable module oracle."""
import struct,json,collections,hashlib
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
source=BASE/'reports/animation-portable-cases.bin'
size=0x10d8
groups=collections.Counter();effects=collections.Counter();contexts=collections.Counter();remaps=collections.Counter();changed=collections.Counter();guard=collections.Counter()
with source.open('rb') as f:
 assert f.read(8)==b'ANIMCS01'
 count=struct.unpack('<I',f.read(4))[0]
 for index in range(count):
  kind,length=struct.unpack('<II',f.read(8));params=struct.unpack('<'+'I'*length,f.read(length*4));before=f.read(size);after=f.read(size);ret,random=struct.unpack('<II',f.read(8));groups[kind]+=1
  if kind!=2:continue
  oldcontext=struct.unpack_from('<b',before,0x7b5)[0];newcontext=struct.unpack_from('<b',after,0x7b5)[0]
  oldaction=struct.unpack_from('<h',before,0x7aa)[0];newaction=struct.unpack_from('<h',after,0x7aa)[0]
  contexts[f'{oldcontext}->{newcontext}']+=1
  effects[{0:'none',1:'stun death frontier',2:'airborne death frontier'}[ret]]+=1
  if oldaction!=newaction:remaps[f'{oldaction}->{newaction}']+=1
  present=oldaction>=0 and bool(params[5+oldaction//32]&(1<<(oldaction%32)))
  blending=before[0x39]!=0
  matching=struct.unpack_from('<h',before,0x3c if blending else 0x3e)[0]==oldaction
  ready=oldaction!=-1 and (not present or matching)
  guard[f'context={oldcontext}, ready={ready}, substate={before[0x7b3]}']+=1
  for offset,(a,b) in enumerate(zip(before,after)):
   if a!=b:changed[f'0x{offset:04x}']+=1
 assert not f.read(1)
report={'method':'Counts of captured original PC outputs; this is outcome coverage, not instrumented branch or exhaustive state-space coverage.','caseFile':str(source.relative_to(BASE)),'sha256':hashlib.sha256(source.read_bytes()).hexdigest(),'total':count,'groups':dict(groups),'deathContextCases':groups[2],'effects':dict(effects),'contextTransitions':dict(contexts),'actionTransitions':dict(remaps),'inputGuards':dict(guard),'changedByteOffsets':dict(changed),'limits':['Death-side-effect frontier precedes KillParts, so corpse/debris/pickup/respawn effects are absent.','Context 96 has no branch in TakeHitCode; its unchanged outputs do not prove that DieGround is unreachable elsewhere.']}
(BASE/'reports/animation-portable-state-coverage.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items()if k not in ['inputGuards','changedByteOffsets']},indent=2))
