"""Corroborate built-in PC Xbox profiles using original x86 mapping routines."""
import sys, importlib.util, json, struct, random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
from unicorn.x86_const import UC_X86_REG_ECX
n=native.NativeX86(); BASE=native.BASE
MANAGER=n.DATA; RAW=n.DATA+0x10000; OUT=RAW+0x1000; KEY=RAW+0x2000; KEY_PTR=KEY+0x1000; MOUSE=KEY+0x2000
n.pack('<I',KEY_PTR,KEY)
profiles=[0x82505c,0x8250f8]
buttons=[('A',0,0x40),('B',1,0x20),('X',2,0x80),('Y',3,0x10),('LB',4,4),('RB',5,8),('Back',6,0x100),('Start',7,0x800),('LeftStickClick',8,0x200),('RightStickClick',9,0x400),('DpadUp',128,0x1000),('DpadRight',129,0x2000),('DpadDown',130,0x4000),('DpadLeft',131,0x8000)]
def init(profile,smoothing=0.0):
    n.write(MANAGER,bytes(0x68b4))
    n.pack('<if',MANAGER+0x6568,8191,0.0)
    n.pack('<f',MANAGER+0x6570,smoothing)
    n.call(0x6d96b0,regs={UC_X86_REG_ECX:MANAGER})
    n.call(0x6d45f0,[profile,0,0,0,0],{UC_X86_REG_ECX:MANAGER})
    return n.read(MANAGER,0x68b4)
def map_inputs(buttonset=(),axes=(0,0,0,0),triggers=(0,0)):
    data=bytearray(0xc4)
    for i in buttonset:data[0x40+i]=1
    for slot,val in zip([0,1,3,4,6,7],list(axes)+[triggers[0]<<7,triggers[1]<<7]):struct.pack_into('<h',data,2*slot,val)
    n.write(RAW,data);n.write(OUT,bytes(12))
    n.call(0x6d7d80,[0,OUT,1,RAW,MOUSE,KEY_PTR],{UC_X86_REG_ECX:MANAGER})
    out=n.read(OUT,12)
    return {'analog':list(out[:8]),'buttons':struct.unpack_from('<I',out,8)[0]}
def expected(buttonset,axes,triggers):
    held=sum(mask for _,bit,mask in buttons if bit in buttonset)
    if triggers[0]>=64:held|=1
    if triggers[1]>=64:held|=2
    return {'analog':[((v+32768)>>8)&255 for v in axes]+[255 if 4 in buttonset else 0,triggers[0],255 if 5 in buttonset else 0,triggers[1]],'buttons':held}
rng=random.Random(0x6d7d80)
cases=[(set(),(0,0,0,0),(0,0))]+[({bit},(0,0,0,0),(0,0)) for _,bit,_ in buttons]
for t in range(256):
    cases.append((set(),(0,0,0,0),(t,0)))
    cases.append((set(),(0,0,0,0),(0,t)))
for _ in range(1024):cases.append(({bit for _,bit,_ in buttons if rng.randrange(2)},tuple(rng.randint(-32768,32767) for _ in range(4)),(rng.randrange(256),rng.randrange(256))))
results=[];errors=[];vectors=[]
for profile in profiles:
    snapshot=init(profile)
    count=n.unpack('<I',MANAGER+0x67e4)[0]
    samples=[]
    for i,(buttonset,axes,triggers) in enumerate(cases):
        n.write(MANAGER,snapshot);actual=map_inputs(buttonset,axes,triggers);want=expected(buttonset,axes,triggers)
        physical=sum(1<<j for j,(_,bit,_)in enumerate(buttons)if bit in buttonset)
        vectors.append({'contract':'defaultXbox','input':{'physical':physical,'axes':axes,'triggers':triggers},'native':actual['analog']+list(struct.pack('<I',actual['buttons']))})
        if actual!=want:errors.append({'profile':hex(profile),'case':i,'actual':actual,'expected':want})
        if i<15:samples.append({'physical':(['Neutral']+[b[0] for b in buttons])[i],**actual})
    results.append({'profile':hex(profile),'name':n.read(profile,64).split(b'\0')[0].decode(),'deadzone':n.read(MANAGER+0x4e50,1)[0],'logicalDescriptors':count,'casesChecked':len(cases),'samples':samples})
# Default 0.1-second digital-to-analog ramp, observed game frame time 1/60 supplied as fixture.
init(profiles[0],0.1);n.pack('<f',0x297dbfc,1/60)
ramp=[map_inputs({4}) for _ in range(8)]+[map_inputs() for _ in range(8)]
report={'binarySha256':n.sha256,'emulator':'Unicorn 2.1.4 x86-32','functions':['0x6d96b0','0x6d4e60','0x6d45f0','0x6d7d80'],'method':'Execute original PC logical-map initialization, profile application, and raw-state conversion in isolated memory. Original callees; no replacements or OS APIs. Fresh manager memory per case.','profiles':results,'totalCases':len(cases)*len(profiles),'mismatches':len(errors),'mismatchExamples':errors[:30],'digitalRampFixture':{'seconds':0.1,'frameTime':1/60,'heldFrames':8,'releasedFrames':8,'samples':ramp},'limits':['Input starts at the raw controller staging buffer; XInput API itself is not emulated.','Exhaustive trigger-byte sweep and individual physical buttons, plus seeded random combinations; not every 16-bit stick combination.','Users may override mappings through Mappings.dat or in-game settings.']}
(BASE/'reports/native-input-emulation.json').write_text(json.dumps(report,indent=2))
print(json.dumps({'profiles':results,'totalCases':report['totalCases'],'mismatches':len(errors),'mismatchExamples':errors[:3],'ramp':ramp},indent=2))
(BASE/'reports/native-input-vectors.json').write_text(json.dumps({'binarySha256':n.sha256,'vectors':vectors},separators=(',',':'))+'\n')
if errors:sys.exit(1)
