"""Refresh the existing evidence-rich prioritization audit from the semantic ledger."""
import datetime, hashlib, json, pathlib, re

ROOT = pathlib.Path('reverse-engineering')
PATH = ROOT / 'reports/gameplay-next-command-priorities.json'
old = json.loads(PATH.read_text(encoding='utf-8'))
ledger_path = ROOT / 'reports/gameplay-command-semantic-coverage.json'
ledger = json.loads(ledger_path.read_text(encoding='utf-8'))
rows = ledger['rows']
by_key = {(r['kind'], r['name']): r for r in rows}
previous = {}
def gather(value):
    if isinstance(value, dict):
        if 'kind' in value and 'name' in value:
            key = value['kind'], value['name']
            if len(value) > len(previous.get(key, {})):
                previous[key] = value
        for child in value.values(): gather(child)
    elif isinstance(value, list):
        for child in value: gather(child)
gather(old)

def item(r):
    result = dict(previous.get((r['kind'], r['name']), {}))
    result.pop('rankBySourceUse', None)
    b = r.get('binding') or {}
    third = b.get('thirdWord')
    initializer = hex(third) if r['kind'] == 'scp-condition' and third and (ROOT / ('decompiled/corpus-expanded/FUN_%x.c' % third)).exists() else None
    result.update(kind=r['kind'], name=r['name'], spellings=r['spellings'], sourceUses=r['sourceUses'], status=r['status'], address=r['function'], table=b.get('table'), tableIndex=b.get('index'), tableEntryVa=b.get('tableVa'), tableThirdWord=hex(third) if third else None, initializerCandidateAddress=initializer, sourceExamples=r['uses'][:3])
    if r['function']:
        path = ROOT / ('decompiled/corpus-expanded/FUN_' + r['function'][2:] + '.c')
        result['corpusAvailable'] = path.exists()
        if path.exists():
            data = path.read_bytes(); text = data.decode('utf-8')
            result.update(corpusPath=path.as_posix(), corpusSha256=hashlib.sha256(data).hexdigest(), pseudocodeLines=len(text.splitlines()), directCalleeTokens=sorted(set(re.findall(r'FUN_[0-9a-fA-F]+', text))))
            result['directCalleeTokenCount'] = len(result['directCalleeTokens'])
    return result

remaining = sorted((r for r in rows if r['status'] != 'bounded-native-contract'), key=lambda r: -r['sourceUses'])
top = [dict(item(r), rankBySourceUse=i+1) for i,r in enumerate(remaining[:20])]
old['generatedAt'] = datetime.datetime.now(datetime.timezone.utc).isoformat()
old['auditMode'] = 'Refreshed from the semantic ledger after six compact conditions and the externally owned bounded Kill contract. No new native implementation or execution occurs in this prioritization refresh.'
old['inputs'] = [dict(file=p.as_posix(), sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in [ledger_path, ROOT/'reports/gameplay-dispatch-contract.json', ROOT/'reports/native-combat-kill.json']]
old['top20'] = top
for field in ['sameNativeHandlerClusters', 'sameSpellingDifferentHandlers', 'sharedConditionInitializerCandidates']:
    for group in old[field]:
        group['members'] = [item(by_key[(m['kind'],m['name'])]) for m in group['members']]
        group['remainingSourceUses'] = sum(m['sourceUses'] for m in group['members'] if m['status'] != 'bounded-native-contract')
old['missingNativeBindings'] = [item(r) for r in remaining if r['status'] == 'unbound-name']
batches = []
completed = old.get('completedPriorityBatches', [])
for batch in old['suggestedBatches']:
    members = [m for m in batch['members'] if by_key[(m['kind'],m['name'])]['status'] != 'bounded-native-contract']
    if not members:
        if batch['label'] not in [b['label'] for b in completed]: completed.append(batch)
        continue
    batch.update(members=members, names=len(members), sourceUses=sum(m['sourceUses'] for m in members), addresses=list(dict.fromkeys(m['address'] for m in members)))
    if batch['label'] == 'Spawn and death lifecycle':
        batch['label'] = 'Spawn lifecycle'
        batch['reason'] = 'CreateCreatures remains uncontracted. Kill has an externally owned bounded dispatch contract; downstream death and parts effects remain open.'
    batches.append(batch)
old['suggestedBatches'] = batches
old['completedPriorityBatches'] = completed
old['externalCompletedContracts'] = [dict(name='Kill', kind='scp-action', address='0x445230', sourceUses=202, report='reverse-engineering/reports/native-combat-kill.json', checks=6920, includedInGameplayCheckTotals=False, scope='Bounded selection and dispatch; world/name/reference/numeric services and parts/death effects retain explicit boundaries.')]
c = old['counts']
c.update(catalogNames=len(rows), boundedContractNames=len(rows)-len(remaining), uncontractedNames=len(remaining), uncontractedSourceUses=sum(r['sourceUses'] for r in remaining), nativeBoundButUncontractedNames=sum(r['status']=='dispatch-only' for r in remaining), missingNativeBindingNames=len(old['missingNativeBindings']), missingNativeBindingSourceUses=sum(r['sourceUses'] for r in old['missingNativeBindings']), top20SourceUses=sum(r['sourceUses'] for r in top), top20MissingBindings=sum(r['status']=='unbound-name' for r in top))
PATH.write_text(json.dumps(old, indent=2)+'\n', encoding='utf-8')
lines = ['REMAINING GAMEPLAY COMMAND PRIORITIES', '', old['auditMode'], '', json.dumps(c, sort_keys=True), '', 'TOP 20 BY SHIPPED USE COUNT']
lines += [f"{r['rankBySourceUse']:2}. {r['name']} [{r['kind']}] {r['sourceUses']} uses | {r['address']} | initializer {r.get('initializerCandidateAddress') or '-'}" for r in top]
for field, title in [('sameNativeHandlerClusters','EXACT SHARED HANDLERS'), ('sameSpellingDifferentHandlers','SAME SPELLING, DIFFERENT HANDLERS'), ('sharedConditionInitializerCandidates','SHARED CONDITION INITIALIZER CANDIDATES')]:
    lines += ['', title]
    for g in old[field]:
        lines.append(str(g.get('address') or g.get('normalizedName')) + ': ' + '; '.join(f"{m['name']} [{m['kind']}] {m['address']} {m['sourceUses']} uses ({m['status']}; init {m.get('initializerCandidateAddress') or '-'})" for m in g['members']))
lines += ['', 'SUGGESTED REMAINING BATCHES']
for b in batches: lines += [f"{b['label']}: {b['names']} names / {b['sourceUses']} uses", b['reason']]
lines += ['', 'ALL NAMES WITHOUT A NATIVE BINDING']
for r in old['missingNativeBindings']:
    e=r['sourceExamples'][0]
    lines.append(f"{r['name']} [{r['kind']}] {r['sourceUses']} uses | {e['source']}:{e['line']}")
lines += ['', 'COMPLETED SINCE ORIGINAL PRIORITIZATION', 'Six compact conditions: 1,888 uses, gameplay-compact-condition-contract.json.', 'Kill: 202 uses, 6,920 external combat comparisons; native-combat-kill.json. These checks are excluded from gameplay totals. Downstream death/parts behavior remains external.', '', 'LIMITS'] + old['limitations']
lines += ['', 'Full source references, native table addresses and retained inspection evidence are in gameplay-next-command-priorities.json.']
PATH.with_suffix('.txt').write_text('\n'.join(lines)+'\n', encoding='utf-8')
print(json.dumps(c, sort_keys=True))
