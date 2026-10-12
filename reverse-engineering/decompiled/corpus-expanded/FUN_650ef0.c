/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650ef0; label: FUN_00650ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00650ef0(int param_1)

{
  if (param_1 != -1) {
    return *(uint *)(param_1 * 0x40 + 4 + DAT_02947b74) >> 0xf & 1;
  }
  return 0xffffffff;
}

