/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x565470; label: FUN_00565470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00565470(int param_1)

{
  float10 fVar1;
  undefined4 local_4;
  
  local_4 = 0.5625;
  if (DAT_00826494 == 2) {
    local_4 = 0.625;
  }
  if (param_1 == 0) {
    *(undefined4 *)(DAT_00925164 + 0x44) = 0x3f400000;
    if (DAT_00921359 == '\0') {
      *(undefined4 *)(DAT_00925164 + 0x40) = 0x3f400000;
    }
    else if (DAT_00921360 == 0.0) {
      *(undefined4 *)(DAT_00925164 + 0x40) = 0x3f400000;
    }
    else {
      fVar1 = (float10)FUN_005d6cc0(DAT_00921360);
      *(float *)(DAT_00925164 + 0x40) = (float)fVar1;
    }
    FUN_0050e6d0(0x3f800000,0x3f800000);
    return;
  }
  *(float *)(DAT_00925164 + 0x44) = local_4;
  if (DAT_00921359 == '\0') {
    *(float *)(DAT_00925164 + 0x40) = (local_4 + 0.75) * 0.5;
    FUN_0050e6d0(0x3f400000,0x3f800000);
    return;
  }
  if (DAT_00921360 == 0.0) {
    *(float *)(DAT_00925164 + 0x40) = local_4;
    FUN_0050e6d0(0x3f400000,0x3f800000);
    return;
  }
  fVar1 = (float10)FUN_005d6cc0(DAT_00921360);
  *(float *)(DAT_00925164 + 0x40) = (float)(((float10)local_4 / (float10)0.75) * fVar1);
  FUN_0050e6d0(0x3f400000,0x3f800000);
  return;
}

