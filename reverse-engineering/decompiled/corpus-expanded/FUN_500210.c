/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500210; label: FUN_00500210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00500210(int param_1)

{
  return (*(int *)(param_1 + 0x88) << 0x13) >> 0x1f;
}

