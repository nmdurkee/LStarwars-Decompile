/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b3d40; label: FUN_004b3d40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b3d40(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  char cVar4;
  short sVar5;
  short sVar6;
  float fVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  float10 fVar14;
  float local_24;
  undefined4 uStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(short *)(param_1 + 0x1064) == DAT_007f18dc) && ((*(uint *)(param_1 + 0xef0) & 0x200) != 0))
  {
    uVar9 = 0x13;
  }
  else {
    uVar9 = FUN_00407e40(param_1,0);
  }
  if (0.0 < *(float *)(param_1 + 0xd58)) {
    *(float *)(param_1 + 0xd58) = *(float *)(param_1 + 0xd58) - _DAT_00925018;
  }
  cVar3 = *(char *)(param_1 + 0x7b5);
  if (cVar3 == '\n') {
    pfVar1 = (float *)(param_1 + 8);
    iVar10 = FUN_0062f150(pfVar1,(int)*(short *)(param_1 + 0x7aa),1,0);
    if (iVar10 != 0) {
      iVar10 = FUN_005a86a0(param_1 + 0x7f4);
      if ((((param_2 == 0) || (iVar10 == 0)) || (0.0 < *(float *)(param_1 + 0xd58))) ||
         ((*(short *)(param_1 + 0x7aa) != 0x57 || (2 < *(byte *)(param_1 + 0xe3b))))) {
        sVar5 = *(short *)(param_1 + 0x7aa);
        if ((sVar5 == 0x5a) || ((sVar5 == 0x5b || (sVar5 == 0x5c)))) {
          if ((*(uint *)(param_1 + 0xe20) & 0x40000) == 0) {
            fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)sVar5,0);
            if (1.0 < (float)fVar14) {
              if (*(char *)(param_1 + 0x39) == '\0') {
                fVar2 = *pfVar1;
              }
              else {
                fVar2 = *(float *)(param_1 + 0x1c);
              }
              if ((float)fVar14 <= fVar2) {
                if (iVar10 != 0) {
                  FUN_0049d430(uVar9,1);
                  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x800;
                }
                *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x40000;
              }
            }
          }
        }
        else if (*(char *)(param_1 + 0xe31) == '\0') {
          fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)sVar5,1);
          if (1.0 < (float)fVar14) {
            if (*(char *)(param_1 + 0x39) == '\0') {
              fVar2 = *pfVar1;
            }
            else {
              fVar2 = *(float *)(param_1 + 0x1c);
            }
            if ((float)fVar14 <= fVar2) {
              if (iVar10 != 0) {
                FUN_0049d430(uVar9,2);
              }
              *(undefined1 *)(param_1 + 0xe31) = 1;
            }
          }
        }
        fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
        *(float *)(param_1 + 0x77c) = fVar2;
        if (fVar2 <= 0.0) {
          sVar5 = *(short *)(param_1 + 0x7aa);
          *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffff7ff;
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          if ((((sVar5 == 0x5a) || (sVar5 == 0x5b)) || (sVar5 == 0x5c)) &&
             (((*(uint *)(param_1 + 0xe20) & 0x40000) == 0 && (iVar10 != 0)))) {
            FUN_0049d430(uVar9,1);
            return 0;
          }
        }
      }
      else {
        if (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) {
          uVar8 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4));
          *(undefined2 *)(param_1 + 0x27a) = uVar8;
          *(undefined2 *)(param_1 + 0x5a) = uVar8;
          *(undefined2 *)(param_1 + 0x58) = uVar8;
        }
        FUN_004b11b0(param_1,0x57);
        if (*(char *)(param_1 + 0xe3b) == '\x03') {
          *(undefined4 *)(param_1 + 0xd58) = 0x3f000000;
          return 0;
        }
      }
    }
    return 0;
  }
  if ((((((*(byte *)(param_1 + 0xeec) & 8) == 0) || (param_2 == 0)) ||
       ((*(uint *)(PTR_PTR_007fb0e4 + cVar3 * 0x10 + 8) & 0x20) != 0)) ||
      ((uVar11 = *(uint *)(param_1 + 0x1fc) >> 7 & 1, uVar11 == 0 &&
       ((cVar3 == '\x06' || (cVar3 == '\a')))))) ||
     ((uVar11 == 0 &&
      ((cVar3 == '\x01' &&
       ((*(short *)(param_1 + 0x7aa) == 0x59 || (*(short *)(param_1 + 0x7aa) == 0xb3)))))))) {
    if (param_4 == 0) {
      return 0;
    }
    if (((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 4) == 0) && (param_3 == 0)) {
      return 0;
    }
    if ((*(byte *)(param_1 + 0xe22) & 1) == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0xe33) != '\0') {
      return 0;
    }
    if (cVar3 == '\x06') {
      return 0;
    }
    if (cVar3 == '\a') {
      return 0;
    }
    if (cVar3 == 'G') {
      return 0;
    }
    if (cVar3 == 'F') {
      return 0;
    }
    if (cVar3 == '\v') {
      return 0;
    }
    if (cVar3 == '.') {
      return 0;
    }
    cVar4 = *(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116);
    if ((cVar4 == '\x02') && (*(char *)(param_1 + 0xe32) == '\x01')) {
      return 0;
    }
    if (cVar3 == '\b') {
      return 0;
    }
    if (cVar3 == '\x1b') {
      return 0;
    }
    if (cVar3 == '\x1d') {
      return 0;
    }
    if (param_4 != 2) {
      if ((*(char *)(param_1 + 0x281) != '\0') &&
         (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) == 0.0)) {
        if ((cVar4 != '\0') ||
           (iVar10 = 0x7e, (*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0)) {
          iVar10 = 0x10;
        }
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar10 * 4) != 0) &&
           ((cVar3 == -1 || ((*(uint *)(PTR_PTR_007fb0e4 + cVar3 * 0x10 + 8) & 4) != 0)))) {
          FUN_0058da10(param_1);
          return 0;
        }
      }
      FUN_0058d930(param_1,1);
      return 0;
    }
    FUN_0058d8e0(param_1);
    return 0;
  }
  if (((cVar3 == '\x06') || (cVar3 == '\a')) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x1000) != 0)) {
    return 0;
  }
  if (DAT_007f3b14 != -1) {
    return 0;
  }
  if ((param_4 != 0) && ((*(byte *)(param_1 + 0xe22) & 1) == 0)) {
    if (param_4 != 2) {
      if (((*(char *)(param_1 + 0xe33) == '\0') && (*(char *)(param_1 + 0x281) != '\0')) &&
         (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) == 0.0)) {
        if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\0') ||
           (iVar10 = 0x7f, (*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0)) {
          iVar10 = 0x11;
        }
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar10 * 4) != 0) &&
           ((cVar3 == -1 || ((*(uint *)(PTR_PTR_007fb0e4 + cVar3 * 0x10 + 8) & 4) != 0)))) {
          FUN_0058d560(param_1);
          return 0;
        }
      }
      FUN_0058d480(param_1,1);
      return 0;
    }
    FUN_0058d430(param_1);
  }
  if ((*(char *)(param_1 + 0x7b5) != -1) || (iVar10 = 2, *(char *)(param_1 + 0xe32) != '\x01')) {
    iVar10 = param_6;
  }
  iVar12 = FUN_005a86a0(param_1 + 0x7f4);
  if (iVar12 == 0) {
    return 0;
  }
  if (0.0 < *(float *)(param_1 + 0xd58)) {
    return 0;
  }
  if (*(char *)(param_1 + 0x28b) != '\0') {
    return 0;
  }
  if ((iVar10 == 0) && (*(char *)(param_1 + 0x281) == '\0')) {
    if (*(char *)(param_1 + 0x7b5) != '\0') {
      return 0;
    }
    if (param_5 == 0) {
      return 0;
    }
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x400000) != 0) {
      return 0;
    }
  }
  if (*(char *)(param_1 + 0x7b5) == '%') {
    return 0;
  }
  if ((*(char *)(param_1 + 0x7b5) == '\0') && (1 < *(byte *)(param_1 + 0x7b9))) {
    return 0;
  }
  iVar12 = FUN_0056e160(0xf);
  if (iVar12 != 0) {
    cVar3 = *(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116);
    if (cVar3 == '\x01') {
      return 0;
    }
    if (cVar3 == '\b') {
      return 0;
    }
  }
  uVar8 = *(undefined2 *)(param_1 + 0x7aa);
  *(undefined2 *)(param_1 + 0x7aa) = 0x16;
  if (((*(short *)(param_1 + 0x1064) == DAT_007f1ab8) && ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0))
     && (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0xf0) != 0)) {
    *(undefined2 *)(param_1 + 0x7aa) = 0x3c;
  }
  if (iVar10 == 2) {
    *(undefined2 *)(param_1 + 0x7aa) = 0x3c;
  }
  iVar10 = FUN_0055cdf0(param_1);
  if (iVar10 != 0) {
    local_c = *(undefined4 *)(param_1 + 0x80);
    local_8 = *(undefined4 *)(param_1 + 0x84);
    local_4 = *(undefined4 *)(param_1 + 0x88);
    (**(code **)(PTR_PTR_008040bc + 0x14))(param_1,&local_24);
    fStack_18 = local_24;
    uStack_14 = uStack_20;
    fStack_10 = fStack_1c;
    iVar10 = FUN_005806a0(uVar9,PTR_DAT_00802c54);
    fVar2 = *(float *)(iVar10 + 0x14);
    iVar10 = FUN_005806a0(uVar9,PTR_DAT_00802c54);
    fVar2 = *(float *)(iVar10 + 0x10) * fVar2;
    fVar7 = fVar2 * fVar2;
    iVar10 = FUN_00433df0(param_1,&local_c,&local_24,fVar2,fVar7,0,1,0,uVar9);
    if (iVar10 == 0) {
      if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
          (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) == 0.0)) &&
         ((*(char *)(param_1 + 0x281) != '\0' && (*(char *)(param_1 + 0x7b5) != '\0')))) {
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x16c) != 0) &&
           (iVar12 = FUN_0062f150(param_1 + 8,0x5b,1,1), iVar12 == 0)) {
          local_24 = fStack_10;
          fStack_1c = -fStack_18;
          iVar12 = FUN_00433df0(param_1,&local_c,&local_24,fVar2,fVar7,0,1,1,uVar9);
          iVar10 = 0;
          if (iVar12 != 0) {
            *(undefined2 *)(param_1 + 0x7aa) = 0x5b;
            FUN_004a5ec0(param_1,iVar12);
            goto LAB_004b460a;
          }
        }
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x168) == 0) ||
           (iVar12 = FUN_0062f150(param_1 + 8,0x5a,1,1), iVar12 != 0)) {
LAB_004b448d:
          if (iVar10 != 0) goto LAB_004b4508;
        }
        else {
          local_24 = -fStack_10;
          fStack_1c = fStack_18;
          iVar10 = FUN_00433df0(param_1,&local_c,&local_24,fVar2,fVar7,0,1,1,uVar9);
          if (iVar10 != 0) {
            *(undefined2 *)(param_1 + 0x7aa) = 0x5a;
            goto LAB_004b448d;
          }
        }
        if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x170) != 0) &&
           (iVar12 = FUN_0062f150(param_1 + 8,0x5c,1,1), iVar12 == 0)) {
          local_24 = -fStack_18;
          fStack_1c = -fStack_10;
          iVar10 = FUN_00433df0(param_1,&local_c,&local_24,fVar2,fVar7,0,1,1,uVar9);
          if (iVar10 == 0) goto LAB_004b4517;
          *(undefined2 *)(param_1 + 0x7aa) = 0x5c;
        }
        if (iVar10 != 0) goto LAB_004b4508;
      }
LAB_004b4517:
      iVar10 = FUN_0046a450(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_00802c54,param_1,
                            &local_c,&fStack_18,fVar2,fVar7,1,0,uVar9);
      if (iVar10 == 0) {
        iVar10 = FUN_0056a240(param_1,&local_c,&fStack_18,fVar2,fVar7,1,0,uVar9);
        if (iVar10 == 0) {
          iVar10 = FUN_00572020(param_1,&local_c,&fStack_18,fVar2,fVar7,1,uVar9);
          if (iVar10 == 0) {
            iVar10 = FUN_00433df0(param_1,&local_c,&fStack_18,fVar2,fVar7,0x200,1,0,uVar9);
            if (iVar10 != 0) {
              FUN_004a5ec0(param_1,iVar10);
            }
          }
          else {
            FUN_004a5fe0(param_1,iVar10);
          }
        }
        else {
          FUN_004a5f70(param_1,iVar10);
        }
      }
    }
    else {
LAB_004b4508:
      FUN_004a5ec0(param_1,iVar10);
    }
  }
LAB_004b460a:
  fVar14 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)*(short *)(param_1 + 0x7aa),
                                 0,0,0);
  *(float *)(param_1 + 0xd58) = (float)fVar14;
  sVar5 = *(short *)(param_1 + 0x1064);
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffbffff;
  *(undefined1 *)(param_1 + 0xe31) = 0;
  if (((((sVar5 == DAT_007f18f4) || (sVar5 == DAT_007f1af4)) || (sVar5 == DAT_007f18f8)) ||
      ((sVar5 == DAT_007f1914 || (sVar5 == DAT_007f1ae4)))) || (sVar5 == DAT_007f1af8)) {
    iVar10 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,1);
    if ((iVar10 != 0) || (iVar10 = FUN_0062f150(param_1 + 8,1,0,0), iVar10 != 0)) goto LAB_004b46ba;
LAB_004b4743:
    if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x98) & 8) == 0) {
      FUN_0049d430(uVar9,3);
      *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) * 0.5;
      *(float *)(param_1 + 0x70) = *(float *)(param_1 + 0x70) * 0.5;
    }
LAB_004b48c7:
    if (0.0 < *(float *)(param_1 + 0xd58)) goto LAB_004b4921;
    iVar10 = FUN_0054fa60();
    fVar2 = (float)iVar10 * 1.5259022e-05 * 0.2 + 0.2;
    *(float *)(param_1 + 0xd58) = fVar2;
    if (*(short *)(param_1 + 0x1064) != DAT_007f1a34) goto LAB_004b4921;
    fVar2 = fVar2 * 5.0;
  }
  else {
LAB_004b46ba:
    sVar5 = *(short *)(param_1 + 0x7aa);
    if (sVar5 != 0x5a) {
      if ((((sVar5 != 0x5b) && (sVar5 != 0x5c)) &&
          (iVar10 = *(int *)(*(int *)(param_1 + 0x54) + 0x24), (*(byte *)(iVar10 + 0x98) & 4) == 0))
         && (((((cVar3 = *(char *)(iVar10 + 0x116), cVar3 == '\x04' &&
                (*(short *)(param_1 + 0x3e) == 3)) ||
               ((sVar6 = *(short *)(param_1 + 0x3e), sVar6 == 0x17 &&
                (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x5c) != 0)))) ||
              (((cVar3 == '\0' && (sVar6 == 0x73)) &&
               (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x1cc) != 0)))) ||
             ((sVar6 == 6 && (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x18) != 0))))))
      goto LAB_004b4743;
      if (((sVar5 == 0x5a) || (sVar5 == 0x5b)) || (sVar5 == 0x5c)) goto LAB_004b478a;
LAB_004b47e2:
      fVar2 = *(float *)(param_1 + 0xd58) - _DAT_029a99a4;
      if (0.0 < fVar2) {
        *(float *)(param_1 + 0x77c) = fVar2;
        *(undefined1 *)(param_1 + 0x7b5) = 10;
        FUN_0062e650(param_1 + 8,0xffffffff);
        *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 0x10;
        FUN_0058d430(param_1);
        if (*(short *)(param_1 + 0x1064) == DAT_007f192c) {
          FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f19999a,0);
          FUN_00549bb0(PTR_DAT_008021b4,0x3f000000,0x3f000000,0x3f800000);
        }
      }
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x98) & 8) != 0) goto LAB_004b48c7;
      if (fVar2 <= 0.0) {
LAB_004b48bb:
        uVar13 = 3;
      }
      else {
        fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                       (int)*(short *)(param_1 + 0x7aa),1);
        uVar13 = 1;
        if (fVar14 <= (float10)1.0) goto LAB_004b48bb;
      }
      FUN_0049d430(uVar9,uVar13);
      goto LAB_004b48c7;
    }
LAB_004b478a:
    fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)sVar5,0);
    if (fVar14 <= (float10)1.0) goto LAB_004b47e2;
    fVar7 = *(float *)(param_1 + 0xd58) - _DAT_029a99a4;
    *(float *)(param_1 + 0x77c) = fVar7;
    fVar2 = 0.0;
    if (0.0 < fVar7) {
      *(undefined1 *)(param_1 + 0x7b5) = 10;
      goto LAB_004b48c7;
    }
  }
  *(float *)(param_1 + 0xd58) = fVar2;
LAB_004b4921:
  if (*(char *)(param_1 + 0x7b5) != '\n') {
    *(undefined2 *)(param_1 + 0x7aa) = uVar8;
    return 1;
  }
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
  if (*(code **)(*(int *)(param_1 + 0x54) + 0x18) == FUN_004b30e0) {
    *(undefined2 *)(param_1 + 0x58) = *(undefined2 *)(param_1 + 0x27a);
    *(undefined2 *)(param_1 + 0x5a) = *(undefined2 *)(param_1 + 0x27a);
  }
  return 1;
}

