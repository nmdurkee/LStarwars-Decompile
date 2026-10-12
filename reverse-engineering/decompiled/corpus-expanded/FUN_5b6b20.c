/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6b20; label: FUN_005b6b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b6b20(int param_1,float *param_2)

{
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(param_1 + 0x30) - *param_2;
  local_8 = *(float *)(param_1 + 0x34) - param_2[1];
  local_4 = *(float *)(param_1 + 0x38) - param_2[2];
  FUN_005b3b30(&local_c,&local_c);
  FUN_005b6490(param_1,&local_c);
  return;
}

