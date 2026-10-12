/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fda20; label: FUN_005fda20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fda20(int param_1)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_20 = *(undefined4 *)(param_1 + 0x30);
  local_1c = *(undefined4 *)(param_1 + 0x34);
  local_18 = *(undefined4 *)(param_1 + 0x38);
  local_14 = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  fVar1 = *(float *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x3c) = 0x3f800000;
  FUN_005b59a0(param_1,param_1);
  FUN_006e5750(0x50,param_1,4);
  FUN_006e5750(0x59,&local_20,1);
  local_20 = *(undefined4 *)(param_1 + 0x40);
  local_1c = 0x3f800000;
  local_14 = 0;
  param_1 = param_1 + 0x44;
  local_18 = 0;
  FUN_006e5750(0x54,&local_20,1);
  FUN_005b59a0(param_1,param_1);
  FUN_006e5750(0x55,param_1,4);
  local_c = DAT_00986ea4;
  local_10 = DAT_00986ea0;
  local_8 = DAT_00986ea8;
  local_4 = DAT_00986eac;
  if (fVar1 < 1.0) {
    local_4 = fVar1 * DAT_00986eac;
    _DAT_0080e690 = 1;
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,0);
    FUN_006e5340(0x17,4);
    FUN_006e5750(0x28,&local_10,4);
    return;
  }
  FUN_005f8930();
  FUN_006e5750(0x28,&local_10,4);
  return;
}

