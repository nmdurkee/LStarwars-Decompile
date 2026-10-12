/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x4615c0; label: FUN_004615c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004615c0(int param_1,undefined4 param_2)

{
  short sVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  sVar1 = *(short *)((int)&DAT_0087a18c + *(int *)(param_1 + 0x14) * 2 + 2);
  while (sVar1 != -1) {
    FUN_00594a90((int)*(short *)((int)&DAT_0087a18c + *(int *)(param_1 + 0x14) * 2 + 2));
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    sVar1 = *(short *)((int)&DAT_0087a18c + *(int *)(param_1 + 0x14) * 2 + 2);
  }
  FUN_004838f0(param_2);
  FUN_004838f0(param_2);
  return;
}

