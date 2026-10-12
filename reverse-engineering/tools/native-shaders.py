"""Extract candidate embedded DX9 shaders and verify them with Microsoft's disassembler."""
import os,json,struct,ctypes,hashlib
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes()
pe=json.loads((BASE/'reports/unpacked-pe/pe.json').read_text())
versions={0xfffe0101:'vs_1_1',0xfffe0200:'vs_2_0',0xfffe0300:'vs_3_0',0xffff0101:'ps_1_1',0xffff0102:'ps_1_2',0xffff0103:'ps_1_3',0xffff0104:'ps_1_4',0xffff0200:'ps_2_0',0xffff0300:'ps_3_0'}
candidates=[]
for section in pe['sections']:
    if section['name'] not in ['.rdata','.data']:continue
    for offset in range(section['offset'],section['offset']+section['size']-3,4):
        version=struct.unpack_from('<I',blob,offset)[0]
        if version in versions:candidates.append({'offset':offset,'va':hex(pe['imageBase']+section['rva']+offset-section['offset']),'token':hex(version),'model':versions[version],'section':section['name']})
(BASE/'reports/native-shader-candidates.json').write_text(json.dumps(candidates,indent=2)+'\n')
system=Path(os.environ['SystemRoot'])/'System32'
dll=ctypes.WinDLL(str(system/'d3dcompiler_47.dll'))
dis=dll.D3DDisassemble
dis.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint,ctypes.c_char_p,ctypes.POINTER(ctypes.c_void_p)]
dis.restype=ctypes.c_long
outdir=BASE/'exports/shaders';outdir.mkdir(parents=True,exist_ok=True)
rows=[];seen={}
for c in candidates:
    o=c['offset'];end=None
    for q in range(o+4,min(len(blob)-3,o+65536),4):
        if struct.unpack_from('<I',blob,q)[0]==0xffff:end=q+4;break
    row={**c,'status':'unverified'}
    if end is None:row['reason']='No aligned END token in bounded 64 KiB search';rows.append(row);continue
    code=blob[o:end];buf=ctypes.create_string_buffer(code);out=ctypes.c_void_p()
    hr=dis(buf,len(code),0,None,ctypes.byref(out))
    row['hresult']=hex(hr&0xffffffff)
    if hr<0 or not out.value:row['reason']='D3DDisassemble rejected candidate';rows.append(row);continue
    vtable=ctypes.cast(out,ctypes.POINTER(ctypes.POINTER(ctypes.c_void_p))).contents
    ptrfn=ctypes.WINFUNCTYPE(ctypes.c_void_p,ctypes.c_void_p)(vtable[3]);sizefn=ctypes.WINFUNCTYPE(ctypes.c_size_t,ctypes.c_void_p)(vtable[4]);release=ctypes.WINFUNCTYPE(ctypes.c_ulong,ctypes.c_void_p)(vtable[2])
    text=ctypes.string_at(ptrfn(out),sizefn(out)).rstrip(b'\0').decode('utf-8','replace');release(out)
    if '???' in text:
        row.update(status='rejected',reason='Disassembler accepted bytes but emitted unknown opcodes; often a CTAB-contained version field.')
        rows.append(row);continue
    sha=hashlib.sha256(code).hexdigest();stem=c['va'][2:]
    (outdir/(stem+'.bin')).write_bytes(code);(outdir/(stem+'.asm')).write_text(text)
    row.update(status='verified-disassembly',endOffset=end,bytes=len(code),sha256=sha,binary='exports/shaders/'+stem+'.bin',assembly='exports/shaders/'+stem+'.asm',duplicateOf=seen.get(sha))
    seen.setdefault(sha,c['va']);rows.append(row)
report={'binarySha256':hashlib.sha256(blob).hexdigest(),'api':str(system/'d3dcompiler_47.dll')+'!D3DDisassemble','apiDocumentation':'https://learn.microsoft.com/en-us/windows/win32/api/d3dcompiler/nf-d3dcompiler-d3ddisassemble','method':'Aligned known shader-version tokens in initialized .rdata/.data; bounded first aligned END-token candidate; official disassembler must accept exact bounded bytes. Original bytecode and disassembly exported.','candidates':len(rows),'accepted':sum(r['status']=='verified-disassembly' for r in rows),'uniqueBytecodes':len(seen),'shaders':rows,'limits':['Shader token scanning can miss unaligned carriers and shaders generated at runtime.','Successful disassembly with no unknown opcodes establishes readable shader instructions, not runtime binding or shader validation by a graphics device.','Original HLSL source is not recovered by disassembly.']}
(BASE/'reports/native-shaders.json').write_text(json.dumps(report,indent=2))
print(json.dumps({k:v for k,v in report.items() if k!='shaders'},indent=2))
