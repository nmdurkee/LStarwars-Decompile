import importlib.util,json,struct,itertools,hashlib,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);n=m.NativeX86();B=m.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX
W1=0x93d858;W2=0x942a04;SIZE=0x51ac;LEVELS=D+0x10000;AREAS=D+0x20000;SAVE=D+0x80000;A1=D+0x30000;A2=D+0x31000
PREFIX=n.read(0x75a208,8).split(b'\0')[0];SEP=n.read(0x75a204,4).split(b'\0')[0];calls=[];rows=[];errors=[];groups={}
ADAPTERS={0x566630:1,0x55f6c0:1,0x547ba0:1,0x6df940:0,0x48ce00:1}
loaderLoaded=0

def hook(mu,address,size,user):
 if address not in ADAPTERS:return
 sp=mu.reg_read(UC_X86_REG_ESP);args=list(n.unpack('<'+'I'*ADAPTERS[address],sp+4)) if ADAPTERS[address] else []
 calls.append(dict(address=hex(address),args=args))
 if address==0x48ce00:n.pack('<I',args[0]+0x110,loaderLoaded)
 mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
n.mu.hook_add(UC_HOOK_CODE,hook)
def put(b,o,v):struct.pack_into('<I',b,o,v&0xffffffff)
def get(b,o):return struct.unpack_from('<I',b,o)[0]
def signed(v):return v if v<0x80000000 else v-0x100000000
def opts(o):
 p=dict(target=0,level=1,loaded=0,cached=1,force=0,otherLoaded=1,otherCached=1,area=2,chapter=3,save=4,arenaLength=64,directory='EPISODE_I/TEST',name='Test_A',current=0,staging=0,currentArea=2,areaFlags=0,previousArea=3,end1=0x10130040,end2=0x10131040,reserve=0x1000,loaderLoaded=1);p.update(o);return p

def setup(o):
 global calls,loaderLoaded
 calls=[];loaderLoaded=o['loaderLoaded'];n.write(D,bytes(0x100000));n.write(W1,bytes([0xa5])*SIZE);n.write(W2,bytes([0x5a])*SIZE)
 for w,a,loaded,cached in [(W1,A1,o['loaded'] if o['target']==0 else o['otherLoaded'],o['cached'] if o['target']==0 else o['otherCached']),(W2,A2,o['loaded'] if o['target']==1 else o['otherLoaded'],o['cached'] if o['target']==1 else o['otherCached'])]:
  n.pack('<III',w+0x100,a,a+32,a+o['arenaLength']);n.pack('<I',w+0x110,loaded);n.pack('<i',w+0x11c,cached);n.write(a,bytes([0x6d])*256)
 n.pack('<I',0x951b78,LEVELS);n.pack('<I',0x951354,AREAS);n.pack('<I',0x87b2cc,SAVE);n.pack('<I',0x87b71c,o['force']);n.pack('<I',0x802c54,[W1,W2][o['current']]);n.pack('<I',0x802c58,[W1,W2][o['staging']]);n.pack('<I',0x802c68,0xfedcba98);n.pack('<i',0x803784,o['currentArea']);n.pack('<i',0x93d848,o['level']);n.pack('<I',0x93d84c,0xabcdef12);n.pack('<I',0x9248b4,o['reserve'])
 # A padded table permits native signed indexing; no claim those indices occur in shipped content.
 for index in [-1,0,1,2]:
  record=LEVELS+index*0x130;n.write(record,o['directory'].encode()+b'\0');n.write(record+0x40,o['name'].encode()+b'\0');n.pack('<b',record+0xa3,o['area']);n.pack('<b',record+0xc8,o['save'])
 n.pack('<b',AREAS+o['area']*0x9c+0x86,o['chapter']);n.pack('<B',AREAS+o['currentArea']*0x9c+0x7a,o['areaFlags'])
 return [bytearray(n.read(w,SIZE)) for w in [W1,W2]],[bytearray(n.read(a,256)) for a in [A1,A2]]

def initialize(o,worlds,arenas,t):
 w=[W1,W2][t];b=worlds[t];expected=[dict(address='0x566630',args=[0])]
 if get(b,0x110)!=0:
  if signed(get(b,0x11c))==o['level'] and o['area']!=-1 and not o['force']:return 0,expected
  expected.append(dict(address='0x55f6c0',args=[w]))
 other=1-t
 if o['force'] and get(worlds[other],0x110)!=0 and signed(get(worlds[other],0x11c))==o['level']:expected.append(dict(address='0x55f6c0',args=[[W1,W2][other]]))
 start=get(b,0x100);end=get(b,0x108);b[:]=bytes(SIZE);put(b,0x100,start);put(b,0x104,start);put(b,0x108,end)
 length=signed((end-start)&0xffffffff)
 if length>0:arenas[t][:length]=bytes(length)
 put(b,0x11c,o['level']);put(b,0x120,-1);put(b,0x124,-1)
 if o['level']!=-1:
  put(b,0x128,LEVELS+o['level']*0x130);put(b,0x120,o['area'])
  if o['area']!=-1:put(b,0x12c,AREAS+o['area']*0x9c);put(b,0x124,o['chapter'])
  for off in [0x2a98,0x2a9c,0x2aa0,0x2aa4,0x2aa8]:put(b,off,-1)
  put(b,0x130,0 if o['save']==-1 or o['save']>=12 else SAVE+o['save']*0x2e28)
  directory=PREFIX+o['directory'].encode();base=directory+SEP+o['name'].encode();b[:len(directory)+1]=directory+b'\0';b[0x80:0x80+len(base)+1]=base+b'\0';expected.append(dict(address='0x547ba0',args=[w]))
 return 1,expected

def run(kind,inputs):
 o=opts(inputs);worlds,arenas=setup(o);wantCalls=[];wantReturn=None;globalsBefore={a:n.unpack('<I',a)[0] for a in [0x802c54,0x802c58,0x802c68,0x93d84c]};wantGlobals=globalsBefore.copy()
 if kind=='Initialize':wantReturn,wantCalls=initialize(o,worlds,arenas,o['target']);got=n.call(0x55ffb0,[[W1,W2][o['target']],o['level']])
 elif kind=='OtherCached':
  b=worlds[1-o['target']];wantReturn=get(b,0x11c) if get(b,0x110) else 0xffffffff;got=n.call(0x55f500,[[W1,W2][o['target']]])
 elif kind=='Stage':
  t=o['staging'];wantCalls=[dict(address='0x6df940',args=[])]
  if o['staging']==o['current'] and (o['currentArea']==-1 or not(o['areaFlags']&8)):t=1-t
  wantGlobals[0x802c58]=[W1,W2][t];ret,c=initialize(o,worlds,arenas,t);wantCalls+=c
  if ret:
   wantCalls.append(dict(address='0x48ce00',args=[[W1,W2][t]]));put(worlds[t],0x110,o['loaderLoaded'])
  wantGlobals[0x93d84c]=0xffffffff
  if get(worlds[t],0x110):wantGlobals[0x802c68]=o['level']&0xffffffff
  got=n.call(0x560630)
 else:
  put(worlds[0],0x108,o['end1']);put(worlds[1],0x108,o['end2']);n.pack('<I',W1+0x108,o['end1']);n.pack('<I',W2+0x108,o['end2'])
  if o['currentArea']!=-1 and o['currentArea']!=o['previousArea'] and o['areaFlags']&8:
   wantGlobals[0x802c54]=W1;wantGlobals[0x802c58]=W1
   if o['end2']>o['end1']:put(worlds[0],0x108,o['end2']-o['reserve']);put(worlds[1],0x108,o['end1'])
  elif (o['currentArea']==-1 or not(o['areaFlags']&8)) and o['end2']<o['end1']:put(worlds[0],0x108,o['end2']);put(worlds[1],0x108,o['end1']+o['reserve'])
  got=n.call(0x55f470,[o['currentArea'],o['previousArea']])
 actualWorlds=[n.read(w,SIZE) for w in [W1,W2]];actualArenas=[n.read(a,256) for a in [A1,A2]];actualGlobals={a:n.unpack('<I',a)[0] for a in wantGlobals}
 bad=[]
 if wantReturn is not None and got!=(wantReturn&0xffffffff):bad.append('return')
 if calls!=wantCalls:bad.append('call trace')
 for i in range(2):
  if actualWorlds[i]!=worlds[i]:bad.append('world'+str(i)+':'+str(next((j for j,(a,b) in enumerate(zip(actualWorlds[i],worlds[i])) if a!=b),-1)))
  if actualArenas[i]!=arenas[i]:bad.append('arena'+str(i))
 if actualGlobals!=wantGlobals:bad.append('globals')
 if bad:errors.append(dict(kind=kind,options=o,bad=bad,got=got,calls=calls,wantCalls=wantCalls))
 rows.append(dict(kind=kind,options=o,nativeReturn=got if wantReturn is not None else None,worldSha256=[hashlib.sha256(b).hexdigest() for b in actualWorlds],arenaSha256=[hashlib.sha256(b).hexdigest() for b in actualArenas],globals={hex(k):v for k,v in actualGlobals.items()},calls=calls.copy()));groups[kind]=groups.get(kind,0)+1

def main():
 for target,loaded,cached,force,otherLoaded,otherCached,level in itertools.product([0,1],[0,1],[0,1],[0,1],[0,1],[0,1],[-1,0,1]):run('Initialize',dict(target=target,loaded=loaded,cached=cached,force=force,otherLoaded=otherLoaded,otherCached=otherCached,level=level))
 for area,chapter,save,length in itertools.product([-128,-2,-1,0,2,127],[-128,-1,0,127],[-128,-2,-1,0,11,12,127],[-64,0,1,64,256]):run('Initialize',dict(area=area,chapter=chapter,save=save,arenaLength=length))
 for target,loaded,cached in itertools.product([0,1],[0,1,0x80000000],[-1,0,1,0x7fffffff]):run('OtherCached',dict(target=target,otherLoaded=loaded,otherCached=cached))
 for current,staging,currentArea,flags,loaded,force,loadResult in itertools.product([0,1],[0,1],[-1,2],[0,8],[0,1],[0,1],[0,1]):run('Stage',dict(current=current,staging=staging,currentArea=currentArea,areaFlags=flags,loaded=loaded,otherLoaded=loaded,force=force,loaderLoaded=loadResult))
 for currentArea,previousArea,flags,end1,end2,reserve in itertools.product([-1,2],[2,3],[0,8],[0,0x7fffffff,0x80000000,0xffffffff],[0,0x7fffffff,0x80000000,0xffffffff],[0,1,0x1000]):run('SwapArenas',dict(currentArea=currentArea,previousArea=previousArea,areaFlags=flags,end1=end1,end2=end2,reserve=reserve))
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullWorldComparisons=len(rows)*2,fullArenaComparisons=len(rows)*2,examples=errors[:8],adapters=[dict(address=hex(a),args=c,behavior='Records call; no-op, except48ce00 sets prepared world+110 to loaderLoaded') for a,c in ADAPTERS.items()],method='Original4 native functions, original path copy/append and memset; adapted external resource/teardown/audio/platform callees. Full21,? byte worlds and256-byte arenas compared against an independent Python contract.',limits=['No original resource load/unload executes.55f6c0 and547ba0 side effects are external.48ce00 loader result is a prepared adapter.','World+110 remains zero after initialization; returned1 means rebuild requested, not load success.','Signed negative area/save values use padded readable native table backing. No pointer target at computed save slot is dereferenced.','Paths fit native128-byte string slots; malformed inputs that would overflow are outside this fixture.','Managed replay remains separate from native Python contract validation.'])
 report['method']=report['method'].replace('21,?','20908')
 (B/'reports/world-loading-20261013-native-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/world-loading-20261013-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,prefix=PREFIX.decode(),separator=SEP.decode(),cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
