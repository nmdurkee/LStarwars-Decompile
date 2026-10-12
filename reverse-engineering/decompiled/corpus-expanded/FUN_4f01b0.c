/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f01b0; label: FUN_004f01b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f01b0(int param_1)

{
  return *(int *)(&DAT_02983744 + (param_1 + -0x400) * 0x14) -
         *(int *)(&DAT_02983740 + (param_1 + -0x400) * 0x14);
}

