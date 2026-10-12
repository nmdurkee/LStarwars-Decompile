/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54d310; label: FUN_0054d310
 */

void FUN_0054d310(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = 0;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x5080) != 0) && (0 < *(int *)(param_1 + 0x5084))) {
      pbVar4 = (byte *)(*(int *)(param_1 + 0x5080) + 0x1e);
      do {
        FUN_0054d1d0();
        if ((param_3 != 0) && (iVar3 < 0x20)) {
          uVar2 = 1 << ((byte)iVar3 & 0x1f);
          iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
          *pbVar4 = *pbVar4 ^ (((*(uint *)(param_3 + 4 + iVar1 * 4) & uVar2) != 0) * '\x02' ^
                              *pbVar4) & 2;
          *pbVar4 = ((*(uint *)(param_3 + iVar1 * 4) & uVar2) != 0 ^ *pbVar4) & 1 ^ *pbVar4;
        }
        iVar3 = iVar3 + 1;
        pbVar4 = pbVar4 + 0xf8;
      } while (iVar3 < *(int *)(param_1 + 0x5084));
    }
    iVar3 = 0;
    pbVar4 = &DAT_00926c76;
    do {
      iVar3 = iVar3 + 1;
      _sprintf((char *)(pbVar4 + -0x1e),"dynamic%i",iVar3);
      pbVar4[2] = 0;
      pbVar4[3] = 0;
      pbVar4[0x36] = 0;
      pbVar4[0x37] = 0;
      pbVar4[0x38] = 0;
      pbVar4[0x39] = 0;
      *pbVar4 = *pbVar4 & 0xfd | 1;
      pbVar4[-2] = 1;
      pbVar4 = pbVar4 + 0xf8;
    } while (iVar3 < 4);
  }
  return;
}

