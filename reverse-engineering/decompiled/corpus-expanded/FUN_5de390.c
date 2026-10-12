/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5de390; label: FUN_005de390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005de390(int param_1)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar2 = *(int *)(param_1 + 0x60);
  iVar6 = 0;
  if (0 < iVar2) {
    puVar1 = (ushort *)(*(int *)(param_1 + 100) + 0x20);
    iVar3 = iVar2;
    do {
      iVar6 = iVar6 + (uint)*puVar1;
      puVar1 = puVar1 + 0x12;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  local_8 = 0;
  if (0 < iVar2) {
    local_4 = 0;
    do {
      piVar5 = (int *)(local_4 + *(int *)(param_1 + 100));
      if (((short)piVar5[8] != 0) && (iVar2 = 0, 0 < iVar6)) {
        puVar4 = *(undefined4 **)(param_1 + 0x50);
        do {
          if (((int)(short)(*(short *)*puVar4 << 4) >> 8) * 0x20000 + (int)((short *)*puVar4)[0x3b]
              == *piVar5) {
            *(short *)((int)piVar5 + 0x22) = (short)iVar2;
            break;
          }
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
        } while (iVar2 < iVar6);
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 0x24;
    } while (local_8 < *(int *)(param_1 + 0x60));
  }
  return;
}

