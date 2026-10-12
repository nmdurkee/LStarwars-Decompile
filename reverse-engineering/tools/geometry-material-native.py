"""Capture exact macro emissions from original PC material feature builder.
Isolated x86, no GPU/game/Windows calls. Feature-emission and texture-resource
query boundaries are captured/supplied; all feature predicates execute natively.
"""
import importlib.util,json,base64,hashlib,struct,sys
from pathlib import Path
root=Path('reverse-engineering').resolve()
spec=importlib.util.spec_from_file_location('native_x86',root/'tools/native-x86.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
n=native.NativeX86();context=n.DATA;builder=n.DATA+0x1000;desc=n.DATA+0x4000;mat=n.DATA+0x5000;texobj=n.DATA+0x6000;comobj=n.DATA+0x7000;vtable=n.DATA+0x7100;getdesc=n.STOP+0x100
n.write(builder,b'\0'*0x3000);n.pack('<I',texobj+0x24,comobj);n.pack('<I',comobj,vtable);n.pack('<I',vtable+0x44,getdesc)
def u32(a):return n.unpack('<I',a)[0]
def cstr(a):
    if not a:return None
    b=n.read(a,256);end=b.find(b'\0')
    if end<0:raise ValueError('Unbounded emitted macro string')
    return b[:end].decode('ascii')
def ret(mu,bytes_to_pop=0,value=0):
    sp=mu.reg_read(UC_X86_REG_ESP);address=u32(sp);mu.reg_write(UC_X86_REG_EAX,value);mu.reg_write(UC_X86_REG_ESP,sp+4+bytes_to_pop);mu.reg_write(UC_X86_REG_EIP,address)
emissions=[];normal_format=0

def hook(mu,address,size,user):
    sp=mu.reg_read(UC_X86_REG_ESP)
    if address==0x747320:
        name,value,kind=n.unpack('<III',sp+4);emissions.append({'name':cstr(name),'value':cstr(value),'kind':kind});ret(mu,12)
    elif address==0x5e5310:ret(mu,value=texobj)
    elif address==getdesc:
        n.pack('<I',u32(sp+12),normal_format);ret(mu,12)
for address in [0x747320,0x5e5310,getdesc]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
index=json.loads((root/'reports/geometry-material-data-index.json').read_text())
scene_index={r['source']:r for r in json.loads((root/'reports/geometry-scene-data-index.json').read_text())['rows']}
configs={};variants={};rows=[];errors=[];legacy=[];calls=0;material_count=0;limit=int(sys.argv[1]) if len(sys.argv)>1 else None
for row in index['rows']:
    data=json.loads((root/row['report']).read_text());sm=json.loads((root/scene_index[row['source']]['report']).read_text());out=[]
    with (root/'extracted'/row['source']).open('rb') as game:
        texture_formats={}
        for t in sm['textures']:
            if t.get('size',0)>=128:
                game.seek(t['offset']+84);texture_formats[t['index']]=struct.unpack('<I',game.read(4))[0]
        for m in data['materials']:
            if m['recordSize']!=708:legacy.append({'source':row['source'],'material':m['index'],'recordSize':m['recordSize']});continue
            raw=base64.b64decode(m['rawRecordBase64']);descriptor=raw[0xb4:0x2bc]
            if len(descriptor)!=0x208:raise ValueError('Bad descriptor length')
            fmt=texture_formats.get(m['normal'],0);key=hashlib.sha256(descriptor+struct.pack('<I',fmt)).hexdigest()
            if key not in configs:
                result={}
                n.write(desc,descriptor);n.write(mat,raw);n.pack('<I',mat+0x100,1 if fmt else 0);normal_format=fmt
                for profile in [1,2,3,4]:
                    for shadow in [0,1]:
                        # Canonical authored-material context: absent texture sentinel -1,
                        # one color render target, no normal/motion/depth auxiliary targets.
                        n.pack('<9I',context,desc,mat,0,shadow,0,0,0,1,0xffffffff)
                        n.pack('<I',builder+0x974,profile);n.pack('<I',0x2976b94,0);n.pack('<B',0x8264c7,0)
                        emissions=[]
                        try:
                            n.call(0x749570,[context,builder],count=20000);calls+=1
                            emitted=list(emissions);digest=hashlib.sha256(json.dumps(emitted,separators=(',',':')).encode()).hexdigest();variants.setdefault(digest,{'profile':profile,'shadow':bool(shadow),'definitions':emitted});result[str(profile)+('_shadow' if shadow else '_color')]=digest
                        except Exception as e:errors.append({'source':row['source'],'material':m['index'],'profile':profile,'shadow':shadow,'error':str(e)});result[str(profile)+('_shadow' if shadow else '_color')]={'error':str(e)}
                configs[key]=result
            out.append({'index':m['index'],'address':m['address'],'sourceRecordSHA256':m['recordSHA256'],'normalDDSFormat':fmt,'featureVariants':configs[key]});material_count+=1
            if limit and material_count>=limit:break
    output=root/'exports/geometry/material-programs'/(row['source']+'.json');output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps({'source':row['source'],'sourceSHA256':data['sourceSHA256'],'materials':out},indent=2))
    rows.append({'source':row['source'],'materials':len(out),'output':str(output.relative_to(root))})
    if len(rows)%25==0:print(json.dumps({'files':len(rows),'materials':material_count,'inputConfigurations':len(configs),'variants':len(variants),'nativeCalls':calls,'errors':len(errors)}),flush=True)
    if limit and material_count>=limit:break
report={'complete':limit is None,'executableSHA256':n.sha256,'entry':'0x749570','emissionBoundary':'0x747320','scope':'Native material feature predicates executed; emission hook records names/values/kinds; texture object query supplies original DDS format. Descriptor input is authored bytes, IDs use -1 absent sentinel. Canonical color/shadow passes for profiles1..4, vendor0, directionalLightmap false, one render target; no normal/motion/depth targets. Not a native pixel-render equivalence test.','files':len(rows),'materials':material_count,'inputConfigurations':len(configs),'nativeCalls':calls,'uniqueVariants':len(variants),'variants':variants,'rows':rows,'legacyUnmapped':legacy,'errors':errors}
(root/'reports/geometry-material-native-programs.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:v for k,v in report.items() if k not in ['variants','rows','legacyUnmapped','errors']},indent=2));print('errors',len(errors))
