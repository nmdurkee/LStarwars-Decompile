/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cf290; label: FUN_006cf290
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cf290(void)

{
  int iVar1;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_006ca3a0(&local_20,&local_24);
  if (iVar1 != 0) {
    _DAT_02973c00 = local_20;
    _DAT_02973c04 = local_1c;
    _DAT_02973c08 = local_18;
    _DAT_02973c0c = local_14;
    FUN_00620f10(&DAT_02973c00);
    FUN_00617e20();
    iVar1 = FUN_006e6b90();
    local_24 = local_24 * 1.2 *
               ((float)(&DAT_029899a0)[iVar1 + 0x4000 >> 1 & 0x7fff] /
               (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff]);
    FUN_00621040(-local_24);
  }
  return;
}

