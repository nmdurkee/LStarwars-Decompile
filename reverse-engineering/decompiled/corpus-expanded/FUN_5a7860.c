/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a7860; label: FUN_005a7860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005a7860(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0095dea8 = PTR_s_PushBlocks_00805b24;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095dea8;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095debc = 0;
  _DAT_0095dec4 = 0;
  _DAT_0095dec8 = 0;
  _DAT_0095dee8 = 0;
  _DAT_0095deec = 0;
  _DAT_0095def0 = 0;
  _DAT_0095def8 = 0;
  _DAT_0095defc = 0;
  _DAT_0095df18 = 0;
  _DAT_0095df1c = 0;
  DAT_0095deac = &DAT_007516c0;
  _DAT_0095deb0 = 0x24c;
  _DAT_0095deb4 = &LAB_005a7030;
  _DAT_0095deb8 = FUN_005a7050;
  _DAT_0095dec0 = FUN_005a5bd0;
  _DAT_0095decc = FUN_005a70c0;
  _DAT_0095ded0 = FUN_005a7120;
  _DAT_0095ded4 = FUN_005a7160;
  _DAT_0095ded8 = FUN_005a71b0;
  _DAT_0095dedc = FUN_005a6f40;
  _DAT_0095dee4 = FUN_005a6fc0;
  _DAT_0095def4 = FUN_005a76c0;
  _DAT_0095df00 = FUN_005a71c0;
  _DAT_0095df04 = FUN_005a71e0;
  _DAT_0095df08 = FUN_005a7210;
  _DAT_0095df0c = &LAB_005a6f20;
  _DAT_0095df10 = FUN_005a6ed0;
  _DAT_0095df14 = FUN_005a73e0;
  _DAT_0095de6c = param_1;
  return &DAT_0095dea8;
}

