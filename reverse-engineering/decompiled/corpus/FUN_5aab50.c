/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5aab50; label: FUN_005aab50
 */

void FUN_005aab50(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    _memset((void *)param_1[1],0,*param_1 * 0x38);
    iVar1 = 0;
    if (0 < *param_1) {
      iVar2 = 0;
      do {
        FUN_004f1310(param_1 + 2,param_1[1] + iVar2);
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x38;
      } while (iVar1 < *param_1);
    }
  }
  return;
}

