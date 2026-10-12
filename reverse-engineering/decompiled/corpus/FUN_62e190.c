/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62e190; label: FUN_0062e190
 */

int FUN_0062e190(int param_1,undefined2 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = 0;
  if (param_1 != 0) {
    uVar3 = 1;
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 4) + 400) <= iVar2) {
        return iVar1;
      }
      if ((param_3 & uVar3) != 0) {
        *param_2 = (short)iVar2;
        param_2 = param_2 + 1;
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
      uVar3 = uVar3 * 2;
    } while (iVar2 < 0x20);
  }
  return iVar1;
}

