/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631e40; label: FUN_00631e40
 */

void FUN_00631e40(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 1;
    *(undefined4 *)(param_1 + 0x2c) = param_2;
    *(undefined4 *)(param_1 + 0x30) = param_2;
  }
  return;
}

