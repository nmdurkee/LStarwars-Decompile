/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55c600; label: FUN_0055c600
 */

void FUN_0055c600(void)

{
  FUN_00547b20(DAT_0093b0d8);
  FUN_00547ab0(DAT_0093b0d8);
  if (DAT_0093b0d8 != 0) {
    FUN_004f5120((float)*(byte *)(DAT_0093b0d8 + 0xc) / 10.0);
  }
  return;
}

