"""Add supplemental decompiles to the native catalog without re-reading the full corpus."""
import json,re,sqlite3,hashlib,time
from pathlib import Path
b=Path(__file__).resolve().parent.parent
r=json.loads((b/'reports/native-supplemental-corpus-index.json').read_text())
if r['processed']!=r['expected'] or r['failed']:raise SystemExit('Supplemental corpus is incomplete')
db=sqlite3.connect(b/'reports/native-catalog.sqlite');added=0
for item in r['items']:
 addr=item['address']
 if db.execute('SELECT 1 FROM functions WHERE address=?',(addr,)).fetchone():continue
 text=(b/item['file']).read_text(encoding='utf-8');body=text[text.find('{'):];warnings=re.findall(r'/\*\s*WARNING:(.*?)\*/',text,re.S);strings=re.findall(r'"(?:[^"\\]|\\.)*"',body)
 row=(addr,item['name'],item['file'],item['evidence'],'supplemental-rtti-seeded',hashlib.sha256(text.encode()).hexdigest(),len(text),json.dumps(warnings),json.dumps(strings))
 db.execute('INSERT INTO functions VALUES(?,?,?,?,?,?,?,?,?)',row);db.execute('INSERT INTO code_fts VALUES(?,?,?)',(addr,item['name'],text));calls={}
 for target in re.findall(r'\bFUN_([0-9a-fA-F]{6,8})\s*\(',body):target=hex(int(target,16));calls[target]=calls.get(target,0)+1
 for target,count in calls.items():db.execute('INSERT INTO call_candidates VALUES(?,?,?,?)',(addr,target,count,'pseudocode-direct-call-candidate'))
 added+=1
report=json.loads((b/'reports/native-catalog.json').read_text());report['updated']=time.time();report['functions']=db.execute('SELECT count(*) FROM functions').fetchone()[0];report['supplementalFunctions']=db.execute("SELECT count(*) FROM functions WHERE profile='supplemental-rtti-seeded'").fetchone()[0];report['textualCallEdges']=db.execute('SELECT count(*) FROM call_candidates').fetchone()[0];report['strings']=sum(len(json.loads(x[0])) for x in db.execute('SELECT string_literals FROM functions'));report['warningFunctions']=sum(bool(json.loads(x[0])) for x in db.execute('SELECT warnings FROM functions'))
for k,v in report.items():db.execute('INSERT OR REPLACE INTO metadata VALUES(?,?)',(k,json.dumps(v)))
db.commit();report['integrityCheck']=db.execute('PRAGMA integrity_check').fetchone()[0];db.close();report['databaseBytes']=(b/'reports/native-catalog.sqlite').stat().st_size;report['databaseSha256']=hashlib.sha256((b/'reports/native-catalog.sqlite').read_bytes()).hexdigest();(b/'reports/native-catalog.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({'added':added,'functions':report['functions'],'supplementalFunctions':report['supplementalFunctions'],'integrityCheck':report['integrityCheck']}))
