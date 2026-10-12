/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x4071d0; label: FUN_004071d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004071d0(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *param_2;
  iVar5 = *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  iVar6 = (uint)*(byte *)(*(byte *)(param_1 + 0x160) + 0x10 + *(int *)(param_1 + 0x15c)) * 0x5c +
          iVar5;
  iVar5 = (uint)*(byte *)((*(byte *)(param_1 + 0x160) == 0) + 0x10 + *(int *)(param_1 + 0x15c)) *
          0x5c + iVar5;
  iVar4 = FUN_0043c9a0(iVar2,iVar5,0);
  if (iVar4 == 0) {
    *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
    if (*(char *)(iVar2 + 0x7b5) != 'F') {
      *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(iVar6 + 8);
      uVar3 = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(param_1 + 0x110) = 0;
      *(undefined4 *)(param_1 + 0x10c) = uVar3;
      if (*(float *)(iVar2 + 0x1090) <= 0.0) {
        FUN_0055dd70(iVar2,*(undefined4 *)(iVar2 + 0x798),1,0x32,0);
        puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 4);
        *puVar1 = *puVar1 | DAT_00802280;
        puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802280;
        return 0;
      }
      return 0;
    }
    FUN_0055dd70(iVar2,*(undefined4 *)(iVar2 + 0x798),1,0x32,0);
    FUN_0043cbb0(iVar2,iVar5,iVar6,7);
  }
  return 1;
}

