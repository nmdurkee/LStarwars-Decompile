"""Independent NumPy reference for numeric D3DFMT 111..116 DDS previews.

These HDR or data textures are exported as original DDS plus an explicitly
clamped 8-bit preview. This checks conversion, not a shader or tone mapper.
"""
from pathlib import Path
from PIL import Image
import numpy as np, json, struct
root=Path('reverse-engineering').resolve()
audit=json.loads((root/'reports/geometry-images-independent.json').read_text(encoding='utf-8'))
checks=[]
for entry in audit['checks']:
    if not entry.get('independentDecoderUnsupported'):continue
    raw=(root/entry['dds']).read_bytes();fmt=struct.unpack_from('<I',raw,84)[0]
    w,h=struct.unpack_from('<I',raw,16)[0],struct.unpack_from('<I',raw,12)[0]
    channels={111:1,112:2,113:4,114:1,115:2,116:4}[fmt]
    values=np.frombuffer(raw,dtype='<f2' if fmt<=113 else '<f4',count=w*h*channels,offset=128).astype(np.float64).reshape(h,w,channels)
    expected=np.zeros((h,w,4),dtype=np.float64);expected[:,:,3]=1;expected[:,:,:channels]=values
    expected=np.floor(np.clip(np.where(np.isfinite(expected),expected,0),0,1)*255+0.5).astype(np.uint8)
    with Image.open(root/entry['png']) as image:actual=np.array(image.convert('RGBA'))
    maxdiff=int(np.max(np.abs(expected.astype(np.int16)-actual.astype(np.int16))))
    finite=values[np.isfinite(values)]
    checks.append({'dds':entry['dds'],'format':fmt,'dimensions':[w,h],'exact':maxdiff==0,'maxChannelDifference':maxdiff,
                   'floatMinimum':float(np.min(finite)) if finite.size else None,'floatMaximum':float(np.max(finite)) if finite.size else None,
                   'valuesOutsideNormalizedRange':int(np.sum((values<0)|(values>1))),'nonfiniteValues':int(np.sum(~np.isfinite(values)))})
report={'numpy':np.__version__,'scope':'First face/base mip, independent clamped linear 8-bit conversion. Original floating point values retained in DDS.',
        'checked':len(checks),'exact':sum(c['exact'] for c in checks),'checks':checks}
(root/'reports/geometry-images-float-independent.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
print(json.dumps({k:v for k,v in report.items() if k!='checks'}))
