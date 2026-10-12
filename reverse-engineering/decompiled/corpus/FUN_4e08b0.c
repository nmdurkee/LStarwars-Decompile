/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e08b0; label: FUN_004e08b0
 */

void FUN_004e08b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  
  iVar3 = 0;
  if ('\0' < DAT_0088947c) {
    puVar5 = &DAT_0088916c;
    do {
      uVar4 = 1 << ((byte)iVar3 & 0x1f);
      FUN_005cfc00(puVar5 + -0xc0,(int)*DAT_00882b74 & uVar4);
      FUN_005cfc00(puVar5,(int)DAT_00882b74[1] & uVar4);
      FUN_005cfc00(puVar5 + 0xc0,(int)DAT_00882b74[2] & uVar4);
      FUN_005cfc00(puVar5 + 0x240,(int)DAT_00882b74[4] & uVar4);
      FUN_005cfc00(puVar5 + 0x180,(int)DAT_00882b74[3] & uVar4);
      if ((uVar4 & (int)DAT_00882b74[5]) != 0) {
        iVar1 = FUN_005d0330(puVar5 + 0x180);
        FUN_00681f40("Kam_DiscoFloorPanelOn",iVar1 + 0x30);
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 0xc;
    } while (iVar3 < DAT_0088947c);
  }
  puVar5 = &DAT_00882b78;
  if ((char)DAT_00882b74[6] == '\0') {
    puVar6 = &DAT_0088908c;
    do {
      FUN_005cfc00(puVar5,0);
      FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),*puVar6,1,0);
      puVar5 = puVar5 + 0xc;
      puVar6 = puVar6 + 1;
    } while ((int)puVar5 < 0x882b9c);
    FUN_005cfc00(&DAT_00882b48,0);
    FUN_005cfc00(&DAT_00882b54,0);
    FUN_005cfc00(&DAT_00882b14,1);
    FUN_005cfc00(&DAT_00882b20,1);
    FUN_005cfc00(&DAT_00882bac,1);
    FUN_005cfc00(&DAT_00882bb8,0);
    FUN_005cfc00(&DAT_00882af8,0);
    FUN_005cfc00(&DAT_00882b04,0);
    FUN_005cfc00(&DAT_00889004,0);
    FUN_005cfc00(&DAT_00882b9c,1);
  }
  else {
    iVar3 = 0;
    do {
      FUN_005cfc00(puVar5,1);
      FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),(&DAT_0088908c)[iVar3],0,0);
      puVar5 = puVar5 + 0xc;
      iVar3 = iVar3 + 1;
    } while ((int)puVar5 < 0x882b9c);
    FUN_005cfc00(&DAT_00882b48,1);
    FUN_005cfc00(&DAT_00882b54,1);
    FUN_005cfc00(&DAT_00882b14,0);
    FUN_005cfc00(&DAT_00882b20,0);
    FUN_005cfc00(&DAT_00882bac,0);
    FUN_005cfc00(&DAT_00882bb8,1);
    FUN_005cfc00(&DAT_00882af8,1);
    FUN_005cfc00(&DAT_00882b04,1);
    FUN_005cfc00(&DAT_00882b9c,0);
    FUN_005cfc00(&DAT_00889004,1);
    if (DAT_00889484 == '\0') {
      uVar2 = FUN_005cf9e0(&DAT_008890ac + iVar3 * 0xc);
      FUN_00681f40("Kam_DiscoFloorPanelDone",uVar2);
      DAT_00889484 = 1;
      return;
    }
  }
  return;
}

