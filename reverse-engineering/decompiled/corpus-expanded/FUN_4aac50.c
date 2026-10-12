/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aac50; label: FUN_004aac50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004aac50(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    *(undefined2 *)(param_1 + 0x42) = 1;
    if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x3c) != 0)) {
      *(undefined2 *)(param_1 + 0x42) = 0xf;
    }
    if (((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) == 0) &&
       (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
      *(undefined2 *)(param_1 + 0x42) = 0;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
  }
  if (*(short *)(param_1 + 0x42) == 1) {
    iVar1 = FUN_00550040(*(undefined2 *)(param_1 + 0x1060),*(undefined2 *)(param_1 + 0x27a));
    if ((iVar1 < 0) && (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x98) != 0)) {
      *(undefined2 *)(param_1 + 0x42) = 0x26;
      return;
    }
    if ((0 < iVar1) && (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x13c) != 0)) {
      *(undefined2 *)(param_1 + 0x42) = 0x4f;
    }
  }
  return;
}

