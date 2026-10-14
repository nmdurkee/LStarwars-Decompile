"""Complete148-byte pool initialization; exact cursor/header/sentinels/free-block writes."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase200-20261014-verify.py').read_text().split('\ndef run(')[0])
CURSOR=D+0x100;BASE=D+0x400;cases=[];checks=0;errors=[]
U=lambda v:v&0xffffffff
def run214(c):
 global checks
 n.write(D,bytes((i*37+11)&255 for i in range(0x7000)));base=BASE+c['alignment'];cursor=base+c['cursorOffset']if'cursorOffset'in c else CURSOR;n.pack('<I',cursor,base)
 if 'badCursor'in c:cursor=c['badCursor']
 capacity=c['capacity'];initial=n.read(D,0x7000);model=bytearray(initial);want=0
 def wr(p,v):model[p-D:p-D+4]=U(v).to_bytes(4,'little')
 if capacity>=80:
  want=base;wr(cursor,base+capacity);wr(base+24,0);root=base+16;wr(root,0);free=base+48;wr(root+4,free);wr(root+12,root);wr(base+36,0);wr(base+40,0);before=base+32;wr(before,0x80000000);wr(before+12,before);last=base+capacity-16;wr(last+4,0);wr(last+8,0);wr(last,0x80000000);wr(last+12,last);wr(free,capacity-80);wr(free+4,0);wr(free+8,root);wr(free+((capacity-80)&0x7fffffff)+12,free);wr(base+4,capacity);wr(base+8,0);wr(base+12,0);wr(base,base)
 actual=n.call(0x4ef980,[cursor,c['reserved'],capacity],count=1000000);final=n.read(D,0x7000)
 for group,a,b in [('return',actual,want),('images',final,bytes(model))]:
  checks+=1
  if a!=b:errors.append(dict(group=group,context=c,native=a if group!='images'else[[hex(D+i),u,v]for i,(u,v)in enumerate(zip(a,b))if u!=v][:12],model=b if group!='images'else'diff'))
 cases.append(dict(inputs=dict(cursor=cursor,reserved=c['reserved'],capacity=capacity),context=c,initial=[dict(address=D,bytes=initial.hex())],final=[dict(address=D,bytes=final.hex())],returnValue=actual))
for capacity,alignment,reserved in itertools.product([0,1,79,80,81,96,128,512,16384],range(4),[0,1,0xffffffff]):run214(dict(capacity=capacity,alignment=alignment,reserved=reserved))
for offset,capacity in itertools.product([0,4,8,12,16,20,24,28,32,36,40,44,48],[80,128,512]):run214(dict(capacity=capacity,alignment=0,reserved=0xdeadbeef,cursorOffset=offset))
for capacity,badCursor in itertools.product([0,1,79],[0,0xdead0000]):run214(dict(capacity=capacity,alignment=0,reserved=0,badCursor=badCursor))
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:4],managedExecution=False,newEntries=0,ports=[],closure='Whole148-byte cursor-consuming initialization, descriptor/root/two busy sentinels/freeblock/boundary tags; aliasedcursorwithheaders andunder80earlyreturnwithoutcursorread')
(nm.BASE/'reports/script-phase214-20261014-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase214-20261014-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps(report))
