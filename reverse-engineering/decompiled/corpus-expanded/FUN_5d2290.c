/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2290; label: FUN_005d2290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2290(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004f9e70(param_1);
  iVar1 = DAT_00971580;
  *(int *)(DAT_00971580 + 0x28 + iVar2 * 4) = (int)*(short *)(DAT_00971580 + 0x1b4);
  *(uint *)(iVar1 + 0x128) = *(uint *)(iVar1 + 0x128) | 1 << ((byte)iVar2 & 0x1f);
  return;
}

