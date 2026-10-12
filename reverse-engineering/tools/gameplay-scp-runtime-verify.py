"""Execute PC condition chains and action scheduling against synthetic script records."""
import importlib.util, json, itertools, struct
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn.x86_const import UC_X86_REG_EAX
n=native.NativeX86(); errors=[]; counts={}; D=n.DATA
def check(kind,got,want,detail=None):
    counts[kind]=counts.get(kind,0)+1
    if got!=want:errors.append(dict(kind=kind,got=got,want=want,detail=detail))
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
LIST=D; PACKET=D+0x100; RECORDS=D+0x400; DEFINITION=D+0x900; SCRIPT=D+0xa00; STATE=D+0xb00
def predicates(timer,entries):
    n.write(D,bytes(0x1000));n.pack('<f',PACKET+0x24,timer);n.pack('<2I',DEFINITION,0,0x514990)
    n.pack('<I',LIST,RECORDS if entries else 0)
    for i,(op,threshold,chain,previous) in enumerate(entries):
        p=RECORDS+i*0x30;n.pack('<I',p,p+0x30 if i+1<len(entries) else 0);n.pack('<f',p+8,threshold);n.pack('<BBH',p+12,op,0,1 if chain else 0)
        n.pack('<I',p+0x1c,0x801768 if previous else DEFINITION)
    return n.call(0x52c880,[0,LIST,0,PACKET],regs={UC_X86_REG_EAX:0})
ops=[lambda a,b:a==b,lambda a,b:a<b,lambda a,b:a>b,lambda a,b:a<=b,lambda a,b:a>=b,lambda a,b:a!=b]
for op in range(6):
    for a,b in itertools.product([-5.,-0.,0.,0.25,1.,8.],repeat=2):
        got=predicates(a,[(op,b,False,False)]);check('comparison',got,RECORDS if ops[op](a,b) else 0,dict(op=op,lhs=a,rhs=b))
# Consecutive records marked bit1 are an AND group; the last record selects the target.
for length in range(1,6):
    for truth in itertools.product([False,True],repeat=length):
        entries=[(0,1. if v else 2.,i+1<length,i>0) for i,v in enumerate(truth)]
        check('and-chain-previous-result',predicates(1.,entries),RECORDS+(length-1)*0x30 if all(truth) else 0,list(truth))
# Unchained records are alternatives: return first matching record.
for truth in itertools.product([False,True],repeat=4):
    entries=[(0,1. if v else 2.,False,i>0) for i,v in enumerate(truth)]
    want=next((RECORDS+i*0x30 for i,v in enumerate(truth) if v),0)
    check('first-matching-alternative',predicates(1.,entries),want,list(truth))
check('empty-condition-list',predicates(0.,[]),0)

# Actual 0x52cc90 scheduler calls actual ResetTimer and Idle handlers. No replacement callbacks.
# ResetTimer's zero-argument form sets timer to zero; Idle with no args waits indefinitely.
actionTrace=[]
for first in [0,1]:
    n.write(D,bytes(0x1000));n.pack('<I',PACKET+4,SCRIPT);n.pack('<I',PACKET+8,STATE);n.pack('<I',PACKET+12,RECORDS)
    n.pack('<I',PACKET+0x50,first);n.pack('<f',PACKET+0x24,5.);n.pack('<I',STATE+0x10,RECORDS)
    n.pack('<I',RECORDS,RECORDS+0x20);n.pack('<I',RECORDS+0x10,DEFINITION);n.pack('<2I',DEFINITION,0,0x515890)
    n.pack('<I',RECORDS+0x30,DEFINITION+0x10);n.pack('<2I',DEFINITION+0x10,0,0x5159a0)
    n.call(0x52cc90,[0,0,0,PACKET,bits(0.25)])
    timer=n.unpack('<f',PACKET+0x24)[0]; action=n.unpack('<I',PACKET+12)[0];flags=n.unpack('<I',PACKET+0x50)[0]
    check('scheduler-instant-action-advances',action,RECORDS+0x20,first);check('scheduler-initialization-flag-cleared',flags&1,0,first)
    check('reset-timer-only-on-entry',timer,0. if first else 5.25,first)
    n.call(0x52cc90,[0,0,0,PACKET,bits(0.25)])
    check('idle-blocks-next-frame',n.unpack('<I',PACKET+12)[0],RECORDS+0x20,first)
    actionTrace.append(dict(initialFlag=first,timerAfterFirstTick=timer,timerAfterSecondTick=n.unpack('<f',PACKET+0x24)[0],actionAfterTwoTicks=hex(n.unpack('<I',PACKET+12)[0])))
report=dict(binarySha256=n.sha256,method='Original PC 0x52c880 and 0x52cc90 on synthetic linked records, original Timer/PreviousResult/ResetTimer/Idle handlers and linked-list helpers. EAX condition-bank index fixed to zero. No function replacement or OS API.',checks=sum(counts.values()),categories=counts,mismatches=len(errors),errors=errors[:40],actionTrace=actionTrace,contracts={'comparators':['==','<','>','<=','>=','!='],'conditionChain':'Bit0 at condition+0x0e joins the next condition with AND. An unmarked passing final record is returned; a failing member skips the remainder of its marked group. Unchained groups are ordered alternatives. PreviousResult has a null handler and reuses the preceding float result.','action':'Packet+0x24 timer increments by delta each update. Handler return zero retains current action for another frame; nonzero advances within the same update. Packet+0x50 bit0 marks the first call of an action; the dispatcher clears it before calling the handler and passes firstCall=1.'},limits=['No full gameplay script or inter-script interrupt/state transition emulation.','Condition variable operands, dynamic random operands and condition-bank1 remain outside these fixtures.','No claim that every parsed source file is reachable during ordinary gameplay.'])
(native.BASE/'reports/gameplay-scp-runtime-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['checks','categories','mismatches','errors','actionTrace']},indent=2));assert not errors
