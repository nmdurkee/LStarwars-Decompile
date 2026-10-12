/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x5285f0; label: FUN_005285f0
 */

void FUN_005285f0(int param_1)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  int iVar9;
  float10 fVar10;
  undefined4 uVar11;
  
  iVar9 = 0;
  if (DAT_0092389c == (code *)0x0) {
    FUN_00621520();
    return;
  }
  for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x371a4); iVar3 != 0;
      iVar3 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar3)) {
    if ((*(int *)(iVar3 + 0x3c) != 0) &&
       (iVar4 = (*DAT_0092389c)((int)*(short *)(iVar3 + 0x58)), iVar4 != 0)) {
      iVar9 = iVar9 + 1;
    }
  }
  FUN_00621520(iVar9);
  iVar9 = FUN_004f1440(DAT_009238e4 + 0x371a4);
  do {
    if (iVar9 == 0) {
      return;
    }
    iVar3 = (*DAT_0092389c)((int)*(short *)(iVar9 + 0x58));
    if ((*(int *)(iVar9 + 0x3c) != 0) && (iVar3 != 0)) {
      FUN_00621440(iVar9 + 8,0x10);
      FUN_00621440(iVar9 + 0x18,0x10);
      if (DAT_0080171c < 0xe) {
        uVar11 = 0x10;
      }
      else {
        uVar11 = 0x20;
      }
      FUN_00621440(iVar3,uVar11);
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x28));
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x2c));
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x30));
      FUN_006215a0(*(undefined2 *)(iVar9 + 0x34));
      if (0xf < DAT_0080171c) {
        FUN_00621600(*(undefined1 *)(iVar9 + 0x5a));
      }
      FUN_00621600(*(undefined1 *)(iVar9 + 0x5b));
      FUN_00621600(*(undefined1 *)(iVar9 + 0x5c));
      FUN_00621520(*(undefined4 *)(iVar9 + 0x54));
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x60));
      FUN_006214d0(*(undefined4 *)(iVar9 + 100));
      FUN_00621520(*(undefined4 *)(iVar9 + 0x68));
      FUN_00621600(*(undefined1 *)(*(int *)(iVar9 + 0x3c) + 0x38));
      iVar3 = *(int *)(*(int *)(param_1 + 4) + *(char *)(*(int *)(iVar9 + 0x3c) + 0x38) * 4);
      uVar7 = (uint)*(ushort *)(iVar3 + 0x12);
      bVar8 = false;
      iVar6 = 0;
      iVar4 = 0;
      if (uVar7 != 0) {
        uVar2 = *(ushort *)(*(int *)(iVar9 + 0x40) + 0x90);
        pbVar5 = (byte *)(*(int *)(iVar3 + 0x80) + 0x11);
        do {
          iVar4 = iVar6;
          if ((pbVar5[-1] == uVar2) &&
             ((ushort)*pbVar5 == *(ushort *)(*(int *)(iVar9 + 0x44) + 0x90))) {
            uVar7 = (int)*(uint *)(iVar9 + 0x50) >> 0x1f;
            bVar8 = 0x3fff < (int)((*(uint *)(iVar9 + 0x50) ^ uVar7) - uVar7);
            goto LAB_00528832;
          }
          if (((ushort)pbVar5[-1] == *(ushort *)(*(int *)(iVar9 + 0x44) + 0x90)) &&
             (*pbVar5 == uVar2)) {
            uVar7 = (int)*(uint *)(iVar9 + 0x50) >> 0x1f;
            bVar8 = (int)((*(uint *)(iVar9 + 0x50) ^ uVar7) - uVar7) < 0x4000;
            goto LAB_00528832;
          }
          iVar6 = iVar6 + 1;
          pbVar5 = pbVar5 + 0x24;
        } while (iVar6 < (int)uVar7);
        bVar8 = false;
        iVar4 = 0;
      }
LAB_00528832:
      FUN_00621600(bVar8);
      FUN_006215a0(iVar4);
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x70));
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x74));
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x78));
      FUN_006214d0(*(undefined4 *)(iVar9 + 0x7c));
      if (*(int *)(iVar9 + 0x80) == 0) {
        FUN_00621520(0);
      }
      else {
        FUN_00621520(1);
        FUN_00621440(*(int *)(iVar9 + 0x80) + 8,0x10);
      }
      if (*(int *)(iVar9 + 0x84) == 0) {
        FUN_00621520(0);
      }
      else {
        FUN_00621520(1);
        FUN_00621440(*(int *)(iVar9 + 0x84) + 8,0x10);
      }
      if (0x10 < DAT_0080171c) {
        if (*(int *)(iVar9 + 0x88) == 0) {
          FUN_00621520(0);
        }
        else {
          FUN_00621520(1);
          FUN_00621440(*(int *)(iVar9 + 0x88) + 8,0x10);
        }
      }
      if (7 < DAT_0080171c) {
        FUN_00621600(*(undefined1 *)(iVar9 + 0x8c));
        FUN_00621600(*(undefined1 *)(iVar9 + 0x8d));
        FUN_00621600(*(undefined1 *)(iVar9 + 0x8e));
        FUN_00621600(*(undefined1 *)(iVar9 + 0x8f));
        FUN_006214d0(*(undefined4 *)(iVar9 + 0x90));
        FUN_006214d0(*(undefined4 *)(iVar9 + 0x94));
        if (9 < DAT_0080171c) {
          FUN_006214d0(*(undefined4 *)(iVar9 + 0x98));
        }
        if (*(char *)(iVar9 + 0x8f) == '\x01') {
          FUN_00621440(*(int *)(iVar9 + 0x6c) + 8,0x10);
        }
      }
      if (10 < DAT_0080171c) {
        if ((DAT_009238c8 == (code *)0x0) ||
           (fVar1 = *(float *)(iVar9 + 0x9c),
           fVar10 = (float10)(*DAT_009238c8)((int)*(short *)(iVar9 + 0x58)),
           fVar10 != (float10)fVar1)) {
          uVar11 = *(undefined4 *)(iVar9 + 0x9c);
        }
        else {
          uVar11 = 0;
        }
        FUN_006214d0(uVar11);
        if ((DAT_009238cc == (code *)0x0) ||
           (fVar1 = *(float *)(iVar9 + 0xa0),
           fVar10 = (float10)(*DAT_009238cc)((int)*(short *)(iVar9 + 0x58)),
           fVar10 != (float10)fVar1)) {
          uVar11 = *(undefined4 *)(iVar9 + 0xa0);
        }
        else {
          uVar11 = 0;
        }
        FUN_006214d0(uVar11);
        if ((DAT_009238d0 == (code *)0x0) ||
           (fVar1 = *(float *)(iVar9 + 0xa4),
           fVar10 = (float10)(*DAT_009238d0)((int)*(short *)(iVar9 + 0x58)),
           fVar10 != (float10)fVar1)) {
          uVar11 = *(undefined4 *)(iVar9 + 0xa4);
        }
        else {
          uVar11 = 0;
        }
        FUN_006214d0(uVar11);
        if ((DAT_009238d4 == (code *)0x0) ||
           (fVar1 = *(float *)(iVar9 + 0xa8),
           fVar10 = (float10)(*DAT_009238d4)((int)*(short *)(iVar9 + 0x58)),
           fVar10 != (float10)fVar1)) {
          uVar11 = *(undefined4 *)(iVar9 + 0xa8);
        }
        else {
          uVar11 = 0;
        }
        FUN_006214d0(uVar11);
        FUN_00621520(0);
      }
    }
    iVar9 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar9);
  } while( true );
}

