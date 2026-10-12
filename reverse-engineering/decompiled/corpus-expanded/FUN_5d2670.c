/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2670; label: FUN_005d2670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2670(void)

{
  int iVar1;
  
  iVar1 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x1ba + *(short *)(DAT_00971580 + 0x1b4) * 2) = 0x10;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  return;
}

