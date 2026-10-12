/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2300; label: FUN_005d2300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2300(int param_1)

{
  int iVar1;
  
  FUN_004f7fb0(param_1);
  iVar1 = FUN_005d1e10(*(undefined4 *)(param_1 + 0x510));
  *(int *)(&DAT_00963e50 + iVar1 * 4) = (int)*(short *)(DAT_00971580 + 0x1b4);
  return;
}

