/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e8d50; label: FUN_004e8d50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e8d50(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  float10 fVar7;
  bool local_34 [16];
  short local_24;
  undefined4 local_22 [7];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_34;
  if (DAT_00855de0 == 0) {
    iVar4 = 0;
    if (DAT_00951b50 == 0) {
      sVar1 = (short)_DAT_0088a30c;
      switch(DAT_0088a300) {
      case 1:
      case 2:
        iVar6 = 0;
        if (DAT_0088a321 != 0) {
          do {
            if (iVar6 == (DAT_0088a321 >> 1) + 1) {
              (&local_24)[iVar4] = -1;
              local_34[iVar4] = false;
              iVar4 = iVar4 + 1;
            }
            local_34[iVar4] = (int)(uint)DAT_0088a320 <= iVar6;
            (&local_24)[iVar4] = sVar1;
            iVar6 = iVar6 + 1;
            iVar4 = iVar4 + 1;
          } while (iVar6 < (int)(uint)DAT_0088a321);
        }
        break;
      case 3:
        if (DAT_0088a321 != 0) {
          psVar5 = &local_24;
          for (uVar3 = (uint)(DAT_0088a321 >> 1); uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint *)psVar5 = CONCAT22(sVar1,sVar1);
            psVar5 = psVar5 + 2;
          }
          for (uVar3 = (uint)((DAT_0088a321 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
            *psVar5 = sVar1;
            psVar5 = psVar5 + 1;
          }
          do {
            local_34[iVar4] = (int)(uint)DAT_0088a320 <= iVar4;
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)(uint)DAT_0088a321);
        }
        break;
      case 4:
        uVar3 = (uint)DAT_0088a321;
        local_24 = DAT_0088a35c;
        local_34[0] = DAT_0088a370 == '\0';
        iVar4 = 1;
        if (uVar3 != 0) {
          iVar6 = 0;
          psVar5 = (short *)local_22;
          for (uVar2 = (uint)(DAT_0088a321 >> 1); uVar2 != 0; uVar2 = uVar2 - 1) {
            *(uint *)psVar5 = CONCAT22(sVar1,sVar1);
            psVar5 = psVar5 + 2;
          }
          for (uVar2 = (uint)((DAT_0088a321 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
            *psVar5 = sVar1;
            psVar5 = psVar5 + 1;
          }
          iVar4 = uVar3 + 1;
          do {
            local_34[iVar6 + 1] = (int)(uint)DAT_0088a320 <= iVar6;
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)uVar3);
        }
        (&local_24)[iVar4] = -1;
        iVar4 = iVar4 + 1;
        iVar6 = 0;
        if (DAT_0088a349 != 0) {
          sVar1 = (short)DAT_0088a334;
          psVar5 = &local_24 + iVar4;
          for (uVar3 = (uint)(DAT_0088a349 >> 1); uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint *)psVar5 = CONCAT22(sVar1,sVar1);
            psVar5 = psVar5 + 2;
          }
          for (uVar3 = (uint)((DAT_0088a349 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
            *psVar5 = sVar1;
            psVar5 = psVar5 + 1;
          }
          do {
            local_34[iVar4] = (int)(uint)DAT_0088a348 <= iVar6;
            iVar6 = iVar6 + 1;
            iVar4 = iVar4 + 1;
          } while (iVar6 < (int)(uint)DAT_0088a349);
        }
      }
      iVar6 = 0;
      if (0 < iVar4) {
        do {
          if (((&local_24)[iVar6] == -1) || (local_34[iVar6] == false)) {
            (&DAT_0088a4f0)[iVar6] = 0x3f800000;
          }
          else {
            fVar7 = (float10)FUN_0054fad0((&DAT_0088a4f0)[iVar6],0x3ecccccd,0x3dcccccd);
            (&DAT_0088a4f0)[iVar6] = (float)fVar7;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
      FUN_004ba4d0(&local_24,local_34,&DAT_0088a4f0,iVar4);
      __security_check_cookie(local_4 ^ (uint)local_34);
      return;
    }
    FUN_004ba4d0(DAT_0088a244,DAT_0088a244 + 0x18,DAT_0088a244 + 0x24,
                 *(undefined4 *)(DAT_0088a244 + 0x54));
  }
  __security_check_cookie(local_4 ^ (uint)local_34);
  return;
}

