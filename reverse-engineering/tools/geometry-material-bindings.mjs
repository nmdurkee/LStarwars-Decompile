// Original PC material uniform formulas, recovered from FUN_742730 and helpers.
// Values are candidate bindings: shaders only request the uniforms they use.
export const uniformNames={0:'ambientColor',2:'incandescentGlow',9:'bitangentFlip',10:'surface_params',11:'surface_params2',12:'specular_params',13:'envmap_params',14:'vtf_kHeight',15:'vtf_kNormal',16:'gooch_params',51:'layer0_diffuse',52:'layer1_diffuse',53:'layer2_diffuse',54:'layer3_diffuse',55:'layer_kOpacities',57:'specular_specular',58:'specular2_specular',59:'refraction_color',60:'refraction_kIndex',64:'uvOffset0',65:'uvOffset1',66:'uvOffset2',67:'uvOffset3',72:'lego_params',80:'fxAttributes',81:'dappleLimit',83:'carpaint_params',91:'edgelit_params',92:'fractal_params'};
export function decodeMaterialUniforms(b,{specularPowerScale=1}={}){
 if(b.length!==708)throw Error('Uniform mapping requires current 708-byte material');
 const f=o=>b.readFloatLE(o),color=o=>Array.from(b.subarray(o,o+4),v=>v/255),v={};
 v[0]=color(0x11c);v[2]=color(0x120);v[2][3]=f(0x1b4);v[9]=[b[0xfb]?-1:1];
 v[10]=[f(0x134),1,f(0x138)*0.035,f(0x14c)];v[11]=[f(0xf0),f(0x284)/f(0x274),0,0];
 v[12]=[f(0x130)*specularPowerScale,f(0x12c),f(0x144),f(0x148)];v[13]=[f(0x140),f(0x13c),f(0x248),0];v[14]=[f(0x114)];v[15]=[f(0x118)];v[16]=[f(0x1b8),f(0x1bc),0,0];
 for(let i=0;i<4;i++){v[0x33+i]=color(0xc8+i*4);v[0x40+i]=[f(0x1d0+i*8),f(0x1d4+i*8)];}
 v[0x37]=[f(0xd8),f(0xdc),f(0xe0),f(0xe4)];v[0x39]=color(0x128);v[0x3a]=color(0xf4);v[0x3b]=color(0x124);v[0x3b][3]=f(0x158);v[0x3c]=[(f(0x150)-1)*0.1];
 v[0x48]=[0.05,f(0x60)*0.32,0.2,0.8];v[0x50]=[(b.readUInt32LE(0x26c)&0x8000)&&f(0x60)===0?1:f(0x60),f(0x64),f(0x68),f(0x64)*f(0x68)*0.2];v[0x51]=[f(0x154)];v[0x53]=[f(0x260),f(0x264),0,0];v[0x5b]=[1/f(0x290),f(0x288),f(0x28c),f(0x294)];v[0x5c]=[f(0x274)*0.1,f(0x27c),f(0x280),f(0x278)];
 return Object.entries(v).map(([id,values])=>({semanticID:Number(id),name:uniformNames[id],values:values.map(x=>{let v=Math.fround(x);return Number.isFinite(v)?v:{nonfinite:Number.isNaN(v)?'NaN':v>0?'+Infinity':'-Infinity'};})}));
}
