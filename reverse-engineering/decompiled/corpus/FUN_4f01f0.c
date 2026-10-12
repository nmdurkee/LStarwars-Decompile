/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f01f0; label: FUN_004f01f0
 */

undefined4 FUN_004f01f0(int param_1)

{
  int iVar1;
  
  while ((param_1 < 0x400 && (0x7ff < param_1))) {
    iVar1 = (param_1 * 3 + -0x1800) * 0x10;
    param_1 = *(int *)((*(int *)(&DAT_0297dc80 + iVar1) + 3) * 0x10 +
                      *(int *)(&DAT_0297dc60 + iVar1));
  }
  return 0;
}

