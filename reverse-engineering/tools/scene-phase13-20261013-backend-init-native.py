"""Original backend constructor capture, no CPU or external-call adapters."""
import importlib.util,struct,json,gzip,random
from pathlib import Path
P=Path(__file__).resolve().parent;R=P.parent/'reports';PREFIX='scene-phase13-20261013-backend-init'
s=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(s);s.loader.exec_module(nx);n=nx.NativeX86()
from unicorn.x86_const import UC_X86_REG_ECX,UC_X86_REG_ESP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
c=Cs(CS_ARCH_X86,CS_MODE_32);assembly=[]
for ins in c.disasm(n.read(0x6e1930,0x200),0x6e1930):
 assembly.append({'address':hex(ins.address),'bytes':ins.bytes.hex(),'instruction':ins.mnemonic+' '+ins.op_str})
 if ins.mnemonic=='ret':break
constant=n.read(0x7519a8,4).hex();assert constant=='abaaaa3f'
rng=random.Random(0x6e1930);cases=[];checks=0;errors=[];CTX=n.DATA+0x1000
w=lambda b,o,v:struct.pack_into('<I',b,o,v)
def ck(a,e,label):
 global checks
 checks+=1
 if a!=e and len(errors)<20:errors.append({'label':label,'native':a,'expected':e})
zero=[0,4,0x1a0,0x5f4,0x5fc,0x618,0x61c,0x620,0x624,0x62c,0x638,0x654,0x660,0x668,0x684,0x688,0x68c,0x690,0x694,0x698,0x6a4,0x6a8,0x6ac,0x6b0,0x6e8,0x6ec]
def model(before):
 b=bytearray(before)
 for offset in [0x628,0x630]:w(b,offset,0x3faaaaab)
 for offset in zero:w(b,offset,0)
 for offset in [0x5f0,0x600,0x604,0x69c,0x6a0]:w(b,offset,1)
 for offset in [0x5f8,0x5f9,0x634,0x63c,0x664]:b[offset]=0
 for offset in [0x5fa,0x65c]:b[offset]=1
 for offset in [0x66c,0x6e4]:struct.pack_into('<H',b,offset,1)
 for offset,size in [(0x1a4,0x44c),(8,0x130),(0x138,0x38)]:b[offset:offset+size]=bytes(size)
 for offset in list(range(0x170,0x188,4))+list(range(0x608,0x618,4)):w(b,offset,0)
 w(b,0x158,b[0x65c]);w(b,0x640,0);w(b,0x658,0)
 for offset in range(0x644,0x654,4):w(b,offset,0xffffffff)
 for i in range(4):
  for offset,value in [(0x6b4,0),(0x6c4,0),(0x6d4,0xffffffff),(0x6f0,0)]:w(b,offset+i*4,value)
 return b
for i in range(2048):
 CTX=n.DATA+0x1000+i%4
 before=bytes([i&255])*0x800 if i<256 else rng.randbytes(0x800);n.write(CTX,before);n.pack('<I',CTX-4,0x12345678);n.pack('<I',CTX+0x800,0x87654321);result=n.call(0x6e1930,regs={UC_X86_REG_ECX:CTX});after=n.read(CTX,0x800);ck(after.hex(),model(before).hex(),['all owned and preserved bytes',i]);ck(result,CTX,['original receiver identity',i]);ck(n.mu.reg_read(UC_X86_REG_ESP),n.STACK+0xe004,['constructor ret0',i]);ck(list(n.unpack('<I',CTX-4))+list(n.unpack('<I',CTX+0x800)),[0x12345678,0x87654321],['image guards',i]);cases.append({'beforeHex':before.hex(),'nativeHex':after.hex(),'returnedReceiver':result==CTX})
written=[i for i,(a,b)in enumerate(zip(bytes([0xa5])*0x800,model(bytes([0xa5])*0x800)))if a!=b];preserved=[i for i in range(0x800)if i not in written]
(R/(PREFIX+'-assembly.json')).write_text(json.dumps({'binarySHA256':n.sha256,'functions':{'0x6e1930':assembly},'constant7519a8Hex':constant},indent=2)+'\n');(R/(PREFIX+'-native-fixtures.json.gz')).write_bytes(gzip.compress(json.dumps({'cases':cases},separators=(',',':')).encode(),mtime=0));report={'schema':'original-backend-constructor-v1','binarySHA256':n.sha256,'passed':not errors,'checks':checks,'errors':errors,'counts':{'constructorCases':2048,'unalignedReceiverCases':1536,'retainedPortableReplayCases':2048,'preparedManagedAssertions':4096},'adapters':{},'writtenOffsets':written,'preservedOffsets':preserved,'limits':['Original6e1930 and actual memset6e6950 run unchanged; no helper, device, arithmetic or COM adapters.','Receiver is a resolved writable0x800-byte image. All source bytes are raw and all unassigned image bytes remain unchanged. Original finite aspect constant7519a8 is exactly3faaaaab.','Constructor clears device pointer, dimensions, viewport, selected handles and four target cache cells. It does not produce a live device, populate real target dimensions or initialize separate render-state/viewport calibration globals.','Original pointer return is represented as receiver identity in portable source. Native/Python differential passed; managed execution pending.']};(R/(PREFIX+'-native-validation.json')).write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items()if k not in ['writtenOffsets','preservedOffsets']}));raise SystemExit(0 if not errors else 1)
