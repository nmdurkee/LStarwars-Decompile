/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481180; label: FUN_00481180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00481180(int param_1,int *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = *param_2;
  if (0.0 < *(float *)(iVar3 + 0x1090)) {
    *(int *)(param_1 + 0x104) = param_2[0x17];
    *(int *)(param_1 + 0x108) = param_2[0x18];
    iVar3 = param_2[0x19];
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(int *)(param_1 + 0x10c) = iVar3;
    *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
    return 1;
  }
  iVar5 = (uint)*(byte *)((*(char *)(param_1 + 0x160) == '\0') + 0x10 + *(int *)(param_1 + 0x15c)) *
          0x5c + *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  if (*(char *)(iVar3 + 0x7b5) == 'G') {
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar5 + 4);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(iVar5 + 8);
    uVar4 = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x10c) = uVar4;
    FUN_0043cbb0(iVar3,iVar5,0,9);
    *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  }
  else {
    iVar5 = FUN_0043c9a0(iVar3,iVar5,0);
    if (iVar5 == 0) {
      puVar2 = (undefined4 *)
               ((uint)*(byte *)(*(byte *)(param_1 + 0x160) + 0x10 + *(int *)(param_1 + 0x15c)) *
                0x5c + 4 + *(int *)(*(int *)(param_1 + 0x158) + 0x7c));
      *(undefined4 *)(param_1 + 0x104) = *puVar2;
      *(undefined4 *)(param_1 + 0x108) = puVar2[1];
      *(undefined4 *)(param_1 + 0x10c) = puVar2[2];
      *(undefined4 *)(param_1 + 0x110) = 0;
      puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 4);
      *puVar1 = *puVar1 | DAT_00802280;
      puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802280;
      FUN_0055dd70(iVar3,0,4,1,0);
      *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
      return 1;
    }
  }
  return 1;
}

