"""Independent Pillow comparison of all current DDS base mip previews.

Read only. Pass --standalone to omit the shared image store. Float DDS formats
unsupported by Pillow are recorded as independent-decoder limitations.
"""
from PIL import Image, ImageChops
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import json, sys, struct, time

root = Path('reverse-engineering').resolve()
targets = []
if '--standalone' not in sys.argv:
    targets += [(p, p.with_suffix('.png')) for p in (root/'exports/geometry/textures').glob('*.dds')]
data = json.loads((root/'reports/geometry-fonts-images.json').read_text(encoding='utf-8'))
for r in data['results']:
    if r['kind'] == 'DDS':
        targets.append((root/'extracted'/r['source'], root/r['png']))
    elif r['kind'] == 'FNT':
        png = root/r['atlas']
        targets.append((png.with_suffix('.dds'), png))

def compare(pair):
    raw, preview = pair
    result = {'dds': str(raw.relative_to(root)), 'png': str(preview.relative_to(root))}
    try:
        head = raw.read_bytes()[:128]
        fourcc = struct.unpack_from('<I', head, 84)[0]
        result['formatCode'] = fourcc
        with Image.open(raw) as source, Image.open(preview) as output:
            reference, converted = source.convert('RGBA'), output.convert('RGBA')
            if reference.size != converted.size:
                raise ValueError('dimension mismatch')
            extrema = ImageChops.difference(reference, converted).getextrema()
            result.update(dimensions=reference.size,
                          maxChannelDifference=max(channel[1] for channel in extrema),
                          exact=all(channel[1] == 0 for channel in extrema))
    except Exception as e:
        result['error'] = str(e)
        result['independentDecoderUnsupported'] = result.get('formatCode') in (111,112,113,114,115,116)
    return result

report = root/'reports'/('geometry-images-independent-standalone.json' if '--standalone' in sys.argv else 'geometry-images-independent.json')
checks=[]
def save(complete=False):
    value={'complete':complete, 'decoder':'Pillow '+Image.__version__, 'total':len(targets),
           'checked':len(checks), 'exact':sum(c.get('exact',False) for c in checks),
           'different':sum('maxChannelDifference' in c and not c['exact'] for c in checks),
           'unsupported':sum(c.get('independentDecoderUnsupported',False) for c in checks),
           'errors':sum('error' in c and not c.get('independentDecoderUnsupported',False) for c in checks),
           'checks':checks}
    report.write_text(json.dumps(value,indent=2))
    print(json.dumps({k:v for k,v in value.items() if k!='checks'}),flush=True)

with ThreadPoolExecutor(max_workers=4) as pool:
    for c in pool.map(compare, sorted(targets)):
        checks.append(c)
        if len(checks)%500==0:save()
save(True)
