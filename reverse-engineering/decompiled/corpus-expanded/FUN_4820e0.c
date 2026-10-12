/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x4820e0; label: FUN_004820e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004820e0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    param_3[2] = 0xffffffff;
    param_3[3] = 0xffffffff;
    param_3[4] = 0xffffffff;
    param_3[5] = 0xffffffff;
    param_3[6] = 0xffffffff;
    param_3[7] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x50a8) != 0)) &&
       (iVar4 = 0, 0 < *(int *)(param_1 + 0x50ac))) {
      pbVar3 = (byte *)(*(int *)(param_1 + 0x50a8) + 0x17);
      do {
        if (0x7f < iVar4) {
          return;
        }
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*pbVar3 & 2) == 0) {
          param_3[iVar1 + 4] = param_3[iVar1 + 4] & ~uVar2;
        }
        if ((*pbVar3 & 1) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0x38;
      } while (iVar4 < *(int *)(param_1 + 0x50ac));
    }
  }
  return;
}

