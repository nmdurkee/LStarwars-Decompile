import importlib.util,json,struct,gzip,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('raw_config',Path(__file__).with_name('native-sound-text-configuration-verify.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r);b=r.b;d=r.d;n=r.n;B=r.B;D=r.D
b.REGIONS=[(0x76d200,40),(0x810300,0x200),(0x88ab4c,4),(0x91eec4,4),(0x2920000,0x44000),(D,0x80000)];b.CURSOR=r.CURSOR;b.PATH=r.PATH
expected=None
#The same sample/group model reads newly allocated backing after6521b0.
def config(m,p):
 global expected
 d.HEADS=m.get(0x292fda0);d.RECORDS=m.get(0x2947b74);d.BANKS=m.get(0x2947d70);d.BACKUP=m.get(0x292fda4);expected=r.model(m,p)
b.service=config
def setup(p):
 m=b.setup(p)
 for a,data in r.constants.items():m.write(a,data)
 m.write(D+0x2000,struct.pack('<256I',*d.TABLEWORDS))
 for a in [0x2962024,0x2962020,0x91eec4]:m.put(a,0)
 m.put(0x2962034,p['flag']);m.put(r.PARSER,r.BUFFER);m.put(r.PARSER+4,r.HANDLE);m.put(r.PARSER+0x50c,r.LINE);m.put(r.PARSER+0x510,r.TOKEN);m.put(r.PARSER+0x514,4096);m.put(r.PARSER+0x518,128);m.put(r.PARSER+0x51c,0);m.put(r.PARSER+0x520,0);m.put(r.PARSER+0x524,0);m.put(r.PARSER+0x528,0);m.put(r.PARSER+0x52c,0xffffffff);m.put(r.PARSER+0x574,len(p['text']));m.put(r.PARSER+0x570,0xffffffff);m.write(r.PARSER+0x578,b'\0');m.put(r.PARSER+0x57c,0);m.put(r.PARSER+0x580,0);return m
def options(text,**kw):
 p=r.options(text);p.update(alignment=0,initialized=0,builtinCount=0,nameCount=0,names=[],path='AUDIO/AUDIO.CFG');p.update(kw);p['names']=['Builtin_'+str(i) for i in range(p['builtinCount'])];return p
def main():
 rows=[];errors=[];sample='Audio 1.00\nSample name A fname first global\nSample name B fname second pitch 12345\nGroup A B\n';cases=[options(text,alignment=align,initialized=init,builtinCount=bi,afterFlag=flag) for text,align,init,bi,flag in itertools.product(['',sample],[0,3],[0,1],[0,2],[0,1])]
 full=(B/'extracted/AUDIO/AUDIO.CFG').read_bytes().decode('latin1');cases+=[options(full,label='authored-complete-file',builtinCount=bi,initialized=init,chunk=4096) for bi,init in [(0,0),(2,1)]]
 for index,p in enumerate(cases):
  r.current=p;r.state=r.l.fresh();r.io=[];r.calls={'sample':0,'group':0,'header':0};m=setup(p);r.load(m);b.model(m,p);events,reads,calls=expected;n.call(0x6521b0,[r.CURSOR,0xaabbccdd,r.PATH],count=1000000000);actual=r.capture();bad=[]
  if r.io!=events:bad.append(dict(events=r.io,want=events))
  if r.state['events']!=reads:bad.append('file reads')
  if r.calls!=calls:bad.append(dict(calls=r.calls,want=calls))
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(dict(address=hex(a+i),got=actual.r[a][i],want=v) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:20]))
  if bad:errors.append(dict(index,label=p['label'],bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),events=r.io,reads=r.state['events'],calls=r.calls,counts=r.stats(actual),mask=actual.read(0x2921760,200).hex()))
  if index%8==0 or p['label']=='authored-complete-file' or errors:print(json.dumps(dict(case=index,mismatches=len(errors),counts=r.stats(actual))),flush=True)
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),bytesComparedPerCase=sum(z for a,z in b.REGIONS),authoredCompleteRuns=sum(r['input']['label']=='authored-complete-file' for r in rows),examples=errors[:2],method='Original6521b0→650280 arena/hash initialization→6520b0→complete raw text parser/sample/group chain executes. Only file and bank/device services remain. Allocation cursor, builtin copies, complete bank/sound/backups/hash/groups/masks and file/device order compare.',limits=['Zero new native addresses: connected evidence for already recovered functions. Valid disjoint allocation arena/parser/source/builtin buffers; sound IDs used for global mask fit0..1599.','Both fresh and preinitializedCRC states,0/2builtin banks, alignment0/3, deviceflag0/1, empty/configured source and two full authored file runs. Final global200-byte mask replaces the service mask exactly.','No real file opening/handle lifetime, resource decoding or hardware audio backend. Managed execution pending.'])
 (B/'reports/native-sound-initialization-pipeline-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-initialization-pipeline-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,table=d.TABLEWORDS,constants={str(a):v.hex() for a,v in r.constants.items()},cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
