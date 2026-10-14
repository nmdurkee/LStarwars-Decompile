"""Original whole container open through real lookup/allocators/parent/memory seek; only final lock/open/diagnostic leaves."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase91-20261013-verify.py').read_text().split('\nfor text,needle')[0])
exec(Path(__file__).with_name('script-phase92-20261013-verify.py').read_text().split('\nfor method,id')[0])
CON=D+0x3000;PATH=DATA;ROWS=D+0x6000;HASHES=D+0x4000;PARENTPATH=D+0x1100;FILEDATA=D+0x8000;AVAILABLE=0x90fba4;ACTIVE=0x91ce60;PARENTACTIVE=0x917844;RAWBASE=0x88ab40;FLAG=0x91ee84;segments=[(COMP,960),(CON,256),(PATH,32),(PARENTPATH,32),(ROWS,16),(HASHES,4),(LOCK,4),(BASEOFFSET,4),(TABLE,400),(AVAILABLE,4),(ACTIVE,4),(PARENTACTIVE,4),(RAWBASE,8),(FLAG,4)];cases=[];checks=0;errors=[]
def parentSeek93(handle,low,high):
 assert handle==0x400
 cursor=(rd(TABLE)+low)&0xffffffff;wd(TABLE+8,cursor);value=(cursor-rd(TABLE))&0xffffffff;return value|(0xffffffff00000000 if value&0x80000000 else 0)
def open93(container,path,mode):
 if mode:return 0
 entry=find91(container,path);offset=(entry<<4)&0xffffffff
 if signed(entry)<0 or not rd(rd(container+8)+offset+4):port92('Diagnostic',[path],True);return 0
 index=record92()
 if index==0xffffffff:port92('Diagnostic',[],True);return 0
 parentIndex=parent92(container,index);record=COMP+index*48
 if parentIndex==0xffffffff:wd(record+36,0);return 0
 parent=container+(parentIndex+3)*16;ensure92(container,parentIndex);wd(record,container);value=offset92(container,rd(rd(container+8)+offset));wd(record+8,value[0]);wd(record+12,value[1]);wd(record+16,value[0]);wd(record+20,value[1]);wd(record+24,rd(rd(container+8)+offset+4));wd(record+28,rd(rd(container+8)+offset+8));wd(record+40,rd(rd(container+8)+offset+12));wd(record+32,parentIndex);wd(parent+8,rd(record+16));wd(parent+12,rd(record+20))
 budget=0
 while True:
  value=parentSeek93(rd(parent),rd(record+8),rd(record+12));budget+=1;assert budget<20
  if signed(value>>32)>=0:break
  port92('Diagnostic',[],True)
 if rd(record+40)==2:wd(ACTIVE,record);wd(PARENTACTIVE,parent);wd(RAWBASE,rd(record+8));wd(RAWBASE+4,rd(record+12));wd(AVAILABLE,0)
 return index+0x800

def hook93(mu,address,size,data):
 if address!=0x4ef7b0:return
 sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];args=[n.unpack('<I',sp+4)[0]]if ret==0x4f9d6d else[];value=port92('Diagnostic',args,False);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook93)
def execute93(c):
 global shadow,checks,events,config
 config=c
 for p,z in segments:n.write(p,bytes([0xa5])*z)
 n.write(PATH,b'file.dat\0'+bytes(23));n.write(PARENTPATH,b'parent.bin\0'+bytes(21));n.pack('<I',FLAG,0);n.pack('<I',LOCK,1);n.pack('<I',BASEOFFSET,c.get('base',0));n.pack('<I',CON,c.get('marker',0));n.pack('<I',CON+4,1);n.pack('<I',CON+8,ROWS);n.pack('<I',CON+16,0);n.pack('<I',CON+28,HASHES);n.pack('<I',CON+32,0);n.pack('<I',CON+40,0)
 h=0x811c9dc5
 for b in b'FILE.DAT':h=((h^b)*0x199933)&0xffffffff
 n.pack('<I',HASHES,h if c.get('found',True)else(h+1)&0xffffffff);n.pack('<4I',ROWS,c.get('offset',17),c.get('packed',17),c.get('plain',31),c.get('flag',2));n.pack('<h',CON+178,0);n.pack('<I',CON+184,PARENTPATH)
 for i in range(20):n.pack('<I',COMP+36+i*48,0 if i in c.get('freeRecords',[0])else 7)
 for i in range(8):n.pack('<I',CON+52+i*16,0xffffffff if i in c.get('freeParents',[0])else 7);n.pack('<I',CON+48+i*16,c.get('cachedHandle',0))
 n.pack('<5I',TABLE,FILEDATA,FILEDATA+1023,FILEDATA+7,0,1);initial=snap();shadow={r['address']+i:b for r in initial for i,b in enumerate(bytes.fromhex(r['bytes']))}
 for i in range(256):shadow[LOCAL+i]=0
 events=[];want=open93(CON,PATH,c.get('mode',0));model=snap(True);me=events.copy();events=[];actual=n.call(0x4f9bd0,[CON,PATH,c.get('mode',0)],count=3000000);final=snap();ne=events.copy()
 for group,a,b in [('return',actual,want),('images',final,model),('events',ne,me)]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[x for x,y in zip(a,b)if x!=y][:1],model=b if group!='images'else[y for x,y in zip(a,b)if x!=y][:1]))
 cases.append(dict(context=c,inputs=dict(container=CON,path=PATH,mode=c.get('mode',0)),initial=initial,returnValue=actual,final=final,nativeEvents=ne))
for freeRecords,freeParents,cached,flag,marker,offset in itertools.product([[0],[3],[19],[]],[[0],[7],[]],[0,0x400],[0,1,2,3],[0,0xfffffffe],[0,17]):execute93(dict(freeRecords=freeRecords,freeParents=freeParents,cachedHandle=cached,flag=flag,marker=marker,offset=offset,openResult=0x400))
for mode,found,packed in itertools.product([0,1,2,0xffffffff],[False,True],[0,17]):execute93(dict(mode=mode,found=found,packed=packed,openResult=0x400))
#A negative64-bit parent seek causes diagnostic retry; repair base into prepared nonnegative position.
execute93(dict(offset=0x80000000,base=0,openResult=0x400,patches={'Diagnostic':[[COMP+8,7],[COMP+12,0]]}))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:1],managedExecution=False,newEntries=1,ports=['EnterCriticalSectionIAT7510b8','LeaveCriticalSectionIAT7510b4','parentGameOpen4fa3f0','diagnostic4ef7b0'],closure='Whole4f9bd0→original4f9aa0/4f76f0/4efdf0/record+parent allocators/lock wrappers/lazy parent/base/memory seek; final lock/open/diagnostic leaves only')
(nm.BASE/'reports/script-phase93-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase93-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}));print(json.dumps(errors[:1]))
