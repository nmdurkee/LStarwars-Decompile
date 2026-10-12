"""Bounded original-PC terrain math: real TER triangles, transforms, slide and integration."""
import importlib.util,json,gzip,struct,math,random
from pathlib import Path
spec=importlib.util.spec_from_file_location('native_x86',Path(__file__).with_name('native-x86.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
n=native.NativeX86();root=native.BASE;D=n.DATA;W=D+0x1000;FACE=D+0x2000;TERR=D+0x3000;OBJ=D+0x4000;V=D+0x5000;OUT=V+0x20;M=V+0x80
counts={};errors=[];examples=[];rng=random.Random(675240)
def f32(x):return struct.unpack('<f',struct.pack('<f',x))[0]
def bits(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def check(kind,got,want,detail=None,tol=0):
    counts[kind]=counts.get(kind,0)+1
    same=got==want
    if tol:
        a=got if isinstance(got,(list,tuple)) else [got];b=want if isinstance(want,(list,tuple)) else [want]
        same=len(a)==len(b) and all(math.isclose(x,y,rel_tol=tol,abs_tol=tol) for x,y in zip(a,b))
    if not same:errors.append(dict(kind=kind,got=got,want=want,detail=detail))
def vec(p,x):n.pack('<3f',p,*x)
n.pack('<I',0x292186c,W);n.pack('<I',0x292fc68,TERR);n.pack('<I',TERR,OBJ)
# Every carrier contributes up to eight actual first triangles; no hand-written substitute geometry.
index=json.loads((root/'reports/gameplay-binary/index.json').read_text());carriers=0
for entry in index['entries']:
    if entry['type']!='TER' or entry.get('error'):continue
    decoded=json.loads(gzip.decompress(Path(entry['output']).read_bytes()));chosen=[]
    for obj in decoded['objects']:
        for block in obj.get('blocks',[]):
            for face in block['faces']:
                p,q,r=face[7:10],face[10:13],face[13:16];normal=face[19:22]
                area=math.sqrt(sum(( (q[(i+1)%3]-p[(i+1)%3])*(r[(i+2)%3]-p[(i+2)%3])-(q[(i+2)%3]-p[(i+2)%3])*(r[(i+1)%3]-p[(i+1)%3]) )**2 for i in range(3)))
                if area>0.01 and all(math.isfinite(x) for x in p+q+r+normal) and 0.9<sum(x*x for x in normal)<1.1:chosen.append((obj['index'],face))
                if len(chosen)>=8:break
            if len(chosen)>=8:break
        if len(chosen)>=8:break
    if chosen:carriers+=1
    for obj,face in chosen:
        n.write(W,bytes(0x948));n.write(FACE,bytes(0x64));p,q,r=face[7:10],face[10:13],face[13:16];normal=face[19:22]
        center=[sum(a)/3 for a in zip(p,q,r)];position=[f32(a+b) for a,b in zip(center,normal)];movement=[f32(-2*x) for x in normal]
        vec(W+0x70,position);vec(W+0x28,movement);n.pack('<f',W+0x98,1000.);vec(FACE+0x18,p);vec(FACE+0x24,q);vec(FACE+0x30,r);vec(FACE+0x48,normal);vec(FACE+0x54,[0,65536,0])
        got=n.call(0x674490,[bits(1.),bits(-1.),0,0,FACE]);detail=dict(source=entry['source'],object=obj,faceOffset=face[0])
        check('real-ter-triangle-ray-hit',got,1,detail);check('real-ter-triangle-ray-fraction',n.unpack('<f',W+0x98)[0],0.5,detail,1e-6);check('real-ter-triangle-normal',list(n.unpack('<3f',W+0xa8)),normal,detail,1e-7)
# Actual PC affine helpers: includes in-place use, rotated/nonuniform scale and translation.
for i in range(200):
    theta=rng.uniform(-math.pi,math.pi);c,s=math.cos(theta),math.sin(theta);sc=[rng.uniform(.1,3) for _ in range(3)];t=[rng.uniform(-50,50) for _ in range(3)]
    matrix=list(map(f32,[c*sc[0],0,-s*sc[0],0,0,sc[1],0,0,s*sc[2],0,c*sc[2],0,*t,1]));v=list(map(f32,[rng.uniform(-5,5) for _ in range(3)]));n.pack('<16f',M,*matrix)
    expected=[sum(v[j]*matrix[j*4+k] for j in range(3))+matrix[12+k] for k in range(3)]
    for inplace in [False,True]:
        vec(V,v);target=V if inplace else OUT;n.call(0x5b30a0,[target,V,M]);check('affine-point',list(n.unpack('<3f',target)),expected,dict(case=i,inplace=inplace),2e-5)
        n.pack('<4f',V,*v,0);n.call(0x5c03e0,[target,V,M]);want=[sum(v[j]*matrix[j*4+k] for j in range(3)) for k in range(4)];check('homogeneous-direction-no-translation',list(n.unpack('<4f',target)),want,dict(case=i,inplace=inplace),2e-5)
    # Terrain slide is v + n*(-dot(v,n)+0.0003), not an exact zero-normal projection.
    normal=[rng.uniform(-1,1) for _ in range(3)];mag=math.sqrt(sum(x*x for x in normal));normal=list(map(f32,[x/mag for x in normal]));vec(V,normal);vec(V+16,v)
    bias=f32(0.0003);projection=f32(-sum(a*b for a,b in zip(normal,v))+bias);want=[f32(v[j]+projection*normal[j]) for j in range(3)]
    n.call(0x677fb0,[V,V+16,V+16]);check('surface-deflection',list(n.unpack('<3f',V+16)),want,i,2e-6)
    scale=f32(rng.uniform(0,2));n.pack('<f',0x2947c00,scale);vec(V+16,v);n.call(0x678010,[V,V+16,OUT]);want[1]=f32(v[1]+projection*normal[1]*scale);check('surface-deflection-scaled-y',list(n.unpack('<3f',OUT)),want,i,2e-6)
    # Unobstructed response reverses internal vertical ellipsoid scaling and radius offset.
    n.write(W,bytes(0x948));pos=list(map(f32,[rng.uniform(-50,50) for _ in range(3)]));move=list(map(f32,[rng.uniform(-2,2) for _ in range(3)]));stretch=f32(rng.uniform(.5,3));radius=f32(rng.uniform(.1,1));vec(W+0x1c,pos);vec(W+0x28,move);n.pack('<f',W+0x50,radius);n.pack('<f',W+0x5c,stretch);n.pack('<B',V+64,255);n.pack('<I',0x2962b38,0)
    n.call(0x6786f0,[OUT,V+16,V+64]);want=[pos[0]+move[0],(pos[1]+move[1])*stretch-radius*stretch,pos[2]+move[2]];check('unobstructed-position-commit',list(n.unpack('<3f',OUT)),want,i,2e-5);check('unobstructed-ground-flag',n.unpack('<B',V+64)[0],0,i)
report=dict(binarySha256=n.sha256,method='Original PC x86 functions with actual decoded TER triangles and synthetic in-memory query state. No game, OS API, callback replacement, or original modification.',checks=sum(counts.values()),categories=counts,mismatches=len(errors),errors=errors[:40],terrainCarriersSampled=carriers,functions=['0x674490','0x5b30a0','0x5c03e0','0x677fb0','0x678010','0x6786f0'],contracts={'triangle':'Interior front-to-back zero-radius ray hits first triangles; no edge/capsule or second-triangle assertion. Triangles are sampled from every terrain carrier containing usable faces.','transform':'worldPoint[k]=x*M[k]+y*M[4+k]+z*M[8+k]+M[12+k]. Homogeneous w=0 excludes translation, including in-place output.','slide':'out=v+n*(-dot(v,n)+0.0003). Variant0x678010 scales only the added Y term by global0x2947c00.','unobstructed':'Position becomes (queryPosition+queryMovement), with Y multiplied by vertical stretch then radius*stretch removed. Ground-contact flag clears.'},limits=['These are bounded triangle, transform, deflection and no-hit response checks. Full swept ellipsoid broadphase/edge handling/moving-platform contacts remain incompletely tested.','Runtime query fixtures are constructed from decoded TER fields; original file-loader execution is not implied.','Native coordinates are preserved; no physical meter scale established.'])
(root/'reports/gameplay-terrain-native-tests.json').write_text(json.dumps(report,indent=2));print(json.dumps({k:report[k] for k in ['checks','categories','mismatches','errors','terrainCarriersSampled']},indent=2));assert not errors
