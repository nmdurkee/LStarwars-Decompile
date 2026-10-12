"""Original currency loss and heart-drop probability. No OS APIs or boundary hooks."""
import importlib.util,json,itertools,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
n=m.NativeX86();B=m.BASE;OBJ=n.DATA;OTHER=OBJ+0x2000;CHAR=OBJ+0x4000;GAME=OBJ+0x5000;CFG=OBJ+0x6000;TABLE=OBJ+0x7000;WALLET=OBJ+0x9000;PICKUPS=OBJ+0xa000
report={'binarySha256':n.sha256,'method':'Unmodified0x46c6e0 currency deduction and0x46c4f0 drop decision with original cheat, invincibility and QRAND callees. Synthetic finite fields; no hooks or game process.','contracts':{},'failures':[]};vectors=[]
def reset():
 n.write(OBJ,bytes(0xc000));n.pack('<I',OBJ+0x54,CHAR);n.pack('<I',CHAR+0x24,GAME);n.pack('<I',OBJ+0x7fc,WALLET);n.pack('<I',0x8032c4,CFG);n.pack('<II',CFG,TABLE,128);n.pack('<I',0x8032cc,0);n.pack('<f',0x950d90,0);n.pack('<I',0x951288,0);n.pack('<I',0x951154,0);n.pack('<f',0x925040,0);n.pack('<I',0x93d7f0,OBJ);n.pack('<I',0x93d7f4,OTHER);n.pack('<I',0x81020c,0);n.pack('<I',0x291f664,PICKUPS)
def contract(name):r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,expected,actual,meta):
 vectors.append({'contract':next(k for k,v in report['contracts'].items()if v is r),'input':meta,'native':actual});r['cases']+=1
 if expected!=actual:
  r['mismatches']+=1
  if len(r['examples'])<12:r['examples'].append({'input':meta,'expected':expected,'actual':actual})
difficulty=n.unpack('<I',0x7f3a14)[0];levels={i:list(n.unpack('<bb',difficulty+i*4))for i in range(-3,4)};report['difficultyTable']={'address':hex(difficulty),'rows':levels}
try:
 r=contract('currency_deduction_and_return_suppression')
 for amount,reason,mode,dynamic,level,suppression in itertools.product([0,1,999,1000,1999,2000,5000,12500,25000,0xffffffff],[0,1,2,3],[0,1],[0,1],range(-3,4),['none','cheat','timer']):
  reset();n.pack('<I',WALLET,amount);n.pack('<I',0x951154,mode);n.pack('<B',TABLE+0x2c*32+8,dynamic);n.pack('<i',0x856c0c,level);n.pack('<I',CFG+8,4 if suppression=='cheat'else 0);n.pack('<f',0x925040,1 if suppression=='timer'else 0)
  wanted=(25000 if mode else 2000)if reason==1 else(12500 if mode else 1000)if reason==2 else 0;modifier=levels[level][0]if dynamic else 0
  if modifier==1:wanted*=2
  elif modifier==-1:wanted>>=1
  deducted=min(amount,wanted);returned=n.call(0x46c6e0,[OBJ,reason]);check(r,[amount-deducted,0 if suppression!='none'else deducted],[n.unpack('<I',WALLET)[0],returned],{'amount':amount,'reason':reason,'specialMode':mode,'dynamicAdjustment':modifier,'suppression':suppression})
 r=contract('currency_early_protection_guards')
 for wallet,flags,invtime,charflags,reason in itertools.product([False,True],[0,4,0x80,0xfc],[-1,0,1],[0,0x8000],[1,2]):
  reset();n.pack('<I',WALLET,10000);n.pack('<I',OBJ+0x7fc,WALLET if wallet else 0);n.pack('<I',CFG+8,flags);n.pack('<f',OBJ+0xdec,invtime);n.pack('<I',GAME+0x90,charflags);blocked=not wallet or bool(flags&0x80)or invtime>0 or bool(charflags&0x8000);deducted=0 if blocked else 2000 if reason==1 else 1000
  returned=n.call(0x46c6e0,[OBJ,reason]);check(r,[10000-deducted,0 if flags&0x7c else deducted],[n.unpack('<I',WALLET)[0],returned],{'hasWallet':wallet,'cheatFlags':flags,'invincibilityTimer':invtime,'characterFlags90':charflags,'reason':reason})
 r=contract('heart_drop_health_pickups_difficulty_and_rng');rng=random.Random(0x46c4f0)
 for i in range(4000):
  reset();maxima=[rng.choice([0,1,4,6,127,255])for _ in range(2)];health=[rng.randrange(0,256)for _ in range(2)];dead=[rng.randrange(2)for _ in range(2)];present=[rng.randrange(2)for _ in range(2)];counter=rng.randrange(0,256);activehearts=rng.randrange(0,8);seed=rng.randrange(65536);dynamic=rng.randrange(2);level=rng.randrange(-3,4)
  total=0;missing=0
  for j,p in enumerate([OBJ,OTHER]):
   n.pack('<I',0x93d7f0+j*4,p if present[j]else 0);n.pack('<B',p+0x28b,dead[j]);n.pack('<BB',p+0x107e,maxima[j],health[j])
   if present[j]and not dead[j]and maxima[j]:total+=maxima[j];missing+=maxima[j]-(health[j] if health[j]<128 else health[j]-256)
  n.pack('<B',0x8668c9,counter);n.pack('<I',0x81020c,8)
  for j in range(8):n.pack('<h',PICKUPS+j*0x220+0x13e,0xcb);n.pack('<B',PICKUPS+j*0x220+0x144,1 if j<activehearts else 0)
  n.pack('<I',0x80253c,seed);n.pack('<B',TABLE+0x2c*32+8,dynamic);n.pack('<i',0x856c0c,level);modifier=levels[level][1]if dynamic else 0
  if total:
   if missing>0:missing-=activehearts
   numerator=max(0,min(total,missing+(9 if counter>5 else 8)-counter));threshold=(numerator<<16)//total
   if modifier==1:threshold//=2
   elif modifier==-1:threshold*=2
   nextseed=(seed*0x24cd+1)&65535;want=int(nextseed<threshold)
  else:nextseed=seed;want=0
  result=n.call(0x46c4f0,[]);check(r,[want,nextseed],[result,n.unpack('<I',0x80253c)[0]],{'maxima':maxima,'health':health,'dead':dead,'present':present,'counter':counter,'activeHearts':activehearts,'seed':seed,'dynamicAdjustment':modifier})
except Exception as e:report['failures'].append({'error':str(e)})
report['totals']={'cases':sum(v['cases']for v in report['contracts'].values()),'mismatches':sum(v['mismatches']for v in report['contracts'].values()),'failures':len(report['failures'])};report['limits']=['Currency pool and drop decision only: no pickup spawning, rendering, player collection or score UI.','Native difficulty table kept unchanged; synthetic global difficulty row -3..3.','Heart-drop fixtures vary bounded player records and eight existing pickup records; this is not a complete world lifecycle.']
(B/'reports/native-combat-economy.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-combat-economy-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n');print(json.dumps(report['totals']));print(report['failures']);print({k:v['examples']for k,v in report['contracts'].items()if v['mismatches']});raise SystemExit(1 if report['totals']['mismatches']or report['failures']else 0)
