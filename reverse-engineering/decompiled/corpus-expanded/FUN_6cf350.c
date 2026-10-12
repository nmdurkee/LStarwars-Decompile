/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf350; label: FUN_006cf350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

