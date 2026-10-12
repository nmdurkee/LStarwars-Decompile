/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9420; label: FUN_005b9420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b9420(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (((((((*param_1 - *param_3) * (param_3[1] - param_2[1]) -
           (*param_3 - *param_2) * (param_1[1] - param_3[1]) <= 0.0) &&
         (fVar1 = (param_4[1] - param_3[1]) * (*param_1 - *param_4) -
                  (*param_4 - *param_3) * (param_1[1] - param_4[1]), fVar1 < 0.0 != (fVar1 == 0.0)))
        && (fVar1 = (param_2[1] - param_4[1]) * (*param_1 - *param_2) -
                    (*param_2 - *param_4) * (param_1[1] - param_2[1]), fVar1 < 0.0 != (fVar1 == 0.0)
           )) && ((param_3[1] != param_2[1] || (*param_3 != *param_2)))) &&
      ((param_4[1] != param_2[1] || (*param_4 != *param_2)))) &&
     ((param_4[1] != param_3[1] || (*param_4 != *param_3)))) {
    return 1;
  }
  return 0;
}

