/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x405d70; label: FUN_00405d70
 */

undefined4 FUN_00405d70(undefined4 param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  iVar4 = *(int *)(param_2 + 0x15c);
  iVar5 = *param_3;
  bVar3 = *(byte *)(param_2 + 0x160);
  uVar12 = *(uint *)(iVar4 + (uint)bVar3 * 4) & *(uint *)(param_2 + 500);
  iVar6 = *(int *)(*(int *)(param_2 + 0x158) + 0x7c);
  iVar10 = (uint)*(byte *)((bVar3 == 0) + 0x10 + iVar4) * 0x5c + iVar6 + 4;
  iVar2 = iVar5 + 0x1098;
  FUN_005b3800(iVar2,iVar10,(uint)*(byte *)(iVar4 + 0x10 + (uint)bVar3) * 0x5c + 4 + iVar6);
  FUN_005b3b30(iVar2,iVar2);
  FUN_005b37d0(iVar2,iVar2,iVar10);
  *(int *)(param_2 + 0x1e4) = iVar2;
  if (*(char *)(iVar5 + 0x7b5) == '[') {
    puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802278;
  }
  else {
    *(uint *)(iVar5 + 0xef4) = *(uint *)(iVar5 + 0xef4) | 0x8000;
  }
  iVar10 = *(int *)(iVar5 + 0x44c);
  if ((*(char *)(iVar10 + 0x2a) != '\0') && ((*(byte *)(iVar10 + 0x2b) & 2) != 0)) {
    iVar2 = *(int *)(iVar5 + 0x420);
    bVar9 = true;
    if (iVar2 != 0) {
      uVar8 = (iVar10 - *(int *)(iVar2 + 0x7c)) / 0x5c;
      uVar11 = uVar8 & 0x80000007;
      if ((int)uVar11 < 0) {
        uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
      }
      if ((*(byte *)(((int)(uVar8 + ((int)uVar8 >> 0x1f & 7U)) >> 3) + 0x18 + iVar2) &
          (byte)(1 << ((byte)uVar11 & 0x1f))) == 0) {
        FUN_0051af40(param_1,iVar2,iVar10);
      }
    }
    if (((*(char *)(iVar5 + 0x281) == '\0') || (*(short *)(iVar5 + 0x27e) == -1)) ||
       (DAT_0292fc68 == 0)) goto LAB_00405ee8;
    iVar10 = FUN_005cffb0(*(int *)(iVar5 + 0x44c) + 0x40);
    if (iVar10 != *(short *)(*(short *)(iVar5 + 0x27e) * 0x6c + 0x4a + *(int *)(DAT_0292fc68 + 0x68)
                            )) goto LAB_00405ee8;
  }
  bVar9 = false;
LAB_00405ee8:
  if (((2.0 < (float)param_3[0x76]) ||
      (((!bVar9 &&
        ((int)*(short *)(iVar5 + 0x3ec) ==
         (*(int *)(iVar5 + 0x44c) - *(int *)(*(int *)(iVar5 + 0x420) + 0x7c)) / 0x5c)) &&
       ((*(char *)(iVar5 + 0x281) != '\0' || (*(float *)(iVar5 + 0x6c) < 0.0)))))) ||
     ((*(char *)(iVar5 + 0x7b5) != '\0' &&
      ((*(float *)(iVar5 + 0x60) < *(float *)(*(int *)(iVar5 + 0x44c) + 0x18) ||
       ((*(uint *)(*(int *)(param_2 + 0x15c) + (uint)*(byte *)(param_2 + 0x160) * 4) & 0x80000000)
        != 0)))))) {
    FUN_0043cbf0(iVar5);
  }
  if (*(int *)(iVar5 + 0x44c) != 0) {
    if ((uVar12 & 0x40) == 0) {
      if (((*(uint *)(iVar5 + 0xeec) & 0x1000) != 0) && (*(float *)(iVar5 + 0x6c) < 0.0)) {
        puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802278;
        *(uint *)(iVar5 + 0xeec) = *(uint *)(iVar5 + 0xeec) & 0xffffefff;
      }
      if ((uVar12 & 4) != 0) {
        puVar1 = (uint *)(*(int *)(iVar5 + 0xca4) + 4);
        *puVar1 = *puVar1 | DAT_00802278;
      }
    }
    iVar10 = *(int *)(iVar5 + 0x44c);
    *(undefined4 *)(iVar5 + 0x3cc) = *(undefined4 *)(iVar10 + 4);
    *(undefined4 *)(iVar5 + 0x3d0) = *(undefined4 *)(iVar10 + 8);
    uVar7 = *(undefined4 *)(iVar10 + 0xc);
    *(undefined4 *)(iVar5 + 0x3d8) = 0;
    *(undefined4 *)(iVar5 + 0x3d4) = uVar7;
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  return 0;
}

