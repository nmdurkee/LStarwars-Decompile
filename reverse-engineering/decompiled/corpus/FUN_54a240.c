/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a240; label: FUN_0054a240
 */

undefined4 FUN_0054a240(int param_1)

{
  int iVar1;
  
  if ((((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x200000) == 0) &&
      (DAT_00951288 == 0)) || (DAT_009253a4 != 0)) {
    return 0;
  }
  if (((*(char *)(param_1 + 0x280) != -1) &&
      (((((*(byte *)(param_1 + 0x1fc) & 0x80) == 0 ||
         ((iVar1 = DAT_0093d7f4, param_1 != DAT_0093d7f0 &&
          (iVar1 = DAT_0093d7f0, param_1 != DAT_0093d7f4)))) || (iVar1 == 0)) ||
       (((*(byte *)(iVar1 + 0x1fc) & 0x80) == 0 || (iVar1 = FUN_0054a1c0(), iVar1 != 0)))))) &&
     (iVar1 = FUN_0054a1c0(), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

