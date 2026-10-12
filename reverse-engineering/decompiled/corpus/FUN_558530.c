/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558530; label: FUN_00558530
 */

void FUN_00558530(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (((*(char *)(param_1 + 0x90) != '\0') || (*(int *)(*(int *)(param_1 + 0x34) + 0xc) != 2)) ||
     ((*(uint *)(param_1 + 0x68) & 0x100) != 0)) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 8;
    *(undefined4 *)(param_1 + 0x48) = param_3;
    *(undefined4 *)(param_1 + 0x38) = param_2;
  }
  return;
}

