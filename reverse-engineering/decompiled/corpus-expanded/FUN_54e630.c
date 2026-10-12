/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54e630; label: FUN_0054e630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0054e630(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00927040 = PTR_s_Grapple_008024e0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00927040;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00927054 = 0;
  _DAT_00927060 = 0;
  _DAT_00927078 = 0;
  _DAT_00927080 = 0;
  _DAT_00927084 = 0;
  _DAT_00927088 = 0;
  _DAT_0092708c = 0;
  _DAT_00927090 = 0;
  _DAT_00927094 = 0;
  _DAT_009270b0 = 0;
  _DAT_009270b4 = 0;
  DAT_00927044 = &DAT_007516c0;
  _DAT_00927048 = 8;
  _DAT_0092704c = FUN_0054ded0;
  _DAT_00927050 = FUN_0054def0;
  _DAT_00927058 = FUN_0054e0c0;
  _DAT_0092705c = FUN_0054db40;
  _DAT_00927064 = FUN_0054df60;
  _DAT_00927068 = FUN_0054df70;
  _DAT_0092706c = FUN_0054dfc0;
  _DAT_00927070 = &LAB_0054dfe0;
  _DAT_00927074 = FUN_0054de80;
  _DAT_0092707c = FUN_0054deb0;
  _DAT_00927098 = FUN_0054dff0;
  _DAT_0092709c = FUN_0054e010;
  _DAT_009270a0 = FUN_0054e030;
  _DAT_009270a4 = FUN_0054d310;
  _DAT_009270a8 = FUN_0054cfb0;
  _DAT_009270ac = FUN_0054cd80;
  DAT_00802460 = param_1;
  return &DAT_00927040;
}

