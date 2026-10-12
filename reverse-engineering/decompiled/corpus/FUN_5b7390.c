/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b7390; label: FUN_005b7390
 */

void FUN_005b7390(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_24 = *param_3 - *param_2;
  local_20 = param_3[1] - param_2[1];
  local_1c = param_3[2] - param_2[2];
  FUN_005b3b30(&local_24,&local_24);
  local_18 = local_1c * param_4[1] - local_20 * param_4[2];
  local_14 = local_24 * param_4[2] - *param_4 * local_1c;
  local_10 = local_20 * *param_4 - param_4[1] * local_24;
  FUN_005b3b30(&local_18,&local_18);
  local_c = local_20 * local_10 - local_14 * local_1c;
  local_8 = local_18 * local_1c - local_24 * local_10;
  local_4 = local_24 * local_14 - local_20 * local_18;
  FUN_005b3b30(&local_c,&local_c);
  *param_1 = local_18;
  param_1[1] = local_c;
  param_1[2] = local_24;
  param_1[3] = 0.0;
  param_1[4] = local_14;
  param_1[5] = local_8;
  param_1[6] = local_20;
  param_1[7] = 0.0;
  param_1[8] = local_10;
  param_1[9] = local_4;
  param_1[10] = local_1c;
  param_1[0xb] = 0.0;
  param_1[0xc] = (-*param_2 * local_18 - param_2[1] * local_14) - param_2[2] * local_10;
  param_1[0xd] = (-*param_2 * local_c - local_8 * param_2[1]) - param_2[2] * local_4;
  param_1[0xe] = (-*param_2 * local_24 - local_20 * param_2[1]) - param_2[2] * local_1c;
  param_1[0xf] = 1.0;
  return;
}

