/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48a310; label: FUN_0048a310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048a310(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 0x130) != 0) && (param_2 != 0)) &&
     (iVar1 = FUN_004f1ff0(param_2), iVar1 != 0)) {
    iVar1 = 0;
    iVar3 = 0;
    while (iVar2 = FUN_004f1ff0(iVar3 + 0x2824 + *(int *)(param_1 + 0x130)), iVar2 != 0) {
      iVar2 = FUN_004f8b10(iVar3 + 0x2824 + *(int *)(param_1 + 0x130),param_2);
      if (iVar2 == 0) {
        *(undefined4 *)(param_2 + 0x24) =
             *(undefined4 *)(*(int *)(param_1 + 0x130) + 0x2834 + iVar1 * 0x20);
        *(undefined4 *)(param_2 + 0x28) =
             *(undefined4 *)(*(int *)(param_1 + 0x130) + 0x2838 + iVar1 * 0x20);
        *(undefined4 *)(param_2 + 0x2c) =
             *(undefined4 *)(*(int *)(param_1 + 0x130) + 0x283c + iVar1 * 0x20);
        *(undefined4 *)(param_2 + 0x30) =
             *(undefined4 *)(*(int *)(param_1 + 0x130) + (iVar1 + 0x142) * 0x20);
        return;
      }
      iVar3 = iVar3 + 0x20;
      iVar1 = iVar1 + 1;
      if (0x3ff < iVar3) {
        return;
      }
    }
  }
  return;
}

