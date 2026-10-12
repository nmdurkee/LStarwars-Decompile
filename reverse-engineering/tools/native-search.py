"""Search recovered pseudocode without requiring a Ghidra session.
Examples: python native-search.py CameraCut
          python native-search.py --address 0x54b3d0
          python native-search.py --callers 0x4faea0
          python native-search.py --class HLSLShaderBuilder
"""
import sqlite3,sys,json
from pathlib import Path
base=Path(__file__).resolve().parent.parent;db=sqlite3.connect('file:'+str(base/'reports/native-catalog.sqlite').replace('\\','/')+'?mode=ro',uri=True);db.row_factory=sqlite3.Row
args=sys.argv[1:]
if not args:raise SystemExit(__doc__)
if args[0]=='--address':
 addr=hex(int(args[1],16));result={'function':[dict(x) for x in db.execute('SELECT * FROM functions WHERE address=?',(addr,))],'names':[dict(x) for x in db.execute('SELECT * FROM names WHERE address=?',(addr,))],'sources':[dict(x) for x in db.execute('SELECT * FROM sources WHERE address=?',(addr,))],'virtualSlots':[dict(x) for x in db.execute('SELECT * FROM rtti_vtable_slots WHERE target=?',(addr,))]}
elif args[0]=='--class':result={'types':[dict(x) for x in db.execute('SELECT * FROM rtti_types WHERE mangled_name LIKE ?',('%'+' '.join(args[1:])+'%',))],'virtualSlots':[dict(x) for x in db.execute('SELECT r.*,f.path FROM rtti_vtable_slots r LEFT JOIN functions f ON f.address=r.target WHERE r.class_name LIKE ?',('%'+' '.join(args[1:])+'%',))]}
elif args[0]=='--callers':result=[dict(x) for x in db.execute('SELECT c.*,f.path FROM call_candidates c LEFT JOIN functions f ON f.address=c.caller WHERE callee=?',(hex(int(args[1],16)),))]
else:
 named=[dict(x) for x in db.execute('SELECT n.*,f.path FROM names n LEFT JOIN functions f ON f.address=n.address WHERE n.name LIKE ? LIMIT 50',('%'+' '.join(args)+'%',))]
 hits=[dict(x) for x in db.execute('SELECT f.address,f.name,f.path,f.evidence,snippet(code_fts,2,\'[\',\']\',\'...\',30) AS snippet FROM code_fts JOIN functions f ON code_fts.address=f.address WHERE code_fts MATCH ? ORDER BY rank LIMIT 50',(' '.join(args),))]
 result={'namedMatches':named,'pseudocodeMatches':hits}
print(json.dumps(result,indent=2));db.close()
