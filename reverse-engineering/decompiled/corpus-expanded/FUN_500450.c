/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500450; label: FUN_00500450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500450(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x8c) =
       *(uint *)(param_1 + 0x8c) ^ (param_2 << 6 ^ *(uint *)(param_1 + 0x8c)) & 0x40;
  return;
}

