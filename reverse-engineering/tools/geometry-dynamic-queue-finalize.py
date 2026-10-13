"""Preserve excluded original-fault queue input alongside passing fixtures."""
from pathlib import Path
p=Path(__file__).resolve().with_name('geometry-dynamic-queue-native.py')
s=p.read_text()
a="json.dumps({'cases':cases},separators="
b="json.dumps({'cases':cases,'excludedUnsafe':excluded},separators="
if a in s:s=s.replace(a,b)
a="'errors':errors,'fixtureFile':fp.name"
b="'errors':errors,'excludedUnsafeCases':[{k:v for k,v in row.items()if k!='before'}for row in excluded],'fixtureFile':fp.name"
if a in s:s=s.replace(a,b)
p.write_text(s)

