/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x468710; label: FUN_00468710
 */

undefined4 FUN_00468710(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}

