/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c0a20; label: FUN_004c0a20
 */

void FUN_004c0a20(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0xffffffff;
    param_3[5] = 0xffffffff;
    param_3[6] = 0xffffffff;
    param_3[7] = 0xffffffff;
    param_3[8] = 0xffffffff;
    param_3[9] = 0xffffffff;
    param_3[10] = 0xffffffff;
    param_3[0xb] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x5090) != 0)) &&
       (iVar4 = 0, 0 < *(int *)(param_1 + 0x5094))) {
      pbVar3 = (byte *)(*(int *)(param_1 + 0x5090) + 0x3c);
      do {
        if (0x7f < iVar4) {
          return;
        }
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*pbVar3 & 8) != 0) {
          param_3[iVar1] = param_3[iVar1] | uVar2;
        }
        if ((*pbVar3 & 2) == 0) {
          param_3[iVar1 + 8] = param_3[iVar1 + 8] & ~uVar2;
        }
        if ((*pbVar3 & 1) == 0) {
          param_3[iVar1 + 4] = param_3[iVar1 + 4] & ~uVar2;
        }
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0x54;
      } while (iVar4 < *(int *)(param_1 + 0x5094));
    }
  }
  return;
}

