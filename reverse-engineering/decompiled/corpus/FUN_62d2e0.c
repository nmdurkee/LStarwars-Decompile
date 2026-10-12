/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62d2e0; label: FUN_0062d2e0
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

