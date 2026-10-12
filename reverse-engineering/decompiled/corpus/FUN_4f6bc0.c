/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f6bc0; label: FUN_004f6bc0
 */

void FUN_004f6bc0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0x800) {
    (&DAT_02983750)[param_1 * 5 + -0x1400] = 0;
    return;
  }
  iVar2 = param_1 * 3 + -0x1800;
  iVar1 = iVar2 * 0x10;
  if (-1 < *(int *)(&DAT_0297dc80 + iVar1)) {
    *(undefined4 *)(*(int *)(&DAT_0297dc80 + iVar1) * 0x10 + 0x34 + *(int *)(&DAT_0297dc60 + iVar1))
         = 0xffffffff;
    (&DAT_0297dc84)[iVar2 * 4] = 0;
    return;
  }
  iVar2 = FUN_004ef790();
  *(undefined4 *)(iVar2 + 0x24) = 0;
  return;
}

