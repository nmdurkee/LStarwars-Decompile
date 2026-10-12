/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c83f0; label: FUN_004c83f0
 */

void FUN_004c83f0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0xffffffff;
    param_3[9] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x5060) != 0)) &&
       (iVar5 = 0, 0 < *(int *)(param_1 + 0x5064))) {
      pbVar3 = (byte *)(*(int *)(param_1 + 0x5060) + 0x6a);
      iVar4 = 0;
      do {
        if (0x127f < iVar4) {
          return;
        }
        uVar2 = 1 << ((byte)iVar5 & 0x1f);
        iVar1 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
        *(undefined1 *)(iVar5 + (int)param_3) =
             *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x5060) + 0x80 + iVar4) + 0xf);
        if ((*pbVar3 & 1) == 0) {
          param_3[iVar1 + 9] = param_3[iVar1 + 9] & ~uVar2;
        }
        if ((*pbVar3 & 2) == 0) {
          param_3[iVar1 + 8] = param_3[iVar1 + 8] & ~uVar2;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x94;
        pbVar3 = pbVar3 + 0x94;
      } while (iVar5 < *(int *)(param_1 + 0x5064));
    }
  }
  return;
}

