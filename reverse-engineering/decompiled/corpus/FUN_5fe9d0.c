/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fe9d0; label: FUN_005fe9d0
 */

void FUN_005fe9d0(float *param_1,float param_2)

{
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  local_30 = 0xffffffff;
  local_48 = *param_1 - param_2;
  local_c = 0xffffffff;
  local_44 = param_1[1];
  local_40 = param_1[2];
  local_24 = param_2 + *param_1;
  local_20 = param_1[1];
  local_1c = param_1[2];
  FUN_005dbed0(&local_48,0,0);
  local_48 = *param_1;
  local_44 = param_1[1] - param_2;
  local_40 = param_1[2];
  local_24 = *param_1;
  local_20 = param_2 + param_1[1];
  local_1c = param_1[2];
  FUN_005dbed0(&local_48,0,0);
  local_48 = *param_1;
  local_44 = param_1[1];
  local_40 = param_1[2] - param_2;
  local_24 = *param_1;
  local_20 = param_1[1];
  local_1c = param_2 + param_1[2];
  FUN_005dbed0(&local_48,0,0);
  return;
}

