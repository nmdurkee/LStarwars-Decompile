/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c6d20; label: FUN_005c6d20
 */

void FUN_005c6d20(int param_1,int param_2,undefined4 param_3)

{
  param_1 = param_2 * 0x380 + param_1;
  *(undefined4 *)(param_1 + 0x354 + *(int *)(param_1 + 0x374) * 4) = param_3;
  *(int *)(param_1 + 0x374) = *(int *)(param_1 + 0x374) + 1;
  return;
}

