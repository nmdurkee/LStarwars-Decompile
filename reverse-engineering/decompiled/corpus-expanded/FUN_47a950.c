/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47a950; label: thunk_FUN_00475020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_00475020(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
  if ((((DAT_0087b02c != 0) && (*(byte *)(DAT_0087b02c + 0x7c) == uVar1)) ||
      ((*(ushort *)(uVar1 * 0x9c + 0x7a + DAT_00951354) & 0x1000) != 0)) ||
     (DAT_0087951c = 1, (&DAT_0086e0f5)[uVar1 * 0xc] == '\0')) {
    DAT_0087951c = 0;
  }
  DAT_00879514 = 0;
  return;
}

