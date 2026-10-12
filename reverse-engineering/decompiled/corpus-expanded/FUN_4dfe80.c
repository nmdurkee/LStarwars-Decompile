/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfe80; label: FUN_004dfe80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dfe80(void)

{
  if (DAT_00951b50 == 0) {
    if (DAT_0093b2a4 != 0) {
      FUN_004897f0((int)DAT_007f1a08,0,0);
      FUN_004a4940();
      return;
    }
    if (DAT_0087b120 != 0) {
      FUN_00489820((int)DAT_007f1a08,0,0,(int)*(short *)(DAT_0087b120 + 0x62));
    }
  }
  FUN_004a4940();
  return;
}

