/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8a70; label: FUN_004f8a70
 */

char * FUN_004f8a70(char *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  
  if (*param_1 != '\0') {
    iVar4 = (int)param_1 - (int)param_2;
    do {
      pbVar3 = param_2;
      if (*param_2 != 0) {
        while (bVar2 = pbVar3[iVar4], bVar2 != 0) {
          if (((byte)(bVar2 + 0x9f) < 0x1a) || (0xdf < bVar2)) {
            bVar2 = bVar2 - 0x20;
          }
          bVar1 = *pbVar3;
          if (((byte)(bVar1 + 0x9f) < 0x1a) || (0xdf < bVar1)) {
            bVar1 = bVar1 - 0x20;
          }
          if (bVar2 != bVar1) break;
          pbVar3 = pbVar3 + 1;
          if (*pbVar3 == 0) {
            return param_1;
          }
        }
      }
      if (*pbVar3 == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 1;
    } while (*param_1 != '\0');
  }
  return (char *)0x0;
}

