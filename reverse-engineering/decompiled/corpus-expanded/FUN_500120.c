/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500120; label: FUN_00500120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500120(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x9c) != 0)) &&
     (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

