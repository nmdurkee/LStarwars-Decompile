"""Independently compare our DDS base-mip PNGs against Pillow's DDS decoder."""
from PIL import Image, ImageChops
from pathlib import Path
import json, sys
manifest_path = Path(sys.argv[1]).resolve()
manifest = json.loads(manifest_path.read_text())
checks = []
for texture in manifest['textureExports']:
    if not texture.get('png') or not texture['raw'].endswith('.dds'):
        continue
    raw = (manifest_path.parent / texture['raw']).resolve()
    preview = (manifest_path.parent / texture['png']).resolve()
    try:
        reference = Image.open(raw).convert('RGBA')
        converted = Image.open(preview).convert('RGBA')
        if reference.size != converted.size:
            raise ValueError('dimension mismatch')
        extrema = ImageChops.difference(reference, converted).getextrema()
        maximum = max(channel[1] for channel in extrema)
        # BC endpoint expansion/interpolation rounding can differ by one unit.
        checks.append({'index': texture['index'], 'sha256': texture['sha256'],
                       'dimensions': reference.size, 'maxChannelDifference': maximum,
                       'withinOneUnit': maximum <= 1})
    except Exception as error:
        checks.append({'index': texture['index'], 'error': str(error)})
report = {'manifest': str(manifest_path), 'decoder': 'Pillow', 'checks': checks,
          'passed': sum(c.get('withinOneUnit', False) for c in checks),
          'failedOrUnsupported': sum(not c.get('withinOneUnit', False) for c in checks)}
if len(sys.argv) > 2:
    Path(sys.argv[2]).write_text(json.dumps(report, indent=2))
print(json.dumps({k: v for k, v in report.items() if k != 'checks'}, indent=2))
