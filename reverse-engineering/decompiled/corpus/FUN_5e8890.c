/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e8890; label: FUN_005e8890
 */

void FUN_005e8890(undefined4 param_1,float *param_2,float *param_3)

{
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_20 = *param_2 - *param_3;
  local_1c = param_2[1] - param_3[1];
  local_18 = param_2[2] - param_3[2];
  local_30 = *param_2 + *param_3;
  local_2c = param_3[1] + param_2[1];
  local_28 = param_2[2] + param_3[2];
  FUN_005c7050(&local_20,&local_30);
  return;
}

