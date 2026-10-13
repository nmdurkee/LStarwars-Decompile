import fs from 'node:fs';
import crypto from 'node:crypto';
const root='reverse-engineering/',read=p=>JSON.parse(fs.readFileSync(root+p));
const tests=read('reports/native-effect-activation-tests.json');if(tests.mismatches)throw Error('Native mismatches');
const file=p=>{const b=fs.readFileSync(root+p);return{path:root+p,bytes:b.length,sha256:crypto.createHash('sha256').update(b).digest('hex')};};
const source=file('reconstructed/gameplay/EffectActivation.cs'),harness=file('tools/native-effect-activation-portable-verify.cs');
const contracts={
  "activate": {
    "address": "0x464360",
    "description": "Ordered case-insensitive effect substring selects the name at match+7; last occurrence wins. Any whole FALSE token latches disabled and TRUE does not undo it. Apply emitter state and saved disabled-name mutation in that order, even if no emitter matches."
  },
  "set": {
    "address": "0x5a8280",
    "description": "Read current-world bank, find existing emitter, then enable or disable the found index."
  },
  "find": {
    "address": "0x658490",
    "description": "Null name returns -1. Skip reserved table index0; first matching name in requested loaded bank wins. If absent, first table match in loaded bank0 or1 wins. Signed count and null table entries preserved."
  },
  "enable": {
    "address": "0x655340",
    "description": "Index -1 no-op, otherwise write activation byte+2f=2. Direct index0 is valid."
  },
  "disable": {
    "address": "0x655320",
    "description": "Index -1 no-op, otherwise write activation byte+2f=0."
  },
  "save": {
    "address": "0x48a060",
    "description": "Twelve16-byte disabled-name slots at record+2d68. Null record/name or name length>=16 returns0. First case-insensitive match: enabling clears only first byte and returns2; disabling returns3. Missing enabled name returns0. Missing disabled name copies into first empty slot and returns1, or returns1 without write when full. Preserve slot tail bytes."
  }
};
const lines=fs.readFileSync(source.path,'utf8').split(/\r?\n/);
const mappings=[["0x464360","EffectActivation.Activate"],["0x5a8280","EffectActivation.Set"],["0x658490","EffectActivation.Find"],["0x655340","EffectActivation.Enable"],["0x655320","EffectActivation.Disable"],["0x48a060","EffectActivation.SaveDisabled"]].map(([address,name])=>({address,sourceFile:source.path,sourceSha256:source.sha256,methods:[{name,line:lines.findIndex(s=>s.includes(' '+name.split('.')[1]+'('))+1}],coverage:'whole helper on bounded attached runtime records',qualification:tests.limits.join(' '),comparisonStatus:'Original native/model differential passed; managed replay pending.',nativeEvidence:['reverse-engineering/reports/native-effect-activation-tests.json']}));
const commands=[{kind:'git-action',name:'ActivateEffect',address:'0x464360',sourceUses:277,qualification:'Existing emitter bank/state and saved disabled-name list; particle allocation and simulation remain external.'}];
const report={generatedAt:new Date().toISOString(),binarySha256:tests.binarySha256,contracts,commands,native:{cases:tests.checks,mismatches:0,fullRegionComparisons:tests.fullRegionComparisons,groups:tests.groups,authoredUses:tests.authoredUses,method:tests.method},portable:{source,harness,entrypoint:'EffectActivationVerify.Main',arguments:['reports/native-effect-activation-vectors.json','reports/native-effect-activation-csharp-validation.json'],fixtures:file('reports/native-effect-activation-vectors.json'),build:'reports/reconstructed-build.json',managedExecution:'Pending; no generated executable launched.'},limits:tests.limits};
fs.writeFileSync(root+'reports/native-effect-activation-contract.json',JSON.stringify(report,null,2)+'\n');fs.writeFileSync(root+'reports/native-effect-activation-source-map.json',JSON.stringify({binarySha256:tests.binarySha256,mappings,commands},null,2)+'\n');console.log(JSON.stringify({checks:tests.checks,mappings:mappings.length,authoredUses:tests.authoredUses}));
