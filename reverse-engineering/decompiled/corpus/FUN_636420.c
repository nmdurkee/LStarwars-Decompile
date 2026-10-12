/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x636420; label: FUN_00636420
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00636420(int param_1)

{
  undefined4 *puVar1;
  
  if (0.0 < *(float *)(param_1 + 0x140)) {
    puVar1 = (undefined4 *)(param_1 + 0x134);
    if (puVar1 != (undefined4 *)0x0) {
      _DAT_0097173c = *puVar1;
      _DAT_00971740 = *(undefined4 *)(param_1 + 0x138);
      _DAT_00971744 = *(undefined4 *)(param_1 + 0x13c);
      _DAT_00971748 = 0;
      _DAT_0097175c = 0;
      FUN_005ff840(puVar1,0);
      return;
    }
    _DAT_00971748 = 1;
    _DAT_0097175c = 0;
    FUN_005ff840(0,0);
  }
  return;
}

