/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fd6b0; label: FUN_005fd6b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fd6b0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  fVar1 = *(float *)(param_1 + 0x3c);
  local_10 = DAT_00986ea0;
  fVar2 = *(float *)(param_1 + 0x2c);
  local_4 = DAT_00986eac;
  local_c = DAT_00986ea4;
  local_8 = DAT_00986ea8;
  if (fVar1 != _DAT_0080e198) {
    if (1.0 <= fVar1) {
      FUN_005f8930();
      FUN_007412e0(0x38,&local_10);
    }
    else {
      local_4 = fVar1 * DAT_00986eac;
      _DAT_0080e690 = 1;
      FUN_006e5340(7,1);
      FUN_006e5340(0xe,0);
      FUN_006e5340(0x17,4);
      FUN_007412e0(0x38,&local_10);
    }
    if (DAT_02974d1c == 4) {
      _DAT_0080e198 = fVar1;
    }
  }
  if ((float)_DAT_0080e194 != fVar2) {
    _DAT_02857148 = fVar2;
    FUN_007412e0(99,&DAT_02857148);
    _DAT_0080e194 = FUN_006e6b90();
  }
  *(undefined4 *)(param_1 + 0x3c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_007412e0(0x11,param_1);
  *(float *)(param_1 + 0x3c) = fVar1;
  *(float *)(param_1 + 0x2c) = fVar2;
  return;
}

