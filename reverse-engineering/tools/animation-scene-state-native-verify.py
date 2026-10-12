"""Original PC StateAnimEvaluate2, isolated with recovered SALI keyframes."""
from pathlib import Path
exec((Path(__file__).parent/'animation-scene-native-verify.py').read_text().split('inventory=json.loads')[0])
report={'binarySha256':hashlib.sha256(blob).hexdigest(),'procedure':'0x5da480','files':0,'tracks':0,'samples':0,'mismatches':0,'examples':[],'failures':[],'method':'Original state evaluator in isolated x86, with all recovered SALI key times and bytes, forward/backward/end cache indices, key boundary and between-key times. No game process or operating system calls.'}
index=json.loads((BASE/'reports/animation-scene-state-export.json').read_text())
for entry in index['results']:
 if not entry['tracks']:continue
 data=json.loads((BASE/'exports/animation-scene-states'/(entry['source']+'.json')).read_text());report['files']+=1
 for track in data['states']:
  keys=track['keys'];n=len(keys);mu.mem_write(DATA,struct.pack('<HHII',n,track['endFrame'],DATA+0x100,DATA+0x1000));mu.mem_write(DATA+0x100,struct.pack('<'+'f'*n,*[k['frame']for k in keys]));mu.mem_write(DATA+0x1000,bytes(k['value']for k in keys));report['tracks']+=1
  frames=sorted(set([keys[0]['frame']-10,keys[-1]['frame']+10]+[k['frame']+delta for k in keys for delta in [-.01,0,.01]]+[(a['frame']+b['frame'])/2 for a,b in zip(keys,keys[1:])]))
  for f in frames:
   frame=struct.unpack('<f',struct.pack('<f',f))[0];selected=max([0]+[i for i,k in enumerate(keys)if k['frame']<=frame])
   for cache in set([0,n-1,255,selected]):
    try:
     initial=min(cache,n-1);expected={'index':selected,'value':keys[selected]['value'],'changed':int(keys[initial]['value']!=keys[selected]['value'])};mu.context_restore(context);mu.mem_write(OUT,bytes([cache,0]));sp=STACK+0xf000;mu.mem_write(sp,struct.pack('<IIIIf',STOP,DATA,OUT,OUT+1,frame));mu.reg_write(UC_X86_REG_ESP,sp);mu.emu_start(0x5da480,STOP,count=100000)
     if mu.reg_read(UC_X86_REG_EIP)!=STOP:raise RuntimeError('instruction budget')
     observed=bytes(mu.mem_read(OUT,2));actual={'index':observed[0],'value':observed[1],'changed':mu.reg_read(UC_X86_REG_EAX)&255};report['samples']+=1
     if actual!=expected:
      report['mismatches']+=1
      if len(report['examples'])<30:report['examples'].append({'source':entry['source'],'track':track['index'],'frame':frame,'cache':cache,'expected':expected,'actual':actual})
    except Exception as e:report['failures'].append({'source':entry['source'],'track':track['index'],'error':str(e)})
(BASE/'reports/animation-scene-state-native-verification.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2))
