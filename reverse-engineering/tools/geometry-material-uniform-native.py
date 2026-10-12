"""Differential check recovered material uniform formulas against original PC x86.
Only captures upload boundaries; original arithmetic/conversions run unchanged.
"""
import importlib.util,json,base64,math,hashlib
from pathlib import Path
root=Path('reverse-engineering').resolve()
spec=importlib.util.spec_from_file_location('native_x86',root/'tools/native-x86.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_ESP,UC_X86_REG_EIP
n=native.NativeX86();context=n.DATA;material=n.DATA+0x1000;records=n.DATA+0x2000
semantic_ids=[0,2,9,10,11,12,13,14,15,16,51,52,53,54,55,57,58,59,60,64,65,66,67,72,80,81,83,91,92]
n.pack('<I',context+0x10,records);n.pack('<I',context+0x14,4)
for i,sid in enumerate(semantic_ids):n.pack('<hhII',records+i*12,0,0,sid<<16,records+(i+1)*12 if i+1<len(semantic_ids) else 0)
actual={}
def u32(a):return n.unpack('<I',a)[0]
def hook(mu,address,size,user):
    sp=mu.reg_read(UC_X86_REG_ESP);rec=mu.reg_read(UC_X86_REG_ECX);sid=n.unpack('<B',rec+6)[0]
    if address==0x742310:values=list(n.unpack('<f',sp+4))
    else:values=list(n.unpack('<'+'f'*(2 if address==0x7426d0 else 4),u32(sp+4)))
    actual[sid]=values;ret=u32(sp);mu.reg_write(UC_X86_REG_ESP,sp+8);mu.reg_write(UC_X86_REG_EIP,ret)
for addr in [0x742380,0x742310,0x7426d0,0x742700]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=addr,end=addr)
idx=json.loads((root/'reports/geometry-material-data-index.json').read_text());rows=[];errors=[];checks=0;components=0;cache={};max_error=0;nonfinite=0
for row in idx['rows']:
    source=json.loads((root/row['report']).read_text());expected=json.loads((root/'exports/geometry/material-parameters'/(row['source']+'.json')).read_text());by_index={m['index']:m for m in expected['materials']};count=0
    for m in source['materials']:
        if m['recordSize']!=708:continue
        raw=base64.b64decode(m['rawRecordBase64']);key=hashlib.sha256(raw).hexdigest();wanted=by_index[m['index']]['nativeUniformCandidates']
        if key not in cache:
            n.write(material,raw);actual={}
            try:
                n.call(0x742730,[context,material],count=20000);cache[key]=actual
            except Exception as e:errors.append({'source':row['source'],'material':m['index'],'error':str(e)});continue
        actual=cache[key]
        for uniform in wanted:
            checks+=1;sid=uniform['semanticID'];vals=actual.get(sid,[]);ev=uniform['values']
            if len(vals)!=len(ev):errors.append({'source':row['source'],'material':m['index'],'semantic':sid,'length':len(vals),'expectedLength':len(ev)});continue
            for j,(x,y) in enumerate(zip(vals,ev)):
                components+=1
                if isinstance(y,dict):
                    nonfinite+=1;ok=math.isnan(x) if y['nonfinite']=='NaN' else x==(math.inf if y['nonfinite']=='+Infinity' else -math.inf)
                    if not ok:errors.append({'source':row['source'],'material':m['index'],'semantic':sid,'component':j,'native':str(x),'expected':y})
                else:
                    delta=abs(x-y)/max(1,abs(x),abs(y)) if math.isfinite(x) else math.inf;max_error=max(max_error,delta)
                    if delta>2e-6:errors.append({'source':row['source'],'material':m['index'],'semantic':sid,'component':j,'native':str(x),'expected':y,'normalizedError':delta})
        count+=1
    rows.append({'source':row['source'],'materials':count})
    if len(rows)%100==0:print(json.dumps({'files':len(rows),'uniformChecks':checks,'uniqueNativeCalls':len(cache),'errors':len(errors)}),flush=True)
report={'complete':True,'executableSHA256':n.sha256,'function':'0x742730','packedColorConverter':'0x742120','uniformSemanticsChecked':semantic_ids,'scope':'Original PC arithmetic and packed color conversion. Only upload boundaries intercepted; no graphics/game/OS execution. Shader specular-power global default1. Candidate uniforms including inactive-effect division by zero are compared with explicit NaN/Infinity classification. This validates values, not which uniforms a shader requests or final pixels.','files':len(rows),'materials':sum(r['materials'] for r in rows),'uniqueNativeCalls':len(cache),'uniformChecks':checks,'scalarComparisons':components,'nonfiniteComparisons':nonfinite,'maxNormalizedError':max_error,'passed':not errors,'errors':errors,'rows':rows}
(root/'reports/geometry-material-uniform-native.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items() if k not in ['rows','errors']},indent=2));print('errors',len(errors))
