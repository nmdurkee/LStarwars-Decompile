/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61cd60; label: FUN_0061cd60
 */

int FUN_0061cd60(undefined4 param_1,int param_2,int param_3,float param_4,undefined4 param_5,
                int param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int *piVar13;
  bool bVar14;
  undefined8 uVar15;
  
  iVar4 = param_2;
  iVar2 = *(int *)(param_2 + 0x7c);
  iVar3 = *(int *)(param_2 + 0x80);
  iVar11 = iVar2 + -0x3c;
  bVar14 = DAT_02912eb8 == 0;
  iVar8 = iVar3 + -0x3c;
  iVar9 = param_3 + 0x1e;
  iVar10 = (int)param_4 + 0x1e;
  *(int *)(param_2 + 0x1c) = param_3;
  *(float *)(param_2 + 0x20) = param_4;
  if ((bVar14) &&
     (FUN_005db880(param_3 << 4,(int)param_4 * 8,iVar2 << 4,iVar3 * 8,0x80000000,DAT_02900c70),
     DAT_02912eb8 == 0)) {
    FUN_005db880(iVar9 * 0x10,iVar10 * 8,iVar11 * 0x10,iVar8 * 8,0x80100000,DAT_02900c70);
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    if ((DAT_02912eb8 == 0) && (FUN_005d0fb0(), DAT_02912eb8 == 0)) {
      FUN_005d1060(DAT_02912b38,0x80808080);
    }
    if (0.0 < *(float *)(param_2 + 0x84)) {
      iVar5 = FUN_006e6b90();
      param_2 = 1;
      iVar6 = FUN_006e6b90();
      if (0 < iVar6) {
        do {
          if (param_2 % (1 - iVar5) == 0) {
            if (DAT_02912eb8 == 0) {
              FUN_005d0fb0();
            }
            FUN_005d0e80(DAT_02912b38,"%1.01f",(double)((float)param_2 * *(float *)(iVar4 + 0x84)));
            FUN_006e6b90();
            FUN_006e6b90();
            FUN_00618310(DAT_02912b38);
            uVar12 = 0x80340000;
          }
          else {
            uVar12 = 0x80260000;
          }
          if (DAT_02912eb8 == 0) {
            iVar7 = FUN_006e6b90();
            FUN_005db5b0(iVar7 << 4,iVar10 * 8,iVar7 << 4,(iVar10 + iVar8) * 8 + -8,uVar12,
                         DAT_02900c70);
          }
          param_2 = param_2 + 1;
        } while (param_2 <= iVar6);
      }
    }
    if (0.0 < *(float *)(iVar4 + 0x88)) {
      iVar5 = FUN_006e6b90();
      param_2 = 1;
      iVar6 = FUN_006e6b90();
      if (0 < iVar6) {
        do {
          if (param_2 % (1 - iVar5) == 0) {
            if (DAT_02912eb8 == 0) {
              FUN_005d0fb0();
            }
            FUN_005d0e80(DAT_02912b38,"%1.01f",(double)((float)param_2 * *(float *)(iVar4 + 0x88)));
            FUN_006e6b90();
            FUN_006e6b90();
            FUN_00618310(DAT_02912b38);
            uVar12 = 0x80340000;
          }
          else {
            uVar12 = 0x80260000;
          }
          if (DAT_02912eb8 == 0) {
            iVar7 = FUN_006e6b90();
            FUN_005db5b0(iVar9 * 0x10,iVar7 * 8,(iVar11 + iVar9) * 0x10 + -0x10,iVar7 * 8,uVar12,
                         DAT_02900c70);
          }
          param_2 = param_2 + 1;
        } while (param_2 <= iVar6);
      }
    }
    if (DAT_02912eb8 == 0) {
      FUN_005d0fb0();
    }
    iVar5 = iVar4 + 0x90;
    FUN_005d0e80(DAT_02912b38,iVar5);
    iVar6 = FUN_006e6b90();
    uVar15 = CONCAT44(iVar5,iVar6 + (int)param_4 * 8);
    uVar12 = DAT_02912b38;
    FUN_00618310();
    iVar5 = iVar3 + (int)param_4;
    FUN_00618310(DAT_02912b38,iVar5 * 8,iVar4 + 0xa0,uVar12,uVar15);
    FUN_005d0e80(DAT_02912b38,iVar4 + 0xb0);
    FUN_006e6b90();
    FUN_00618310();
    FUN_005d0e80(DAT_02912b38,&DAT_0076ae58);
    FUN_006e6b90();
    FUN_00618310();
    uVar12 = 0x80303030;
    if (param_6 != 0) {
      uVar12 = 0x80707070;
    }
    if (DAT_02912eb8 == 0) {
      iVar6 = FUN_006e6b90();
      FUN_005db5b0(iVar9 * 0x10,iVar6 * 8,(iVar9 + iVar11) * 0x10 + -0x10,iVar6 * 8,uVar12,
                   DAT_02900c70);
      if (DAT_02912eb8 == 0) {
        iVar6 = FUN_006e6b90();
        FUN_005db5b0(iVar6 << 4,iVar10 * 8,iVar6 << 4,(iVar10 + iVar8) * 8 + -8,uVar12,DAT_02900c70)
        ;
      }
    }
    *(undefined4 *)(iVar4 + 0x8c) = 0xffffffff;
    param_4 = 1.0;
    param_2 = 0;
    if ('\0' < *(char *)(*(int *)(iVar4 + 0x4c) + 1)) {
      do {
        iVar6 = FUN_006e6b90();
        iVar6 = iVar6 + iVar9;
        iVar7 = FUN_006e6b90();
        iVar7 = (iVar10 - iVar7) + iVar8;
        if ((DAT_02912eb8 == 0) &&
           (FUN_005db5b0((iVar6 + -10) * 0x10,iVar7 * 8,(iVar6 + 10) * 0x10,iVar7 * 8,0x80505050,
                         DAT_02900c70), DAT_02912eb8 == 0)) {
          FUN_005db5b0(iVar6 * 0x10,iVar7 * 8 + -0x50,iVar6 * 0x10,iVar7 * 8 + 0x50,0x80505050,
                       DAT_02900c70);
        }
        iVar6 = *(int *)(iVar4 + 0x4c);
        fVar1 = ABS(*(float *)(iVar4 + 0x78) - *(float *)(iVar6 + 0x24 + param_2 * 4)) +
                ABS(*(float *)(iVar4 + 0x74) - *(float *)(iVar6 + 4 + param_2 * 4));
        if ((fVar1 < param_4) && (fVar1 < 0.05)) {
          *(int *)(iVar4 + 0x8c) = param_2;
          param_4 = fVar1;
        }
        param_2 = param_2 + 1;
      } while (param_2 < *(char *)(iVar6 + 1));
    }
    piVar13 = (int *)(iVar4 + 0x50);
    iVar6 = 8;
    do {
      if (*piVar13 != 0) {
        FUN_0061cb40(*piVar13,iVar9,iVar10,iVar11,iVar8,0x80402000);
      }
      piVar13 = piVar13 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_0061cb40(*(undefined4 *)(iVar4 + 0x4c),iVar9,iVar10,iVar11,iVar8,0x80800000);
    if ((-1 < *(int *)(iVar4 + 0x8c)) && (DAT_02912eb8 == 0)) {
      iVar11 = FUN_006e6b90(0xc0,0x60,0x80ffffff,(&DAT_02900c70)[DAT_02912e94]);
      iVar8 = FUN_006e6b90(((iVar10 - iVar11) + iVar8) * 8 + -0x30);
      FUN_005dbbf0((iVar8 + -6 + iVar9) * 0x10);
    }
    if ((DAT_02912f20 != 0) || (DAT_02912f24 != 0)) {
      if (DAT_02912eb8 == 0) {
        FUN_005d0fb0();
      }
      FUN_005d0e80();
      iVar8 = FUN_006e6b90();
      iVar8 = iVar8 + iVar10 * 8;
      if (DAT_02912eb8 == 0) {
        FUN_005d1060(DAT_02912b38,0x80808080);
      }
      FUN_00618310(DAT_02912b38,iVar8,"Scaling %c Axis",0x59 - (uint)(DAT_02912f20 != 0));
      FUN_005d0e80(DAT_02912b38);
      iVar9 = FUN_006e6b90();
      if (DAT_02912f20 == 0) {
        fVar1 = *(float *)(*(int *)(iVar4 + 0x4c) + 0x48);
      }
      else {
        fVar1 = *(float *)(*(int *)(iVar4 + 0x4c) + 0x44);
      }
      FUN_00618310(DAT_02912b38,iVar8 + iVar9,"%1.03f",(double)fVar1);
      FUN_005d0e80(DAT_02912b38);
    }
    FUN_005d0e80();
    iVar8 = FUN_006e6b90();
    iVar8 = iVar8 >> 3;
    FUN_005d0e80(DAT_02912b38);
    iVar9 = FUN_006e6b90();
    FUN_005d0eb0();
    iVar10 = FUN_006e6b90();
    iVar10 = iVar10 + (iVar8 * 8 - iVar9 >> 1);
    if (((DAT_02912eb8 == 0) &&
        (FUN_005db880(param_3 << 4,iVar5 * 8,iVar2 << 4,iVar8 * 8,
                      *(undefined4 *)(iVar4 + 0x30 + (*(byte *)(iVar4 + 0x11) & 1) * 4),
                      (&DAT_02900c70)[DAT_02912e90]), DAT_02912eb8 == 0)) &&
       (FUN_005d0fb0(), DAT_02912eb8 == 0)) {
      FUN_005d1060(DAT_02912b38,*(undefined4 *)(iVar4 + 0x28 + (*(byte *)(iVar4 + 0x11) & 1) * 4));
    }
    iVar9 = *(int *)(iVar4 + 0x8c);
    if (-1 < iVar9) {
      iVar2 = *(int *)(iVar4 + 0x4c);
      FUN_00618310(DAT_02912b38,iVar10 + iVar5 * 8,"Point %d = %1.02f, %1.02f",iVar9,
                   (double)(*(float *)(iVar2 + 4 + iVar9 * 4) * *(float *)(iVar2 + 0x44) *
                           *(float *)(iVar2 + 0x4c)),
                   (double)(*(float *)(iVar2 + 0x24 + iVar9 * 4) * *(float *)(iVar2 + 0x48) *
                           *(float *)(iVar2 + 0x50)));
    }
    iVar9 = *(int *)(iVar4 + 0x4c);
    FUN_00618310(DAT_02912b38,iVar10 + iVar5 * 8,"Cursor pos = %1.02f, %1.02f",
                 (double)(*(float *)(iVar9 + 0x44) * *(float *)(iVar4 + 0x74) *
                         *(float *)(iVar9 + 0x4c)),
                 (double)(*(float *)(iVar9 + 0x48) * *(float *)(iVar4 + 0x78) *
                         *(float *)(iVar9 + 0x50)));
    return iVar3 + iVar8;
  }
  if ((DAT_02912eb8 == 0) && (FUN_005d0fb0(), DAT_02912eb8 == 0)) {
    FUN_005d1060(DAT_02912b38,0x80000080);
  }
  FUN_00618310();
  return iVar3;
}

