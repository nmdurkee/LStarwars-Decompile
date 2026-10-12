"""Verify PC numeric parsing and all ten observed locomotion scalar setter handlers.
Runs only bounded original parser/handler code in isolated x86 with synthetic buffers.
"""
import importlib.util,struct,json,random,math
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
n=native.NativeX86();BASE=native.BASE;P=n.DATA;INPUT=P+0x1000;WORD=P+0x2000;GAME=P+0x3000;OUT=P+0x4000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
bits=lambda x:struct.pack('<f',x).hex()
fields={'tiptoe_speed':(0x5876c0,0x14),'walk_speed':(0x5876e0,0x18),'run_speed':(0x587700,0x1c),'backwards_factor':(0x587720,0x20),'air_gravity':(0x587740,0x24),'jump_speed':(0x587760,0x2c),'jump_2_speed':(0x587780,0x38),'acceleration':(0x5877a0,0x44),'jump_move_speed_scale':(0x5871c0,0x84),'hover_time':(0x5891d0,0x48)}
def parse(token):
 i=0;a=0.;d=1.
 if token.startswith('-'):d=-1.;i=1
 def digit():return i<len(token)and '0'<=token[i]<='9'
 while digit():a=f32(f32(a*10)+(ord(token[i])-48));i+=1
 if i<len(token)and token[i]=='.':
  i+=1
  while digit():d=f32(d*10);a=f32(f32(a*10)+(ord(token[i])-48));i+=1
 return f32(a/d)
catalog=json.loads((BASE/'reports/gameplay-catalog/characters.json').read_text());configs=catalog['configs'];by_source={c['source'].lower():c for c in configs};assignments=[]
for config in configs:
 for source in config['loadPlan']['passes']:
  for setting in by_source[source.lower()]['settings']:
   if setting['key']in fields:assignments.append({'characterSource':config['source'],'source':source,'line':setting['line'],'key':setting['key'],'token':setting['args'][0]})
tokens=sorted(set(a['token']for a in assignments));rng=random.Random(0x4f28e0)
edge=['','-','.', '-.','+1',' 1','1e3','-.2','-0','-0.0','1.23suffix','NaN','0x10','1.2.3','16777217','0.99999999999999','99999999999999.9']
random_tokens=[]
for _ in range(5000):
 digits=''.join(str(rng.randrange(10))for _ in range(rng.randrange(1,16)));p=rng.randrange(len(digits)+1)
 random_tokens.append(('-'if rng.randrange(2)else'')+digits[:p]+'.'+digits[p:]+('xyz'if rng.randrange(5)==0 else''))
report={'binarySha256':n.sha256,'method':'Original x86 FUN_4f28e0 decimal converter and complete scalar setter -> NuFParGetFloat -> NuFParGetWord -> decimal converter call chains; synthetic ASCII parser buffers, no OS/game process. Float32 bits must match exactly.','numberFunction':'0x4f28e0','getFloatFunction':'0x4f8100','getWordFunction':'0x4f7fb0','uniqueObservedTokens':len(tokens),'contracts':{'numericParser':{'cases':0,'mismatches':0},'scalarSetters':{'cases':0,'mismatches':0}},'failures':[],'mismatchExamples':[],'observedTokens':[]}
n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.pack('<I',0x954404,GAME)
def compare(kind,want,actual,meta):
 r=report['contracts'][kind];r['cases']+=1
 if bits(want)!=bits(actual):
  r['mismatches']+=1
  if len(report['mismatchExamples'])<20:report['mismatchExamples'].append({'kind':kind,**meta,'expected':want,'actual':actual,'expectedBits':bits(want),'actualBits':bits(actual)})
try:
 for token in tokens+edge+random_tokens:
  n.write(INPUT,token.encode()+b'\0');n.call(0x4f28e0,[INPUT]);n.mu.emu_start(n.STOP,n.STOP+6);actual=n.unpack('<f',OUT)[0];compare('numericParser',parse(token),actual,{'token':token})
  if token in tokens:report['observedTokens'].append({'token':token,'value':actual,'bits':bits(actual)})
 for a in assignments:
  n.write(P,bytes(0x600));n.write(INPUT,a['token'].encode()+b'\0');n.write(WORD,bytes(256));n.pack('<IIII',P+0x50c,INPUT,WORD,256,256)
  address,offset=fields[a['key']];n.call(address,[P]);actual=n.unpack('<f',GAME+offset)[0];want=parse(a['token']);want=abs(want)if a['key']=='hover_time'else want
  compare('scalarSetters',want,actual,a)
except Exception as e:report['failures'].append(str(e))
report['totals']={'cases':sum(v['cases']for v in report['contracts'].values()),'mismatches':sum(v['mismatches']for v in report['contracts'].values()),'failures':len(report['failures'])}
(BASE/'reports/animation-locomotion-parser-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k not in['observedTokens']},indent=2))
if report['totals']['mismatches']or report['failures']:raise SystemExit(1)
