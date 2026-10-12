/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62f220; label: FUN_0062f220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0062f220(int param_1,int param_2)

{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    return (float10)*(float *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x38);
  }
  return (float10)0;
}

