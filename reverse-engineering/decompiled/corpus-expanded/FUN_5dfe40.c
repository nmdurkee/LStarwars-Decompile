/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dfe40; label: FUN_005dfe40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dfe40(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = param_2;
  iVar1 = *(int *)(param_1 + 0x18);
  *param_3 = 0x8d;
  *(int *)(param_3 + 4) = iVar1 + 0x10;
  param_3[1] = 1;
  *(undefined1 **)(param_1 + 0x14) = param_3;
  return;
}

