import fs from 'node:fs/promises';
import path from 'node:path';
import {execFile} from 'node:child_process';
import {promisify} from 'node:util';
import {fileURLToPath} from 'node:url';
const base=path.resolve(path.dirname(fileURLToPath(import.meta.url)),'..');
const run=promisify(execFile);
const game=path.resolve(base,'../Lego Star Wars Saga');
const archive=process.argv[2]??'EPISODE_I.DAT';
if(!/^(GAME|EPISODE_I{1,3}|EPISODE_IV|EPISODE_V|EPISODE_VI)\.DAT$/.test(archive))throw Error('Choose an installed DAT archive');
const filter=process.argv[3];
const args=['-R','-k','-q'];
if(filter)args.push('-f',filter);
args.push('-L',path.join(base,'reports',archive+'-extraction-list.txt'),path.join(base,'references/ttgames.bms'),path.join(game,archive),path.join(base,'extracted'));
try{const result=await run(path.join(base,'tools/quickbms/quickbms.exe'),args,{windowsHide:true,maxBuffer:16*1024*1024});await fs.writeFile(path.join(base,'reports',archive+'-extraction.log'),result.stdout+result.stderr);console.log(archive+' extraction exited successfully');}
catch(e){await fs.writeFile(path.join(base,'reports',archive+'-extraction.log'),(e.stdout??'')+(e.stderr??'')+'\n'+e.message);throw e;}
