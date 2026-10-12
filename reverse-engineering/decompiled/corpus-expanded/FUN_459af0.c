/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x459af0; label: FUN_00459af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00459af0(int param_1,int param_2)

{
  if ((((*(byte *)(param_2 + 0xb0) & 2) == 0) &&
      (DAT_0087a1a0 = DAT_0087a1a0 + DAT_0087a18c, (*(byte *)(param_2 + 0xb0) & 0x10) != 0)) &&
     ((*(int *)(param_1 + 0x14) != 6 ||
      (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) ==
       (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18)))))) {
    FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),50000,0,0);
  }
  FUN_004838f0(param_2);
  return;
}

