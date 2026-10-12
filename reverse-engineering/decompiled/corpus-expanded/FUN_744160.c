/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x744160; label: FUN_00744160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined ** FUN_00744160(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  undefined **ppuVar6;
  bool bVar7;
  
  iVar2 = 0;
  ppuVar6 = &PTR_s_ambientColor_0082b1d0;
  do {
    pbVar3 = ppuVar6[1];
    pbVar5 = param_1;
    if (pbVar3 != (byte *)0x0) {
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_007441a0:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_007441a5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_007441a0;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_007441a5:
      if (iVar4 == 0) goto LAB_007441ee;
    }
    pbVar3 = *ppuVar6;
    pbVar5 = param_1;
    if (pbVar3 != (byte *)0x0) {
      do {
        bVar1 = *pbVar3;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_007441d1:
          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_007441d6;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_007441d1;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_007441d6:
      if (iVar4 == 0) {
LAB_007441ee:
        return &PTR_s_ambientColor_0082b1d0 + iVar2 * 0x17;
      }
    }
    ppuVar6 = ppuVar6 + 0x17;
    iVar2 = iVar2 + 1;
    if (0x82d5bf < (int)ppuVar6) {
      return (undefined **)0x0;
    }
  } while( true );
}

