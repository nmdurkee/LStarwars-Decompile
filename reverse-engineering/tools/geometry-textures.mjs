// Bounded top-level DDS conversion to PNG. Raw DDS is always retained separately.
// Supports BC1/DXT1, BC2/DXT3, BC3/DXT5 and common masked RGB(A) surfaces.
import zlib from 'node:zlib';
const crcTable=Uint32Array.from({length:256},(_,n)=>{for(let j=0;j<8;j++)n=n&1?0xedb88320^(n>>>1):n>>>1;return n>>>0;});
function crc(buf){let c=0xffffffff;for(const n of buf)c=crcTable[(c^n)&255]^(c>>>8);return(c^0xffffffff)>>>0;}
function chunk(tag,bytes){let type=Buffer.from(tag),r=Buffer.alloc(12+bytes.length);r.writeUInt32BE(bytes.length);type.copy(r,4);bytes.copy(r,8);r.writeUInt32BE(crc(Buffer.concat([type,bytes])),8+bytes.length);return r;}
export function png(width,height,rgba){
  if(rgba.length!==width*height*4)throw Error('RGBA dimensions mismatch');
  let ihdr=Buffer.alloc(13);ihdr.writeUInt32BE(width);ihdr.writeUInt32BE(height,4);ihdr[8]=8;ihdr[9]=6;
  let scan=Buffer.alloc(height*(width*4+1));for(let y=0;y<height;y++)Buffer.from(rgba.buffer,rgba.byteOffset+y*width*4,width*4).copy(scan,y*(width*4+1)+1);
  return Buffer.concat([Buffer.from('89504e470d0a1a0a','hex'),chunk('IHDR',ihdr),chunk('IDAT',zlib.deflateSync(scan)),chunk('IEND',Buffer.alloc(0))]);
}
export function decodeDDS(b){
  if(b.length<128||b.toString('ascii',0,4)!=='DDS '||b.readUInt32LE(4)!==124)throw Error('Invalid DDS header');
  let width=b.readUInt32LE(16),height=b.readUInt32LE(12),flags=b.readUInt32LE(80),fourcc=b.toString('ascii',84,88),bits=b.readUInt32LE(88),caps2=b.readUInt32LE(112);
  if(!width||!height||width>16384||height>16384||width*height>268435456)throw Error('Invalid DDS dimensions');
  let rgba=Buffer.alloc(width*height*4),alphaNonOpaque=false;
  const numericFormat=b.readUInt32LE(84);
  if((flags&4)&&[111,112,113,114,115,116].includes(numericFormat)){
    const half=n=>{let sign=n&32768?-1:1,e=(n>>>10)&31,m=n&1023;return sign*(e===0?m*2**-24:e===31?(m?NaN:Infinity):(1+m/1024)*2**(e-15));};
    const channels={111:1,112:2,113:4,114:1,115:2,116:4}[numericFormat],size=numericFormat<=113?2:4;
    if(128+width*height*channels*size>b.length)throw Error('Truncated float base mip');
    for(let j=0;j<width*height;j++){for(let c=0;c<4;c++){let val=c===3?1:0;if(c<channels){let p=128+(j*channels+c)*size;val=size===2?half(b.readUInt16LE(p)):b.readFloatLE(p);}rgba[j*4+c]=Math.round(Math.max(0,Math.min(1,Number.isFinite(val)?val:0))*255);}if(rgba[j*4+3]<255)alphaNonOpaque=true;}
    fourcc='D3DFMT_'+numericFormat;
  }else if(flags&4){
    if(!['DXT1','DXT3','DXT5'].includes(fourcc))throw Error('Unsupported DDS FourCC '+fourcc);
    let size=fourcc==='DXT1'?8:16,bw=Math.ceil(width/4),bh=Math.ceil(height/4);if(128+bw*bh*size>b.length)throw Error('Truncated BC base mip');
    const c565=v=>{let r=v>>>11,g=(v>>>5)&63,bl=v&31;return[(r<<3)|(r>>>2),(g<<2)|(g>>>4),(bl<<3)|(bl>>>2),255];};
    for(let by=0;by<bh;by++)for(let bx=0;bx<bw;bx++){
      let off=128+(by*bw+bx)*size,co=off+(size===8?0:8),c0=b.readUInt16LE(co),c1=b.readUInt16LE(co+2),pal=[c565(c0),c565(c1)];
      if(c0>c1||fourcc!=='DXT1')for(let j=1;j<=2;j++)pal.push([0,1,2].map(k=>Math.floor(((3-j)*pal[0][k]+j*pal[1][k])/3)).concat(255));
      else{pal.push([0,1,2].map(k=>Math.floor((pal[0][k]+pal[1][k])/2)).concat(255));pal.push([0,0,0,0]);}
      let code=b.readUInt32LE(co+4),ap,ab;
      if(fourcc==='DXT5'){ap=[b[off],b[off+1]];if(ap[0]>ap[1])for(let j=1;j<=6;j++)ap.push(Math.floor(((7-j)*ap[0]+j*ap[1])/7));else{for(let j=1;j<=4;j++)ap.push(Math.floor(((5-j)*ap[0]+j*ap[1])/5));ap.push(0,255);}ab=b.readUIntLE(off+2,6);}
      for(let j=0;j<16;j++){
        let x=bx*4+j%4,y=by*4+(j>>>2);if(x>=width||y>=height)continue;
        let col=pal[(code>>>(j*2))&3],a=col[3];if(fourcc==='DXT3')a=((b[off+(j>>>1)]>>>((j%2)*4))&15)*17;if(fourcc==='DXT5')a=ap[Math.floor(ab/2**(j*3))&7];
        let o=(y*width+x)*4;rgba[o]=col[0];rgba[o+1]=col[1];rgba[o+2]=col[2];rgba[o+3]=a;if(a<255)alphaNonOpaque=true;
      }
    }
  }else if(flags&0x40){
    if(![16,24,32].includes(bits))throw Error('Unsupported RGB bit depth '+bits);
    let bytes=bits/8,row=width*bytes,declared=b.readUInt32LE(20);if((b.readUInt32LE(8)&8)&&declared>=row)row=declared;
    if(128+row*height>b.length)throw Error('Truncated RGB base mip');
    let masks=[92,96,100,104].map(p=>b.readUInt32LE(p));
    function channel(value,mask){if(!mask)return 255;let shift=0;while(((mask>>>shift)&1)===0)shift++;let max=mask>>>shift;return Math.round(((value&mask)>>>shift)*255/max);}
    for(let y=0;y<height;y++)for(let x=0;x<width;x++){let v=b.readUIntLE(128+y*row+x*bytes,bytes),o=(y*width+x)*4;for(let j=0;j<4;j++)rgba[o+j]=channel(v,masks[j]);if(rgba[o+3]<255)alphaNonOpaque=true;}
  }else throw Error('Unsupported DDS pixel flags '+flags.toString(16));
  return {width,height,rgba,fourcc,bits,caps2,alphaNonOpaque,topLevelOnly:true,cubemap:!!(caps2&0x200)};
}
