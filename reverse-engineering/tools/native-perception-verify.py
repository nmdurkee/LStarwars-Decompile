"""Original PC perception/terrain command handlers and concrete defaults."""
import importlib.util,struct,json,itertools,random,hashlib
from pathlib import Path
p=Path(__file__).with_name('native-x86.py');s=importlib.util.spec_from_file_location('perception_native',p);native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
n=native.NativeX86();B=native.BASE;D=n.DATA;SYS=D;CRE=D+0x1000;REF=D+0x2000;CALLER=D+0x4000;SCRIPT=D+0x4300;ARGS=D+0x5000;TEXT=D+0x6000;TEMPLATES=D+0x10000;CAT=D+0x20000;ROWS=D+0x21000;DEFS=D+0x22000;CHARINFO=D+0x24000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
flags=[('IgnoreWallSplines',0x5160b0,'controller',0x80,False),('CheckWallSplines',0x516120,'controller',0x100,False),('NoTerrain',0x5161a0,'object',0x20,False),('NoLosCheck',0x516220,'object',0x400,False),('FlatTerrain',0x5162a0,'object',0x10,False),('ShadowTerrain',0x516320,'object',8,False),('DontUseShadowTerrain',0x5163a0,'object',0x40,False),('BuiltinDontPush',0x516420,'object',2,False),('CanSeeBehind',0x5164a0,'object',0x800,False),('RequiresLOS',0x516520,'controller',0x20000,False),('SetFullPathSearch',0x516590,'object',0x80000,True),('NoShadows',0x516bf0,'object1f8',0x2000,False)]
values=[('SetViewDistance',0x516610,0,0x230,0x94,0x9238c8,0x43c1a0),('SetHearDistance',0x516850,1,0x234,0x98,0x9238cc,0x43c1c0),('SetMaxViewHeight',0x516790,2,0x238,0x9c,0x9238d0,0x43c1e0),('SetMinViewHeight',0x5166d0,3,0x23c,0xa0,0x9238d4,0x43c200),('SetMoveRadius',0x516910,4,0x120,0,0,0)]
entries={x[0]:x for x in flags+values};events=[];rows=[];errors=[];write_errors=[]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def fl(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def f32(v):
 try:return fl(bits(v))
 except OverflowError:return float('-inf')if v<0 else float('inf')
def cstr(p):return n.read(p,256).split(b'\0')[0].decode('latin1')
def fold(t):return bytes(c-32 if 97<=c<=122 or c>=224 else c for c in t.encode('latin1').split(b'\0')[0])
def number(t):
 t=t.split('\0')[0]
 if 'param'in t.lower():return 2.75
 if t.lower()in ['alpha','beta','gamma','delta']:return [2.75,1.5,3.,4.][['alpha','beta','gamma','delta'].index(t.lower())]
 i=0;value=0.;den=1.
 if t.startswith('-'):i=1;den=-1.
 while i<len(t)and'0'<=t[i]<='9':value=f32(f32(value*10)+int(t[i]));i+=1
 if i<len(t)and t[i]=='.':
  i+=1
  while i<len(t)and'0'<=t[i]<='9':den=f32(den*10);value=f32(f32(value*10)+int(t[i]));i+=1
 return f32(value/den)
def snapshot():return dict(controllerFlags=n.unpack('<I',CRE+0x1e8)[0],objectFlags=n.unpack('<I',REF+0x1fc)[0],objectStateFlags=n.unpack('<I',REF+0x1f8)[0],values=list(n.unpack('<4I',REF+0x230)),moveRadius=n.unpack('<I',CRE+0x120)[0])
def observer(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x514920:events.append(['number',cstr(n.unpack('<I',sp+12)[0]),snapshot()])
 else:events.append(['default',(address-0x43c1a0)//0x20,n.unpack('<i',sp+4)[0]])
for a in [0x514920,0x43c1a0,0x43c1c0,0x43c1e0,0x43c200]:n.mu.hook_add(UC_HOOK_CODE,observer,begin=a,end=a)
def setup(v):
 n.write(D,bytes(0x25000));events.clear();n.write(CRE,bytes([0xa5])*0x300);n.write(REF,bytes([0x5a])*0x300)
 n.pack('<I',SYS+0x18,TEMPLATES);n.pack('<I',CRE+0xd0,REF if v['reference']else 0);n.pack('<B',CRE+0x138,v['template']);n.pack('<I',CRE+0x1e8,v['controllerFlags']);n.pack('<I',CRE+0x120,v['moveRadius']);n.pack('<II',REF+0x1f8,v['objectStateFlags'],v['objectFlags']);n.pack('<4I',REF+0x230,*v['values']);n.pack('<I',REF+0xac,v['radius']);n.pack('<I',REF+0x50,CHARINFO);n.pack('<h',CHARINFO,v['characterType'])
 n.pack('<I',0x29130e4,CAT);n.pack('<I',CAT+0x20,ROWS)
 for i in range(8):n.pack('<I',ROWS+i*0x4c+0x24,DEFS+i*0x100);n.pack('<4I',DEFS+i*0x100+0x64,*v['characterDefaults'])
 for i in range(255):n.pack('<4I',TEMPLATES+i*0xa4+0x94,*v['templateDefaults'])
 for name,a,k,off,toff,g,callback in values[:4]:n.pack('<I',g,callback if v['callbacks'][k]else 0)
 n.pack('<I',0x9238c0,0);n.pack('<I',CALLER+4,SCRIPT);n.pack('<4f',CALLER+0x14,2.75,1.5,3.,4.)
 for i,name in enumerate(['alpha','beta','gamma','delta']):n.pack('<I',SCRIPT+0x18+i*8,SCRIPT+0x80+i*32);n.write(SCRIPT+0x80+i*32,name.encode()+b'\0')
 for i,t in enumerate(v['tokens']):n.pack('<I',ARGS+4*i,TEXT+256*i);n.write(TEXT+256*i,t.encode('latin1')+b'\0')
def defaults(**kw):
 v=dict(controller=True,reference=True,first=True,template=255,characterType=1,callbacks=[True]*4,controllerFlags=0xa5a58080,objectFlags=0x12340000,objectStateFlags=0x8000400,values=[bits(x)for x in [11.,22.,33.,44.]],moveRadius=bits(55.),radius=bits(1.25),characterDefaults=[bits(x)for x in [20.,30.,4.,-3.]],templateDefaults=[bits(x)for x in [100.,200.,40.,-30.]])
 v.update(kw);return v
def model(name,v):
 state={k:list(v[k])if isinstance(v[k],list)else v[k]for k in ['controllerFlags','objectFlags','objectStateFlags','values','moveRadius']};e=[]
 if not v['controller']or not v['first']:return state,e
 if name in [x[0]for x in flags]:
  _,a,target,mask,inverse=entries[name]
  if target!='controller'and not v['reference']:return state,e
  enabled=not any(fold(t)==b'FALSE'for t in v['tokens']);enabled=not enabled if inverse else enabled
  field='controllerFlags'if target=='controller'else'objectStateFlags'if target=='object1f8'else'objectFlags';state[field]=(state[field]&~mask)|(mask if enabled else 0)
  if name=='CheckWallSplines'and enabled:state[field]|=0x80
 else:
  if not v['reference']:return state,e
  _,a,k,off,toff,g,callback=entries[name]
  if k==4:state['moveRadius']=bits(f32(fl(v['radius'])*2))
  else:
   if v['template']!=255:val=v['templateDefaults'][k]
   elif v['callbacks'][k]:e.append(['default',k,v['characterType']]);val=bits(0.)if v['characterType']==-1 else v['characterDefaults'][k]
   else:val=bits(1.)
   state['values'][k]=val
  if v['tokens']and fold(v['tokens'][0])!=b'DEFAULT':
   e.append(['number',v['tokens'][0].split('\0')[0],json.loads(json.dumps(state))]);value=bits(number(v['tokens'][0]))
   if k==4:state['moveRadius']=value
   else:state['values'][k]=value
 return state,e
def run(name,tokens,group='synthetic',source=None,**options):
 v=defaults(tokens=tokens,**options);setup(v);before=[bytearray(n.read(p,0x300))for p in [CRE,REF]];expected,ee=model(name,v)
 result=n.call(entries[name][1],[SYS,CALLER,CRE if v['controller']else 0,ARGS,len(tokens),int(v['first'])]);actual=snapshot();row={'name':name,'group':group,'input':v,'expected':dict(state=actual,events=list(events),result=result),'source':source};rows.append(row)
 if actual!=expected or events!=ee or result!=1:errors.append(dict(name=name,input=v,expected=dict(state=expected,events=ee,result=1),native=row['expected']))
 # Full512+/768-byte records must differ only by the known flag/value writes.
 struct.pack_into('<I',before[0],0x1e8,expected['controllerFlags']);struct.pack_into('<I',before[0],0x120,expected['moveRadius']);struct.pack_into('<II',before[1],0x1f8,expected['objectStateFlags'],expected['objectFlags']);struct.pack_into('<4I',before[1],0x230,*expected['values'])
 if any(n.read(p,0x300)!=bytes(w)for p,w in zip([CRE,REF],before)):write_errors.append({'name':name,'input':v})
for item,tokens,gate,initial in itertools.product(flags,[[],['false'],['FALSE','true'],['true','fAlSe'],['false-ish'],['xfalse'],['false\0tail'],['','TRUE']],range(4),[0,0xffffffff,0xaaaaaaaa,0x55555555]):
 run(item[0],tokens,controller=gate!=0,reference=gate!=1,first=gate!=2,controllerFlags=initial,objectFlags=initial,objectStateFlags=initial)
for item,tokens,template,ctype,callbacks,gate in itertools.product(values,[[],['default'],['DeFaUlT','99'],['-0'],['0.1'],['123.125'],['param3'],['alpha'],['-2.5','99']],[0,127,254,255],[-1,0,7],[True,False],range(4)):
 run(item[0],tokens,template=template,characterType=ctype,callbacks=[callbacks]*4,controller=gate!=0,reference=gate!=1,first=gate!=2)
# Exact float32 bit storage, including signed zero and radius overflow.
for raw,item in itertools.product([0,0x80000000,1,0x80000001,0x7f7fffff,0xff7fffff,0x3f800001,0xbf800001],values):run(item[0],['default'],group='float-boundary',characterDefaults=[raw]*4,radius=raw)
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());authored={}
for r in ledger['rows']:
 if r['name']not in entries or int(r['function'],16)!=entries[r['name']][1]:continue
 authored[r['name']]=r['sourceUses']
 for use in r['uses']:
  for variant in range(3):run(r['name'],use['args'],group='authored',source={k:use[k]for k in ['source','line']},template=[0,255,255][variant],callbacks=[variant!=2]*4)
assembly=[]
for a,z in [(x[1],0xc0 if x in values else 0x80)for x in flags+values]+[(0x43c1a0,0x20),(0x43c1c0,0x20),(0x43c1e0,0x20),(0x43c200,0x20)]:assembly.append({'address':hex(a),'instructions':[{'address':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(a,z),a)]})
report={'binarySha256':n.sha256,'cases':len(rows),'stateEventResultMismatches':len(errors),'wholeRecordWriteChecks':len(rows)*2,'wholeRecordWriteMismatches':len(write_errors),'examples':errors[:10],'writeExamples':write_errors[:3],'authoredUses':authored,'uniqueNativeEntries':len(flags)+len(values)+4,'adapters':[],'boundaries':['Valid projected controller/reference/template/character records. Character type -1 or valid nonnegative index only.','Whole first-call handler branches and original defaults execute. Full game record allocation and perception/collision consumers are not recovered here.','Numeric fixtures use original resolver on decimal literals, one parameter or parameter-name tokens; no full expression-language C# recovery is claimed.','BuiltinDontPush0x516420 is overridden by0x4497b0 for cataloged game scripts; those177 authored uses are deliberately not credited.','Full-record write checks supplement per-case observations; they are not additional recovered behaviors.'],'vectors':'reports/native-perception-vectors.json'}
# Verified callback entries were previously labels inside the decompiler corpus.
# Preserve disassembly evidence separately; do not label it Ghidra pseudocode.
verified=[];(B/'native-disassembly').mkdir(exist_ok=True)
for a,name in [(0x43c1a0,'CharacterDefaultViewDistance'),(0x43c1c0,'CharacterDefaultHearDistance'),(0x43c1e0,'CharacterDefaultMaxViewHeight'),(0x43c200,'CharacterDefaultMinViewHeight')]:
 rel='native-disassembly/'+hex(a)[2:]+'.asm';raw=n.read(a,0x20);lines=['; Original PC disassembly, not original source or decompiler pseudocode.','; Registered by0x43c830 and executed through native perception commands.','; Binary SHA256 '+n.sha256,'; Range '+hex(a)+'..'+hex(a+0x20)+' (exclusive); bytes SHA256 '+hashlib.sha256(raw).hexdigest()]
 lines += [hex(i.address)+'  '+i.mnemonic+' '+i.op_str for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(raw,a)]
 (B/rel).write_text('\n'.join(lines)+'\n');verified.append(dict(address=hex(a),name=name,file=rel,status='ok',evidence='reports/native-perception-tests.json;reports/native-perception-assembly.json;decompiled/corpus-expanded/FUN_43c830.c'))
prior_verified_path=B/'reports/native-verified-entry-index.json'
if prior_verified_path.exists():
 prior_verified=json.loads(prior_verified_path.read_text());assert prior_verified['binarySha256']==n.sha256
 verified += [item for item in prior_verified['items']if item['address']not in {row['address']for row in verified}]
verified.sort(key=lambda row:int(row['address'],16))
(B/'reports/native-verified-entry-index.json').write_text(json.dumps(dict(binarySha256=n.sha256,expected=len(verified),processed=len(verified),failed=0,scope='Independently verified callback boundaries beyond the retained Ghidra union; body evidence is original disassembly.',items=verified),indent=2)+'\n')
(B/'reports/native-perception-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-perception-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'cases':rows},indent=2)+'\n');(B/'reports/native-perception-assembly.json').write_text(json.dumps({'binarySha256':n.sha256,'procedures':assembly},indent=2)+'\n');print(json.dumps(report,indent=2));assert not errors and not write_errors
