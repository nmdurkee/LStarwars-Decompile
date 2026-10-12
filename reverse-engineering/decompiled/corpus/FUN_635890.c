/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635890; label: FUN_00635890
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635890(int param_1,float param_2,float param_3)

{
  int iVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    iVar1 = FUN_00547560(_DAT_02913970,param_1);
    if (iVar1 != 0) {
      *(float *)(iVar1 + 0x3c) = param_2;
      if (param_3 < param_2) {
        *(float *)(iVar1 + 0x40) = param_2;
        return 1;
      }
      *(float *)(iVar1 + 0x40) = param_3;
      return 1;
    }
  }
  return 0;
}

