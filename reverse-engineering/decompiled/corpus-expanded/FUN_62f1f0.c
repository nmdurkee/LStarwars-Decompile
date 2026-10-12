/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62f1f0; label: FUN_0062f1f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0062f1f0(int param_1,int param_2,uint param_3)

{
  if (((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) && (param_3 < 4))
  {
    return (float10)*(float *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x28 + param_3 * 4);
  }
  return (float10)0;
}

