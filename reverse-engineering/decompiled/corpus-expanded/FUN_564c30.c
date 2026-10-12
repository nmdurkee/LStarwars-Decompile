/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x564c30; label: FUN_00564c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00564c30(undefined4 param_1)

{
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [48];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_4c = *(float *)(DAT_00925164 + 0x4c) * 0.1 * 0.5;
  local_48 = local_4c;
  local_44 = local_4c;
  FUN_005b45a0(local_40,&local_4c);
  local_10 = *(undefined4 *)(DAT_00925164 + 0x30);
  local_c = *(undefined4 *)(DAT_00925164 + 0x34);
  local_8 = *(undefined4 *)(DAT_00925164 + 0x38);
  FUN_005f33b0(param_1,local_40);
  return;
}

