/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x570100; label: FUN_00570100
 */

byte FUN_00570100(int param_1)

{
  if (param_1 != 0) {
    return *(byte *)(param_1 + 0x17) >> 7;
  }
  return 0;
}

