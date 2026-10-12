/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54f920; label: FUN_0054f920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054f920(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x30);
  param_2[1] = *(float *)(*(int *)(param_1 + 0x798) + 0x34) - *(float *)(param_1 + 0x778);
  param_2[2] = *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x38);
  return 1;
}

