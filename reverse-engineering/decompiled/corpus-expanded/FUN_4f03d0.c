/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f03d0; label: FUN_004f03d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f03d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,param_2,param_3,0);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380();
    return;
  }
  FUN_004ff3f0();
  return;
}

