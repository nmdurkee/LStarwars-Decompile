// Direct invocation of the installed compiler; does not launch generated programs.
import fs from 'node:fs/promises';
import path from 'node:path';
import crypto from 'node:crypto';
import {execFile} from 'node:child_process';
import {fileURLToPath} from 'node:url';
const directory=path.dirname(fileURLToPath(import.meta.url));
const compiler=path.join(process.env.WINDIR??'C:\\Windows','Microsoft.NET','Framework64','v4.0.30319','csc.exe');
const manifest=JSON.parse(await fs.readFile(path.join(directory,'source-manifest.json'),'utf8'));
const bin=path.join(directory,'bin');await fs.mkdir(bin,{recursive:true});
const sources=manifest.modules.flatMap(m=>m.files.map(f=>path.resolve(directory,f)));
const harness=manifest.harnessFiles.map(f=>path.resolve(directory,f));
const library=path.join(bin,'Recovered.Runtime.dll'),verifier=path.join(bin,'RecoveredSourceVerify.exe');
const hash=async p=>crypto.createHash('sha256').update(await fs.readFile(p)).digest('hex');
async function compile(response,args){
 await fs.writeFile(response,'\ufeff'+args.map(a=>'"'+a+'"').join('\n')+'\n');
 await new Promise((resolve,reject)=>execFile(compiler,['@'+response],{cwd:directory,maxBuffer:1024*1024},(err,out,stderr)=>{if(out)process.stdout.write(out);if(stderr)process.stderr.write(stderr);err?reject(err):resolve();}));
}
await compile(path.join(bin,'library-build.rsp'),['/nologo','/target:library','/optimize+','/platform:anycpu','/out:'+library,...sources]);
await compile(path.join(bin,'verifier-build.rsp'),['/nologo','/target:exe','/optimize+','/platform:anycpu','/r:System.Web.Extensions.dll','/main:RecoveredSourceVerify','/out:'+verifier,...sources,...harness]);
const report={updated:new Date().toISOString(),compiler,libraryCompiled:true,unifiedVerifierCompiled:true,librarySha256:await hash(library),sources:await Promise.all(sources.map(async p=>({path:p,sha256:await hash(p)}))),harnessSources:await Promise.all(harness.map(async p=>({path:p,sha256:await hash(p)}))),unifiedVerifierSha256:await hash(verifier),execution:'Build only. Compilation is not an execution or differential verification pass.',invocation:'Direct compiler through build.mjs. PowerShell script launch was disabled by execution policy; no policy or security settings changed.'};
await fs.writeFile(path.resolve(directory,'../reports/reconstructed-build.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({compiledCoreSources:sources.length,compiledHarnessSources:harness.length,librarySha256:report.librarySha256,unifiedVerifierSha256:report.unifiedVerifierSha256}));
