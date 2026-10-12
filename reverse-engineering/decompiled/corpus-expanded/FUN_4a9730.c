/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a9730; label: FUN_004a9730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a9730(int param_1)

{
  short sVar1;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    return;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x100000) != 0) {
    *(undefined2 *)(param_1 + 0x42) = 3;
    return;
  }
  sVar1 = *(short *)(param_1 + 0x1064);
  if ((((sVar1 == DAT_007f19b8) || (sVar1 == DAT_007f19bc)) || (sVar1 == DAT_007f19c0)) &&
     ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28) &&
      (**(int **)(*(int *)(param_1 + 0x50) + 0xc) != 0)))) {
    *(undefined2 *)(param_1 + 0x42) = 0;
    return;
  }
  *(undefined2 *)(param_1 + 0x42) = 1;
  return;
}

