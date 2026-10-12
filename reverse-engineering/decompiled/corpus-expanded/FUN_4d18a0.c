/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d18a0; label: FUN_004d18a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d18a0(int param_1,int param_2)

{
  float fVar1;
  char cVar2;
  short sVar3;
  float fVar4;
  float *pfVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  
  cVar2 = *(char *)(param_1 + 0x7b5);
  if (cVar2 == 'D') {
    sVar3 = *(short *)(param_1 + 0x7aa);
    if (sVar3 != 0x8f) {
      *(float *)(param_1 + 0x74c) = _DAT_00925018 + *(float *)(param_1 + 0x74c);
    }
    if ((sVar3 != 6) && (sVar3 != 5)) {
      if (param_2 != 0) {
        if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
          FUN_00561ba0(param_1);
          *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
          return;
        }
        *(undefined4 *)(param_1 + 0x6c) = 0x40000000;
        *(undefined2 *)(param_1 + 0x7aa) = 6;
        *(undefined4 *)(param_1 + 0x77c) = 0;
        fVar9 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),6,0,0);
        *(float *)(param_1 + 0x784) = (float)fVar9;
        if ((float)fVar9 <= 0.0) {
          *(undefined4 *)(param_1 + 0x784) = 0x3f800000;
        }
        FUN_0062e650(param_1 + 8,0xffffffff);
        return;
      }
      if (sVar3 == 0x8f) {
        pfVar5 = (float *)FUN_0062f150(param_1 + 8,0x8f,1);
        if (pfVar5 != (float *)0x0) {
          fVar9 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                        (int)*(short *)(param_1 + 0x7aa),0);
          if (((1.0 <= (float)fVar9) && ((float)fVar9 <= *pfVar5)) &&
             (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) {
            uVar6 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4),
                                 *(undefined2 *)(*(int *)(param_1 + 0x798) + 0x44));
            fVar9 = (float10)FUN_00550180(uVar6);
            if (DAT_029959a0 < ABS((float)fVar9)) {
              FUN_004d1360(0);
              goto LAB_004d1acb;
            }
          }
          fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
          *(float *)(param_1 + 0x77c) = fVar1;
          if (fVar1 <= 0.0) {
            *(undefined2 *)(param_1 + 0x7aa) = 0x88;
          }
        }
      }
      else {
        iVar7 = FUN_004d1360(0);
        if (((iVar7 == 0) && (*(short *)(param_1 + 0x7aa) != 0x8f)) &&
           (fVar1 = *(float *)(param_1 + 0x74c), !NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5))) {
          FUN_00561ba0(param_1,0);
          if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x80000) == 0) {
            uVar6 = 0x3fe66666;
          }
          else {
            uVar6 = 0x3f99999a;
          }
          *(undefined4 *)(param_1 + 0x6c) = uVar6;
        }
      }
LAB_004d1acb:
      fVar9 = (float10)FUN_005bed80(param_1 + 0x80,*(int *)(param_1 + 0x798) + 0x10,0);
      *(float *)(param_1 + 0x778) = (float)fVar9;
      return;
    }
    fVar1 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
    iVar7 = *(int *)(param_1 + 0x798);
    *(float *)(param_1 + 0x77c) = fVar1;
    if (sVar3 == 5) {
      fVar4 = *(float *)(param_1 + 0x784) + *(float *)(param_1 + 0x784);
      if (fVar4 < fVar1 != (fVar4 == fVar1)) {
        FUN_00561d20(param_1);
      }
    }
    else if ((sVar3 == 6) &&
            (*(float *)(param_1 + 0x784) < fVar1 != (*(float *)(param_1 + 0x784) == fVar1))) {
      *(undefined2 *)(param_1 + 0x7aa) = 5;
    }
    if (((*(float *)(param_1 + 0x6c) <= 0.0) && (iVar8 = FUN_004d1510(), iVar8 == 0)) &&
       (*(char *)(param_1 + 0x281) != '\0')) {
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x400;
      if ((*(short *)(param_1 + 0x7aa) != 5) ||
         (iVar8 = FUN_005621a0(param_1,0xffffffff), iVar8 == 0)) {
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x1c) == 0) ||
           (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) != 0.0)) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        }
        else {
          *(undefined1 *)(param_1 + 0x7b5) = 1;
          *(undefined2 *)(param_1 + 0x7aa) = 7;
          fVar9 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),7,0,0,1);
          *(float *)(param_1 + 0x77c) = (float)fVar9;
          *(undefined4 *)(param_1 + 0xd28) = 0x3e4ccccd;
          FUN_0062e650(param_1 + 8,0xffffffff);
        }
      }
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffbff;
    }
    if ((*(char *)(param_1 + 0x7b5) == 'D') && (*(int *)(param_1 + 0x798) == iVar7)) {
      FUN_004d1360(1);
      fVar9 = (float10)FUN_005bed80(param_1 + 0x80,*(int *)(param_1 + 0x798) + 0x10,0);
      *(float *)(param_1 + 0x778) = (float)fVar9;
    }
  }
  else if (((((*(char *)(param_1 + 0x281) == '\0') && (*(float *)(param_1 + 0x6c) <= 0.0)) &&
            (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x220) != 0)) &&
           ((cVar2 == -1 ||
            (((cVar2 == '\0' && (0.1 <= *(float *)(param_1 + 0x77c))) &&
             ((cVar2 = *(char *)(param_1 + 0x7b8), cVar2 != '\x03' &&
              ((cVar2 != '\x04' && (cVar2 != '\b')))))))))) &&
          (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0 || ((*(uint *)(param_1 + 0xef4) & 0x4000) != 0)
           ))) {
    FUN_004d1510();
    *(undefined4 *)(param_1 + 0x750) = 0;
    *(undefined1 *)(param_1 + 0x7b4) = 0;
    *(undefined4 *)(param_1 + 0x74c) = 0;
    return;
  }
  return;
}

