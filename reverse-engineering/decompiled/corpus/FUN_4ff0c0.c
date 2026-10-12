/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff0c0; label: FUN_004ff0c0
 */

void FUN_004ff0c0(DWORD param_1)

{
  int iVar1;
  
  if (DAT_0091f1b4 != 0) {
    if ((DAT_00921230 == 0) && (iVar1 = FUN_00547580(DAT_0091f1b4,0), iVar1 == 0)) {
      return;
    }
    Sleep(param_1);
  }
  return;
}

