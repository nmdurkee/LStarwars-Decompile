// Separate glTF previews reference the finalized immutable base geometry buffers.
import fs from 'node:fs/promises';import path from 'node:path';import {fileURLToPath} from 'node:url';
import {scenePose} from './animation-scene-pose.mjs';
const slash=s=>s.replaceAll('\\','/');
export async function exportScenePreview(root,entry,{fps=30}={}){
 const rel=entry.source,sourceData=path.join(root,'exports/animation-scenes',rel+'.json'),data=JSON.parse(await fs.readFile(sourceData,'utf8'));
 if(!data.instances.length||!data.animations.some(Boolean))return{source:slash(rel),status:'no-bound-animation',instances:data.instances.length};
 const raw=await fs.readFile(path.join(root,'extracted',rel));
 const base=entry.output,out=path.join(root,'exports/animated-scenes',rel.replace(/\.GSC$/i,'')),gltf=JSON.parse(await fs.readFile(path.join(base,'scene.gltf'),'utf8'));
 const sourceNodes=new Map(gltf.nodes.map((n,i)=>[n.extras?.sourceAddress,i])),metadata=JSON.parse(await fs.readFile(path.join(base,'source-metadata.json'),'utf8'));
 const specialObjects=metadata.specialObjects??metadata.scene?.specialObjects;
 if(!specialObjects)throw Error('Missing special-object metadata');
 for(const list of[gltf.buffers,gltf.images])for(const x of list??[])if(x.uri&&!x.uri.startsWith('data:'))x.uri=slash(path.relative(out,path.resolve(base,decodeURIComponent(x.uri))));
 gltf.buffers??=[];gltf.bufferViews??=[];gltf.accessors??=[];gltf.animations=[];
 const bufferIndex=gltf.buffers.length,parts=[],accessorCache=new Map(),report={source:slash(rel),sourceSha256:data.sourceSha256,baseGeometry:slash(path.relative(root,path.join(base,'scene.gltf'))),previewFPS:fps,clips:[],boundObjects:0,sampledPoses:0,unboundAnimations:[],nullAnimationInstances:[],warnings:[],basisNodesReset:[]};let bytes=0;
 function accessor(values,width){
  if(!values.length||values.some(x=>!Number.isFinite(x)))throw Error('Invalid animation accessor');
  const raw=Buffer.alloc(values.length*4);values.forEach((x,i)=>raw.writeFloatLE(x,i*4));const key=width+':'+raw.toString('base64');if(accessorCache.has(key))return accessorCache.get(key);
  const vi=gltf.bufferViews.length;gltf.bufferViews.push({buffer:bufferIndex,byteOffset:bytes,byteLength:raw.length});parts.push(raw);bytes+=raw.length;
  const a={bufferView:vi,componentType:5126,count:values.length/width,type:width===1?'SCALAR':'VEC'+width,min:Array(width).fill(Infinity),max:Array(width).fill(-Infinity)};
  for(let i=0;i<values.length;i++){const v=raw.readFloatLE(i*4);a.min[i%width]=Math.min(a.min[i%width],v);a.max[i%width]=Math.max(a.max[i%width],v);}gltf.accessors.push(a);const index=gltf.accessors.length-1;accessorCache.set(key,index);return index;
 }
 const all={name:'All decoded motions (synchronised preview)',samplers:[],channels:[],extras:{timing:'All recovered object motions start together at 30 preview frames per second. This is not the game trigger, wait, repeat or visibility state machine.'}},groups=new Map(),seenNodes=new Set();
 for(const binding of data.specialObjectBindings){
  const instance=data.instances[binding.instanceAnimationIndex];if(!instance)throw Error('Missing instance binding');const animation=data.animations[instance.animationIndex];if(!animation){report.nullAnimationInstances.push(instance.index);continue;}if(animation.error)throw Error(animation.error);
  const special=specialObjects[binding.objectIndex],ni=sourceNodes.get(special.address);if(ni===undefined){report.warnings.push(`Object ${binding.objectIndex} ${binding.name} has no exported geometry node`);continue;}
  if(seenNodes.has(ni))throw Error('Multiple motion bindings to same node');seenNodes.add(ni);const node=gltf.nodes[ni],original={};for(const key of['matrix','translation','rotation','scale'])if(node[key])original[key]=node[key];
  node.extras={...node.extras,originalBindTransform:original,instanceAnimation:instance};delete node.matrix;
  for(const ci of node.children??[]){const child=gltf.nodes[ci];if(child.extras?.affineFactorizationOfNode===ni){child.extras.animatedPreviewOriginalBasisRotation=child.rotation;child.rotation=[0,0,0,1];report.basisNodesReset.push(ci);}}
  const translation=special.matrix.slice(12,15),pose=scenePose(animation,animation.header.firstFrame,translation,raw);for(const key of['translation','rotation','scale'])node[key]=pose[key];
  if(!groups.has(instance.animationIndex))groups.set(instance.animationIndex,[]);groups.get(instance.animationIndex).push({node:ni,instance:instance.index,translation,name:binding.name});report.boundObjects++;
 }
 for(let ai=0;ai<data.animations.length;ai++){
  const animation=data.animations[ai];if(!animation)continue;const targets=groups.get(ai);if(!targets){report.unboundAnimations.push(ai);continue;}
  const h=animation.header,framesSet=new Set(animation.keyFramePositions);for(let f=h.firstFrame;f<=h.firstFrame+h.frameCount-1;f++)framesSet.add(f);const frames=[...framesSet].sort((a,b)=>a-b),poses=frames.map(f=>scenePose(animation,f,[0,0,0],raw)),input=accessor(frames.map(f=>(f-h.firstFrame)/fps),1);
  const clip={name:`ALA3_${ai}_${targets[0].name}`,samplers:[],channels:[],extras:{sourceAnimationIndex:ai,sourceOffset:animation.sourceOffset,instanceIndices:targets.map(t=>t.instance),framesPerSecond:fps,sourceFirstFrame:h.firstFrame,sourceFrameCount:h.frameCount,nativeExternalFrameOffset:1,timing:'Neutral 30 fps preview; source script playback conditions and timeFactor are metadata only.',evaluation:'PC scene Euler matrix consumer 0x5ea390, 16-bit angle conversion and original isolated-PC-initialized sine lookup table; glTF LINEAR interpolation between sampled source frames and packed key boundaries.'}};
  function channel(node,kind,values,width){const constant=values.slice(width).every((x,i)=>x===values[i%width]),si=clip.samplers.length;clip.samplers.push({input:constant?accessor([0],1):input,output:accessor(constant?values.slice(0,width):values,width),interpolation:'LINEAR'});clip.channels.push({sampler:si,target:{node,path:kind}});}
  const rotations=[];let previous=null;for(const p of poses){let q=p.rotation;if(previous&&q.reduce((v,x,i)=>v+x*previous[i],0)<0)q=q.map(x=>-x);rotations.push(...q);previous=q;}
  for(const t of targets){channel(t.node,'translation',poses.flatMap(p=>p.translation.map((x,i)=>x+t.translation[i])),3);channel(t.node,'rotation',rotations,4);channel(t.node,'scale',poses.flatMap(p=>p.scale),3);}
  const shift=all.samplers.length;all.samplers.push(...clip.samplers);all.channels.push(...clip.channels.map(c=>({...c,sampler:c.sampler+shift})));gltf.animations.push(clip);report.clips.push({index:ai,name:clip.name,objects:targets.length,samples:frames.length,seconds:(frames.at(-1)-h.firstFrame)/fps});report.sampledPoses+=poses.length;
 }
 if(!gltf.animations.length)return{...report,status:'no-exportable-bound-animation'};
 gltf.animations.unshift(all);gltf.buffers.push({uri:'animation.bin',byteLength:bytes});gltf.asset.generator='Recovered PC scene animation preview exporter';
 report.status='exported';report.animationBytes=bytes;report.limitations=['Scene starts all motions together only for inspection. Gameplay triggers, wait/repeat logic, visibility and texture animations are not simulated.','Individual ALA3 clips are also available. Unselected objects retain the first decoded pose. Original base scene remains separate and unchanged.','Native pose basis, Z conversion, row scaling and base translation are reconstructed; original sine table is recovered; glTF quaternion interpolation approximates continuous native playback.'];gltf.asset.extras={...gltf.asset.extras,sceneAnimationPreview:report.limitations};
 await fs.mkdir(out,{recursive:true});await fs.writeFile(path.join(out,'animation.bin'),Buffer.concat(parts));await fs.writeFile(path.join(out,'animated.gltf'),JSON.stringify(gltf));await fs.writeFile(path.join(out,'animation-report.json'),JSON.stringify(report,null,2));return{...report,output:slash(path.relative(root,path.join(out,'animated.gltf')))};
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
 const root=path.resolve('reverse-engineering'),index=JSON.parse(await fs.readFile(path.join(root,'reports/geometry-finalized-gsc.json'),'utf8')),filter=process.argv[2],report={results:[],failures:[]};
 for(const entry of index.results.filter(e=>!filter||slash(e.source).toLowerCase().includes(filter.toLowerCase()))){try{const r=await exportScenePreview(root,entry);report.results.push(r);if(r.status==='exported')console.log(r.source,r.boundObjects,r.clips.length,r.animationBytes);}catch(e){report.failures.push({source:slash(entry.source),error:e.stack});console.error(entry.source,e.message);}}
 report.totals={checked:report.results.length+report.failures.length,exported:report.results.filter(r=>r.status==='exported').length,failures:report.failures.length};for(const k of['boundObjects','sampledPoses','animationBytes'])report.totals[k]=report.results.reduce((s,r)=>s+(r[k]??0),0);report.totals.clips=report.results.reduce((s,r)=>s+(r.clips?.length??0),0);await fs.writeFile(path.join(root,'reports/animation-scene-preview'+(filter?'-sample':'')+'.json'),JSON.stringify(report,null,2));console.log(report.totals);
}
