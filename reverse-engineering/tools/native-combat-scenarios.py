"""Original command -> hit -> death integration in one persistent synthetic world."""
import importlib.util,json
from pathlib import Path
spec=importlib.util.spec_from_file_location('fixture',Path(__file__).with_name('native-combat-fixture.py'));f=importlib.util.module_from_spec(spec);spec.loader.exec_module(f)
globals().update({k:v for k,v in vars(f).items()if not k.startswith('__')})
SCRIPT=OBJ+0x20000;WEAK=OBJ+0x21000;ATTWEAK=OBJ+0x21010;ARGS=OBJ+0x22000;TEXT=OBJ+0x23000
steps=[];failures=[];mismatches=[]
def command(address,tokens):
 n.write(ARGS,bytes(0x100));n.write(TEXT,bytes(0x1000))
 for i,t in enumerate(tokens):n.pack('<I',ARGS+4*i,TEXT+128*i);n.write(TEXT+128*i,t.encode()+b'\0')
 return n.call(address,[0,0,SCRIPT,ARGS,len(tokens),1],count=2000000)
def state():return {'hp':n.read(OBJ+0x107f,1)[0],'maximum':n.read(OBJ+0x107e,1)[0],'shield':n.read(OBJ+0xe38,1)[0],'deathState':n.read(OBJ+0x28b,1)[0],'protection':n.unpack('<f',OBJ+0x1018)[0]}
def step(name,fn,want):
 result=fn();got=state();record={'name':name,'expected':want,'actual':got,'return':result};steps.append(record)
 for k,v in want.items():
  if got[k]!=v:mismatches.append({'step':name,'field':k,'expected':v,'actual':got[k]})
try:
 reset();n.write(SCRIPT,bytes(0x5000));n.pack('<I',0x81020c,0);n.pack('<I',CHAR+4,0x2000000);n.pack('<B',GAME+0xf4,4);n.pack('<B',GAME+0xf5,6);n.pack('<I',0x923904,0);n.pack('<I',SCRIPT+0xd0,WEAK);n.pack('<I',WEAK,OBJ);n.pack('<I',ATTWEAK,ATT);n.pack('<I',0x93d500,1);n.pack('<I',0x93d504,OBJ);n.pack('<B',OBJ+0x378,1)
 step('SetHitPoints5',lambda:command(0x44b150,['5']),{'hp':5,'maximum':5,'deathState':0})
 step('TakeDamage2',lambda:command(0x44fd10,['damage=2']),{'hp':3,'protection':f32(.4)})
 step('Immediate second damage is protected',lambda:command(0x44fd10,['damage=1']),{'hp':3,'protection':f32(.4)})
 n.pack('<I',SCRIPT+0xd0,ATTWEAK);n.pack('<I',SCRIPT+0xe4,WEAK);n.pack('<I',ATT+0x1fc,0x1081)
 step('Player opponent attacker bypasses protection',lambda:command(0x44fd10,['opponent','damage=1']),{'hp':2,'protection':f32(.4)})
 n.pack('<I',SCRIPT+0xd0,WEAK);n.pack('<I',SCRIPT+0xe4,0)
 step('SetShieldHitPoints default',lambda:command(0x44b290,[]),{'hp':2,'shield':6})
 n.pack('<f',OBJ+0xd30,1)
 step('Unflagged script damage reaches active shield with zero damage',lambda:command(0x44fd10,['damage=2']),{'hp':2,'shield':6})
 step('Original shield hit lowers shield health',lambda:n.call(0x433be0,[0,OBJ,2,0]),{'hp':2,'shield':4})
 n.pack('<f',OBJ+0xd30,0);n.call(0x414ab0,[OBJ,0])
 step('Set one health before lethal group hit',lambda:command(0x44b150,['1']),{'hp':1,'maximum':1})
 step('TakeDamage set1 executes native lethal cleanup',lambda:command(0x44fd10,['set=1']),{'hp':0,'deathState':2})
 step('Setting health alone does not revive dead state',lambda:command(0x44b150,['default']),{'hp':4,'maximum':4,'deathState':2})
 step('Dead target rejects subsequent scripted damage',lambda:command(0x44fd10,['damage=1']),{'hp':4,'deathState':2})
except Exception as e:failures.append({'error':str(e),'completedSteps':len(steps)})
result={'binarySha256':n.sha256,'steps':steps,'mismatches':mismatches,'failures':failures,'scope':'One persistent synthetic NPC world. All command, hit, protection and death functions execute unchanged. Only media/rumble/alert boundaries inherited from fixture are intercepted; no final hit or death callback replacement.','functions':['0x44b150','0x44b290','0x44fd10','0x438230','0x433be0','0x414ab0','0x437770','0x4364e0'],'limits':['A programmed command sequence, not a complete original SCP scheduler or a live level.','No-parts character flag0x2000000 selects original no-debris branch.','No populated AI, game scripts, player death/stud drops or graphics/audio APIs.']}
(BASE/'reports/native-combat-scenarios.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'steps':len(steps),'mismatches':mismatches,'failures':failures}));raise SystemExit(1 if mismatches or failures else 0)
