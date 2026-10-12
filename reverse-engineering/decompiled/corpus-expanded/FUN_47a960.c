/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47a960; label: thunk_FUN_00476360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_00476360(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
  DAT_00879584 = 0;
  DAT_00879580 = (int)*pcVar1;
  DAT_008794ec = (int)*(char *)(DAT_00879580 * 0x9c + 0x86 + DAT_00951354);
  DAT_00879b14 = 0;
  if ((DAT_0087b030 == 0) ||
     (DAT_0087950c = 1, (int)*pcVar1 != (uint)*(byte *)(DAT_0087b030 + 0x7c))) {
    DAT_0087950c = 0;
  }
  return;
}

