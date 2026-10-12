/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fdb60; label: FUN_005fdb60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fdb60(int param_1)

{
  float fVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_02974d1c == 4) {
    FUN_007412e0(0x23,param_1);
  }
  else {
    FUN_007412e0(1,param_1);
    FUN_007412e0(6,param_1 + 0x40);
    FUN_007412e0(7,param_1 + 0x50);
    FUN_007412e0(8,param_1 + 0x60);
    FUN_007412e0(3,param_1 + 0x10);
    FUN_007412e0(4,param_1 + 0x20);
    FUN_007412e0(5,param_1 + 0x30);
    FUN_007412e0(0x49,param_1 + 0x70);
  }
  if (DAT_02974d1c != 4) {
    FUN_005b3dc0(&local_10,param_1 + 0x40,param_1 + 0x50);
    FUN_005b3dc0(&local_10,&local_10,param_1 + 0x60);
    FUN_005b3b30(&local_10,&local_10);
    FUN_007412e0(0x4c,&local_10);
    if (*(float *)(param_1 + 0x20) <= *(float *)(param_1 + 0x30)) {
      fVar1 = *(float *)(param_1 + 0x30);
    }
    else {
      fVar1 = *(float *)(param_1 + 0x20);
    }
    if (*(float *)(param_1 + 0x10) <= fVar1) {
      if (*(float *)(param_1 + 0x20) <= *(float *)(param_1 + 0x30)) {
        local_10 = *(undefined4 *)(param_1 + 0x30);
      }
      else {
        local_10 = *(undefined4 *)(param_1 + 0x20);
      }
    }
    else {
      local_10 = *(undefined4 *)(param_1 + 0x10);
    }
    if (*(float *)(param_1 + 0x24) <= *(float *)(param_1 + 0x34)) {
      fVar1 = *(float *)(param_1 + 0x34);
    }
    else {
      fVar1 = *(float *)(param_1 + 0x24);
    }
    if (*(float *)(param_1 + 0x14) <= fVar1) {
      if (*(float *)(param_1 + 0x24) <= *(float *)(param_1 + 0x34)) {
        local_c = *(undefined4 *)(param_1 + 0x34);
      }
      else {
        local_c = *(undefined4 *)(param_1 + 0x24);
      }
    }
    else {
      local_c = *(undefined4 *)(param_1 + 0x14);
    }
    if (*(float *)(param_1 + 0x28) <= *(float *)(param_1 + 0x38)) {
      fVar1 = *(float *)(param_1 + 0x38);
    }
    else {
      fVar1 = *(float *)(param_1 + 0x28);
    }
    if (*(float *)(param_1 + 0x18) <= fVar1) {
      if (*(float *)(param_1 + 0x28) <= *(float *)(param_1 + 0x38)) {
        local_8 = *(undefined4 *)(param_1 + 0x38);
      }
      else {
        local_8 = *(undefined4 *)(param_1 + 0x28);
      }
    }
    else {
      local_8 = *(undefined4 *)(param_1 + 0x18);
    }
    local_4 = 0x3f800000;
    FUN_007412e0(0x4b,&local_10);
  }
  return;
}

