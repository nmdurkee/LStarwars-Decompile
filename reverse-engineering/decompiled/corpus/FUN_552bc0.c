/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x552bc0; label: FUN_00552bc0
 */

undefined4 FUN_00552bc0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == -1) {
    return 1;
  }
  if ((param_1 == 0) && (param_1 = FUN_0055f450(), param_1 == 0)) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x2ac0) + param_2 * 0x10;
  if (*(char *)(iVar1 + 0xe) == '\0') {
    return 0;
  }
  uVar2 = FUN_005f33b0(iVar1,param_3);
  return uVar2;
}

