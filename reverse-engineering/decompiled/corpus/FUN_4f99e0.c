/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f99e0; label: FUN_004f99e0
 */

void FUN_004f99e0(int param_1)

{
  int iVar1;
  
  if (0xfff < param_1) {
    FUN_006dee70(param_1 + -0x1000,0);
    return;
  }
  if (param_1 < 0x400) {
    param_1 = param_1 + -1;
    iVar1 = FUN_004ff380(param_1);
    while (iVar1 < 0) {
      FUN_004ef790();
      iVar1 = FUN_004ff380(param_1);
    }
    if (*(undefined4 **)(&DAT_008ceb88 + param_1 * 0x40) != (undefined4 *)0x0) {
      **(undefined4 **)(&DAT_008ceb88 + param_1 * 0x40) = 0;
    }
    _memset(&DAT_008ceb50 + param_1 * 0x40,0,0x40);
    return;
  }
  FUN_004f6bc0(param_1);
  return;
}

