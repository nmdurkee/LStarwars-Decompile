/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62f250; label: FUN_0062f250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0062f250(int param_1,int param_2)

{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    return *(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x28;
  }
  return 0;
}

