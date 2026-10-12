/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b82d0; label: FUN_005b82d0
 */

void FUN_005b82d0(float *param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = param_2[2] * param_2[2] +
          param_2[1] * param_2[1] + *param_2 * *param_2 + param_2[3] * param_2[3];
  if (0.0 < fVar1) {
    fVar2 = (float10)FUN_005c0240(fVar1);
    if ((float)fVar2 == 0.0) {
      fVar1 = 0.0;
    }
    else {
      fVar1 = 1.0 / (float)fVar2;
    }
    param_1[3] = fVar1 * param_2[3];
    *param_1 = *param_2 * fVar1;
    param_1[1] = param_2[1] * fVar1;
    param_1[2] = fVar1 * param_2[2];
    return;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}

