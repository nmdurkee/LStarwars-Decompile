"""Complete original607820 plus existing signed-byte payload/append helpers."""
import ast,json,gzip,struct,hashlib,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';path=B/'tools/geometry-shader-emission-native.py';nodes=[]
for node in ast.parse(path.read_text()).body:
 if isinstance(node,ast.For):break
 nodes.append(node)
# The early observation-hook for loop must be retained; select definitions and
# initialization explicitly through setup(), without the large original batch.
tree=ast.parse(path.read_text());stop=next(i for i,v in enumerate(tree.body)if isinstance(v,ast.For)and isinstance(v.target,ast.Tuple));ns={'__file__':str(path)};exec(compile(ast.Module(body=tree.body[:stop],type_ignores=[]),str(path),'exec'),ns)
n=ns['n'];BASE=ns['BASE'];u=ns['u'];w=ns['w'];hh=ns['hh'];wh=ns['wh'];cases=[];errors=[];counts={'cases':0,'payloads':0,'appends':0,'checkedBytes':0}
from unicorn import UC_HOOK_CODE
n.mu.hook_add(UC_HOOK_CODE,ns['observe'],begin=0x607820,end=0x607820)
def model(before,control,record,shader,descriptor):
 b=bytearray(before);trace=[0x607820]
 if not shader or u(b,u(b,record+8)+0x20)==u(b,shader+0x20):return b,trace
 if hh(b,u(b,record+8)+0x30)!=hh(b,shader+0x30):
  trace.append(0x5fcfd0);p=ns['payload'](b,0x5fcfd0,shader,control,descriptor)
  if p:trace.append(0x6034b0);ns['append'](b,control,record,0xa9,p)
  wh(b,u(b,record+8)+0x30,hh(b,shader+0x30))
 w(b,u(b,record+8)+0x20,u(b,shader+0x20));return b,trace
for i,(count,offset,sameId,sameKey,nullShader)in enumerate(itertools.product([None,0,1,3,4,5,127,128,254,255],range(16),[False,True],[False,True],[False,True])):
 control,shader,record,ctx,descriptor,cached=ns['setup'](i,count,offset);before=bytearray(ns['memory']);ident=[0,1,0x7fffffff,0x80000000,0xffffffff][i%5];w(before,shader+0x20,ident);w(before,ctx+0x20,ident if sameId else ident^0xffffffff);key=[0,1,0x7fff,0x8000,0xffff][i%5];wh(before,shader+0x30,key);wh(before,ctx+0x30,key if sameKey else key^1);actualShader=0 if nullShader else shader;want,trace=model(before,control,record,actualShader,descriptor)
 n.write(BASE,before);n.pack('<I',0x9736e0,control);n.pack('<I',0x9738a4,descriptor);ns['calls'].clear();n.call(0x607820,[record,actualShader]);actual=n.read(BASE,len(before))
 if actual!=want or ns['calls']!=trace:
  errors.append(dict(case=i,offsets=[j for j,(a,b)in enumerate(zip(actual,want))if a!=b][:20],nativeCalls=ns['calls'].copy(),expectedCalls=trace));raise AssertionError(errors[-1])
 counts['cases']+=1;counts['payloads']+=trace.count(0x5fcfd0);counts['appends']+=trace.count(0x6034b0);counts['checkedBytes']+=len(before);cases.append(dict(before=bytes(before).hex(),control=control,record=record,shader=actualShader,descriptor=descriptor,nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeCalls=trace))
fp=R/'geometry-shadow-context-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=BASE,cases=cases),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-context-native-v1',passed=not errors,binarySHA256=n.sha256,counts=counts,errors=errors,fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),limits=['Complete original607820/5fcfd0/6034b0 and byte-to-float conversion/copies run unchanged; observation hooks only.','Synthetic valid disjoint images, all16 allocator alignments, null shader/descriptor, matching/different32-bit IDs and16-bit keys, signed-byte arrays including zero/255 count.','Only context+30 key and+20 ID update; other shader groups stay untouched. A changed key with null descriptor still synchronizes the key.','CPU payload/list changes only. No full shadow scheduling, GPU backend or managed execution claim.']);(R/'geometry-shadow-context-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors
