/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467380; label: FUN_00467380
 */

void FUN_00467380(void)

{
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    FUN_005a11b0(*(undefined4 *)(unaff_ESI + 0x28),0);
    if (*(float *)(unaff_ESI + 0x58) < 0.0) {
      FUN_005a1030(*(undefined4 *)(unaff_ESI + 0x28),
                   *(float *)(unaff_ESI + 0x60) * *(float *)(unaff_ESI + 0x58),0);
      return;
    }
    FUN_005a1030(*(undefined4 *)(unaff_ESI + 0x28),
                 *(float *)(unaff_ESI + 0x5c) * *(float *)(unaff_ESI + 0x58),0);
  }
  return;
}

