/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627930; label: FUN_00627930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00627930(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_02912eb8;
  if (*(int *)(param_1 + 0x24) < 0) {
    DAT_02912eb8 = 1;
    FUN_00626b50(param_1);
  }
  DAT_02912eb8 = uVar1;
  if (0x280 - param_2 < *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x24)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x14) < param_2) {
    *(int *)(param_1 + 0x14) = param_2;
  }
  if (0x1c0 - param_2 < *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x28)) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x28);
  }
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
  }
  return;
}

