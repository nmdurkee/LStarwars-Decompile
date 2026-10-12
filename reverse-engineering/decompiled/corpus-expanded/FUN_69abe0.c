/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69abe0; label: FUN_0069abe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0069abe0(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  FUN_004ffaa0(DAT_02973a00);
  iVar1 = *(int *)(param_4 + 0x318);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x104) == 0)) {
    FUN_004ffac0(DAT_02973a00);
    return 0;
  }
  uVar2 = *(int *)(iVar1 + 0x108) - *(int *)(param_4 + 0x31c);
  if ((int)(param_2 * param_3) < (int)uVar2) {
    uVar2 = param_2 * param_3;
  }
  if ((int)uVar2 < 0) {
    FUN_004ffac0(DAT_02973a00);
    return 0;
  }
  FUN_004ef660(param_1,*(int *)(param_4 + 0x31c) + *(int *)(iVar1 + 0x104),uVar2);
  *(int *)(param_4 + 0x31c) = *(int *)(param_4 + 0x31c) + uVar2;
  FUN_004ffac0(DAT_02973a00);
  return uVar2 / param_2;
}

