/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b870; label: FUN_0058b870
 */

int FUN_0058b870(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0055ce20(param_1,1,1,1,0);
  if (((iVar1 == 0) || ((*(uint *)(iVar1 + 0xeec) & 0x8000000) == 0)) ||
     ((*(char *)(iVar1 + 0x28b) == '\0' && (*(char *)(iVar1 + 0x107f) != '\0')))) {
    iVar1 = 0;
  }
  return iVar1;
}

