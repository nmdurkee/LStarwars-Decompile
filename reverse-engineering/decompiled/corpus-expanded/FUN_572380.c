/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x572380; label: FUN_00572380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00572380(void)

{
  int iVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  byte *pbVar5;
  
  DAT_00951004 = 0;
  _DAT_00951008 = 0;
  DAT_00802524 = 0x10;
  pbVar5 = &DAT_008034d8;
  iVar4 = 2;
  do {
    bVar2 = (byte)iVar4;
    uVar3 = (ushort)(1 << (bVar2 - 2 & 0x1f));
    if ((pbVar5[-0xc] & 4) == 0) {
      _DAT_00951008 = _DAT_00951008 | uVar3;
    }
    else {
      DAT_00951004 = DAT_00951004 | uVar3;
    }
    uVar3 = (ushort)(1 << (bVar2 - 1 & 0x1f));
    if ((*pbVar5 & 4) == 0) {
      _DAT_00951008 = _DAT_00951008 | uVar3;
    }
    else {
      DAT_00951004 = DAT_00951004 | uVar3;
    }
    uVar3 = (ushort)(1 << (bVar2 & 0x1f));
    if ((pbVar5[0xc] & 4) == 0) {
      _DAT_00951008 = _DAT_00951008 | uVar3;
    }
    else {
      DAT_00951004 = DAT_00951004 | uVar3;
    }
    uVar3 = (ushort)(1 << (bVar2 + 1 & 0x1f));
    if ((pbVar5[0x18] & 4) == 0) {
      _DAT_00951008 = _DAT_00951008 | uVar3;
    }
    else {
      DAT_00951004 = DAT_00951004 | uVar3;
    }
    iVar1 = iVar4 + 2;
    pbVar5 = pbVar5 + 0x30;
    iVar4 = iVar4 + 4;
  } while (iVar1 < 0x20);
  return;
}

