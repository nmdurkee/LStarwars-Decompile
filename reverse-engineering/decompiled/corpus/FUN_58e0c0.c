/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58e0c0; label: FUN_0058e0c0
 */

undefined4 FUN_0058e0c0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)*(char *)(param_1 + 0x7b5);
  if ((((*(uint *)(PTR_PTR_007fb0e4 + iVar1 * 0x10 + 8) & 0x10000) == 0) &&
      (((DAT_00802838 == -1 || (iVar1 != DAT_00802838)) || (*(char *)(param_1 + 0x7b8) != '\x03'))))
     && ((((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0 ||
          (DAT_00802844 == 0)) || (iVar1 != DAT_00802844)))) {
    return 0;
  }
  return 1;
}

