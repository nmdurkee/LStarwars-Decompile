/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x5579d0; label: FUN_005579d0
 */

void FUN_005579d0(int param_1)

{
  if (param_1 != 0) {
    FUN_005a11b0(*(undefined4 *)(param_1 + 0x34),*(char *)(param_1 + 0x90) == '\x02');
    if (*(float *)(param_1 + 0x48) < 0.0) {
      FUN_005a1030(*(undefined4 *)(param_1 + 0x34),
                   -*(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x4c),0);
      return;
    }
    FUN_005a1030(*(undefined4 *)(param_1 + 0x34),
                 -*(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x50),0);
  }
  return;
}

