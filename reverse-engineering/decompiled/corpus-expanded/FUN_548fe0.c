/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x548fe0; label: FUN_00548fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548fe0(float *param_1)

{
  float fVar1;
  
  param_1[1] = *param_1;
  *param_1 = *param_1 + _DAT_00925018;
  fVar1 = _DAT_00925018 + param_1[2];
  param_1[2] = fVar1;
  if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
    do {
      param_1[2] = param_1[2] - 1.0;
    } while (1.0 < param_1[2] != (param_1[2] == 1.0));
  }
  if (param_1[3] != -NAN) {
    param_1[3] = (float)((int)param_1[3] + 1);
  }
  return;
}

