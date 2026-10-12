/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa670; label: FUN_004aa670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aa670(int param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    if (*(int *)(param_1 + 0xeac) == 0) {
      FUN_004a7c00();
      iVar4 = FUN_00562150(param_1);
      if (iVar4 == 0) {
        if (*(short *)(param_1 + 0x42) != 5) {
          iVar4 = *(int *)(param_1 + 0xca4);
          if (((*(byte *)(iVar4 + 0x5a) & 2) != 0) || (*(float *)(iVar4 + 0x28) <= 0.0)) {
            if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 100) != 0) &&
               (fVar1 = *(float *)(param_1 + 0xd3c), !NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5)))
            {
              *(undefined2 *)(param_1 + 0x42) = 0x19;
            }
          }
          else {
            iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
            if ((*(float *)(iVar3 + 0x1c) + *(float *)(iVar3 + 0x18)) * 0.5 <
                *(float *)(iVar4 + 0x28)) {
              if (((*(byte *)(param_1 + 0xe22) & 1) != 0) || (0.0 < *(float *)(param_1 + 0xd3c))) {
                *(undefined2 *)(param_1 + 0x42) = 0x17;
              }
              else {
                *(undefined2 *)(param_1 + 0x42) = 3;
              }
            }
            else if (((*(byte *)(param_1 + 0xe22) & 1) != 0) || (0.0 < *(float *)(param_1 + 0xd3c)))
            {
              *(undefined2 *)(param_1 + 0x42) = 0x40;
            }
            else {
              *(undefined2 *)(param_1 + 0x42) = 0;
            }
          }
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 5;
      }
    }
    else {
      iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
      if (*(int *)(iVar4 + 0xac) == 0) {
        if (*(int *)(iVar4 + 0x14) == 0) {
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
  sVar2 = *(short *)(param_1 + 0x42);
  if ((sVar2 != 5) &&
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) == 0 ||
      (((sVar2 != 0x28 && (sVar2 != 0x4b)) && (sVar2 != 0x4c)))))) {
    *(undefined4 *)(param_1 + 0xdac) = 0;
    return;
  }
  *(float *)(param_1 + 0xdac) = _DAT_00925018 + *(float *)(param_1 + 0xdac);
  return;
}

