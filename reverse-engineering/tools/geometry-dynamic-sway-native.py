"""Complete normal caller with actual sway coefficients/matrix and visibility."""
import ast,json,gzip,struct,hashlib,base64,math,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/geometry-dynamic-submission-native.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.Assign)and any(isinstance(v,ast.Name)and v.id=='index'for v in node.targets):break
 nodes.append(node)
ns={'__file__':str(path)};exec(compile(ast.Module(body=nodes,type_ignores=[]),str(path),'exec'),ns);n=ns['n'];D=n.DATA;SCRATCH=D+0x6900;x=ns['x87'];TABLE=(B/'references/native-animation-sine-table.f32').read_bytes();n.write(0x29899a0,TABLE)
sway=dict(x=x,struct=struct,math=math,W=x.wide,mul=x.mul,div=x.div,add=x.add,sine=struct.unpack('<32768f',TABLE),f32=ns['f32'],bits=ns['bits'],val=lambda v:struct.unpack('<f',struct.pack('<I',v))[0])
for node in ast.parse((B/'tools/geometry-sway-native.py').read_text()).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['store','angle','sample','coefficients','mutate']:exec(compile(ast.Module(body=[node],type_ignores=[]),'sway-model-helpers','exec'),sway)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EDX
captured=None;calls=0
def capture(mu,address,size,user):
 global captured,calls
 captured=n.read(mu.reg_read(UC_X86_REG_EDX),64);calls+=1
n.mu.hook_add(UC_HOOK_CODE,capture,begin=0x5ec61e,end=0x5ec61e)
def apply(before,source,a,seed,o):
 pair,angles=sway['coefficients'](a,seed,o['swayFrame'],o['swayAmplitude'],o['swayRate'],o['swaySse']);return sway['mutate'](before,SCRATCH-D,source-D,pair)
ns['applySway']=apply;ns['swayScratch']=SCRATCH
source=path.read_text()
for node in ast.parse(source).body:
 if isinstance(node,ast.FunctionDef)and node.name in ['model','run']:
  text=ast.get_source_segment(source,node)
  if node.name=='model':
   text=text.replace("o['matrix']",'matrixPointer').replace('sp=u(b,h+8);mat=',"""sp=u(b,h+8);matrixPointer=o['matrix'];seed,a=struct.unpack_from('<hh',b,sp-BASE+0xc8)
 if a:b[:]=applySway(b,matrixPointer,a,seed,o);matrixPointer=swayScratch
 mat=""")
  else:
   text=text.replace("'before':bytes(before).hex(),","'beforeZ':base64.b64encode(gzip.compress(bytes(before),mtime=0)).decode(),").replace('actual=bytearray(n.read(BASE,SIZE))','actual=bytearray(n.read(BASE,SIZE));actual[swayScratch-BASE:swayScratch-BASE+64]=readSwayCapture(before)')
  exec(compile(text,'sway-normal-'+node.name,'exec'),ns)
ns['base64']=base64;ns['readSwayCapture']=lambda before:captured if captured is not None else before[SCRATCH-D:SCRATCH-D+64]
priorPath=R/'geometry-sway-fixtures.json.gz';prior=json.loads(gzip.decompress(priorPath.read_bytes()));authored=[c for c in prior['cases']if c['sourceOrigin']and'source'in c['sourceOrigin']];rawCache={};counts=collections.Counter();sourceProofs=[]
def execute(c,index,visible,zero=False):
 global captured
 proof=c['sourceOrigin'];p=proof['source']
 if p not in rawCache:rawCache[p]=(B/'extracted'/p).read_bytes();assert hashlib.sha256(rawCache[p]).hexdigest()==proof['sha256']
 raw=rawCache[p];at=proof['offset'];minimum=list(struct.unpack_from('<3f',raw,at+0x80));maximum=list(struct.unpack_from('<3f',raw,at+0x90));matrix=list(struct.unpack_from('<16f',raw,at+64));tp=at+0xbc+struct.unpack_from('<i',raw,at+0xbc)[0];thresholds=[]
 for i in range(64):
  value=struct.unpack_from('<f',raw,tp+i*4)[0];thresholds.append(value)
  if value==0:break
 before,o=ns['setup'](minimum,maximum,matrix,thresholds,index,visible);struct.pack_into('<hh',before,ns['special']-D+0xc8,c['seed'],0 if zero else c['a']);o.update(swayFrame=c['time'],swayAmplitude=sway['val'](c['amplitude']),swayRate=sway['val'](c['rate']),swaySse=c['sse']);n.pack('<I',0x97390c,o['swayFrame']);n.pack('<f',0x80b6d8,o['swayAmplitude']);n.pack('<f',0x80b6dc,o['swayRate']);n.pack('<I',0x29a9c48,int(o['swaySse']));captured=None
 ns['run'](before,o,['sway',proof['source'],proof['special'],int(c['sse']),visible,zero]);ns['cases'][-1].update(sourceOrigin=proof,nativeSwayMatrix=None if captured is None else captured.hex());counts['cases']+=1;counts['zeroSway']+=zero
 if ns['errors']:raise AssertionError(ns['errors'][:3])
for i,c in enumerate(authored):
 for visible in [-1,1]:execute(c,i,visible)
 if i%100==0:print('sway caller',i,'errors',len(ns['errors']),flush=True)
for i,c in enumerate(authored[:64]):execute(c,2000+i,1,True)
fp=R/'geometry-dynamic-sway-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(cases=ns['cases'],sineTable=prior['sineTable'],swayScratch=SCRATCH),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-dynamic-sway-native-v1',passed=not ns['errors'],binarySHA256=n.sha256,counts=dict(counts),normalCounts=ns['counts'],swayCalls=calls,authoredSpecials=len(authored)//2,sources=len(rawCache),errors=ns['errors'],fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Full original5f0f00 with actual5ec590/5ec3d0/RNG/sine/CRT helpers before actual scalar bounds, transformed-center LOD, material/shader and ordinary/prefix packets. Observation hooks only.','All245 nonzero authored sway specials from4carriers in both conversion modes and forced/scalar visibility;64 zero-sway regressions. Raw authored coefficient shorts, min/max, matrix and LOD offsets are preserved with source hashes. Runtime material/arena records remain controlled relocated fixtures.','Original temporary stack matrix captured at5ec590 return and mirrored into the explicit64-byte portable scratch adapter; native source and all later consumer instructions remain unchanged. Entire64KiB persistent image compared except established32-byte cache/output adapter.','Normal zero-shadow/fade, same-layout overrides, null skin/morph. Billboard, skin and fade cross-products not included in this sway caller batch.','Finite scalar math, valid disjoint scratch, bounded resources and trig-product signed64 domain. No live runtime loader, GPU or managed execution claim.'])
(R/'geometry-dynamic-sway-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not ns['errors']
