/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ede70; label: FUN_005ede70
 */

void FUN_005ede70(float *param_1,float *param_2,undefined4 param_3)

{
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  local_30 = *param_1 + *param_2;
  local_2c = param_1[1] + param_2[1];
  local_28 = param_1[2] + param_2[2];
  local_20 = *param_1 - *param_2;
  local_1c = param_1[1] - param_2[1];
  local_18 = param_1[2] - param_2[2];
  if (DAT_0097394c == 1) {
    FUN_00603cc0(&DAT_00973760);
  }
  FUN_005dc9f0(&local_20,&local_30,&DAT_00806680,param_3);
  if (DAT_0097394c == 1) {
    FUN_00603cc0(&DAT_00971b00);
  }
  return;
}

