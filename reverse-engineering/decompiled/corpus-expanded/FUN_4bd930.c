/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bd930; label: FUN_004bd930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004bd930(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0087ba78 = PTR_s_SecurityDoor_0075c1c3_1_007fc5a0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0087ba78;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0087ba8c = 0;
  _DAT_0087ba98 = 0;
  _DAT_0087bab0 = 0;
  _DAT_0087bab8 = 0;
  _DAT_0087bac0 = 0;
  _DAT_0087bac4 = 0;
  _DAT_0087bac8 = 0;
  _DAT_0087bacc = 0;
  _DAT_0087bae8 = 0;
  _DAT_0087baec = 0;
  DAT_0087ba7c = &DAT_007516c0;
  _DAT_0087ba80 = 0xc;
  _DAT_0087ba84 = FUN_004bd740;
  _DAT_0087ba88 = FUN_004bd760;
  _DAT_0087ba90 = FUN_004bd280;
  _DAT_0087ba94 = &LAB_004bd4a0;
  _DAT_0087ba9c = FUN_004bd7d0;
  _DAT_0087baa0 = FUN_004bd7f0;
  _DAT_0087baa4 = FUN_004bd810;
  _DAT_0087baa8 = FUN_004bd820;
  _DAT_0087baac = &LAB_004bd030;
  _DAT_0087bab4 = FUN_004bd060;
  _DAT_0087babc = FUN_004bd910;
  _DAT_0087bad0 = FUN_004bd830;
  _DAT_0087bad4 = FUN_004bd850;
  _DAT_0087bad8 = FUN_004bd870;
  _DAT_0087badc = FUN_004bd190;
  _DAT_0087bae0 = FUN_004bcfe0;
  _DAT_0087bae4 = FUN_004bcf00;
  return &DAT_0087ba78;
}

