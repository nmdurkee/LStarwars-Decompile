/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d7620; label: FUN_004d7620
 */

void FUN_004d7620(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x4688) != 0)) &&
       (iVar3 = 0, 0 < *(int *)(param_1 + 0x468c))) {
      pbVar4 = (byte *)(*(int *)(param_1 + 0x4688) + 0x68);
      do {
        if (0x1f < iVar3) {
          return;
        }
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        if ((*pbVar4 & 0x80) == 0) {
          param_3[iVar1 + 1] = param_3[iVar1 + 1] & ~uVar2;
        }
        if ((*pbVar4 & 0x40) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        iVar3 = iVar3 + 1;
        pbVar4 = pbVar4 + 0x7c;
      } while (iVar3 < *(int *)(param_1 + 0x468c));
    }
  }
  return;
}

