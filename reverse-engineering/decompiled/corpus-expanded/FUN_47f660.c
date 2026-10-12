/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47f660; label: FUN_0047f660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0047f660(undefined4 param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  
  iVar4 = *param_3;
  iVar5 = *(int *)(*(int *)(param_2 + 0x158) + 0x7c);
  iVar2 = iVar4 + 0x1098;
  iVar9 = (uint)*(byte *)((*(byte *)(param_2 + 0x160) == 0) + 0x10 + *(int *)(param_2 + 0x15c)) *
          0x5c + iVar5 + 4;
  FUN_005b3800(iVar2,iVar9,
               (uint)*(byte *)(*(byte *)(param_2 + 0x160) + 0x10 + *(int *)(param_2 + 0x15c)) * 0x5c
               + 4 + iVar5);
  FUN_005b3b30(iVar2,iVar2);
  FUN_005b37d0(iVar2,iVar2,iVar9);
  *(int *)(param_2 + 0x1e4) = iVar2;
  if ((*(char *)(iVar4 + 0x7b5) == '[') || (*(char *)(iVar4 + 0x7b5) == 'U')) {
    puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802278;
  }
  else {
    *(uint *)(iVar4 + 0xef4) = *(uint *)(iVar4 + 0xef4) | 0x8000;
  }
  iVar9 = *(int *)(iVar4 + 0x44c);
  if ((*(char *)(iVar9 + 0x2a) != '\0') && ((*(byte *)(iVar9 + 0x2b) & 2) != 0)) {
    iVar2 = *(int *)(iVar4 + 0x420);
    bVar8 = true;
    if (iVar2 != 0) {
      uVar7 = (iVar9 - *(int *)(iVar2 + 0x7c)) / 0x5c;
      uVar10 = uVar7 & 0x80000007;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
      }
      if ((*(byte *)(((int)(uVar7 + ((int)uVar7 >> 0x1f & 7U)) >> 3) + 0x18 + iVar2) &
          (byte)(1 << ((byte)uVar10 & 0x1f))) == 0) {
        FUN_0051af40(param_1,iVar2,iVar9);
      }
    }
    if (((*(char *)(iVar4 + 0x281) == '\0') || (*(short *)(iVar4 + 0x27e) == -1)) ||
       (DAT_0292fc68 == 0)) goto LAB_0047f7be;
    iVar9 = FUN_005cffb0(*(int *)(iVar4 + 0x44c) + 0x40);
    if (iVar9 != *(short *)(*(short *)(iVar4 + 0x27e) * 0x6c + 0x4a + *(int *)(DAT_0292fc68 + 0x68))
       ) goto LAB_0047f7be;
  }
  bVar8 = false;
LAB_0047f7be:
  if (((2.0 < (float)param_3[0x76]) ||
      ((!bVar8 &&
       ((int)*(short *)(iVar4 + 0x3ec) ==
        (*(int *)(iVar4 + 0x44c) - *(int *)(*(int *)(iVar4 + 0x420) + 0x7c)) / 0x5c)))) ||
     ((cVar3 = *(char *)(iVar4 + 0x7b5), cVar3 != '\0' &&
      (((cVar3 != '[' && (cVar3 != 'U')) &&
       ((*(float *)(iVar4 + 0x60) < *(float *)(*(int *)(iVar4 + 0x44c) + 0x18) ||
        (((*(uint *)(*(int *)(param_2 + 0x15c) + (uint)*(byte *)(param_2 + 0x160) * 4) & 0x80000000)
          != 0 || (*(float *)(iVar4 + 0x1090) < -5.0)))))))))) {
    FUN_0043cbf0(iVar4);
  }
  if (*(int *)(iVar4 + 0x44c) != 0) {
    if (((*(uint *)(iVar4 + 0xeec) & 0x1000) != 0) && (*(float *)(iVar4 + 0x6c) < 0.0)) {
      puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
      *(uint *)(iVar4 + 0xeec) = *(uint *)(iVar4 + 0xeec) & 0xffffefff;
    }
    iVar9 = *(int *)(iVar4 + 0x44c);
    *(undefined4 *)(iVar4 + 0x3cc) = *(undefined4 *)(iVar9 + 4);
    *(undefined4 *)(iVar4 + 0x3d0) = *(undefined4 *)(iVar9 + 8);
    uVar6 = *(undefined4 *)(iVar9 + 0xc);
    *(undefined4 *)(iVar4 + 0x3d8) = 0;
    *(undefined4 *)(iVar4 + 0x3d4) = uVar6;
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  return 0;
}

