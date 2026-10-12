/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x568710; label: FUN_00568710
 */

void FUN_00568710(int param_1)

{
  if (param_1 != 0) {
    if (*(short *)(param_1 + 0x102) != -1) {
      FUN_0067c930((int)*(short *)(param_1 + 0x102));
      *(undefined2 *)(param_1 + 0x102) = 0xffff;
    }
    if (*(short *)(param_1 + 0x104) != -1) {
      FUN_0067c930((int)*(short *)(param_1 + 0x104));
      *(undefined2 *)(param_1 + 0x104) = 0xffff;
    }
  }
  return;
}

