/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf290; label: FUN_006cf290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

