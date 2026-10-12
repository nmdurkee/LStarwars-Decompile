/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4cb790; label: FUN_004cb790
 */

undefined4 FUN_004cb790(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  
  iVar2 = *param_2;
  iVar5 = *(int *)(param_1 + 0x15c);
  uVar7 = (uint)*(byte *)((*(char *)(param_1 + 0x160) == '\0') + 0x10 + iVar5);
  iVar3 = *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  piVar8 = (int *)(uVar7 * 0x5c + iVar3);
  if (((int)*(short *)(iVar2 + 0x3ec) != uVar7) && (*(char *)(iVar2 + 0x7b5) != '+')) {
    if ((*(uint *)(iVar5 + (uint)*(byte *)(param_1 + 0x160) * 4) & 0x800) == 0) {
      iVar5 = FUN_0043c9a0(iVar2,piVar8,0);
      if (iVar5 == 0) {
        if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b128) && (*piVar8 != 0)) &&
            (iVar5 = FUN_004f8b10(*piVar8,"stairs_top"), iVar5 == 0)) &&
           (piVar6 = (int *)FUN_0051ad80(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),0,"stairs_top2")
           , piVar6 != (int *)0x0)) {
          piVar8 = piVar6;
        }
        FUN_00561e20(iVar2,piVar8 + 1,0,0x3f000000,0x3f800000,0);
        FUN_0043cbb0(iVar2,piVar8,0,3);
        return 0;
      }
    }
    else {
      puVar1 = (undefined4 *)
               ((uint)*(byte *)(*(byte *)(param_1 + 0x160) + 0x10 + iVar5) * 0x5c + 4 + iVar3);
      *(undefined4 *)(param_1 + 0x104) = *puVar1;
      *(undefined4 *)(param_1 + 0x108) = puVar1[1];
      uVar4 = puVar1[2];
      *(uint *)(param_1 + 0x1e8) = *(uint *)(param_1 + 0x1e8) | 0x800000;
      *(undefined4 *)(param_1 + 0x110) = 0;
      *(undefined4 *)(param_1 + 0x10c) = uVar4;
      *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
    }
    return 1;
  }
  return 0;
}

