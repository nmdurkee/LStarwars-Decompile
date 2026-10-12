/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467820; label: FUN_00467820
 */

void FUN_00467820(float *param_1,int param_2)

{
  FUN_005be2d0(*(float *)(param_2 + 0x1c) - *param_1,*(float *)(param_2 + 0x24) - param_1[2]);
  return;
}

