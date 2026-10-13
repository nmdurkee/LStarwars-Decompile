from pathlib import Path
src=Path(__file__).with_name('movement-phase4-20261013-native.py').read_text().split('# Guards, flags, formation byte boundaries')[0]
exec(compile(src,str(Path(__file__).with_name('movement-phase4-20261013-native.py')),'exec'))
hits=[]
def trace(mu,a,s,u):
 if 0x51c000<=a<=0x51d500:hits.append(hex(a))
n.mu.hook_add(UC_HOOK_CODE,trace,begin=0x51c000,end=0x51d500)
run('origin',dict(formation=True,owner=True,mutateFormation=True),[],False,.125)
print(json.dumps({'events':events,'errors':errors,'hits':hits[:300]}))
