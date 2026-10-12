/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e6710; label: FUN_005e6710
 */

void FUN_005e6710(float *param_1,float *param_2,undefined4 param_3)

{
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_20 = *param_1 - *param_2;
  local_1c = param_1[1] - param_2[1];
  local_18 = param_1[2] - param_2[2];
  local_30 = *param_1 + *param_2;
  local_2c = param_1[1] + param_2[1];
  local_28 = param_1[2] + param_2[2];
  FUN_005c6dc0(&local_20,&local_30,param_3);
  return;
}

