/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5ff080; label: FUN_005ff080
 */

void FUN_005ff080(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = DAT_0096d908;
  local_10 = DAT_0096d900;
  local_18 = DAT_0096d8f8;
  puVar2 = &DAT_0096d8f8;
  puVar3 = &DAT_00963e10;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_10 = local_10 >> 4;
  local_14 = DAT_0096d8fc;
  local_c = DAT_0096d904 >> 4;
  local_4 = DAT_0096d90c;
  FUN_006e57b0(&local_18);
  DAT_0095e674 = 1;
  return;
}

