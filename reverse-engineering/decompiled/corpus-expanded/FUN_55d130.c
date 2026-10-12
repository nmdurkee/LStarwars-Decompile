/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55d130; label: FUN_0055d130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055d130(int param_1,float param_2,float *param_3)

{
  float fVar1;
  
  if (param_2 <= 0.0) {
    param_2 = 0.0;
  }
  fVar1 = param_2 * 0.025;
  if (*(float *)(param_1 + 0x21c) == 2e+06) {
    if (param_3 != (float *)0x0) {
      *param_3 = 2e+06;
    }
  }
  else {
    param_2 = fVar1 * (*(float *)(param_1 + 0xac) / 0.225);
    if (param_2 < fVar1) {
      param_2 = fVar1;
    }
    fVar1 = *(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c);
    if (param_3 != (float *)0x0) {
      *param_3 = fVar1;
    }
    if (fVar1 < param_2) {
      return 1;
    }
  }
  return 0;
}

