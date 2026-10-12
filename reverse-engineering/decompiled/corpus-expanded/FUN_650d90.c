/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650d90; label: FUN_00650d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00650d90(int param_1)

{
  return (int)*(short *)(&DAT_02920d8a + param_1 * 8);
}

