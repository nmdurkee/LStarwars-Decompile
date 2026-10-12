/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa490; label: FUN_004aa490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aa490(int param_1)

{
  short sVar1;
  int iVar2;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    if (*(int *)(param_1 + 0xeac) == 0) {
      FUN_004a7c00();
      iVar2 = FUN_00562150(param_1);
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0xca4);
        if (((*(byte *)(iVar2 + 0x5a) & 2) == 0) && (0.0 < *(float *)(iVar2 + 0x28))) {
          FUN_004a54b0(*(undefined4 *)(iVar2 + 0x28),
                       ~(*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 3) & 1);
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 5;
      }
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
      if (*(int *)(iVar2 + 0xac) == 0) {
        *(ushort *)(param_1 + 0x42) = (ushort)(*(int *)(iVar2 + 0x14) != 0) * 4 + 1;
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 0x2b;
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
  }
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

