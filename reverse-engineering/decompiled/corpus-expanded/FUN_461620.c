/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461620; label: FUN_00461620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00461620(int param_1,undefined4 param_2,float param_3)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (1.0 <= param_3) {
      *(undefined4 *)(param_1 + 0x14) = 1;
      if (DAT_0087a190 == -1) {
        FUN_00547930(0x32,0,0,0);
        FUN_004836f0(0xffffffff,0x3f19999a,0,0);
        FUN_004838f0(param_2);
        return;
      }
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0x40400000;
    }
  }
  else {
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_00594a90((int)*(short *)((int)&DAT_0087a18c + *(int *)(param_1 + 0x14) * 2 + 2));
      FUN_00681f40("LegoClicks",0);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0x40400000;
      if (*(short *)((int)&DAT_0087a18c + *(int *)(param_1 + 0x14) * 2 + 2) == -1) {
        FUN_004838f0(param_2);
        return;
      }
    }
  }
  return;
}

