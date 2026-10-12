/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cb5e0; label: FUN_004cb5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004cb65f) */

undefined4 FUN_004cb5e0(int param_1,int *param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = *param_2;
  bVar2 = *(byte *)(param_1 + 0x160);
  iVar7 = *(int *)(param_1 + 0x15c);
  bVar3 = *(byte *)((bVar2 == 0) + 0x10 + iVar7);
  iVar8 = *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  puVar1 = (undefined4 *)((uint)*(byte *)(bVar2 + 0x10 + iVar7) * 0x5c + 4 + iVar8);
  iVar8 = (uint)bVar3 * 0x5c + iVar8;
  *(undefined4 *)(param_1 + 0x104) = *puVar1;
  *(undefined4 *)(param_1 + 0x108) = puVar1[1];
  *(undefined4 *)(param_1 + 0x10c) = puVar1[2];
  *(undefined4 *)(param_1 + 0x110) = 0;
  if (((*(uint *)(iVar7 + (uint)bVar2 * 4) & 0x200) == 0) &&
     ((*(byte *)(((int)(uint)bVar3 >> 3) + 0x38 + *(int *)(param_1 + 0x158)) &
      (byte)(1 << (bVar3 & 7))) != 0)) {
    iVar6 = FUN_0043c9a0(iVar6,iVar8,0);
    if (iVar6 != 0) {
      return 1;
    }
    *(undefined1 *)(param_1 + 0x139) = 0;
    goto LAB_004cb771;
  }
  if ((*(char *)(param_1 + 0x139) != '\0') && (iVar7 = FUN_0043c9a0(iVar6,iVar8,0), iVar7 != 0)) {
    return 1;
  }
  cVar4 = *(char *)(param_1 + 0x139);
  if (cVar4 == '\0') {
    iVar7 = FUN_0056db40(iVar6);
    if (iVar7 == 0) goto LAB_004cb771;
    *(undefined1 *)(param_1 + 0x139) = 1;
LAB_004cb701:
    iVar7 = FUN_0056db40(iVar6);
    if ((iVar7 != 0) &&
       ((*(float *)(iVar6 + 0x17c) <= *(float *)(*(int *)(iVar6 + 0x798) + 0x28) ||
        (*(float *)(iVar6 + 0x6c) <= 0.0)))) goto LAB_004cb771;
    *(undefined1 *)(param_1 + 0x139) = 2;
  }
  else {
    if (cVar4 == '\x01') goto LAB_004cb701;
    if (cVar4 != '\x02') goto LAB_004cb771;
  }
  *(undefined1 *)(param_1 + 0x139) = 0;
  FUN_0043cbb0(iVar6,iVar8,0,0);
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar8 + 4);
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(iVar8 + 8);
  uVar5 = *(undefined4 *)(iVar8 + 0xc);
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x10c) = uVar5;
LAB_004cb771:
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

