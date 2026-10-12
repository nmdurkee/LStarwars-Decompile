/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50c000; label: FUN_0050c000
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0050c000(void)

{
  if (((DAT_00921e6c != 0) && (DAT_00921e58 != 0)) && (DAT_00802014 != -1)) {
    DAT_00921de8 = 1;
    _DAT_00921d30 = 0;
    return 1;
  }
  return 0;
}

