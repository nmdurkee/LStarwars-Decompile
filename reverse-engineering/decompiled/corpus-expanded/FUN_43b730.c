/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43b730; label: FUN_0043b730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043b730(int param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  if ((pbVar3 != (byte *)0x0) && (iVar6 = 0, *pbVar3 != 0)) {
    do {
      iVar1 = *(int *)(*(int *)(pbVar3 + 4) + iVar6 * 4);
      iVar5 = 0;
      if (*(short *)(iVar1 + 0x12) != 0) {
        iVar7 = 0;
        do {
          uVar2 = *(uint *)(*(int *)(iVar1 + 0x80) + 8 + iVar7);
          puVar4 = (uint *)(*(int *)(iVar1 + 0x80) + iVar7);
          *puVar4 = uVar2;
          if (DAT_00950d50 != 0) {
            *puVar4 = ~DAT_00950d50 & uVar2;
          }
          puVar4[1] = puVar4[3];
          if (DAT_00950d50 != 0) {
            puVar4[1] = ~DAT_00950d50 & puVar4[3];
          }
          iVar5 = iVar5 + 1;
          iVar7 = iVar7 + 0x24;
        } while (iVar5 < (int)(uint)*(ushort *)(iVar1 + 0x12));
      }
      pbVar3 = *(byte **)(param_1 + 0x10);
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)*pbVar3);
  }
  return;
}

