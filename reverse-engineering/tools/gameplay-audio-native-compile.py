"""Recover actual PC audio definition records by executing original parsers on supplied CFG lines.
No disk APIs are emulated or invoked. Line/token buffers and arenas are synthetic memory.
"""
import importlib.util, json, struct, hashlib
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
n=native.NativeX86(); cfg=json.loads((native.BASE/'reports/gameplay-media/sound-config.json').read_text())
PARSER=n.DATA; LINE=n.DATA+0x1000; TOKEN=n.DATA+0x2000; DEFS=n.DATA+0x10000; BACKUP=n.DATA+0x30000; FILES=n.DATA+0x50000; BUCKETS=n.DATA+0x60000; ARENA=n.DATA+0x61000
def text_at(ptr,maxbytes=128):return n.read(ptr,maxbytes).split(b'\0')[0].decode('latin1') if ptr else None
n.write(DEFS,bytes(0x19000));n.write(BACKUP,bytes(0x19000));n.write(FILES,bytes(0xaf00));n.write(BUCKETS,b'\xff'*512)
for address,value in [(0x2947b74,DEFS),(0x292fda4,BACKUP),(0x2947d70,FILES),(0x292fda0,BUCKETS),(0x2962014,0),(0x2962018,0),(0x296201c,0),(0x2962020,0),(0x2962024,0),(0x296202c,0),(0x2962044,0)]:n.pack('<I',address,value)
n.pack('<I',ARENA,ARENA+16);n.call(0x650280,[ARENA])
def line_parser(line):
    b=line.encode('latin1');assert len(b)<1024
    n.write(PARSER,bytes(0x584));n.write(LINE,b+b'\0');n.write(TOKEN,bytes(1024))
    for off,val in [(0x50c,LINE),(0x510,TOKEN),(0x514,1024),(0x518,1024),(0x520,0)]:n.pack('<I',PARSER+off,val)
def decode_def(index,sourceLine):
    p=DEFS+index*64;b=n.read(p,64);flags=struct.unpack_from('<I',b,4)[0]
    return {'id':index,'line':sourceLine,'name':text_at(struct.unpack_from('<I',b,0)[0],32),'flags':flags,'sampleId':(flags&0x7fff)-(0x8000 if flags&0x4000 else 0),'pitch':struct.unpack_from('<i',b,8)[0],'priority':struct.unpack_from('<b',b,12)[0],'hashNext':struct.unpack_from('<h',b,16)[0],'volume':struct.unpack_from('<h',b,18)[0],'group':struct.unpack_from('<h',b,20)[0],'fcat':struct.unpack_from('<H',b,22)[0],'pan':struct.unpack_from('<f',b,24)[0],'pitchRandom':struct.unpack_from('<f',b,28)[0],'volumeRandom':struct.unpack_from('<f',b,32)[0],'near':struct.unpack_from('<f',b,36)[0],'far':struct.unpack_from('<f',b,40)[0],'rumble':[struct.unpack_from('<f',b,44)[0],struct.unpack_from('<i',b,48)[0],struct.unpack_from('<f',b,52)[0],struct.unpack_from('<f',b,56)[0]],'filename':text_at(struct.unpack_from('<I',b,60)[0],64),'rawHex':b.hex()}
events=sorted([{'kind':'sample',**x} for x in cfg['samples']]+[{'kind':'group',**x} for x in cfg['groups']],key=lambda x:x['line'])
sourceLines=[];groupEvents=[];maxLineBytes=0
for e in events:
    if e['kind']=='sample':
        assert n.unpack('<I',0x296201c)[0]<1600
        line=e['directive'].split(None,1)[1];maxLineBytes=max(maxLineBytes,len(line.encode('latin1')));assert len(line.encode('latin1'))<512;line_parser(line);before=n.unpack('<I',0x296201c)[0]
        n.call(0x6516a0,[PARSER],count=2000000);after=n.unpack('<I',0x296201c)[0];assert after==before+1,(e['line'],before,after)
        sourceLines.append(e['line'])
    else:
        line=' '.join('"'+x+'"' for x in [e['leader']]+e['members']);maxLineBytes=max(maxLineBytes,len(line.encode('latin1')));assert len(line.encode('latin1'))<512;line_parser(line);before=n.unpack('<I',0x2962024)[0];n.call(0x652010,[PARSER]);after=n.unpack('<I',0x2962024)[0]
        groupEvents.append({'line':e['line'],'leader':e['leader'],'groupBefore':before,'groupAfter':after})
defs=[decode_def(i,line) for i,line in enumerate(sourceLines)]
files=[]
for i in range(n.unpack('<I',0x2962014)[0]):
    b=n.read(FILES+i*28,28);files.append({'id':i,'name':text_at(struct.unpack_from('<I',b,0)[0],64),'words':list(struct.unpack('<7I',b)),'rawHex':b.hex()})
groups=[]
for i in range(n.unpack('<I',0x2962024)[0]):
    start,count,cursor,unknown=n.unpack('<4h',0x2920d88+i*8);ids=list(n.unpack('<'+str(count)+'h',0x2921260+start*2));groups.append({'id':i,'poolStart':start,'count':count,'cursor':cursor,'unknown':unknown,'memberIds':ids,'names':[defs[x]['name'] for x in ids]})
lookups=[]
for name in dict.fromkeys(x['name'] for x in defs):
    n.write(TOKEN,name.encode('latin1')+b'\0');value=n.call(0x650dc0,[TOKEN]);lookups.append({'name':name,'selectedId':value,'selectedSourceLine':defs[value]['line'] if value<len(defs) else None})
report={'source':cfg['source'],'sourceSha256':cfg['sha256'],'binarySha256':n.sha256,'method':'Original PC functions0x6516a0 and0x652010 parse preservedCFG lines in sourceorder, using original token/numeric/string/hash helpers. Synthetic parserstructures, memoryarenas, zero preloadedbackend samples; no file access or OS APIs. Actual parsed records are recovered, not interpreted from names.', 'preconditions':{'preloadedSamples':0,'lineBufferBytes':1024,'tokenBufferBytes':1024,'note':'Native file parser normally supplies512-bytebuffers; all actual parsed lines here are shorter than512. Fixture buffers enlarged only to ensure safety.'},'summary':{'definitions':len(defs),'uniqueFilenameSamples':len(files),'groups':len(groups),'memberSlots':n.unpack('<I',0x2962020)[0],'hashLookups':len(lookups),'disabled':sum(bool(x['flags']&0x40000) for x in defs),'commented':sum(bool(x['flags']&0x80000) for x in defs),'looped':sum(bool(x['flags']&0x8000) for x in defs),'sequential':sum(bool(x['flags']&0x10000) for x in defs)},'definitions':defs,'files':files,'groups':groups,'groupEvents':groupEvents,'lookups':lookups,'limitations':['This executes native CFG handlers only, not the Audio.cfg file loader, mixer, backend sample decompressor or playback.','Assumes zero preloaded backend sample entries; native file IDs can shift if runtime preloads exist. Logical definition IDs correspond to this tested config order.','Global process state is synthetic; no user/game process memory accessed.','Generated pointers are fixture addresses; raw records preserve them only as verification evidence.']}
report['preconditions']['maxSuppliedLineBytes']=maxLineBytes
(native.BASE/'reports/gameplay-native-audio-compiled.json').write_text(json.dumps(report,indent=2));print(json.dumps(report['summary'],indent=2))
