/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d1e0; label: FUN_0056d1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0056d1e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00950c58 = PTR_s_GuideLine_008031c0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00950c58;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00950c6c = 0;
  _DAT_00950c70 = 0;
  _DAT_00950c78 = 0;
  _DAT_00950c90 = 0;
  _DAT_00950c98 = 0;
  _DAT_00950c9c = 0;
  _DAT_00950ca0 = 0;
  _DAT_00950ca4 = 0;
  _DAT_00950ca8 = 0;
  _DAT_00950cac = 0;
  _DAT_00950cc8 = 0;
  _DAT_00950ccc = 0;
  DAT_00950c5c = &DAT_007516c0;
  _DAT_00950c60 = 8;
  _DAT_00950c64 = FUN_0056d040;
  _DAT_00950c68 = FUN_0056d060;
  _DAT_00950c74 = FUN_0056cff0;
  _DAT_00950c7c = FUN_0056d0d0;
  _DAT_00950c80 = FUN_0056d0e0;
  _DAT_00950c84 = FUN_0056d100;
  _DAT_00950c88 = FUN_0056d110;
  _DAT_00950c8c = FUN_0056d000;
  _DAT_00950c94 = FUN_0056d020;
  _DAT_00950cb0 = FUN_0056d120;
  _DAT_00950cb4 = FUN_0056d140;
  _DAT_00950cb8 = FUN_0056d160;
  _DAT_00950cbc = FUN_0056cea0;
  _DAT_00950cc0 = FUN_0056ce30;
  _DAT_00950cc4 = FUN_0056cdb0;
  return &DAT_00950c58;
}

