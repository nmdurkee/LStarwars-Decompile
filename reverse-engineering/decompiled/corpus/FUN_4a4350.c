/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a4350; label: FUN_004a4350
 */

undefined4 FUN_004a4350(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x7b5) == '\x1c') {
    if (*(char *)(param_1 + 0x7b8) != '\0') {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x790);
    if (iVar2 == 0) {
      return 0;
    }
    if (*(char *)(iVar2 + 0x7b5) != '\x1b') {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0xe20) & 0x300) != 0) {
      return 0;
    }
    if ((char)*(uint *)(iVar2 + 0xe20) < '\0') {
      return 0;
    }
    sVar1 = *(short *)(param_2 + 0x1064);
    param_2 = param_1;
  }
  else {
    if (*(char *)(param_2 + 0x7b5) != '\x1c') {
      return 0;
    }
    if (*(char *)(param_2 + 0x7b8) != '\0') {
      return 0;
    }
    iVar2 = *(int *)(param_2 + 0x790);
    if (iVar2 == 0) {
      return 0;
    }
    if (*(char *)(iVar2 + 0x7b5) != '\x1b') {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0xe20) & 0x300) != 0) {
      return 0;
    }
    if ((char)*(uint *)(iVar2 + 0xe20) < '\0') {
      return 0;
    }
    sVar1 = *(short *)(param_1 + 0x1064);
  }
  if ((sVar1 != DAT_007f1a50) && (iVar2 = FUN_004a3b60(param_2,iVar2), iVar2 != 0)) {
    return 1;
  }
  return 0;
}

