"""Read-only pre-push size and high-confidence credential scan. Prints no secret values."""
import gzip,json,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
patterns={
 'github-token':re.compile(rb'\b(?:gh[pousr]_[A-Za-z0-9]{36,255}|github_pat_[A-Za-z0-9_]{30,255})\b'),
 'openai-key':re.compile(rb'\bsk-(?:proj-|svcacct-)?[A-Za-z0-9_-]{40,255}\b'),
 'aws-access-key':re.compile(rb'\b(?:AKIA|ASIA)[A-Z0-9]{16}\b'),
 'private-key':re.compile(rb'-----BEGIN (?:RSA |EC |OPENSSH |DSA )?PRIVATE KEY-----'),
 'credential-url':re.compile(rb'https?://[^\s/:"\x27]+:[^\s/@"\x27]{8,}@[^\s/]+')}
paths=set()
for args in [['--cached'],['--others','--exclude-standard']]:
 result=subprocess.run(['git','ls-files','-z']+args,cwd=ROOT,check=True,stdout=subprocess.PIPE);paths.update(p.decode('utf-8')for p in result.stdout.split(b'\0')if p)
from concurrent.futures import ThreadPoolExecutor,as_completed

def inspect(rel):
 p=ROOT/rel
 if not p.is_file():return None
 size=p.stat().st_size;findings=[]
 logical=rel[:-3]if rel.endswith('.gz')else rel
 binary=Path(logical).suffix.lower()in['.bin','.f32','.sqlite','.png','.jpg','.dds']
 if not binary and not rel.endswith('/check-publish.py'):
  opener=gzip.open if p.suffix=='.gz'else open
  with opener(p,'rb')as f:
   carry=b'';seen=set()
   for part in iter(lambda:f.read(1024*1024),b''):
    block=carry+part
    for name,pattern in patterns.items():
     if name not in seen and pattern.search(block):findings.append({'path':rel,'rule':name});seen.add(name)
    carry=block[-2048:]
 return {'path':rel,'bytes':size,'findings':findings,'binary':binary}

findings=[];oversized=[];scanned=total=skipped=0
with ThreadPoolExecutor(max_workers=16)as pool:
 futures=[pool.submit(inspect,rel)for rel in sorted(paths)]
 for task in as_completed(futures):
  result=task.result()
  if result is None:continue
  scanned+=1;total+=result['bytes'];skipped+=int(result['binary']);findings.extend(result['findings'])
  if result['bytes']>=100*1024*1024:oversized.append({'path':result['path'],'bytes':result['bytes']})
  if scanned%5000==0:print(json.dumps({'checkedFiles':scanned,'totalFiles':len(paths)}),flush=True)
report={'files':len(paths),'checked':scanned,'binaryFixturesExcludedFromCredentialScan':skipped,'workingTreeBytes':total,'oversized':oversized,'credentialFindings':findings,'scope':'High-confidence patterns in source/text evidence including compressed JSON; generated numeric/image/database fixtures are excluded. Not a proof of absence of every possible secret.'}
print(json.dumps(report,indent=2),flush=True);raise SystemExit(1 if findings or oversized else 0)
