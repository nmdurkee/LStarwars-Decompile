/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bd870; label: FUN_004bd870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004bd870(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    param_3[2] = 0;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x50b0) != 0)) && (0 < *(int *)(param_1 + 0x50b4))) {
      pbVar3 = (byte *)(*(int *)(param_1 + 0x50b0) + 0xa2);
      do {
        if (0x1f < iVar4) {
          return;
        }
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*pbVar3 & 2) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        if ((*pbVar3 & 1) == 0) {
          param_3[iVar1 + 1] = param_3[iVar1 + 1] & ~uVar2;
        }
        if ((*pbVar3 & 4) != 0) {
          param_3[iVar1 + 2] = param_3[iVar1 + 2] | uVar2;
        }
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0xc0;
      } while (iVar4 < *(int *)(param_1 + 0x50b4));
    }
  }
  return;
}

