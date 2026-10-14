from pathlib import Path
p=Path(__file__).with_name('world-phase33-20261013-verify.py');env={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('\ncases=[]')],str(p),'exec'),env)
for life in [0,0x80000000,1,0x80000001,env['bits'](0.5),env['bits'](-0.5)]:
 c=env['seed']();c['writes'] += [env['byte'](env['PHYS']+0x2f0,0),env['word'](env['PHYS']+0xa4,life)];im=env['Image'](c)
 for a,z,_ in env['REGIONS']:env['n'].write(a,im.read(a,z))
 env['n'].call(0x656080,[c['cue'],c['time'],c['physical'],c['emitter'],c['latch']]);print(hex(life),hex(env['n'].unpack('<I',env['EM']+0x2cc)[0]))
