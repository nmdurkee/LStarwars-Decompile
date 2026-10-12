/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a69e0; label: FUN_004a69e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a69e0(void)

{
  short sVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  
  if (*(char *)(unaff_ESI + 0x7b5) == '\x14') {
    pfVar3 = (float *)FUN_0062f150(unaff_ESI + 8,(int)*(short *)(unaff_ESI + 0x7aa),1,0);
    if (pfVar3 != (float *)0x0) {
      if ((*(uint *)(unaff_ESI + 0xe20) & 0x40000) == 0) {
        fVar5 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_ESI + 0x50),
                                      (int)*(short *)(unaff_ESI + 0x7aa),0);
        if ((1.0 <= (float)fVar5) && ((float)fVar5 <= *pfVar3)) {
          *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) | 0x40010;
          FUN_00681f40("JgRocket",unaff_ESI + 0x80);
        }
      }
      fVar2 = *(float *)(unaff_ESI + 0x77c) - _DAT_00925018;
      *(float *)(unaff_ESI + 0x77c) = fVar2;
      if (fVar2 <= 0.0) {
        *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
      }
    }
  }
  else if (((((*(char *)(unaff_ESI + 0x7b5) == -1) &&
             ((*(uint *)(*(int *)(unaff_ESI + 0xca4) + 8) & DAT_00802284) != 0)) &&
            (((*(uint *)(*(int *)(unaff_ESI + 0x54) + 4) & 0x1000000) != 0 ||
             (*(char *)(unaff_ESI + 0x1082) == '\x06')))) &&
           ((iVar4 = (int)*(char *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x10c),
            iVar4 != -1 && (*(int *)(*(int *)(unaff_ESI + 0x50) + 0x14 + iVar4 * 4) != 0)))) &&
          ((*(char *)(unaff_ESI + 0x280) == -1 ||
           (((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0 && (iVar4 = FUN_0056e160(0x27), iVar4 != 0))
           )))) {
    if (*(float *)(unaff_ESI + 0xd60) == 2.0) {
      *(undefined4 *)(unaff_ESI + 0xd60) = 0;
      FUN_005618e0(2,1,0xffffffff,0);
    }
    sVar1 = (-(ushort)(*(char *)(unaff_ESI + 0x281) != '\0') & 0xffb5) + 0x4d;
    *(short *)(unaff_ESI + 0x7aa) = sVar1;
    fVar5 = (float10)FUN_0062e040((int)*(short *)(unaff_ESI + 0x1064),(int)sVar1,0,0,1);
    *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) & 0xfffbffff;
    *(float *)(unaff_ESI + 0x77c) = (float)fVar5;
    if (0.0 < *(float *)(unaff_ESI + 0x77c)) {
      *(undefined1 *)(unaff_ESI + 0x7b5) = 0x14;
      return;
    }
  }
  return;
}

