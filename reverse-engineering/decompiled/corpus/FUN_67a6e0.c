/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67a6e0; label: FUN_0067a6e0
 */

int FUN_0067a6e0(void)

{
  if (((DAT_0292fc68 != (int *)0x0) && (DAT_02961fdc != -1)) &&
     (*(int *)(*DAT_0292fc68 + 0x2c + DAT_02961fdc * 0x38) == 1)) {
    return (int)*(short *)(*DAT_0292fc68 + DAT_02961fdc * 0x38 + 0x30);
  }
  return -1;
}

