/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635a20; label: FUN_00635a20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635a20(void)

{
  int iVar1;
  int iVar2;
  
  if (_DAT_02913970 != 0) {
    iVar1 = FUN_00547580(_DAT_02913970,0);
    while (iVar1 != 0) {
      iVar2 = FUN_00547580(_DAT_02913970,iVar1);
      FUN_005474d0(iVar1);
      iVar1 = iVar2;
    }
    _DAT_02913978 = 0;
  }
  return DAT_02913974;
}

