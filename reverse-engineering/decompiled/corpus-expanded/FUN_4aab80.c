/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aab80; label: FUN_004aab80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004aab80(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    return;
  }
  if ((*(char *)(param_1 + 0x7b5) != '\x1e') ||
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x14) == 0)) {
    FUN_004a7c00();
    iVar1 = FUN_00562150(param_1);
    if (iVar1 == 0) {
      if (*(short *)(param_1 + 0x42) == 5) {
        return;
      }
      if ((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) != 0) {
        return;
      }
      if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
        return;
      }
      FUN_004a85e0();
      return;
    }
  }
  *(undefined2 *)(param_1 + 0x42) = 5;
  return;
}

