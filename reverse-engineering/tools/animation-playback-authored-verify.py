"""Authored ANI end frames, actual Qui-Gon parser blocks and packet playback."""
import importlib.util,struct,json,hashlib,re,random
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
native=module('native','native-x86.py');model=module('playback','animation-playback-model.py');n=native.NativeX86();BASE=native.BASE
P=n.DATA;LINE=P+0x1000;WORD=P+0x2000;INPUT=P+0x3000;SET=P+0x5000;CHAR=P+0x6000;DEFS=P+0x7000;CURSOR=P+0x9000;OUT=P+0xa000;DELIM=P+0xb000;M=P+0xc000;A=P+0xd000;D=P+0xe000;HEAD=P+0x10000;PACKET=P+0x20000
n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.pack('<I',0x29130e4,SET);n.pack('<I',SET+8,233);n.call(0x6306e0,[n.unpack('<I',0x7fbec8)[0],0x7fbed0])
bits=lambda f:struct.unpack('<I',struct.pack('<f',f))[0]
report={'binarySha256':n.sha256,'method':'Unmodified original PC header helper, complete anim_start handler and callees in first-load mode0x20, then original packet updater/callees. No game launch, substituted callbacks or text normalization.','headerCases':0,'headerMismatches':0,'blocks':[],'packetFrames':0,'packetMismatches':0,'failures':[],'limits':['Quigon animation block loader first-load mode0x20 excludes effect allocation mode0x40; unrelated config initialization not executed.','Animation playback request schedule is a deterministic fixture, not recovered AI/player timing.','Managed C# execution remains pending.']}
try:
 for path in sorted((BASE/'extracted').rglob('*.AN3')):
  raw=path.read_bytes();magic=struct.unpack_from('<I',raw)[0]
  want=sum(struct.unpack_from('<H',raw,o)[0]for o in (10,14))if magic in(0x414e4934,0x414e4935)else struct.unpack_from('<f',raw)[0]
  n.write(HEAD,raw[:32]);n.call(0x5ca470,[HEAD]);n.mu.emu_start(n.STOP,n.STOP+6);actual=n.unpack('<f',OUT)[0]
  report['headerCases']+=1;report['headerMismatches']+=bits(actual)!=bits(want)
 folder=BASE/'extracted/CHARS/QUIGONJINN';source=folder/'QUIGONJINN.TXT';raw=source.read_bytes();report['configSource']=str(source.relative_to(BASE));report['configSha256']=hashlib.sha256(raw).hexdigest()
 n.pack('<I',0x954400,CHAR);n.pack('<I',CHAR+0x10,DEFS);n.pack('<I',0x95440c,0x20);n.pack('<I',0x954420,CURSOR);n.pack('<I',CURSOR,0);n.write(DELIM,b'=\0')
 clips={};headers={};bindings=[]
 for ordinal,match in enumerate(re.finditer(rb'(?im)^anim_start=.*?^anim_end\s*$',raw,re.S)):
  block=match.group();n.write(P,bytes(0x600));n.write(LINE,bytes(4096));n.write(INPUT,block+b'\0');n.write(WORD,bytes(512))
  n.pack('<I',P,INPUT);n.pack('<IIII',P+0x50c,LINE,WORD,4096,512);n.pack('<III',P+0x524,0,0,len(block));n.pack('<I',P+0x574,len(block));n.pack('<I',P+0x57c,DELIM);n.pack('<H',0x95441e,0)
  n.call(0x4fc5b0,[P]);n.call(0x4f7fb0,[P]);n.call(0x585760,[P],count=3000000)
  count=n.unpack('<H',0x95441e)[0]
  if count==0:
   report['blocks'].append({'configLine':raw[:match.start()].count(b'\n')+1,'parserSkipped':True,'blockSha256':hashlib.sha256(block).hexdigest(),'sourceText':block.decode()});continue
  if count!=1:raise ValueError('Unexpected native block count: '+str(count))
  definition=n.read(DEFS,76);action=struct.unpack_from('<h',definition,8)[0];name=n.read(0x954428,40).split(b'\0')[0].decode();ani=next((p for p in folder.glob('*.AN3')if p.stem.casefold()==name.casefold()),None)
  record={'name':name,'action':action,'configLine':raw[:match.start()].count(b'\n')+1,'definitionHex':definition.hex(),'definitionSha256':hashlib.sha256(definition).hexdigest()}
  if ani:
   data=ani.read_bytes();n.write(HEAD,data[:32]);n.call(0x5ca470,[HEAD]);n.mu.emu_start(n.STOP,n.STOP+6)
   c={'endFrame':n.unpack('<f',OUT)[0],'flags':struct.unpack_from('<I',definition,4)[0]}
   c.update(zip(['blendIn','blendOut','fps','movementReference','rateCap'],struct.unpack_from('<5f',definition,16)))
   record.update({'source':str(ani.relative_to(BASE)),'sourceSha256':hashlib.sha256(data).hexdigest(),'clip':c});clips[action]=c;headers[action]=data[:32];bindings.append((action,definition))
  else:record['missingClip']=True
  report['blocks'].append(record)
 n.pack('<II',M+8,D,A);n.write(A,bytes(233*4));n.write(D,bytes(233*4))
 for action,definition in bindings:
  h=HEAD+64*action;d=DEFS+80*action
  n.write(h,headers[action]);n.write(d,definition);n.pack('<I',A+4*action,h);n.pack('<I',D+4*action,d)
 rng=random.Random(0x418ca0);p=model.Packet();model.reset(p,-1);n.pack('<I',0x80fb90,1);actions=sorted(clips)
 for frame in range(7200):
  p.s16(0x38,p.i16(0x36))
  if frame%73==0:p.s16(0x3a,rng.choice(actions))
  if frame%239==0:p.flag(128)
  step=model.f32(30/60);speed=model.f32(rng.choice([-.75,0,.15,.6,1.2]));blendStep=model.f32(1/60);before=bytes(p.b);model.update(p,clips,step,speed,blendStep,1.,1)
  n.write(PACKET,before);n.call(0x62e9b0,[M,PACKET,bits(step),bits(speed),bits(blendStep),bits(1.)]);actual=n.read(PACKET,72)
  report['packetFrames']+=1
  if actual!=p.b:
   report['packetMismatches']+=1
   if report['packetMismatches']<5:report.setdefault('examples',[]).append({'frame':frame,'actual':actual.hex(),'expected':bytes(p.b).hex()})
 report['boundClips']=len(clips)
except Exception as e:report['failures'].append(str(e))
(BASE/'reports/animation-playback-authored-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items()if k!='blocks'},indent=2));print('blocks',len(report['blocks']))
if report['failures']or report['headerMismatches']or report['packetMismatches']:raise SystemExit(1)
