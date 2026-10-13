"""Actual named41f6d0 ->41c120 spawn reset composition, no live game launch."""
import importlib.util,itertools,json
from pathlib import Path
s=importlib.util.spec_from_file_location('reinit',Path(__file__).with_name('gameplay-reinitialization-verify.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
n=r.n;A=r.A;NAME=r.D+0x40000;POSITION=NAME+256;events=r.events;options={};vectors=[];errors=[]
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX

def hook(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if address==0x43c220:r.events.append(['name',n.read(n.unpack('<I',sp+8)[0],64).split(b'\0')[0].decode()]);return
 args=list(n.unpack('<II',sp+4));r.events.append(['Refresh',args,r.probe(n.read(A,0x10d8))]);b=bytearray(n.read(A,0x10d8));r.effects(b,'Refresh',options);n.write(A,b)
 mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EAX,0)
for addr in [0x43c220,0x595af0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=addr,end=addr)

def run(o):
 global options
 options=o;before=r.setup(o);b=before['actor'];r.put(b,0,A);r.put(b,0x1f8,0);r.put(b,0x1fc,1);n.write(A,b)
 n.pack('<I',0x9553d4,0);n.pack('<I',0x93b2a4,0);n.pack('<I',r.WORLD+0x2ae8,0 if o.get('noSystem') else r.SYS);n.pack('<I',r.WORLD+0x2ab4,0xabcdef01)
 n.pack('<II',0x93d500,1,A);n.pack('<I',0x923904,0x43c220);n.pack('<I',0x93d810,A);n.pack('<I',r.CHAR+0xc,NAME+64);n.write(NAME+64,b'Alpha\0')
 name='Player' if o.get('noSystem') else 'Alpha';n.write(NAME,name.encode()+b'\0');n.pack('<3f',POSITION,999,998,997)
 result=n.call(0x41f6d0,[NAME,POSITION,0x7654]);out,ev=r.model(before,o);ev.insert(0,['name',name]);ev.append(['Refresh',[A,0xabcdef01],r.probe(out['actor'])]);r.effects(out['actor'],'Refresh',o)
 after=dict(actor=n.read(A,0x10d8),formation=n.read(r.FORM,len(before['formation'])),origin=list(n.unpack('<III',0x93d620)))
 got=dict(result=result,state=r.summarize(before,after,r.events));want=dict(result=A,state=r.summarize(before,out,ev))
 if got!=want:errors.append(dict(options=o,got=got,want=want))
 vectors.append(dict(options=o,name=name,native=got))

def main():
 for locator,count,column,row in itertools.product([False,True],[0,1],[0,1,7],[0,3]):run(dict(locator=locator,count=count,column=column,row=row,formation=True,slot=(row*3+column)&255))
 for system,accessory in itertools.product([False,True],[-1,12]):run(dict(noSystem=system,accessory=accessory))
 for op,offset,value in [('BeforeReset',0x400,1),('ResetTerrain',0x5c,r.bits(99.25)),('ResetState',0x60,r.bits(-25.5)),('Refresh',0x1fc,0),('Refresh',0x5c,r.bits(17.25))]:run(dict(effects=[dict(operation=op,offset=offset,value=value,size=1 if offset==0x400 else 4)]))
 report=dict(binarySha256=n.sha256,checks=len(vectors),mismatches=len(errors),examples=errors[:3],method='Original41f6d0 executes58a900,440120/43c220 and actual41c120 with4b6b80,51a7c0,5b3620,5b37d0,5b3710. Reinitialization retains its fourteen explicit services and final595af0 is recorded. Complete actor/formation byte deltas, origin, return identity and ordered callback probes compared.',limits=['Existing downstream reinitialization services remain explicit; no whole lifecycle or terrain/animation backend equivalence.','Valid finite prepared spawn/locator/formation records; no actual game world allocation.'])
 (r.BASE/'reports/gameplay-named-reinitialization-tests.json').write_text(json.dumps(report,indent=2),encoding='utf8')
 (r.BASE/'reports/gameplay-named-reinitialization-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=vectors),separators=(',',':')),encoding='utf8');print(json.dumps(report))
 if errors:raise SystemExit(1)
if __name__=='__main__':main()
