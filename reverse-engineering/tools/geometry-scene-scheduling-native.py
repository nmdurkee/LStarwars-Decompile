"""Normal CPU scheduler with unchanged portal/static predicates and recorded dynamic boundary."""
import ast,importlib.util,json,gzip,struct,hashlib,math
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;R=B/'reports'
# Reuse the already checked isolated scene allocator/helper definitions only.
# The source's top-level authored batch starts at assignment 'selection'; it is
# deliberately not imported/executed. Record this exact dependency in evidence.
helper=P/'geometry-portal-entry-native.py';syntax=ast.parse(helper.read_text());stop=next(i for i,x in enumerate(syntax.body)if isinstance(x,ast.Assign)and any(isinstance(t,ast.Name)and t.id=='selection'for t in x.targets));ns={'__file__':str(helper)};exec(compile(ast.Module(body=syntax.body[:stop],type_ignores=[]),str(helper),'exec'),ns)
n=ns['n'];model=ns['model'];f32=ns['f32'];scene=ns['scene'];display=ns['display'];rooms=ns['rooms'];portals=ns['portals'];arena=ns['arena'];flagsMemory=ns['flagsMemory'];overrideMemory=ns['overrideMemory'];pointMemory=ns['pointMemory'];staleHeader=ns['staleHeader'];sine=ns['sine'];scale=ns['scale']
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_ESI
EXTRA=0x11000000;EXTRA_SIZE=0x1000000;n.mu.mem_map(EXTRA,EXTRA_SIZE);cursor=EXTRA;events=[];schedulerCalls={};preparing=False;matrixCalls=0;dynamicBase=0;phaseCalls=[];errors=[];fixtures=[];sources=[];counts={'normalCases':0,'earlyReturnCases':0,'staticFrustumCalls':0,'selectedStaticClips':0,'dynamicHandoffs':0,'finiteAlphaComparisons':0};digest=hashlib.sha256()
def allocate(size):
 global cursor
 out=(cursor+15)&~15;cursor=out+size
 if cursor>EXTRA+EXTRA_SIZE:raise ValueError('Scheduling fixture arena exhausted')
 n.write(out,bytes(size));return out
def hook(mu,address,size,_):
 global matrixCalls
 if address in [0x5f5830,0x5fd0d0,0x5f3c80,0x5f5380,0x603960,0x5f0f00,0x5c12f0]:phaseCalls.append(hex(address))
 if address==0x5c1240 and preparing:
  sp=mu.reg_read(UC_X86_REG_ESP);ret,out,a,b=n.unpack('<4I',sp);aa=n.unpack('<16f',a);bb=n.unpack('<16f',b);product=[f32(sum(float(aa[i*4+k])*bb[k*4+j]for k in range(4)))for i in range(4)for j in range(4)];n.pack('<16f',out,*product);mu.reg_write(UC_X86_REG_EAX,out);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret);matrixCalls+=1
 elif address==0x5f0f00:
  sp=mu.reg_read(UC_X86_REG_ESP);ret,handle,matrix,a,b,c=n.unpack('<6I',sp);owner,unused,special=n.unpack('<3I',handle);events.append({'special':(special-dynamicBase)//208,'ownerMatches':owner==scene,'matrixHex':n.read(matrix,64).hex(),'usesOverride':matrix!=special+64,'tailArguments':[a,b,c]});mu.reg_write(UC_X86_REG_EAX,0);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 else:
  schedulerCalls[hex(address)]=schedulerCalls.get(hex(address),0)+1
  if address==0x5d69a0:counts['staticFrustumCalls']+=1
for address in [0x5c1240,0x5f0f00,0x5f5830,0x5fd0d0,0x5f3c80,0x5d6900,0x5f5380,0x603960,0x5c12f0,0x5d69a0]:n.mu.hook_add(UC_HOOK_CODE,hook,begin=address,end=address)
def compare(a,e,where):
 digest.update(str((a,e)).encode())
 if a!=e and len(errors)<30:errors.append({'context':where,'native':a,'expected':e})
def project(m,p,c,t=True):return model.x87.dot3_plus_constant(*p,m[c],m[c+4],m[c+8],m[c+12]if t else 0.)
def frustum(block,far,center,extent,override):
 v=struct.unpack('<84f',block);outer=v[:16];inner=v[16:32];nf=list(v[32:48]);aa=v[52:68];ab=v[68:84]
 if override!=0:nf[12]=f32(override+f32(nf[12]-far))
 d=[project(outer,center,j)for j in range(4)]+[project(nf,center,j)for j in range(2)];r=[project(aa,extent,j,j<3)for j in range(4)]+[project(nf,extent,j,False)for j in [2,3]]
 if any(x < -y for x,y in zip(d,r)):return 0
 if any(d[j]<r[j]for j in range(4))and any(project(inner,center,j)<project(ab,extent,j)for j in range(4)):return 2
 return 1
def distance(camera,center):
 d=[f32(camera[i]-center[i])for i in range(3)];p=[model.x87.mul(model.x87.wide(v),model.x87.wide(v))for v in d];return model.x87.store(model.x87.add(model.x87.add(p[2],p[1]),p[0]))
def fade(d,start,end):
 if end<=start:
  if d<=end*end:return 0.
  a=f32(math.sqrt(d))-end;b=start-end
  if not b:return float('nan')if a==0 else 1.
  v=f32(a/b);return 1. if v>1 else v
 if d<=start*start:return 1.
 return max(0.,f32((end-f32(math.sqrt(d)))/(end-start)))
def bit(mask,i):return bool(mask[i>>3]&(1<<(i&7)))
with gzip.open(R/'geometry-portal-entry-fixtures.json.gz','rt',encoding='utf8')as f:entryCases=json.load(f)['cases']
index={r['source']:r for r in json.loads((R/'geometry-scene-data-index.json').read_text())['rows']};chosen={}
for c in entryCases:
 if c['native']['returned']and c['override']:chosen.setdefault(c['source'],{}).setdefault(c['mode'],c)
for source,modeCases in chosen.items():
 row=index[source];data=json.loads((B/row['report']).read_text());raw=(B/'extracted'/source).read_bytes();render=json.loads((B/'exports/geometry/scene-runtime'/(source+'.json')).read_text())['renderState'];sourceFlags,sourceOverrides=ns['load_scene'](data,render);cursor=EXTRA;clipCount=render['clipObjectCount'];materialCount=len(data['materials']);itemCount=len(data['commands']);specials=data['specialObjects'];pd=data['portalData'];clipBytes=((clipCount+15)//16)*4;materialBytes=(materialCount+7)//8;materialBits=[allocate(materialBytes),allocate(materialBytes)];clipBits=[allocate(clipBytes),allocate(clipBytes)];lod=allocate(clipCount*4);far=allocate(clipCount*4);clipDefs=allocate(clipCount*12);clipCounts=allocate(clipCount*2);shader=allocate(420);alphaCursor=allocate(4);alpha=allocate(clipCount*4+16);fades=allocate(len(data['bounds'])*8);dynamicBase=allocate(len(specials)*208);remote=[];specialFlags=[]
 n.pack('<I',display+0x10,clipCount);n.pack('<I',display+0x14,clipDefs);n.pack('<I',display+0x18,clipCounts);n.pack('<I',display+0x28,lod);n.pack('<I',display+0x2c,far);n.pack('<2I',display+0x30,*clipBits);n.pack('<I',display+0x44,ns['boxes']);n.pack('<2I',display+0x58,*materialBits);n.pack('<I',display+0x78,scene);n.pack('<I',display+0x80,shader);n.pack('<2I',display+0x6c,len(specials),dynamicBase);n.pack('<I',display+0xc,fades)
 n.pack('<'+'f'*clipCount,lod,*render['lodRangesSquared']);n.pack('<'+'f'*clipCount,far,*render['farClipRanges']);n.pack('<'+'f'*(len(data['bounds'])*2),fades,*[v for x in render['instances']for v in x['fade']]);n.pack('<'+'H'*clipCount,clipCounts,*render['clipItemCounts'])
 for i,m in enumerate(data['models']):
  mats=allocate(len(m['parts'])*4);items=allocate(len(m['parts'])*4)
  for k,p in enumerate(m['parts']):n.pack('<I',mats+k*4,p['material']);n.pack('<I',items+k*4,p['command'])
  n.pack('<3I',clipDefs+i*12,len(m['parts']),mats,items)
 for i,s in enumerate(specials):
  addr=dynamicBase+i*208;n.write(addr,raw[s['address']:s['address']+208]);displacement=struct.unpack_from('<i',raw,s['address']+196)[0];ref=allocate(64)if displacement not in[0,-1]else 0
  if ref:n.write(ref,raw[s['address']+196+displacement:s['address']+260+displacement])
  n.pack('<i',addr+196,ref if ref else displacement);remote.append(ref);specialFlags.append(n.unpack('<I',addr+184)[0])
 defaultContext=[(0x12340000+i*17)&0xffffffff for i in range(105)];n.pack('<105I',0x9868a0,*defaultContext);expectedShader=list(defaultContext)
 for i in [0x5a,0x44,0xd,0x60]:expectedShader[i]=0
 jobs=[(0,0,True,True),(1,1,True,True),(0,1,False,True),(1,0,True,False)]
 for mode,parity,portalEnabled,dynamicFiltering in jobs:
  c=modeCases[mode];matrix=c['world'];projection=c['projection'];flags=sourceFlags if mode==0 else[1]*len(sourceFlags);overrides=sourceOverrides if mode==0 else bytes(625);active=[p['activeFlags']if mode==0 else p['activeFlags']|1 for p in pd['portals']];flagsWord=0x4000|(parity<<15);meta={'source':source,'mode':mode,'parity':parity,'portalsEnabled':portalEnabled,'dynamicPortalFiltering':dynamicFiltering}
  n.pack('<I',display+0x74,flagsWord);n.pack('<I',0x973fcc,0);n.pack('<I',0x973fd0,0);n.pack('<I',0x9718dc,0);n.pack('<I',0x80bab4,int(dynamicFiltering));n.pack('<I',0x80ba58,int(portalEnabled));n.pack('<I',0x80b6f4,1);n.pack('<I',0x80b6f8,0);n.pack('<I',0x80ba14,0);n.pack('<I',0x973940,0);n.pack('<I',0x97394c,0);n.pack('<I',0x97393c,0);n.write(0x80bbe0,bytes(2));n.pack('<I',scene+0x1c,len(data['bounds']));n.pack('<I',scene+0x128,0);n.pack('<I',scene+0x12c,0);n.pack('<I',scene+0x134,0);n.pack('<I',scene+0x138,1);n.pack('<I',scene+0x13c,0);n.pack('<2I',scene+0x140,0x77777777,0x88888888);n.pack('<I',scene+0x148,0xffffffff);n.pack('<i',scene+0xe4,c['depthLimit']);n.pack('<I',scene+0xdc,1);n.pack('<i',scene+0xe0,0x12345678);n.write(scene+0x9c,bytes(64));n.pack('<I',scene+0x9c,staleHeader);n.write(staleHeader,bytes(160));n.pack('<h',staleHeader+158,-7);n.pack('<I',0x96d9c0,arena);n.pack('<I',0x966388,arena+0x60000);n.pack('<i',0x80ba5c,-1);n.pack('<I',0x97398c,0);n.pack('<I',0x973990,pointMemory);n.pack('<3f',pointMemory,*c['point']);n.pack('<16f',0x9736e8,*matrix);n.pack('<4f',0x973728,c['fov'],c['aspect'],c['near'],1000.);n.pack('<16f',0x80b888,*projection);n.pack('<16h',0x963f54,*([-1]*16));n.write(0x280a2f0,bytes([0xa5])*625);n.write(flagsMemory,bytes(flags));n.write(overrideMemory,overrides);n.pack('<I',0x9736e0,alphaCursor);n.pack('<I',alphaCursor,alpha);n.write(alpha,bytes(clipCount*4+16));n.write(shader,bytes([0xa5])*420)
  for ri,r in enumerate(pd['rooms']):n.pack('<I',rooms+24*ri+16,r['flags']|4)
  for pi,value in enumerate(active):n.pack('<I',portals+32*pi+28,value)
  for ptr in materialBits:n.write(ptr,bytes(materialBytes))
  for ptr in clipBits:n.write(ptr,bytes(clipBytes))
  import numpy as np
  view=[f32(v)for v in np.linalg.inv(np.array(matrix).reshape(4,4)).ravel()];n.pack('<16f',0x80b708,*view)
  for address,value in [(0x966378,1.),(0x97313c,.75),(0x966270,.9),(0x96dce4,.65)]:n.pack('<f',address,value)
  preparing=True;n.call(0x5d5500);preparing=False;planeBlock=n.read(0x963fa0,336);events.clear();phaseCalls.clear();ns['calls'].clear();ns['traversalEntries'].clear();n.call(0x5f5830,[display],count=9000000);nativePortalBits=n.read(0x280a2f0,625)
  if portalEnabled:
   compare(hashlib.sha256(nativePortalBits).hexdigest(),c['native']['bitsSHA256'],[meta,'portalBits']);compare(n.unpack('<i',scene+0xe0)[0],c['native']['selectedHeader'],[meta,'root']);compare(n.unpack('<I',scene+0xdc)[0],len(c['nativeVolumes']),[meta,'volumeCount'])
  else:compare(nativePortalBits,bytes([0xa5])*625,[meta,'preservedPortalBits'])
  expectedMat=bytearray(materialBytes);expectedClip=bytearray(clipBytes);expectedAlpha={};expectedEvents=[]
  for group in render['lodGroups']:
   instance=group['instance'];ci=group['firstClipObject'];vf=flags[instance];visible=not portalEnabled or(vf&8)!=0 or bit(nativePortalBits,instance)
   if not visible or not vf&1:continue
   bound=data['bounds'][instance];dist=distance(matrix[12:15],bound['center'])
   if render['lodRangesSquared'][ci]!=0 and dist<render['lodRangesSquared'][ci]:
    ci+=1
    while dist<render['lodRangesSquared'][ci]:ci+=1
   fstart,fend=render['instances'][instance]['fade'];limit=fend if vf&64 and fstart<fend else render['farClipRanges'][ci];result=frustum(planeBlock,1000.,bound['center'],bound['extent'],limit)
   if not result:continue
   expectedClip[ci>>2]|=result<<((ci&3)*2);expectedAlpha[ci]=fade(dist,fstart,fend)if vf&64 else 1.
   for part in data['models'][ci]['parts']:expectedMat[part['material']>>3]|=1<<(part['material']&7)
  for i,s in enumerate(specials):
   bi=s['boundsIndex']
   if specialFlags[i]&2 and(not(dynamicFiltering and portalEnabled)or flags[bi]&8 or bit(nativePortalBits,bi)):
    matrixPtr=remote[i]or(dynamicBase+i*208+64);expectedEvents.append({'special':i,'ownerMatches':True,'matrixHex':n.read(matrixPtr,64).hex(),'usesOverride':bool(remote[i]),'tailArguments':[0,0,0]})
  actual={'phaseCalls':list(phaseCalls),'displayFlags':n.unpack('<I',display+0x74)[0],'contextCount':n.unpack('<I',scene+0x120)[0],'contextScratch':list(n.unpack('<2I',scene+0x140)),'contextFlags':n.unpack('<I',scene+0x148)[0],'cameraMode':n.unpack('<I',0x97394c)[0],'visibilityActive':n.unpack('<I',0x97393c)[0],'shaderContext':list(n.unpack('<105I',shader)),'materialBits':n.read(materialBits[parity],materialBytes).hex(),'clipBits':n.read(clipBits[parity],clipBytes).hex(),'dynamicHandoffs':list(events)}
  expected={'phaseCalls':[hex(x)for x in[0x5f5830,0x5fd0d0,0x5f3c80,0x5f5380,0x603960]]+[hex(0x5f0f00)]*len(expectedEvents),'displayFlags':flagsWord|4,'contextCount':len(data['bounds']),'contextScratch':[0,0],'contextFlags':0xffffffea,'cameraMode':0,'visibilityActive':1,'shaderContext':expectedShader,'materialBits':expectedMat.hex(),'clipBits':expectedClip.hex(),'dynamicHandoffs':expectedEvents};compare(actual,expected,meta);alphaValues=n.unpack('<'+'f'*clipCount,alpha)
  for i,e in expectedAlpha.items():
   a=alphaValues[i];counts['finiteAlphaComparisons']+=1
   compare((math.isnan(a)and math.isnan(e))or abs(a-e)<=1e-7,True,[meta,'alpha',i,a,e])
  counts['normalCases']+=1;counts['selectedStaticClips']+=len(expectedAlpha);counts['dynamicHandoffs']+=len(events);fixtures.append({**meta,'entryFixture':{'point':c['point'],'world':matrix,'projection':projection,'fov':c['fov'],'aspect':c['aspect'],'near':c['near'],'depthLimit':c['depthLimit']},'frustumBlockHex':planeBlock.hex(),'native':actual,'nativeAlpha':[[i,alphaValues[i]]for i in expectedAlpha],'portalBitsHex':nativePortalBits.hex()})
  # Dirty bit4 causes a subsequent normal scheduler call to return via its
  #original empty debug assertion. Global skip suppresses even that assertion.
  for skip in [False,True]:
   n.pack('<I',0x973fcc,int(skip));before=n.read(shader,420);events.clear();phaseCalls.clear();ns['calls'].clear();n.call(0x5f5830,[display]);compare(phaseCalls,[hex(0x5f5830)]+([]if skip else[hex(0x5c12f0)]),[meta,'earlyOrder',skip]);compare(events,[],[meta,'earlyHandoff',skip]);compare(n.read(shader,420),before,[meta,'earlyContext',skip]);counts['earlyReturnCases']+=1
 sources.append({'source':source,'sha256':row['sha256'],'rooms':len(pd['rooms']),'portals':len(pd['portals']),'bounds':len(data['bounds']),'clips':clipCount,'specials':len(specials)});print('scheduling sources',len(sources),'cases',counts['normalCases'],'errors',len(errors),flush=True)
 if errors:break
report={'schema':'original-normal-scene-scheduling-v1','passed':not errors,'binarySHA256':n.sha256,'counts':counts,'sources':sources,'errors':errors,'resultSHA256':digest.hexdigest(),'schedulerCallCounts':schedulerCalls,'portalCallCounts':ns['callCounts'],'fixtureHelper':{'file':str(helper.relative_to(B)),'sha256':hashlib.sha256(helper.read_bytes()).hexdigest(),'reuse':'AST prefix containing only isolated allocator/setup helper definitions and initialization; authored entry batch not executed'},'externalMatrixPreparationCalls':matrixCalls,'fixtureFile':'geometry-scene-scheduling-fixtures.json.gz','boundaryAdapters':{'0x5f0f00':'Records original selected special handle,matrix bytes and trailing arguments, then returns0. Packet generation/material updates/GPU beyond this boundary not executed.','0x5c1240':'Only during prepared frustum-plane construction, external D3DXMatrixMultiply represented by float32-rounded scalar matrix multiplication.'},'limits':['Normal modern display0x4000 only. Original portal/static/frustum/LOD/fade/scheduler instructions execute unchanged.','Grid/tree/shadow/alternate camera modes disabled; their implementations are not recovered by this batch.','Camera/projection inputs are prepared fixtures, not proof of live camera production.','Dynamic handoffs are scheduling decisions, not completed packets/draws.','Original16-clip-volume limit retained; inputs selected from successful safe prior entry fixtures.','Compiled C# execution remains pending; no managed launches.']}
(R/'geometry-scene-scheduling-native-validation.json').write_text(json.dumps(report,indent=2)+'\n')
with gzip.open(R/report['fixtureFile'],'wt',encoding='utf8')as f:json.dump({'cases':fixtures},f,separators=(',',':'),allow_nan=False)
print(json.dumps({k:report[k]for k in ['passed','counts','errors']},indent=2))
if errors:raise SystemExit(1)
