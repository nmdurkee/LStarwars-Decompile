/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0360; label: FUN_004f0360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f0360(int param_1)

{
  return *(undefined4 *)(&DAT_02983748 + (param_1 * 5 + -0x1400) * 4);
}

