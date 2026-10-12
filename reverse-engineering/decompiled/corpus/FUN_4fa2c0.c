/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4fa2c0; label: FUN_004fa2c0
 */

void FUN_004fa2c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 < 0x400) || (0x7ff < iVar1)) {
    if ((*(char *)(param_1 + 8) == '\0') || (iVar1 == 0)) {
      iVar1 = FUN_004ef790();
    }
    FUN_004f99e0(iVar1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

