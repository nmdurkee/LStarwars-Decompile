/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54f920; label: FUN_0054f920
 */

undefined4 FUN_0054f920(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x30);
  param_2[1] = *(float *)(*(int *)(param_1 + 0x798) + 0x34) - *(float *)(param_1 + 0x778);
  param_2[2] = *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x38);
  return 1;
}

