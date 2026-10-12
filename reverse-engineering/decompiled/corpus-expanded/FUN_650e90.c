/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650e90; label: FUN_00650e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00650e90(int param_1)

{
  if (-1 < param_1) {
    return *(undefined4 *)(param_1 * 0x40 + DAT_02947b74);
  }
  return 0;
}

