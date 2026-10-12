/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cd750; label: FUN_004cd750
 */

void FUN_004cd750(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x5078) != 0)) &&
       (iVar3 = 0, 0 < *(int *)(param_1 + 0x507c))) {
      pbVar4 = (byte *)(*(int *)(param_1 + 0x5078) + 0x3c);
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
        pbVar4 = pbVar4 + 0x70;
      } while (iVar3 < *(int *)(param_1 + 0x507c));
    }
  }
  return;
}

