import importlib.util,json,struct,itertools,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('gizmo',Path(__file__).with_name('native-gizmo-conditions-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q)
n=q.n;B=q.B;D=q.D
ROOT=D+0x20000;ARGS=D+0x20100;ACTIVE=D+0x21000;VISIBLE=D+0x21010;ALTERNATE=D+0x21020;TEXTS=D+0x22000
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
NAMES=['Obstacle','Force','Special','Force',''];events=[];current={};rows=[];errors=[];groups={}
def observe(mu,address,size,user):
 sp=mu.reg_read(UC_X86_REG_ESP);record,raw=n.unpack('<II',sp+4);value=raw if raw<0x80000000 else raw-0x100000000;pair=q.identity(record)
 if address==VISIBLE:
  events.append(['visible',pair,value]);typ=n.unpack('<B',record+6)[0]
  if current['rewrite']:n.pack('<I',q.TYPES+typ*0x9c+0x54,ALTERNATE)
  if current['retag']>=0:n.pack('<B',record+6,current['retag'])
 else:events.append(['active',pair,value,'alternate' if address==ALTERNATE else 'original'])
 mu.reg_write(UC_X86_REG_EIP,n.unpack('<I',sp)[0]);mu.reg_write(UC_X86_REG_ESP,sp+4)
for a in [ACTIVE,VISIBLE,ALTERNATE]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=a)
def options(o):
 p=q.options(dict(tokens=['name=alpha'],activation=[True,True,False,True,True],visibility=[True,False,True,True,True],active=1,rewrite=False,retag=-1));p.update(o);return p
def setup(o,name):
 q.setup(o,name);n.write(D+0x1b000,bytes(0x15000));events.clear();current.clear();current.update(o);n.pack('<I',ROOT,q.REG if o['registry'] else 0)
 for typ in range(5):n.write(q.TYPES+typ*0x9c,NAMES[typ].encode()+b'\0');n.pack('<I',q.TYPES+typ*0x9c+0x54,ACTIVE if o['activation'][typ] else 0);n.pack('<I',q.TYPES+typ*0x9c+0x5c,VISIBLE if o['visibility'][typ] else 0)
 for i,token in enumerate(o['tokens']):n.pack('<I',ARGS+i*4,TEXTS+i*0x100);n.write(TEXTS+i*0x100,token.encode()+b'\0')
def findtype(o,name):
 if name is None or not o['types'] or not o['registry']:return -1
 name=name.split('\0')[0];return next((i for i in range(max(0,o['typeCount'])) if NAMES[i]==name),-1)
def dispatch(o,bound,active):
 ev=[];changed=[]
 if bound is not None and o['types'] and o['registry'] and bound[0]<o['typeCount'] and o['activation'][bound[0]]:
  alternate=False
  if active!=0 and o['visibility'][bound[0]]:
   ev.append(['visible',bound,1])
   if o['rewrite']:alternate=True;changed.append(['callback',bound[0]])
   if o['retag']>=0:changed.append(['type',bound,o['retag']])
  ev.append(['active',bound,active,'alternate' if alternate else 'original'])
 return ev,changed
def model(kind,o,name):
 if kind=='FindType':return dict(result=findtype(o,name),events=[]),[]
 if kind=='SetActive':ev,changed=dispatch(o,o['bound'],o['active']);return dict(events=ev),changed
 bound=None;target=None;typ=-1;active=1
 for text in o['tokens']:
  token=text.split('\0')[0];lower=token.lower();at=lower.find('name=')
  if at>=0:target=token[at+5:]
  else:
   at=lower.find('type=')
   if at>=0:typ=findtype(o,token[at+5:])
   elif 'false' in lower:active=0
 nameevents=[]
 if target is not None:
  found=q.model('bindBlowup',dict(o,blowupType=typ),target);bound=found['result'];nameevents=found['events']
 ev,changed=dispatch(o,bound,active);return dict(events=nameevents+ev),changed
def run(kind,inputs=None,name=None,source=None):
 o=options(inputs or {});setup(o,name);before=bytearray(n.read(D,0x30000));want,changed=model(kind,o,name)
 if kind=='FindType':value=n.call(0x559e20,[q.REG if o['registry'] else 0,q.TEXT if name is not None else 0]);got=dict(result=value if value<0x80000000 else value-0x100000000,events=[])
 elif kind=='SetActive':n.call(0x55a250,[q.REG if o['registry'] else 0,0 if o['bound'] is None else q.record(*o['bound']),o['active'],99]);got=dict(events=events.copy())
 else:n.call(0x464820,[ROOT,0,ARGS,len(o['tokens'])]);got=dict(events=q.events+events)
 for change in changed:
  if change[0]=='callback':struct.pack_into('<I',before,q.TYPES+change[1]*0x9c+0x54-D,ALTERNATE)
  else:struct.pack_into('<B',before,q.record(*change[1])+6-D,change[2])
 bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x30000)!=before:bad.append('Complete memory mismatch')
 if bad:errors.append(dict(kind=kind,options=o,name=name,bad=bad))
 rows.append(dict(kind=kind,options=o,name=name,native=got,source=source));groups[kind]=groups.get(kind,0)+1

def main():
 for name,count,types,registry in itertools.product([None,'','Obstacle','obstacle','Force','force','Special','missing','Force\0ignored'],[-1,0,1,2,4,5],[False,True],[False,True]):run('FindType',dict(typeCount=count,types=types,registry=registry),name)
 for bound,count,active,rewrite,retag in itertools.product([None,[0,0],[0,3],[1,1],[2,0],[3,0],[4,0]],[-1,0,1,2,4,5],[-1,0,1,2],[False,True],[-1,2,255]):run('SetActive',dict(bound=bound,typeCount=count,active=active,rewrite=rewrite,retag=retag))
 tokenSets=[[],['alpha'],['name=alpha'],['xNAME=ALPHA'],['name=missing'],['name=alpha','name=beta'],['name=missing','name=alpha'],['name=alpha','type=Force'],['name=alpha','type=force'],['name=alpha','type=Missing'],['name=alpha','type=Force','type=Obstacle'],['name=alpha','FALSE','TRUE'],['name=alpha','prefixFALSEsuffix'],['name=alpha','type=FALSE'],['name=FALSE'],['name=alpha\0ignored']]
 for tokens,types,registry,activation,visibility,rewrite in itertools.product(tokenSets,[False,True],[False,True],[False,True],[False,True],[False,True]):run('ActivateGizmo',dict(tokens=tokens,types=types,registry=registry,activation=[activation]*5,visibility=[visibility]*5,rewrite=rewrite))
 uses=next(r['uses'] for r in json.loads((B/'reports/gameplay-command-semantic-coverage.json').read_text())['rows'] if r['name']=='ActivateGizmo')
 for source in uses:run('ActivateGizmo',dict(tokens=source['args']),source=source)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,fullRegionComparisons=len(rows),authoredUses={'ActivateGizmo':len(uses)},examples=errors[:4],method='Actual464820,559e20,55a020,558770,55a250 and string helpers; physical activation/visibility callbacks are explicit services. Compare callback order, raw signed activation argument, callback-slot reread, post-visibility retag behavior and complete fixture memory.',limits=['Finite valid ASCII token/type/name buffers and bounded signed type counts. Global type table and registry pointers have independent gates.','Physical type callbacks are explicit service boundaries, not recovered world simulation. Callback array storage stays stable; tests permit activation-slot replacement and gizmo type mutation during visibility.','56 authored action operands replay on prepared name tables, not loaded-level binding. Managed replay pending.'])
 (B/'reports/native-gizmo-activation-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-gizmo-activation-vectors.json').write_text(json.dumps(dict(binarySha256=n.sha256,names=q.names,typeNames=NAMES,cases=rows),separators=(',',':'))+'\n');print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
