/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635750; label: FUN_00635750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00635750(int param_1)

{
  int iVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar1 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar1 != 0) {
      FUN_005474d0(iVar1);
      _DAT_02913978 = _DAT_02913978 + -1;
    }
  }
  return;
}

