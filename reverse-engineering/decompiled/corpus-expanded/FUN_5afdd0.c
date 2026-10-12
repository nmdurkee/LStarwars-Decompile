/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afdd0; label: FUN_005afdd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005afdd0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    param_3[2] = 0;
    if ((((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x516c), piVar1 != (int *)0x0)) &&
        (*piVar1 != 0)) && (0 < piVar1[1])) {
      pbVar4 = (byte *)(*piVar1 + 0x23);
      do {
        if (0x1f < iVar5) {
          return;
        }
        iVar2 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
        uVar3 = 1 << ((byte)iVar5 & 0x1f);
        if ((*pbVar4 & 2) == 0) {
          param_3[iVar2] = param_3[iVar2] & ~uVar3;
        }
        if ((*pbVar4 & 1) == 0) {
          param_3[iVar2 + 1] = param_3[iVar2 + 1] & ~uVar3;
        }
        if ((*pbVar4 & 4) != 0) {
          param_3[iVar2 + 1] = param_3[iVar2 + 1] | uVar3;
        }
        iVar5 = iVar5 + 1;
        pbVar4 = pbVar4 + 0x34;
      } while (iVar5 < *(int *)(*(int *)(param_1 + 0x516c) + 4));
    }
  }
  return;
}

