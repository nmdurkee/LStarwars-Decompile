/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa2c0; label: FUN_004aa2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004aa2c0(int param_1)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  undefined2 uVar4;
  int iVar5;
  
  bVar3 = false;
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    if (*(int *)(param_1 + 0xeac) == 0) {
      FUN_004a7c00();
      if (*(short *)(param_1 + 0x42) == 5) {
        uVar4 = FUN_004aa280(param_1);
        *(undefined2 *)(param_1 + 0x42) = uVar4;
        bVar3 = true;
      }
      else {
        cVar1 = *(char *)(param_1 + 0xe39);
        if (cVar1 == '\x01') {
          *(undefined2 *)(param_1 + 0x42) = 8;
        }
        else if (cVar1 == '\x02') {
          *(undefined2 *)(param_1 + 0x42) = 0x14;
        }
        else if (cVar1 == '\x03') {
          *(undefined2 *)(param_1 + 0x42) = 0xf;
        }
        else {
          *(undefined2 *)(param_1 + 0x42) = 1;
        }
      }
      iVar5 = FUN_00562150(param_1);
      if (iVar5 == 0) {
        if (((!bVar3) && ((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) == 0)) &&
           (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
          cVar1 = *(char *)(param_1 + 0xe39);
          if (cVar1 == '\x01') {
            *(undefined2 *)(param_1 + 0x42) = 0x1d;
          }
          else if (cVar1 == '\x02') {
            *(undefined2 *)(param_1 + 0x42) = 0x17;
          }
          else if (cVar1 == '\x03') {
            *(undefined2 *)(param_1 + 0x42) = 3;
          }
          else {
            *(undefined2 *)(param_1 + 0x42) = 0;
          }
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 5;
      }
    }
    else {
      cVar1 = *(char *)(param_1 + 0xe39);
      if (cVar1 == '\x01') {
        *(undefined2 *)(param_1 + 0x42) = 0x4c;
      }
      else if (cVar1 == '\x02') {
        *(undefined2 *)(param_1 + 0x42) = 0x4b;
      }
      else if (cVar1 == '\x03') {
        *(undefined2 *)(param_1 + 0x42) = 0x28;
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 5;
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
  }
  if (*(short *)(param_1 + 0x42) == 5) {
    cVar1 = *(char *)(param_1 + 0xe39);
    if (cVar1 == '\x01') {
      uVar4 = 0x4c;
    }
    else if (cVar1 == '\x02') {
      uVar4 = 0x4b;
    }
    else if (cVar1 == '\x03') {
      uVar4 = 0x28;
    }
    else {
      uVar4 = 5;
    }
    *(undefined2 *)(param_1 + 0x42) = uVar4;
  }
  FUN_00415370(param_1);
  sVar2 = *(short *)(param_1 + 0x42);
  if ((sVar2 != 5) &&
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) == 0 ||
      (((sVar2 != 0x28 && (sVar2 != 0x4b)) && (sVar2 != 0x4c)))))) {
    *(undefined4 *)(param_1 + 0xdac) = 0;
    return;
  }
  *(float *)(param_1 + 0xdac) = *(float *)(param_1 + 0xdac) + _DAT_00925018;
  return;
}

