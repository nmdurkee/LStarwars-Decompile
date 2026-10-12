/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8180; label: FUN_005a8180
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

