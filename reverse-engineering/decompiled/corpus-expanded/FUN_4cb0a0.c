/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cb0a0; label: FUN_004cb0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cb0a0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *param_3;
  if (*(char *)(iVar2 + 0x7b5) == '\0') {
    FUN_0043cbb0(iVar2,*(undefined4 *)(iVar2 + 0x44c),0,0);
    iVar3 = *(int *)(iVar2 + 0x44c);
    *(undefined4 *)(iVar2 + 0x3cc) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar2 + 0x3d0) = *(undefined4 *)(iVar3 + 8);
    uVar4 = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar2 + 0x3d8) = 0;
    *(undefined4 *)(iVar2 + 0x3d4) = uVar4;
    return 1;
  }
  puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
  *puVar1 = *puVar1 | DAT_00802278;
  *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
  return 1;
}

