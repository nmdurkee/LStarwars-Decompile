/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4a9940; label: FUN_004a9940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9940(int param_1)

{
  char cVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    goto LAB_004a9af6;
  }
  FUN_004a7c00();
  if (*(char *)(param_1 + 0x7b5) == '\0') {
    FUN_004a7360();
  }
  else {
    iVar4 = FUN_00562150(param_1);
    if (iVar4 == 0) {
      cVar1 = *(char *)(param_1 + 0x7b5);
      if (cVar1 == '\x1b') {
        if (((char)*(uint *)(param_1 + 0xe20) < '\0') || ((*(uint *)(param_1 + 0xe20) & 0x500) != 0)
           ) {
LAB_004a9a93:
          if ((((*(byte *)(param_1 + 0xe22) & 1) == 0) && (*(char *)(param_1 + 0xe33) != '\x01')) ||
             (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x9c) == 0)) {
            *(undefined2 *)(param_1 + 0x42) = 0xb;
          }
          else {
            *(undefined2 *)(param_1 + 0x42) = 0x27;
          }
        }
        else {
          *(ushort *)(param_1 + 0x42) =
               (-(ushort)(*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x9c) != 0) & 0x1c) +
               0xb;
        }
      }
      else {
        if (((cVar1 == '\x1d') || (cVar1 == '\x12')) || (cVar1 == '\b')) goto LAB_004a9a93;
        if (*(short *)(param_1 + 0x42) != 5) {
          iVar4 = *(int *)(param_1 + 0xca4);
          if (((*(byte *)(iVar4 + 0x5a) & 2) != 0) || (*(float *)(iVar4 + 0x28) <= 0.0)) {
            if (((*(byte *)(param_1 + 0xe22) & 1) != 0) || (*(char *)(param_1 + 0xe33) == '\x01')) {
              if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\0') &&
                 ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) != 0)) {
                if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x1d8) != 0) {
                  *(undefined2 *)(param_1 + 0x42) = 0x76;
                }
              }
              else if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 100) != 0) {
                *(undefined2 *)(param_1 + 0x42) = 0x19;
              }
            }
          }
          else {
            FUN_004a54b0(*(undefined4 *)(iVar4 + 0x28),1);
          }
        }
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x42) = 5;
    }
  }
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\0') &&
     ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) != 0)) {
    if (*(short *)(param_1 + 0x42) == 0x17) {
      *(undefined2 *)(param_1 + 0x42) = 0x73;
    }
    else if (*(short *)(param_1 + 0x42) == 0x40) {
      *(undefined2 *)(param_1 + 0x42) = 0x72;
    }
  }
LAB_004a9af6:
  FUN_00415370(param_1);
  sVar2 = *(short *)(param_1 + 0x42);
  if ((sVar2 == 5) ||
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) != 0 &&
      (((sVar2 == 0x28 || (sVar2 == 0x4b)) || (sVar2 == 0x4c)))))) {
    fVar3 = *(float *)(param_1 + 0xdac) + _DAT_00925018;
  }
  else {
    fVar3 = 0.0;
  }
  *(float *)(param_1 + 0xdac) = fVar3;
  sVar2 = *(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xec);
  if (((sVar2 != 0x65) && (sVar2 != 0x67)) && ((sVar2 != 0x69 && (sVar2 != 0x6b)))) {
    return;
  }
  FUN_004a8980();
  return;
}

