/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x500d50; label: FUN_00500d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00500d50(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar1 = (undefined4 *)FUN_005ce7e0(*(undefined4 *)(param_1 + 0x50),0,param_3,0);
  if ((**(byte **)(*(int *)(param_1 + 0x50) + 0x34) & 1) == 0) {
    FUN_005b44e0(param_2);
  }
  else {
    local_18 = FUN_006e6b90();
    local_14 = FUN_006e6b90();
    local_10 = FUN_006e6b90();
    FUN_005b5300(param_2,&local_18);
  }
  local_c = *puVar1;
  local_8 = puVar1[1];
  local_4 = puVar1[2];
  FUN_005b4900(param_2,&local_c);
  *(float *)(param_2 + 8) = -*(float *)(param_2 + 8);
  *(float *)(param_2 + 0x18) = -*(float *)(param_2 + 0x18);
  *(float *)(param_2 + 0x20) = -*(float *)(param_2 + 0x20);
  *(float *)(param_2 + 0x24) = -*(float *)(param_2 + 0x24);
  *(float *)(param_2 + 0x2c) = -*(float *)(param_2 + 0x2c);
  *(float *)(param_2 + 0x38) = -*(float *)(param_2 + 0x38);
  FUN_005b4900(param_2,param_1 + 0x30);
  return puVar1;
}

