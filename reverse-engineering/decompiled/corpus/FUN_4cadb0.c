/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4cadb0; label: FUN_004cadb0
 */

undefined4 FUN_004cadb0(undefined4 param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  bVar4 = *(byte *)(param_2 + 0x160);
  iVar5 = *param_3;
  iVar6 = *(int *)(param_2 + 0x15c);
  uVar13 = *(uint *)(iVar6 + (uint)bVar4 * 4) & *(uint *)(param_2 + 500);
  iVar2 = iVar5 + 0x1098;
  iVar7 = *(int *)(*(int *)(param_2 + 0x158) + 0x7c);
  iVar14 = (uint)*(byte *)((bVar4 == 0) + 0x10 + iVar6) * 0x5c + iVar7;
  iVar11 = iVar14 + 4;
  FUN_005b3800(iVar2,iVar11,(uint)*(byte *)(iVar6 + 0x10 + (uint)bVar4) * 0x5c + 4 + iVar7);
  FUN_005b3b30(iVar2,iVar2);
  FUN_005b37d0(iVar2,iVar2,iVar11);
  *(int *)(param_2 + 0x1e4) = iVar2;
  iVar11 = *(int *)(iVar5 + 0x44c);
  if ((*(char *)(iVar11 + 0x2a) != '\0') && ((*(byte *)(iVar11 + 0x2b) & 2) != 0)) {
    bVar10 = true;
    if (*(int *)(iVar5 + 0x420) != 0) {
      uVar9 = (iVar11 - *(int *)(*(int *)(iVar5 + 0x420) + 0x7c)) / 0x5c;
      uVar12 = uVar9 & 0x80000007;
      if ((int)uVar12 < 0) {
        uVar12 = (uVar12 - 1 | 0xfffffff8) + 1;
      }
      if ((*(byte *)(((int)(uVar9 + ((int)uVar9 >> 0x1f & 7U)) >> 3) + 0x18 +
                    *(int *)(iVar5 + 0x420)) & (byte)(1 << ((byte)uVar12 & 0x1f))) == 0) {
        FUN_0051af40(param_1,*(int *)(iVar5 + 0x420),*(undefined4 *)(iVar5 + 0x44c));
      }
    }
    if (((*(char *)(iVar5 + 0x281) == '\0') || (*(short *)(iVar5 + 0x27e) == -1)) ||
       (DAT_0292fc68 == 0)) goto LAB_004caf2a;
    iVar11 = FUN_005cffb0(*(int *)(iVar5 + 0x44c) + 0x40);
    if (iVar11 != *(short *)(*(short *)(iVar5 + 0x27e) * 0x6c + 0x4a + *(int *)(DAT_0292fc68 + 0x68)
                            )) goto LAB_004caf2a;
  }
  bVar10 = false;
LAB_004caf2a:
  if (((2.0 < (float)param_3[0x76]) ||
      ((!bVar10 &&
       ((int)*(short *)(iVar5 + 0x3ec) ==
        (*(int *)(iVar5 + 0x44c) - *(int *)(*(int *)(iVar5 + 0x420) + 0x7c)) / 0x5c)))) ||
     ((*(char *)(iVar5 + 0x7b5) != '\0' &&
      (((*(float *)(iVar5 + 0x60) < *(float *)(*(int *)(iVar5 + 0x44c) + 0x18) ||
        ((*(uint *)(*(int *)(param_2 + 0x15c) + (uint)*(byte *)(param_2 + 0x160) * 4) & 0x80000000)
         != 0)) || (((uVar13 & 0x40) != 0 && (*(char *)(iVar5 + 0x281) != '\0')))))))) {
    FUN_0043cbf0(iVar5);
  }
  if (*(int *)(iVar5 + 0x44c) != 0) {
    if ((uVar13 & 0x40) == 0) {
      if ((uVar13 & 4) == 0) {
        if (((*(uint *)(iVar5 + 0xeec) & 0x1000) != 0) && (*(float *)(iVar5 + 0x6c) < 0.0)) {
          puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 8);
          *puVar1 = *puVar1 | DAT_00802278;
          *(uint *)(iVar5 + 0xeec) = *(uint *)(iVar5 + 0xeec) & 0xffffefff;
        }
      }
      else {
        fVar3 = *(float *)(iVar14 + 0x18);
        if (fVar3 < *(float *)(param_2 + 0x150) != (fVar3 == *(float *)(param_2 + 0x150))) {
          puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 4);
          *puVar1 = *puVar1 | DAT_00802278;
          if ((*(char *)(iVar5 + 0xe32) == '\0') || (*(char *)(iVar5 + 0xe32) == '\x03')) {
            puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 8);
            *puVar1 = *puVar1 | DAT_00802278;
          }
        }
      }
    }
    iVar11 = *(int *)(iVar5 + 0x44c);
    *(undefined4 *)(iVar5 + 0x3cc) = *(undefined4 *)(iVar11 + 4);
    *(undefined4 *)(iVar5 + 0x3d0) = *(undefined4 *)(iVar11 + 8);
    uVar8 = *(undefined4 *)(iVar11 + 0xc);
    *(undefined4 *)(iVar5 + 0x3d8) = 0;
    *(undefined4 *)(iVar5 + 0x3d4) = uVar8;
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  return 0;
}

