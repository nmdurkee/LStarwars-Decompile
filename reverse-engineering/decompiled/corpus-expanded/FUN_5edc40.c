/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5edc40; label: FUN_005edc40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005edc40(float *param_1,float *param_2)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = -DAT_0080b708;
  local_14 = 0.0;
  local_10 = -_DAT_0080b728;
  FUN_005b3b30(&local_18,&local_18);
  *param_1 = local_18;
  param_1[1] = local_14;
  param_1[2] = local_10;
  param_1[4] = 0.0;
  param_1[5] = 1.0;
  param_1[6] = 0.0;
  local_c = -_DAT_0080b710;
  local_8 = 0.0;
  local_4 = -_DAT_0080b730;
  FUN_005b3b30(&local_c,&local_c);
  param_1[8] = local_c;
  param_1[9] = local_8;
  param_1[10] = local_4;
  param_1[0xb] = 0.0;
  param_1[7] = 0.0;
  param_1[3] = 0.0;
  param_1[0xf] = 1.0;
  param_1[0xc] = *param_2;
  param_1[0xd] = param_2[1];
  param_1[0xe] = param_2[2];
  return;
}

