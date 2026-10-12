/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54fd90; label: FUN_0054fd90
 */

undefined4
FUN_0054fd90(float *param_1,float *param_2,float *param_3,int param_4,float param_5,float *param_6)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_5 == 0.0) {
    local_c = *param_1;
    local_8 = param_1[1];
    local_4 = param_1[2];
  }
  else {
    FUN_005b3830(&local_c,param_3,param_5);
    FUN_005b37d0(&local_c,&local_c,param_1);
  }
  fVar1 = (local_4 - param_2[2]) * param_3[2] +
          (local_c - *param_2) * *param_3 + (local_8 - param_2[1]) * param_3[1];
  if (param_6 != (float *)0x0) {
    *param_6 = fVar1;
  }
  if (fVar1 <= 0.0) {
    if (param_4 != 0) {
      FUN_005b3830(param_4,param_3,-(fVar1 - 0.5));
      FUN_005b37d0(param_4,param_4,param_1);
      return 1;
    }
    return 1;
  }
  return 0;
}

