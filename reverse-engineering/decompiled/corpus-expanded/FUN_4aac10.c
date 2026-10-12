/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aac10; label: FUN_004aac10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004aac10(int param_1)

{
  *(undefined2 *)(param_1 + 0x42) = 1;
  if (((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) == 0) &&
     (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
    *(undefined2 *)(param_1 + 0x42) = 0;
  }
  FUN_00415370();
  return;
}

