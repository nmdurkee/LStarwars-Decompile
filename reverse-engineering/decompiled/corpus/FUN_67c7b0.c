/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67c7b0; label: FUN_0067c7b0
 */

void FUN_0067c7b0(int param_1,uint param_2)

{
  uint *puVar1;
  
  if ((-1 < param_1) && (param_1 < *(int *)(DAT_0292fc68 + 0xa48c))) {
    puVar1 = (uint *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4c + param_1 * 0x6c);
    *puVar1 = *puVar1 ^ (*(uint *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4c + param_1 * 0x6c) ^ param_2)
                        & 1;
  }
  return;
}

