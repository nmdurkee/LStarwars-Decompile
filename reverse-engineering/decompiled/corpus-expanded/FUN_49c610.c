/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49c610; label: FUN_0049c610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c610(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  int unaff_EDI;
  byte bVar9;
  float10 fVar10;
  
  if (*(char *)(unaff_EDI + 0x7b5) != '8') {
    return;
  }
  fVar1 = *(float *)(unaff_EDI + 0x77c);
  fVar2 = _DAT_00925018 + *(float *)(unaff_EDI + 0x77c);
  *(float *)(unaff_EDI + 0x77c) = fVar2;
  if ((*(float *)(unaff_EDI + 0x784) < fVar2 != (*(float *)(unaff_EDI + 0x784) == fVar2)) ||
     ((sVar3 = *(short *)(unaff_EDI + 0x7aa), sVar3 != 0x1f && (*(int *)(unaff_EDI + 0x790) == 0))))
  {
    *(undefined1 *)(unaff_EDI + 0x7b5) = 0xff;
    return;
  }
  iVar4 = *(int *)(unaff_EDI + 0x790);
  if (iVar4 == 0) {
    return;
  }
  if ((*(byte *)(unaff_EDI + 0x7bc) & 0x40) != 0) {
    return;
  }
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x50) + 0xc) + sVar3 * 4) == 0) {
    fVar5 = *(float *)(unaff_EDI + 0x784) * 0.5;
    if (fVar5 <= fVar1) {
      return;
    }
    bVar9 = fVar5 < fVar2 | (byte)((ushort)((ushort)(fVar5 == fVar2) << 0xe) >> 8);
  }
  else {
    pfVar6 = (float *)FUN_0062f150(unaff_EDI + 8,(int)sVar3,1,0);
    if (pfVar6 == (float *)0x0) {
      return;
    }
    fVar10 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_EDI + 0x50),
                                   (int)*(short *)(unaff_EDI + 0x7aa),1);
    if ((float)fVar10 < 1.0) {
      return;
    }
    if (*pfVar6 < (float)fVar10) {
      return;
    }
    fVar10 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_EDI + 0x50),
                                   (int)*(short *)(unaff_EDI + 0x7aa),2);
    fVar1 = (float)fVar10;
    if (fVar1 < 1.0) {
      return;
    }
    bVar9 = *pfVar6 < fVar1 | (byte)((ushort)((ushort)(*pfVar6 == fVar1) << 0xe) >> 8);
  }
  if (((POPCOUNT(bVar9) & 1U) != 0) &&
     ((((iVar7 = (int)*(char *)(*(int *)(*(int *)(unaff_EDI + 0x54) + 0x24) + 0xf8),
        *(char *)(unaff_EDI + 0x28c) == '\0' || (iVar7 == -1)) ||
       (*(int *)(*(int *)(unaff_EDI + 0x50) + 0x14 + iVar7 * 4) == 0)) ||
      (fVar10 = (float10)FUN_005b3c50(iVar7 * 0x40 + 0x834 + unaff_EDI,iVar4 + 0x80,0),
      fVar10 <= (float10)0.4899999797344208)))) {
    if ((*(short *)(iVar4 + 0x1064) == DAT_007f1884) && (*(short *)(unaff_EDI + 0x7aa) == 0x1f)) {
      *(uint *)(unaff_EDI + 0x7bc) = *(uint *)(unaff_EDI + 0x7bc) | 0x40;
      if ((*(char *)(iVar4 + 0x7b5) == '\x1c') && (*(int *)(iVar4 + 0x790) != 0)) {
        *(undefined4 *)(*(int *)(iVar4 + 0x790) + 0x790) = 0;
      }
      FUN_0055e4a0(iVar4,1);
      FUN_0055e4e0(iVar4 + 0x6c4);
      *(undefined1 *)(iVar4 + 0x7b5) = 0x39;
      *(undefined2 *)(iVar4 + 0x7aa) = 5;
      *(int *)(iVar4 + 0x790) = iVar4;
      *(undefined4 *)(iVar4 + 0xd10) = 0;
      FUN_00548460(iVar4);
      *(uint *)(unaff_EDI + 0xe24) = *(uint *)(unaff_EDI + 0xe24) | 1;
      return;
    }
    if ((*(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x8000) == 0) {
      *(uint *)(unaff_EDI + 0x7bc) = *(uint *)(unaff_EDI + 0x7bc) | 0x40;
      FUN_00547930(0x4a,(float *)(iVar4 + 0x80),0,0);
      DAT_00955574 = 1;
      FUN_00438230();
      uVar8 = FUN_005be2d0(*(float *)(iVar4 + 0x80) - *(float *)(unaff_EDI + 0x80),
                           *(float *)(iVar4 + 0x88) - *(float *)(unaff_EDI + 0x88));
      fVar1 = *(float *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x18);
      fVar2 = (float)(&DAT_029899a0)[(int)((uVar8 & 0xffff) + 0x4000) >> 1 & 0x7fff];
      *(float *)(iVar4 + 0x68) =
           *(float *)(iVar4 + 0x68) + fVar1 * (float)(&DAT_029899a0)[(uVar8 & 0xffff) >> 1];
      *(float *)(iVar4 + 0x70) = fVar1 * fVar2 + *(float *)(iVar4 + 0x70);
      return;
    }
  }
  return;
}

