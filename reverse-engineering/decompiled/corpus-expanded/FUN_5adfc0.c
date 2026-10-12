/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5adfc0; label: FUN_005adfc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005adfc0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0095dff8 = PTR_s_GizTurret_00763dfb_1_00805ea4;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095dff8;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095e00c = 0;
  _DAT_0095e018 = 0;
  _DAT_0095e038 = 0;
  _DAT_0095e040 = 0;
  DAT_0095dffc = &DAT_007516c0;
  _DAT_0095e000 = 0x70;
  _DAT_0095e004 = FUN_005ad250;
  _DAT_0095e008 = FUN_005ad270;
  _DAT_0095e010 = FUN_005ac080;
  _DAT_0095e014 = FUN_005ad1d0;
  _DAT_0095e01c = FUN_005ad2d0;
  _DAT_0095e020 = FUN_005ad2f0;
  _DAT_0095e024 = FUN_005ad340;
  _DAT_0095e028 = FUN_005ad390;
  _DAT_0095e02c = FUN_005ab900;
  _DAT_0095e030 = FUN_005ab950;
  _DAT_0095e034 = FUN_005ab9f0;
  _DAT_0095e03c = &LAB_005aba30;
  _DAT_0095e044 = &LAB_005ad7e0;
  _DAT_0095e048 = FUN_005ad8e0;
  _DAT_0095e04c = FUN_005adc90;
  _DAT_0095e050 = FUN_005ad3a0;
  _DAT_0095e054 = FUN_005ad3c0;
  _DAT_0095e058 = FUN_005ad460;
  _DAT_0095e05c = FUN_005abc00;
  _DAT_0095e060 = FUN_005ab840;
  _DAT_0095e064 = FUN_005ab3d0;
  _DAT_0095e068 = FUN_005ab730;
  _DAT_0095e06c = FUN_005ab790;
  DAT_00805e24 = param_1;
  return &DAT_0095dff8;
}

