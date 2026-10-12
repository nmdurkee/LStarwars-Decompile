/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c84c0; label: FUN_004c84c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004c84c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_008804d0 = PTR_s_Signal_007fcd00;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_008804d0;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_008804e4 = 0;
  _DAT_008804f0 = 0;
  _DAT_00880510 = 0;
  _DAT_00880518 = 0;
  _DAT_0088051c = 0;
  _DAT_00880520 = 0;
  _DAT_00880524 = 0;
  _DAT_00880540 = 0;
  _DAT_00880544 = 0;
  DAT_008804d4 = &DAT_007516c0;
  _DAT_008804d8 = 0x28;
  _DAT_008804dc = FUN_004c82c0;
  _DAT_008804e0 = FUN_004c82e0;
  _DAT_008804e8 = FUN_004c7d30;
  _DAT_008804ec = FUN_004c8030;
  _DAT_008804f4 = FUN_004c8350;
  _DAT_008804f8 = FUN_004c8360;
  _DAT_008804fc = FUN_004c8380;
  _DAT_00880500 = FUN_004c8390;
  _DAT_00880504 = &LAB_004c7a20;
  _DAT_00880508 = FUN_004c7a40;
  _DAT_0088050c = &LAB_004c7ae0;
  _DAT_00880514 = FUN_004c7b00;
  _DAT_00880528 = FUN_004c83a0;
  _DAT_0088052c = FUN_004c83c0;
  _DAT_00880530 = FUN_004c83f0;
  _DAT_00880534 = FUN_004c7c60;
  _DAT_00880538 = FUN_004c79d0;
  _DAT_0088053c = FUN_004c78b0;
  return &DAT_008804d0;
}

