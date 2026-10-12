/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524810; label: FUN_00524810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00524810(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  *param_3 = 0;
  iVar1 = FUN_005245c0(*(undefined4 *)(param_2 + 0xc),param_3 + 4,param_3 + 5,0);
  if (iVar1 != 0) {
    *param_3 = 1;
    return;
  }
  iVar1 = 0x30;
  do {
    if (*(int *)(iVar1 + *(int *)(param_2 + 8)) != 0) {
      iVar2 = FUN_005245c0(*(int *)(param_2 + 8),param_3 + 4,param_3 + 5,0);
      if (iVar2 != 0) {
        *param_3 = 1;
        return;
      }
    }
    if (*(int *)(iVar1 + *(int *)(param_2 + 0xc)) != 0) {
      iVar2 = FUN_005245c0(*(undefined4 *)(iVar1 + *(int *)(param_2 + 0xc)),param_3 + 4,param_3 + 5,
                           0);
      if (iVar2 != 0) {
        *param_3 = 1;
        return;
      }
    }
    iVar1 = iVar1 + 0xc;
  } while (iVar1 < 0x90);
  return;
}

