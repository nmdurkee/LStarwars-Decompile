import json,gzip,struct
from pathlib import Path
B=Path(__file__).resolve().parent.parent
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
w=lambda x:struct.unpack('<I',struct.pack('<f',x))[0]
def multiply(a,b):
 out=[]
 for i in range(4):
  for j in range(4):
   total=0.
   for k in range(4):total+=float(a[i*4+k])*b[k*4+j]
   out.append(f32(total))
 return out
f=json.loads(gzip.decompress((B/'reports/scene-phase4-20261013-native-fixtures.json.gz').read_bytes()))
fail=[]
for ci,c in enumerate(f['transformCases']):
 for mi,key in enumerate(['outer','inner']):
  got=[w(v)for v in multiply(c['view'],c['local'][mi])]
  if got!=c['nativePlaneWords'][key]:fail.append([ci,key])
print({'phase4TransformCases':len(f['transformCases']),'sequentialDoubleDifferences':fail[:20],'total':len(fail)})
