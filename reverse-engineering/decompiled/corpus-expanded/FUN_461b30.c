/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461b30; label: FUN_00461b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00461b30(int param_1,undefined4 param_2,float param_3)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
  }
  else if (*(int *)(param_1 + 0x14) == 1) {
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_004838f0(param_2);
      return;
    }
  }
  return;
}

