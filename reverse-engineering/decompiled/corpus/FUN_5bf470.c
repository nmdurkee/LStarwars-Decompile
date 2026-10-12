/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5bf470; label: FUN_005bf470
 */

undefined4 FUN_005bf470(float *param_1,float *param_2,float param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005c0240((param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
                                (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +
                                (*param_1 - *param_2) * (*param_1 - *param_2));
  if ((float10)param_3 < fVar1) {
    return 0;
  }
  return 1;
}

