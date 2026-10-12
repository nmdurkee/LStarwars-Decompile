/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67c8e0; label: FUN_0067c8e0
 */

void FUN_0067c8e0(int param_1,int param_2)

{
  int iVar1;
  
  if (((DAT_0292fc68 != (int *)0x0) && (-1 < param_1)) && (param_1 < DAT_0292fc68[0x2923])) {
    iVar1 = (int)*(short *)(DAT_0292fc68[0x1a] + 0x48 + param_1 * 0x6c);
    if (param_2 != 0) {
      *(undefined4 *)(*DAT_0292fc68 + 0x2c + iVar1 * 0x38) = 1;
      return;
    }
    *(undefined4 *)(*DAT_0292fc68 + 0x2c + iVar1 * 0x38) = 0xffffffff;
  }
  return;
}

