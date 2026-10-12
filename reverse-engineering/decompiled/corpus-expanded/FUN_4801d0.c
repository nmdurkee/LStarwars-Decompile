/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x4801d0; label: FUN_004801d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004801d0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = *param_3;
  iVar4 = *(int *)(*(int *)(iVar3 + 0x108c) + 4);
  FUN_0055dd70(iVar3,iVar4,1,0x32,0);
  cVar2 = *(char *)(iVar3 + 0x7b5);
  if ((cVar2 == DAT_00802874) && (*(int *)(iVar3 + 0x798) == iVar4)) {
    *(undefined4 *)(iVar3 + 0x3d8) = 0;
    *(undefined4 *)(iVar3 + 0x3cc) = *(undefined4 *)(iVar3 + 0x5c);
    *(undefined4 *)(iVar3 + 0x3d0) = *(undefined4 *)(iVar3 + 0x60);
    *(undefined4 *)(iVar3 + 0x3d4) = *(undefined4 *)(iVar3 + 100);
    FUN_0043cbb0(iVar3,*(undefined4 *)(iVar3 + 0x44c),*(undefined4 *)(iVar3 + 0x1094),7);
    return 1;
  }
  if (((-1.0 <= *(float *)(iVar3 + 0x1090)) || (cVar2 == '\0')) &&
     ((_DAT_007fa29c <= *(float *)(iVar3 + 0x1090) || (cVar2 == DAT_00802874)))) {
    *(undefined4 *)(iVar3 + 0x3cc) = *(undefined4 *)(iVar4 + 0x24);
    *(undefined4 *)(iVar3 + 0x3d0) = *(undefined4 *)(iVar4 + 0x28);
    uVar5 = *(undefined4 *)(iVar4 + 0x2c);
    *(undefined4 *)(iVar3 + 0x3d8) = 0;
    *(undefined4 *)(iVar3 + 0x3d4) = uVar5;
    if (cVar2 != '\0') {
      puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
    }
    return 1;
  }
  FUN_0043cbf0(iVar3);
  return 0;
}

