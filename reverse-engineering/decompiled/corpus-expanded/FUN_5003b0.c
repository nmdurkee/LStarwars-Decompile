/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x5003b0; label: FUN_005003b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005003b0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(*(int *)(param_1 + 0x58) + 8);
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x58) + 8);
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xffffffbf;
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xfffffffd | 0x1000;
  if ((*(int *)(param_1 + 0x9c) != 0) && (-1 < *(char *)(*(int *)(param_1 + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

