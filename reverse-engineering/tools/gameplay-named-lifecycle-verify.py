"""Named activation41f6d0/deactivation414c50 with actual mission/name/script helpers."""
import importlib.util,json,copy,itertools,struct
from pathlib import Path
s=importlib.util.spec_from_file_location('activation',Path(__file__).with_name('gameplay-activation-verify.py'));a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
b=a.a;n=a.n;BASE=a.BASE;D=a.D;MISSION=D+0x80000;POSITION=D+0x81000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP
checks={};errors=[];vectors=[];executed=set();options={};initial_images=[];image_ids={}
def word(image,p):return struct.unpack_from('<I',image,p)[0]
def put(image,p,value,size=4):image[p:p+size]=(value&((1<<(size*8))-1)).to_bytes(size,'little')
def effect(images,world,name,o):
 for e in o.get('effects',[]):
  if e['operation']!=name:continue
  if e.get('world')=='refresh':world['refresh']=e['value']
  elif e.get('world')=='reset':world['reset'][e['index']]=e['value']
  else:put(images[e.get('actor',0)],e['offset'],e['value'],e.get('size',4))
def extra_hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);arg=lambda i:n.unpack('<I',sp+4*(i+1))[0]
 names={0x52f800:'resetState',0x5728a0:'resetTerrain',0x572660:'clearTerrain',0x595af0:'refresh'};name=names[address];actor=b.aid(arg(1) if name=='resetState' else arg(0));image=n.read(b.actor(actor),0x10d8)
 args=[int(bool(arg(0))),actor,arg(3),arg(4)] if name=='resetState' else [actor,arg(1)] if name in ['clearTerrain','refresh'] else [actor]
 b.events.append([name,args,[word(image,p) for p in [0x5c,0x60,0x64,0x1fc]]])
 images=[bytearray(n.read(b.actor(i),0x10d8)) for i in range(8)];world=dict(refresh=n.unpack('<I',a.WORLD+0x2ab4)[0],reset=list(n.unpack('<III',0x93b0cc)));effect(images,world,name,options)
 for i,image in enumerate(images):n.write(b.actor(i),image)
 n.pack('<I',a.WORLD+0x2ab4,world['refresh']);n.pack('<III',0x93b0cc,*world['reset']);b.ret(mu,0)
for addr in [0x52f800,0x5728a0,0x572660,0x595af0]:n.mu.hook_add(UC_HOOK_CODE,extra_hook,begin=addr,end=addr)
def trace(mu,address,size,user):executed.add(address)
for start,end in [(0x41f6d0,0x41fa00),(0x414c50,0x414cc0)]:n.mu.hook_add(UC_HOOK_CODE,trace,begin=start,end=end-1)
def phys_delta(before,after):
 result=[]
 for ix,(old,new) in enumerate(zip(before,after)):
  changes=[]
  for p in range(0,len(old),4):
   if 0x2c8<=p<0x400:continue # typed ScriptPacket/activation snapshot is authoritative
   if old[p:p+4]!=new[p:p+4]:changes.append([p,word(new,p)])
  if changes:result.append([ix,changes])
 return result
def setup(o,name,position):
 global options
 options=o;c=a.setup([],o);n.write(MISSION,bytes(0x1200));n.pack('<I',0x9553d4,MISSION if o.get('missionState',True) else 0);n.pack('<B',MISSION+0x1d,o.get('missionEnabled',0));n.pack('<I',MISSION+4,o.get('missionPointer',0x12345678));n.pack('<I',0x93b2a4,o.get('restricted',0));n.pack('<I',a.WORLD+0x2ae8,b.SYS if c['system'] else 0);n.pack('<I',a.WORLD+0x2ab4,0xabcdef01)
 n.pack('<III',0x93d620,0x11111111,0x22222222,0x33333333);n.pack('<III',0x93b0cc,*o.get('reset',[0,0,0]))
 for i in range(8):n.pack('<HH',b.actor(i)+0x58,0x3456,0x789a);n.pack('<H',b.actor(i)+0x27a,0xbcde)
 if name is not None:n.write(b.TEXT,name.encode()+b'\0')
 ptr=0
 if position:
  if 'actor' in position:ptr=b.actor(position['actor'])+position['offset']
  else:ptr=POSITION;n.pack('<III',ptr,*position['words'])
 return c,ptr
def run(kind,name,o=None,position=None,angle=0x8765):
 o=o or {};c,ptr=setup(o,name,position);before=a.snapshot();images=[bytearray(n.read(b.actor(i),0x10d8)) for i in range(8)];world=dict(refresh=0xabcdef01,origin=[0x11111111,0x22222222,0x33333333],reset=o.get('reset',[0,0,0]).copy());out=copy.deepcopy(before);new=copy.deepcopy(images);ev=[];selected=-1
 def call(op,ix,args):ev.append([op,args,[word(new[ix],p) for p in [0x5c,0x60,0x64,0x1fc]]]);effect(new,world,op,o)
 def copyv(image,to,fr):image[to:to+12]=image[fr:fr+12]
 mission=o.get('missionState',True) and o.get('missionEnabled',0)!=0 and o.get('missionPointer',0x12345678)!=0
 if not mission and name is not None:
  ref=-1
  if c['callback']:ev.append(['name',name]);ref=b.resolve_name(c,name)
  ix=c['actors'][ref]['world'] if ref>=0 else -1
  if ix>=0 and (not o.get('restricted',0) or word(new[ix],0x1f8)&0x400) and (kind=='deactivate' or not word(new[ix],0x1fc)&0x1000):
   image=new[ix]
   if kind=='deactivate':a.deactivate(out,c,o,ev,ix);put(image,0x1fc,out['actors'][ix]['active']);put(image,0x406,out['actors'][ix]['phase'],1)
   else:
    selected=ix
    if image[0x400]==255:
     put(image,0x1fc,word(image,0x1fc)|0x1000);out['actors'][ix]['active']=word(image,0x1fc);a.change(out,c,o,ev,ix,'Base')
     if position:
      for j in range(3):put(image,0x5c+4*j,word(new[position['actor']],position['offset']+4*j) if 'actor' in position else position['words'][j])
      for at in [0x27a,0x58,0x5a]:put(image,at,angle,2)
      call('resetState',ix,[int(c['system']),ix,255,1]);copyv(image,0x80,0x5c);copyv(image,0x98,0x5c);world['origin']=[word(image,0x80+4*j) for j in range(3)];copyv(image,0x8c,0x80)
      for at in [0x1cc,0x1b4,0x10bc]:copyv(image,at,0x5c)
      for j,v in enumerate(world['reset']):put(image,0xdf8+4*j,v);put(image,0x68+4*j,v)
      call('resetTerrain',ix,[ix]);call('clearTerrain',ix,[ix,0])
    else:
     ev.append(['reinitialize',ix,c['system']])
     if 'reinitializeGroup' in o:out['actors'][ix]['group']=o['reinitializeGroup']
    call('refresh',ix,[ix,world['refresh']]);out['actors'][ix]['active']=word(image,0x1fc)
 result=n.call(0x41f6d0 if kind=='activate' else 0x414c50,[b.TEXT if name is not None else 0,ptr,angle] if kind=='activate' else [b.TEXT if name is not None else 0]);after=[n.read(b.actor(i),0x10d8) for i in range(8)];got=dict(result=b.aid(result) if kind=='activate' else None,delta=a.delta(before,a.snapshot()),physical=phys_delta(images,after),origin=list(n.unpack('<III',0x93d620)),reset=list(n.unpack('<III',0x93b0cc)),refresh=n.unpack('<I',a.WORLD+0x2ab4)[0],events=b.events.copy());want=dict(result=selected if kind=='activate' else None,delta=a.delta(before,out),physical=phys_delta(images,new),origin=world['origin'],reset=world['reset'],refresh=world['refresh'],events=ev);checks[kind]=checks.get(kind,0)+1
 if got!=want:errors.append(dict(kind=kind,name=name,options=o,position=position,angle=angle,got=got,want=want))
 physical_input=[[[p,word(image,p)] for p in range(0,len(image),4) if not 0x2c8<=p<0x400 and word(image,p)] for image in images]
 key=json.dumps(physical_input,separators=(',',':'))
 if key not in image_ids:image_ids[key]=len(initial_images);initial_images.append(physical_input)
 vectors.append(dict(kind=kind,name=name,options=o,position=position,angle=angle,imageSet=image_ids[key],native=got))
def main():
 base=dict(actorOverrides={'0':dict(active=1,spawn=255)})
 for kind,name in itertools.product(['activate','deactivate'],[None,'Alpha','aLpHa','order66','Player','Player_2','Player0','missing']):run(kind,name,base,dict(words=[b.bits(12.25),b.bits(-4.5),b.bits(9.75)]))
 for kind,enabled,present,missionptr,restricted,flags,active,spawn in itertools.product(['activate','deactivate'],[0,1],[False,True],[0,0x12345678],[0,1],[0,0x400],[0,1,0x1001],[0,255]):
  run(kind,'Alpha',dict(missionEnabled=enabled,missionState=present,missionPointer=missionptr,restricted=restricted,actorOverrides={'0':dict(active=active,flags=flags,spawn=spawn)}))
 for position,angle in itertools.product([None,dict(words=[b.bits(1.25),0x80000000,0x7fc01234]),dict(actor=0,offset=0x58),dict(actor=0,offset=0x5c),dict(actor=0,offset=0x60),dict(actor=1,offset=0x5c)],[0,32768,65535]):run('activate','Alpha',base,position,angle)
 for op,offset,value in [('resetState',0x5c,b.bits(123.5)),('resetTerrain',0x60,b.bits(45.75)),('clearTerrain',0x64,b.bits(-6.5)),('refresh',0x1fc,0)]:run('activate','Alpha',dict(**base,effects=[dict(operation=op,offset=offset,value=value)]),dict(words=[1,2,3]))
 for op in ['resetState','resetTerrain','clearTerrain']:run('activate','Alpha',dict(**base,effects=[dict(operation=op,world='refresh',value=0x12345678),dict(operation=op,world='reset',index=1,value=b.bits(4.5))]),dict(words=[1,2,3]))
 for system,callback,alias in itertools.product([False,True],[False,True],[-1,0,1]):run('activate','Player0',dict(system=system,callback=callback,actorOverrides={'1':dict(active=1,spawn=255,world=alias),'0':dict(active=1,spawn=255)}),dict(actor=0,offset=0x58))
 for attached,flags,scriptkind in itertools.product([-1,7],[0x400,0x4400],[0,1,2]):run('deactivate','Alpha',dict(actorOverrides={'0':dict(active=1,flags=flags)},attached=[attached]+[-1]*7,scriptKinds=[scriptkind]*8))
 from capstone import Cs,CS_ARCH_X86,CS_MODE_32
 d=Cs(CS_ARCH_X86,CS_MODE_32);functions=[]
 for start,size in [(0x41f6d0,0x300),(0x414c50,0x70)]:
  ins=[]
  for i in d.disasm(n.read(start,size),start):
   if i.mnemonic=='int3':break
   ins.append(dict(address=hex(i.address),bytes=i.bytes.hex(),mnemonic=i.mnemonic,operands=i.op_str,executed=i.address in executed))
  functions.append(dict(address=hex(start),instructions=ins))
 report=dict(binarySha256=n.sha256,checks=sum(checks.values()),groups=checks,mismatches=len(errors),examples=errors[:3],instructionCoverage={p['address']:dict(total=len(p['instructions']),executed=sum(i['executed'] for i in p['instructions']),missing=[i['address'] for i in p['instructions'] if not i['executed']]) for p in functions})
 (BASE/'reports/gameplay-named-lifecycle-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8');(BASE/'reports/gameplay-named-lifecycle-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,typeNames=b.TYPE_NAMES,initialPhysicalImages=initial_images,cases=vectors),separators=(',',':')),encoding='utf8');(BASE/'reports/gameplay-named-lifecycle-assembly.json').write_text(json.dumps(dict(binarySha256=n.sha256,functions=functions),indent=2),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
