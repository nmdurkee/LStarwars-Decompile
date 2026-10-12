/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500a70; label: FUN_00500a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500a70(void)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x90) = *(float *)(*(int *)(in_ECX + 0x58) + 8) - 1.0;
  FUN_004fff10(*(undefined4 *)(*(int *)(in_ECX + 0x58) + 0x2c));
  return;
}

