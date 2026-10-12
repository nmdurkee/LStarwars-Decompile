/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4a9e40; label: FUN_004a9e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9e40(int param_1)

{
  short sVar1;
  int iVar2;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    if (*(int *)(param_1 + 0xeac) == 0) {
      FUN_004a7c00();
      if (*(char *)(param_1 + 0x7b5) == '\0') {
        if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
          *(undefined2 *)(param_1 + 0x42) = 0x24;
        }
        else {
          *(undefined2 *)(param_1 + 0x42) = 0x25;
        }
      }
      else {
        iVar2 = FUN_00562150(param_1);
        if (iVar2 == 0) {
          if (((*(short *)(param_1 + 0x42) != 5) &&
              ((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) == 0)) &&
             (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
            *(undefined2 *)(param_1 + 0x42) = 0;
          }
        }
        else {
          *(undefined2 *)(param_1 + 0x42) = 5;
        }
      }
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
      if (*(int *)(iVar2 + 0xac) == 0) {
        if (*(int *)(iVar2 + 0x14) == 0) {
          *(undefined2 *)(param_1 + 0x42) = 1;
        }
        else {
          *(undefined2 *)(param_1 + 0x42) = 5;
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 0x2b;
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
  }
  FUN_00415370(param_1);
  sVar1 = *(short *)(param_1 + 0x42);
  if ((sVar1 != 5) &&
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) == 0 ||
      (((sVar1 != 0x28 && (sVar1 != 0x4b)) && (sVar1 != 0x4c)))))) {
    *(undefined4 *)(param_1 + 0xdac) = 0;
    return;
  }
  *(float *)(param_1 + 0xdac) = *(float *)(param_1 + 0xdac) + _DAT_00925018;
  return;
}

