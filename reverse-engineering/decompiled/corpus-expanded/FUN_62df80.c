/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62df80; label: FUN_0062df80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0062df80(int param_1)

{
  short sVar1;
  
  if (param_1 != -1) {
    sVar1 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_1 * 2);
    if (sVar1 != -1) {
      return sVar1 * 0x54 + *(int *)(DAT_029130e4 + 0x18);
    }
  }
  return 0;
}

