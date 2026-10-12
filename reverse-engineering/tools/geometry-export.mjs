// Export decoded Nu2 geometry as standard glTF 2.0. Source metadata remains authoritative.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {fileURLToPath} from 'node:url';
import {parseNu2,decodeMesh,identity} from './geometry-nu2.mjs';
import {decodeDDS,png} from './geometry-textures.mjs';
export const hash=b=>crypto.createHash('sha256').update(b).digest('hex');
const textureMemo=new Map();
export async function exportGeometry(input,out,textureDirectory){
  const b=await fs.readFile(input),scene=parseNu2(b,input);await fs.mkdir(out,{recursive:true});await fs.mkdir(textureDirectory,{recursive:true});
  const gltf={asset:{version:'2.0',generator:'Nu2 static evidence exporter',extras:{sourceSHA256:scene.sha256,scope:'Recovered geometry with approximate standard materials. Static visibility and animation are not executed.'}},scene:0,scenes:[{name:'Static environment and all named object records',nodes:[]},{name:'Static environment only',nodes:[]},{name:'Individual model library (overlaid in source local coordinates)',nodes:[]}],nodes:[],meshes:[],materials:[],textures:[],images:[],samplers:[{magFilter:9729,minFilter:9987,wrapS:10497,wrapT:10497}],accessors:[],bufferViews:[],buffers:[]};
  const imageMap=new Map(),texMap=new Map(),textureResults=[],problems=[];
  const relativeFile=file=>path.relative(out,file).replaceAll('\\','/');
  for(const t of scene.textures){if(!t.size)continue;let raw=b.subarray(t.offset,t.offset+t.size),digest=hash(raw),magic=raw.toString('ascii',0,4),ext=magic==='DDS '?'.dds':raw[0]===137&&raw.toString('ascii',1,4)==='PNG'?'.png':'.bin';
    const rawPath=path.join(textureDirectory,digest+ext);if(!textureMemo.has(digest))try{await fs.writeFile(rawPath,raw,{flag:'wx'});}catch(e){if(e.code!=='EEXIST')throw e;}
    let result={...t,sha256:digest,raw:relativeFile(rawPath)};
    try{
      let pngPath,decoded,cached=textureMemo.get(digest);
      if(cached){pngPath=cached.pngPath;Object.assign(result,cached.meta);}
      else if(ext==='.dds'){decoded=decodeDDS(raw);pngPath=path.join(textureDirectory,digest+'.png');await fs.writeFile(pngPath,png(decoded.width,decoded.height,decoded.rgba));let meta={format:decoded.fourcc.replaceAll('\0',''),width:decoded.width,height:decoded.height,cubemap:decoded.cubemap,alphaNonOpaque:decoded.alphaNonOpaque,pngTopMipOnly:true};Object.assign(result,meta);textureMemo.set(digest,{pngPath,meta});}
      else if(ext==='.png')pngPath=rawPath;else throw Error('Unknown image allocation');
      result.png=relativeFile(pngPath);
      let image=imageMap.get(digest);if(image===undefined){image=gltf.images.length;gltf.images.push({uri:result.png,name:'Texture_'+t.index});imageMap.set(digest,image);}
      let tx=gltf.textures.length;gltf.textures.push({source:image,sampler:0});texMap.set(t.index,{index:tx,alpha:result.alphaNonOpaque});
    }catch(e){result.conversionError=e.message;problems.push(`Texture ${t.index}: ${e.message}`);}
    textureResults.push(result);
  }
  for(const m of scene.materials){let tex=texMap.get(m.diffuse),color=m.color.slice(0,3).map(v=>Number.isFinite(v)?Math.max(0,Math.min(1,v)):1),pbr={baseColorFactor:[...color,1],metallicFactor:0,roughnessFactor:0.65};if(tex)pbr.baseColorTexture={index:tex.index};
    const alpha=(m.alpha&15)===1||(m.alpha&15)===2||(m.alpha&15)===3?'BLEND':tex?.alpha?'MASK':'OPAQUE';
    gltf.materials.push({name:'Material_'+m.index,pbrMetallicRoughness:pbr,doubleSided:true,alphaMode:alpha,...(alpha==='MASK'?{alphaCutoff:0.05}:{}),extras:{sourceAddress:m.address,rawAlphaFlags:m.alpha,rawColor:m.color,shaderFlags:m.shaderFlags,warning:'Approximate PBR display; Nu2 lightmaps, reflection, FX and blend rules preserved in source metadata only.'}});
  }
  const buffers=[];let byteLength=0;
  function accessor(values,components,type='float',target=34962){
    if(!values.length)return undefined;const isInt=type==='uint',buf=Buffer.alloc(values.length*4);for(let j=0;j<values.length;j++)isInt?buf.writeUInt32LE(values[j],j*4):buf.writeFloatLE(values[j],j*4);
    let min=Array(components).fill(Infinity),max=Array(components).fill(-Infinity);for(let j=0;j<values.length;j++){let v=values[j];if(!Number.isFinite(v))throw Error('Nonfinite accessor');min[j%components]=Math.min(min[j%components],v);max[j%components]=Math.max(max[j%components],v);}
    let view=gltf.bufferViews.length;gltf.bufferViews.push({buffer:0,byteOffset:byteLength,byteLength:buf.length,target});buffers.push(buf);byteLength+=buf.length;
    let index=gltf.accessors.length;gltf.accessors.push({bufferView:view,componentType:isInt?5125:5126,count:values.length/components,type:components===1?'SCALAR':'VEC'+components,min,max});return index;
  }
  const pairs=new Map(),pairMetadata=[],usedMeshes=new Set();
  function meshFor(mi,ma){let key=mi+':'+ma;if(pairs.has(key))return pairs.get(key);if(mi===undefined)return undefined;
    try{let d=decodeMesh(b,scene,mi,ma);if(!d.indices.length){problems.push(`Mesh ${mi} has no supported triangles`);return undefined;}
      let attributes={POSITION:accessor(d.positions,3)};
      if(d.uv.length)attributes.TEXCOORD_0=accessor(d.uv,2);
      if(d.normals.length){let nn=[];for(let j=0;j<d.normals.length;j+=3){let len=Math.hypot(...d.normals.slice(j,j+3));nn.push(...(len>1e-8?d.normals.slice(j,j+3).map(x=>x/len):[0,1,0]));}attributes.NORMAL=accessor(nn,3);}
      if(d.colors.length){let col=[];for(let j=0;j<d.colors.length;j+=4)col.push(Math.min(1,d.colors[j+2]*2),Math.min(1,d.colors[j+1]*2),Math.min(1,d.colors[j]*2),Math.min(1,d.colors[j+3]*2));attributes.COLOR_0=accessor(col,4);}
      let primitive={attributes,indices:accessor(d.indices,1,'uint',34963),mode:4};if(ma!==undefined)primitive.material=ma;
      let index=gltf.meshes.length;gltf.meshes.push({name:`Mesh_${mi}_Material_${ma??'unresolved'}`,primitives:[primitive],extras:{sourceMesh:mi,sourceAddress:scene.meshes[mi].address,dynamic:scene.meshes[mi].dynamic,hasUnexportedSkinAttributes:!!(d.weights.length||d.joints.length)}});pairs.set(key,index);usedMeshes.add(mi);pairMetadata.push({mesh:mi,material:ma,exportMesh:index,vertices:d.positions.length/3,triangles:d.indices.length/3,rawIndexCount:d.sourceIndexCount});return index;
    }catch(e){problems.push(`Mesh ${mi}, material ${ma}: ${e.message}`);return undefined;}
  }
  const billboardExports=[];
  function billboardFor(bi,ma){let key='billboard:'+bi+':'+ma;if(pairs.has(key))return pairs.get(key);let bb=scene.billboards[bi];if(!bb)return undefined;
    let positions=[],uv=[],colors=[];for(let v of bb.vertices){positions.push(v.center[0]+v.corner[0],v.center[1]+v.corner[1],v.center[2]);uv.push(...v.uv);colors.push(...[v.color[2],v.color[1],v.color[0],v.color[3]].map(c=>Math.min(1,c/127.5)));}
    if(!positions.length)return undefined;let primitive={attributes:{POSITION:accessor(positions,3),TEXCOORD_0:accessor(uv,2),COLOR_0:accessor(colors,4)},indices:accessor(Array.from({length:bb.vertices.length},(_,j)=>j),1,'uint',34963),mode:4};if(ma!==undefined)primitive.material=ma;
    let index=gltf.meshes.length;gltf.meshes.push({name:`Billboard_${bi}_Fixed_XY_Preview`,primitives:[primitive],extras:{sourceBillboard:bi,sourceAddress:bb.address,warning:'Camera-facing corners expanded in fixed local XY plane for interchange preview; runtime camera-facing shader must be reconstructed.'}});pairs.set(key,index);billboardExports.push({billboard:bi,material:ma,exportMesh:index,faces:bb.faceCount});return index;
  }
  function node(n){if(n.children&&!n.children.length)delete n.children;if(n.matrix?.every((v,i)=>v===identity[i]))delete n.matrix;let index=gltf.nodes.length;gltf.nodes.push(n);return index;}
  function group(name,children,extras={}){return node({name,children,extras});}
  const statics=[];
  for(const dl of scene.displayLists){let material,matrix=identity,children=[];
    for(let j=dl.first;j<=dl.last;j++){let c=scene.commands[j];if(c.type===0x80)material=c.material;if(c.type===0x83)matrix=c.matrix;if(c.type===0x82||c.type===0x8f){let mesh=c.type===0x82?meshFor(c.mesh,material):billboardFor(c.billboard,material);if(mesh!==undefined)children.push(node({name:`Static_${dl.index}_Command_${j}`,mesh,matrix,extras:{commandAddress:c.address}}));}}
    statics.push(group('DisplayList_'+dl.index,children,{sourceAddress:dl.address,order:dl.order}));
  }
  const modelMeshes=new Map();
  for(const model of scene.models){let list=[];for(const p of model.parts){let command=scene.commands[p.command];if(command?.type===0x82||command?.type===0x8f){let m=command.type===0x82?meshFor(command.mesh,p.material):billboardFor(command.billboard,p.material);if(m!==undefined)list.push(m);}else problems.push(`Model ${model.index} part command ${p.command} type ${command?.type} not geometry`);}modelMeshes.set(model.index,list);}
  const objects=[];
  for(const obj of scene.specialObjects){let children=(modelMeshes.get(obj.model)??[]).map(mesh=>node({mesh}));objects.push(node({name:obj.name,matrix:obj.matrix,children,extras:{sourceAddress:obj.address,sourceModel:obj.model,boundsIndex:obj.boundsIndex,visibilityFunction:obj.visibilityFunction,warning:'All stored objects included; visibility/LOD/puzzle state not simulated.'}}));}
  gltf.scenes[0].nodes=[group('Static_environment',statics),group('All_named_objects',objects)];gltf.scenes[1].nodes=[gltf.scenes[0].nodes[0]];
  for(const model of scene.models){gltf.scenes[2].nodes.push(group('Model_'+model.index,(modelMeshes.get(model.index)??[]).map(mesh=>node({mesh})),{sourceAddress:model.address}));}
  // Unassociated character meshes remain viewable with neutral material, never guessed material IDs.
  let loose=[];for(const m of scene.meshes)if(!usedMeshes.has(m.index)){let mesh=meshFor(m.index,undefined);if(mesh!==undefined)loose.push(node({name:'UnassociatedMesh_'+m.index,mesh}));}
  if(loose.length){let gi=group('Unassociated mesh buffers (unskinned)',loose);gltf.scenes.push({name:'Unassociated geometry (neutral material; no recovered skin)',nodes:[gi]});if(!statics.length&&!objects.length)gltf.scene=gltf.scenes.length-1;}
  if(!byteLength){delete gltf.buffers;delete gltf.bufferViews;delete gltf.accessors;}else{gltf.buffers=[{byteLength,uri:'geometry.bin'}];await fs.writeFile(path.join(out,'geometry.bin'),Buffer.concat(buffers));}
  for(const key of ['images','textures','materials','meshes','accessors','bufferViews'])if(gltf[key]?.length===0)delete gltf[key];
  if(!gltf.textures)delete gltf.samplers;for(const s of gltf.scenes)if(!s.nodes?.length)delete s.nodes;
  await fs.writeFile(path.join(out,'scene.gltf'),JSON.stringify(gltf));
  const manifest={...scene,textureExports:textureResults,meshExports:pairMetadata,billboardExports,exportProblems:problems,exportNotes:['Native coordinates retained. Matrix storage is compatible with glTF column-major ordering.','All named objects included independently of gameplay visibility/LOD. Alternative states may overlap.','PBR colors/alpha are approximations. Original shaders, lightmaps, animated deformation and particles are not implemented.','Billboards retain centers, UVs, colors and corner offsets in metadata; glTF renders a fixed local XY preview instead of dynamic camera-facing geometry.','DDS raw payloads retain all stored mips/faces; PNG previews use top mip and first cubemap face.','Raw source .GHG mesh positions are unskinned until material/palette/joint binding is recovered.']};
  await fs.writeFile(path.join(out,'source-metadata.json'),JSON.stringify(manifest,null,2));
  return {source:input,output:out,sha256:scene.sha256,meshes:scene.meshes.length,exportedUniqueMeshes:usedMeshes.size,meshMaterialPairs:pairMetadata.length,billboards:billboardExports.length,triangles:pairMetadata.reduce((n,m)=>n+m.triangles,0)+billboardExports.reduce((n,m)=>n+m.faces*2,0),textures:textureResults.length,convertedTextures:textureResults.filter(t=>t.png).length,staticLists:scene.displayLists.length,specialObjects:scene.specialObjects.length,problems,warnings:scene.warnings,binaryBytes:byteLength};
}
if(typeof process!=='undefined'&&process.argv[1]&&fileURLToPath(import.meta.url)===path.resolve(process.argv[1])){
  const [input,out,textureDirectory]=process.argv.slice(2);if(!input||!out)throw Error('Usage: node geometry-export.mjs input.GSC output-directory [shared-textures-directory]');console.log(JSON.stringify(await exportGeometry(input,out,textureDirectory??path.join(out,'textures')),null,2));
}
