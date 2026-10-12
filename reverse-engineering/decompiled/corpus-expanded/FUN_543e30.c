/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543e30; label: FUN_00543e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00543e30(int param_1)

{
  _sprintf((char *)&DAT_009246f8,"SaveGame%d.%s_SavedGame",param_1,PTR_s_GameTitle_0082761c);
  FUN_006e8de2(&DAT_009246f8);
  DAT_02989558 = param_1;
  if (DAT_00802014 == param_1) {
    DAT_00802014 = -1;
  }
  return;
}

