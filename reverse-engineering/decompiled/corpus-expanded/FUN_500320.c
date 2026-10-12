/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500320; label: FUN_00500320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500320(int param_1)

{
  if ((((param_1 != 0) && (*(int **)(param_1 + 0x58) != (int *)0x0)) &&
      (9 < **(int **)(param_1 + 0x58))) && (*(float *)(param_1 + 0x98) != 0.0)) {
    FUN_004fff50((float)*(ushort *)(*(int *)(param_1 + 0x5c) + 0x42),*(undefined4 *)(param_1 + 0x98)
                );
  }
  return;
}

