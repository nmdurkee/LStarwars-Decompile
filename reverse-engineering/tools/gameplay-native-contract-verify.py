"""Execute isolated original PC checksum/audio routines against synthetic memory only."""
import importlib.util, json, random, struct
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
n=native.NativeX86(); rng=random.Random(0x50b970); errors=[]; counts={}
def check(kind,actual,expected,detail=None):
    counts[kind]=counts.get(kind,0)+1
    if actual!=expected:errors.append({'kind':kind,'actual':actual,'expected':expected,'detail':detail})
def checksum(b):return (0x5c0999+sum(struct.unpack_from('<I',b,i)[0] for i in range(0,len(b)-3,4)))&0xffffffff
for size in [0,1,2,3,4,5,7,8,16,32332]+[rng.randrange(0,4096) for _ in range(120)]:
    b=rng.randbytes(size);n.write(n.DATA,b);actual=n.call(0x50b970,[n.DATA,size]);check('save-checksum',actual,checksum(b),{'bytes':size})
for completion in [0,1,99,100,32767,32768,65535]:
    n.pack('<H',0x86e4e0,completion);check('save-trailer-completion',n.call(0x428b80),completion)
# Construct original CRC table using its native routine and a synthetic arena pointer.
n.pack('<I',0x2962044,0);n.pack('<I',n.DATA,n.DATA+0x1000);n.call(0x650280,[n.DATA]);table=n.unpack('<256I',n.DATA+0x1000)
def crc_table_word(i):
    c=i<<24
    for _ in range(8):c=((c<<1)^(0x04c11db7 if c&0x80000000 else 0))&0xffffffff
    return c
for i,c in enumerate(table):check('audio-crc-table',c,crc_table_word(i),i)
def name_hash(s):
    result=0
    for c in s:
        if 97<=c<=122:c-=32
        result=((result<<8)^table[c^(result>>24)])&0xffffffff
    return result
cfg=json.loads((native.BASE/'reports/gameplay-media/sound-config.json').read_text())
names=[x['name'] for x in cfg['samples'] if x.get('name')]+['','a','A','AbCd_123','abcd_123']
hash_examples=[]
for name in names:
    b=name.encode('ascii');n.write(n.DATA+0x2000,b+b'\0');actual=n.call(0x650430,[n.DATA+0x2000]);check('audio-name-hash',actual,name_hash(b),name)
    if len(hash_examples)<5:hash_examples.append({'name':name,'hash':hex(actual),'bucket':actual&255})
# Original group picker: group record = first member, count, cursor, unknown (four shorts).
members=[12,37,141,400,1599];group=0x2920d88;pool=0x2921260
n.pack('<5h',pool,*members);n.pack('<hhhh',group,0,len(members),0,0)
for i in range(23):
    check('audio-group-sequential',n.call(0x650d10,[0,1]),members[i%len(members)],i)
    check('audio-group-sequential-cursor',n.unpack('<h',group+4)[0],(i+1)%len(members),i)
seed=0x12345678;n.pack('<I',0x810364,seed)
random_examples=[]
for i in range(100):
    seed=(seed*0x19660d+0x3c6ef35f)&0xffffffff;expected=members[(seed>>16)%len(members)];actual=n.call(0x650d10,[0,0]);check('audio-group-random',actual,expected,i);check('audio-group-rng-state',n.unpack('<I',0x810364)[0],seed,i)
    if i<8:random_examples.append(actual)
report={'generatedBy':Path(__file__).name,'binarySha256':n.sha256,'method':'Unicorn x86-32 executes original checksum, completion callback, CRC table generator, name hash and group picker. Synthetic memory; no OS APIs, game launch, save search, or user saves. No native function replacements.','functions':['0x50b970','0x428b80','0x650280','0x650430','0x650d10','0x5b9e10'],'tests':sum(counts.values()),'categories':counts,'mismatches':len(errors),'errors':errors[:50],'audioHashExamples':hash_examples,'groupRandomExamples':random_examples,'limits':['Does not emulate filesystem framing or native save-state machine.','Audio mixer, 3D attenuation, floating-point random pitch/volume and live playback are outside these isolated checks.','ASCII audio config names only; non-ASCII hashing is not generalized.']}
(native.BASE/'reports/gameplay-native-contract-tests.json').write_text(json.dumps(report,indent=2))
print(json.dumps(report,indent=2));assert not errors,'Native contract mismatch'
