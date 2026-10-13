import importlib.util,json,struct,gzip,hashlib,itertools,random
from pathlib import Path
s=importlib.util.spec_from_file_location('native',Path(__file__).with_name('native-x86.py'));x=importlib.util.module_from_spec(s);s.loader.exec_module(x);n=x.NativeX86();B=x.BASE;D=n.DATA
from unicorn import UC_HOOK_CODE
visited=set()
n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:visited.add(a),begin=0x651530,end=0x65167f)
def main():
 rows=[];errors=[];flags=[0,0xffffffff,0xdeadbeef,0x55555555,0xaaaaaaaa]+[1<<i for i in range(32)];counts=[0,19,0xffffffff];rng=random.Random(0x651530)
 for index,flag,delta,count in itertools.product([-2,0,1,31],flags,[-64,-16,-4,0,4,16,0x4000],counts):
  seed=rng.randrange(256);before=bytearray(bytes((i*7+seed)&255 for i in range(256))*256);source=0x2000+index*64;target=source+delta;struct.pack_into('<I',before,source+4,flag);n.write(D,before);n.pack('<I',0x2947b74,D+0x2000);n.pack('<I',0x292fda4,D+0x2000+delta);n.pack('<I',0x296201c,count);want=bytearray(before)
  struct.pack_into('<I',want,source,(0x293b318+count*32)&0xffffffff);struct.pack_into('<I',want,source+4,(flag&0xff880000)|0x7fff);struct.pack_into('<I',want,source+8,0x5622);want[source+12]=0;struct.pack_into('<3H',want,source+0x12,0x3fff,0xffff,0);want[source+0x18:source+0x3c]=bytes(0x24)
  for i in range(16):want[target+i*4:target+i*4+4]=want[source+i*4:source+i*4+4]
  n.call(0x651530,[index]);actual=n.read(D,0x10000);got=hashlib.sha256(actual).hexdigest()
  if actual!=bytes(want) or n.unpack('<I',0x296201c)[0]!=count:errors.append(dict(index=index,flag=flag,delta=delta,count=count))
  rows.append(dict(index=index,flag=flag,delta=delta,count=count,seed=seed,nativeSha=got))
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),visitedInstructions=len(visited),examples=errors[:3],method='Original651530 executes without substitutions; complete64KiB memory and unchanged global count compare per case, including forward-DWORD overlap in its final REP MOVSD.',limits=['Record, globals and cursor addresses are disjoint; record/backup64-byte regions may overlap by tested DWORD multiples. Negative record index allowed only with valid readable backing.','Name pointer arithmetic wraps uint32 and uses global sound count, independent of index; the name storage is not dereferenced by this initializer.','Unwritten link/padding/trailing name bytes and comment bit survive. Float defaults are raw positive-zero bits. Managed replay pending.'])
 (B/'reports/native-sound-record-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-sound-record-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
