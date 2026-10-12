/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b8f40; label: FUN_005b8f40
 */

void FUN_005b8f40(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float local_c;
  float local_8;
  float local_4;
  
  local_c = (param_3[1] - param_2[1]) * (param_4[2] - param_2[2]) -
            (param_3[2] - param_2[2]) * (param_4[1] - param_2[1]);
  local_8 = (*param_4 - *param_2) * (param_3[2] - param_2[2]) -
            (*param_3 - *param_2) * (param_4[2] - param_2[2]);
  local_4 = (param_4[1] - param_2[1]) * (*param_3 - *param_2) -
            (param_3[1] - param_2[1]) * (*param_4 - *param_2);
  FUN_005b3b30(param_1,&local_c);
  param_1[3] = -(param_1[2] * param_2[2] + *param_1 * *param_2 + param_1[1] * param_2[1]);
  return;
}

