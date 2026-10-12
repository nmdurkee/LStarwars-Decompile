/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x432f50; label: FUN_00432f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432f50(int param_1,int param_2,int param_3,int param_4,int param_5,ushort param_6,
                 ushort param_7,undefined4 param_8)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 0x400;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = 0x10;
  }
  fVar1 = *(float *)(param_4 + 0x22c) / *(float *)(*(int *)(*(int *)(param_4 + 0x54) + 0x24) + 0x1c)
  ;
  if (fVar1 < 0.25 != (fVar1 == 0.25)) {
    *(undefined4 *)(param_1 + 0x1c) = 0xc1000000;
    *(undefined4 *)(param_1 + 0x2c) = 0x90;
    *(code **)(param_1 + 0x4c) = FUN_00571c50;
    *(code **)(param_1 + 0x54) = FUN_00571c80;
    *(code **)(param_1 + 0x3c) = FUN_00571ba0;
    *(undefined4 *)(param_1 + 8) = param_8;
    FUN_0064d270(param_1);
    return;
  }
  if (param_5 == 0) {
    *(undefined4 *)(param_1 + 0x2c) = 0x111;
    *(undefined1 **)(param_1 + 0x44) = &LAB_00432a10;
    *(undefined4 *)(param_1 + 0xa4) = _DAT_00925018;
    *(undefined4 **)(param_1 + 8) = &DAT_0093b0cc;
    FUN_0064d270(param_1);
    return;
  }
  if (param_5 != 1) {
    *(undefined4 *)(param_1 + 0x20) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x2c) = 0x91;
    *(undefined1 **)(param_1 + 0x44) = &LAB_004329f0;
    *(code **)(param_1 + 0x54) = FUN_00571c80;
    *(code **)(param_1 + 0x3c) = FUN_00432a50;
    *(undefined4 *)(param_1 + 8) = param_8;
    FUN_0064d270(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0x111;
  local_c = *(float *)(param_4 + 0x68) * 0.75;
  local_4 = *(float *)(param_4 + 0x70) * 0.75;
  local_8 = local_c;
  if (param_2 == 5) {
    FUN_005b35a0(&local_c,&local_c,-(uint)param_7);
    FUN_005b3620(&local_c,&local_c,-(uint)param_6);
    *(code **)(param_1 + 0x34) = FUN_00432ef0;
  }
  else {
    FUN_005b35a0(&local_c,&local_c,(uint)param_7);
    FUN_005b3620(&local_c,&local_c,param_6);
    *(undefined1 **)(param_1 + 0x34) = &LAB_00432e20;
  }
  *(undefined4 *)(param_1 + 0xa4) = 0x40000000;
  *(undefined1 **)(param_1 + 0x44) = &LAB_004329f0;
  *(code **)(param_1 + 0x3c) = FUN_00432a50;
  *(float **)(param_1 + 8) = &local_c;
  FUN_00681f40("Tie_Spins",param_4 + 0x80);
  FUN_0064d270(param_1);
  return;
}

