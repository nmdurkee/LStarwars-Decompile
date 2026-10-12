/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dbb80; label: FUN_004dbb80
 */

float10 FUN_004dbb80(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x1064);
  if (((sVar1 == DAT_007f1a98) || (sVar1 == DAT_007f1a2c)) || (sVar1 == DAT_007f1a9c)) {
    return (float10)0.6;
  }
  if (((sVar1 != DAT_007f1a1c) && (sVar1 != DAT_007f1a24)) &&
     ((sVar1 != DAT_007f19a4 && (sVar1 != DAT_007f1a00)))) {
    return (float10)1;
  }
  return (float10)0.8;
}

