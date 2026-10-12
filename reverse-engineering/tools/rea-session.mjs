import fs from 'node:fs/promises';
import path from 'node:path';
import {spawn} from 'node:child_process';
import {createInterface} from 'node:readline';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const queue=path.join(base, 'rea-queue');
const progressLog=path.join(base,'reports/rea/helper-progress.log');
console.log=(...args)=>{fs.appendFile(progressLog,args.join(' ')+'\n').catch(()=>{});};
const reports=path.join(base, 'reports', 'rea');
await fs.mkdir(queue,{recursive:true});await fs.mkdir(reports,{recursive:true});
const server=spawn(process.execPath,[path.join(base,'tools/rea/node_modules/rea-agents/scripts/rea.mjs'),'mcp'],{windowsHide:true,env:process.env,stdio:['pipe','pipe','pipe']});
let id=0;const pending=new Map();
const stderr=await fs.open(path.join(reports,'server.log'),'a');
server.stderr.on('data',d=>stderr.write(d));
createInterface({input:server.stdout}).on('line',line=>{
 let data;try{data=JSON.parse(line);}catch{console.error('Non-JSON server output:',line.slice(0,100));return;}
 if(data.id!==undefined&&pending.has(data.id)){const p=pending.get(data.id);pending.delete(data.id);clearTimeout(p.timer);data.error?p.reject(Error(JSON.stringify(data.error))):p.resolve(data.result);}
});
function rpc(method,params){return new Promise((resolve,reject)=>{const n=++id;const timer=setTimeout(()=>{pending.delete(n);reject(Error('RPC timeout: '+method));},2100000);pending.set(n,{resolve,reject,timer});server.stdin.write(JSON.stringify({jsonrpc:'2.0',id:n,method,params})+'\n');});}
server.on('exit',code=>{for(const p of pending.values()){clearTimeout(p.timer);p.reject(Error('Server exited '+code));}pending.clear();});
async function save(name,data){const target=path.join(reports,name);const temporary=target+'.writing';await fs.writeFile(temporary,JSON.stringify(data,null,2));await fs.rename(temporary,target);}
try{
 await save('initialize.json',await rpc('initialize',{protocolVersion:'2025-03-26',capabilities:{},clientInfo:{name:'local-game-analysis',version:'1.0'}}));
 server.stdin.write(JSON.stringify({jsonrpc:'2.0',method:'notifications/initialized'})+'\n');
 await save('tools.json',await rpc('tools/list',{}));
 console.log('REA ready; request files go in '+queue);
 let idle=0;
 while(idle<7200){
  const jobs=(await fs.readdir(queue)).filter(f=>f.endsWith('.request.json')).sort((a,b)=>parseInt(a,10)-parseInt(b,10)||a.localeCompare(b)).slice(0,1);
  if(!jobs.length){await new Promise(r=>setTimeout(r,1000));idle++;continue;}idle=0;
  for(const name of jobs){
   const file=path.join(queue,name);let job;
   try{job=JSON.parse((await fs.readFile(file,'utf8')).replace(/^\uFEFF/,''));}
   catch(e){await save(name.replace('.request.json','.result.json'),{hostError:'Malformed queue JSON: '+e.message});await fs.rename(file,file.replace('.request.json','.invalid.json'));console.error('Rejected malformed request '+name);continue;}
   await fs.rename(file,file.replace('.request.json','.running.json'));
   console.log('Starting '+name+': '+job.name);
   try{const result=await rpc('tools/call',{name:job.name,arguments:job.arguments??{}});await save(name.replace('.request.json','.result.json'),result);console.log('Finished '+name+' error='+Boolean(result.isError));}
   catch(e){await save(name.replace('.request.json','.result.json'),{hostError:e.message});console.error(e.message);}
   await fs.rename(file.replace('.request.json','.running.json'),file.replace('.request.json','.done.json'));
   if(job.name==='close_binary'){server.stdin.end();await new Promise(r=>setTimeout(r,1500));server.kill();await stderr.close();process.exit(0);}
  }
 }
}finally{server.stdin.end();server.kill();await stderr.close().catch(()=>{});}
