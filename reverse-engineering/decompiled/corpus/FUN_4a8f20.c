/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a8f20; label: FUN_004a8f20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8f20(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  
  if ((*(short *)(param_1 + 0x1064) == DAT_007f1958) &&
     (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94)) {
    *(undefined2 *)(param_1 + 0x42) = 1;
    if ((*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) ||
       (**(int **)(*(int *)(param_1 + 0x50) + 0xc) == 0)) {
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x3c) != 0) && (0.0 < _DAT_00879550))
      {
        *(undefined2 *)(param_1 + 0x42) = 0xf;
        return;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x42) = 0;
    }
    return;
  }
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    if (*(int *)(param_1 + 0xeac) == 0) {
      if (*(char *)(param_1 + 0x7b5) == '\b') {
        *(undefined2 *)(param_1 + 0x42) = 0xb;
      }
      else {
        FUN_004a7c00();
        if (*(char *)(param_1 + 0x7b5) == '\0') {
          FUN_004a7360();
        }
        else {
          iVar3 = FUN_00562150(param_1);
          if (iVar3 == 0) {
            if ((*(char *)(param_1 + 0x7b5) == -1) && (*(char *)(param_1 + 0xe32) == '\x01')) {
              if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
                *(undefined2 *)(param_1 + 0x42) = 0xf;
              }
              else {
                *(undefined2 *)(param_1 + 0x42) = 0x25;
              }
            }
            else if (*(short *)(param_1 + 0x42) != 5) {
              iVar3 = *(int *)(param_1 + 0xca4);
              if (((*(byte *)(iVar3 + 0x5a) & 2) != 0) || (*(float *)(iVar3 + 0x28) <= 0.0)) {
                if ((((*(byte *)(param_1 + 0xe22) & 1) != 0) ||
                    (*(char *)(param_1 + 0xe33) == '\x01')) &&
                   (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 100) != 0)) {
                  *(undefined2 *)(param_1 + 0x42) = 0x19;
                }
              }
              else {
                if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) &&
                   (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\x01')) {
                  uVar5 = 0;
                }
                else {
                  uVar5 = ~(*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 3) & 1;
                }
                FUN_004a54b0(*(undefined4 *)(iVar3 + 0x28),uVar5);
              }
            }
          }
          else {
            *(undefined2 *)(param_1 + 0x42) = 5;
          }
        }
      }
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
      if (*(int *)(iVar3 + 0xac) == 0) {
        *(ushort *)(param_1 + 0x42) = (ushort)(*(int *)(iVar3 + 0x14) != 0) * 4 + 1;
      }
      else {
        *(undefined2 *)(param_1 + 0x42) = 0x2b;
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) ||
     ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802280) == 0)) goto LAB_004a9174;
  sVar2 = *(short *)(param_1 + 0x1064);
  if (sVar2 == DAT_007f1884) {
    bVar4 = *(short *)(param_1 + 0x42) == 0x19;
  }
  else {
    if (sVar2 == DAT_007f1868) {
      if (*(short *)(param_1 + 0x42) == 1) {
        *(undefined2 *)(param_1 + 0x42) = 0x60;
      }
      goto LAB_004a9174;
    }
    if ((sVar2 != DAT_007f1a8c) && (sVar2 != DAT_007f1a90)) goto LAB_004a9174;
    bVar4 = *(short *)(param_1 + 0x42) == 1;
  }
  if (bVar4) {
    *(undefined2 *)(param_1 + 0x42) = 0xf;
  }
LAB_004a9174:
  FUN_00415370(param_1);
  sVar2 = *(short *)(param_1 + 0x42);
  if ((sVar2 == 5) ||
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) != 0 &&
      (((sVar2 == 0x28 || (sVar2 == 0x4b)) || (sVar2 == 0x4c)))))) {
    *(float *)(param_1 + 0xdac) = *(float *)(param_1 + 0xdac) + _DAT_00925018;
  }
  else {
    *(undefined4 *)(param_1 + 0xdac) = 0;
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f17c8) {
    iVar3 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_007f17cc * 2);
    if (iVar3 != -1) {
      if ((sVar2 == -1) ||
         (*(int *)(*(int *)(*(int *)(DAT_029130e4 + 0x18) + 0xc + iVar3 * 0x54) + sVar2 * 4) == 0))
      {
        *(undefined2 *)(param_1 + 0x7f2) = 1;
      }
      else {
        *(short *)(param_1 + 0x7f2) = sVar2;
      }
      FUN_0062f0a0(iVar3 * 0x54 + *(int *)(DAT_029130e4 + 0x18),param_1 + 2000,_DAT_00925018 * 30.0,
                   0,_DAT_00925018);
      return;
    }
  }
  else if (((*(int *)(param_1 + 0xcbc) != 0) &&
           ((*(byte *)(*(int *)(param_1 + 0xcbc) + 0xc) & 2) != 0)) &&
          (iVar3 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_007f17bc * 2), iVar3 != -1))
  {
    cVar1 = *(char *)(param_1 + 0x7b5);
    if (cVar1 == 'O') {
      *(undefined2 *)(param_1 + 0x7f2) = 0x2d;
    }
    else if ((cVar1 == '\0') && (*(char *)(param_1 + 0x7b8) == '\x04')) {
      *(undefined2 *)(param_1 + 0x7f2) = 0x21;
    }
    else {
      *(ushort *)(param_1 + 0x7f2) = (-(ushort)(cVar1 != '\x0e') & 10) + 0x22;
    }
    FUN_0062f0a0(iVar3 * 0x54 + *(int *)(DAT_029130e4 + 0x18),param_1 + 2000,_DAT_00925018 * 30.0,0,
                 _DAT_00925018);
    return;
  }
  return;
}

