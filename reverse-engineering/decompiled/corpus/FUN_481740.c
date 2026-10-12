/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x481740; label: FUN_00481740
 */

void FUN_00481740(int param_1)

{
  *(undefined4 *)(param_1 + 0x4bc) = 0x20000000;
  if ((*(uint *)(param_1 + 0x1f8) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x1f8) & 4) == 0) {
      *(undefined4 *)(param_1 + 0x4bc) = 0x20000100;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x4bc) = 0x20000200;
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x18) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 3;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x200000) == 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 4;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x100000) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 8;
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f17d0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x400;
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x334) != 0) {
    *(uint *)(param_1 + 0x4bc) = *(uint *)(param_1 + 0x4bc) | 0x10;
  }
  return;
}

