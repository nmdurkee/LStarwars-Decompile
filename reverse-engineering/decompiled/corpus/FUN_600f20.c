/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x600f20; label: FUN_00600f20
 */

void FUN_00600f20(int param_1,int param_2)

{
  FUN_005e5140(param_1 + 0xb4);
  if (*(short *)(param_1 + 0x74) < 1) {
    *(uint *)(param_1 + 200) =
         (((int)ROUND(*(float *)(param_1 + 0x5c) * 255.0) & 0xffU | 0xffffff00) << 8 |
         (int)ROUND(*(float *)(param_1 + 0x58) * 255.0) & 0xffU) << 8 |
         (int)ROUND(*(float *)(param_1 + 0x54) * 255.0) & 0xffU;
  }
  else {
    *(int *)(param_1 + 0xb8) = (int)*(short *)(param_1 + 0x74);
    if (*(char *)(param_1 + 0x15c) == '\0') {
      *(undefined1 *)(param_1 + 0x15c) = 1;
    }
    if ((*(uint *)(param_1 + 0x1f0) & 0x3800) == 0) {
      *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xffffcfff | 0x800;
    }
  }
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) | 0x40000;
  }
  return;
}

