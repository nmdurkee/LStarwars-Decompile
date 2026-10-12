/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650da0; label: FUN_00650da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00650da0(int param_1,int param_2)

{
  return (int)*(short *)(&DAT_02921260 + ((short)(&DAT_02920d88)[param_1 * 4] + param_2) * 2);
}

