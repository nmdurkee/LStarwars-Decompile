"""Validate all recovered base routing tables with original PC next-hop code."""
import importlib.util,json,gzip,struct,random,time
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn.x86_const import UC_X86_REG_EAX
n=native.NativeX86(); index=json.loads((native.BASE/'reports/gameplay-binary/index.json').read_text());errors=[];files=0;paths=0;checks=0;distancechecks=0;rng=random.Random(0x51be90);started=time.time()
PATH=n.DATA;PACKET=n.DATA+0x1000;DUMMY=n.DATA+0x2000;OUT=n.DATA+0x3000;NODES=n.DATA+0x10000;CNXS=n.DATA+0x20000;ADJ=n.DATA+0x40000;ROWPTR=n.DATA+0x50000;MATRIX=n.DATA+0x51000
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
FLTMAX=f32(3.4028234663852886e38)
def model_distance(p,m,start,dest):
    if start==dest:return 0.0
    cur=start;total=0.0;previous=-1;seen=set()
    while cur!=dest:
        if cur in seen:raise ValueError('Cycle')
        seen.add(cur);slot=m[cur*len(p['points'])+dest]
        if slot==255:return FLTMAX
        ix=p['points'][cur]['connectionIndices'][slot];c=p['connections'][ix]
        if ix==previous:return total
        total=f32(total+c['distanceCandidates'][0]);cur=c['from'] if c['to']==cur else c['to'];previous=ix
    return total
for entry in [e for e in index['entries'] if e['type']=='AI2' and not e.get('error')]:
    d=json.loads(gzip.decompress((native.BASE.parent/entry['output']).read_bytes()));files+=1
    for pi,p in enumerate(d['paths']):
        paths+=1;count=len(p['points']);matrix=bytes.fromhex(p['routingMatrix']['hex']);assert count<256
        n.write(PATH,bytes(0xa8));n.write(PACKET,bytes(0x200));n.write(DUMMY,bytes(36));n.write(NODES,bytes(count*92));n.write(CNXS,bytes(len(p['connections'])*36));n.write(MATRIX,matrix)
        n.pack('<B',PATH+0x10,count);n.pack('<I',PATH+0x7c,NODES);n.pack('<I',PATH+0x80,CNXS);n.pack('<I',PATH+0x84,ROWPTR)
        n.pack('<I',PACKET+0x158,PATH);n.pack('<I',PACKET+0x15c,DUMMY);n.pack('<B',PACKET+0x13c,255)
        for i,c in enumerate(p['connections']):
            q=CNXS+i*36;n.pack('<4I',q,c['toFlags'],c['fromFlags'],c['toFlags'],c['fromFlags']);n.pack('<BBHH',q+0x10,c['to'],c['from'],*c['unknownShorts']);n.pack('<2f',q+0x18,*c['distanceCandidates'])
        adj_at=ADJ
        for i,point in enumerate(p['points']):
            q=NODES+i*92;connections=point['connectionIndices'];n.pack('<I',ROWPTR+i*4,MATRIX+i*count);n.pack('<B',q+0x28,len(connections));n.pack('<I',q+0x34,adj_at);n.pack('<BB',q+0x2e,255,255);n.pack('<3f',q+4,*point['position'])
            for ci in connections:n.pack('<I',adj_at,CNXS+ci*36);adj_at+=4
        assert adj_at<ROWPTR
        for start,point in enumerate(p['points']):
            n.pack('<BB',DUMMY+0x10,start,start)
            for dest in range(count):
                n.pack('<I',PACKET+0x17c,NODES+dest*92);n.pack('<I',OUT,0xdeadbeef);slot=matrix[start*count+dest];ci=point['connectionIndices'][slot] if slot<len(point['connectionIndices']) else None;want=CNXS+ci*36 if ci is not None else 0
                got=n.call(0x51be90,[OUT],{UC_X86_REG_EAX:PACKET});direction=n.unpack('<I',OUT)[0];wantdir=int(p['connections'][ci]['to']!=start) if ci is not None else 0xdeadbeef;checks+=1
                if got!=want or direction!=wantdir:errors.append({'source':entry['source'],'path':pi,'start':start,'destination':dest,'native':hex(got),'expected':hex(want),'direction':direction,'expectedDirection':wantdir})
        # Original float-return function, captured with a synthetic FSTP instruction after return.
        pairs=set((a,b) for a in [0,count//2,count-1] for b in [0,count//2,count-1]) if count else set()
        pairs.update((rng.randrange(count),rng.randrange(count)) for _ in range(min(16,count*count)))
        for start,dest in pairs:
            n.pack('<BB',NODES+start*92+0x2e,255,255);n.call(0x51a890,[PATH,start,dest,255,0],count=200000)
            n.write(n.STOP,b'\xd9\x1d'+struct.pack('<I',OUT));n.mu.emu_start(n.STOP,n.STOP+6,count=1);got=n.unpack('<f',OUT)[0];want=model_distance(p,matrix,start,dest);distancechecks+=1
            if got!=want:errors.append({'source':entry['source'],'path':pi,'start':start,'destination':dest,'nativeDistance':got,'expectedDistance':want})
        if paths%20==0:print(json.dumps({'paths':paths,'nextHopCases':checks,'distanceCases':distancechecks,'mismatches':len(errors)}),flush=True)
report={'binarySha256':n.sha256,'method':'Materialize runtime path/point/connection records using decoded AI2 fields and the PC loader/writer layout; run original0x51be90 on every base-matrix cell and original0x51a890 on seeded representative pairs. No native callee replaced. Float return captured with a synthetic FSTP after the original returns.','functions':['0x51be90','0x51a890'],'files':files,'paths':paths,'nextHopAndDirectionCases':checks,'distanceCases':distancechecks,'mismatches':len(errors),'errors':errors[:40],'elapsedSeconds':time.time()-started,'limits':['Tests base routes with selected-route index255 and exclusion mask0. Named subroute groups and dynamic special transforms are not covered.','Runtime records are materialized from bounded decoded fields; this does not itself execute or validate every branch of the AI2 loader.','Live character capability filters, collision steering and dynamic graph updates remain separate.']}
(native.BASE/'reports/gameplay-navigation-native-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps(report,indent=2));assert not errors
