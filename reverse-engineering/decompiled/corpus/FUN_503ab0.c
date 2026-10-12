/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x503ab0; label: FUN_00503ab0
 */

void FUN_00503ab0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (((DAT_00921310 != 0) && (DAT_009213d4 != 0)) && (DAT_00921330 != 0)) {
    DAT_02854d1c = DAT_02854d1c + 1;
    FUN_00600b20(0);
    FUN_00607d70(0x10,5,0);
    iVar4 = DAT_00921310 - DAT_00921330;
    if (DAT_00921334 == 0) {
      fVar1 = (float)iVar4;
      if (iVar4 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      fVar1 = 580.0 / fVar1;
      FUN_00500020();
      FUN_006009e0(0x41f00000,0x434e0000,0);
      FUN_00500020();
      FUN_006009e0(0x44188000,0x43520000,0);
      puVar6 = DAT_00921308 + DAT_009213d4 * 4;
      for (puVar7 = DAT_00921308; puVar7 < puVar6; puVar7 = puVar7 + 4) {
        if ((*(byte *)(puVar7 + 3) & 4) != 0) {
          iVar5 = (*DAT_00921338)(*puVar7);
          iVar4 = *(int *)(iVar5 + 0x58);
          fVar2 = (float)(iVar4 - DAT_00921330);
          if (iVar4 - DAT_00921330 < 0) {
            fVar2 = fVar2 + 4.2949673e+09;
          }
          iVar4 = (*(int *)(iVar4 + 0x58) - DAT_00921330) + iVar4;
          fVar3 = (float)iVar4;
          if (iVar4 < 0) {
            fVar3 = fVar3 + 4.2949673e+09;
          }
          FUN_00500020();
          FUN_006009e0(fVar1 * fVar2 + 30.0,0x434e0000,0);
          FUN_00500020();
          FUN_006009e0(fVar3 * fVar1 + 30.0,0x43520000,0);
          fVar2 = (float)(iVar5 - DAT_00921330);
          if (iVar5 - DAT_00921330 < 0) {
            fVar2 = fVar2 + 4.2949673e+09;
          }
          iVar5 = (*(int *)(iVar5 + 0xf0) - DAT_00921330) + iVar5;
          fVar3 = (float)iVar5;
          if (iVar5 < 0) {
            fVar3 = fVar3 + 4.2949673e+09;
          }
          FUN_00500020();
          FUN_006009e0(fVar1 * fVar2 + 30.0,0x434e0000,0);
          FUN_00500020();
          FUN_006009e0(fVar3 * fVar1 + 30.0,0x43520000,0);
        }
      }
    }
    else {
      fVar1 = (float)iVar4;
      if (iVar4 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      FUN_00500020();
      FUN_006009e0(0x41f00000,0x434e0000,0);
      FUN_00500020();
      FUN_006009e0(0x44188000,0x43500000,0);
      puVar6 = DAT_00921308 + DAT_009213d4 * 4;
      for (puVar7 = DAT_00921308; puVar7 < puVar6; puVar7 = puVar7 + 4) {
        if ((*(byte *)(puVar7 + 3) & 4) != 0) {
          iVar4 = (*DAT_00921338)(*puVar7);
          iVar4 = *(int *)(iVar4 + 0x58);
          fVar2 = (float)(iVar4 - DAT_00921330);
          if (iVar4 - DAT_00921330 < 0) {
            fVar2 = fVar2 + 4.2949673e+09;
          }
          iVar4 = (*(int *)(iVar4 + 0x58) - DAT_00921330) + iVar4;
          fVar3 = (float)iVar4;
          if (iVar4 < 0) {
            fVar3 = fVar3 + 4.2949673e+09;
          }
          FUN_00500020();
          FUN_006009e0((580.0 / fVar1) * fVar2 + 30.0,0x434e0000,0);
          FUN_00500020();
          FUN_006009e0(fVar3 * (580.0 / fVar1) + 30.0,0x43500000,0);
        }
      }
      fVar1 = (float)(DAT_0092132c - DAT_00921334);
      if (DAT_0092132c - DAT_00921334 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      FUN_00500020();
      FUN_006009e0(0x41f00000,0x43510000,0);
      FUN_00500020();
      FUN_006009e0(0x44188000,0x43530000,0);
      for (puVar7 = DAT_00921308; puVar7 < puVar6; puVar7 = puVar7 + 4) {
        if ((*(byte *)(puVar7 + 3) & 4) != 0) {
          iVar4 = (*DAT_00921338)(*puVar7);
          fVar2 = (float)(iVar4 - DAT_00921334);
          if (iVar4 - DAT_00921334 < 0) {
            fVar2 = fVar2 + 4.2949673e+09;
          }
          iVar4 = (*(int *)(iVar4 + 0xf0) - DAT_00921334) + iVar4;
          fVar3 = (float)iVar4;
          if (iVar4 < 0) {
            fVar3 = fVar3 + 4.2949673e+09;
          }
          FUN_00500020();
          FUN_006009e0((580.0 / fVar1) * fVar2 + 30.0,0x43510000,0);
          FUN_00500020();
          FUN_006009e0(fVar3 * (580.0 / fVar1) + 30.0,0x43530000,0);
        }
      }
    }
    FUN_006009a0();
    DAT_02854d1c = DAT_02854d1c + -1;
    FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
  }
  return;
}

