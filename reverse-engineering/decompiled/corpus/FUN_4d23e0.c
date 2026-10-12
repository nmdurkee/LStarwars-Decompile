/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d23e0; label: FUN_004d23e0
 */

undefined4 FUN_004d23e0(int param_1)

{
  short sVar1;
  
  if ((param_1 != 0) &&
     ((((sVar1 = *(short *)(param_1 + 0x1064), sVar1 == DAT_007f1960 || (sVar1 == DAT_007f1ad4)) ||
       (sVar1 == DAT_007f1964)) || ((sVar1 == DAT_007f1adc || (sVar1 == DAT_007f1ae0)))))) {
    return 5;
  }
  return 3;
}

