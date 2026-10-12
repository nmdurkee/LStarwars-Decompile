/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f05b0; label: FUN_004f05b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f05b0(int param_1,ushort param_2)

{
  if (DAT_0091eea0 != 0) {
    param_2 = CONCAT11((char)param_2,(char)(param_2 >> 8));
  }
  _param_2 = (uint)param_2;
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,&param_2,2,0);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380(param_1,&param_2);
    return;
  }
  FUN_004ff3f0(param_1 + -1,&param_2,2);
  return;
}

