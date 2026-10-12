"""Bounded original face-on transform callback validation and preserved assembly."""
import importlib.util,json,struct,math
from pathlib import Path
P=Path(__file__).resolve().parent;sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=nx.NativeX86(); uploads=[]; states=[]
def ret(mu):
 sp=mu.reg_read(UC_X86_REG_ESP);target=struct.unpack('<I',mu.mem_read(sp,4))[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,target)
def hook(mu,addr,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP)
 if addr==0x6e5750:
  reg,p,count=n.unpack('<3I',sp+4);num=16 if reg in (0x50,0x55) else 4
  uploads.append({'register':reg,'nativeVectorCount':count,'values':list(n.unpack('<'+str(num)+'f',p))});ret(mu)
 elif addr==0x6e5340:states.append(list(n.unpack('<2I',sp+4)));ret(mu)
 elif addr==0x5f8930:states.append('restore-material-depth-state');ret(mu)
n.mu.hook_add(UC_HOOK_CODE,hook)
n.pack('<I',0x2854c20,n.DATA+0x8000)
n.pack('<I',n.DATA+0x8040,0)
rows=[];errs=[]
for i in range(12):
 a=i*.27;c=math.cos(a);s=math.sin(a);op=[.25,1,1.2][i%3];scale=.5+i*.1
 matrix=[c,0,s,0,0,1,0,0,-s,0,c,0,i*.3,-i*.2,i*.5,op]
 view=[c,s,0,0,-s,c,0,0,0,0,1,0,0,0,0,1]
 packet=struct.pack('<33f',*(matrix+[scale]+view));n.write(n.DATA,packet);matrix=list(struct.unpack('<16f',packet[:64]));view=list(struct.unpack('<16f',packet[68:]));scale=struct.unpack('<f',packet[64:68])[0]
 tint=[.7,.8,.9,.6];n.pack('<4f',0x986ea0,*tint);tint=list(n.unpack('<4f',0x986ea0));uploads.clear();states.clear();n.call(0x5fda20,[n.DATA])
 clean=matrix[:];translation=matrix[12:15]+[1];clean[12:15]=[0,0,0];clean[15]=1
 tr=lambda x:[x[j*4+k] for k in range(4) for j in range(4)]
 expected={0x50:tr(clean),0x59:translation,0x54:[scale,1,0,0],0x55:tr(view),0x28:tint[:3]+[tint[3]*matrix[15] if matrix[15]<1 else tint[3]]}
 for u in uploads:
  e=expected[u['register']]
  if any(abs(v-w)>1e-7 for v,w in zip(u['values'],e)):errs.append({'case':i,'register':u['register']})
 rows.append({'case':i,'opacity':matrix[15],'scale':scale,'uploads':uploads[:],'stateCalls':states[:]})
asm='\n'.join(f'{i.address:08x} {i.mnemonic} {i.op_str}' for i in Cs(CS_ARCH_X86,CS_MODE_32).disasm(n.read(0x608000,0x3c1),0x608000))+'\n'
(P.parent/'reports/geometry-native-material-callback.asm').write_text(asm)
r={'binarySha256':n.sha256,'callback':'0x5fda20','cases':len(rows),'uploadChecks':sum(len(r['uploads']) for r in rows),'passed':not errs,'errors':errs,'rows':rows,'limits':['Only upload and render-state boundaries are intercepted. Original transpose and alpha arithmetic run unchanged.','Native tint upload passes count 4; only the first four floats consumed by reflected kTint are compared.','Shader assembly math is decoded, not GPU rasterization compared.']}
(P.parent/'reports/geometry-billboard-native-validation.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k!='rows'},indent=2))
