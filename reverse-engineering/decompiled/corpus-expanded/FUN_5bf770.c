/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bf770; label: FUN_005bf770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bf770(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 float *param_5)

{
  if (ABS(*param_5) <= ABS(param_5[1])) {
    if (ABS(param_5[1]) <= ABS(param_5[2])) {
      if (param_5[2] <= 0.0) {
        FUN_005b9330(param_1,param_2,param_3,param_4);
        return;
      }
      FUN_005b9420(param_1,param_2,param_3,param_4);
      return;
    }
    if (param_5[1] <= 0.0) {
      FUN_005b9600(param_1,param_2,param_3,param_4);
      return;
    }
    FUN_005b9510(param_1,param_2,param_3,param_4);
    return;
  }
  if (ABS(*param_5) <= ABS(param_5[2])) {
    if (param_5[2] <= 0.0) {
      FUN_005b9330(param_1,param_2,param_3,param_4);
      return;
    }
    FUN_005b9420(param_1,param_2,param_3,param_4);
    return;
  }
  if (*param_5 <= 0.0) {
    FUN_005b96f0(param_1,param_2,param_3,param_4);
    return;
  }
  FUN_005b97f0(param_1,param_2,param_3,param_4);
  return;
}

