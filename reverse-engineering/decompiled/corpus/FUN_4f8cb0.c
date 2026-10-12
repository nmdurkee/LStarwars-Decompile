/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8cb0; label: FUN_004f8cb0
 */

uint FUN_004f8cb0(byte *param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar2 = *param_1;
  uVar1 = 0;
  if (bVar2 == 0) {
    return 0;
  }
  do {
    if (((byte)(bVar2 + 0x9f) < 0x1a) || (0xdf < bVar2)) {
      bVar2 = bVar2 - 0x20;
    }
    uVar3 = (uint)bVar2;
    uVar4 = uVar3 - 0x30;
    if (9 < uVar4) {
      if (5 < uVar3 - 0x41) {
        return 0;
      }
      uVar4 = uVar3 - 0x37;
    }
    uVar1 = uVar1 << 4 | uVar4;
    bVar2 = param_1[1];
    param_1 = param_1 + 1;
  } while (bVar2 != 0);
  return uVar1;
}

