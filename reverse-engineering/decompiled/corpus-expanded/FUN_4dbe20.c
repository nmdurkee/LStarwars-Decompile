/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dbe20; label: FUN_004dbe20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dbe20(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  DAT_008824b4 = 0xbf800000;
  DAT_008824b0 = 0xbf800000;
  DAT_00882490 = 0;
  DAT_008824ac = 0xbf800000;
  DAT_008824c0 = 0xbf800000;
  DAT_008824bc = 0xbf800000;
  DAT_008824b8 = 0xbf800000;
  _DAT_008824a0 = 0;
  if (((_DAT_008824aa & 0xc) == 0) && ((DAT_00951b50 == 0 || (*DAT_00882a58 < 3)))) {
    _DAT_008824aa = _DAT_008824aa & 0xffee;
    _DAT_0088249c = 0x40400000;
    DAT_00882490 = 0;
    DAT_008824a6 = 1;
    _DAT_00882a54 = 0;
    DAT_008824a7 = 0;
  }
  else {
    _DAT_0087b8b8 = 0x3f800000;
    _DAT_008824aa = _DAT_008824aa & 0xffe2;
    DAT_008824a6 = 3;
    DAT_008824a7 = 4;
    iVar3 = 0;
    do {
      iVar2 = DAT_0093d814;
      if (iVar3 == 0) {
        iVar2 = DAT_0093d810;
      }
      if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) {
        *(undefined4 *)(iVar2 + 0xdc8) = 0x3f800000;
        puVar1 = (undefined4 *)(iVar2 + 0x68);
        *puVar1 = 0;
        *(undefined4 *)(iVar2 + 0x6c) = 0;
        *(undefined4 *)(iVar2 + 0x70) =
             *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x1c);
        FUN_005b3620(puVar1,puVar1,*(undefined2 *)(iVar2 + 0x27a));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    if (DAT_008765ec != 0) {
      FUN_0057ce90(DAT_008765ec);
      FUN_0042da10(DAT_008765ec);
    }
  }
  FUN_004d8510();
  DAT_00882494 = FUN_0051acd0(*(undefined4 *)(param_1 + 0x2ae8),"Boulders");
  return;
}

