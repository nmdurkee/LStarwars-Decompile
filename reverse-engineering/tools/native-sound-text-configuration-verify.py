import importlib.util,json,struct,gzip,copy,itertools
from pathlib import Path
def module(name,file):
 s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
g=module('groups','native-sound-groups-verify.py');d=g.d;b=d.b;B=d.B;D=d.D;n=b.x.NativeX86();l=module('lines','native-text-lines-verify.py');num=module('numbers','native-text-numbers-verify.py');t=num.t
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
PARSER=d.PARSER;TOKEN=d.TOKENS;BUFFER=D+0x62000;LINE=D+0x64000;PATH=D+0x66000;CURSOR=D+0x67000;MARKER=D+0x7f000;HANDLE=0x12345678
l.PARSER=PARSER;l.BUFFER=BUFFER;l.LINE=LINE;t.PARSER=PARSER;t.LINE=LINE;t.TOKEN=TOKEN
b.REGIONS=[(0x76d200,40),(0x810470,32),(0x88ab4c,4),(0x91eec4,4),(0x2920000,0x44000),(D,0x80000)]
constants={a:n.read(a,z) for a,z in b.REGIONS[:2]}
def capture():
 m=b.Image(0)
 for a,z in b.REGIONS:m.r[a]=bytearray(n.read(a,z))
 return m
def load(m):
 for a,data in m.r.items():n.write(a,data)
def setup(p):
 m=d.setup(d.options([],index=0,seed=p['seed']));
 for a,data in constants.items():m.write(a,data)
 for a,z in [(d.RECORDS,0x19000),(d.BACKUP,0x19000),(d.BANKS,0xaf00)]:m.write(a,bytes(z))
 for a in [0x2962024,0x2962020,0x91eec4]:m.put(a,0)
 m.put(0x2962034,p['flag']);m.put(PARSER,BUFFER);m.put(PARSER+4,HANDLE);m.put(PARSER+0x50c,LINE);m.put(PARSER+0x510,TOKEN);m.put(PARSER+0x514,4096);m.put(PARSER+0x518,128);m.put(PARSER+0x51c,0);m.put(PARSER+0x520,0);m.put(PARSER+0x524,0);m.put(PARSER+0x528,0);m.put(PARSER+0x52c,0xffffffff);m.put(PARSER+0x574,len(p['text']));m.put(PARSER+0x570,0xffffffff);m.write(PARSER+0x578,b'\0');m.put(PARSER+0x57c,0);m.put(PARSER+0x580,0);m.text(PATH,'AUDIO/AUDIO.CFG');m.put(CURSOR,D+0x68000);return m
def stats(m):return dict(sounds=m.get(0x296201c),banks=m.get(0x2962014),names=m.get(0x2962018),groups=m.get(0x2962024),members=m.get(0x2962020),version=m.get(0x2962030))
def device(m,p,kind,args,events):
 row=dict(kind=kind,args=list(args))
 if kind=='banks':row['counts']=stats(m)
 events.append(row)
 if kind=='banks':m.write(0x2921760,b'\xee'*200);m.put(0x2962034,p['afterFlag']);m.put(CURSOR,m.get(CURSOR)+16)
 elif kind=='mask':m.write(0x2921760,bytes((i*3+p['seed'])&255 for i in range(200)))
 elif kind=='finish':m.put(MARKER,0x12345678)
def model(m,p):
 io=[];state=l.fresh();counts={'sample':0,'group':0,'header':0};device(m,p,'open',[PATH],io)
 def read(kind='next'):
  t.next_token(m);text=t.string(m,TOKEN)
  if kind=='integer':return b.signed(num.hexadecimal(text[1:]) if text.startswith('$') else num.hexadecimal(text[2:]) if text[:2].lower()=='0x' else num.decimal(text))
  if kind=='real':return num.flt(num.real(text))
  return text if text else None
 if p['open']:
  t.push(m,0x810470)
  while l.line(m,p,state):
   command=read()
   if command is None:continue
   if command.lower()=='audio':counts['header']+=1;m.put(0x2962030,num.bits(read('real')))
   elif command.lower()=='sample':
    counts['sample']+=1;params=d.options([],index=m.get(0x296201c),builtinCount=m.get(0x296202c));d.model(params,m,reader=read)
   elif command.lower()=='group':
    counts['group']+=1;first=True;group=-1
    while True:
     name=read()
     if name is None:break
     sound=g.find(m,name)
     if first:
      if sound==-1:break
      group=g.create(m,sound);first=False
     else:
      sound=g.find(m,name)
      if sound!=-1 and m.get(0x2962020)!=512:
       member=m.get(0x2962020);g.half(m,g.MEMBERS+member*2,sound);m.put(0x2962020,member+1);at=g.GROUPS+group*8;g.half(m,at+2,g.short(m,at+2)+1);g.half(m,at+4,0)
  device(m,p,'close',[PARSER],io)
 at=m.get(0x2947d70)+m.get(0x2962014)*28
 for j,v in enumerate([0,0,0,0xffffffff]):m.put(at+j*4,v)
 device(m,p,'banks',[m.get(0x2947d70),CURSOR,0xaabbccdd],io);m.write(0x2921760,bytes(200))
 if not m.get(0x2962034):device(m,p,'mask',[0x2921760,100],io)
 device(m,p,'finish',[],io);return io,state['events'],counts
current=None;state=None;io=[];calls=None
TARGETS={0x4fc860:('open',1),0x4fa300:('close',1),0x697a50:('banks',3),0x698710:('mask',2),0x698e70:('finish',0)}
def observe(mu,a,z,u):
 if a in [0x651680,0x6516a0,0x652010]:calls[{0x651680:'header',0x6516a0:'sample',0x652010:'group'}[a]]+=1;return
 sp=mu.reg_read(UC_X86_REG_ESP);result=0
 if a==0x4fb550:
  args=list(n.unpack('<3I',sp+4));handle,buffer,requested=args;assert handle==HANDLE and buffer==BUFFER and requested<=4096;data=current['text'].encode('latin1');count=min(requested,current['chunk'],len(data)-state['position']);n.write(buffer,data[state['position']:state['position']+count]);state['events'].append(dict(args=args,position=state['position'],count=count));state['position']+=count;result=count
 elif a in TARGETS:
  kind,count=TARGETS[a];args=n.unpack('<'+str(count)+'I',sp+4) if count else [];m=capture();device(m,current,kind,args,io);load(m);result=PARSER if kind=='open' and current['open'] else 0
 else:return
 mu.reg_write(UC_X86_REG_EAX,result);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for a in list(TARGETS)+[0x4fb550,0x651680,0x6516a0,0x652010]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def options(text,**kw):
 p=dict(text=text,seed=17,chunk=4096,capacity=4096,binary=0,failAfter=0x7fffffff,flag=0,afterFlag=0,open=True,label='synthetic');p.update(kw);return p
def main():
 global current,state,io,calls
 sample='Audio 1.25\r\nSample name A fname file pitch $5622 volume 0x2000 pan -.25 global\nSample name B fname file pitch +22050 volume 99999 loop\nGroup A B missing A\n'
 cases=[options(text,chunk=chunk,afterFlag=flag,open=opened) for text,chunk,flag,opened in itertools.product(['',';comment\n',sample,sample+'Unknown ignored\nSample name C fname third pitch 1e3\n'],[1,17,4096],[0,1],[False,True])]
 full=(B/'extracted/AUDIO/AUDIO.CFG').read_bytes().decode('latin1');cases.extend(options(full,chunk=chunk,label='authored-complete-file') for chunk in [4096,17]);rows=[];errors=[]
 for index,p in enumerate(cases):
  current=p;state=l.fresh();io=[];calls={'sample':0,'group':0,'header':0};m=setup(p);load(m);wantEvents,wantReads,wantCalls=model(m,p);n.call(0x6520b0,[PATH,CURSOR,0xaabbccdd],count=1000000000);actual=capture();bad=[]
  if io!=wantEvents:bad.append(dict(events=io,want=wantEvents))
  if state['events']!=wantReads:bad.append('file reads')
  if calls!=wantCalls:bad.append(dict(calls=calls,want=wantCalls))
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(dict(address=hex(a+i),got=actual.r[a][i],want=v) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:20]))
  if bad:errors.append(dict(index,label=p['label'],bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),events=io,reads=state['events'],calls=calls,counts=stats(actual)))
  print(json.dumps(dict(case=index,label=p['label'],mismatches=len(errors),counts=stats(actual))),flush=True)
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),bytesComparedPerCase=sum(z for a,z in b.REGIONS),authoredCompleteRuns=sum(r['input']['label']=='authored-complete-file' for r in rows),examples=errors[:2],method='Original6520b0→real buffered line/token/number/table dispatch→real651680/6516a0/652010 and CRC/group/record helpers execute. Only file open/read/close and bank/audio device services remain. Complete raw source bytes, bank records, hash chains, groups, counts, I/O order and whole memory compare.',limits=['Text-mode configuration with valid preallocated parser and sound/bank/name/hash buffers; file allocation/lifetime and audio resource/device actions remain external. Supplied original Audio command table bytes and names retained.','This adds651680header mapping and composed evidence for already mapped functions, no repeated native credit. Full6521b0 arena initialization integration is separate.','All1130samples/100groups parsed twice from unmodified raw authored file using17/4096-byte reads, custom numeric rounding and native comment/token rules; counts are compared rather than inferred. Managed execution pending.'])
 (B/'reports/native-sound-text-configuration-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-text-configuration-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,table=d.TABLEWORDS,constants={str(a):v.hex() for a,v in constants.items()},cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
