/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6ba8a0; label: FUN_006ba8a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba8a0(float *param_1,float param_2,undefined4 param_3)

{
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_2c = param_1[1];
  local_28 = param_1[2];
  local_20 = *param_1 - param_2;
  local_30 = param_2 + *param_1;
  local_1c = local_2c;
  local_18 = local_28;
  FUN_006ba7d0(&local_20,&local_30,param_3);
  local_30 = *param_1;
  local_1c = param_1[1] - param_2;
  local_2c = param_2 + param_1[1];
  local_20 = local_30;
  FUN_006ba7d0(&local_20,&local_30,param_3);
  local_2c = param_1[1];
  local_18 = param_1[2] - param_2;
  local_28 = param_2 + param_1[2];
  local_1c = local_2c;
  FUN_006ba7d0(&local_20,&local_30,param_3);
  return;
}

