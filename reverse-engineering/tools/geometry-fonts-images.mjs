import fs from 'node:fs/promises';import path from 'node:path';import crypto from 'node:crypto';import {decodeDDS,png} from './geometry-textures.mjs';
const root=path.resolve('reverse-engineering'),ex=path.join(root,'extracted'),out=path.join(root,'exports/geometry/standalone');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
async function walk(dir){let a=[];for(let e of await fs.readdir(dir,{withFileTypes:true})){let p=path.join(dir,e.name);if(e.isDirectory())a.push(...await walk(p));else if(/\.(dds|fnt|raw)$/i.test(e.name))a.push(p);}return a;}
const results=[],errors=[];
for(const input of (await walk(ex)).sort()){
  const relative=path.relative(ex,input),b=await fs.readFile(input),base=path.join(out,relative);await fs.mkdir(path.dirname(base),{recursive:true});let result={source:relative,bytes:b.length,sha256:sha(b)};
  try{
    if(/\.dds$/i.test(input)){let d=decodeDDS(b);await fs.writeFile(base+'.png',png(d.width,d.height,d.rgba));Object.assign(result,{kind:'DDS',width:d.width,height:d.height,format:d.fourcc.replaceAll('\0',''),cubemap:d.cubemap,png:path.relative(root,base+'.png'),scope:'Base mip, first face preview. Original DDS retains all mipmaps/faces.'});}
    if(/\.fnt$/i.test(input)){
      const range=(p,n)=>{if(p<0||p+n>b.length||!Number.isInteger(p))throw Error('FNT range out of bounds');};
      const ptr=p=>{range(p,4);let v=b.readInt32LE(p);let r=v?p+v:0;range(r,0);return r;},u=p=>b.readUInt32LE(p),f=p=>b.readFloatLE(p);
      let reloc=u(0),count=u(reloc);range(reloc+4,count*4);if(reloc+4+count*4!==b.length)throw Error('FNT relocation table does not end at EOF');
      let relocationFields=[];for(let j=0;j<count;j++){let field=ptr(reloc+4+j*4);range(field,4);relocationFields.push({field,target:ptr(field)});}
      let font=ptr(4),texture=ptr(8),glyphCount=u(font+12),unicodeCount=u(font+16),glyphPtr=ptr(font+52),unicodePtr=ptr(font+56);range(glyphPtr,glyphCount*12);range(unicodePtr,unicodeCount*4);
      let atlas=b.subarray(texture,reloc),d=decodeDDS(atlas),height=f(font+20),glyphs=Array.from({length:glyphCount},(_,j)=>({index:j,x:f(glyphPtr+j*12),y:f(glyphPtr+j*12+4),width:f(glyphPtr+j*12+8),height}));
      for(let g of glyphs)if(![g.x,g.y,g.width,g.height].every(Number.isFinite)||g.x<0||g.y<0||g.x+g.width>d.width||g.y+g.height>d.height)throw Error('Glyph exceeds font atlas');
      let unicode=Array.from({length:unicodeCount},(_,j)=>{let code=b.readUInt16LE(unicodePtr+j*4),index=b.readUInt16LE(unicodePtr+j*4+2);return{codePoint:code,character:String.fromCharCode(code),glyphIndex:index,inGlyphTable:index<glyphCount,spaceCode:index===32};});
      await fs.writeFile(base+'.atlas.dds',atlas);await fs.writeFile(base+'.atlas.png',png(d.width,d.height,d.rgba));
      Object.assign(result,{kind:'FNT',fontOffset:font,textureOffset:texture,textureBytes:atlas.length,atlasSHA256:sha(atlas),atlasWidth:d.width,atlasHeight:d.height,flags:b.readUInt16LE(font+6),height,baseline:f(font+24),spaceWidth:f(font+28),interCharacterGap:f(font+36),glyphCount,unicodeCount,glyphs,unicode,relocationFields,atlas:path.relative(root,base+'.atlas.png'),evidence:'VUFNT and VUFNTCHAR/VUCHARIDX definitions cross-checked with OpenSaga nuqfnt.h; all glyph rectangles and tables bounded in supplied PC files. Unicode index32 is a spacing control even when outside button glyph table.'});
      await fs.writeFile(base+'.json',JSON.stringify(result,null,2));
    }
    if(/\.raw$/i.test(input)){
      const paired=input.replace(/\.raw$/i,'_PC.DDS'),db=await fs.readFile(paired),width=db.readUInt32LE(16),height=db.readUInt32LE(12);if(width*height*4!==b.length)throw Error('RAW byte count not matched by paired DDS dimensions');
      // No header exists to assert the channel order; export both plausible orders.
      let bgra=Buffer.from(b);for(let p=0;p<bgra.length;p+=4)[bgra[p],bgra[p+2]]=[bgra[p+2],bgra[p]];
      await fs.writeFile(base+'.rgba-candidate.png',png(width,height,b));await fs.writeFile(base+'.bgra-candidate.png',png(width,height,bgra));
      Object.assign(result,{kind:'RAW',width,height,bytesPerPixel:4,pairedDDS:path.relative(ex,paired),dimensionEvidence:'Pair basename and exact width*height*4 size agree. Headerless carrier; dimensions/channel interpretation are inferred.',scope:'Two labelled RGBA/BGRA candidate previews; not a confirmed texture conversion or exact match to paired compressed DDS.'});
    }
    results.push(result);
  }catch(e){errors.push({...result,error:e.message});}
}
await fs.writeFile(path.join(root,'reports/geometry-fonts-images.json'),JSON.stringify({results,errors},null,2));console.log(JSON.stringify({files:results.length,counts:Object.fromEntries(['DDS','FNT','RAW'].map(k=>[k,results.filter(r=>r.kind===k).length])),errors},null,2));
