"""Inspect original moving-platform carry transform with a no-hit candidate list."""
import importlib.util,json,struct,math,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
n=native.NativeX86();D=n.DATA;W=D;TERR=D+0x10000;PLAT=D+0x20000;CUR=PLAT+0x100;CONTACT=PLAT+0x200;CAND=PLAT+0x300;MOVE=PLAT+0x400;SCRATCH=D+0x30000
def vec(p,v):n.pack('<3f',p,*v)
def mat(tx,ty,tz,angle=0):
    c,s=math.cos(angle),math.sin(angle);return[c,0,-s,0,0,1,0,0,s,0,c,0,tx,ty,tz,1]
rows=[]
for transformed in [0,1]:
    n.write(D,bytes(0x40000));n.pack('<I',0x292186c,W);n.pack('<I',0x292fc68,TERR);n.pack('<I',TERR+0x68,PLAT);n.pack('<I',0x2947c74,CONTACT);n.pack('<I',0x827730,SCRATCH);n.pack('<f',0x810b30,.1)
    n.pack('<16f',PLAT,*mat(1,2,3));n.pack('<16f',CUR,*mat(4,6,8,math.pi/2 if transformed else 0));n.pack('<I',PLAT+0x40,CUR);n.pack('<B',PLAT+0x4c,transformed)
    n.pack('<IHHH',CONTACT,MOVE,0,1,4);n.pack('<h',CAND,-1);n.pack('<I',W+0x8c,CAND)
    vec(W+0x1c,[2,3.25,4]);vec(MOVE,[0,0,0]);n.pack('<f',W+0x50,.25);n.pack('<f',W+0x54,.0625);n.pack('<f',W+0x58,4);n.pack('<f',W+0x5c,2);n.pack('<f',W+0x60,4);n.pack('<f',W+0x64,.5);n.pack('<f',W+0x68,.25)
    result=n.call(0x68ee40,[6,MOVE],count=200000)
    rows.append(dict(transformed=bool(transformed),returnedIterations=result,carryTarget=list(n.unpack('<3f',SCRATCH+0xc0)),temporaryStart=list(n.unpack('<3f',SCRATCH+0xcc)),originalQueryPosition=list(n.unpack('<3f',W+0x1c)),scratchRestored=n.unpack('<I',0x827730)[0]==SCRATCH))
examples=rows;checks=0;errors=[];rng=random.Random(0x68ee40)
def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def inverse3(m):
    a,b,c,d,e,f,g,h,i=m[0],m[4],m[8],m[1],m[5],m[9],m[2],m[6],m[10]
    det=a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g)
    return[(e*i-f*h)/det,(c*h-b*i)/det,(b*f-c*e)/det,(f*g-d*i)/det,(a*i-c*g)/det,(c*d-a*f)/det,(d*h-e*g)/det,(b*g-a*h)/det,(a*e-b*d)/det]
for case in range(400):
    transformed=case%2;prior=mat(*[rng.uniform(-10,10) for _ in range(3)],rng.uniform(-3,3));current=mat(*[rng.uniform(-10,10) for _ in range(3)],rng.uniform(-3,3))
    for m in [prior,current]:
        for axis in range(3):
            scale=rng.uniform(.5,2)
            for k in range(3):m[axis*4+k]=f32(m[axis*4+k]*scale)
        for k in range(16):m[k]=f32(m[k])
    pos=list(map(f32,[rng.uniform(-5,5) for _ in range(3)]));radius=f32(rng.uniform(.1,1));stretch=f32(rng.uniform(.5,3))
    n.write(D,bytes(0x40000));n.pack('<I',0x292186c,W);n.pack('<I',0x292fc68,TERR);n.pack('<I',TERR+0x68,PLAT);n.pack('<I',0x2947c74,CONTACT);n.pack('<I',0x827730,SCRATCH);n.pack('<f',0x810b30,.1)
    n.pack('<16f',PLAT,*prior);n.pack('<16f',CUR,*current);n.pack('<I',PLAT+0x40,CUR);n.pack('<B',PLAT+0x4c,transformed);n.pack('<IHHH',CONTACT,MOVE,0,1,4);n.pack('<h',CAND,-1);n.pack('<I',W+0x8c,CAND)
    vec(W+0x1c,pos);vec(MOVE,[0,0,0])
    for off,value in [(0x50,radius),(0x54,radius*radius),(0x58,1/radius),(0x5c,stretch),(0x60,stretch*stretch),(0x64,1/stretch),(0x68,1/(stretch*stretch))]:n.pack('<f',W+off,value)
    if transformed:
        relative=[pos[0]-prior[12],(pos[1]-radius)*stretch-prior[13],pos[2]-prior[14]];inv=inverse3(prior);local=[sum(inv[k*3+j]*relative[j] for j in range(3)) for k in range(3)];world=[sum(local[j]*current[j*4+k] for j in range(3))+current[12+k] for k in range(3)];want=[world[0],world[1]/stretch+radius,world[2]]
    else:want=[pos[0]+current[12]-prior[12],pos[1]+(current[13]-prior[13])/stretch,pos[2]+current[14]-prior[14]]
    result=n.call(0x68ee40,[6,MOVE],count=200000);got=list(n.unpack('<3f',SCRATCH+0xcc))
    assertions=[('carry-transform',all(math.isclose(a,b,rel_tol=2e-5,abs_tol=2e-5) for a,b in zip(got,want)),dict(got=got,want=want)),('no-hit-retains-iterations',result==6,result),('no-hit-does-not-commit',list(n.unpack('<3f',W+0x1c))==pos,None),('scratch-arena-restored',n.unpack('<I',0x827730)[0]==SCRATCH,None)]
    for kind,ok,detail in assertions:
        checks+=1
        if not ok:errors.append(dict(case=case,transformed=bool(transformed),kind=kind,detail=detail))
report=dict(binarySha256=n.sha256,method='Original 0x68ee40 including inverse-matrix0x5b5b90 and homogeneous transforms0x5c03e0. Synthetic platform, retained-contact record and negative candidate header yield an empty copied candidate list; this allows checking the carry proposal and no-hit refusal without replacement callbacks. No live contact is claimed.',cases=400,checks=checks,mismatches=len(errors),errors=errors[:30],examples=examples,contracts={'translationOnly':'proposalXYZ=queryXYZ+(currentTranslation-priorTranslation), with Y translation divided by vertical stretch.','transformed':'Convert internal query Y to foot/world Y: (queryY-radius)*stretch. Subtract prior translation, multiply inverse prior3x3, then current full matrix. Return proposed internalY=worldY/stretch+radius.','acceptance':'These no-hit fixtures preserve the original query position, retain iteration count and restore the scratch arena. Actual support-hit acceptance still needs collision fixtures.'},limits=['Only Y-axis platform rotations with nonuniform scale were sampled; arbitrary 3D rotations and singular matrices are untested.','Negative candidate header is a bounded fixture to bypass contact geometry; the recovered transform does not itself prove live moving-platform collision or carry acceptance.'])
(native.BASE/'reports/gameplay-terrain-platform-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['cases','checks','mismatches','errors']},indent=2));assert not errors
