/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d160; label: FUN_0056d160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d160(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x50a0) != 0)) &&
       (iVar3 = 0, 0 < *(int *)(param_1 + 0x50a4))) {
      pbVar4 = (byte *)(*(int *)(param_1 + 0x50a0) + 0x20);
      do {
        if (0x1f < iVar3) {
          return;
        }
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        if ((*pbVar4 & 2) == 0) {
          param_3[iVar1 + 1] = param_3[iVar1 + 1] & ~uVar2;
        }
        if ((*pbVar4 & 1) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        iVar3 = iVar3 + 1;
        pbVar4 = pbVar4 + 0x24;
      } while (iVar3 < *(int *)(param_1 + 0x50a4));
    }
  }
  return;
}

