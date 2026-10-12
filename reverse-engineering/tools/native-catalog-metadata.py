"""Join original RTTI and evidence-backed subsystem labels into the search catalog."""
import sqlite3,json,hashlib
from pathlib import Path
base=Path(__file__).resolve().parent.parent;db=sqlite3.connect(base/'reports/native-catalog.sqlite');rtti=json.loads((base/'reports/native-rtti.json').read_text());aliases=json.loads((base/'reports/native-contract-aliases.json').read_text())
db.executescript('''DROP TABLE IF EXISTS rtti_types;DROP TABLE IF EXISTS rtti_bases;DROP TABLE IF EXISTS rtti_vtable_slots;
CREATE TABLE rtti_types(address TEXT PRIMARY KEY,mangled_name TEXT,typeinfo_vftable TEXT);
CREATE TABLE rtti_bases(hierarchy_address TEXT,ordinal INTEGER,mangled_name TEXT,mdisp INTEGER,pdisp INTEGER,vdisp INTEGER,attributes INTEGER,contained_bases INTEGER);
CREATE TABLE rtti_vtable_slots(vtable TEXT,class_name TEXT,object_offset INTEGER,slot INTEGER,target TEXT);
CREATE INDEX virtual_target ON rtti_vtable_slots(target);''')
for row in rtti['types']:db.execute('INSERT INTO rtti_types VALUES(?,?,?)',(row['descriptor'],row['name'],row['typeInfoVftable']))
for h in rtti['hierarchies']:
 for i,row in enumerate(h['bases']):db.execute('INSERT INTO rtti_bases VALUES(?,?,?,?,?,?,?,?)',(h['address'],i,row['name'],row['mdisp'],row['pdisp'],row['vdisp'],row['attributes'],row['containedBases']))
for v in rtti['vftables']:
 for s in v['slots']:db.execute('INSERT INTO rtti_vtable_slots VALUES(?,?,?,?,?)',(v['address'],v['className'],v['objectOffset'],s['slot'],s['target']))
db.execute("DELETE FROM names WHERE scope='investigation-contract-label'")
for row in aliases['entries']:db.execute('INSERT INTO names VALUES(?,?,?,?,?,?)',(row['address'],row['name'],None,'investigation-contract-label',row['status'],row['evidence']))
db.commit();report=json.loads((base/'reports/native-catalog.json').read_text());report['rtti']=rtti['counts'];report['names']=db.execute('SELECT count(*) FROM names').fetchone()[0];report['exampleNamedSearches']={name:db.execute('SELECT count(*) FROM names WHERE name=?',(name,)).fetchone()[0] for name in ['CameraCut','ConstructShaderManagerHLSL']};report['integrityCheck']=db.execute('PRAGMA integrity_check').fetchone()[0];db.close();report['databaseBytes']=(base/'reports/native-catalog.sqlite').stat().st_size;report['databaseSha256']=hashlib.sha256((base/'reports/native-catalog.sqlite').read_bytes()).hexdigest();(base/'reports/native-catalog.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:report[k] for k in ['functions','rtti','exampleNamedSearches','integrityCheck','databaseBytes']}))
