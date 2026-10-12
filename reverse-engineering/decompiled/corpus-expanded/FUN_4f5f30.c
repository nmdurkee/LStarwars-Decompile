/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5f30; label: FUN_004f5f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f5f30(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)((int)&DAT_008cf398 + (DAT_0297e024 >> 0x18) * 2);
  if (0xd < uVar4) {
    uVar3 = 0x800000;
    do {
      if ((uVar3 & DAT_0297e024) == 0) {
        uVar2 = *(ushort *)(&DAT_02982740 + uVar4 * 2);
      }
      else {
        uVar2 = *(ushort *)(&DAT_02982f40 + uVar4 * 2);
      }
      uVar4 = (uint)uVar2;
      uVar3 = uVar3 >> 1;
    } while (0xd < uVar4);
  }
  FUN_004f5d00((&DAT_0091ce68)[uVar4]);
  if (uVar4 != 0) {
    iVar1 = uVar4 - 1;
    if (iVar1 == 0) {
      return 1 << ((char)uVar4 - 1U & 0x1f);
    }
    uVar3 = DAT_0297e024 >> (0x20U - (char)iVar1 & 0x1f);
    FUN_004f5d00(iVar1);
    return (1 << ((char)uVar4 - 1U & 0x1f)) + uVar3;
  }
  return 0;
}

