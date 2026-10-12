/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500400; label: FUN_00500400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500400(int param_1)

{
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffff7ff;
  return;
}

