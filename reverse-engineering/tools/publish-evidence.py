"""Losslessly pack large evidence for Git, or restore it after cloning. Python standard library only."""
import argparse,gzip,hashlib,json,os,tempfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'reverse-engineering';STORE=ROOT/'checkpoint-artifacts';MANIFEST=STORE/'manifest.json';LIMIT=8*1024*1024

def digest(path):
 h=hashlib.sha256()
 with path.open('rb')as f:
  for chunk in iter(lambda:f.read(1024*1024),b''):h.update(chunk)
 return h.hexdigest()
def contained(relative):
 p=(ROOT/relative).resolve()
 if not p.is_relative_to(ROOT.resolve()):raise ValueError('Artifact path leaves repository: '+relative)
 return p
def pack():
 STORE.mkdir(exist_ok=True);records=[]
 for p in sorted((BASE/'reports').rglob('*')):
  if not p.is_file()or p.stat().st_size<LIMIT:continue
  relative=p.relative_to(ROOT).as_posix();packed=STORE/(relative+'.gz');packed.parent.mkdir(parents=True,exist_ok=True)
  expected=digest(p)
  old=next((r for r in previous if r['path']==relative and r['sha256']==expected),None)
  if not(old and packed.exists()and digest(packed)==old['packedSha256']):
   with p.open('rb')as src,packed.open('wb')as dst,gzip.GzipFile(filename='',fileobj=dst,mode='wb',mtime=0,compresslevel=6)as out:
    for chunk in iter(lambda:src.read(1024*1024),b''):out.write(chunk)
  with gzip.open(packed,'rb')as src:
   h=hashlib.sha256()
   for chunk in iter(lambda:src.read(1024*1024),b''):h.update(chunk)
  if h.hexdigest()!=expected:raise ValueError('Compression verification failed: '+relative)
  records.append({'path':relative,'bytes':p.stat().st_size,'sha256':expected,'packed':packed.relative_to(ROOT).as_posix(),'packedBytes':packed.stat().st_size,'packedSha256':digest(packed)})
 manifest={'formatVersion':1,'purpose':'Byte-exact evidence compression; restore before using reports that are absent in a fresh clone.','restoreCommand':'python reverse-engineering/tools/publish-evidence.py --restore','artifacts':records}
 MANIFEST.write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
 ignore=ROOT/'.gitignore';text=ignore.read_text(encoding='utf-8');start='# BEGIN COMPRESSED EVIDENCE';end='# END COMPRESSED EVIDENCE';head,tail=text.split(start,1);_,tail=tail.split(end,1);ignore.write_text(head+start+'\n'+''.join('/'+r['path']+'\n'for r in records)+end+tail,encoding='utf-8')
 print(json.dumps({'packedArtifacts':len(records),'sourceBytes':sum(r['bytes']for r in records),'packedBytes':sum(r['packedBytes']for r in records),'verified':'Every gzip payload matches its recorded source SHA256.'}))

def restore():
 restored=existing=0
 for r in json.loads(MANIFEST.read_text(encoding='utf-8'))['artifacts']:
  source=contained(r['packed']);target=contained(r['path'])
  if digest(source)!=r['packedSha256']:raise ValueError('Packed SHA256 mismatch: '+r['packed'])
  if target.exists():
   if digest(target)!=r['sha256']:raise ValueError('Refusing to overwrite differing local file: '+r['path'])
   existing+=1;continue
  target.parent.mkdir(parents=True,exist_ok=True);fd,temp_name=tempfile.mkstemp(prefix=target.name+'.restore-',dir=target.parent);os.close(fd);temp=Path(temp_name)
  try:
   with gzip.open(source,'rb')as src,temp.open('wb')as dst:
    for chunk in iter(lambda:src.read(1024*1024),b''):dst.write(chunk)
   if temp.stat().st_size!=r['bytes']or digest(temp)!=r['sha256']:raise ValueError('Restored data mismatch: '+r['path'])
   os.replace(temp,target);restored+=1
  finally:
   if temp.exists():temp.unlink()
 print(json.dumps({'restored':restored,'alreadyMatching':existing}))

if __name__=='__main__':
 ap=argparse.ArgumentParser(description=__doc__);mode=ap.add_mutually_exclusive_group(required=True);mode.add_argument('--pack',action='store_true');mode.add_argument('--restore',action='store_true');args=ap.parse_args();previous=json.loads(MANIFEST.read_text(encoding='utf-8'))['artifacts']if MANIFEST.exists()else[]
 pack()if args.pack else restore()
