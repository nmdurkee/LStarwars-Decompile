/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x570bb0; label: FUN_00570bb0
 */

undefined4 FUN_00570bb0(void)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  if ((((DAT_00951364 == 0) || (*(int *)(iVar1 + 300) != DAT_00951364)) && (DAT_0093b2a8 == 0)) &&
     (((*(int *)(iVar1 + 300) == 0 || ((*(ushort *)(*(int *)(iVar1 + 300) + 0x7a) & 0x100) == 0)) &&
      ((*(int *)(iVar1 + 0x128) == 0 || ((*(uint *)(*(int *)(iVar1 + 0x128) + 100) & 0x400) == 0))))
     )) {
    return 0;
  }
  return 1;
}

