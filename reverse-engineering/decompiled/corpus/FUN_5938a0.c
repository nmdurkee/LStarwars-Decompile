/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x5938a0; label: FUN_005938a0
 */

int FUN_005938a0(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = 0;
  piVar4 = (int *)(param_1 + 0x48);
  do {
    iVar5 = 0;
    if (0 < *piVar4) {
      iVar2 = 0;
      do {
        iVar1 = FUN_004f8b10(param_2,*(undefined4 *)(iVar2 + piVar4[-9]));
        if (iVar1 == 0) {
          if (param_3 != (int *)0x0) {
            *param_3 = iVar3;
          }
          if (param_4 != (int *)0x0) {
            *param_4 = iVar5;
          }
          return *(int *)(param_1 + 0x24 + iVar3 * 4) + iVar5 * 0x28;
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x28;
      } while (iVar5 < *piVar4);
    }
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar3 < 9);
  return 0;
}

