"""Finite scalar model of original portal runtime; no native calls or file mutations."""
import importlib.util,struct,math,itertools
from pathlib import Path
s=importlib.util.spec_from_file_location('portal_x87',Path(__file__).with_name('animation-x87.py'));x87=importlib.util.module_from_spec(s);s.loader.exec_module(x87)
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
def wd(v,p):return x87.add(x87.add(x87.add(x87.mul(x87.wide(v[0]),x87.wide(p[0])),x87.mul(x87.wide(v[1]),x87.wide(p[1]))),x87.mul(x87.wide(v[2]),x87.wide(p[2]))),x87.wide(p[3]))
def dot(p,v):return x87.store(wd(v,p))
def quotient(a,b):return x87.store(x87.div(x87.wide(a),x87.wide(b)))
def pack(planes,eye):
 p=planes[:8]+[eye]*max(0,8-len(planes));return [p[(i//16)*4+i%4][i%16//4]for i in range(32)]
def project_bounds(vertices,matrix):
 points=[]
 for v in vertices:
  w=dot([matrix[3],matrix[7],matrix[11],matrix[15]],v);inv=quotient(1.,w)if w!=0 else 0.
  points.append([x87.store(x87.mul(wd(v,[matrix[k],matrix[4+k],matrix[8+k],matrix[12+k]]),x87.wide(inv)))for k in range(3)])
 return [[min(1.,max(-1.,fn(p[k]for p in points)))for k in range(3)]for fn in [min,max]]
def volume(planes,minimum,maximum,room,eye):return {'planes':planes,'min':list(minimum),'max':list(maximum),'room':room,'packed':pack(planes,eye)}
def edge_volume(vertices,plane,camera,matrix,eye,room):
 result=[];flip=dot(plane,camera)>=0
 for i,v in enumerate(vertices):
  a=[f32(camera[k]-v[k])for k in range(3)];b=[f32(camera[k]-vertices[(i+1)%len(vertices)][k])for k in range(3)]
  cross=[dot([b[2],-b[1],0.,0.],[a[1],a[2],0.]),dot([b[0],-b[2],0.,0.],[a[2],a[0],0.]),dot([b[1],-b[0],0.,0.],[a[0],a[1],0.])]
  length=f32(math.sqrt(dot(cross+[0.],cross)));reciprocal=quotient(1.,length)if length>0 else 0.;normal=[f32(x*reciprocal)for x in cross];constant=dot(normal+[0.],camera)
  result.append([-x for x in normal]+[constant]if flip else normal+[-constant])
 lo,hi=project_bounds(vertices,matrix);return volume(result,lo,hi,room,eye)
def angle_index(fov,scale):
 value=x87.mul(x87.wide(f32(fov*.5)),x87.wide(scale));m,e=value
 return (abs(m)<<e if e>=0 else abs(m)>>-e)*(-1 if m<0 else 1)
def rectangle_volume(minimum,maximum,room,cameraMatrix,fov,aspect,sine,angleScale,eye):
 index=angle_index(fov,angleScale);tangent=quotient(sine[(index>>1)&32767],sine[((index+0x4000)>>1)&32767]);horizontal=quotient(tangent,aspect)
 slopes=[f32(maximum[0]*horizontal),f32(minimum[0]*horizontal),f32(minimum[1]*tangent),f32(maximum[1]*tangent)]
 normalizers=[quotient(1.,f32(math.sqrt(dot([v,0.,0.,1.],[v,0.,0.]))))for v in slopes]
 a,b,c,d=normalizers;aa,bb,cc,dd=slopes
 local=[[-a,0.,f32(aa*a),0.],[b,0.,f32(-bb*b),0.],[0.,c,f32(-cc*c),0.],[0.,-d,f32(dd*d),0.]]
 planes=[];camera=cameraMatrix[12:15]
 for p in local:
  normal=[dot([cameraMatrix[k],cameraMatrix[k+4],cameraMatrix[k+8],0.],p[:3])for k in range(3)]
  planes.append(normal+[-dot(normal+[0.],camera)])
 return volume(planes,minimum,maximum,room,eye)
def classify(portal,current,priorities,camera,planes):
 front,back=portal['frontRoom'],portal['backRoom'];target=back if current==front else front
 if priorities[current]<priorities[target]:
  d=dot(portal['plane'],camera)
  if (back==current and d<0)or(front==current and d>0):return 0
 partial=False
 for plane in planes:
  outside=sum(dot(plane,v)<0 for v in portal['vertices'])
  if outside==len(portal['vertices']):return 0
  if outside:partial=True
 return 2 if partial else 1
def partial(portal,parent,room,cameraMatrix,fov,aspect,sine,angleScale,projection,eye):
 positive=sum(dot(eye,v)>0 for v in portal['vertices'])
 if not positive:return 0,None
 if positive!=len(portal['vertices']):return 4,None
 lo,hi=project_bounds(portal['vertices'],projection)
 if not all(parent['min'][i]<hi[i]and lo[i]<parent['max'][i]for i in range(2)):return 0,None
 for i in range(2):lo[i]=max(parent['min'][i],lo[i]);hi[i]=min(parent['max'][i],hi[i])
 return 1,rectangle_volume(lo,hi,room,cameraMatrix,fov,aspect,sine,angleScale,eye)
def center_box(center,extent,planes):return all(dot(p,center)>=-dot([abs(p[0]),abs(p[1]),abs(p[2]),0.],extent)for p in planes)
def traverse(data,root,initial,cameraMatrix,fov,aspect,sine,angleScale,projection,eye,depthLimit,flags,overrides,before,roomFlags=None,active=None,startDepth=0,previous=-1,path=None,maxVolumes=16):
 rooms=data['portalData']['rooms'];portals=data['portalData']['portals'];bounds=data['bounds'];priorities=[r['priority']for r in rooms];camera=cameraMatrix[12:15]
 state={'bits':bytearray(before),'roomFlags':list(roomFlags)if roomFlags is not None else[r['flags']for r in rooms],'path':list(path)if path is not None else[-1]*16,'volumes':[initial],'entries':[],'visits':[],'classifications':[],'partialResults':[]}
 def append(c):
  if len(state['volumes'])>=maxVolumes:raise ValueError('Native clip pointer list capacity would be exceeded')
  state['volumes'].append(c);return c
 def walk(current,previous,depth,clip):
  state['entries'].append([current,previous,depth])
  if current in state['path'][:max(0,depth-1)]:return
  if depth>=16:return
  state['path'][depth]=current;state['visits'].append([current,previous,depth]);room=rooms[current]
  for i in room['instanceIndices']:
   mask=1<<(i&7);offset=i>>3
   if current==root:state['bits'][offset]|=mask
   elif not state['bits'][offset]&mask:
    b=bounds[i]
    if overrides[offset]&mask or(flags[i]&1 and(flags[i]&8 or center_box(b['center'],b['extent'],clip['planes']))):state['bits'][offset]|=mask
  state['roomFlags'][current]|=4
  if depth>=depthLimit:return
  for pi in room['portalIndices']:
   p=portals[pi];target=p['frontRoom']if p['frontRoom']!=current else p['backRoom']
   if target==previous:continue
   if not((active[pi]if active is not None else p['activeFlags'])&1):continue
   result=classify(p,current,priorities,camera,clip['planes']);state['classifications'].append([pi,current,target,result])
   if result==1:walk(target,current,depth+1,append(edge_volume(p['vertices'],p['plane'],camera,projection,eye,target)))
   elif result==2:
    result,child=partial(p,clip,target,cameraMatrix,fov,aspect,sine,angleScale,projection,eye);state['partialResults'].append([pi,target,result])
    if result==1:walk(target,current,depth+1,append(child))
    elif result==4:
     child=dict(clip);child['packed']=list(clip['packed']);child['room']=target;walk(target,current,depth+1,append(child))
   elif result!=0:walk(target,current,depth+1,clip)
 walk(root,previous,startDepth,initial);return state
