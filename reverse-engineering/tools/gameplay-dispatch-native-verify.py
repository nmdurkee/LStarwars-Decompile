"""Original PC script lookups and GIT Boolean/count predicates in synthetic memory."""
import importlib.util, json, gzip, itertools
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn.x86_const import UC_X86_REG_EDI
n=native.NativeX86(); root=native.BASE; errors=[]; counts={}
def check(kind,got,want,detail=None):
    counts[kind]=counts.get(kind,0)+1
    if got!=want:errors.append({'kind':kind,'got':got,'want':want,'detail':detail})
rows=json.loads(gzip.decompress((root/'reports/gameplay-native-dispatch/rows.json.gz').read_bytes()))
tables=json.loads((root/'reports/gameplay-native-dispatch/tables.json').read_text())['tables'];tables={x['id']:x for x in tables}
n.call(0x512fb0,[0x7f6858]);n.call(0x512f60,[0x7f7060])
lookups=[]
for kind,fn,ordered in [('scp-condition',0x512ea0,['scp-game-conditions','scp-builtin-conditions']),('scp-action',0x512f00,['scp-game-actions','scp-builtin-actions'])]:
    names=list(dict.fromkeys([e['name'] for table in ordered for e in tables[table]['entries']]+[r['name'] for r in rows if r['kind']==kind]+['__missing_native_test__']))
    for name in names:
        candidates=[e for table in ordered for e in tables[table]['entries'] if e['name'].lower()==name.lower()];want=int(candidates[0]['tableVa'],16) if candidates else 0
        for spelling in [name,name.lower(),name.upper()]:
            n.write(n.DATA,spelling.encode('latin1')+b'\0');got=n.call(fn,regs={UC_X86_REG_EDI:n.DATA});check('native-'+kind+'-lookup',got,want,spelling)
        lookups.append({'kind':kind,'name':name,'selectedTableVa':hex(want) if want else None,'selectedHandler':candidates[0]['functionVa'] if candidates else None,'duplicateTableNames':len(candidates)})
# PC condition enum table proves names/types independently of the public source.
enum=[]
for i in range(6):
    p=0x805538+i*12;code,name,loader=n.unpack('<3I',p);enum.append({'code':code,'name':n.read(name,32).split(b'\0')[0].decode(),'parameterLoader':hex(loader) if loader else None})
FLOW=n.DATA+0x1000;BOX=n.DATA+0x2000;COND=n.DATA+0x3000;PARENTS=n.DATA+0x4000;PARENTPTR=n.DATA+0x5000;OUTPUTS=n.DATA+0x6000
def condition_case(code,states,threshold=0,loop_skip=0,monitoring=False):
    n.write(BOX,bytes(32));n.write(COND,bytes(4));n.write(FLOW,bytes(32));n.pack('<BBBB',BOX,len(states),loop_skip,0,1);n.pack('<H',BOX+10,0x400 if monitoring else 0)
    n.pack('<I',BOX+12,COND if code is not None else 0);n.pack('<I',BOX+16,PARENTPTR);n.pack('<I',BOX+24,OUTPUTS)
    if code is not None:n.pack('<BB',COND,code,threshold)
    for i,state in enumerate(states):
        parent=PARENTS+i*32;n.write(parent,bytes(32));n.pack('<B',parent+3,2);n.pack('<H',parent+10,2 if state else 0);n.pack('<I',PARENTPTR+i*4,parent);n.pack('<B',OUTPUTS+i,0)
    return n.call(0x59db00,[FLOW,BOX])
def expected(code,states,threshold,loop_skip,monitoring):
    total=sum(states);count=len(states)
    if code is None or code==0:return int(total==count)
    if code==1:return int(total>=1)
    if code==2:return int(total==0)
    if code==3:return int(total>=threshold) if count else int(threshold==0)
    if code==5:return int(total==threshold)
    if code==4:return int(total>=count-(loop_skip if monitoring else 0))
truth_examples=[]
for parentcount in range(6):
    for states in itertools.product([False,True],repeat=parentcount):
        for code in [None,0,1,2,3,4,5]:
            thresholds=range(parentcount+2) if code in (3,5) else [0]
            for threshold in thresholds:
                for monitor,skip in ([(False,0)]+[(True,k) for k in range(parentcount+1)] if code==4 else [(False,0)]):
                    got=condition_case(code,states,threshold,skip,monitor);want=expected(code,states,threshold,skip,monitor);detail={'code':code,'states':list(states),'threshold':threshold,'loopSkip':skip,'monitorFlag':monitor};check('git-condition-predicate',got,want,detail)
                    if parentcount==0:truth_examples.append({**detail,'result':got})
report={'binarySha256':n.sha256,'method':'Original x86 lookup routines use actual PC tables with name passed in EDI (a custom register ABI missed by initial C pseudocode). GIT 0x59db00 is executed with original action-node output callback0x59e080 and synthetic parent completion flags. No callback replacement or OS API.','functions':['0x512fb0','0x512f60','0x512ea0','0x512f00','0x59db00','0x59e080'],'checks':sum(counts.values()),'categories':counts,'mismatches':len(errors),'errors':errors[:40],'lookupResults':lookups,'gitConditionEnum':enum,'zeroParentCases':truth_examples,'contracts':{'lookup':'Case insensitive; game table wins over built-in, first name entry wins; unknown returnsNULL. PreviousResult has a real table entry withNULL handler.','All':'All parent output checks nonzero; true for zero parents.','Any':'At least one parent output nonzero; false for zero parents.','None':'No parent output nonzero; true for zero parents.','Sum':'At least threshold parent outputs nonzero; for zero parents true only for zero threshold. Counts booleans, not magnitudes.','Exactly':'Number of nonzero parent outputs equals threshold.','Loop':'Requires all parent outputs, or totalParents-loopSkip when flag0x400 is set. Successful predicate then propagates/reset-walks children; this side effect excluded by zero-child fixtures.'},'limits':['Parent fixtures use action-node kind2 completion bits; live gizmo callback values and whole graph scheduling not exhaustively emulated.','Loop predicate verified with no children; recursive reset/walk side effects not validated here.','No complete SCP interpreter or execution of gameplay action handlers.']}
(root/'reports/gameplay-dispatch-native-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['checks','categories','mismatches','errors','gitConditionEnum']},indent=2));assert not errors
