/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635970; label: FUN_00635970
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_00635970(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar2 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar2 != 0) {
      bVar1 = *(byte *)(iVar2 + 0x59);
      *(byte *)(iVar2 + 0x59) = (param_2 == 0 ^ bVar1) & 1 ^ bVar1;
      return ~bVar1 & 1;
    }
  }
  return 0;
}

