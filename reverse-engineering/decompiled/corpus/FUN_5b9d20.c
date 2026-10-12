/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b9d20; label: FUN_005b9d20
 */

void FUN_005b9d20(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (param_4 == (float *)0x0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = *param_4;
  }
  param_1[2] = fVar1;
  fVar1 = param_2[2];
  *param_1 = *param_2 + ((param_1[2] - fVar1) * *param_3) / param_3[2];
  param_1[1] = ((param_1[2] - fVar1) * param_3[1]) / param_3[2] + param_2[1];
  return;
}

