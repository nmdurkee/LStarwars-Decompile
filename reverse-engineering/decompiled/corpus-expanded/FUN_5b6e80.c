/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6e80; label: FUN_005b6e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b6e80(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  param_2[1] = *(undefined4 *)(param_1 + 0x14);
  param_2[2] = *(undefined4 *)(param_1 + 0x18);
  return;
}

