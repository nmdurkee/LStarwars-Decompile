/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4a9b80; label: FUN_004a9b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9b80(int param_1)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  
  if ((*(uint *)(param_1 + 0xe20) & 0x1000000) != 0) {
    if ((((*(uint *)(param_1 + 0xe20) & 0x10000) == 0) && (*(char *)(param_1 + 0xe33) != '\x01')) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x9c) == 0)) {
      *(undefined2 *)(param_1 + 0x42) = 0xb;
    }
    else {
      *(undefined2 *)(param_1 + 0x42) = 0x27;
    }
    goto switchD_004a9d9e_caseD_2;
  }
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    goto switchD_004a9d9e_caseD_2;
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
LAB_004a9d50:
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
        if (((cVar1 == '\x1d') || (cVar1 == '\x12')) || (cVar1 == '\b')) goto LAB_004a9d50;
        if (*(short *)(param_1 + 0x42) != 5) {
          iVar4 = *(int *)(param_1 + 0xca4);
          if (((*(byte *)(iVar4 + 0x5a) & 2) != 0) || (*(float *)(iVar4 + 0x28) <= 0.0)) {
            if ((((*(byte *)(param_1 + 0xe22) & 1) != 0) || (*(char *)(param_1 + 0xe33) == '\x01'))
               && (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 100) != 0)) {
              *(undefined2 *)(param_1 + 0x42) = 0x19;
            }
          }
          else if ((*(short *)(param_1 + 0x1064) == DAT_007f18c8) ||
                  (*(short *)(param_1 + 0x1064) == DAT_007f18cc)) {
            if (((*(float *)(param_1 + 0xd3c) != 1.0) && (*(char *)(param_1 + 0xe33) != '\x01')) ||
               (uVar3 = 0x3f, *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xfc) == 0)) {
              uVar3 = 4;
            }
            *(undefined2 *)(param_1 + 0x42) = uVar3;
          }
          else {
            FUN_004a54b0(*(undefined4 *)(iVar4 + 0x28),
                         ~(*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 3) & 1);
          }
        }
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x42) = 5;
    }
  }
  if ((DAT_00955584 != (code *)0x0) && (iVar4 = (*DAT_00955584)(param_1), iVar4 != 0)) {
    switch(*(undefined2 *)(param_1 + 0x42)) {
    case 0:
      *(undefined2 *)(param_1 + 0x42) = 0x72;
      break;
    case 1:
      *(undefined2 *)(param_1 + 0x42) = 0x75;
      break;
    case 3:
      *(undefined2 *)(param_1 + 0x42) = 0x73;
      break;
    case 4:
      *(undefined2 *)(param_1 + 0x42) = 0x71;
      break;
    case 5:
      *(undefined2 *)(param_1 + 0x42) = 0x74;
    }
  }
switchD_004a9d9e_caseD_2:
  FUN_00415370(param_1);
  sVar2 = *(short *)(param_1 + 0x42);
  if ((sVar2 != 5) &&
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) == 0 ||
      (((sVar2 != 0x28 && (sVar2 != 0x4b)) && (sVar2 != 0x4c)))))) {
    *(undefined4 *)(param_1 + 0xdac) = 0;
    FUN_004a8980();
    return;
  }
  *(float *)(param_1 + 0xdac) = _DAT_00925018 + *(float *)(param_1 + 0xdac);
  FUN_004a8980();
  return;
}

