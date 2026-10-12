/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ee430; label: FUN_004ee430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ee430(int param_1)

{
  DAT_0087b8d4 = FUN_004ea820;
  DAT_0087aa94 = FUN_005d0690(*(undefined4 *)(param_1 + 0x13c),&DAT_0075b9a0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087aad8,"fire_cube",0);
  FUN_00553570(&DAT_0088a570,DAT_0087aa94,0,0);
  FUN_00553570(&DAT_0088a650,DAT_0087aa94,0,0);
  _DAT_0088a568 = 0;
  _DAT_0088a594 = 0x3f800000;
  return;
}

