/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49b960; label: FUN_0049b960
 */

void FUN_0049b960(int param_1)

{
  if (*(char *)(param_1 + 0x7b5) != ',') {
    FUN_0055e4a0(param_1,1);
    FUN_0055e4e0(param_1 + 0x6c4);
    *(undefined4 *)(param_1 + 0x754) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x10bc) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x758) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x10c0) = *(undefined4 *)(param_1 + 0x60);
    *(undefined1 *)(param_1 + 0x7b5) = 0x2c;
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    *(undefined4 *)(param_1 + 0x75c) = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x10c4) = *(undefined4 *)(param_1 + 100);
  }
  return;
}

