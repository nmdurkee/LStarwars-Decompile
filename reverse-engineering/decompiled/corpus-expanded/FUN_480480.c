/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x480480; label: FUN_00480480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00480480(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float10 fVar6;
  
  iVar2 = *param_3;
  iVar3 = *(int *)(*(int *)(iVar2 + 0x108c) + 4);
  FUN_0055dd70(iVar2,iVar3,1,0x32,0);
  iVar4 = *(int *)(iVar2 + 0x44c);
  *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar4 + 4);
  *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar4 + 8);
  uVar5 = *(undefined4 *)(iVar4 + 0xc);
  *(undefined4 *)(iVar2 + 0x3d8) = 0;
  *(undefined4 *)(iVar2 + 0x3d4) = uVar5;
  if (*(char *)(iVar2 + 0x7b5) == '\0') {
    FUN_0043cbb0(iVar2,iVar4,0,0);
    FUN_0055dd70(iVar2,0,0,0,0);
    return 1;
  }
  if ((*(char *)(iVar2 + 0x7b5) == DAT_00802874) && (*(int *)(iVar2 + 0x798) == iVar3)) {
    if (*(float *)(iVar3 + 0x4c) == 0.0) {
      puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
      *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
      return 1;
    }
    fVar6 = (float10)FUN_005b3cf0(iVar4 + 4,iVar2 + 0x5c,0);
    if ((float)fVar6 < _DAT_007fa298 * _DAT_007fa298) {
      puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
      *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    }
    return 1;
  }
  FUN_0043cbf0(iVar2);
  return 0;
}

