from pathlib import Path
p=Path(__file__).with_name('world-phase20-20261013-verify.py');scope={'__file__':str(p)};s=p.read_text();exec(compile(s[:s.index('rows=[];errors=')],str(p),'exec'),scope)
observed=[]
for index,c in enumerate(scope['cases']):
 if c['kind']!='copy':continue
 im=scope['Image'](c)
 for i in range(0,64,4):
  v=im.W(c['src']+i)
  if (v&0x7f800000)==0x7f800000 and (v&0x7fffff)!=0 and not(v&0x400000):observed.append(dict(case=index,word=i,bits=hex(v)))
  im.W(c['dest']+i,v)
print(observed)
