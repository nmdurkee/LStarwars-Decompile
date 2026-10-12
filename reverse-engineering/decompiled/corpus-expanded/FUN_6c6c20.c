/* Ghidra pseudocode, not original source.
 * ev_3e1dd6b2d4f666d2001b5d4d68499aac60c4283e1c30ebf06a77c3cfaf088012
 * Entry: 0x6c6c20; label: FUN_006c6c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c6c20(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int in_ECX;
  
  FUN_006c5f80(param_2);
  iVar1 = *(int *)(in_ECX + 0x14);
  if (iVar1 == -0x7ffffff8) {
    *(undefined4 *)(param_1 + 0x18) = *param_3;
    *(undefined4 *)(param_1 + 0x1c) = param_3[1];
    *(undefined4 *)(param_1 + 0x20) = param_3[2];
  }
  else {
    if (iVar1 == -0x7ffffff7) {
      FUN_005cfc00(param_1 + 0x18,*param_3);
      return;
    }
    if (iVar1 == -0x7ffffff6) {
      FUN_005cfcc0(param_1 + 0x18,*param_3);
      return;
    }
  }
  return;
}

