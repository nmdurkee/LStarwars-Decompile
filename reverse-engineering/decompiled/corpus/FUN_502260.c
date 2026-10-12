/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502260; label: FUN_00502260
 */

void FUN_00502260(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = (undefined4 *)FUN_005ce7e0(*(undefined4 *)(param_1 + 0x4c),0,param_2,0);
  bVar1 = **(byte **)(*(int *)(param_1 + 0x4c) + 0x34);
  if ((bVar1 & 1) == 0) {
    FUN_005b44e0(param_3);
  }
  else {
    local_24 = FUN_006e6b90();
    local_20 = FUN_006e6b90();
    local_1c = FUN_006e6b90();
    FUN_005b5300(param_3,&local_24);
  }
  if ((bVar1 & 8) != 0) {
    local_18 = puVar2[6];
    local_14 = puVar2[7];
    local_10 = puVar2[8];
    FUN_005b4c30(param_3,&local_18);
  }
  local_c = *puVar2;
  local_8 = puVar2[1];
  local_4 = puVar2[2];
  FUN_005b4900(param_3,&local_c);
  *(float *)(param_3 + 8) = -*(float *)(param_3 + 8);
  *(float *)(param_3 + 0x18) = -*(float *)(param_3 + 0x18);
  *(float *)(param_3 + 0x20) = -*(float *)(param_3 + 0x20);
  *(float *)(param_3 + 0x24) = -*(float *)(param_3 + 0x24);
  *(float *)(param_3 + 0x2c) = -*(float *)(param_3 + 0x2c);
  *(float *)(param_3 + 0x38) = -*(float *)(param_3 + 0x38);
  FUN_005b4900(param_3,param_1 + 0x30);
  return;
}

