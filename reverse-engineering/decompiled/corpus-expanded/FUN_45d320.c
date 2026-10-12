/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45d320; label: FUN_0045d320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045d320(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  FUN_004838f0(param_2);
  if (*(int *)(*(int *)(param_2 + 0x124) + 0xc) == 7) {
    FUN_004838f0(param_2);
  }
  return;
}

