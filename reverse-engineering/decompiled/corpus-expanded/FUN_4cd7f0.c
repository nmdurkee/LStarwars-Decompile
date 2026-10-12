/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd7f0; label: FUN_004cd7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004cd7f0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00880590 = PTR_s_Techno_007fd1d0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00880590;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_008805b0 = 0;
  _DAT_008805c8 = 0;
  _DAT_008805d0 = 0;
  _DAT_008805d8 = 0;
  _DAT_008805dc = 0;
  _DAT_008805e0 = 0;
  _DAT_008805e4 = 0;
  _DAT_00880600 = 0;
  _DAT_00880604 = 0;
  DAT_00880594 = &DAT_007516c0;
  _DAT_00880598 = 8;
  _DAT_0088059c = FUN_004cd5c0;
  _DAT_008805a0 = FUN_004cd5e0;
  _DAT_008805a4 = FUN_004cd1e0;
  _DAT_008805a8 = FUN_004cd220;
  _DAT_008805ac = FUN_004cd2a0;
  _DAT_008805b4 = FUN_004cd650;
  _DAT_008805b8 = FUN_004cd660;
  _DAT_008805bc = FUN_004cd6f0;
  _DAT_008805c0 = FUN_004cd700;
  _DAT_008805c4 = FUN_004cd060;
  _DAT_008805cc = FUN_004cd040;
  _DAT_008805d4 = FUN_004cd7d0;
  _DAT_008805e8 = FUN_004cd710;
  _DAT_008805ec = FUN_004cd730;
  _DAT_008805f0 = FUN_004cd750;
  _DAT_008805f4 = FUN_004cd080;
  _DAT_008805f8 = &LAB_004ccf40;
  _DAT_008805fc = FUN_004cce10;
  DAT_007fd164 = param_1;
  return &DAT_00880590;
}

