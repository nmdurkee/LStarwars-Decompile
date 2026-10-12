/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558510; label: FUN_00558510
 */

void FUN_00558510(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
  *(undefined4 *)(param_1 + 0x48) = param_2;
  return;
}

