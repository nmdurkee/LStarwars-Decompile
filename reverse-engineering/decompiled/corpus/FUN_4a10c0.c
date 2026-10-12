/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a10c0; label: FUN_004a10c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a10c0(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  bool bVar7;
  int in_EAX;
  float *pfVar8;
  int iVar9;
  uint uVar10;
  float10 fVar11;
  
  *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xfffffffd;
  cVar2 = *(char *)(in_EAX + 0x7b5);
  uVar5 = *(uint *)(in_EAX + 0x7bc);
  if (cVar2 != '\x05') {
    if ((((((((param_1 == 0) || (cVar2 == '\x15')) || (cVar2 == 'Z')) ||
           (((cVar2 == '\x13' || (cVar2 == '.')) ||
            ((uVar10 = *(uint *)(in_EAX + 0x1fc) >> 7 & 1, uVar10 == 0 &&
             ((cVar2 == '\x06' || (cVar2 == '\a')))))))) || (cVar2 == '\b')) ||
         (((cVar2 == '\x1b' || (cVar2 == '-')) || (cVar2 == '\x0f')))) ||
        (((cVar2 == '\'' || (cVar2 == '(')) ||
         ((cVar2 == 'Y' || ((cVar2 == '0' || (cVar2 == '=')))))))) ||
       ((cVar2 == 'C' || (((cVar2 == 'J' || (cVar2 == 'a')) || (cVar2 == 'K')))))) {
      if (((((((*(byte *)(*(int *)(in_EAX + 0xca4) + 0x5a) & 4) != 0) || (param_4 != 0)) &&
            (((*(uint *)(in_EAX + 0xe20) & 0x10000) != 0 &&
             ((*(char *)(in_EAX + 0xe33) == '\0' && (cVar2 != '\x06')))))) && (cVar2 != '\a')) &&
          ((((cVar2 != '\x12' && (cVar2 != '\x1b')) && (cVar2 != '\x1d')) &&
           ((cVar2 != '\0' ||
            ((*(char *)(in_EAX + 0x7b8) != '\x03' && (*(char *)(in_EAX + 0x7b8) != '\x04')))))))) &&
         (((cVar2 != '\r' && ((cVar2 != '\x0e' && (cVar2 != '.')))) &&
          ((((*(uint *)(in_EAX + 0xe20) & 0x1000000) == 0 &&
            (uVar10 = *(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8), (uVar10 & 0x4000000) == 0)) &&
           ((((uVar10 & 0x8000000) == 0 || ((uVar5 & 0x20000) == 0)) && (cVar2 != '\b')))))))) {
        if ((*(char *)(in_EAX + 0x281) != '\0') &&
           (*(float *)(*(int *)(in_EAX + 0xca4) + 0x28) == 0.0)) {
          if ((*(char *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x116) != '\0') ||
             (iVar9 = 0x7e, (*(byte *)(*(int *)(in_EAX + 0x54) + 4) & 0x80) == 0)) {
            iVar9 = 0x10;
          }
          if ((*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + iVar9 * 4) != 0) &&
             ((cVar2 == -1 || ((uVar10 & 4) != 0)))) {
            FUN_0058da10();
            goto LAB_004a1c2e;
          }
        }
        FUN_0058d930();
      }
    }
    else {
      if ((*(uint *)(in_EAX + 0xe20) & 0x10000) == 0) {
        if (((*(char *)(in_EAX + 0xe33) == '\0') && (*(char *)(in_EAX + 0x281) != '\0')) &&
           (*(float *)(*(int *)(in_EAX + 0xca4) + 0x28) == 0.0)) {
          if ((*(char *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x116) != '\0') ||
             (iVar9 = 0x7f, (*(byte *)(*(int *)(in_EAX + 0x54) + 4) & 0x80) == 0)) {
            iVar9 = 0x11;
          }
          if ((*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + iVar9 * 4) != 0) &&
             (((cVar2 == -1 || (cVar2 == '\x01')) ||
              ((cVar2 == '\x02' || ((cVar2 == '\x04' || (cVar2 == '\x03')))))))) {
            FUN_0058d560();
            return;
          }
        }
        FUN_0058d480();
        return;
      }
      if (((((*(uint *)(in_EAX + 0xe20) & 4) == 0) &&
           (((uVar10 != 0 || (*(char *)(in_EAX + 0xe33) == '\0')) &&
            (*(char *)(in_EAX + 0x281) != '\0')))) &&
          (((cVar2 == -1 || (cVar2 == '\x01')) ||
           ((cVar2 == '\x02' ||
            (((cVar2 == '\x04' || (cVar2 == '\x03')) || ((cVar2 == '\x06' || (cVar2 == '\a')))))))))
          ) && ((((((FUN_0058d430(), *(int *)(in_EAX + 0xd04) == 0 &&
                    (*(int *)(in_EAX + 0xcfc) == 0)) && (*(int *)(in_EAX + 0xd00) == 0)) &&
                  (*(int *)(in_EAX + 0xcb0) == 0)) || (iVar9 = FUN_0049e370(), iVar9 == 0)) &&
                ((((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0 ||
                  (((*(byte *)(in_EAX + 0xef8) & 2) == 0 &&
                   ((*(byte *)(*(int *)(in_EAX + 0x54) + 4) & 4) != 0)))) ||
                 ((*(uint *)(in_EAX + 0xeec) & 0x400) != 0)))))) {
        FUN_0049d200(0x3f800000,1,0);
        *(undefined4 *)(in_EAX + 0xd4c) = 0;
        *(undefined1 *)(in_EAX + 0x7b5) = 5;
        *(undefined1 *)(in_EAX + 0x7b2) = 0;
        if (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0xd4) == 0) {
          *(undefined1 *)(in_EAX + 0xe41) = 1;
        }
        if (*(char *)(in_EAX + 0xe41) == '\0') {
          *(undefined1 *)(in_EAX + 0xe41) = 1;
          *(undefined2 *)(in_EAX + 0x7ac) = 0x35;
        }
        else {
          *(undefined1 *)(in_EAX + 0xe41) = 0;
          *(undefined2 *)(in_EAX + 0x7ac) = 0x2e;
        }
        *(undefined4 *)(in_EAX + 0xd3c) = 0x3f800000;
        *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x10040;
        *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xffffffa3;
        *(undefined4 *)(in_EAX + 0x6c) = 0;
        *(undefined1 *)(in_EAX + 0x7ae) = 0;
        *(undefined2 *)(in_EAX + 0x7aa) = *(undefined2 *)(in_EAX + 0x7ac);
        *(undefined1 *)(in_EAX + 0xe33) = 0;
        *(undefined1 *)(in_EAX + 0x7b0) = 0;
        if (*(short *)(in_EAX + 0x1064) != DAT_007f1878) {
          FUN_00548540(0);
        }
        if (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + *(short *)(in_EAX + 0x7aa) * 4) == 0)
        {
          *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
        }
      }
    }
    goto LAB_004a1c2e;
  }
  *(uint *)(in_EAX + 0xeec) = *(uint *)(in_EAX + 0xeec) | 0x800;
  if ((uVar5 & 4) != 0) {
    if (((param_1 == 0) && (*(char *)(in_EAX + 0x7b0) == '\0')) ||
       (bVar3 = *(byte *)(in_EAX + 0x7b2), 1 < bVar3)) {
      fVar1 = *(float *)(in_EAX + 0xd4c) - _DAT_00925018;
      *(float *)(in_EAX + 0xd4c) = fVar1;
      if (fVar1 <= 0.0) {
        *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
        *(uint *)(in_EAX + 0x7bc) = uVar5 | 2;
        if (param_2 != 0) {
          FUN_0058e3b0();
        }
      }
      else if (((*(byte *)(in_EAX + 0x7b2) < 2) && (param_3 != 0)) &&
              (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x48) != 0)) {
        FUN_0049d200(0x3f800000,0,1);
        FUN_0049e2b0(0);
      }
    }
    else if (bVar3 == 0) {
      FUN_0049d200(0x3f800000,1,0);
      *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xfffffffb;
      *(undefined1 *)(in_EAX + 0x7b2) = 1;
      if (*(short *)(in_EAX + 0x1064) != DAT_007f1878) {
        FUN_00548540(0);
      }
      if (((*(uint *)(in_EAX + 0xe20) & 0x40) != 0) &&
         (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 8 + *(short *)(in_EAX + 0x7ac) * 4) ==
          0)) {
        *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) & 0xffffffbf;
      }
      if ((*(byte *)(in_EAX + 0xe20) & 0x40) == 0) {
        *(undefined1 *)(in_EAX + 0x7ae) = 1;
        FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),0x3eb33333,0);
      }
      else {
        *(undefined1 *)(in_EAX + 0x7ae) = 2;
        FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),0x3f000000,0);
        if (*(short *)(in_EAX + 0x1064) != DAT_007f1878) {
          FUN_00548540("ComboSaber2");
        }
      }
      *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x40;
      *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xffffffaf;
      *(ushort *)(in_EAX + 0x7aa) = (ushort)*(byte *)(in_EAX + 0x7ae) + *(short *)(in_EAX + 0x7ac);
      *(undefined1 *)(in_EAX + 0x7b0) = 0;
    }
    else if (bVar3 == 1) {
      FUN_0049d200(0x3f800000,1,0);
      *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xfffffffb;
      *(undefined1 *)(in_EAX + 0x7b2) = 2;
      if (*(short *)(in_EAX + 0x1064) != DAT_007f1878) {
        FUN_00548540(0);
      }
      FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),0x3eb33333,0);
      uVar5 = *(uint *)(in_EAX + 0xe20);
      if (*(char *)(in_EAX + 0x7ae) == '\x01') {
        if (((uVar5 & 0x40) != 0) &&
           (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x10 + *(short *)(in_EAX + 0x7ac) * 4
                    ) == 0)) {
          *(uint *)(in_EAX + 0xe20) = uVar5 & 0xffffffbf;
        }
        *(char *)(in_EAX + 0x7ae) = ((*(byte *)(in_EAX + 0xe20) & 0x40) != 0) + '\x03';
      }
      else {
        if (((uVar5 & 0x40) != 0) &&
           (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x18 + *(short *)(in_EAX + 0x7ac) * 4
                    ) == 0)) {
          *(uint *)(in_EAX + 0xe20) = uVar5 & 0xffffffbf;
        }
        if ((*(byte *)(in_EAX + 0xe20) & 0x40) == 0) {
          *(undefined1 *)(in_EAX + 0x7ae) = 5;
        }
        else {
          *(undefined1 *)(in_EAX + 0x7ae) = 6;
          FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),0x3f19999a,0);
          if (*(short *)(in_EAX + 0x1064) != DAT_007f1878) {
            FUN_00548540("ComboSaber1");
          }
        }
      }
      *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x40;
      *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) & 0xffffffaf;
      *(ushort *)(in_EAX + 0x7aa) = (ushort)*(byte *)(in_EAX + 0x7ae) + *(short *)(in_EAX + 0x7ac);
      *(undefined1 *)(in_EAX + 0x7b0) = 0;
    }
    goto LAB_004a1c2e;
  }
  sVar4 = *(short *)(in_EAX + 0x7aa);
  if (((*(short *)(in_EAX + 0x3e) == sVar4) && (*(char *)(in_EAX + 0x39) == '\0')) &&
     (*(short *)(in_EAX + 0x42) == sVar4)) {
    if (*(char *)(in_EAX + 0x7b2) != '\x02') {
      if ((*(byte *)(in_EAX + 0x38) & 1) == 0) goto LAB_004a16a7;
      if (*(char *)(in_EAX + 0x7b2) != '\x02') {
        if ((*(byte *)(in_EAX + 0x38) & 1) != 0) {
          *(undefined4 *)(in_EAX + 0xd4c) = 0x3e4ccccd;
          *(uint *)(in_EAX + 0x7bc) = uVar5 | 4;
          FUN_0058e040();
          *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) | 2;
          if ((*(byte *)(in_EAX + 0x7bc) & 0x40) == 0) {
            FUN_0058e360();
          }
        }
        goto LAB_004a1c2e;
      }
    }
    pfVar8 = (float *)FUN_0062f250(*(undefined4 *)(in_EAX + 0x50),(int)sVar4);
    if ((((*(byte *)(in_EAX + 0x7bc) & 0x40) == 0) && (0.0 < *pfVar8)) &&
       (*pfVar8 <= *(float *)(in_EAX + 8))) {
      FUN_0058e360();
    }
    if ((0.0 < pfVar8[1]) && (pfVar8[1] <= *(float *)(in_EAX + 8))) {
      *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) | 8;
    }
    if ((*(byte *)(in_EAX + 0x38) & 1) == 0) {
      fVar1 = *(float *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 8) +
                                 *(short *)(in_EAX + 0x7aa) * 4) + 0x14);
      if ((0.0 < fVar1) &&
         (fVar11 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),
                                         (int)*(short *)(in_EAX + 0x7aa),*(undefined4 *)(in_EAX + 8)
                                         ,0,0), fVar11 < (float10)fVar1)) {
        *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) | 2;
        *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
      }
    }
    else {
      *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) | 2;
      *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
    }
    *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) | 2;
    if (((*(uint *)(in_EAX + 0x7bc) & 0x40) == 0) &&
       ((((*(uint *)(in_EAX + 0x7bc) & 8) != 0 &&
         (fVar11 = (float10)FUN_0062f1f0(*(undefined4 *)(in_EAX + 0x50),
                                         (int)*(short *)(in_EAX + 0x7aa),0), fVar11 == (float10)0.0)
         ) || ((*(byte *)(in_EAX + 0x7bc) & 2) != 0)))) {
      FUN_0058e360();
    }
    if (((*(char *)(in_EAX + 0x7b5) == -1) && (param_2 != 0)) &&
       ((*(short *)(in_EAX + 0x1064) != DAT_007f1878 || (*(char *)(in_EAX + 0x7b2) != '\x02')))) {
      FUN_0058e3b0();
    }
    if (((*(byte *)(in_EAX + 0x7bc) & 0x40) != 0) && ((uVar5 >> 6 & 1) == 0)) {
      if (*(char *)(in_EAX + 0x7ae) == '\x06') {
        uVar6 = 0x3f333333;
      }
      else {
        uVar6 = 0x3eb33333;
      }
      FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),uVar6,0);
    }
  }
  else {
LAB_004a16a7:
    bVar7 = false;
    pfVar8 = (float *)FUN_0062f150(in_EAX + 8,(int)sVar4,1,0);
    if (pfVar8 != (float *)0x0) {
      if ((*(byte *)(in_EAX + 0x7bc) & 0x40) == 0) {
        fVar11 = (float10)FUN_0062f1f0(*(undefined4 *)(in_EAX + 0x50),
                                       (int)*(short *)(in_EAX + 0x7aa),0);
        if ((0.0 < (float)fVar11) && ((float)fVar11 <= *pfVar8)) {
          FUN_0058e360();
        }
      }
      if ((*(byte *)(in_EAX + 0x7bc) & 0x10) == 0) {
        fVar11 = (float10)FUN_0062f1f0(*(undefined4 *)(in_EAX + 0x50),
                                       (int)*(short *)(in_EAX + 0x7aa),1);
        if ((0.0 < (float)fVar11) && ((float)fVar11 <= *pfVar8)) {
          *(uint *)(in_EAX + 0x7bc) = *(uint *)(in_EAX + 0x7bc) | 0x10;
        }
      }
      fVar11 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),
                                     (int)*(short *)(in_EAX + 0x7aa),*pfVar8,0,0);
      if (fVar11 < (float10)0.10000000149011612) {
        *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x80000;
        bVar7 = true;
      }
    }
    if ((param_1 != 0) && (*(char *)(in_EAX + 0x7b0) == '\0')) {
      if (bVar7) {
        *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) | 3;
        *(undefined1 *)(in_EAX + 0x7b0) = 1;
        goto LAB_004a1c2e;
      }
      *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) & 0xffffffbf;
    }
    *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) | 3;
  }
LAB_004a1c2e:
  if ((((*(float *)(in_EAX + 0xd3c) == 1.0) && ((*(uint *)(in_EAX + 0xe20) & 0x80000) == 0)) &&
      (*(char *)(in_EAX + 0x7b5) == '\x05')) && ((*(byte *)(in_EAX + 0x7bc) & 4) != 0)) {
    *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x80000;
  }
  return;
}

