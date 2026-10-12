/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467470; label: FUN_00467470
 */

void FUN_00467470(int param_1)

{
  if (param_1 != 0) {
    if ((*(byte *)(param_1 + 0xa0) & 0x40) != 0) {
      FUN_00467380();
      return;
    }
    FUN_004673e0();
  }
  return;
}

