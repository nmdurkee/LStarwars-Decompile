"""Prepared replay or saved-output comparison only; no managed launch."""
import argparse,json,hashlib
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports';p=argparse.ArgumentParser();p.add_argument('--compare',type=Path);args=p.parse_args();native=json.loads((R/'geometry-dynamic-sway-native-validation.json').read_text());assert native['passed'];fixture=R/native['fixtureFile'];assert hashlib.sha256(fixture.read_bytes()).hexdigest()==native['fixtureSHA256']
report=dict(status='prepared-not-executed',caseCount=native['counts']['cases'],mainType='DynamicSwayHarness',arguments=[str(fixture.relative_to(B)),'resultJson'],fixtureSHA256=native['fixtureSHA256'],limits='Finite normal sway branch with explicit temporary-matrix mirror; managed equality pending.')
if args.compare:
 result=json.loads(args.compare.read_text());assert result['checks']==report['caseCount'];report.update(status='passed'if result['failures']==0 else'failed',managed=result,resultSHA256=hashlib.sha256(args.compare.read_bytes()).hexdigest())
(R/'geometry-dynamic-sway-managed-check.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))
