/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x617a60; label: FUN_00617a60
 */

int FUN_00617a60(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  bool bVar10;
  
  pbVar8 = param_2;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          bVar1 = *param_1;
          uVar5 = (uint)bVar1;
          pbVar7 = param_1 + 1;
          if ((char)bVar1 < '\0') break;
          bVar2 = *pbVar7;
          param_1 = param_1 + 2;
          uVar9 = uVar5 & 3;
          if ((bVar1 & 3) != 0) {
            do {
              uVar9 = uVar9 - 1;
              *pbVar8 = *param_1;
              pbVar8 = pbVar8 + 1;
              param_1 = param_1 + 1;
            } while (uVar9 != 0);
          }
          pbVar7 = pbVar8 + ((uVar5 & 0x60) * -8 - (uint)bVar2) + -1;
          iVar6 = (bVar1 >> 2 & 7) + 2;
          do {
            *pbVar8 = *pbVar7;
            pbVar8 = pbVar8 + 1;
            pbVar7 = pbVar7 + 1;
            bVar10 = iVar6 != 0;
            iVar6 = iVar6 + -1;
          } while (bVar10);
        }
        if ((bVar1 & 0x40) != 0) break;
        bVar1 = *pbVar7;
        bVar2 = param_1[2];
        param_1 = param_1 + 3;
        for (uVar9 = (uint)(bVar1 >> 6); uVar9 != 0; uVar9 = uVar9 - 1) {
          *pbVar8 = *param_1;
          pbVar8 = pbVar8 + 1;
          param_1 = param_1 + 1;
        }
        pbVar7 = pbVar8 + ((bVar1 & 0x3f) * -0x100 - (uint)bVar2) + -1;
        iVar6 = (uVar5 & 0x3f) + 3;
        do {
          *pbVar8 = *pbVar7;
          pbVar8 = pbVar8 + 1;
          pbVar7 = pbVar7 + 1;
          bVar10 = iVar6 != 0;
          iVar6 = iVar6 + -1;
        } while (bVar10);
      }
      if ((bVar1 & 0x20) != 0) break;
      bVar2 = *pbVar7;
      bVar3 = param_1[2];
      uVar9 = (uint)bVar1;
      bVar4 = param_1[3];
      param_1 = param_1 + 4;
      uVar5 = uVar9 & 3;
      if ((bVar1 & 3) != 0) {
        do {
          uVar5 = uVar5 - 1;
          *pbVar8 = *param_1;
          pbVar8 = pbVar8 + 1;
          param_1 = param_1 + 1;
        } while (uVar5 != 0);
      }
      pbVar7 = pbVar8 + (((uint)bVar2 * -0x100 + (uVar9 & 0x10) * -0x1000) - (uint)bVar3) + -1;
      iVar6 = bVar4 + 4 + (uVar9 & 0xc) * 0x40;
      do {
        *pbVar8 = *pbVar7;
        pbVar8 = pbVar8 + 1;
        pbVar7 = pbVar7 + 1;
        bVar10 = iVar6 != 0;
        iVar6 = iVar6 + -1;
      } while (bVar10);
    }
    uVar9 = (bVar1 & 0x1f) * 4 + 4;
    param_1 = pbVar7;
    if (0x70 < uVar9) break;
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pbVar8 = *param_1;
      pbVar8 = pbVar8 + 1;
      param_1 = param_1 + 1;
    }
  }
  uVar5 = uVar5 & 3;
  if ((bVar1 & 3) != 0) {
    do {
      uVar5 = uVar5 - 1;
      *pbVar8 = *pbVar7;
      pbVar8 = pbVar8 + 1;
      pbVar7 = pbVar7 + 1;
    } while (uVar5 != 0);
  }
  return (int)pbVar8 - (int)param_2;
}

