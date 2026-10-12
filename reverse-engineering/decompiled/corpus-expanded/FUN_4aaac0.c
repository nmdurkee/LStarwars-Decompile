/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aaac0; label: FUN_004aaac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004aaac0(int param_1)

{
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    return;
  }
  *(undefined2 *)(param_1 + 0x42) = 1;
  if (((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) == 0) &&
     (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
    *(undefined2 *)(param_1 + 0x42) = 0;
  }
  return;
}

