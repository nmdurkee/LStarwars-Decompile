/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x570030; label: FUN_00570030
 */

int FUN_00570030(int param_1,uint param_2,byte param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = 0;
  if ((param_3 == 0) && (param_2 == 0xffffffff)) {
    return 0;
  }
  iVar1 = (*(int **)(param_1 + 0x50b8))[2];
  if (0 < iVar1) {
    pbVar2 = (byte *)(**(int **)(param_1 + 0x50b8) + 0x25);
    do {
      if (param_3 == 0) {
        bVar4 = *pbVar2 == param_2;
      }
      else {
        bVar4 = pbVar2[-0x11] == param_3;
      }
      if (bVar4) {
        iVar3 = iVar3 + 1;
      }
      pbVar2 = pbVar2 + 0x2c;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return iVar3;
}

