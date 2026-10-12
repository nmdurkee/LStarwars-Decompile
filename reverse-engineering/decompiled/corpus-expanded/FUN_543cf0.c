/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543cf0; label: FUN_00543cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00543cf0(undefined4 param_1)

{
  _sprintf((char *)&DAT_009246f8,"SaveGame%d.%s_SavedGame",param_1,PTR_s_GameTitle_0082761c);
  FUN_006e8de2(&DAT_009246f8);
  return 1;
}

