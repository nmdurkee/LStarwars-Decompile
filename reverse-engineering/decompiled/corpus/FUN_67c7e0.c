/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67c7e0; label: FUN_0067c7e0
 */

void FUN_0067c7e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((-1 < param_1) && (param_1 < *(int *)(DAT_0292fc68 + 0xa48c))) {
    param_1 = param_1 * 0x6c;
    if (*(float *)(*(int *)(DAT_0292fc68 + 0x68) + 0x54 + param_1) == 0.0) {
      *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + param_1 + 0x58) = 0;
      *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x5c + param_1) = 0;
    }
    *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x54 + param_1) = param_2;
    *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x60 + param_1) = param_3;
    *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 100 + param_1) = param_4;
  }
  return;
}

