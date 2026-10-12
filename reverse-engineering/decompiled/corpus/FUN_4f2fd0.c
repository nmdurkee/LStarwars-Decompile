/* Ghidra analysis pseudocode, not original source.
 * ev_13e6c2c4ac29a9d5612ecbc9d77509c6da5dca39a1f6ec82bb6af72a765c12b9
 * Entry: 0x4f2fd0; label: FUN_004f2fd0
 */

byte * FUN_004f2fd0(ushort *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  ushort uVar4;
  
  bVar1 = *param_2;
  uVar4 = (ushort)bVar1;
  pbVar3 = param_2 + 1;
  if (0x7f < bVar1) {
    if ((bVar1 & 0xe0) == 0xc0) {
      *param_1 = (bVar1 & 0x1f) << 6 | *pbVar3 & 0x3f;
      return param_2 + 2;
    }
    if ((bVar1 & 0xf0) != 0xe0) {
      return pbVar3;
    }
    bVar2 = *pbVar3;
    pbVar3 = param_2 + 3;
    uVar4 = (bVar2 & 0x3f | (ushort)bVar1 << 6) << 6 | param_2[2] & 0x3f;
  }
  *param_1 = uVar4;
  return pbVar3;
}

