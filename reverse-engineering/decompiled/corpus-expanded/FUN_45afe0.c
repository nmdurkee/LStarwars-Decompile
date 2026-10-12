/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45afe0; label: FUN_0045afe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045afe0(undefined4 param_1,int param_2)

{
  FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),*(int *)(param_2 + 0x84) + *(int *)(param_2 + 0x88),0
               ,0);
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x88) = 0;
  FUN_004838f0(param_2);
  return;
}

