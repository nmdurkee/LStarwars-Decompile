"""Original actor-state/Sock command bytes in isolated x86 memory.
Native name callback and takeover-release implementation are explicit boundaries.
No game executable or OS API is run. All meaningful fixtures are retained.
"""
import importlib.util, itertools, json, struct, hashlib, random
from pathlib import Path
spec=importlib.util.spec_from_file_location('nx',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=m.NativeX86();B=m.BASE;D=n.DATA;ACTORS=[D+0x1000,D+0x3000];REFS=[D+0x6000,D+0x6100];CREATURE=D+0x6200;WORLD=D+0x7000;TABLE=D+0x10000;RECORDS=D+0x20000;PACKET=D+0x40000;SCRIPT=D+0x41000;TOKENS=D+0x50000;STRINGS=D+0x60000;LOOKUP=n.STOP+0x100;events=[]
def cstr(address):
 result=bytearray()
 for i in range(512):
  value=n.read(address+i,1)[0]
  if not value:return result.decode('ascii')
  result.append(value)
 raise ValueError('Unterminated prepared ASCII operand')
def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
 if address in [0x541430,0x541460]:
  events.append(['enable'if address==0x541430 else'disable',n.unpack('<i',sp+8)[0]]);return
 if address==LOOKUP:
  name=cstr(n.unpack('<I',sp+8)[0]);events.append(['name',name]);value=REFS[0]if name.lower()=='a'else REFS[1]if name.lower()=='b'else 0
  mu.reg_write(UC_X86_REG_EAX,value)
 else:
  events.append(['release',ACTORS.index(n.unpack('<I',sp+4)[0])])
  mu.reg_write(UC_X86_REG_EAX,0)
 mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
for va in [LOOKUP,0x4882d0,0x541430,0x541460]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=va,end=va)
def strings(tokens):
 cursor=STRINGS;pointers=[]
 for token in tokens:
  if token is None:pointers.append(0);continue
  data=token.encode('ascii')+b'\0';n.write(cursor,data);pointers.append(cursor);cursor+=len(data)+8
 if pointers:n.pack('<'+'I'*len(pointers),TOKENS,*pointers)
 return TOKENS
seedflags=[(i*997+0x55aa)&0xffff for i in range(64)]
def setup(tokens):
 n.write(D,bytes(0x80000));events.clear();n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x2988,TABLE);n.pack('<I',TABLE,RECORDS)
 for i in range(2):n.pack('<I',REFS[i],ACTORS[i])
 n.pack('<I',CREATURE+0xd0,REFS[0]);n.pack('<I',PACKET+4,SCRIPT);n.pack('<4f',PACKET+0x14,5.75,63.9,-.75,100)
 for i,name in enumerate(['slot','other','neg','large']):
  p=SCRIPT+0x100+i*16;n.write(p,name.encode()+b'\0');n.pack('<I',SCRIPT+0x18+i*8,p)
 for i in range(64):
  n.pack('<B',RECORDS+i*0x13c+0x32,1 if i in [0,7,8,63]else 0);n.pack('<H',RECORDS+i*0x13c+0x68,seedflags[i]);n.write(RECORDS+i*0x13c+0xe4,(['Zero'if i==0 else'Door'if i in[7,8]else'Final'if i==63 else'Unused'+str(i)][0]).encode()+b'\0')
 n.pack('<I',0x923904,LOOKUP);strings(tokens)
def invoke(va,tokens,first=1,creature=CREATURE,count=None):
 return n.call(va,[WORLD,PACKET,creature,TOKENS,len(tokens)if count is None else count,first],count=1000000)
def parse_float(text):
 text=text.split('\0')[0];v=0.;div=1.;i=0;f=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
 if text.startswith('-'):div=-1.;i=1
 while i<len(text)and'0'<=text[i]<='9':v=f(f(v*10)+ord(text[i])-48);i+=1
 if i<len(text)and text[i]=='.':
  i+=1
  while i<len(text)and'0'<=text[i]<='9':div=f(div*10);v=f(f(v*10)+ord(text[i])-48);i+=1
 return f(v/div)
def number(text):
 if 'param'in text.lower():return 5.75
 if text.lower()in['slot','other','neg','large']:return[5.75,63.9,-.75,100][['slot','other','neg','large'].index(text.lower())]
 return parse_float(text)
def sock_model(tokens,first,table=True):
 flags=seedflags.copy();index=-1;enabled=True
 if first:
  for token in tokens:
   token=token.split('\0')[0];low=token.lower()
   if 'ix='in low:index=int(number(token[low.index('ix=')+3:]))&0xffffffff;index=index if index<0x80000000 else index-0x100000000
   elif 'name='in low:
    value=token[low.index('name=')+5:].lower();found={'zero':0,'door':7,'final':63}.get(value,-1)if table else-1
    if found!=-1:index=found
   elif 'false'in low:enabled=False
  if table and 0<=index<64:flags[index]=flags[index]&0xfeff if enabled else flags[index]|0x100
 return flags,([['enable'if enabled else'disable',index]]if first else[])
report={'binarySha256':n.sha256,'checks':0,'mismatches':[],'groups':{},'vectors':[],'authoredOccurrences':0,'method':'Original3 command bodies plus0x53f7e0 fixed64-entry lookup,0x541430/0x541460 bit mutation, original string/packet numeric and signed64 truncation helpers. Registered character-name resolver and full takeover release are explicit adapters.'}
def check(group,input,actual,want):
 report['checks']+=1;report['groups'][group]=report['groups'].get(group,0)+1
 if actual!=want:report['mismatches'].append({'group':group,'input':input,'actual':actual,'expected':want})
 report['vectors'].append({'group':group,'input':input,'native':actual})
false_tokens=[[],['FALSE'],['false'],['xFALSE'],['FALSEtail'],['TRUE','FALSE','TRUE'],[''],[None],['FALSE\0tail']]
for flags,first,gate,tokens in itertools.product([0,1,2,3,0xffffffff,0x80000000], [0,1],range(4),false_tokens):
 setup(tokens);n.pack('<I',ACTORS[0]+0xef0,flags)
 creature=CREATURE
 if gate==0:creature=0
 if gate==1:n.pack('<I',CREATURE+0xd0,0)
 if gate==2:n.pack('<I',REFS[0],0)
 result=invoke(0x44ccd0,tokens,first,creature)
 want=flags
 if gate==3 and first:
  want|=2
  for token in tokens:
   if token is not None and token.split('\0')[0].lower()=='false':want&=0xfffffffd
 actual=[result,n.unpack('<I',ACTORS[0]+0xef0)[0]];meta={'flags':flags,'first':first,'gate':gate,'tokens':tokens}
 check('CannotBeSeen',meta,actual,[1,want])
base_tokens=[[],['FALSE'],['ix=0'],['ix=7'],['ix=63'],['ix=64'],['ix=-1'],['ix=4294967296'],['ix=4294967808'],['ix=slot'],['ix=param3'],['ix=63.9'],['ix=-.75'],['prefixIX=7'],['name=Door'],['name=Final'],['name=Nope'],['ix=7','name=Nope'],['name=Door','ix=63'],['FALSE','ix=7','TRUE'],['name=DoorFALSE'],['ix=7FALSE'],['name=Door','xxfalseyy'],['ix=7','name=Missing','FALSE'],['name=door\0FALSE'],['ix=5name=DoorFALSE']]
for first,table,tokens in itertools.product([0,1],[False,True],base_tokens):
 setup(tokens)
 if not table:n.pack('<I',WORLD+0x2988,0)
 result=invoke(0x44ce00,tokens,first);actual=[result,list(n.unpack('<H',RECORDS+i*0x13c+0x68)[0]for i in range(64)),list(events)]
 flags,seq=sock_model(tokens,first,table);meta={'first':first,'table':table,'tokens':tokens};check('EnableSock',meta,actual,[1,flags,seq])
for va,enabled,index,initial in itertools.product([0x541430,0x541460],[0],[-2147483648,-1,0,1,63,64,2147483647],[0,1,0x100,0x101,0xffff]):
 setup([]);n.pack('<H',RECORDS+0x68,initial);n.pack('<H',RECORDS+63*0x13c+0x68,initial)
 result=n.call(va,[TABLE,index]);flags=[n.unpack('<H',RECORDS+i*0x13c+0x68)[0]for i in range(64)];want=seedflags.copy();want[0]=initial;want[63]=initial
 if 0<=index<64:want[index]=want[index]&0xfeff if va==0x541430 else want[index]|0x100
 check('SockUnsignedIndex',{'address':hex(va),'index':index,'flags':initial},flags,want)
release_tokens=[[],['character=B'],['character=Missing'],['character=B','character=Missing'],['character=Missing','character=A'],['xxCHARACTER=b'],['character=B\0character=A'],['FALSE']]
for first,callback,gate,links,tokens in itertools.product([0,1],[0,1],range(4),range(4),release_tokens):
 setup(tokens);n.pack('<I',0x923904,LOOKUP if callback else 0)
 for i in range(2):n.pack('<I',ACTORS[i]+0xcd0,ACTORS[1-i]if links&(1<<i)else 0)
 creature=CREATURE
 if gate==0:creature=0
 if gate==1:n.pack('<I',CREATURE+0xd0,0)
 if gate==2:n.pack('<I',REFS[0],0)
 actor=0 if gate==3 else None;want=[]
 if first:
  for token in tokens:
   low=token.split('\0')[0].lower()
   if 'character='in low:
    name=token.split('\0')[0][low.index('character=')+10:]
    if callback:want.append(['name',name])
    actor={'a':0,'b':1}.get(name.lower())if callback else None
    if actor==0 and gate==2:actor=None
  if actor is not None and links&(1<<actor):want.append(['release',actor])
 result=invoke(0x4545d0,tokens,first,creature);meta={'first':first,'callback':callback,'gate':gate,'links':links,'tokens':tokens}
 check('ReleaseTakeOver',meta,[result,list(events)],[1,want])
# Preserve and execute all actual source command operands as separate cases.
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())
for row in ledger['rows']:
 if row['kind']!='scp-action'or row['name']not in ['CannotBeSeen','EnableSock','ReleaseTakeOver']:continue
 for use in row['uses']:
  tokens=use['args'];setup(tokens)
  if row['name']=='CannotBeSeen':
   n.pack('<I',ACTORS[0]+0xef0,0x55aa55aa);result=invoke(0x44ccd0,tokens);want=0x55aa55aa|2
   for token in tokens:
    if token.lower()=='false':want&=0xfffffffd
   actual=[result,n.unpack('<I',ACTORS[0]+0xef0)[0]];expected=[1,want]
  elif row['name']=='EnableSock':
   result=invoke(0x44ce00,tokens);flags,seq=sock_model(tokens,1);actual=[result,[n.unpack('<H',RECORDS+i*0x13c+0x68)[0]for i in range(64)],list(events)];expected=[1,flags,seq]
  else:
   n.pack('<I',ACTORS[0]+0xcd0,ACTORS[1]);result=invoke(0x4545d0,tokens);wanted=[];actor=0
   for token in tokens:
    low=token.lower()
    if 'character='in low:
     name=token[low.index('character=')+10:];wanted.append(['name',name]);actor={'a':0,'b':1}.get(name.lower())
   if actor==0:wanted.append(['release',0])
   actual=[result,list(events)];expected=[1,wanted]
  meta={'first':1,'table':True,'flags':0x55aa55aa,'callback':1,'gate':3,'links':1,'tokens':tokens,'authored':use,'command':row['name']}
  check('Authored-'+row['name'],meta,actual,expected);report['authoredOccurrences']+=1
report['adapters']=[{'address':hex(LOOKUP),'purpose':'Prepared character resolver returns reference for A/B or null. Source composes existing ActorStateWorld resolver; real world actor population is external.'},{'address':'0x4882d0','purpose':'Records(actor,0) release boundary; actual transfer, vehicle restoration and ReleasedTakeOver notifications are not executed.'}]
report['limits']=['Prepared valid fixed64-entry table, actor/reference attachments, ASCII tokens; strings truncate at first NUL.','EnableSock original numeric resolution/case-insensitive substring scanning and helper bit writes execute unmodified. No Sock loader or visual consumer reconstructed.','Takeover callback and full release remain explicit adapters, not an integrated vehicle release.','Native suites are independent of compiled C# behavior; managed execution remains pending.']
report['sourceEvidence']=[{'address':'0x'+va,'path':'decompiled/corpus-expanded/FUN_'+va+'.c','sha256':hashlib.sha256((B/('decompiled/corpus-expanded/FUN_'+va+'.c')).read_bytes()).hexdigest()}for va in['44ccd0','44ce00','4545d0','53f7e0','541430','541460']]
report['toolSha256']=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
assembly={}
for va,size in[(0x44ccd0,0xb0),(0x44ce00,0x120),(0x4545d0,0xe0),(0x53f7e0,0x70),(0x541430,0x30),(0x541460,0x30)]:assembly[hex(va)]=[{'address':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str}for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(va,size),va)]
(B/'reports/actor-next-20261013-assembly.json').write_text(json.dumps(assembly,indent=2)+'\n')
(B/'reports/actor-next-20261013-fixtures.json').write_text(json.dumps(report,indent=2)+'\n')
summary={k:v for k,v in report.items()if k!='vectors'};(B/'reports/actor-next-20261013-native-tests.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps({k:summary[k]for k in ['checks','groups','authoredOccurrences','mismatches']}));raise SystemExit(bool(report['mismatches']))
