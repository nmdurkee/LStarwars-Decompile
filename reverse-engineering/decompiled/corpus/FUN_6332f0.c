/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6332f0; label: FUN_006332f0
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

