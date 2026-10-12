/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x482180; label: FUN_00482180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00482180(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0087a110 = PTR_s_Ledge_007598d6_2_007fa4a0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0087a110;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0087a124 = 0;
  _DAT_0087a128 = 0;
  _DAT_0087a130 = 0;
  _DAT_0087a148 = 0;
  _DAT_0087a150 = 0;
  _DAT_0087a154 = 0;
  _DAT_0087a158 = 0;
  _DAT_0087a15c = 0;
  _DAT_0087a160 = 0;
  _DAT_0087a164 = 0;
  _DAT_0087a180 = 0;
  _DAT_0087a184 = 0;
  DAT_0087a114 = &DAT_007516c0;
  _DAT_0087a118 = 0x20;
  _DAT_0087a11c = FUN_00481fb0;
  _DAT_0087a120 = FUN_00481fd0;
  _DAT_0087a12c = FUN_00481f00;
  _DAT_0087a134 = FUN_00482040;
  _DAT_0087a138 = FUN_00482050;
  _DAT_0087a13c = FUN_00482070;
  _DAT_0087a140 = FUN_00482080;
  _DAT_0087a144 = FUN_00481d90;
  _DAT_0087a14c = FUN_00481d70;
  _DAT_0087a168 = FUN_00482090;
  _DAT_0087a16c = FUN_004820b0;
  _DAT_0087a170 = FUN_004820e0;
  _DAT_0087a174 = FUN_00481db0;
  _DAT_0087a178 = FUN_00481bb0;
  _DAT_0087a17c = FUN_00481ac0;
  return &DAT_0087a110;
}

