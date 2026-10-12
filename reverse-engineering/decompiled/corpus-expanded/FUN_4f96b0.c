/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f96b0; label: FUN_004f96b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f96b0(void)

{
  ushort uVar1;
  uint uVar2;
  size_t _Size;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar5 = DAT_0297e024 >> 0x17;
  FUN_004f5d00(9);
  uVar4 = DAT_0297e024;
  if (uVar5 == 0) {
    FUN_004f5d00(9);
    _memset(&DAT_0090f598,0,0x1fe);
    uVar1 = (ushort)(uVar4 >> 0x17);
    puVar6 = &DAT_00913fa8;
    for (iVar3 = 0x800; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = CONCAT22(uVar1,uVar1);
      puVar6 = puVar6 + 1;
    }
    return;
  }
  iVar3 = 0;
  if (uVar5 != 0) {
    do {
      uVar4 = (uint)*(ushort *)((int)&DAT_008cf398 + (DAT_0297e024 >> 0x18) * 2);
      if (0x12 < uVar4) {
        uVar2 = 0x800000;
        do {
          if ((uVar2 & DAT_0297e024) == 0) {
            uVar1 = *(ushort *)(&DAT_02982740 + uVar4 * 2);
          }
          else {
            uVar1 = *(ushort *)(&DAT_02982f40 + uVar4 * 2);
          }
          uVar4 = (uint)uVar1;
          uVar2 = uVar2 >> 1;
        } while (0x12 < uVar4);
      }
      FUN_004f5d00((&DAT_0091ce68)[uVar4]);
      if (uVar4 < 3) {
        if (uVar4 == 0) {
          _Size = 1;
        }
        else if (uVar4 == 1) {
          uVar4 = DAT_0297e024 >> 0x1c;
          FUN_004f5d00(4);
          _Size = uVar4 + 3;
        }
        else {
          uVar4 = DAT_0297e024 >> 0x17;
          FUN_004f5d00(9);
          _Size = uVar4 + 0x14;
        }
        if (-1 < (int)(_Size - 1)) {
          _memset(&DAT_0090f598 + iVar3,0,_Size);
          iVar3 = iVar3 + _Size;
        }
      }
      else {
        (&DAT_0090f598)[iVar3] = (char)uVar4 + -2;
        iVar3 = iVar3 + 1;
      }
    } while (iVar3 < (int)uVar5);
    if (0x1fd < iVar3) goto LAB_004f97f9;
  }
  _memset(&DAT_0090f598 + iVar3,0,0x1fe - iVar3);
LAB_004f97f9:
  FUN_004f6000(0x1fe,&DAT_0090f598,0xc,&DAT_00913fa8);
  return;
}

