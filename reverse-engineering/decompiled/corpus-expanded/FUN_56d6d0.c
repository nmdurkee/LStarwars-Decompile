/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56d6d0; label: FUN_0056d6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d6d0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x4690) != 0)) &&
       (iVar3 = 0, 0 < *(int *)(param_1 + 0x4694))) {
      pbVar4 = (byte *)(*(int *)(param_1 + 0x4690) + 0x34);
      do {
        if (0x1f < iVar3) {
          return;
        }
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        if ((*pbVar4 & 2) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        if ((*pbVar4 & 1) == 0) {
          param_3[iVar1 + 1] = param_3[iVar1 + 1] & ~uVar2;
        }
        iVar3 = iVar3 + 1;
        pbVar4 = pbVar4 + 0x40;
      } while (iVar3 < *(int *)(param_1 + 0x4694));
    }
  }
  return;
}

