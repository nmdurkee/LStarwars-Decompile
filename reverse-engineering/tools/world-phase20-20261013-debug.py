from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');env={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('rows=[];errors=')],str(p),'exec'),env)
c=env['cases'][183];print({k:v for k,v in c.items() if k!='writes'});im=env['Image'](c);ptr=c['ptr'];print('input',im.read(ptr,64).hex());print('coeff',hex(im.W(env['SINE']+((env['U'](c['angle']+0x4000)>>1)&0x7fff)*4)),hex(im.W(env['SINE']+((env['U'](c['angle'])>>1)&0x7fff)*4)))
env['rotate'](im,ptr,c['angle'],c['axis']);print('model',im.read(ptr,64).hex());initial=env['Image'](c);n=env['n']
for a,z,_ in env['REGIONS']:n.write(a,initial.read(a,z))
n.call(0x64ffe0,regs={env['UC_X86_REG_EAX']:ptr,env['UC_X86_REG_ECX']:c['angle']});print('native',n.read(ptr,64).hex())
