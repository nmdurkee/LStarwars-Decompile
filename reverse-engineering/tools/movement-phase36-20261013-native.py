"""Original4d9760 with independent passed world and live current-world pointer."""
from pathlib import Path
import json,gzip,base64,itertools
p=Path(__file__).with_name('movement-phase34-20261013-native.py');q={'__file__':str(p)};exec(compile(p.read_text().split('for target,radius,limit,timer,legacy in itertools.product')[0],str(p),'exec'),q)
n=q['n'];m=q['m'];D=q['D'];SIZE=q['SIZE'];POD=q['POD'];WORLD=q['WORLD'];GAME=q['GAME'];CURRENT=D+0x16000;OTHER=GAME+0x100;bits=q['bits'];state=q['state'];events=q['events'];counts=q['counts'];vectors=[];errors=[]
def gid(value):return[0,GAME,OTHER][value]
def run(c):
 seed=dict(c);seed['mode']=c.get('mode',1)&0xffffffff;q['setup34'](seed);current=0 if c.get('nullCurrent')else CURRENT;n.pack('<I',0x802c54,current);n.pack('<I',CURRENT+0x128,gid(c.get('currentGame',1)));n.pack('<I',WORLD+0x128,gid(c.get('passedGame',1)));before=n.read(D,SIZE);before_random=n.unpack('<I',0x95e5d4)[0];expected=bytearray(before)+bytearray(0x100000-SIZE);model=dict(c);model['special']=gid(c.get('currentGame',1))==n.unpack('<I',0x87b090)[0];model['wrongWorld']=gid(c.get('passedGame',1))!=n.unpack('<I',0x87b08c)[0];state.clear();state.update(random=before_random,center=n.unpack('<f',0x7ffd08)[0],spread=n.unpack('<f',0x7ffd0c)[0],events=[]);ret=q['q']['oracle34'](model,expected);actual=n.call(0x4d9760,[POD,WORLD],count=3000000);after=n.read(D,SIZE);rand=n.unpack('<I',0x95e5d4)[0];center=n.unpack('<I',0x7ffd08)[0];spread=n.unpack('<I',0x7ffd0c)[0];bad=[]
 if ret!=actual:bad.append('return')
 if after!=expected[:SIZE]:bad.append('image')
 if events!=state['events']:bad.append('events')
 if rand!=state['random']:bad.append('random')
 if center!=bits(state['center'])or spread!=bits(state['spread']):bad.append('lateGlobals')
 if bad:errors.append(dict(input=c,bad=bad,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12]))
 vectors.append(dict(input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode(),result=actual,events=list(events),beforeRandom=before_random,afterRandom=rand,afterCenterBits=center,afterSpreadBits=spread,currentWorld=current,specialGame=n.unpack('<I',0x87b090)[0],projectileGame=n.unpack('<I',0x87b08c)[0],deltaBits=n.unpack('<I',0x925018)[0],lookAheadBits=n.unpack('<I',0x7f15e0)[0],nativeEntryCounts=dict(counts)))
for cur,passed,special,mode,wrong,phase in itertools.product([0,1,2],[0,1,2],[False,True],[-1,0,1,2],[False,True],[.5,1.]):run(dict(currentGame=cur,passedGame=passed,special=special,mode=mode,wrongWorld=wrong,phase=phase,spawnMode=4))
for phase,freeze,passed in itertools.product([.5,1.],[.125,1.],[0,1,2]):run(dict(nullCurrent=True,phase=phase,freeze=freeze,passedGame=passed))
for passed in[0,1,2]:run(dict(nullCurrent=True,phase=1.,passedGame=passed))
report=dict(binarySha256=n.sha256,cases=len(vectors),assertionGroups=5*len(vectors),mismatches=len(errors),errors=errors[:5],constructorAdapters=['64d270']);(m.BASE/'reports/movement-phase36-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:3])))
if errors:raise SystemExit('Independent world mismatch; no paired fixture')
with gzip.open(m.BASE/'reports/movement-phase36-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(sineTable='reverse-engineering/references/native-animation-sine-table.f32',angles=q['q']['q22']['angles'],vectors=vectors),f,separators=(',',':'))
