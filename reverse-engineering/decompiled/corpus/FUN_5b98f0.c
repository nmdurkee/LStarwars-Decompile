/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b98f0; label: FUN_005b98f0
 */

undefined4 FUN_005b98f0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  local_8 = param_1[2] * *param_2 - *param_1 * param_2[2];
  local_4 = param_2[1] * *param_1 - *param_2 * param_1[1];
  FUN_005b3b30(&local_c,&local_c);
  *param_4 = local_c;
  param_4[1] = local_8;
  param_4[2] = local_4;
  local_c = ABS(local_c);
  local_4 = ABS(local_4);
  local_8 = ABS(local_8);
  if ((local_c < local_4 != (local_c == local_4)) && (local_8 < local_4 != (local_8 == local_4))) {
    if (0.0001 <= ABS(*param_2)) {
      fVar1 = ((param_2[3] * *param_1) / *param_2 - param_1[3]) /
              (param_1[1] - (param_2[1] * *param_1) / *param_2);
      param_3[1] = fVar1;
      *param_3 = (-param_2[3] - param_2[1] * fVar1) / *param_2;
      param_3[2] = 0.0;
      return 0;
    }
    fVar1 = ((*param_2 * param_1[3]) / *param_1 - param_2[3]) /
            (param_2[1] - (*param_2 * param_1[1]) / *param_1);
    param_3[1] = fVar1;
    *param_3 = (-param_1[3] - param_1[1] * fVar1) / *param_1;
    param_3[2] = 0.0;
    return 0;
  }
  if ((local_c <= local_8) && (local_4 <= local_8)) {
    if (0.0001 <= ABS(*param_2)) {
      fVar1 = ((param_2[3] * *param_1) / *param_2 - param_1[3]) /
              (param_1[2] - (*param_1 * param_2[2]) / *param_2);
      param_3[2] = fVar1;
      *param_3 = (-param_2[3] - param_2[2] * fVar1) / *param_2;
      param_3[1] = 0.0;
      return 0;
    }
    fVar1 = ((*param_2 * param_1[3]) / *param_1 - param_2[3]) /
            (param_2[2] - (param_1[2] * *param_2) / *param_1);
    param_3[2] = fVar1;
    *param_3 = (-param_1[3] - param_1[2] * fVar1) / *param_1;
    param_3[1] = 0.0;
    return 0;
  }
  if (0.0001 <= ABS(param_2[1])) {
    fVar1 = ((param_2[3] * param_1[1]) / param_2[1] - param_1[3]) /
            (param_1[2] - (param_1[1] * param_2[2]) / param_2[1]);
    param_3[2] = fVar1;
    param_3[1] = (-param_2[3] - param_2[2] * fVar1) / param_2[1];
    *param_3 = 0.0;
    return 0;
  }
  fVar1 = ((param_2[1] * param_1[3]) / param_1[1] - param_2[3]) /
          (param_2[2] - (param_1[2] * param_2[1]) / param_1[1]);
  param_3[2] = fVar1;
  param_3[1] = (-param_1[3] - param_1[2] * fVar1) / param_1[1];
  *param_3 = 0.0;
  return 0;
}

