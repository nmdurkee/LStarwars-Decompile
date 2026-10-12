/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56dea0; label: FUN_0056dea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0056dea0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00950cd0 = PTR_DAT_00803240;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00950cd0;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00950ce4 = 0;
  _DAT_00950cf0 = 0;
  _DAT_00950d10 = 0;
  _DAT_00950d18 = 0;
  _DAT_00950d1c = 0;
  _DAT_00950d20 = 0;
  _DAT_00950d24 = 0;
  _DAT_00950d40 = 0;
  _DAT_00950d44 = 0;
  DAT_00950cd4 = &DAT_007516c0;
  _DAT_00950cd8 = 8;
  _DAT_00950cdc = FUN_0056d5b0;
  _DAT_00950ce0 = FUN_0056d5d0;
  _DAT_00950ce8 = &LAB_0056db80;
  _DAT_00950cec = FUN_0056d5a0;
  _DAT_00950cf4 = FUN_0056d640;
  _DAT_00950cf8 = FUN_0056d650;
  _DAT_00950cfc = FUN_0056d670;
  _DAT_00950d00 = FUN_0056d680;
  _DAT_00950d04 = FUN_0056d430;
  _DAT_00950d08 = FUN_0056d450;
  _DAT_00950d0c = FUN_0056d4b0;
  _DAT_00950d14 = FUN_0056d750;
  _DAT_00950d28 = FUN_0056d690;
  _DAT_00950d2c = FUN_0056d6b0;
  _DAT_00950d30 = FUN_0056d6d0;
  _DAT_00950d34 = FUN_0056d4f0;
  _DAT_00950d38 = FUN_0056d3e0;
  _DAT_00950d3c = FUN_0056d340;
  return &DAT_00950cd0;
}

