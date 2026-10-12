/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8180; label: FUN_005a8180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8180(void)

{
  if (DAT_00805b3c != 0xffffffff) {
    FUN_0068e900(DAT_00805b3c);
    FUN_0068ea00(DAT_00805b3c & 0xff);
    DAT_00805b3c = 0xffffffff;
  }
  return;
}

