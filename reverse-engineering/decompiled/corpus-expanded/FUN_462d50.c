/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x462d50; label: FUN_00462d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00462d50(undefined4 param_1,int param_2)

{
  **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x7c);
  FUN_004838f0(param_2);
  return;
}

