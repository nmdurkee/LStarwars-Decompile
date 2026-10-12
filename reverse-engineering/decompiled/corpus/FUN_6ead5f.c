/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6ead5f; label: FUN_006ead5f
 */

undefined * FUN_006ead5f(void)

{
  int iVar1;
  
  iVar1 = FUN_006f0395();
  if (iVar1 == 0) {
    return &DAT_00829a48;
  }
  return (undefined *)(iVar1 + 8);
}

