/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62d2e0; label: FUN_0062d2e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062d2e0(undefined2 *param_1)

{
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  if (*(int *)(DAT_029130e4 + 8) != 0) {
    _memset(*(void **)(param_1 + 4),0,*(int *)(DAT_029130e4 + 8) * 4);
    _memset(*(void **)(param_1 + 6),0,*(int *)(DAT_029130e4 + 8) * 4);
    _memset(*(void **)(param_1 + 8),0,*(int *)(DAT_029130e4 + 8) * 4);
  }
  _memset(param_1 + 10,0,0x40);
  return;
}

