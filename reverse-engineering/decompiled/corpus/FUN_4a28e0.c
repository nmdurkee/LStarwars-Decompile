/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a28e0; label: FUN_004a28e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a28e0(int param_1)

{
  ushort *puVar1;
  float fVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  bool bVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  int unaff_EDI;
  
  if (*(char *)(unaff_EDI + 0x7b5) != '\x1b') {
    return;
  }
  FUN_004399e0();
  if ((*(byte *)(*(int *)(unaff_EDI + 0xca4) + 0x5a) & 0x10) != 0) {
    param_1 = 1;
  }
  *(uint *)(unaff_EDI + 0xe20) = *(uint *)(unaff_EDI + 0xe20) | 0x20000;
  iVar13 = *(int *)(unaff_EDI + 0x790);
  if (iVar13 != 0) {
    if (*(char *)(iVar13 + 0x7b5) == '\x0f') {
LAB_004a293e:
      *(undefined4 *)(unaff_EDI + 0x790) = 0;
      FUN_004a1f50();
    }
    else if ((((*(uint *)(iVar13 + 0x1fc) & 1) == 0) || ((*(uint *)(iVar13 + 0x1fc) & 0x1000) == 0))
            || (*(char *)(iVar13 + 0x28b) != '\0')) {
      *(undefined4 *)(unaff_EDI + 0x790) = 0;
    }
    else if (((*(uint *)(unaff_EDI + 0xe20) & 0x600) == 0) && (*(char *)(iVar13 + 0x7b5) != '\x1c'))
    goto LAB_004a293e;
  }
  iVar5 = *(int *)(unaff_EDI + 0x790);
  if (iVar5 != 0) {
    FUN_0058bfb0();
    FUN_0058bfb0(iVar5);
    if ((*(uint *)(unaff_EDI + 0xe20) & 0x400) == 0) {
      if (iVar5 != 0) {
        iVar8 = FUN_0054fa60(0);
        FUN_0054a850(**(undefined4 **)(iVar5 + 0xca4),(float)iVar8 * 1.5259022e-05 * 0.4);
        if ((*(uint *)(unaff_EDI + 0xe20) & 0x100) != 0) {
          FUN_004a26b0();
        }
      }
      *(int *)(unaff_EDI + 0xd18) = iVar5;
      *(undefined1 *)(unaff_EDI + 0xe2d) = 2;
      if (((*(char *)(iVar5 + 0x7b5) != '\x1c') ||
          ((*(byte *)(*(int *)(iVar5 + 0x54) + 4) & 0x20) != 0)) ||
         ((*(int *)(*(int *)(*(int *)(iVar5 + 0x50) + 0xc) + *(short *)(iVar5 + 0x7aa) * 4) == 0 ||
          (iVar8 = FUN_0062f1a0(iVar5 + 8), iVar8 == *(short *)(iVar5 + 0x7aa))))) {
        *(float *)(unaff_EDI + 0x77c) = _DAT_00925018 + *(float *)(unaff_EDI + 0x77c);
      }
      iVar8 = FUN_0054fa60(0);
      FUN_0054a850(**(undefined4 **)(unaff_EDI + 0xca4),(float)iVar8 * 1.5259022e-05 * 0.4);
      uVar12 = *(uint *)(unaff_EDI + 0xe20);
      fVar2 = _DAT_007fc068;
      if ((((uVar12 & 0x200) == 0) && (fVar2 = _DAT_007fc064, -1 < (char)uVar12)) &&
         ((uVar12 & 0x100) == 0)) {
        fVar2 = _DAT_007fc060;
      }
      bVar6 = false;
      *(undefined1 *)(unaff_EDI + 0x7b3) = 0;
      if ((((*(byte *)(unaff_EDI + 0x1fc) & 0x80) != 0) &&
          ((*(uint *)(unaff_EDI + 0x1f8) & 0x40000) == 0)) &&
         ((((DAT_0087b904 != 0 &&
            (((*(byte *)(iVar5 + 0x1fc) & 0x80) == 0 && (0.2 <= *(float *)(unaff_EDI + 0x77c))))) &&
           (0.0 < *(float *)(*(int *)(unaff_EDI + 0xca4) + 0x28))) &&
          (((uVar9 = uVar12 >> 8 & 1, uVar9 == 0 ||
            ((*(uint *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x90) & 0x4000) == 0)) &&
           (((char)uVar12 < '\0' || (uVar9 != 0)))))))) {
        *(undefined1 *)(unaff_EDI + 0x7b3) = 1;
        *(float *)(unaff_EDI + 0x748) =
             *(float *)(unaff_EDI + 0x5c) +
             (float)(&DAT_029899a0)[*(ushort *)(unaff_EDI + 0x58) >> 1] * 0.5;
        *(float *)(unaff_EDI + 0x74c) =
             (*(float *)(unaff_EDI + 0x188) - *(float *)(unaff_EDI + 0x17c)) * 0.75 +
             *(float *)(unaff_EDI + 0x17c);
        *(float *)(unaff_EDI + 0x750) =
             (float)(&DAT_029899a0)[(int)(*(ushort *)(unaff_EDI + 0x58) + 0x4000) >> 1 & 0x7fff] *
             0.5 + *(float *)(unaff_EDI + 100);
        uVar10 = FUN_005be2d0(*(float *)(iVar5 + 0x5c) - *(float *)(unaff_EDI + 0x5c),
                              *(float *)(iVar5 + 100) - *(float *)(unaff_EDI + 100));
        uVar11 = FUN_0054b3d0();
        uVar12 = FUN_00550040(uVar11,uVar10);
        if ((int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f)) < 0xaaa) {
          bVar6 = true;
        }
        else if (fVar2 - 0.3 <= *(float *)(unaff_EDI + 0x77c)) {
          *(float *)(unaff_EDI + 0x77c) = fVar2 - 0.3;
        }
      }
      if ((fVar2 < *(float *)(unaff_EDI + 0x77c) != (fVar2 == *(float *)(unaff_EDI + 0x77c))) ||
         ((((-1 < (char)*(uint *)(unaff_EDI + 0xe20) &&
            ((*(uint *)(unaff_EDI + 0xe20) & 0x300) == 0)) && (0.2 <= *(float *)(unaff_EDI + 0x77c))
           ) && ((*(char *)(iVar13 + 0x1078) != '\0' &&
                 (ABS(*(float *)(iVar13 + 0x6b8)) < DAT_02996ef4)))))) {
        if (bVar6) {
          *(undefined1 *)(unaff_EDI + 0x7b5) = 0xff;
          *(undefined4 *)(unaff_EDI + 0x790) = 0;
          puVar1 = (ushort *)(*(int *)(unaff_EDI + 0xca4) + 0x5a);
          *puVar1 = *puVar1 & 0xffef;
          *(undefined4 *)(unaff_EDI + 0xd20) = 0;
          *(undefined4 *)(iVar5 + 0x790) = 0;
          FUN_004a1f50(iVar5,0);
          if (bVar6) {
            FUN_00681f40("JForcePush",unaff_EDI + 0x80);
            FUN_0054aa10();
            FUN_005483e0(iVar5);
            FUN_00549bb0(0,0x3f400000,0x3f400000,0x3f800000);
            *(undefined1 *)(iVar5 + 0x7b5) = 0x5f;
            iVar13 = *(int *)(*(int *)(iVar5 + 0x50) + 0xc);
            if (*(int *)(iVar13 + 0x2e0) == 0) {
              if (*(int *)(iVar13 + 0x14) != 0) {
                *(undefined2 *)(iVar5 + 0x7aa) = 5;
              }
            }
            else {
              *(undefined2 *)(iVar5 + 0x7aa) = 0xb8;
              FUN_0062e650(iVar5 + 8,0xffffffff);
            }
            *(undefined1 *)(iVar5 + 0x107f) = 1;
            *(undefined4 *)(iVar5 + 0x77c) = 0;
            *(undefined4 *)(iVar5 + 0x784) = 0x40000000;
            iVar13 = FUN_005be2d0(*(float *)(iVar5 + 0x80) - *(float *)(unaff_EDI + 0x80),
                                  *(float *)(iVar5 + 0x88) - *(float *)(unaff_EDI + 0x88));
            iVar8 = FUN_0054fa60();
            fVar7 = ((float)iVar8 * 1.5259022e-05 * 0.4 + 0.8) * _DAT_007fc04c;
            *(float *)(iVar5 + 0x748) = fVar7 * (float)(&DAT_029899a0)[iVar13 >> 1 & 0x7fff];
            fVar2 = (float)(&DAT_029899a0)[iVar13 + 0x4000 >> 1 & 0x7fff];
            *(uint *)(iVar5 + 0x7bc) = *(uint *)(iVar5 + 0x7bc) & 0xfffffeff;
            *(float *)(iVar5 + 0x750) = fVar7 * fVar2;
            iVar13 = FUN_0054fa60();
            *(float *)(iVar5 + 0x6c) = ((float)iVar13 * 1.5259022e-05 * 0.4 + 0.8) * _DAT_007fc050;
            cVar3 = *(char *)(unaff_EDI + 0x280);
            if ((cVar3 == '\0') || (cVar3 == '\x01')) {
              *(char *)(iVar5 + 0x7bb) = cVar3;
            }
            else {
              *(undefined1 *)(iVar5 + 0x7bb) = 0xff;
            }
            FUN_00414ab0(iVar5,0x3ecccccd);
            *(undefined4 *)(unaff_EDI + 0x784) = 0;
            FUN_00549f10();
            goto LAB_004a30ed;
          }
        }
        else {
          uVar12 = *(uint *)(unaff_EDI + 0xe20) >> 9 & 1;
          if (((uVar12 == 0) && (*(short *)(iVar5 + 0x1064) != DAT_007f1a50)) &&
             (((*(byte *)(*(int *)(iVar5 + 0x54) + 4) & 0x10) == 0 ||
              (*(byte *)(iVar5 + 0x107e) < 2)))) {
            if (((DAT_0093b2a4 == 0) || ((*(uint *)(unaff_EDI + 0xe20) & 0x100) == 0)) ||
               ((*(uint *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x90) & 0x4000) == 0)) {
              bVar6 = false;
            }
            else {
              bVar6 = true;
            }
            iVar13 = FUN_00438230();
            if (((iVar13 != 2) && ((*(byte *)(unaff_EDI + 0xe20) & 0x80) != 0)) && (!bVar6)) {
              *(undefined4 *)(iVar5 + 0xdac) = 0x3e4ccccd;
            }
            iVar13 = *(int *)(unaff_EDI + 0x790);
            if (iVar13 != 0) {
              *(undefined4 *)(iVar13 + 0x790) = 0;
              FUN_004a1f50(iVar13,0);
            }
            *(undefined4 *)(unaff_EDI + 0x790) = 0;
            puVar1 = (ushort *)(*(int *)(unaff_EDI + 0xca4) + 0x5a);
            *puVar1 = *puVar1 & 0xffef;
            *(undefined4 *)(unaff_EDI + 0x784) = 0;
            *(undefined4 *)(unaff_EDI + 0xd20) = 0;
            FUN_00549f10();
            goto LAB_004a30ed;
          }
          if (uVar12 == 0) {
            FUN_00432620(iVar5,_DAT_00804b04,0);
          }
          else {
            iVar13 = FUN_00432620(iVar5,0x40a00000,0);
            if (iVar13 != 0) {
              *(undefined1 *)(iVar5 + 0x7b8) = 1;
              iVar13 = FUN_0054fa60();
              *(float *)(iVar5 + 0x778) = (float)iVar13 * 1.5259022e-05 * 0.3 + 0.2;
              if (*(short *)(iVar5 + 0x1064) == DAT_007f197c) {
                FUN_00681f40("Jawa_Dizzy",iVar5 + 0x80);
              }
            }
          }
          FUN_0054a8a0(**(undefined4 **)(unaff_EDI + 0xca4),0x3dcccccd,0);
          FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
        }
        *(undefined4 *)(unaff_EDI + 0x784) = 0;
        FUN_00549f10();
      }
    }
    else {
      *(int *)(unaff_EDI + 0xd18) = iVar5;
      *(undefined1 *)(unaff_EDI + 0xe2d) = 2;
      if ((iVar5 != 0) && ((*(uint *)(unaff_EDI + 0xe20) & 0x100) != 0)) {
        FUN_004a26b0();
      }
    }
  }
LAB_004a30ed:
  fVar2 = *(float *)(unaff_EDI + 0x784);
  if (((NAN(fVar2) || 0.2 < fVar2 == (fVar2 == 0.2)) || (param_1 == 0)) ||
     (*(int *)(unaff_EDI + 0x790) == 0)) {
    if (((*(uint *)(unaff_EDI + 0x1f8) & 0x40000) == 0) &&
       (fVar2 = *(float *)(unaff_EDI + 0x784) - _DAT_00925018, *(float *)(unaff_EDI + 0x784) = fVar2
       , fVar2 <= 0.0)) {
      iVar13 = *(int *)(unaff_EDI + 0x790);
      if ((((0.4 <= *(float *)(unaff_EDI + 0x77c)) &&
           ((iVar13 != 0 && ((*(byte *)(iVar13 + 0x1fc) & 1) != 0)))) &&
          (*(char *)(iVar13 + 0x28b) == '\0')) &&
         ((((*(char *)(*(int *)(*(int *)(iVar13 + 0x54) + 0x24) + 0x116) == '\x04' ||
            (sVar4 = *(short *)(iVar13 + 0x1064), sVar4 == DAT_007f1894)) || (sVar4 == DAT_007f1a50)
           ) || ((sVar4 == DAT_007f18b8 || (sVar4 == DAT_007f1a78)))))) {
        FUN_00432620(iVar13,_DAT_00804b04 * 0.5,0);
        FUN_0054a850(**(undefined4 **)(unaff_EDI + 0xca4),0x3f000000,0);
      }
      FUN_004a25b0();
      if (((*(byte *)(unaff_EDI + 0xe20) & 0x80) != 0) && (iVar13 != 0)) {
        *(undefined4 *)(iVar13 + 0xdac) = 0x3e4ccccd;
      }
    }
  }
  else {
    fVar2 = *(float *)(unaff_EDI + 0x784) - _DAT_00925018;
    *(float *)(unaff_EDI + 0x784) = fVar2;
    if (fVar2 < 0.2 != (fVar2 == 0.2)) {
      *(undefined4 *)(unaff_EDI + 0x784) = 0x3e4ccccd;
      return;
    }
  }
  return;
}

