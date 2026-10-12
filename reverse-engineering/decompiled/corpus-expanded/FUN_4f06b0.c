/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f06b0; label: FUN_004f06b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f06b0(int param_1)

{
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,&stack0x00000008,1,0);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380(param_1,&stack0x00000008);
    return;
  }
  FUN_004ff3f0(param_1 + -1,&stack0x00000008,1);
  return;
}

