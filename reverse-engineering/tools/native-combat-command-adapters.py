"""Original PC health command handlers and signed HitPoints condition."""
import importlib.util,struct,json,itertools,math
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
n=native.NativeX86();BASE=native.BASE;OBJ=n.DATA;OTHER=OBJ+0x2000;CHAR=OBJ+0x4000;GAME=OBJ+0x5000;SCRIPT=OBJ+0x6000;WEAK=OBJ+0x7000;OTHERWEAK=OBJ+0x7010;ARGS=OBJ+0x8000;TEXT=OBJ+0x9000;SCALAR=OBJ+0xa000
report={'binarySha256':n.sha256,'method':'Original PC command/condition functions with original string matching, decimal conversion and float-to-integer truncation. Synthetic character/actor state; no OS calls. TakeDamage dispatch alone records its final hit-handler boundary separately.','contracts':{},'failures':[]};vectors=[]
def reset(tokens=(),actor=True):
 n.write(OBJ,bytes(0xb000));n.pack('<I',OBJ+0x54,CHAR);n.pack('<I',CHAR+0x24,GAME);n.pack('<I',SCRIPT+0xd0,WEAK if actor else 0);n.pack('<I',WEAK,OBJ);n.pack('<I',OTHERWEAK,OTHER);n.pack('<B',GAME+0xf4,4);n.pack('<B',GAME+0xf5,6);n.pack('<BB',OBJ+0x107e,17,19);n.pack('<B',OBJ+0xe38,23);n.pack('<I',0x923904,0)
 for i,t in enumerate(tokens):n.write(TEXT+i*128,t.encode()+b'\0');n.pack('<I',ARGS+i*4,TEXT+i*128)
def contract(name):
 r={'cases':0,'mismatches':0,'examples':[]};report['contracts'][name]=r;return r
def check(r,want,got,meta):
 vectors.append({'contract':next(k for k,v in report['contracts'].items() if v is r),'input':meta,'native':got})
 r['cases']+=1
 if want!=got:
  r['mismatches']+=1
  if len(r['examples'])<12:r['examples'].append({'input':meta,'expected':want,'actual':got})
def gethp(direct=0,actor=SCRIPT):
 n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',SCALAR));n.call(0x441e20,[0,0,actor,0,direct]);n.mu.emu_start(n.STOP,n.STOP+6);return n.unpack('<f',SCALAR)[0]
calls=[]
def hit(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);calls.append(list(n.unpack('<IIIIII',sp+4)));ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,1);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hit,begin=0x438230,end=0x438230)

report['method']='Original health command handlers with real numeric parameter and message list lookup. Only named-character callback, bounded CRT sprintf string formatting, and downstream hit call are adapters; command token parsing, numeric conversion and message lookup run unmodified.'
report['contracts']={};report['failures']=[];vectors=[];BIND=n.STOP+0x100;CONTEXT=OBJ+0x20000;DEF=OBJ+0x20100;NAMES=OBJ+0x20200;MESSAGES=OBJ+0x21000;NODE=OBJ+0x21100;OTHERCHAR=OBJ+0x22000;OTHERGAME=OBJ+0x22100
params=[5.9,-1.2,260.75,.25]
def read_string(addr):return n.read(addr,128).split(b'\0')[0].decode('latin1')
def resolve(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);name=read_string(n.unpack('<I',sp+8)[0]).lower();ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,WEAK if name=='self'else OTHERWEAK if name=='other'else 0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,resolve,begin=BIND,end=BIND)
def sprintf(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);dst,fmt=n.unpack('<II',sp+4);template=read_string(fmt);parts=[read_string(n.unpack('<I',sp+12+4*i)[0])for i in range(template.count('%s'))];output=template%tuple(parts);n.write(dst,output.encode('latin1')+b'\0');ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,len(output));mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,sprintf,begin=0x6e69ef,end=0x6e69ef)
def setup(ts,actor,parameters,message):
 reset(ts,actor);calls.clear();n.write(CONTEXT,bytes(0x2200));n.pack('<I',0x923904,BIND);n.pack('<I',SCRIPT+0xe4,OTHERWEAK);n.pack('<I',OTHER+0x54,OTHERCHAR);n.pack('<I',OTHERCHAR+0x24,OTHERGAME);n.pack('<BB',OTHERGAME+0xf4,8,9);n.pack('<BB',OTHER+0x107e,29,31);n.pack('<B',OTHER+0xe38,37);n.pack('<I',0x93d500,0);n.pack('<I',0x93d504,0)
 n.pack('<I',CONTEXT+4,DEF);n.pack('<4f',CONTEXT+0x14,*params)
 for i,name in enumerate(['alpha','beta','gamma','delta']):
  n.write(NAMES+i*32,name.encode()+b'\0');n.pack('<I',DEF+0x18+i*8,NAMES+i*32)
 n.pack('<I',0x95df4c,MESSAGES);n.write(0x805d48,b'\0');n.pack('<I',MESSAGES+0x10,NODE if message else 0);n.write(NODE+8,b'hp\0');n.pack('<f',NODE+0x28,6.75)
 return CONTEXT if parameters else 0
forms={
 'SetHitPoints':[['character=other','3'],['7','prefixCHARACTER=other','dont_set_max'],['character=self','-1'],['character=missing','2'],['0','character=other','character=self','default'],['messageval=hp'],['3','messageval=missing'],['character=other','messageval=hp','dont_set_max'],['prefixMESSAGEVAL=hp'],['alpha'],['beta'],['gamma'],['delta'],['param0'],['param3'],['prefixPaRaM99'],['4','DEFAULT']],
 'SetShieldHitPoints':[['character=other','3'],['character=self','-1'],['character=missing','2'],['gamma'],['delta'],['param3'],['prefixCHARACTER=other','beta']],
 'TakeDamage':[['prefixCHARACTER=other','prefixDAMAGE=2'],['character=other','hitter=self'],['hitter=other','opponent'],['hitter=other','character=missing','damage=1'],['PREFIXopponentsuffix','damage=gamma'],['character=other','damage=param3'],['damage=alpha'],['garbageSET=2'],['set=2','prefixset=0','hitter=self']]}
addresses={'SetHitPoints':0x44b150,'SetShieldHitPoints':0x44b290,'TakeDamage':0x44fd10}
try:
 for command,forms_list in forms.items():
  for ts,first,actor,parameters,message in itertools.product(forms_list,[0,1],[False,True],[False,True],[False,True]):
   ctx=setup(ts,actor,parameters,message);result=n.call(addresses[command],[0,ctx,SCRIPT,ARGS,len(ts),first],count=1000000);got=[[*n.unpack('<BB',OBJ+0x107e),n.read(OBJ+0xe38,1)[0]],[*n.unpack('<BB',OTHER+0x107e),n.read(OTHER+0xe38,1)[0]],calls.copy(),result]
   vectors.append({'contract':'command_named_or_value_adapters','input':{'command':command,'tokens':ts,'firstCall':first,'actor':actor,'parameters':parameters,'message':message,'parameterValues':params},'native':got})
except Exception as e:report['failures'].append({'error':str(e),'command':command,'tokens':ts,'firstCall':first,'actor':actor,'parameters':parameters,'message':message})
report['totals']={'cases':len(vectors),'failures':len(report['failures'])};report['limits']=['Named resolver is an explicit fixture callback, not reconstructed world lookup.','TakeDamage final hit is recorded; no damage engine side effects in this suite.','Message list contains one authored-style named float record and no free records; full message allocation is not asserted.','Bounded finite parameter values; original numeric code runs without hooks.']
(BASE/'reports/native-combat-command-adapters.json').write_text(json.dumps(report,indent=2)+'\n');(BASE/'reports/native-combat-command-adapter-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n');print(json.dumps(report['totals']));print(report['failures'])

raise SystemExit(1 if report['totals'].get('mismatches',0) or report['totals'].get('failures',0) else 0)
