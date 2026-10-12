/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a6050; label: FUN_004a6050
 */

int FUN_004a6050(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x28c) != '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    iVar2 = (int)*(char *)(iVar1 + 0xfc);
    if (((iVar2 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)) ||
       ((iVar2 = (int)*(char *)(iVar1 + 0xf8), iVar2 != -1 &&
        (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)))) {
      return iVar2 * 0x40 + 0x834 + param_1;
    }
  }
  return param_1 + 0x80;
}

