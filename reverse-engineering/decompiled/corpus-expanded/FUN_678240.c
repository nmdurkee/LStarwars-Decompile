/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x678240; label: FUN_00678240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00678240(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = -param_2[2] * param_1[2] + -*param_2 * *param_1 + -param_2[1] * param_1[1];
  fVar2 = (float10)FUN_005c0240(param_2[2] * param_2[2] +
                                *param_2 * *param_2 + param_2[1] * param_2[1]);
  *param_3 = *param_2 + fVar1 * *param_1 * 2.0;
  param_3[1] = param_1[1] * fVar1 * 2.0 + param_2[1];
  fVar1 = fVar1 * param_1[2] * 2.0 + param_2[2];
  param_3[2] = fVar1;
  fVar3 = (float10)FUN_005c0240(*param_3 * *param_3 + param_3[1] * param_3[1] + fVar1 * fVar1);
  if ((float)fVar3 != 0.0) {
    fVar1 = (float)fVar2 / (float)fVar3;
    *param_3 = fVar1 * *param_3;
    param_3[1] = param_3[1] * fVar1;
    param_3[2] = fVar1 * param_3[2];
    return;
  }
  return;
}

