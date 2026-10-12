/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e23e0; label: FUN_004e23e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e23e0(int param_1)

{
  _DAT_0095df36 = FUN_005806f0("trooper_green",param_1);
  _DAT_0095df34 = FUN_005806f0("trooper_red",param_1);
  DAT_0095df3c = 0;
  DAT_0095df3d = 0;
  DAT_0095df3e = 0;
  DAT_0095df3f = 0;
  DAT_0095df40 = 0;
  DAT_0095df41 = 1;
  DAT_0095df42 = 1;
  DAT_0095df43 = 1;
  DAT_0095df44 = 1;
  DAT_0095df45 = 1;
  FUN_005a8dd0(param_1,10,0x20,0);
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"power_a11");
  DAT_0087a970 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"power_b11");
  DAT_0087a974 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"power_a21");
  _DAT_0087a978 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"power_b21");
  return;
}

