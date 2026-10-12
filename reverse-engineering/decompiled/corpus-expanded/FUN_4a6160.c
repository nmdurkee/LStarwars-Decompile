/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a6160; label: FUN_004a6160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a6160(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float *pfVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  int unaff_ESI;
  float10 fVar14;
  float *pfVar15;
  undefined4 uVar16;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  cVar5 = *(char *)(unaff_ESI + 0x7b5);
  if (cVar5 != '\x16') {
    iVar11 = 0;
    if ((param_1 != 0) && ((*(byte *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x98) & 1) != 0)
       ) {
      if (*(char *)(unaff_ESI + 0xe32) == '\x01') {
        if (cVar5 != -1) {
          return;
        }
        if (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0xf0) == 0) {
          return;
        }
        uVar13 = 0x3c;
      }
      else {
        if (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x58) == 0) {
          return;
        }
        if (*(char *)(unaff_ESI + 0x281) == '\0') {
          return;
        }
        iVar12 = FUN_005620f0();
        if (iVar12 == 0) {
          return;
        }
        uVar13 = 0x16;
      }
      local_40 = 0.36;
      *(undefined4 *)(unaff_ESI + 0x790) = 0;
      FUN_005b3620(local_18,&DAT_0080250c,*(undefined2 *)(unaff_ESI + 0x5a));
      iVar12 = DAT_0093d504;
      if (0 < DAT_0093d500) {
        do {
          if ((iVar12 != unaff_ESI) &&
             ((iVar10 = FUN_004a60b0(iVar12), iVar10 != 0 ||
              ((((((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0 &&
                  ((*(uint *)(iVar12 + 0x1fc) & 1) != 0)) &&
                 ((*(uint *)(iVar12 + 0x1fc) & 0x1000) != 0)) &&
                ((*(char *)(iVar12 + 0x28b) == '\0' && (*(char *)(iVar12 + 0x7b5) != '\x17')))) &&
               ((((*(byte *)(*(int *)(unaff_ESI + 0x54) + 4) & 0x40) != 0 &&
                 (*(char *)(*(int *)(*(int *)(iVar12 + 0x54) + 0x24) + 0x116) == '\x01')) ||
                ((iVar10 = FUN_0056e160(0x26), iVar10 != 0 &&
                 (*(int *)(*(int *)(*(int *)(iVar12 + 0x50) + 0xc) + 0x104) != 0)))))))))) {
            fVar14 = (float10)FUN_005b3c50(iVar12 + 0x80,unaff_ESI + 0x80,local_c);
            if (((float)fVar14 < local_40) && (0.0 < local_18[0] * local_c[0] + local_10 * local_4))
            {
              *(int *)(unaff_ESI + 0x790) = iVar12;
              local_40 = (float)fVar14;
            }
          }
          iVar11 = iVar11 + 1;
          iVar12 = iVar12 + 0x10d8;
        } while (iVar11 < DAT_0093d500);
      }
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0x16;
      *(undefined2 *)(unaff_ESI + 0x7aa) = uVar13;
      fVar14 = (float10)FUN_0062e040((int)*(short *)(unaff_ESI + 0x1064),uVar13,0,0,1);
      *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) & 0xffffffbf;
      *(float *)(unaff_ESI + 0x77c) = (float)fVar14;
      FUN_0058d430();
      return;
    }
    if (param_2 == 0) {
      return;
    }
    if ((*(short *)(unaff_ESI + 0x1064) != DAT_007f197c) &&
       (*(short *)(unaff_ESI + 0x1064) != DAT_007f1a30)) {
      return;
    }
    if ((*(byte *)(unaff_ESI + 0xe22) & 1) == 0) {
      return;
    }
    if (*(char *)(unaff_ESI + 0xe33) != '\0') {
      return;
    }
    if (cVar5 == '\x06') {
      return;
    }
    if (cVar5 == '\a') {
      return;
    }
    if ((*(char *)(unaff_ESI + 0x281) != '\0') &&
       (*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28) == 0.0)) {
      if ((*(char *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x116) != '\0') ||
         (iVar11 = 0x7e, (*(byte *)(*(int *)(unaff_ESI + 0x54) + 4) & 0x80) == 0)) {
        iVar11 = 0x10;
      }
      if ((*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar11 * 4) != 0) &&
         ((cVar5 == -1 || ((*(uint *)(PTR_PTR_007fb0e4 + cVar5 * 0x10 + 8) & 4) != 0)))) {
        FUN_0058da10();
        return;
      }
    }
    FUN_0058d930();
    return;
  }
  pfVar6 = (float *)FUN_0062f150(unaff_ESI + 8,(int)*(short *)(unaff_ESI + 0x7aa),1,0);
  if (pfVar6 == (float *)0x0) {
    return;
  }
  iVar11 = *(int *)(unaff_ESI + 0x790);
  uVar7 = FUN_004a6050();
  if ((*(byte *)(unaff_ESI + 0x7bc) & 0x40) == 0) {
    fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_ESI + 0x50),
                                   (int)*(short *)(unaff_ESI + 0x7aa),0);
    if (((float)fVar14 < 1.0) || ((float)fVar14 <= *pfVar6)) {
      *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) | 0x40;
    }
    if ((*(byte *)(unaff_ESI + 0x7bc) & 0x40) != 0) {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),
                   (*(short *)(unaff_ESI + 0x1064) != DAT_007f1a18) * '\x02' + '\x01',uVar7);
      FUN_0054a8a0(**(undefined4 **)(unaff_ESI + 0xca4),0x3dcccccd,0);
      uVar16 = 1;
      pfVar1 = (float *)(unaff_ESI + 0x80);
      pfVar15 = pfVar1;
      if (*(short *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0xe4) == -1) {
        uVar8 = FUN_00547820();
        iVar12 = FUN_00650dc0("R2Zap",pfVar1,uVar8);
      }
      else {
        uVar8 = FUN_00547820();
        iVar12 = (int)*(short *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0xe4);
      }
      FUN_005478a0(iVar12,pfVar15,uVar8,uVar16);
      if (iVar11 == 0) {
        FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x58,uVar7);
        goto LAB_004a66b0;
      }
      uVar9 = FUN_005be2d0(*pfVar1 - *(float *)(iVar11 + 0x80),
                           *(float *)(unaff_ESI + 0x88) - *(float *)(iVar11 + 0x88));
      local_30 = (float)(&DAT_029899a0)[(uVar9 & 0xffff) >> 1] * *(float *)(iVar11 + 0xac) +
                 *(float *)(iVar11 + 0x80);
      local_2c = *(float *)(iVar11 + 0x84);
      local_28 = (float)(&DAT_029899a0)[(int)((uVar9 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
                 *(float *)(iVar11 + 0xac) + *(float *)(iVar11 + 0x88);
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),
                   (*(short *)(unaff_ESI + 0x1064) != DAT_007f1a18) * '\x02' + '\x01',&local_30);
      if ((((*(byte *)(unaff_ESI + 0x1fc) & 0x80) == 0) ||
          (iVar12 = FUN_0056e160(0x26), iVar12 == 0)) ||
         ((*(byte *)(*(int *)(iVar11 + 0x54) + 4) & 0x10) == 0)) {
        iVar12 = *(int *)(unaff_ESI + 0x790);
      }
      else {
        DAT_00955574 = 1;
        iVar10 = FUN_00438230();
        iVar12 = iVar11;
        if (iVar10 == 2) goto LAB_004a6463;
      }
      iVar12 = FUN_00432620(iVar12,_DAT_00804b04);
      if ((iVar12 != 0) && ((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0)) {
        FUN_00549f10();
        iVar12 = FUN_0056e160(0x15);
        if ((iVar12 != 0) &&
           (((*(byte *)(*(int *)(iVar11 + 0x54) + 4) & 0x10) != 0 &&
            ((*(byte *)(*(int *)(*(int *)(iVar11 + 0x54) + 0x24) + 0x90) & 0x40) == 0)))) {
          *(undefined1 *)(iVar11 + 0x7b8) = 2;
          iVar12 = FUN_0054fa60();
          *(float *)(iVar11 + 0x778) = (float)iVar12 * 1.5259022e-05 * 0.3 + 0.2;
          *(uint *)(iVar11 + 0x7bc) =
               *(uint *)(iVar11 + 0x7bc) ^
               ((uint)(*(short *)(unaff_ESI + 0x1064) == DAT_007f1a18) << 8 ^
               *(uint *)(iVar11 + 0x7bc)) & 0x100;
        }
      }
    }
  }
LAB_004a6463:
  if (iVar11 != 0) {
    fVar14 = (float10)FUN_005ca470(*(undefined4 *)
                                    (*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) +
                                    *(short *)(unaff_ESI + 0x7aa) * 4));
    fVar2 = (float)fVar14;
    fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_ESI + 0x50),
                                   (int)*(short *)(unaff_ESI + 0x7aa),1);
    fVar3 = (float)fVar14;
    if ((1.0 <= fVar3) && (fVar3 < fVar2)) {
      fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_ESI + 0x50),
                                     (int)*(short *)(unaff_ESI + 0x7aa),2);
      fVar4 = (float)fVar14;
      if (fVar3 < fVar4) {
        if (fVar2 < fVar4) {
          fVar4 = fVar2;
        }
        if ((fVar3 <= *pfVar6) && (*pfVar6 < fVar4 != (*pfVar6 == fVar4))) {
          *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) | 0x2000000;
          FUN_00681f40("ForceLightningLp",iVar11 + 0x80);
          if (*(int *)(unaff_ESI + 0xe04) != -1) {
            FUN_00635970(*(int *)(unaff_ESI + 0xe04),1);
            fVar14 = (float10)FUN_005becc0(iVar11 + 0x80,(float *)(unaff_ESI + 0x80),&local_24);
            fVar2 = (float)(fVar14 * (float10)0.5);
            FUN_00635890(*(undefined4 *)(unaff_ESI + 0xe04),fVar2,
                         (float)((float10)fVar2 + (float10)0.5));
            FUN_0054fa60();
            if (*(short *)(unaff_ESI + 0x1064) == DAT_007f1a18) {
              iVar11 = FUN_0054fa60();
              if (iVar11 < 0x8000) {
                local_3c = 0x40000000;
                local_34 = 0;
              }
              else {
                local_3c = 0x3e800000;
                local_34 = 0;
              }
            }
            else {
              local_3c = 0;
              iVar11 = FUN_0054fa60();
              if (iVar11 < 0x8000) {
                local_34 = 0x40000000;
              }
              else {
                local_34 = 0x3e800000;
              }
            }
            local_38 = local_34;
            FUN_00635900(*(undefined4 *)(unaff_ESI + 0xe04),&local_3c,0);
            local_30 = *(float *)(unaff_ESI + 0x80) + local_24 * 0.5;
            local_2c = local_20 * 0.5 + *(float *)(unaff_ESI + 0x84);
            local_28 = local_1c * 0.5 + *(float *)(unaff_ESI + 0x88);
            FUN_00635840(*(undefined4 *)(unaff_ESI + 0xe04),&local_30);
          }
        }
      }
    }
  }
LAB_004a66b0:
  FUN_0058bfb0();
  fVar2 = *(float *)(unaff_ESI + 0x77c) - _DAT_00925018;
  *(float *)(unaff_ESI + 0x77c) = fVar2;
  if (0.0 < fVar2) {
    return;
  }
  *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
  return;
}

