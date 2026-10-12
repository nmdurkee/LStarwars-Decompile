/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49ea70; label: FUN_0049ea70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ea70(int param_1,int param_2,int param_3,int param_4,int param_5,float param_6)

{
  float fVar1;
  char cVar2;
  float fVar3;
  short sVar4;
  undefined2 uVar5;
  float *pfVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  float10 fVar14;
  char *pcVar15;
  undefined4 local_14;
  int local_10 [4];
  
  if (DAT_007f39e4 == 0) {
    uVar9 = 0x40000000;
  }
  else {
    uVar9 = 0x3fa00000;
  }
  FUN_0049ea00(param_1);
  if ((param_4 != 0) && ((DAT_007f39e4 == 0 || (param_4 = 2, *(char *)(param_1 + 0xf00) == '\x05')))
     ) {
    param_4 = 1;
  }
  if (*(char *)(param_1 + 0x1085) == '\a') {
    return;
  }
  if (*(char *)(param_1 + 0xf00) == '\x05') {
    param_2 = 1;
  }
  if (*(char *)(param_1 + 0x7b5) == '&') {
    if ((*(char *)(param_1 + 0x7b7) != -1) && (*(int *)(param_1 + 0x790) == 0)) {
      if ((*(uint *)(param_1 + 0xe20) & 0x40000000) != 0) {
        FUN_0058d480(param_1,1);
      }
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      if (param_6 == 0.0) {
        return;
      }
      *(float *)(param_1 + 0xd58) = param_6;
      return;
    }
    pfVar6 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0);
    if (pfVar6 == (float *)0x0) {
      return;
    }
    bVar13 = false;
    if (*(char *)(param_1 + 0x7b0) == '\0') {
      if (param_2 != 0) {
        if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
          iVar7 = FUN_0054fa60();
          *(char *)(param_1 + 0x7b0) =
               (char)((int)(iVar7 + (iVar7 >> 0x1f & 0x7fffU)) >> 0xf) + '\x01';
        }
        else if (((*(byte *)(param_1 + 0x7bc) & 0x40) != 0) ||
                (*(float *)(param_1 + 0x77c) <= *(float *)(param_1 + 0x784))) {
          *(undefined1 *)(param_1 + 0x7b0) = 2;
        }
        else {
          *(undefined1 *)(param_1 + 0x7b0) = 1;
        }
      }
      bVar13 = *(char *)(param_1 + 0x7b0) == '\0';
    }
    if ((bVar13) || (*(float *)(param_1 + 0x784) < *(float *)(param_1 + 0x77c))) {
      *(float *)(param_1 + 0x77c) = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    }
    else {
      *(undefined4 *)(param_1 + 0x77c) = 0;
    }
    if (0.0 < *(float *)(param_1 + 0x77c)) {
      if ((*(byte *)(param_1 + 0x7bc) & 0x40) != 0) {
        return;
      }
      fVar14 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                     (int)*(short *)(param_1 + 0x7aa),0);
      if ((float)fVar14 <= 0.0) {
        return;
      }
      if (*pfVar6 < (float)fVar14) {
        return;
      }
      FUN_0058e4e0(param_1,*(undefined4 *)(param_1 + 0x790),local_14,param_1);
      return;
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    if (*(char *)(param_1 + 0x7b7) == -1) {
      if ((*(byte *)(param_1 + 0x7bc) & 0x40) == 0) {
        FUN_0058e4e0(param_1,*(undefined4 *)(param_1 + 0x790),local_14,param_1);
      }
      if ((((param_5 == 0) && ((*(byte *)(param_1 + 0x7bc) & 0x80) == 0)) &&
          (*(byte *)(param_1 + 0x7b2) < 2)) &&
         ((*(char *)(param_1 + 0x7b0) != '\0' && (*(char *)(param_1 + 0x1085) != '\x06')))) {
        *(undefined4 *)(param_1 + 0x790) = 0;
        *(undefined4 *)(param_1 + 0x794) = 0;
        iVar7 = FUN_0049ca80(param_1,uVar9,param_1,1,1,1);
        *(int *)(param_1 + 0x790) = iVar7;
        if (iVar7 == 0) {
          if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
            uVar8 = FUN_00569980(param_1,uVar9,param_1,0,4,0,0,0);
            *(undefined4 *)(param_1 + 0x794) = uVar8;
          }
          if (*(int *)(param_1 + 0x794) == 0) {
            uVar9 = FUN_0049ca80(param_1,uVar9,param_1,1,1,2);
            *(undefined4 *)(param_1 + 0x790) = uVar9;
          }
        }
        if (((param_4 == 0) || (*(int *)(param_1 + 0x790) != 0)) || (*(int *)(param_1 + 0x794) != 0)
           ) {
          *(char *)(param_1 + 0x7b2) = *(char *)(param_1 + 0x7b2) + '\x01';
          if ((*(byte *)(param_1 + 0x7bc) & 1) == 0) {
            *(ushort *)(param_1 + 0x7aa) = (*(char *)(param_1 + 0x7b2) != '\x01') + 0x55;
          }
          else {
            local_10[1] = 0xffffffff;
            local_10[2] = 0xffffffff;
            local_10[3] = 0xffffffff;
            if (*(char *)(param_1 + 0x7b2) == '\x01') {
              if (*(char *)(param_1 + 0x7b0) == '\x02') {
                *(undefined1 *)(param_1 + 0x7ae) = 2;
                local_10[0] = 1;
              }
              else {
                *(undefined1 *)(param_1 + 0x7ae) = 1;
                local_10[0] = 2;
              }
            }
            else {
              if (*(char *)(param_1 + 0x7ae) == '\x02') {
                *(char *)(param_1 + 0x7ae) = (*(char *)(param_1 + 0x7b0) == '\x02') + '\x05';
              }
              else {
                *(char *)(param_1 + 0x7ae) = (*(char *)(param_1 + 0x7b0) == '\x02') + '\x03';
              }
              local_10[0] = 6;
              local_10[1] = 5;
              local_10[2] = 4;
              local_10[3] = 3;
            }
            sVar4 = (ushort)*(byte *)(param_1 + 0x7ae) + *(short *)(param_1 + 0x7ac);
            *(short *)(param_1 + 0x7aa) = sVar4;
            iVar7 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
            if (*(int *)(iVar7 + sVar4 * 4) == 0) {
              iVar12 = 0;
              do {
                if (local_10[0] == -1) break;
                iVar10 = (int)*(short *)(param_1 + 0x7ac) + local_10[iVar12];
                if (*(int *)(iVar7 + iVar10 * 4) != 0) {
                  *(short *)(param_1 + 0x7aa) = (short)iVar10;
                  break;
                }
                iVar12 = iVar12 + 1;
              } while (iVar12 < 4);
            }
          }
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4)
              != 0) {
            fVar14 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                           (int)*(short *)(param_1 + 0x7aa),0,0,0);
            fVar1 = (float)fVar14;
            uVar9 = 0;
            if (0.0 < fVar1) {
              *(float *)(param_1 + 0x77c) = fVar1;
              *(undefined1 *)(param_1 + 0x7b5) = 0x26;
              if (((*(uint *)(param_1 + 0x7bc) & 1) != 0) && (*(byte *)(param_1 + 0x7b2) < 2)) {
                uVar9 = 0x3e4ccccd;
              }
              *(undefined4 *)(param_1 + 0x784) = uVar9;
              *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
              *(float *)(param_1 + 0x77c) = fVar1 + *(float *)(param_1 + 0x784);
              *(undefined1 *)(param_1 + 0x7b0) = 0;
              FUN_0062e650(param_1 + 8,0xffffffff);
              if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x98) & 0x10) == 0) {
                uVar11 = FUN_0062a6a0(*(undefined4 *)(param_1 + 0x50),
                                      (int)*(short *)(param_1 + 0x7aa));
                if ((uVar11 & 4) == 0) {
                  pcVar15 = "Swipe";
                }
                else {
                  pcVar15 = "WhipSwish";
                }
                FUN_00681f40(pcVar15,param_1 + 0x80);
              }
              if ((*(int *)(param_1 + 0x790) == 0) && (*(int *)(param_1 + 0x794) == 0)) {
                uVar5 = FUN_0054b3d0(param_1,*(undefined4 *)(param_1 + 0xca4));
                *(undefined2 *)(param_1 + 0x5a) = uVar5;
              }
            }
          }
        }
      }
      else if (((param_3 != 0) || (*(char *)(param_1 + 0x1085) == '\x06')) &&
              ((*(short *)(param_1 + 0x1064) == DAT_007f1884 ||
               (*(short *)(param_1 + 0x1064) == DAT_007f1874)))) {
        FUN_0058e3b0(param_1);
      }
    }
    else {
      iVar7 = FUN_0058af20((int)*(char *)(param_1 + 0x7b7),8);
      if (iVar7 != 0) {
        if ((*(int *)(param_1 + 0x790) != 0) &&
           (FUN_00414ab0(*(int *)(param_1 + 0x790),0x3ecccccd),
           (*(byte *)(*(int *)(param_1 + 0x790) + 0x1fc) & 0x80) != 0)) {
          FUN_0054aae0(param_1,0x3f333333);
        }
        FUN_0054aa70(param_1);
      }
    }
    if (*(char *)(param_1 + 0x7b5) != -1) {
      return;
    }
    if ((*(uint *)(param_1 + 0xe20) & 0x40000000) != 0) {
      FUN_0058d480(param_1,1);
    }
    if (param_6 == 0.0) {
      return;
    }
    *(float *)(param_1 + 0xd58) = param_6;
    return;
  }
  if ((param_6 != 0.0) && (0.0 < *(float *)(param_1 + 0xd58))) {
    *(float *)(param_1 + 0xd58) = *(float *)(param_1 + 0xd58) - _DAT_00925018;
    return;
  }
  if (((*(char *)(param_1 + 0x281) == '\0') || (*(char *)(param_1 + 0x7b5) != -1)) &&
     (iVar7 = FUN_00578790(param_1,0x26), iVar7 == 0)) {
    return;
  }
  if ((DAT_007f39e4 == 0) && (param_4 == 0)) {
    uVar11 = *(uint *)(param_1 + 0x1fc) >> 7 & 1;
    if ((uVar11 == 0) || ((*(byte *)(param_1 + 0xe24) & 0x40) == 0)) {
      if (uVar11 != 0) {
        return;
      }
      goto LAB_0049f14b;
    }
  }
  else {
LAB_0049f14b:
    if (param_2 == 0) {
      return;
    }
  }
  FUN_0049cf20(uVar9,param_1,1);
  iVar7 = *(int *)(param_1 + 0x790);
  if (((iVar7 == 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)) &&
     ((*(char *)(param_1 + 0x1085) == '\0' && (*(char *)(param_1 + 0xf00) != '\x05')))) {
    return;
  }
  if ((((iVar7 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) &&
      (*(char *)(iVar7 + 0x7b5) != '0')) && (iVar7 = FUN_0058af60(param_1,iVar7), iVar7 != -1)) {
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x200;
    *(char *)(param_1 + 0x7b7) = (char)iVar7;
    uVar5 = FUN_0058aec0((int)(char)iVar7);
    *(undefined2 *)(param_1 + 0x7aa) = uVar5;
    *(undefined1 *)(param_1 + 0x7b2) = 2;
    goto LAB_0049f2c6;
  }
  if (((*(int *)(param_1 + 0x790) == 0) || (DAT_0087b898 == 0)) &&
     ((*(int *)(param_1 + 0x794) == 0 || (DAT_00950bb0 == 0)))) {
    *(undefined1 *)(param_1 + 0x7b7) = 0xff;
    if (*(char *)(param_1 + 0x1085) == '\0') {
switchD_0049f268_default:
      *(undefined1 *)(param_1 + 0x7b2) = 0;
LAB_0049f2bf:
      *(undefined2 *)(param_1 + 0x7aa) = 0x51;
    }
    else {
      switch(*(char *)(param_1 + 0x1085)) {
      case '\x01':
        *(undefined1 *)(param_1 + 0x7b2) = 2;
        goto LAB_0049f2bf;
      case '\x02':
        *(undefined2 *)(param_1 + 0x7aa) = 0x55;
        *(undefined1 *)(param_1 + 0x7b2) = 2;
        break;
      case '\x03':
        *(undefined2 *)(param_1 + 0x7aa) = 0x56;
        *(undefined1 *)(param_1 + 0x7b2) = 2;
        break;
      case '\x04':
        goto switchD_0049f268_caseD_4;
      case '\x05':
        *(undefined2 *)(param_1 + 0x7aa) = 100;
        goto LAB_0049f2d0;
      case '\x06':
        FUN_0058e3b0(param_1);
        return;
      case '\a':
        goto switchD_0049f268_caseD_7;
      default:
        goto switchD_0049f268_default;
      }
    }
LAB_0049f2c6:
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffff7f;
  }
  else {
    *(undefined1 *)(param_1 + 0x7b7) = 0xff;
switchD_0049f268_caseD_4:
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x80;
    *(undefined2 *)(param_1 + 0x7aa) = 0x94;
    *(undefined1 *)(param_1 + 0x7b2) = 0;
  }
LAB_0049f2d0:
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffffffe;
  if ((((DAT_007f39e4 == 0) || (DAT_00876580 != 0)) ||
      ((*(short *)(param_1 + 0x1064) == DAT_007f17d4 &&
       (iVar7 = FUN_0062df80((int)DAT_007f17c4), iVar7 != 0)))) &&
     ((*(short *)(param_1 + 0x7aa) == 0x51 && (*(char *)(param_1 + 0x7b2) == '\0')))) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
    bVar13 = *(int *)(iVar7 + 0xd4) == 0;
    if (*(int *)(iVar7 + 0xb8) == 0) {
      if (bVar13) {
        *(undefined1 *)(param_1 + 0xe41) = 0xff;
      }
      else {
        *(undefined1 *)(param_1 + 0xe41) = 1;
      }
    }
    else if (bVar13) {
      *(undefined1 *)(param_1 + 0xe41) = 0;
    }
    else {
      *(bool *)(param_1 + 0xe41) = *(char *)(param_1 + 0xe41) == '\0';
    }
    if ((*(char *)(param_1 + 0xe41) != -1) &&
       (iVar7 = (-(uint)(*(char *)(param_1 + 0xe41) != '\0') & 7) + 0x2e,
       *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar7 * 4) != 0)) {
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 1;
      uVar5 = (undefined2)iVar7;
      *(undefined2 *)(param_1 + 0x7ac) = uVar5;
      *(undefined1 *)(param_1 + 0x7ae) = 0;
      *(undefined2 *)(param_1 + 0x7aa) = uVar5;
    }
  }
  if (((((param_4 != 2) || (*(int *)(param_1 + 0x790) != 0)) || (*(int *)(param_1 + 0x794) == 0)) &&
      (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) != 0))
     && (((param_4 == 0 || (*(int *)(param_1 + 0x790) != 0)) || (*(int *)(param_1 + 0x794) != 0))))
  {
    fVar14 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                   (int)*(short *)(param_1 + 0x7aa),0,0,0);
    fVar1 = (float)fVar14;
    fVar3 = 0.0;
    if (0.0 < fVar1) {
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
      *(float *)(param_1 + 0x77c) = fVar1;
      *(undefined1 *)(param_1 + 0x7b5) = 0x26;
      *(undefined1 *)(param_1 + 0x7b0) = 0;
      if ((*(uint *)(param_1 + 0x7bc) & 1) != 0) {
        fVar3 = 0.2;
      }
      *(float *)(param_1 + 0x784) = fVar3;
      if (-1 < (char)*(uint *)(param_1 + 0x7bc)) {
        *(float *)(param_1 + 0x77c) = fVar3 + fVar1;
      }
      FUN_0062e650(param_1 + 8,0xffffffff);
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x98) & 0x10) == 0) {
        uVar11 = FUN_0062a6a0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa));
        if ((uVar11 & 4) == 0) {
          pcVar15 = "Swipe";
        }
        else {
          pcVar15 = "WhipSwish";
        }
        FUN_00681f40(pcVar15,param_1 + 0x80);
      }
      if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x20) == 0) {
        uVar11 = *(uint *)(param_1 + 0xe20);
        if (((uVar11 & 0x10000) == 0) && (*(char *)(param_1 + 0xe33) != '\x01')) {
          iVar7 = 0;
        }
        else {
          iVar7 = 1;
        }
        *(uint *)(param_1 + 0xe20) = (iVar7 << 0x1e ^ uVar11) & 0x40000000 ^ uVar11;
        FUN_0058d8e0(param_1);
      }
      else {
        *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x40000000;
        FUN_0058d430(param_1);
      }
      iVar7 = *(int *)(param_1 + 0x790);
      if ((iVar7 != 0) && (*(char *)(param_1 + 0x7b7) != -1)) {
        *(undefined1 *)(iVar7 + 0x7b5) = 0x30;
        cVar2 = *(char *)(param_1 + 0x7b7);
        *(char *)(iVar7 + 0x7b7) = cVar2;
        *(int *)(iVar7 + 0x790) = param_1;
        sVar4 = FUN_0058aee0((int)cVar2);
        *(short *)(iVar7 + 0x7aa) = sVar4;
        fVar14 = (float10)FUN_0062e040((int)*(short *)(iVar7 + 0x1064),(int)sVar4,0,0,0);
        *(float *)(iVar7 + 0x77c) = (float)fVar14;
        FUN_0062e650(iVar7 + 8,0xffffffff);
        sVar4 = FUN_005be2d0(*(float *)(iVar7 + 0x5c) - *(float *)(param_1 + 0x5c),
                             *(float *)(iVar7 + 100) - *(float *)(param_1 + 100));
        *(short *)(param_1 + 0x5a) = sVar4;
        *(short *)(iVar7 + 0x5a) = sVar4 + -0x8000;
        return;
      }
    }
  }
switchD_0049f268_caseD_7:
  return;
}

