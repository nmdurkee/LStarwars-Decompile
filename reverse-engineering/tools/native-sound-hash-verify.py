import importlib.util,json,struct,itertools,gzip,random,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('sound',Path(__file__).with_name('native-build-sound-verify.py'));b=importlib.util.module_from_spec(s);s.loader.exec_module(b);n=b.n;B=b.B;D=n.DATA
CURSOR=D+0x1000;ARENA=D+0x2000;OLD=D+0x7000;TEXT=D+0x8000;rows=[];errors=[];groups={};calls=0
OLDWORDS=[(0xdeadbeef+i*0x9e3779b9)&0xffffffff for i in range(256)]
def setup(offset):
 n.write(D,bytes((i*7+3)&255 for i in range(0x10000)));n.pack('<I',CURSOR,ARENA+offset);n.pack('<I',0x2947d80,OLD);n.pack('<256I',OLD,*OLDWORDS)
def init(offset,flags):
 global calls
 setup(offset);cursor=ARENA+offset;table=OLD;words=OLDWORDS;events=[]
 for flag in flags:
  n.pack('<i',0x2962044,flag);expected=bytearray(n.read(D,0x10000));newflag=flag
  if flag==0:
   table=(cursor+3)&0xfffffffc;cursor=table+0x400;words=b.TABLEWORDS;newflag=1;struct.pack_into('<I',expected,CURSOR-D,cursor);struct.pack_into('<256I',expected,table-D,*words)
  n.call(0x650280,[CURSOR]);calls+=1;got=dict(cursor=n.unpack('<I',CURSOR)[0]-D,table=n.unpack('<I',0x2947d80)[0]-D,initialized=n.unpack('<i',0x2962044)[0],words=list(n.unpack('<256I',n.unpack('<I',0x2947d80)[0])));want=dict(cursor=cursor-D,table=table-D,initialized=newflag,words=words)
  if got!=want or n.read(D,0x10000)!=bytes(expected):errors.append(dict(kind='init',offset=offset,flag=flag,got=got,want=want))
  events.append(got)
 rows.append(dict(kind='init',offset=offset,flags=flags,native=events));groups['init']=groups.get('init',0)+1

def prefix(name,limit,offset):
 global calls
 setup(offset);n.pack('<i',0x2962044,0);n.call(0x650280,[CURSOR]);calls+=1;n.write(TEXT,name.encode('ascii')+b'\0');before=n.read(D,0x10000);got=n.call(0x650470,[TEXT,limit]);calls+=1;query=name.split('\0')[0][:limit];want=b.hash_name(query,b.TABLEWORDS);bad=[]
 if got!=want:bad.append(dict(got=got,want=want))
 if n.read(D,0x10000)!=before:bad.append('Hash changed complete input image')
 if bad:errors.append(dict(kind='prefix',name=name,limit=limit,bad=bad))
 rows.append(dict(kind='prefix',name=name,limit=limit,offset=offset,native=got));groups['prefix']=groups.get('prefix',0)+1

def main():
 for offset,flags in itertools.product(range(32),[[0],[1],[-1],[-2147483648],[0,1,1],[1,0,1],[0,0,0],[0,-1,0]]):init(offset,flags)
 rng=random.Random(0x650280);names=['','LegoSingle','LEGOSINGLE','a'*31+'bcd','alpha\0ignored']+[''.join(chr(rng.randrange(1,128)) for j in range(rng.randrange(1,130))) for i in range(128)]
 for i,name in enumerate(names):
  for limit in [0,1,2,15,31,32,33,64,127,128,0x7fffffff,0x80000000,0xffffffff]:prefix(name,limit,i%4)
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),groups=groups,originalEntryCalls=calls,initializationSteps=sum(len(r['flags']) for r in rows if r['kind']=='init'),tableWords=256,examples=errors[:3],method='Original650280 initializes the actual arena/CRC table;650470 consumes it directly with no replacements. Exact table words, arena cursor/global pointer/init flag and complete64KiB image compare at every initialization step, plus unchanged input region and hash result for every prefix call.',limits=['Valid disjoint cursor variable, aligned table destination and readable name storage. Offsets represent original pointers portably; native uint32 alignment/wrap arithmetic is preserved but invalid wrapped process addresses are excluded.','Persistent signed initialization flag gates on any nonzero value. Repeated calls retain existing table/cursor; explicit external resets to0 cause another aligned1024-byte allocation.','ASCII names only because original signed-byte high-bit indexing can read before the hash table. Prefix length is unsigned32-bit and stops at firstNUL.','Allocator ownership and sound database/bucket population remain outside this two-helper scope. Managed replay pending.'])
 (B/'reports/native-sound-hash-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-hash-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,oldWords=OLDWORDS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
