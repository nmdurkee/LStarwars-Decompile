/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635840; label: FUN_00635840
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635840(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (((_DAT_02913970 != 0) && (-1 < param_1)) && (param_1 < DAT_02913974)) {
    puVar1 = (undefined4 *)FUN_00547560(_DAT_02913970,param_1);
    if ((puVar1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
      *puVar1 = *param_2;
      puVar1[1] = param_2[1];
      puVar1[2] = param_2[2];
      return 1;
    }
  }
  return 0;
}

