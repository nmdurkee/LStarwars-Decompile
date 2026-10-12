/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5aafb0; label: FUN_005aafb0
 */

int * FUN_005aafb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00517160(param_1,param_2,0x18);
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    iVar2 = FUN_00517160(param_1,param_2,param_3 * 0x38);
    piVar1[1] = iVar2;
    if (iVar2 != 0) {
      *piVar1 = param_3;
      FUN_005aab50(piVar1);
    }
  }
  return piVar1;
}

