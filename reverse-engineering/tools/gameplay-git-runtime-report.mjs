import fs from 'node:fs';
import zlib from 'node:zlib';

// This report reads the existing source catalog; it does not rewrite that catalog.
const root = 'reverse-engineering/';
const read = p => JSON.parse(fs.readFileSync(root + p));
const tests = read('reports/gameplay-git-runtime-tests.json');
if (tests.mismatches) throw Error('GIT runtime verification failed');
const graphs = read('reports/gameplay-catalog/graphs.json').graphs;
const rows = JSON.parse(zlib.gunzipSync(fs.readFileSync(root + 'reports/gameplay-native-dispatch/rows.json.gz')));
function evidence(fn, needle) {
  const file = ['corpus-expanded', 'corpus'].map(d => `${root}decompiled/${d}/FUN_${fn}.c`).find(fs.existsSync);
  if (!file) throw Error(`Missing function ${fn}`);
  const lines = fs.readFileSync(file, 'utf8').split(/\r?\n/);
  const line = lines.findIndex(s => s.includes(needle)) + 1;
  if (!line) throw Error(`Missing evidence ${fn}: ${needle}`);
  return {file, line, excerpt: lines[line - 1].trim()};
}
const nodeRef = (g, n) => ({source:g.source, line:n.line, id:n.id, kind:n.kind, name:n.name, parents:n.parents, children:n.children});
const counts = a => a.reduce((r, v) => (r[v] = (r[v] ?? 0) + 1, r), {});
const timers = [], randoms = [], conditions = [], directives = [], gizmoTypes = [];
const interesting = new Set(['monitorinputs','randomtime','startinvisible','finishedinvisible','reverse','finisheddeactive','outputonly','notstorymode','notfreeplay','revinvis']);
for (const g of graphs) {
  for (const n of g.nodes) {
    for (const giz of n.gizmos) {
      gizmoTypes.push(giz.type ?? '<missing>');
      const item = {...nodeRef(g,n), gizmo:giz};
      if (giz.type?.toLowerCase() === 'giztimer') timers.push(item);
      if (giz.type?.toLowerCase() === 'gizrandom') randoms.push(item);
    }
    for (const c of n.conditions) {
      const type = c.children.find(x => x.key?.toLowerCase() === 'type');
      conditions.push({...nodeRef(g,n), condition:c, type:type?.args[0] ?? '<missing>'});
    }
  }
  const nodes = [...g.nodes].sort((a,b) => a.line - b.line);
  fs.readFileSync(g.source,'utf8').split(/\r?\n/).forEach((text,i) => {
    const key = text.trim().split(/\s+/)[0]?.toLowerCase();
    if (interesting.has(key)) {
      const n = nodes.findLast(n => n.line <= i+1);
      directives.push({source:g.source,line:i+1,text:text.trim(),key,node:n?.id ?? null});
    }
  });
}
const action = rows.find(r => r.kind === 'git-action' && r.name.toLowerCase() === 'turnonflowbox');
if (action?.selectedBinding?.functionVa !== '0x464760') throw Error('Unexpected TurnOnFlowBox binding');
const actionUses = action.uses.map(use => {
  let target = null, enabled = true;
  for (const arg of use.args) {
    const offset = arg.toLowerCase().indexOf('name=');
    if (offset >= 0) target = arg.slice(offset+5);
    else if (arg.toLowerCase() === 'false') enabled = false;
  }
  const graph = graphs.find(g => g.source === use.source);
  return {...use, target, enabled, matchingSourceNodes:graph.nodes.filter(n => n.name?.toLowerCase() === target?.toLowerCase()).map(n => nodeRef(graph,n))};
});
const negotiations = graphs.filter(g => g.source.includes('/NEGOTIATIONS/')).map(g => ({source:g.source, nodes:g.nodes.filter(n => n.gizmos.some(x => ['giztimer','gizrandom'].includes(x.type?.toLowerCase())) || n.conditions.some(c => c.children.some(x => x.key?.toLowerCase()==='type' && x.args[0]?.toLowerCase()==='loop'))).map(n => ({...nodeRef(g,n),gizmos:n.gizmos,conditions:n.conditions}))}));
const contracts = {
  nodeLayout: {
    description:'Runtime node size is 32 bytes. Source Collapse nodes and negative source IDs are retained separately in the usage ledger; the GIT text loader and editor-collapse flattening are not emulated by these fixtures.',
    fields:{'0x00':'parent count u8','0x01':'Loop startup return-input count u8','0x02':'child count u8','0x03':'kind: gizmo 0, condition 1, action 2','0x08':'tick generation u8','0x09':'reset traversal generation u8','0x0a':'state flags u16','0x0c':'kind-specific data pointer','0x10':'parent pointer array','0x14':'child pointer array','0x18':'parent-output index byte array','0x1c':'name pointer'},
    evidence:[evidence('59f740','iVar2 = iVar2 + 0x20'),evidence('59db00','pbVar3 + 0x18')]
  },
  tick: {description:tests.contracts.tick,evidence:[evidence('59f740',"+ '\\x01'"),evidence('59f740','& 0x100'),evidence('59e090','0x802'),evidence('59e090','FUN_0059e090(param_1')]},
  activationVsOutput: {description:'Successful processing and an active gizmo output are separate. A timer activation immediately completes its flow node; downstream nodes still consult the timer output callback, which requires enabled && remaining <= 0. Each kind has its own process/output pair. This distinction is necessary to reproduce timer delays.',table:{address:'0x805518',stride:12,kinds:[{kind:0,process:'0x59f800',output:'0x59d930'},{kind:1,process:'0x59db00',output:'0x59ddd0'},{kind:2,process:'0x59f8d0',output:'0x59e080'}]},evidence:[evidence('59e090','PTR_FUN_00805518'),evidence('59f800','FUN_0055a250'),evidence('59d930','FUN_0055a1b0'),evidence('5b0470','return')]},
  initialization: {description:'Without saved graph state, initialization resolves gizmo references, clears selected runtime flags and generation, and activates ordinary nodes only when they have no parents. A Loop computes reachable return edges, stores their count in node+1, and can start active when every input is a return input. The original initializer and a Timer/Action/Loop cycle were executed for 270 frames at each of four durations, including 8-bit tick/reset generation wrap. Saved graph-state restoration is verified separately in gameplay-reconstruction.json.',evidence:[evidence('59f4e0','FUN_0059f2a0'),evidence('59f4e0','0xfedd'),evidence('59f4e0','FUN_0059da30'),evidence('59f4e0','0x801')]},
  loopThreshold: {description:'Loop is condition code 4. While state flag 0x400 is set, its required true-input count is parentCount minus startup return-input count; otherwise it requires all parents. Successful processing starts a distinct reset generation for each immediate child and recursively deactivates eligible descendant gizmos. A later successful processing with both 0x400 and 0x800 set clears 0x400.',evidence:[evidence('59db00','uVar4 - param_2[1]'),evidence('59db00','FUN_0059da60'),evidence('59e090','0x400')]},
  loopReset: {description:tests.contracts.loopReset,evidence:[evidence('59da60','param_3 != param_2'),evidence('59da60','0x1000'),evidence('59da60','FUN_0055a250'),evidence('59da60','FUN_0059da60')]},
  parentCleanup: {description:tests.contracts.parentCleanup,verification:'2,592 combinations of child flags, timer deactivation, reversal-branch presence and recursive release; timer activation callback is original PC code. This covers release barriers and timer side effects, not a real reversal/visibility callback.',evidence:[evidence('59de40','& 0xc0'),evidence('59de40','& 0x100'),evidence('59de40','FUN_0055a250'),evidence('59de40','0xffdf')]},
  monitoredCondition: {description:tests.contracts.monitor,evidence:[evidence('59ddd0','0x200'),evidence('59ddd0','PTR_FUN_00805518')]},
  monitoredGizmo: {description:'A monitored gizmo reads parent outputs and calls reversal wrapper 0x55b0e0 with reverse=1 on the first false parent, otherwise reverse=0. Node flag 0x80 also changes visibility. Original NuSpecial callbacks, static-instance visibility and exact callback order are now verified in gameplay-reconstruction.json; other physical gizmo implementations remain open.',evidence:[evidence('59df70','FUN_0055b0e0'),evidence('55b0e0','0x58'),evidence('55b0e0','FUN_0055a2b0')]},
  timer: {description:tests.contracts.timer,objectBytes:28,fields:{'0x00':'remaining float32','0x04':'configured duration float32','0x0a':'flags: enabled 1, randomized reset 2','0x0c':'name bytes'},functions:{register:'0x5b0670',update:'0x5b0400',output:'0x5b0470',activate:'0x5b04b0'},precision:'The actual instruction path includes remaining==0 in countdown updates, despite awkward decompiler floating-condition syntax. Fixed-duration cases compare exact float32 values; randomized duration comparisons use 1e-6 tolerance.',evidence:[evidence('5b0400','fVar1 == 0.0'),evidence('5b0470','return'),evidence('5b04b0','FUN_0054fa60')]},
  random: {description:tests.contracts.GizRandom,objectBytes:60,fields:{'0x00':'name bytes','0x10':'output count i32','0x14':'eight signed output weights','0x34':'selected output index or 0xffffffff','0x38':'flags, enabled 1'},rng:{address:'0x54fa60',stateAddress:'0x80253c',formula:'(state * 0x24cd + 1) & 0xffff',reciprocalAddress:'0x751700',reciprocalBinary64:1.5259021893143654e-5},precision:'The exact binary64 reciprocal is slightly below 1/65535. Replacing this x87 computation with exact real division produces a wrong top-end draw. Overlapping inclusive ranges select the first match. Zero/negative/under-total/over-total weights were also tested on bounded seeds. Deactivation clears enabled but preserves selection and RNG state.',evidence:[evidence('5b00b0','iVar5 <= 1 - iVar2'),evidence('5b00b0','0xffffffff'),evidence('54fa60','0x24cd')]},
  TurnOnFlowBox: {description:tests.contracts.TurnOnFlowBox,binding:action.selectedBinding,evidence:[evidence('464760','"name="'),evidence('464760','"FALSE"'),evidence('464760','& 1;'),evidence('59e030','(*pcVar2)(param_1')]}
};
const report = {
  generatedAt:new Date().toISOString(),binarySha256:tests.binarySha256,
  scope:'PC GIT puzzle scheduling, generation, parent cleanup, Loop resets, monitored conditions, GizTimer/GizRandom and TurnOnFlowBox. Native behavior is verified on bounded synthetic records; shipped source usage is a separate evidence layer.',
  verification:{report:root+'reports/gameplay-git-runtime-tests.json',tool:root+'tools/gameplay-git-runtime-verify.py',method:tests.method,checks:tests.checks,categories:tests.categories,mismatches:tests.mismatches},
  counts:{sourceGraphs:graphs.length,sourceNodes:graphs.reduce((n,g)=>n+g.nodes.length,0),nodeKinds:counts(graphs.flatMap(g=>g.nodes.map(n=>n.kind))),timers:timers.length,randoms:randoms.length,conditions:counts(conditions.map(c=>c.type)),directives:counts(directives.map(d=>d.key)),gizmoTypes:counts(gizmoTypes),TurnOnFlowBoxUses:actionUses.length,TurnOnFlowBoxUnmatchedSourceTargets:actionUses.filter(u=>!u.matchingSourceNodes.length).length},
  contracts,sourceUsage:{timers,randoms,conditions,directives,TurnOnFlowBox:actionUses,negotiations},
  remaining:[...tests.limits,'Source Collapse nodes and negative IDs require native loader flattening before treating the parsed editor topology as the exact runtime graph.','NuSpecial reversal/visibility and saved graph restoration are verified in gameplay-reconstruction.json; other physical gizmo implementations remain open.','Source references demonstrate use, not full reachability or successful end-to-end puzzle execution. The Negotiations examples are shipped source graphs; the verified Timer/Action/Loop fixture is synthetic.'],
  evidencePolicy:'All behavioral contracts here come from this PC binary and isolated execution or explicitly labeled PC static caller flow. Public Android/OpenSaga source is not used as proof of identical PC runtime behavior.'
};
fs.writeFileSync(root+'reports/gameplay-git-runtime-contract.json',JSON.stringify(report,null,2));
const lines = ['PC GIT PUZZLE RUNTIME CONTRACT','',`${tests.checks.toLocaleString('en-US')} original-PC checks passed; zero mismatches.`,`${report.counts.sourceGraphs} shipped source graphs: ${report.counts.timers} GizTimer instances, ${report.counts.randoms} GizRandom instances, ${report.counts.conditions.Loop ?? 0} Loop conditions, ${actionUses.length} TurnOnFlowBox commands.`,
  '',...Object.entries(contracts).flatMap(([name,c])=>[name,c.description,...c.evidence.map(e=>`  ${e.file}:${e.line} — ${e.excerpt}`),'']),
  'Concrete source examples',
  'NEGOTIATIONS_C.GIT:600 configures node 35 (GizTimer_1) for 15 seconds; source parents are node 3, children 4 and 41. Nodes 36 and 37 use Loop at lines 612 and 624. These links are catalog evidence, not a claim that the entire level has run.',
  ...actionUses.map(u=>`${u.source}:${u.line} — ${u.text}; matched source node IDs ${u.matchingSourceNodes.map(n=>n.id).join(', ')||'<none>'}.`),
  '',`All source paths, lines, directives, matching node records and source counts are in gameplay-git-runtime-contract.json.`,
  '', 'Remaining limitations',...report.remaining];
fs.writeFileSync(root+'reports/gameplay-git-runtime-contract.txt',lines.join('\n')+'\n');
console.log(JSON.stringify({checks:tests.checks,mismatches:tests.mismatches,counts:report.counts}));
