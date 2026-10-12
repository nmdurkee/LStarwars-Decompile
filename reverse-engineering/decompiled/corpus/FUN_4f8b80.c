/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8b80; label: FUN_004f8b80
 */

undefined4 FUN_004f8b80(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  if (param_1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (byte *)0x0) {
    if (param_3 != 0) {
      pbVar3 = param_1;
      if ((param_3 == -1) || (pbVar3 = param_2, param_3 == -2)) {
        param_3 = FUN_004f1ff0(pbVar3);
      }
      do {
        bVar1 = *param_1;
        if (((byte)(bVar1 + 0x9f) < 0x1a) || (0xdf < bVar1)) {
          bVar1 = bVar1 - 0x20;
        }
        bVar2 = *param_2;
        if (((byte)(bVar2 + 0x9f) < 0x1a) || (0xdf < bVar2)) {
          bVar2 = bVar2 - 0x20;
        }
        if ((char)bVar2 < (char)bVar1) {
          return 1;
        }
        if ((char)bVar1 < (char)bVar2) {
          return 0xffffffff;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (((bVar1 != 0) && (bVar2 != 0)) && (param_3 != 0));
    }
    return 0;
  }
  return 1;
}

