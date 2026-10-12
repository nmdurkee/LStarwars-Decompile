/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x597250; label: FUN_00597250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00597250(int param_1)

{
  _memset(&DAT_00955b70,0,0x440);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_00955b48,"Snake_bit_1",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_00955b54,"Snake_bit_2",1);
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_00955b60,"Snake_bit_3",1);
  return;
}

