/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67c860; label: FUN_0067c860
 */

uint FUN_0067c860(int param_1)

{
  if (((DAT_0292fc68 != 0) && (-1 < param_1)) && (param_1 < *(int *)(DAT_0292fc68 + 0xa48c))) {
    return *(uint *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4c + param_1 * 0x6c) >> 1 & 1;
  }
  return 0;
}

