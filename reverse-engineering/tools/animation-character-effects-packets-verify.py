"""Original mixed character packets with sway, distance fade and shadows."""
from pathlib import Path
import ast,json,gzip,struct,hashlib,base64,collections,os,math
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def sha(b):return hashlib.sha256(b).hexdigest()
path=B/'tools/animation-character-mixed-packets-verify.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='limit'for v in node.targets):break
 nodes.append(node)
mix={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),mix)
ss=mix['ss'];c=mix['c'];ns=mix['ns'];n=mix['n'];mp=mix['mp'];f=mix['f'];D=n.DATA;SWAY=D+0x1e000;FADES=D+0x1e100;tasks=mix['tasks'];x=ns['x87'];TABLE=(B/'references/native-animation-sine-table.f32').read_bytes();n.write(0x29899a0,TABLE)
sway=dict(x=x,struct=struct,math=math,W=x.wide,mul=x.mul,div=x.div,add=x.add,sine=struct.unpack('<32768f',TABLE),f32=ns['f32'],bits=ns['bits'],val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0])
for node in ast.parse((B/'tools/geometry-sway-native.py').read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['store','angle','sample','coefficients','mutate']:exec(compile(ast.Module(body=[node],type_ignores=[]),'effects-sway-math','exec'),sway)
fadeModel=dict(math=math,struct=struct,f32=ns['f32'],bits=ns['bits'],expectedFade=[])
for node in ast.parse((B/'tools/geometry-dynamic-fade-native.py').read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name=='fade':exec(compile(ast.Module(body=[node],type_ignores=[]),'effects-fade-math','exec'),fadeModel)
expectedSway=[];capturedSway=[];expectedAlpha=[];nativeAlpha=[];nativeFade=[]
def applySway(b,source,a,seed,o):
 pair,angles=sway['coefficients'](a,seed,o['swayFrame'],o['swayAmplitude'],o['swayRate'],o['swaySse']);out=sway['mutate'](b,SWAY-D,source-D,pair);expectedSway.append(bytes(out[SWAY-D:SWAY-D+64]));return out
sh=ss['sh'];sh.update(applySway=applySway,swayScratch=SWAY,fade=fadeModel['fade'],bits=ns['bits'],expectedAlpha=expectedAlpha)
source=(B/'tools/geometry-dynamic-shadow-native.py').read_text();node=next(v for v in ast.parse(source).body if isinstance(v,ast.FunctionDef)and v.name=='model');text=ast.get_source_segment(source,node).replace("o['matrix']",'matrixPointer')
text=text.replace('sp=u(b,h+8);mat=',"sp=u(b,h+8);matrixPointer=o['matrix'];seed,a=struct.unpack_from('<hh',b,sp-D+0xc8)\n if a:b[:]=applySway(b,matrixPointer,a,seed,o);matrixPointer=swayScratch\n mat=")
text=text.replace('modelAddress=u(b,sp+0xb0)+lod*12;w(b,ns[\'cache\'],0)',"modelAddress=u(b,sp+0xb0)+lod*12;alpha=1.\n if u(b,owner+12)and instanceFlags&64:\n  alpha=fade(distance,*floats(b,u(b,owner+12)+instance*8,2))\n  if alpha==0:return b,0,flag,draws\n w(b,ns['cache'],0)")
text=text.replace('0x3f800000,metadata];b[:],unused,trace=', 'bits(alpha),metadata];expectedAlpha.append(bits(alpha));b[:],unused,trace=')
text=text.replace('0x5e02b0 if prefix else 0x5e0200',"0x5e0490 if b[cmd-D]==0x8f else 0x5e0390 if o['skin'] else 0x5e02b0 if prefix else 0x5e0200")
sh['struct']=struct;exec(compile(text,'effects-shadow-model','exec'),sh)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EDX,UC_X86_REG_ESP
def observe(mu,address,size,user):
 if address==0x5ec61e:capturedSway.append(n.read(mu.reg_read(UC_X86_REG_EDX),64))
 else:
  sp=mu.reg_read(UC_X86_REG_ESP)
  if address==0x5df7b0:nativeFade.append(list(n.unpack('<3I',sp+4)))
  else:nativeAlpha.append(n.unpack('<I',sp+28)[0])
for a in [0x5ec61e,0x5df7b0,0x5e0530]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
oldOriginal=c['original']
def original(before,o,r,state):
 got,result=oldOriginal(before,o,r,state)
 if capturedSway:ss['put'](got,SWAY,capturedSway[-1])
 return got,result
c['original']=original
variant=0
def effects(b,o,index):
 a=[0,16384,0,-8192,32767,-32768][variant];seed=[0,21,33,-12345,30000,-32768][variant];struct.pack_into('<hh',b,ns['special']-D+0xc8,seed,a)
 o.update(swayFrame=[0,60,3600,1000000,0xffffffff,0x80000000][variant],swayAmplitude=1.,swayRate=1.,swaySse=bool((index//6+index)&1),effectVariant=variant)
 n.pack('<I',0x97390c,o['swayFrame']);n.pack('<f',0x80b6d8,o['swayAmplitude']);n.pack('<f',0x80b6dc,o['swayRate']);n.pack('<I',0x29a9c48,int(o['swaySse']))
 active=variant>=2;ns['w'](b,ns['owner']+12,FADES if active else 0);b[ns['flags']-D+3]|=64 if active else 0;pair=[(0.,1.),(0.,1.),(0.,.001),(0.,1000.),(1000.,0.),(4.,4.)][variant];ns['storefloats'](b,FADES+24,pair)
 if variant==5:
  ns['storefloats'](b,ns['special']+0x80,[0.,0.,0.]);ns['storefloats'](b,ns['special']+0x90,[0.,0.,0.]);world=ns['floats'](b,c['WORLD'],16);o['camera']=[ns['f32'](world[12]+4),ns['f32'](world[13]+2**-10),ns['f32'](world[14]+2**-10)]
ss['applyEffects']=effects;text=mix['text'].replace('cache=CACHE','applyEffects(b,o,index)\n cache=CACHE');exec(compile(text,'effects-character-execute','exec'),ss);ss.update(cases=[],counts=collections.Counter(),rigs=set(),errors=[])
limit=int(os.environ.get('CHARACTER_EFFECTS_LIMIT','0'));extra=collections.Counter()
for ti,task in enumerate(tasks):
 for variant in range(6):
  mode=[0,1,0,5,6,0][variant];expectedSway.clear();capturedSway.clear();expectedAlpha.clear();nativeAlpha.clear();nativeFade.clear();fadeModel['expectedFade'].clear();ss['execute'](ti,len(ss['cases']),mode)
  assert expectedSway==capturedSway,('sway outputs',ti,variant)
  assert expectedAlpha==nativeAlpha,('alpha words',ti,variant)
  assert fadeModel['expectedFade']==nativeFade,('fade inputs',ti,variant)
  ss['cases'][-1]['native'].update(swayMatrices=[v.hex()for v in capturedSway],alphaWords=nativeAlpha.copy(),fadeInputs=nativeFade.copy());extra['swayCalls']+=len(capturedSway);extra['fadeCalls']+=len(nativeFade);extra['nonunitAlpha']+=sum(v!=0x3f800000 for v in nativeAlpha);extra['nanAlpha']+=sum((v&0x7fffffff)>0x7f800000 for v in nativeAlpha)
 if(ti+1)%10==0:print('effect lists',ti+1,'checks',len(ss['cases']),flush=True)
 if limit and ti+1>=limit:break
counts=dict(ss['counts']);counts.update(extra);counts['billboardPackets']=sum(d[2]==0x5e0490 for c in ss['cases']for d in c['native']['draws']);payload=[dict(r,joints=[[f.bits(v)for v in a]for a in r['joints']],inverse=[[f.bits(v)for v in a]for a in r['inverse']],minimum=[f.bits(v)for v in r['minimum']],maximum=[f.bits(v)for v in r['maximum']])for r in c['rigs']]
fp=R/'animation-character-effects-packets-native-fixtures.json.gz';doc=dict(binarySha256=n.sha256,rigs=payload,meshFixture=dict(path=str(mp['fixturePath'].relative_to(B)),sha256=sha(mp['fixturePath'].read_bytes())),addresses={k:ns[k]for k in ['control','shader','scale','translation','cache','output','matrix','combined','farLanes']},maskMirror=ss['MASKS'],swayScratch=SWAY,sineTable=dict(path='references/native-animation-sine-table.f32',sha256=sha(TABLE)),cases=ss['cases']);fp.write_bytes(gzip.compress(json.dumps(doc,separators=(',',':')).encode(),mtime=0))
deps=['tools/animation-character-mixed-packets-verify.py','tools/geometry-sway-native.py','tools/geometry-dynamic-fade-native.py','tools/geometry-dynamic-shadow-native.py']
report=dict(binarySha256=n.sha256,d3dx=c['dll'],comparisons=len(ss['cases']),counts=counts,authoredRigs=len(ss['rigs']),authoredMeshes=len(set(c['mesh']for c in ss['cases'])),mismatches=0,fixture=dict(path=fp.relative_to(B).as_posix(),bytes=fp.stat().st_size,sha256=sha(fp.read_bytes())),dependencies=[dict(path=p,sha256=sha((B/p).read_bytes()))for p in deps],method='Original full character/secondary/shadow/mixed packet chain plus actual5ec590/5ec3d0 sway and5df7b0 fade/sqrt. Every persistent1MiB byte including last captured native stack sway matrix, layer hashes, masks/state, ordered packets/records, all sway matrices, fade input bits and forwarded alpha bits compared. Only successful COM buffer locking supplied.',limits=['Controlled source-matched mesh/billboard/layer bindings and explicit finite sway/fade/camera scenarios; exact shipped loader and runtime parameter producer remain separate.','Sway coefficients fit signed64 conversion bounds, both original conversion modes. Finite fade inputs can produce original NaN alpha at equal endpoints.','Active legacy character shadow queue, GPU execution and managed executable launch remain separate.'])
(R/'animation-character-effects-packets-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
