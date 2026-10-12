/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fe9d0; label: FUN_005fe9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

