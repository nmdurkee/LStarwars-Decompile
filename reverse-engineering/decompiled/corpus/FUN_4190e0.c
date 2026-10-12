/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x4190e0; label: FUN_004190e0
 */

undefined4 FUN_004190e0(int param_1)

{
  int iVar1;
  
  if ((((DAT_0093b2a4 == 0) && (*(short *)(param_1 + 0x1064) == DAT_007f19cc)) &&
      (iVar1 = *(int *)(PTR_DAT_00802c54 + 300), iVar1 != 0)) &&
     ((iVar1 == DAT_0087af74 || (iVar1 == DAT_0087af7c)))) {
    return 1;
  }
  return 0;
}

