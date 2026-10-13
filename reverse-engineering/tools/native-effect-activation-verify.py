import importlib.util,json,struct,random,base64,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
WORLD=D;SAVE=D+0x4000;TABLE=D+0x8000;ENTRIES=D+0x9000;ARGS=D+0xc000;TEXT=D+0xd000;NAME=D+0xe000
rows=[];errors=[];groups={};memory=0
ledger=json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text());uses=next(x['uses'] for x in ledger['rows'] if x['name']=='ActivateEffect')
def enc(b):return base64.b64encode(b).decode()
def defaults(o):
 entries=[dict(name=['Flame','Smoke','Spark'][i%3],group=i%8,activation=(i*17)&255) for i in range(24)];entries[7]=None
 saved=bytearray([0xa5]*192)
 for i in range(12):
  name=['Smoke','OldEffect','Flame'][i] if i<3 else '';raw=name.encode()+b'\0';saved[i*16:i*16+len(raw)]=raw
 out=dict(entries=entries,count=24,loaded=[True]*8,group=2,saved=enc(saved),savePresent=True);out.update(o);return out

def setup(v,tokens,name):
 n.write(D,bytes(0x10000));n.pack('<I',0x802c54,WORLD);n.pack('<I',WORLD+0x130,SAVE if v['savePresent'] else 0);n.pack('<B',WORLD+0x2a98,v['group']);n.pack('<iI',0x2962098,v['count'],TABLE);n.pack('<8I',0x2924b10,*[int(x) for x in v['loaded']]);n.write(SAVE+0x2d68,base64.b64decode(v['saved']))
 for i,e in enumerate(v['entries']):
  n.pack('<I',TABLE+i*4,ENTRIES+i*0x80 if e is not None else 0)
  if e is not None:
   assert len(e['name'])<16;n.write(ENTRIES+i*0x80,bytes([0xb6])*0x80);n.write(ENTRIES+i*0x80,e['name'].encode()+b'\0');n.pack('<B',ENTRIES+i*0x80+0x11,e['group']);n.pack('<B',ENTRIES+i*0x80+0x2f,e['activation'])
 for i,t in enumerate(tokens):n.pack('<I',ARGS+4*i,TEXT+128*i);n.write(TEXT+128*i,t.encode()+b'\0')
 if name is not None:n.write(NAME,name.encode()+b'\0')
def find(v,name,group):
 if name is None:return -1
 name=name.split('\0')[0].lower()
 if group<8 and v['loaded'][group]:
  for i in range(1,v['count']):
   e=v['entries'][i]
   if e is not None and e['group']==group and e['name'].lower()==name:return i
 for i in range(1,v['count']):
  e=v['entries'][i]
  if e is not None and e['group']<2 and v['loaded'][e['group']] and e['name'].lower()==name:return i
 return -1

def save(v,data,name,enabled):
 if not v['savePresent'] or name is None:return 0
 name=name.split('\0')[0]
 if len(name)>=16:return 0
 for i in range(12):
  old=bytes(data[i*16:i*16+16]).split(b'\0')[0].decode()
  if old.lower()==name.lower():
   if enabled:data[i*16]=0;return 2
   return 3
 if enabled:return 0
 for i in range(12):
  if data[i*16]==0:raw=name.encode()+b'\0';data[i*16:i*16+len(raw)]=raw;break
 return 1

def run(kind,options={},tokens=[],name=None,enabled=True,index=1,source=None):
 global memory
 v=defaults(options);setup(v,tokens,name);wanted=[None if e is None else e['activation'] for e in v['entries']];saved=bytearray(base64.b64decode(v['saved']));ret=None
 if kind=='command':
  named=None;active=True
  for t in tokens:
   t=t.split('\0')[0];low=t.lower();at=low.find('effect')
   if at>=0:
    assert at+7<=len(t);named=t[at+7:]
   elif low=='false':active=False
  if named is not None:
   ix=find(v,named,v['group'])
   if ix>=0:wanted[ix]=2 if active else 0
   save(v,saved,named,active)
 elif kind=='set':
  ix=find(v,name,v['group'])
  if ix>=0:wanted[ix]=2 if enabled else 0
 elif kind=='find':ret=find(v,name,v['group'])
 elif kind in ['enable','disable']:
  if index!=-1:wanted[index]=2 if kind=='enable' else 0
 elif kind=='save':ret=save(v,saved,name,enabled)
 else:raise ValueError(kind)
 regions=[(ENTRIES,len(v['entries'])*0x80),(SAVE,0x3000),(TABLE,len(v['entries'])*4),(WORLD,0x3000)];expected=[bytearray(n.read(p,z)) for p,z in regions]
 for i,value in enumerate(wanted):
  if value is not None:expected[0][i*0x80+0x2f]=value
 expected[1][0x2d68:0x2d68+192]=saved
 pointer=NAME if name is not None else 0
 if kind=='command':n.call(0x464360,[0,0,ARGS,len(tokens)]);gotRet=None
 elif kind=='set':n.call(0x5a8280,[pointer,int(enabled)]);gotRet=None
 elif kind=='find':x=n.call(0x658490,[pointer,v['group']]);gotRet=x if x<0x80000000 else x-0x100000000
 elif kind=='save':gotRet=n.call(0x48a060,[SAVE if v['savePresent'] else 0,pointer,int(enabled)])
 else:n.call(0x655340 if kind=='enable' else 0x655320,[index]);gotRet=None
 got=dict(result=gotRet,activation=[None if e is None else n.unpack('<B',ENTRIES+i*0x80+0x2f)[0] for i,e in enumerate(v['entries'])],saved=enc(n.read(SAVE+0x2d68,192)));want=dict(result=ret,activation=wanted,saved=enc(saved));bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 for i,(p,z) in enumerate(regions):
  memory+=1
  if n.read(p,z)!=expected[i]:bad.append(dict(region=i))
 if bad:errors.append(dict(kind=kind,options=v,tokens=tokens,name=name,bad=bad))
 rows.append(dict(kind=kind,options=v,tokens=tokens,name=name,enabled=enabled,index=index,source=source,native=got));groups[kind]=groups.get(kind,0)+1

def main():
 for use in uses:
  names=[t[t.lower().index('effect')+7:] for t in use['args'] if 'effect'in t.lower()]
  o=defaults({});o['entries'][2]['name']=names[-1] if names else 'unused'
  for options in [o,dict(o,loaded=[False,False,False,True,True,True,True,True]),dict(o,savePresent=False)]:run('command',options,use['args'],source=use)
 for group in list(range(10))+[127,128,255]:
  for loaded in [[True]*8,[False]*8,[True,False]+[False]*6,[False,True]+[False]*6,[False,False,True]+[False]*5]:
   for name in [None,'Flame','SMOKE','Spark','missing']:
    run('find',dict(group=group,loaded=loaded),name=name)
 for count in [-1,0,1,2,24]:
  for name in ['Flame','Smoke']:
   for enabled in [False,True]:run('set',dict(count=count),name=name,enabled=enabled)
 for kind in ['enable','disable']:
  for index in [-1,0,1,2,23]:run(kind,index=index)
 for name in [None,'','Flame','Smoke','NewEffect','fifteen_chars15','sixteen_chars_16','1234567890123456','Flame\0suffix']:
  for enabled in [False,True]:
   for state in ['normal','full','duplicates','absent']:
    o=defaults({})
    if state in ['full','duplicates']:
     data=bytearray(base64.b64decode(o['saved']))
     for i in range(12):raw=('Smoke' if state=='duplicates' else 'Full'+str(i)).encode()+b'\0';data[i*16:i*16+len(raw)]=raw
     o['saved']=enc(data)
    if state=='absent':o['savePresent']=False
    run('save',o,name=name,enabled=enabled)
 for tokens in [[],['TRUE'],['FALSE'],['effect=Flame'],['FALSE','TRUE','effect=Flame'],['effect=Flame','effect=Smoke'],['xxEFFECT=Spark','FALSE'],['effectXSmoke'],['effect='],['effect=missing'],['effect=1234567890123456'],['effect=Flame','xFALSE'],['effect=Flame\0effect=Smoke']]:run('command',tokens=tokens)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,authoredUses=277,fullRegionComparisons=memory,examples=errors[:8],method='Original GIT handler, current-world getter, emitter bank lookup, enable/disable byte stores and saved-name mutation all execute unchanged with no substitutions. Complete emitter/save/table/world memory regions compared.',limits=['Valid finite emitter pointer table with reserved index0 and readable loaded-bank flags. Existing emitters only; no allocation or particle simulation recovered.','Terminated ASCII names/12 fixed16-byte save slots; substring effect must leave its delimiter-skip pointer within the source token.','Managed replay pending; emitter-state consumption and save lifecycle remain separate.'])
 (B/'reports/native-effect-activation-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-effect-activation-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
