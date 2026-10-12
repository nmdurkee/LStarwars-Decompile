/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c0ae0; label: FUN_004c0ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004c0ae0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0087baf8 = PTR_s_Shard_0075cd7f_1_007fcb00;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0087baf8;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0087bb18 = 0;
  _DAT_0087bb30 = 0;
  _DAT_0087bb38 = 0;
  _DAT_0087bb3c = 0;
  _DAT_0087bb40 = 0;
  _DAT_0087bb44 = 0;
  _DAT_0087bb48 = 0;
  _DAT_0087bb4c = 0;
  _DAT_0087bb68 = 0;
  _DAT_0087bb6c = 0;
  DAT_0087bafc = &DAT_007516c0;
  _DAT_0087bb00 = 0x30;
  _DAT_0087bb04 = FUN_004c08e0;
  _DAT_0087bb08 = FUN_004c0900;
  _DAT_0087bb0c = FUN_004c03f0;
  _DAT_0087bb10 = &LAB_004c0420;
  _DAT_0087bb14 = FUN_004c0740;
  _DAT_0087bb1c = FUN_004c0970;
  _DAT_0087bb20 = FUN_004c0980;
  _DAT_0087bb24 = FUN_004c09a0;
  _DAT_0087bb28 = FUN_004c09b0;
  _DAT_0087bb2c = FUN_004c03b0;
  _DAT_0087bb34 = FUN_004c03d0;
  _DAT_0087bb50 = FUN_004c09c0;
  _DAT_0087bb54 = FUN_004c09e0;
  _DAT_0087bb58 = FUN_004c0a20;
  _DAT_0087bb5c = FUN_004c02d0;
  _DAT_0087bb60 = FUN_004c01e0;
  _DAT_0087bb64 = FUN_004c0130;
  return &DAT_0087baf8;
}

