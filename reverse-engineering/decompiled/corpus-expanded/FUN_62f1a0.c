/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62f1a0; label: FUN_0062f1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0062f1a0(int param_1)

{
  if (*(char *)(param_1 + 0x31) != '\0') {
    return (int)*(short *)(param_1 + 0x34);
  }
  return (int)*(short *)(param_1 + 0x36);
}

