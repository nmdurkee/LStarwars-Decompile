/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x5700f0; label: FUN_005700f0
 */

void FUN_005700f0(int param_1)

{
  if (param_1 != 0) {
    *(byte *)(param_1 + 0x17) = *(byte *)(param_1 + 0x17) | 0x86;
  }
  return;
}

