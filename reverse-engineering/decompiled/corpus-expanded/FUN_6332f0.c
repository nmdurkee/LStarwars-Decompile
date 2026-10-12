/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x6332f0; label: FUN_006332f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006332f0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_00632280();
  if (iVar1 == param_2) {
    iVar1 = FUN_00632280();
    if (iVar1 == param_3) goto LAB_0063331b;
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    FUN_00632790(param_1,param_2,param_3,param_4,param_5);
    return;
  }
LAB_0063331b:
  FUN_006330f0(param_1,param_2,param_3,param_4,param_5);
  return;
}

