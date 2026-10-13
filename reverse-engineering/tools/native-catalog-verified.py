"""Add independently verified native entry disassembly to the existing catalog."""
import json,sqlite3,hashlib,time
from pathlib import Path
b=Path(__file__).resolve().parent.parent
r=json.loads((b/'reports/native-verified-entry-index.json').read_text())
if r['processed']!=r['expected']or r['failed']:raise SystemExit('Verified entry index incomplete')
db=sqlite3.connect(b/'reports/native-catalog.sqlite');added=0
for item in r['items']:
 address=item['address']
 if db.execute('SELECT 1 FROM functions WHERE address=?',(address,)).fetchone():continue
 text=(b/item['file']).read_text();row=(address,item['name'],item['file'],item['evidence'],'native-verified-disassembly',hashlib.sha256(text.encode()).hexdigest(),len(text),'[]','[]')
 db.execute('INSERT INTO functions VALUES(?,?,?,?,?,?,?,?,?)',row);db.execute('INSERT INTO code_fts VALUES(?,?,?)',(address,item['name'],text));added+=1
report=json.loads((b/'reports/native-catalog.json').read_text());report['updated']=time.time();report['functions']=db.execute('SELECT count(*) FROM functions').fetchone()[0];report['independentlyVerifiedDisassemblyEntries']=db.execute("SELECT count(*) FROM functions WHERE profile='native-verified-disassembly'").fetchone()[0]
report['verifiedEntryEvidence']='reports/native-verified-entry-index.json'
for k,v in report.items():db.execute('INSERT OR REPLACE INTO metadata VALUES(?,?)',(k,json.dumps(v)))
db.commit();report['integrityCheck']=db.execute('PRAGMA integrity_check').fetchone()[0];db.close();report['databaseBytes']=(b/'reports/native-catalog.sqlite').stat().st_size;report['databaseSha256']=hashlib.sha256((b/'reports/native-catalog.sqlite').read_bytes()).hexdigest();(b/'reports/native-catalog.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({'added':added,'functions':report['functions'],'independentlyVerifiedDisassemblyEntries':report['independentlyVerifiedDisassemblyEntries'],'integrityCheck':report['integrityCheck']}))
