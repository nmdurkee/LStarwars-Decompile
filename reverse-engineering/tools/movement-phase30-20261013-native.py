"""Whole original three mode capability producers, without child adapters."""
from pathlib import Path
import importlib.util,struct,json,gzip,base64,itertools,random
sp=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);n=m.NativeX86();D=n.DATA;SIZE=0x10000;ACT=D+0x1000;META=D+0x4000;DATA=D+0x5000;MODEL=D+0x6000;CLIPS=D+0x7000;SUIT=D+0x8000;vectors=[];errors=[]
def setup30(c):
 n.write(D,bytes([0xa5])*SIZE);meta=ACT+c['metaOffset']if'metaOffset'in c else META;data=ACT+c['dataOffset']if'dataOffset'in c else DATA;clips=ACT+c['clipOffset']if'clipOffset'in c else CLIPS;suit=ACT+c['suitOffset']if'suitOffset'in c else SUIT;n.pack('<2I',ACT+0x50,MODEL,meta);n.pack('<I',meta+0x24,data);n.pack('<I',MODEL+0xc,clips);n.pack('<I',ACT+0x1f8,c.get('actorFlags',0));n.pack('<I',ACT+0xcbc,suit if c.get('suit')else 0);n.pack('<B',ACT+0x280,c.get('player',255));n.pack('<H',ACT+0x1064,c.get('type',7)&65535);n.pack('<H',0x7f17d0,c.get('alternateType',7)&65535);n.pack('<H',0x7f18bc,c.get('specialType',8)&65535)
 for j,at in enumerate([0x18,0x220,0x224,0x228,0x22c,0x230,0x334]):n.pack('<I',clips+at,c.get('present',127)&(1<<j))
 n.pack('<I',meta+4,c.get('metadataFlags',0));n.pack('<I',data+0x90,c.get('dataFlags',0));n.pack('<I',suit+0x10,c.get('suitFlags',0));n.pack('<I',meta+0x44,c.get('baseFlags',0))
 return bytearray(n.read(D,SIZE))
def oracle30(kind,c,img):
 def u(p):return struct.unpack_from('<I',img,p-D)[0]
 def put(p,v):struct.pack_into('<I',img,p-D,v&0xffffffff)
 def b(p):return img[p-D]
 def add(v):put(ACT+0x4bc,u(ACT+0x4bc)|v)
 def clip(model,at):return u(u(model+0xc)+at)
 def data(meta):return u(u(meta+0x24)+0x90)
 if kind=='alternate':
  fl=u(ACT+0x1f8);put(ACT+0x4bc,0x20000000)
  if fl&1:put(ACT+0x4bc,0x20000200)
  elif not fl&4:put(ACT+0x4bc,0x20000100)
  model=u(ACT+0x50)
  if clip(model,0x18):add(3)
  meta=u(ACT+0x54)
  if not u(meta+4)&0x200000:add(4)
  if u(meta+4)&0x100000:add(8)
  if u(ACT+0x1064)&65535==c.get('alternateType',7)&65535:add(0x400)
  if clip(model,0x334):add(0x10)
  return
 if kind=='special':
  flags=u(ACT+0x1f8);meta=u(ACT+0x54);v=u(meta+0x44)|0x20180040;put(ACT+0x4bc,v)
  if flags&1:v|=0x100;put(ACT+0x4bc,v)
  elif not flags&4:v|=0x80;put(ACT+0x4bc,v)
  model=u(ACT+0x50)
  if clip(model,0x18):add(1)
  fl=u(meta+4)
  if not fl&0x200000 and fl&8:add(0x1000)
  if b(meta+4)&8:add(3)
  if data(meta)&0x400000:add(0x23)
  if u(meta+4)&0x40000:add(0x10)
  if b(meta+4)&0x40:add(0x4004)
  if u(meta+4)&0x100000:add(8)
  if u(meta+4)&0x2000:add(0x10000)
  if b(meta+4)&0x88 or data(meta)&0x40:add(0x8000)
  if b(ACT+0x280)!=255:add(0x20000)
  if u(ACT+0x1064)&65535==c.get('specialType',8)&65535:add(0x4000)
  return
 model=u(ACT+0x50);meta=u(ACT+0x54);v=u(meta+0x44)|0x20000040;put(ACT+0x4bc,v);clips=u(model+0xc)
 if u(clips+0x220)and u(clips+0x224):v|=0x40000 if data(meta)&0x80000 else 0x80000;put(ACT+0x4bc,v)
 clips=u(model+0xc)
 if u(clips+0x228)and u(clips+0x22c)and u(clips+0x230):add(0x400000)
 if clip(model,0x334):add(0x100000)
 if clip(model,0x18):add(1)
 if data(meta)&0x400000:add(0x20)
 if data(meta)&0x40000000:add(2)
 suit=u(ACT+0xcbc)
 if suit:add(u(suit+0x10))
 fl=u(ACT+0x1f8)
 if fl&1:add(0x100)
 elif not fl&4:add(0x80)
 add(0x1000)
 if u(meta+4)&0x40000:add(0x10)
 if u(meta+4)&0x100000:add(8)
 if u(meta+4)&0x2000:add(0x10000)
 if b(meta+4)&0x88 or data(meta)&0x40:add(0x8000)
 if b(ACT+0x280)!=255:add(0x20000)
 if data(meta)&0x4000000:add(0x800000)
def run30(kind,c):
 before=setup30(c);expected=bytearray(before);oracle30(kind,c,expected);n.call({'normal':0x407b60,'alternate':0x481740,'special':0x4cbe50}[kind],[ACT]);after=n.read(D,SIZE)
 if after!=expected:errors.append(dict(kind=kind,input=c,diff=[[hex(j),after[j],expected[j]]for j in range(SIZE)if after[j]!=expected[j]][:12]))
 vectors.append(dict(kind=kind,input=c,before=base64.b64encode(gzip.compress(before)).decode(),after=base64.b64encode(gzip.compress(after)).decode()))
for kind,mask,flags in itertools.product(['normal','alternate','special'],range(128),[0,1,4,5]):run30(kind,dict(present=mask,actorFlags=flags))
for kind,bit in itertools.product(['normal','alternate','special'],range(32)):
 for field in['metadataFlags','dataFlags','baseFlags','suitFlags']:run30(kind,{field:1<<bit,'suit':True})
for kind,field,offset,flags in itertools.product(['normal','alternate','special'],['metaOffset','dataOffset','clipOffset','suitOffset'],[0,1],[0,0xffffffff]):
 address={'metaOffset':[0x4b8,0x478],'dataOffset':[0x42c,0x430],'clipOffset':[0x4a4,0x188],'suitOffset':[0x4ac,0x4b0]}[field][offset];run30(kind,{field:address,'metadataFlags':flags,'dataFlags':flags,'baseFlags':flags,'suit':True,'suitFlags':flags})
for kind,typ,alt,special,player in itertools.product(['alternate','special'],[0,7,8,32767,32768,65535],[7,32768],[8,65535],[0,255]):run30(kind,dict(type=typ,alternateType=alt,specialType=special,player=player))
r=random.Random(30)
for j in range(192):run30(['normal','alternate','special'][j%3],dict(present=r.randrange(128),actorFlags=r.getrandbits(32),metadataFlags=r.getrandbits(32),dataFlags=r.getrandbits(32),baseFlags=r.getrandbits(32),suit=True,suitFlags=r.getrandbits(32),player=r.randrange(256)))
report=dict(status='unsealed whole mode capability body comparisons',binarySha256=n.sha256,cases=len(vectors),assertionGroups=len(vectors),mismatches=len(errors),errors=errors[:10],explicitServices=[])
(m.BASE/'reports/movement-phase30-20261013-draft-tests.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(cases=len(vectors),mismatches=len(errors),errors=errors[:2])))

if errors:raise SystemExit('Mismatches; no sealed fixture written')
report.update(status='sealed whole original mode capability comparisons; managed replay unexecuted',limits=['Whole three own-state mode capability bodies without child adapters; complete readable backing required.','Original captured actor/model/metadata values and fresh sequential field reads retained; valid output aliases into metadata flags/base flags, data flags, suit flags and clip fields tested.','Void function return registers and machine flags excluded; full DATA image comparison is one assertion group per case.'])
(m.BASE/'reports/movement-phase30-20261013-tests.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(m.BASE/'reports/movement-phase30-20261013-fixtures.json.gz','wt',encoding='utf-8')as f:json.dump(dict(vectors=vectors),f,separators=(',',':'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
cs=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
for a,b in[(0x407b60,0x407cf3),(0x481740,0x4817d8),(0x4cbe50,0x4cbf6b)]:functions.append(dict(address=hex(a),size=b-a,instructions=[dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str)for i in cs.disasm(n.read(a,b-a),a)]))
(m.BASE/'reports/movement-phase30-20261013-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2)+'\n')
