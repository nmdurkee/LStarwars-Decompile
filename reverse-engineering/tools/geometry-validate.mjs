import fs from 'node:fs/promises';
import path from 'node:path';
import validator from './geometry-validation/node_modules/gltf-validator/index.js';
const input=path.resolve(process.argv[2]),out=process.argv[3];
const report=await validator.validateBytes(new Uint8Array(await fs.readFile(input)),{uri:path.basename(input),maxIssues:0,externalResourceFunction:async uri=>new Uint8Array(await fs.readFile(path.resolve(path.dirname(input),decodeURIComponent(uri))))});
if(out)await fs.writeFile(out,JSON.stringify(report,null,2));
console.log(JSON.stringify({input,validator:validator.version(),errors:report.issues.numErrors,warnings:report.issues.numWarnings,infos:report.issues.numInfos,truncated:report.issues.truncated,firstProblems:report.issues.messages.filter(m=>m.severity<2).slice(0,12)},null,2));
