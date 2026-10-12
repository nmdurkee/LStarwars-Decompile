/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b45b0; label: FUN_006b45b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_006b45b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = 0;
  if (0 < param_5) {
    do {
      if (*(int *)(param_4 + iVar1 * 4) != 0) {
        iVar3 = iVar3 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_5);
    if (iVar3 != 0) {
      uVar2 = FUN_006b3b50(param_2,param_3,param_5);
      return uVar2;
    }
  }
  return 0;
}

