/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x404fa0; label: FUN_00404fa0
 */

undefined4 FUN_00404fa0(int param_1)

{
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x20000000) != 0) {
    *(ushort *)(*(int *)(param_1 + 0xcc0) + 0xac) =
         (*(short *)(param_1 + 0x1064) == DAT_007f180c) + 0x32;
    if (*(char *)(*(short *)(*(int *)(param_1 + 0xcc0) + 0xac) * 0x10 + 0xe +
                 *(int *)(PTR_DAT_00802c54 + 0x2ac0)) != '\0') {
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x20000;
      *(undefined1 *)(param_1 + 0x7b3) = 0;
      *(undefined4 *)(param_1 + 0x77c) = 0;
      *(undefined1 *)(param_1 + 0x7b1) = 0;
      *(undefined1 *)(param_1 + 0x7b5) = 0x4d;
      *(undefined2 *)(param_1 + 0x7aa) = 0x90;
      *(int *)(*(int *)(param_1 + 0xcc0) + 0x84) = param_1;
      *(undefined1 *)(*(int *)(param_1 + 0xcc0) + 0x7c) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x88) = *(undefined4 *)(param_1 + 0xc5c);
      *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x8c) = *(undefined4 *)(param_1 + 0xc60);
      *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x90) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x9c) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x98) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x94) = 0;
      FUN_005655d0(*(int *)(param_1 + 0xcc0) + 0x88,*(int *)(param_1 + 0xcc0) + 0x94);
      return 1;
    }
  }
  return 0;
}

