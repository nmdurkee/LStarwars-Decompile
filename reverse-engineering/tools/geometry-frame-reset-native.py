"""Native frame-reset tests: authored tables, padding, aliasing and caller order."""
import importlib.util,json,hashlib,gzip,struct,itertools
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';P=B/'tools'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESI
BASE=0x11000000;SIZE=0x2000000;n.mu.mem_map(BASE,SIZE);cursor=BASE
errors=[];cases=[];sources=[];counts={'authoredReset':0,'syntheticReset':0,'contextReset':0,'shaderReset':0,'globalReset':0,'frameAdvance':0,'checkedBytes':0};calls=[];digest=hashlib.sha256()
def alloc(size):
 global cursor
 p=(cursor+15)&~15;cursor=p+max(16,size)
 if cursor>BASE+SIZE:raise ValueError('Arena capacity')
 n.write(p,bytes(max(16,size)));return p
def observe(mu,a,size,_):calls.append(a)
for a in [0x5dfab0,0x4ffaa0,0x4ffac0,0x5ddd10,0x5fca40,0x5fd100,0x5fd160]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def compare(a,e,where):
 counts['checkedBytes']+=len(a);digest.update(a);digest.update(e)
 if a!=e and len(errors)<20:
  delta=[i for i,(x,y)in enumerate(zip(a,e))if x!=y]
  errors.append({'where':where,'actualBytes':len(a),'expectedBytes':len(e),'firstOffsets':delta[:12]})
def u(b,p):return struct.unpack_from('<I',b,p)[0]
def w(b,p,v):struct.pack_into('<I',b,p,v&0xffffffff)
def seq(size,seed):return bytes(((i*37+seed*19)^(i>>3))&255 for i in range(size))
def ctx_model(b):
 b=bytearray(b);w(b,8,0);w(b,0x14,0xffffffff);w(b,0x20,0xffffffff)
 for p in [0x24,0x2c,0x2e,0x1e]:struct.pack_into('<H',b,p,65535)
 return bytes(b)
def shader_model(b):
 b=bytearray(b)
 for p in [0xf4,0x100,0x168,0x34,0x110,0x180,0x198]:w(b,p,0)
 return bytes(b)
def sizes(c,m):return (0 if c==0 else (((c+7)//8*2)//16+1)*16,0 if m==0 else (((m+7)//8)//16+1)*16)
def model(spec,flags,force,seed):
 cs,ms=sizes(spec['clipCount'],len(spec['table']));clips=[bytearray(seq(cs+16,seed+p))for p in range(2)];mats=[bytearray(seq(ms+16,seed+2+p))for p in range(2)];records=[bytearray.fromhex(x)for x in spec['records']];contexts=[bytes.fromhex(x)for x in spec['contexts']];active=force!=0 or bool(flags&6);parity=(flags>>15)&1;trace=[0x5ddd10]
 if active:
  mats[parity][:ms]=bytes(ms);clips[parity][:cs]=bytes(cs)
  if force:clips[1-parity][:cs]=bytes([255])*cs
  for ri in spec['table']:
   r=records[ri];w(r,0x14,u(r,0x10));slot=0 if force else int(u(r,0x34)==0);w(r,0x34,slot);w(r,0x30,u(r,0x28+slot*4));ci=spec['recordContexts'][ri];contexts[ci]=ctx_model(contexts[ci]);trace.append(0x5fca40)
  flags&=0xfffffff1
 return flags,clips,mats,records,contexts,trace
def encode(state):
 flags,clips,mats,records,contexts,_=state
 return struct.pack('<I',flags)+b''.join(bytes(x)for x in clips+mats+records+contexts)
def install(spec,flags,seed,at=None,owner=False):
 p=alloc(0x90)if at is None else at;n.write(p,bytes(0x90));cs,ms=sizes(spec['clipCount'],len(spec['table']));clipPtrs=[alloc(cs+16)for _ in range(2)];matPtrs=[alloc(ms+16)for _ in range(2)];contextPtrs=[alloc(len(bytes.fromhex(x)))for x in spec['contexts']];recordPtrs=[alloc(68)for _ in spec['records']];table=alloc(len(spec['table'])*4)
 for i,x in enumerate(spec['contexts']):n.write(contextPtrs[i],bytes.fromhex(x))
 for i,x in enumerate(spec['records']):
  raw=bytearray.fromhex(x);w(raw,8,contextPtrs[spec['recordContexts'][i]]);n.write(recordPtrs[i],raw)
 for i,ri in enumerate(spec['table']):n.pack('<I',table+i*4,recordPtrs[ri])
 for i,a in enumerate(clipPtrs):n.write(a,seq(cs+16,seed+i))
 for i,a in enumerate(matPtrs):n.write(a,seq(ms+16,seed+2+i))
 n.pack('<I',p+0x10,spec['clipCount']);n.pack('<2I',p+0x30,*clipPtrs);n.pack('<I',p+0x4c,len(spec['table']));n.pack('<I',p+0x54,table);n.pack('<2I',p+0x58,*matPtrs);n.pack('<I',p+0x74,flags);op=alloc(0x50)if owner else 0;n.pack('<I',p+0x78,op)
 if op:n.write(op,seq(0x50,seed+9))
 return {'p':p,'clips':clipPtrs,'mats':matPtrs,'contexts':contextPtrs,'records':recordPtrs,'owner':op,'cs':cs,'ms':ms}
def snapshot(spec,layout,trace):
 records=[]
 for i,p in enumerate(layout['records']):
  raw=bytearray(n.read(p,68));w(raw,8,u(bytes.fromhex(spec['records'][i]),8));records.append(raw)
 return n.unpack('<I',layout['p']+0x74)[0],[n.read(p,layout['cs']+16)for p in layout['clips']],[n.read(p,layout['ms']+16)for p in layout['mats']],records,[n.read(p,len(bytes.fromhex(spec['contexts'][i])))for i,p in enumerate(layout['contexts'])],trace
def run_reset(spec,si,flags,force,seed,kind):
 global cursor
 cursor=BASE;layout=install(spec,flags,seed);expected=model(spec,flags,force,seed);calls.clear();n.call(0x5ddd10,args=[force],regs={UC_X86_REG_ESI:layout['p']},count=8000000);actual=snapshot(spec,layout,list(calls));a=encode(actual);e=encode(expected);compare(a,e,[kind,si,flags,force,seed]);compare(struct.pack('<'+'I'*len(calls),*calls),struct.pack('<'+'I'*len(expected[-1]),*expected[-1]),['resetCalls',si]);counts[kind]+=1;cases.append({'kind':'reset','spec':si,'flags':flags,'force':force,'seed':seed,'nativeSHA256':hashlib.sha256(a).hexdigest(),'nativeCalls':list(calls)})
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};specs=[]
for si,sr in enumerate(json.loads((R/'geometry-static-finish-native-validation.json').read_text())['sources']):
 raw=(B/'extracted'/sr['source']).read_bytes();rs=json.loads((B/'exports/geometry/scene-runtime'/(sr['source']+'.json')).read_text())['renderState'];a=rs['address']
 def ptr(q):
  d=struct.unpack_from('<i',raw,q)[0];return q+d if d else 0
 count=u(raw,a+0x4c);tablePtr=ptr(a+0x54);recordIds={};ctxIds={};spec={'clipCount':u(raw,a+0x10),'table':[],'records':[],'contexts':[],'recordContexts':[]}
 for i in range(count):
  rp=ptr(tablePtr+i*4)
  if rp not in recordIds:
   recordIds[rp]=len(spec['records']);spec['records'].append(raw[rp:rp+68].hex());cp=ptr(rp+8)
   if cp not in ctxIds:ctxIds[cp]=len(spec['contexts']);spec['contexts'].append(raw[cp:cp+52].hex())
   spec['recordContexts'].append(ctxIds[cp])
  spec['table'].append(recordIds[rp])
 specs.append(spec);sources.append({'source':sr['source'],'sha256':hashlib.sha256(raw).hexdigest(),'clips':spec['clipCount'],'materialReferences':count,'uniqueRecords':len(recordIds),'uniqueContexts':len(ctxIds)})
 for parity in [0,1]:
  for fi,(force,flag)in enumerate([(0,0),(0,2),(0,4),(0,8),(1,0),(0xffffffff,8)]):run_reset(spec,si,flag|(parity<<15)|0x40100000,force,si+fi,'authoredReset')
 print('authored',si+1,flush=True)if (si+1)%10==0 else None
# Synthetic sizes straddle both parity bitset padding boundaries. Record/table
# aliasing and non-boolean previous slot values deliberately retained.
for clipCount,materialCount in [(0,0),(1,1),(7,7),(8,8),(63,63),(64,64),(65,65),(127,127),(128,128),(129,129),(255,255),(256,256),(257,257)]:
 records=[];contexts=[];rc=[]
 for i in range(materialCount):
  r=bytearray(seq(68,i));w(r,0x34,[0,1,2,0xffffffff][i%4]);records.append(r.hex())
  ci=i//2
  if ci==len(contexts):contexts.append(seq(52,ci+5).hex())
  rc.append(ci)
 table=list(range(materialCount))
 if materialCount>=7:table[3]=0;table[6]=0
 spec={'clipCount':clipCount,'table':table,'records':records,'contexts':contexts,'recordContexts':rc};si=len(specs);specs.append(spec)
 for parity,flag,force in itertools.product([0,1],range(16),[0,1]):run_reset(spec,si,flag|(parity<<15),force,clipCount+flag,'syntheticReset')
# Whole context helper checks include identical object/template aliasing.
for kind,address,size in [('contextReset',0x5fca40,52),('shaderReset',0x5fd100,420),('globalReset',0x5fd160,420)]:
 for seed in range(32):
  cursor=BASE;data=seq(size,seed);glob=seq(420,seed+47);p=alloc(size);n.write(p,data);n.write(0x9868a0,glob);alias=(kind=='shaderReset'and seed%2!=0)
  if alias:p=0x9868a0;data=glob
  calls.clear();n.call(address,args=[]if kind=='globalReset'else[p]);out=n.read(p,size)if kind!='globalReset'else b'';g=n.read(0x9868a0,420)
  if kind=='contextReset':eo=ctx_model(data);eg=glob
  elif kind=='shaderReset':
   eo=shader_model(data);eg=ctx_model(glob)
   if alias:eo=eg=ctx_model(shader_model(glob))
  else:eo=b'';eg=ctx_model(shader_model(glob))
  compare(out+g,eo+eg,[kind,seed,alias]);counts[kind]+=1;cases.append({'kind':kind,'seed':seed,'alias':alias,'nativeSHA256':hashlib.sha256(out+g).hexdigest()})
# Original caller plus original nonempty resetters, sorted list and global cache.
for registryCount,pattern in itertools.product([0,1,2,7,256],range(4)):
 cursor=BASE;layouts=[];rs=[];globalSpec=specs[len(sources)+2];gs=0x973dbc;gf=pattern|0x8000;globalLayout=install(globalSpec,gf,pattern,at=gs);layouts.append(globalLayout);rs.append((len(sources)+2,gf,pattern))
 n.pack('<I',0x973fa4,0);n.pack('<I',0x9739b8,registryCount)
 for i in range(registryCount):
  si=len(sources)+(i%4);flags=((i+pattern)%16)|((i&1)<<15);seed=i+pattern+23;layout=install(specs[si],flags,seed,owner=(i%3!=0));n.pack('<I',0x9739bc+i*4,layout['p']);layouts.append(layout);rs.append((si,flags,seed))
 # List follows deliberately permuted pointers; logical order is separately stored.
 listCount=[0,1,7,31][pattern];nodes=[alloc(32)for _ in range(listCount)];listRaw=[seq(32,i+pattern)for i in range(listCount)]
 for i,p in enumerate(nodes):
  r=bytearray(listRaw[i]);w(r,8,nodes[i+1]if i+1<len(nodes)else 0);n.write(p,r);listRaw[i]=bytes(r)
 n.pack('<I',0x973ecc,nodes[0]if nodes else 0);n.pack('<I',0x973ed0,0xdeadbeef);initialGlobal=seq(420,pattern+39);n.write(0x9868a0,initialGlobal);calls.clear();n.call(0x5dfab0,count=12000000);parts=[];expectedParts=[];expectedCalls=[0x5dfab0,0x4ffaa0]
 for idx,(si,flags,seed)in enumerate(rs):
  expected=model(specs[si],flags^0x8000,0,seed);actual=snapshot(specs[si],layouts[idx],[]);parts.append(encode(actual));expectedParts.append(encode(expected));expectedCalls.extend(expected[-1]);op=layouts[idx]['owner']
  if op:
   observed=n.read(op,0x50);wanted=bytearray(seq(0x50,seed+9));w(wanted,0x44,0);parts.append(observed);expectedParts.append(bytes(wanted))
 for i,p in enumerate(nodes):
  actual=bytearray(n.read(p,32));e=bytearray(listRaw[i]);w(e,0x14,u(e,0x14)&~2);w(actual,8,0);w(e,8,0);parts.append(bytes(actual));expectedParts.append(bytes(e))
 parts.extend([n.read(0x973ed0,4),n.read(0x9868a0,420)]);expectedParts.extend([bytes(4),ctx_model(shader_model(initialGlobal))]);expectedCalls.extend([0x5fd160,0x4ffac0]);a=b''.join(parts);e=b''.join(expectedParts);compare(a,e,['advance',registryCount,pattern]);compare(struct.pack('<'+'I'*len(calls),*calls),struct.pack('<'+'I'*len(expectedCalls),*expectedCalls),['advanceCalls',registryCount,pattern]);counts['frameAdvance']+=1;cases.append({'kind':'advance','count':registryCount,'pattern':pattern,'nativeSHA256':hashlib.sha256(a).hexdigest(),'nativeCalls':list(calls)})
fixture={'specs':specs,'cases':cases};fp=R/'geometry-frame-reset-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(fixture,separators=(',',':')).encode(),mtime=0));report={'schema':'geometry-frame-reset-native-v1','binarySHA256':n.sha256,'passed':not errors,'counts':counts,'sources':sources,'errors':errors,'resultSHA256':digest.hexdigest(),'fixtureFile':fp.name,'fixtureBytes':fp.stat().st_size,'fixtureSHA256':hashlib.sha256(fp.read_bytes()).hexdigest(),'boundaries':{'locking':'Original 4ffaa0/4ffac0 execute unchanged with zero lock handle. Nonzero OS synchronization excluded.','memory':'Only valid allocated buffers/counts and finite acyclic registered/sort lists. Exact16-byte block padding and16-byte untouched canaries checked.','native':'All six primary helpers and the original block-fill/CRT calls run unchanged. No replacement hooks.'},'limits':['No managed executable launched; original-versus-Python comparison only.','Static frame state only; dynamic-list flush and sorted packet finalizer still separate.','Source metadata selects60 portal-bearing scenes; synthetic counts0..257 straddle padding boundaries.','Synthetic duplicate material-record references and shared contexts preserve pointer alias effects.']}
(R/'geometry-frame-reset-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k]for k in ['passed','counts','errors','fixtureBytes']}));raise SystemExit(bool(errors))

