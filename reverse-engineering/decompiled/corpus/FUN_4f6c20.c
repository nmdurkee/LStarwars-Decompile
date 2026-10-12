/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f6c20; label: FUN_004f6c20
 */

longlong FUN_004f6c20(int param_1)

{
  int iVar1;
  
  if (0x7ff < param_1) {
    iVar1 = (param_1 * 3 + -0x1800) * 0x10;
    return CONCAT44((*(int *)(&DAT_0297dc74 + iVar1) - *(int *)(&DAT_0297dc6c + iVar1)) -
                    (uint)(*(uint *)(&DAT_0297dc70 + iVar1) < *(uint *)(&DAT_0297dc68 + iVar1)),
                    *(uint *)(&DAT_0297dc70 + iVar1) - *(uint *)(&DAT_0297dc68 + iVar1));
  }
  return (longlong)
         (*(int *)(&DAT_02983748 + (param_1 + -0x400) * 0x14) -
         *(int *)(&DAT_02983740 + (param_1 + -0x400) * 0x14));
}

