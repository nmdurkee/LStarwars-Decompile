/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x4678f0; label: FUN_004678f0
 */

undefined4 FUN_004678f0(int param_1,int param_2)

{
  if ((((param_2 != 0) && (param_1 != 0)) && (*(char *)(param_1 + 0x7b5) == '\b')) &&
     (*(int *)(param_1 + 0x10cc) == param_2)) {
    return 1;
  }
  return 0;
}

