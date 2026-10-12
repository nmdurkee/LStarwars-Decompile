/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ebd10; label: FUN_004ebd10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ebd10(int param_1)

{
  DAT_0087a7f0 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"AI_rancor");
  DAT_0087a95c = FUN_0051acd0(*(undefined4 *)(param_1 + 0x2ae8),"Alcove_1");
  DAT_0087a960 = FUN_0051acd0(*(undefined4 *)(param_1 + 0x2ae8),"Alcove_2");
  DAT_0087a964 = FUN_0051acd0(*(undefined4 *)(param_1 + 0x2ae8),"Back_Room");
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  _DAT_00803574 = 0xa040;
  _DAT_00803538 = 0x2040;
  return;
}

