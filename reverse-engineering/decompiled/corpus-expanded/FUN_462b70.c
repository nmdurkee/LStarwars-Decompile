/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x462b70; label: FUN_00462b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00462b70(int param_1,int param_2,float param_3)

{
  float fVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x40800000;
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    FUN_00482f10(param_2,(int)*(char *)(param_2 + 0xb8));
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_004838f0(param_2);
      return;
    }
    if ((fVar1 < 0.5) && (!NAN(param_3) && 0.5 < param_3 != (param_3 == 0.5))) {
      if (*(float *)(param_2 + 0x60) == 0.0) {
        FUN_00547930(0x32,0,0,0);
      }
      else {
        FUN_00681f40("StatusAward");
      }
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      return;
    }
  }
  return;
}

