/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dbb80; label: FUN_004dbb80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

