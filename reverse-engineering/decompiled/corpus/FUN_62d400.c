/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62d400; label: FUN_0062d400
 */

undefined4 FUN_0062d400(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(DAT_029130e4 + 0x24);
  iVar3 = 0;
  if (0 < *(int *)(DAT_029130e4 + 0x2c)) {
    do {
      iVar1 = FUN_004f8b10(param_1,iVar2);
      if (iVar1 == 0) goto LAB_0062d482;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x34;
    } while (iVar3 < *(int *)(DAT_029130e4 + 0x2c));
  }
  if (*(int *)(DAT_029130e4 + 0x14) <= iVar3) {
    *(int *)(DAT_029130e4 + 0x30) = *(int *)(DAT_029130e4 + 0x30) + 1;
    return 0;
  }
  FUN_004f1f10(iVar2,param_1);
  iVar3 = FUN_005f3310(iVar2,param_3,&stack0x00000010);
  *(int *)(iVar2 + 0x30) = iVar3;
  if (iVar3 != 0) {
    if (param_2 != 0) {
      *(int *)(DAT_029130e4 + 0x28) = *(int *)(DAT_029130e4 + 0x28) + 1;
    }
    *(int *)(DAT_029130e4 + 0x2c) = *(int *)(DAT_029130e4 + 0x2c) + 1;
    *(int *)(DAT_029130e4 + 0x30) = *(int *)(DAT_029130e4 + 0x30) + 1;
  }
LAB_0062d482:
  return *(undefined4 *)(iVar2 + 0x30);
}

