import importlib.util,json,struct,gzip,itertools,random,re,copy
from pathlib import Path
s=importlib.util.spec_from_file_location('tokens',Path(__file__).with_name('native-text-tokens-verify.py'));t=importlib.util.module_from_spec(s);s.loader.exec_module(t);b=t.b;n=t.n;B=t.B;D=t.D;PARSER=t.PARSER;TOKEN=t.TOKEN;TEXT=D+0x7000;RESULT=D+0x8000
s=importlib.util.spec_from_file_location('rounding',Path(__file__).with_name('native-distance-rounding-verify.py'));q=importlib.util.module_from_spec(s);s.loader.exec_module(q)
from fractions import Fraction
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
visited=set();binaryCalls=0;current=None
#Replace the imported binary token service so wide numeric inputs are preserved.
def capture():return t.capture()
def load(m):t.load(m)
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def flt(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def decimal(text):
 negative=text.startswith('-');text=text[1:] if negative else text;v=0
 for c in text:
  if not '0'<=c<='9':break
  v=(v*10+ord(c)-48)&0xffffffff
 return(-v if negative else v)&0xffffffff
def hexadecimal(text):
 v=0
 for c in text:
  c=ord(c)
  if 97<=c<=122 or c>=224:c=(c-32)&255
  digit=c-48
  if not 0<=digit<=9:
   digit=c-65+10
   if not 10<=digit<=15:return 0
  v=((v<<4)|digit)&0xffffffff
 return v
def real(text):
 negative=text.startswith('-');text=text[1:] if negative else text;value=0.;divisor=-1. if negative else 1.;i=0
 def append(v,d):return q.store(Fraction(q.store(Fraction(v)*10))+d)
 while i<len(text) and '0'<=text[i]<='9':value=append(value,ord(text[i])-48);i+=1
 if i<len(text) and text[i]=='.':
  i+=1
  while i<len(text) and '0'<=text[i]<='9':divisor=q.store(Fraction(divisor)*10);value=append(value,ord(text[i])-48);i+=1
 if value==0:return 0x80000000 if negative else 0
 return bits(q.store(Fraction(value)/Fraction(divisor)))
def setup(p):
 o=t.options('',capacity=128,binary=0,seed=p['seed']);m=t.setup(o);m.write(t.LINE,p['line'].encode('latin1')+b'\0');m.write(TEXT,p['text'].encode('latin1')+b'\0');return m
def model(m,p):
 kind=p['kind'];text=p['text']
 if kind.startswith('read-'):t.next_token(m);text=t.string(m,TOKEN)
 if kind in ['decimal','read-int']:
  if kind=='read-int' and text.startswith('$'):return hexadecimal(text[1:])
  if kind=='read-int' and text[:2].lower()=='0x':return hexadecimal(text[2:])
  return decimal(text)
 if kind=='hex':return hexadecimal(text)
 result=real(text);m.put(RESULT,result);return result
def observe(mu,a,z,u):visited.add(a)
for a,z in [(0x4f28e0,0x4f299e),(0x4f29a0,0x4f29e5),(0x4f8cb0,0x4f8d00),(0x4f8100,0x4f8194),(0x4f9e70,0x4f9f51)]:n.mu.hook_add(UC_HOOK_CODE,observe,begin=a,end=z)
n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',RESULT))
def main():
 rows=[];errors=[];rng=random.Random(0x4f28e0);texts=['','-','+1',' 1','0','-0','1','-1','2147483647','2147483648','4294967296','-4294967295','123abc','1e3','.5','-.5','+0.5','1.23456789','-123.99999','123456789012345678901234567890','0.00000000000000000000000000001','12.34.56','0xFF','$ff','ffffFFFF','ffG','\xff']
 for i in range(512):texts.append(('-' if i%2 else '')+str(rng.randrange(10**rng.randrange(1,18)))+('.'+str(rng.randrange(10**rng.randrange(1,12))) if i%3 else '')+rng.choice(['','x','e3']))
 cases=[]
 for text in texts:
  for kind in ['decimal','hex','real','read-int','read-real']:
   line='"'+text+'" tail' if kind.startswith('read-') else '';cases.append(dict(kind=kind,text=text,line=line,seed=17))
 #All numeric words actually present in the authored source, with bounded real digits.
 nums=set(re.findall(r'(?<![A-Za-z0-9_])[+-]?(?:\d+(?:\.\d*)?|\.\d+)',(B/'extracted/AUDIO/AUDIO.CFG').read_text(encoding='latin1')))
 for text in sorted(nums):
  if len(text)<30:
   for kind in ['read-int','read-real']:cases.append(dict(kind=kind,text=text,line=text+' tail',seed=31))
 for index,p in enumerate(cases):
  m=setup(p);load(m);want=model(m,p);kind=p['kind'];addr={'decimal':0x4f29a0,'hex':0x4f8cb0,'real':0x4f28e0,'read-int':0x4f9e70,'read-real':0x4f8100}[kind];got=n.call(addr,[PARSER if kind.startswith('read-') else TEXT],count=1000000)
  if kind in ['real','read-real']:n.mu.emu_start(n.STOP,n.STOP+6);got=n.unpack('<I',RESULT)[0]
  actual=capture();bad=[]
  if got!=want:bad.append(dict(result=hex(got),want=hex(want)))
  if actual.sha()!=m.sha():
   diffs=[]
   for a,data in m.r.items():diffs.extend(hex(a+i) for i,v in enumerate(data) if actual.r[a][i]!=v)
   bad.append(dict(differences=diffs[:20]))
  if bad:errors.append(dict(index,input=p,bad=bad))
  rows.append(dict(input=p,nativeSha=actual.sha(),result=got))
  if errors:break
 report=dict(binarySha256=n.sha256,checks=len(rows),mismatches=len(errors),visitedInstructions=len(visited),bytesComparedPerCase=sum(z for a,z in b.REGIONS),groups={k:sum(r['input']['kind']==k for r in rows) for k in ['decimal','hex','real','read-int','read-real']},examples=errors[:2],method='Original4f28e0/4f29a0/4f8cb0 and numeric readers4f8100/4f9e70 execute with actual shared token scanner. No computational hooks; exact raw32-bit results and complete prepared memory compare.',limits=['Terminated byte strings, numeric reader tokens below64bytes, finite stored floating intermediates. Text-mode reader composition covered; binary token decoding remains an explicit service in portable API, not exercised here.','Decimal integer wraps32bits and consumes optionalminus/digitprefix; no plus or whitespace. Hex consumeswholeinput, any invalidbyte returns0. Readers recognize$and0xprefixes.','Real parser does not implement exponent syntax. It rounds after every multiply, add, divisor scale and final divide; minuszero retained. Full audio parsing through these helpers is separate; managed execution pending.'])
 (B/'reports/native-text-numbers-tests.json').write_text(json.dumps(report,indent=2)+'\n');(B/'reports/native-text-numbers-vectors.json.gz').write_bytes(gzip.compress(json.dumps(dict(binarySha256=n.sha256,regions=b.REGIONS,cases=rows),separators=(',',':')).encode(),mtime=0));print(json.dumps(report,indent=2));assert not errors
if __name__=='__main__':main()
