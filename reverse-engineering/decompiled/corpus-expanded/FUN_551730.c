/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x551730; label: FUN_00551730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00551730(float *param_1,float *param_2,float *param_3,float param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_3 - *param_1;
  fVar2 = param_3[1] - param_1[1];
  fVar3 = param_3[2] - param_1[2];
  fVar4 = fVar2 * param_2[1] + fVar1 * *param_2 + fVar3 * param_2[2];
  if ((0.0 <= fVar4) &&
     (fVar1 = (fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2) - fVar4 * fVar4, fVar1 <= param_4)) {
    if (param_5 == (float *)0x0) {
      return 1;
    }
    *param_5 = fVar1;
    return 1;
  }
  return 0;
}

