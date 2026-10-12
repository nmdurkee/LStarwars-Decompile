// Bounded compiler + evaluator for the ATS operations present in this corpus.
// Reference: OpenSaga nutexanim.cpp; native PC corroboration tracked separately.
import fs from 'node:fs/promises';import path from 'node:path';import crypto from 'node:crypto';import {fileURLToPath} from 'node:url';
const fixed=n=>Math.trunc(Math.fround(Math.fround(n*Math.fround(1/60))*4096));
export function compileATS(text,source='buffer'){
  const out={source,name:'',mask:1,on:{},off:{},labels:{},instructions:[],sourceLines:[]},jumps=[];const code=out.instructions;
  for(let [i,raw] of text.split(/\r?\n/).entries()){
    let line=raw.split(';')[0].trim();if(!line)continue;let words=line.match(/"[^"]*"|[^\s,]+/g).map(w=>w.replace(/^"|"$/g,'')),op=words.shift().toLowerCase(),nums=words.map(Number),at=code.length;
    if(op.endsWith(':')){out.labels[op.slice(0,-1)]=at;continue;}
    if(op==='scriptname'){out.name=words[0];continue;}if(op==='scriptmask'){out.mask=nums[0];continue;}
    if(op==='on'||op==='off'){if(nums[0]<0||nums[0]>31)throw Error('Signal outside 0..31');out[op][nums[0]]=at;continue;}
    if(op==='rate'||op==='wait')code.push(op==='rate'?7:4,fixed(nums[0]??0),fixed(nums[1]??0));
    else if(op==='tex')code.push(0,nums[0]);
    else if(op==='texadj')code.push(2,...nums);
    else if(op==='repeat')code.push(13,(nums[0]??0)||-1,nums[1]??0);
    else if(op==='untiltex'){const cond={'=':0,'<':1,'>':2,'<=':3,'>=':4,'<>':5,'!=':5}[words[0]];if(cond===undefined)throw Error('Unknown ATS comparison');code.push(15,cond,nums[1]);}
    else if(op==='goto'){code.push(9,0);jumps.push({at:at+1,label:words[0].toLowerCase()});}
    else if(op==='end')code.push(16);
    else throw Error('Unsupported ATS operation '+op+' at '+source+':'+(i+1));
    out.sourceLines.push({line:i+1,wordOffset:at,text:line});
  }
  for(let j of jumps){if(!(j.label in out.labels))throw Error('Undefined ATS label '+j.label);code[j.at]=out.labels[j.label];}
  if(code.some(n=>!Number.isInteger(n)||n<-32768||n>32767))throw Error('Instruction operand outside signed16');
  if(!out.name)throw Error('Missing script name');return out;
}
export function nativeATSRandom(seed){
  if((seed>>>0)===0)seed=1;
  const x=(seed^0x075bd924)|0,q=Math.trunc(x/0x1f31d);
  let y=(Math.imul(x,0x41a7)-Math.imul(q,0x7fffffff))|0;if(y<0)y=(y+0x7fffffff)|0;
  return (y^0x075bd924)>>>0;
}
export function simulateATS(program,{ticks=1200,on={},off={},random='minimum',frameTicks=68,seed=1}={}){
  let pc=0,texture=0,waitBase=0,waitRandom=0,remaining=0,loops=[],events=[],last=-1,maxTexture=0;const code=program.instructions;
  let randomState=seed>>>0;const rnd=range=>{if(random==='native-seeded'){randomState=nativeATSRandom(randomState);return (randomState|0)%range;}return random==='maximum'?range-1:0;};
  const test=(cond,v)=>[texture===v,texture<v,texture>v,texture<=v,texture>=v,texture!==v][cond];
  for(let tick=0;tick<ticks;tick++){
    for(let [which,signals] of [['off',off],['on',on]])for(let signal of signals[tick]??[])if(program[which][signal]!==undefined){pc=program[which][signal];remaining=0;loops=[];break;}
    if(remaining!==0){remaining-=frameTicks;if(remaining>0)continue;}
    let yielded=false;
    for(let step=0;step<10000;step++){
      if(pc<0||pc>=code.length)throw Error('ATS PC outside code');let op=code[pc];
      if(op===0||op===2){texture=op===0?code[pc+1]:Math.max(code[pc+2],Math.min(code[pc+3],texture+code[pc+1]));pc+=op===0?2:4;remaining+=waitBase+(waitRandom?rnd(waitRandom):0);remaining=Math.max(0,remaining);maxTexture=Math.max(maxTexture,texture);if(texture!==last)events.push({tick,texture}),last=texture;yielded=true;break;}
      if(op===4){remaining+=code[pc+1]+(code[pc+2]?rnd(code[pc+2]):0);pc+=3;remaining=Math.max(0,remaining);yielded=true;break;}
      if(op===7){waitBase=code[pc+1];waitRandom=code[pc+2];pc+=3;continue;}
      if(op===9){pc=code[pc+1];continue;}
      if(op===13){if(loops.length>=16)throw Error('ATS loop stack overflow');loops.push({remaining:code[pc+1]+(code[pc+2]?rnd(code[pc+2]):0),start:pc+3});pc+=3;continue;}
      if(op===15){let loop=loops.at(-1);if(!loop)throw Error('ATS loop stack underflow');if(!test(code[pc+1],code[pc+2])&&loop.remaining!==0){loop.remaining--;pc=loop.start;}else{loops.pop();pc+=3;}continue;}
      if(op===16){yielded=true;break;}
      throw Error('Unsupported executable ATS opcode '+op);
    }
    if(!yielded)throw Error('ATS failed to yield within bounded instruction budget');
  }
  return{ticks,frameTicks,random,...(random==='native-seeded'?{seed,finalRandomState:randomState}:{}),finalPC:pc,maximumTextureIndex:maxTexture,events};
}
if(process.argv[1]&&fileURLToPath(import.meta.url)===path.resolve(process.argv[1])){
  const root=path.resolve('reverse-engineering'),dir=path.join(root,'extracted/STUFF/ATS'),out=path.join(root,'exports/geometry/texture-programs');await fs.mkdir(out,{recursive:true});let programs=[],errors=[];
  for(let filename of (await fs.readdir(dir)).filter(x=>/\.ATS$/i.test(x)).sort())try{
    const b=await fs.readFile(path.join(dir,filename)),p=compileATS(b.toString('utf8'),filename),scenarios=[];
    for(let {random,seed,suffix} of [{random:'minimum',suffix:'minimum'},{random:'maximum',suffix:'maximum'},...[1,305419896,2147483647].map(seed=>({random:'native-seeded',seed,suffix:'native_'+seed}))]){scenarios.push({name:'initial_'+suffix,...simulateATS(p,{random,seed})});for(let signal of Object.keys(p.on))scenarios.push({name:'signal_'+signal+'_'+suffix,...simulateATS(p,{random,seed,on:{10:[+signal]}})});for(let signal of Object.keys(p.off))scenarios.push({name:'off_'+signal+'_'+suffix,...simulateATS(p,{random,seed,on:{10:[+signal]},off:{500:[+signal]}})});}
    const record={...p,sha256:crypto.createHash('sha256').update(b).digest('hex'),semantics:'Fixed-point 4096 units/second; Rate/Wait operands compiled from 60-Hz authored frame counts. Each Tex/TexAdj/Wait yields immediately. On/Off edges reset stacks and jump. End holds until a signal. Simulation uses 68 fixed units/tick; minimum/maximum bounds and seeded original-PC XOR Park-Miller RNG scenarios. Live frame timing and simultaneous multi-program global RNG scheduling are not simulated.',scenarios};
    await fs.writeFile(path.join(out,filename+'.json'),JSON.stringify(record,null,2));let bytes=Buffer.alloc(p.instructions.length*2);p.instructions.forEach((n,i)=>bytes.writeInt16LE(n,i*2));await fs.writeFile(path.join(out,filename+'.code.bin'),bytes);programs.push({source:filename,name:p.name,mask:p.mask,words:p.instructions.length,on:p.on,off:p.off,maximumTextureIndex:Math.max(...scenarios.map(x=>x.maximumTextureIndex)),scenarios:scenarios.length,output:path.relative(root,path.join(out,filename+'.json'))});
  }catch(e){errors.push({source:filename,error:e.message});}
  await fs.writeFile(path.join(root,'reports/geometry-texture-programs.json'),JSON.stringify({programs,errors},null,2));console.log(JSON.stringify({programs:programs.length,scenarios:programs.reduce((n,p)=>n+p.scenarios,0),errors},null,2));
}
