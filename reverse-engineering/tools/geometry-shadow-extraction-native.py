"""Complete original5e8950 CPU camera-to-shadow-volume construction chain."""
import ast,json,struct,gzip,hashlib,random,collections
from pathlib import Path
B=Path(__file__).resolve().parent.parent;R=B/'reports'
def prefix(file,stop):
 p=B/file;tree=ast.parse(p.read_text());body=[]
 for node in tree.body:
  if isinstance(node,ast.Assign)and any(isinstance(t,ast.Name)and t.id==stop for t in node.targets):break
  body.append(node)
 ns={'__file__':str(p)};exec(compile(ast.Module(body=body,type_ignores=[]),str(p),'exec'),ns);return ns
v=prefix('tools/geometry-shadow-volume-native.py','cases');c=prefix('tools/geometry-shadow-camera-native.py','cases');n=v['n'];x=v['x'];W=x.wide;mul=x.mul;div=x.div;store=v['store'];f32=v['f32'];D=n.DATA;SIZE=8192;CAM=D+0x100;CUTS=D+0x180;CTX=D+0x400;PROJECTION=D+0x1500;VIEW=D+0x1540;NATIVE_PROJECTION=0x978440;NATIVE_VIEW=0x97ac80
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX
degreeScale=n.unpack('<d',0x75bf80)[0];pi=n.unpack('<d',0x763610)[0];calls=[]
for address in [0x5e8950,0x5b7670,0x5b5a40,0x5c8030,0x5c82c0,0x5c8540]:n.mu.hook_add(UC_HOOK_CODE,lambda mu,a,z,u:calls.append(a),begin=address,end=address)
def model(before,count):
 out=bytearray(before);read=lambda p,k:list(struct.unpack_from('<'+'f'*k,before,p-D));write=lambda p,values:struct.pack_into('<'+'f'*len(values),out,p-D,*values);camera=read(CAM,20);cuts=read(CUTS,count);direction=read(CTX+0x770,3)
 degrees=store(div(mul(W(camera[16]),W(degreeScale)),W(pi)),camera[16]*degreeScale/pi);aspect=store(div(W(1),W(camera[17])),1/camera[17]);projection,_=c['perspective'](degrees,aspect,camera[18],camera[19]);write(PROJECTION,projection);write(VIEW,c['inverse'](camera[:16]));write(CTX+0x740,camera[12:15]+[1.]);write(CTX+0x750,camera[8:11]+[0.]);struct.pack_into('<i',out,CTX+0x710-D,count-1);write(CTX+0x700,cuts);unknown=[];planeCounts=[]
 for i in range(count-1):
  volume=CTX+i*0x380;points,farPlane,_=v['frustum'](camera[:16],camera[16],camera[17],cuts[i],cuts[i+1]);corners=[p+[1.]for p in points]
  for k,p in enumerate(points):write(volume+0x120+k*16,p+([1.]if k<4 else[]))
  unknown.extend(volume-D+0x120+k*16+12 for k in range(4,8));write(volume+0x270,farPlane);planes,_=v['planes'](direction,corners);planeCounts.append(len(planes))
  for k,p in enumerate(planes):write(volume+0x1a0+k*16,p)
  struct.pack_into('<I',out,volume+0x260-D,len(planes));out[volume-D:volume-D+128]=before[CTX+0x780-D:CTX+0x800-D];center,position,radius,_=v['aggregate'](direction,corners);write(volume+0x280,center);write(volume+0x290,position);unknown.append(volume-D+0x29c);write(volume+0x2a0,[radius]);write(CTX+0x720+i*16,[0.,0.,store(div(W(1),W(cuts[i+1])),1/cuts[i+1]),-1.])
 return out,unknown,planeCounts
cases=[];counts=collections.Counter();hist=collections.Counter()
def execute(index,camera,cuts,direction,poison=0,sse=False,origin=None):
 before=bytearray((i*37+index*13)&255 for i in range(SIZE));write=lambda p,values:struct.pack_into('<'+'f'*len(values),before,p-D,*values);write(CAM,camera);write(CUTS,cuts);write(CTX+0x770,direction);write(CTX+0x780,[float(i)for i in range(32)]);expected,unknown,planeCounts=model(before,len(cuts));n.write(D,before);n.write(n.STACK,struct.pack('<I',poison)*16384);n.write(NATIVE_PROJECTION,before[PROJECTION-D:PROJECTION-D+64]);n.write(NATIVE_VIEW,before[VIEW-D:VIEW-D+64]);n.pack('<I',0x29a9c48,int(sse));calls.clear();n.call(0x5e8950,[CAM,CUTS,len(cuts)],{UC_X86_REG_ECX:CTX},count=1000000);raw=bytearray(n.read(D,SIZE));raw[PROJECTION-D:PROJECTION-D+64]=n.read(NATIVE_PROJECTION,64);raw[VIEW-D:VIEW-D+64]=n.read(NATIVE_VIEW,64);actual=bytearray(raw)
 for p in unknown:actual[p:p+4]=before[p:p+4]
 if actual!=expected:raise AssertionError(dict(index=index,offsets=[i for i,(a,b)in enumerate(zip(actual,expected))if a!=b][:30],actual=raw.hex(),expected=expected.hex()))
 counts['cases']+=1;counts['volumes']+=max(0,len(cuts)-1);counts['persistentBytes']+=SIZE;hist[len(cuts)]+=1;cases.append(dict(index=index,before=bytes(before).hex(),cutCount=len(cuts),sse=sse,stackPoison=poison,undefinedWordOffsets=unknown,nativeUndefinedWords=[struct.unpack_from('<I',raw,p)[0]for p in unknown],nativeSHA256=hashlib.sha256(actual).hexdigest(),nativeContextBytes=raw[CTX-D:CTX-D+0x830].hex(),nativeProjection=raw[PROJECTION-D:PROJECTION-D+64].hex(),nativeView=raw[VIEW-D:VIEW-D+64].hex(),planeCounts=planeCounts,nativeCalls=calls.copy(),source=origin))
cp='exports/cutscenes/LEVELS/EPISODE_V/ENDING/EPISODE5ENDING_A/EPISODE5ENDING_A.CU2.json';camera=json.loads((B/cp).read_text());identity=[1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.];matrices=[identity]+[r['matrix']for r in camera['cameras']['cameras']];rng=random.Random(0x5e8950)
for i in range(1024):
 params=[f32([.1,1.,2.,2.9,-1.][i%5]),f32([1.,.75,1.3333333,-1.][i%4]),f32(.1),f32(1000.)];cuts=[[1.,100.,1000.],[.1,1.,100.],[-1.,-10.,-100.],[10.,1.,.1]][i//4%4][:i%4];direction=[f32(rng.uniform(-1,1))for _ in range(3)]if i%3 else[[1.,0.,0.],[0.,1.,0.],[0.,0.,1.],[0.,0.,0.]][i//3%4];execute(i,matrices[i%7]+params,cuts,direction,[0,0x12345678,0xdeadbeef][i%3],bool(i&1),dict(cameraFile=cp,cameraIndex=i%7-1))
fp=R/'geometry-shadow-extraction-fixtures.json.gz';fp.write_bytes(gzip.compress(json.dumps(dict(base=D,size=SIZE,camera=CAM,cuts=CUTS,context=CTX,projection=PROJECTION,view=VIEW,cases=cases,sineTable=dict(file='references/native-animation-sine-table.f32',sha256=hashlib.sha256(v['ns']['TABLE']).hexdigest())),separators=(',',':')).encode(),mtime=0));report=dict(schema='geometry-shadow-extraction-native-v1',passed=True,binarySHA256=n.sha256,counts=dict(counts),errors=[],cutCountHistogram=dict(hist),fixtureFile=fp.name,fixtureBytes=fp.stat().st_size,fixtureSHA256=hashlib.sha256(fp.read_bytes()).hexdigest(),constants=dict(degreeScale=degreeScale,pi=pi),limits=['Complete original5e8950 chain and all real camera/frustum/plane/bounds helpers execute unchanged. No computational replacements.','Cutcount0..3 matches fixed two-volume context. Count0 storesactiveCount=-1, count1 zero. Inputs, context and output matrices disjoint; finite math and previously bounded camera domains.','Every volume writes four undefined far-cornerW words and one undefined positionW. Only these proven padding words are normalized for comparison; raw native words retained.','Camera near/far are restored exactly after per-split temporary changes. Persistent context and original global view/projection outputs compare exactly on known lanes.','Six authored CU2 transforms plus identity, controlled light directions/projection/cuts/context data. Prior light configuration and live registration, GPU output, managed runtime equality remain separate.']);(R/'geometry-shadow-extraction-native-validation.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report,indent=2))
