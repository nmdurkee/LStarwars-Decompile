"""Build a reproducible SQLite/FTS catalog of native pseudocode, evidence, names and asset paths.
Calls are textual pseudocode references, not a complete proven native call graph.
"""
import json,re,sqlite3,hashlib,time
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent
load=lambda name:json.loads((BASE/name).read_text(encoding='utf-8-sig'))
first=load('reports/native-corpus-index.json');expanded=load('reports/native-expanded-corpus-index.json')
if expanded['processed']!=expanded['expected']:raise SystemExit('Wait for expanded corpus completion before building final database')
items={}
profiles=[('dispatch-seeded',first),('expanded-boundary-seeded',expanded)]
supplement=BASE/'reports/native-supplemental-corpus-index.json'
if supplement.exists():profiles.append(('supplemental-rtti-seeded',load('reports/native-supplemental-corpus-index.json')))
verified=BASE/'reports/native-verified-entry-index.json'
if verified.exists():profiles.append(('native-verified-disassembly',load('reports/native-verified-entry-index.json')))
for profile,report in profiles:
 for item in report['items']:
  if item['status']=='ok':items[item['address']]={**item,'profile':profile}
dbpath=BASE/'reports/native-catalog.sqlite';db=sqlite3.connect(dbpath)
db.executescript('''
DROP TABLE IF EXISTS code_fts;DROP TABLE IF EXISTS functions;DROP TABLE IF EXISTS call_candidates;DROP TABLE IF EXISTS names;DROP TABLE IF EXISTS sources;DROP TABLE IF EXISTS assets;DROP TABLE IF EXISTS metadata;
CREATE TABLE functions(address TEXT PRIMARY KEY,name TEXT,path TEXT,evidence TEXT,profile TEXT,sha256 TEXT,characters INTEGER,warnings TEXT,string_literals TEXT);
CREATE VIRTUAL TABLE code_fts USING fts5(address UNINDEXED,name,pseudocode,tokenize='unicode61');
CREATE TABLE call_candidates(caller TEXT,callee TEXT,occurrences INTEGER,kind TEXT);
CREATE INDEX calls_callee ON call_candidates(callee);CREATE INDEX calls_caller ON call_candidates(caller);
CREATE TABLE names(address TEXT,name TEXT,table_address TEXT,scope TEXT,status TEXT,evidence TEXT);
CREATE INDEX names_name ON names(name);CREATE INDEX names_address ON names(address);
CREATE TABLE sources(address TEXT,source_path TEXT,instruction_address TEXT,evidence TEXT);
CREATE TABLE assets(archive TEXT,path TEXT PRIMARY KEY,extension TEXT,offset INTEGER,stored_bytes INTEGER,expanded_bytes INTEGER,flags INTEGER,filename_hash INTEGER);
CREATE TABLE metadata(key TEXT PRIMARY KEY,value TEXT);
''')
report={'generated':time.time(),'functions':len(items),'supplementalFunctions':sum(i['profile']=='supplemental-rtti-seeded' for i in items.values()),'initialFunctions':first['succeeded'],'expandedFunctions':expanded['succeeded'],'initialOnlyFunctions':sum(i['profile']=='dispatch-seeded' for i in items.values()),'textualCallEdges':0,'strings':0,'warningFunctions':0,'names':0,'sourceReferences':0,'assetPaths':0,'limits':['Pseudocode is decompiler output, not original buildable C/C++.','Expanded boundaries are caller assertions with documented heuristic provenance.','Call candidates are textual direct FUN_* references in decompiled bodies; indirect calls, external symbol calls and optimized flows can be absent. They are not a verified complete call graph.','Candidate names from broad table scanning remain unconfirmed; explicitly bounded dispatch tables are tagged separately.','Function names/types and source attribution can be inferred or incomplete.']}
for addr,item in sorted(items.items(),key=lambda t:int(t[0],16)):
 text=(BASE/item['file']).read_text(encoding='utf-8');body=text[text.find('{'):];warnings=re.findall(r'/\*\s*WARNING:(.*?)\*/',text,re.S);strings=re.findall(r'"(?:[^"\\]|\\.)*"',body)
 row=(addr,item['name'],item['file'],item['evidence'],item['profile'],hashlib.sha256(text.encode()).hexdigest(),len(text),json.dumps(warnings),json.dumps(strings))
 db.execute('INSERT INTO functions VALUES(?,?,?,?,?,?,?,?,?)',row);db.execute('INSERT INTO code_fts VALUES(?,?,?)',(addr,item['name'],text))
 calls={}
 for target in re.findall(r'\bFUN_([0-9a-fA-F]{6,8})\s*\(',body):target=hex(int(target,16));calls[target]=calls.get(target,0)+1
 for target,count in calls.items():db.execute('INSERT INTO call_candidates VALUES(?,?,?,?)',(addr,target,count,'pseudocode-direct-call-candidate'))
 report['textualCallEdges']+=len(calls);report['strings']+=len(strings);report['warningFunctions']+=bool(warnings)
for row in load('reports/dispatch-candidates.json')['entries']:
 db.execute('INSERT INTO names VALUES(?,?,?,?,?,?)',(row['functionVa'],row['name'],row['tableVa'],'broad-static-scan','unconfirmed-candidate','reports/dispatch-candidates.json'));report['names']+=1
for table in load('reports/gameplay-native-dispatch/tables.json')['tables']:
 for row in table['entries']:
  if not row.get('functionVa'):continue
  db.execute('INSERT INTO names VALUES(?,?,?,?,?,?)',(row['functionVa'],row['name'],row['tableVa'],table['id'],'bounded-native-dispatch',json.dumps(table['evidence'])));report['names']+=1
for row in load('reports/native-contract-aliases.json')['entries']:
 db.execute('INSERT INTO names VALUES(?,?,?,?,?,?)',(row['address'],row['name'],None,'investigation-contract-label',row['status'],row['evidence']));report['names']+=1
for source in load('reports/native-source-map.json'):
 for ref in source['references']:
  p=ref['result'].get('procedure')
  if p:db.execute('INSERT INTO sources VALUES(?,?,?,?)',(p['address'],source['source'],ref['address'],ref['evidence']));report['sourceReferences']+=1
for a in load('reports/all-assets.json'):
 db.execute('INSERT INTO assets VALUES(?,?,?,?,?,?,?,?)',(a['archive'],a['path'],Path(a['path']).suffix.upper(),a['offset'],a['storedSize'],a['size'],a['flags'],a['hash']));report['assetPaths']+=1
for k,v in report.items():db.execute('INSERT INTO metadata VALUES(?,?)',(k,json.dumps(v)))
db.commit();report['integrityCheck']=db.execute('PRAGMA integrity_check').fetchone()[0];report['exampleSearches']={q:db.execute('SELECT count(*) FROM code_fts WHERE code_fts MATCH ?',(q,)).fetchone()[0] for q in ['CameraCut','vertexProgram','LZ2K']};db.close()
report['databaseBytes']=dbpath.stat().st_size;(BASE/'reports/native-catalog.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
