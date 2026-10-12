/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c6cc0; label: FUN_005c6cc0
 */

void FUN_005c6cc0(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 4) {
    *(undefined4 *)(param_1 + 0x800) = param_3;
  }
  else if (param_2 == 5) {
    *(undefined4 *)(param_1 + 0x804) = param_3;
    return;
  }
  return;
}

