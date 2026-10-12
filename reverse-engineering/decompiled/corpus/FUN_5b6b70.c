/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b6b70; label: FUN_005b6b70
 */

void FUN_005b6b70(int param_1,float *param_2)

{
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(param_1 + 0x30) - *param_2;
  local_8 = *(float *)(param_1 + 0x34) - param_2[1];
  local_4 = *(float *)(param_1 + 0x38) - param_2[2];
  FUN_005b3b30(&local_c,&local_c);
  FUN_005b65a0(param_1,&local_c);
  return;
}

