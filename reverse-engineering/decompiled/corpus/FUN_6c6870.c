/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6870; label: FUN_006c6870
 */

undefined4 FUN_006c6870(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*param_3 < param_4) {
    *(int *)(param_2 + *param_3 * 4) = (in_ECX - DAT_02973b90) / 0x18;
    *param_3 = *param_3 + 1;
  }
  for (iVar1 = *(int *)(in_ECX + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    uVar2 = *(uint *)(iVar1 + 0x1c);
    if ((int)uVar2 < 0) {
      if ((*(uint *)(param_1 + 0x1c) & 0x400000) == 0) {
        uVar2 = uVar2 & 0x10000000;
      }
      else {
        uVar2 = uVar2 & 0x400000;
      }
      if (uVar2 == 0) {
        FUN_006c6870(param_1,param_2,param_3,param_4);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

