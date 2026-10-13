"""Original ordinary dynamic mesh packets and matrix payload, bounded replay."""
import importlib.util,struct,json,gzip,hashlib,ast
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';s=importlib.util.spec_from_file_location('nx',B/'tools/native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86();BASE=n.DATA;SIZE=4096
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDI
ns={'BASE':BASE,'struct':struct};tree=ast.parse((B/'tools/geometry-dynamic-command-native.py').read_text())
for node in tree.body:
 if isinstance(node,ast.FunctionDef)and node.name in {'u','w','quiet','alpha','model'}:exec(compile(ast.Module(body=[node],type_ignores=[]),'dynamic-support-model','exec'),ns)
u=ns['u'];w=ns['w'];cases=[];errors=[];calls=[];sources=[];counts={'transpose':0,'matrix':0,'ordinary':0,'prefix':0,'authoredMatrices':0,'checkedBytes':0}
def observe(mu,address,size,_):calls.append(address)
for address in [0x5f7610,0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5e0200,0x5e02b0,0x603530,0x603ad0,0x603b10]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=address,end=address)
def transpose(b,dst,src):
 def pair(a,c):
  temp=u(b,src+a*4);w(b,dst+a*4,u(b,src+c*4));w(b,dst+c*4,temp)
 w(b,dst,u(b,src));pair(1,4);pair(2,8);pair(3,12);w(b,dst+20,u(b,src+20));pair(6,9);pair(7,13);w(b,dst+40,u(b,src+40));pair(11,14);w(b,dst+60,u(b,src+60))
def matrix(b,control,src,scale,translation,uv):
 b[scale-BASE:scale-BASE+64]=bytes(64);b[translation-BASE:translation-BASE+64]=bytes(64)
 for off,value in[(0,uv[0]),(20,uv[1]),(40,0x3f800000),(60,0x3f800000)]:w(b,scale+off,value)
 for off,value in[(0,0x3f800000),(20,0x3f800000),(40,0x3f800000),(48,uv[2]),(52,uv[3]),(60,0x3f800000)]:w(b,translation+off,value)
 p=(u(b,control)+3)&~3;w(b,control,p);transpose(b,p,src);w(b,control,u(b,control)+64);return p
def evaluate(kind,before,args,uv):
 b=bytearray(before);control,record,cmd,src,cache,out,scale,translation,alphaWord,metadata=args;trace=[];ret=None
 if kind=='transpose':transpose(b,cmd,src);trace=[0x5f7610]
 elif kind=='matrix':ret=matrix(b,control,src,scale,translation,uv);trace=[0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610]
 else:
  prefix=kind=='prefix';trace=[0x5e02b0 if prefix else 0x5e0200,0x603530];changed,_=ns['model']('reserve',b,[control,record,3 if prefix else 2]);b[:]=changed;resource=u(b,cmd+4)
  def command(opcode,value):
   p=u(b,record+0x24);b[p-BASE]=opcode;b[p-BASE+1]=3;w(b,p+4,value);w(b,record+0x24,p+16);return p
  if prefix:w(b,out,command(b[cmd-BASE-32],u(b,cmd-28)))
  payload=matrix(b,control,src,scale,translation,uv);trace.extend([0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610]);w(b,cache,payload);first=command(0x8c,payload);w(b,out+(4 if prefix else 0),first);second=command(0x82,resource);w(b,out+(8 if prefix else 4),second);w(b,payload+60,ns['alpha'](alphaWord));trace.append(0x603ad0)
  if not prefix:struct.pack_into('<f',b,payload-BASE+56,float(metadata-0x100000000 if metadata>=0x80000000 else metadata));trace.append(0x603b10)
 return bytes(b),ret,trace
def setup(raw,index):
 b=bytearray(SIZE);control=BASE;owner=BASE+0x100;table=BASE+0x200;record=BASE+0x300;cmd=BASE+0x400;src=BASE+0x600;cache=BASE+0x700;out=BASE+0x720;scale=BASE+0x500;translation=BASE+0x540
 for i in range(0x800,SIZE):b[i]=(i*37+index*17)&255
 b[src-BASE:src-BASE+64]=raw;w(b,control,BASE+0x800+(index&15));w(b,record,owner);w(b,owner+0x50,table);w(b,table,0x12345678);w(b,record+0x14,BASE+0x780);w(b,record+0x18,BASE+0x7a0);w(b,cmd+4,0xfedcba98);w(b,cmd-28,0x89abcdef);b[cmd-BASE-32]=[0xb0,0xae,0xaf][index%3];w(b,cache,0xdeadbeef)
 alpha=[0,0x80000000,0xbf800000,0x3e800000,0x3f800000,0x40000000,0x7fc12345][index%7];metadata=[0,0x80000000,0x7fffffff,0x01000001,0xffffffff][index%5];uv=[0x3f000000,0x40000000,0x80000000,0xbf800000]
 return b,[control,record,cmd,src,cache,out,scale,translation,alpha,metadata],uv
def run(kind,b,args,uv,label):
 before=bytes(b);expected,expectedRet,trace=evaluate(kind,b,args,uv);control,record,cmd,src,cache,out,scale,translation,alphaWord,metadata=args;n.write(BASE,b);n.pack('<I',0x9736e0,control);n.pack('<4I',0x80e258,*uv);n.write(0x2857230,b[scale-BASE:scale-BASE+64]);n.write(0x28571f0,b[translation-BASE:translation-BASE+64]);calls.clear()
 if kind=='transpose':ret=n.call(0x5f7610,regs={UC_X86_REG_EAX:src,UC_X86_REG_ECX:cmd})
 elif kind=='matrix':ret=n.call(0x603580,args=[control,src,0x12345678,0x87654321,0xabcdef12])
 else:ret=n.call(0x5e02b0 if kind=='prefix'else 0x5e0200,args=[cmd,src,cache,alphaWord]+([]if kind=='prefix'else[metadata]),regs={UC_X86_REG_EAX:record,UC_X86_REG_EDI:out})
 actual=bytearray(n.read(BASE,SIZE))
 if kind!='transpose':actual[scale-BASE:scale-BASE+64]=n.read(0x2857230,64);actual[translation-BASE:translation-BASE+64]=n.read(0x28571f0,64)
 for field,a,e in [('memory',bytes(actual),expected),('trace',calls,trace)]:
  if a!=e and len(errors)<20:errors.append({'kind':kind,'label':label,'field':field,'offsets':[i for i,(x,y)in enumerate(zip(a,e))if x!=y][:20]})
 if expectedRet is not None and ret!=expectedRet:errors.append({'kind':kind,'label':label,'return':ret,'expected':expectedRet})
 counts[kind]+=1;counts['checkedBytes']+=SIZE;cases.append({'kind':kind,'label':label,'before':before.hex(),'args':args,'uv':uv,'nativeSHA256':hashlib.sha256(actual).hexdigest(),'nativeReturn':ret if expectedRet is not None else None,'nativeCalls':list(calls)})
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']}
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 row=index[sr['source']];metadata=json.loads((B/row['report']).read_text());raw=(B/'extracted'/sr['source']).read_bytes();specials=metadata['specialObjects'];indices=sorted(set(int(i*(len(specials)-1)/7)for i in range(8)))if specials else[]
 for ii in indices:
  spec=specials[ii];matrixBytes=raw[spec['address']+64:spec['address']+128];counts['authoredMatrices']+=1
  for kind in ['matrix','ordinary','prefix']:
   b,args,uv=setup(matrixBytes,si+ii);run(kind,b,args,uv,[sr['source'],ii])
 sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'specialIndices':indices})
 if(si+1)%10==0:print('ordinary sources',si+1,'errors',len(errors),flush=True)
 if errors:break
words=[0,0x80000000,1,0x80000001,0x3f800000,0xbf800000,0x7f800000,0xff800000,0x7fc12345,0xffc12345,0x00800000,0x80800000,0x3f7fffff,0x3f800001,0x007fffff,0x807fffff]
for shift in [-60,-16,-4,0,4,16,60,128]:
 for pattern in range(16):
  raw=struct.pack('<16I',*(words[pattern:]+words[:pattern]));b,args,uv=setup(raw,pattern);args[2]=args[3]+shift;run('transpose',b,args,uv,['alias',shift,pattern])
fp=R/'geometry-ordinary-packets-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-ordinary-packets-native-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'limits':['All four mapped original helpers and all nested dependencies execute unchanged; hooks observe only.','603580 performs transpose only for payload; scratch scale/translation globals are written but not multiplied into output. Three trailing original inputs ignored.','Finite valid memory; payload/control/record regions disjoint except explicit transpose alias tests. Matrix and alpha signaling NaNs excluded; quiet NaNs/infinities/signed zeros retained.','Ordinary and prefix packets preserve opcode/resource words, cache pointer, output pointers, link tail and original alpha/metadata stores. No shader emission or full5f0f00 consumer claim.','No managed executable or GPU launched.']};(R/'geometry-ordinary-packets-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))
