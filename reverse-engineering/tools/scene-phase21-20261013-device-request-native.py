"""Original mode request wrapper plus real selector, with no CPU or host hooks."""
import importlib.util,ast,struct,json,gzip,random
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase21-20261013-device-request'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_ESP
u=lambda b,o:struct.unpack_from('<I',b,o)[0]
def w(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def i32(v):return ((v+0x80000000)&0xffffffff)-0x80000000
ns={'i32':i32,'u':u,'w':w}
tree=ast.parse((P/'scene-phase14-20261013-mode-selection-native.py').read_text());selected=[z for z in tree.body if isinstance(z,ast.FunctionDef)and z.name in ['distance','select']];exec(compile(ast.Module(body=selected,type_ignores=[]),'sealed-mode-model','exec'),ns)
B=0x29765c8;MODES=n.DATA+0x8000;rng=random.Random(0x6e2ce021);checks=0;errors=[];fixtures=[]
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<12:errors.append({'case':case,'label':label,'native':a,'model':e})
for case in range(8192):
 b=bytearray(rng.randbytes(0x800));m=bytearray(rng.randbytes(0x200));count=case%33;w(b,0x618,count);w(b,0x61c,MODES);b[0x65c]=[0,1,255][case%3];args=[rng.getrandbits(32)for _ in range(3)];args[2]=0 if case%3==0 else args[2]
 if case%7==0:
  for j in range(32):struct.pack_into('<4I',m,j*16,*[640,480,60,j])
 before={'backendHex':b.hex(),'modesHex':m.hex()};expectedB=bytearray(b);expectedM=bytearray(m);expectedM,selected=ns['select'](expectedB,expectedM,[i32(v)for v in args]);result=selected if selected<u(expectedB,0x618)else u(expectedB,0x620);w(expectedB,0x660,result);n.write(B,b);n.write(MODES,m);actual=n.call(0x6e2ce0,args,regs={UC_X86_REG_ECX:B});after={'backendHex':n.read(B,0x800).hex(),'modesHex':n.read(MODES,0x200).hex()};ck(actual,result,'requested index return');ck(after['backendHex'],expectedB.hex(),'backend publication');ck(after['modesHex'],expectedM.hex(),'mutable mode records');ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe010,'thiscall ret12');fixtures.append({'before':before,'arguments':args,'after':after,'return':actual})
report={'status':'passed'if not errors else'failed','binarySHA256':n.sha256,'calls':len(fixtures),'checks':checks,'failures':errors,'scope':'Original6e2ce0 and6e1b70 CPU run unchanged, no adapters/hooks. Stable disjoint32-record image; count0..32; all raw requested integer words; mutable record0 retained when count0; rejected chosen index falls back to current620 and publishes660.'}
(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2))
with gzip.open(R/(PREFIX+'-native-fixtures.json.gz'),'wt')as f:json.dump({'report':report,'fixtures':fixtures},f,separators=(',',':'))
print(json.dumps({k:v for k,v in report.items()if k!='failures'},indent=2));print('failures',[(z['case'],z['label'])for z in errors]);raise SystemExit(bool(errors))
