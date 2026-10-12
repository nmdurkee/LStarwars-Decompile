/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x5589b0; label: FUN_005589b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005589b0(undefined4 param_1,int *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  
  FUN_005588b0(param_1,param_3);
  if (param_3 != 0) {
    iVar4 = 0;
    if ((short)param_2[2] != 0) {
      pbVar5 = (byte *)(*param_2 + 0x9c);
      do {
        if (0x7f < iVar4) {
          return;
        }
        iVar2 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar3 = 1 << ((byte)iVar4 & 0x1f);
        if ((pbVar5[-8] & 2) == 0) {
          puVar1 = (uint *)(param_3 + 0x10 + iVar2 * 4);
          *puVar1 = *puVar1 & ~uVar3;
        }
        if ((pbVar5[-8] & 1) == 0) {
          puVar1 = (uint *)(param_3 + iVar2 * 4);
          *puVar1 = *puVar1 & ~uVar3;
        }
        if ((*pbVar5 & 1) != 0) {
          puVar1 = (uint *)(param_3 + 0x20 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar3;
        }
        if ((*pbVar5 & 4) != 0) {
          puVar1 = (uint *)(param_3 + 0x30 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar3;
        }
        if ((*pbVar5 & 8) != 0) {
          puVar1 = (uint *)(param_3 + 0x40 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar3;
        }
        if ((*pbVar5 & 0x40) != 0) {
          puVar1 = (uint *)(param_3 + 0x50 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar3;
        }
        if ((*pbVar5 & 0x80) != 0) {
          puVar1 = (uint *)(param_3 + 0x60 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar3;
        }
        iVar4 = iVar4 + 1;
        pbVar5 = pbVar5 + 0xa0;
      } while (iVar4 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

