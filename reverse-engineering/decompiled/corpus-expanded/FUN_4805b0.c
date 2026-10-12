/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x4805b0; label: FUN_004805b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004805b0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_3;
  if (*(char *)(iVar2 + 0x7b5) != 'F') {
    FUN_0043cbf0(iVar2);
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x44c);
  if (*(float *)(iVar3 + 8) <= *(float *)(*(int *)(iVar2 + 0x1094) + 8)) {
    if ((*(byte *)(iVar2 + 0xe24) & 0x80) == 0) {
      *(undefined4 *)(iVar2 + 0x3d8) = 0;
      *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar2 + 0x5c);
      *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar2 + 0x60);
      *(undefined4 *)(iVar2 + 0x3d4) = *(undefined4 *)(iVar2 + 100);
      return 1;
    }
    *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0x3d4) = *(undefined4 *)(iVar3 + 0xc);
  }
  else {
    iVar3 = FUN_0054f780(iVar2);
    if (iVar3 == 0) {
      puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 4);
      *puVar1 = *puVar1 | DAT_00802280;
      *(undefined4 *)(iVar2 + 0x3d8) = 0;
      *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar2 + 0x5c);
      *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar2 + 0x60);
      *(undefined4 *)(iVar2 + 0x3d4) = *(undefined4 *)(iVar2 + 100);
      return 1;
    }
    iVar3 = *(int *)(iVar2 + 0x44c);
    *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0x3d4) = *(undefined4 *)(iVar3 + 0xc);
  }
  *(undefined4 *)(iVar2 + 0x3d8) = 0;
  puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
  *puVar1 = *puVar1 | DAT_00802278;
  FUN_0043cbb0(iVar2,*(undefined4 *)(iVar2 + 0x44c),0,0);
  return 1;
}

