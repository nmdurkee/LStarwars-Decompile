/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cf350; label: FUN_006cf350
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cf350(void)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_006ca2f0(&local_20);
  if (iVar1 != 0) {
    _DAT_02973c00 = local_20;
    _DAT_02973c04 = local_1c;
    _DAT_02973c08 = local_18;
    _DAT_02973c0c = local_14;
    FUN_00620f10(&DAT_02973c00);
  }
  return;
}

