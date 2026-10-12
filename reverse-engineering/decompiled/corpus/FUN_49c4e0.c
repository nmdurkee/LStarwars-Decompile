/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49c4e0; label: FUN_0049c4e0
 */

void FUN_0049c4e0(int param_1)

{
  if ((*(int *)(param_1 + 0x790) != 0) && ((*(byte *)(param_1 + 0xe24) & 1) != 0)) {
    FUN_004364e0(*(int *)(param_1 + 0x790),2,0);
    *(undefined4 *)(param_1 + 0x790) = 0;
  }
  if ((*(char *)(param_1 + 0x7b5) == '9') || (*(char *)(param_1 + 0x7b5) == '8')) {
    *(undefined4 *)(param_1 + 0x790) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffffe;
  return;
}

