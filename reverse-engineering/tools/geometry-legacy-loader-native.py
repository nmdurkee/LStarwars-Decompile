"""Trace original PC scene-loader behavior up to material texture fixup, without graphics/OS execution."""
import importlib.util,json,struct,hashlib
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ECX
cases=[]
for name in ['DROIDTRIFIGHTER','VULTUREDROID']:
 for ext in ['GSC','GHG']:
  src=f'CHARS/{name}/{name}_PC.{ext}';blob=(B/'extracted'/src).read_bytes();nu=struct.unpack_from('<I',blob,0)[0]+4;tail=blob[nu:];n=nx.NativeX86();base=n.DATA+0x10000;n.write(base,tail)
  rel=lambda off:off+struct.unpack_from('<i',blob,off)[0]
  hdr=rel(nu+28);table=rel(hdr+12);count=struct.unpack_from('<I',blob,hdr+16)[0];original=[rel(table+4*i) for i in range(count)]
  n.pack('<I',0x986e9c,n.DATA+0x2000);textures=struct.unpack_from('<I',blob,hdr+4)[0]
  for i in range(textures):n.pack('<I',n.DATA+0x2000+i*4,0x700+i)
  n.pack('<I',n.DATA+0x100,n.DATA+0x90000);n.pack('<I',n.DATA+0x104,n.DATA+0xf0000)
  calls=[];capture={}
  def ret(mu,value):
   st=mu.reg_read(UC_X86_REG_ESP);pc=struct.unpack('<I',mu.mem_read(st,4))[0];mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,st+4);mu.reg_write(UC_X86_REG_EIP,pc)
  def hook(mu,addr,size,user):
   st=mu.reg_read(UC_X86_REG_ESP)
   if addr==0x5e5210:
    calls.append({'textureRegisterArgument':n.unpack('<I',st+4)[0]});ret(mu,0x100+len(calls))
   elif addr==0x5eedf0:
    scene=n.unpack('<I',st+4)[0];mt=n.unpack('<I',scene+12)[0];ptrs=list(n.unpack('<'+str(count)+'I',mt));capture.update({'sceneAddress':scene,'legacyFlag':n.unpack('<I',scene+0x1f4)[0],'materialPointers':ptrs,'allocatorAfter':n.unpack('<I',n.DATA+0x100)[0]});mu.reg_write(UC_X86_REG_EIP,n.STOP)
  n.mu.hook_add(UC_HOOK_CODE,hook);n.call(0x5ef1d0,[n.DATA+0x100,n.DATA+0x104,0],regs={UC_X86_REG_ECX:base},count=1000000)
  expected=[base+x-nu for x in original];stride=original[1]-original[0]
  cases.append({'source':src,'sha256':hashlib.sha256(blob).hexdigest(),'NU20version':struct.unpack_from('<I',blob,nu+8)[0],'materialCount':count,'authoredMaterialStride':stride,'legacyFlagAfterVersionGate':capture['legacyFlag'],'materialPointerTableUnchangedExceptRelocation':capture['materialPointers']==expected,'noNewMaterialAllocationBeforeFixup':capture['allocatorAfter']==n.DATA+0x90000,'textureRegistrationCalls':len(calls),'firstMaterialNativeReadOutsideLegacyRecord':{'function':'0x5eedf0','offsets':[0x298,0x29c],'recordSize':stride} if stride==628 else None})
r={'binarySHA256':n.sha256,'scope':'Original scene loader 0x5ef1d0 with preloaded NU20 bytes; original pointer relocation0x4f4f40 and version gate execute. Texture registration boundary is stubbed; execution stops at entry0x5eedf0 before material fixup. No originals modified, no Windows process.','cases':cases,'passed':all(c['materialPointerTableUnchangedExceptRelocation'] and c['noNewMaterialAllocationBeforeFixup'] for c in cases),'evidence':['decompiled/corpus-expanded/FUN_5ef1d0.c','decompiled/corpus-expanded/FUN_4f4f40.c','decompiled/corpus-expanded/FUN_602370.c','decompiled/corpus-expanded/FUN_5eedf0.c','decompiled/corpus-expanded/FUN_601030.c','decompiled/corpus-expanded/FUN_602550.c'],'finding':'The ordinary PC loader accepts version1 but performs no 628-to708 material expansion before invoking current-layout texture fixup. It retains all authored material pointers and sets scene+0x1f4=1. Current fixup reads material+0x298/+0x29c and writes+0x2c0; current preparation writes+0x2bc. Those offsets exceed628-byte records. Both legacy GSCs have current GHG companions.','limits':['No unsupported layout conversion is invented. No claim that every possible game path ignores or cannot consume these GSCs.','This bounded trace establishes the ordinary loader path only; downstream full graphics execution is not attempted.','The 46 legacy records remain excluded from the current native material feature and uniform survey.']}
(B/'reports/geometry-legacy-loader-native.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
