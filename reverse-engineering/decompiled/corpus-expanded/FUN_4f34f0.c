/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f34f0; label: FUN_004f34f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_004f34f0(short *param_1,short *param_2,int *param_3,int param_4)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  bool bVar7;
  int iVar8;
  short *psVar9;
  
  sVar3 = *param_1;
  bVar7 = true;
  do {
    if (sVar3 == 0) {
      return (short *)0x0;
    }
    if ((bVar7) || (param_4 == 0)) {
      sVar4 = *param_2;
      psVar2 = param_1;
      psVar9 = param_2;
      sVar5 = sVar3;
      while (sVar4 != 0) {
        if (sVar5 == 0) {
LAB_004f3592:
          if (*psVar9 != 0) goto LAB_004f35e0;
          break;
        }
        sVar4 = *psVar9;
        iVar8 = FUN_004f3460();
        if (iVar8 == 0) goto LAB_004f3592;
        sVar5 = psVar2[1];
        while (psVar2 = psVar2 + 1, sVar5 != 0) {
          iVar8 = 0;
          sVar6 = DAT_008004ac;
          while (sVar6 != 0) {
            if (sVar6 == sVar5) goto LAB_004f357a;
            psVar1 = &DAT_008004ae + iVar8;
            iVar8 = iVar8 + 1;
            sVar6 = *psVar1;
          }
          if (sVar5 != sVar4) break;
LAB_004f357a:
          sVar5 = psVar2[1];
        }
        psVar9 = psVar9 + 1;
        sVar4 = *psVar9;
      }
      if ((param_4 == 0) || (psVar2[1] == 0)) {
LAB_004f3632:
        *param_3 = (int)psVar2 - (int)param_1 >> 1;
        return param_1;
      }
      iVar8 = 0;
      sVar4 = DAT_008004ac;
      while (sVar4 != 0) {
        if (sVar4 == psVar2[1]) goto LAB_004f3632;
        psVar9 = &DAT_008004ae + iVar8;
        iVar8 = iVar8 + 1;
        sVar4 = *psVar9;
      }
    }
LAB_004f35e0:
    iVar8 = 0;
    sVar4 = DAT_008004ac;
    while (sVar4 != 0) {
      if (sVar4 == sVar3) {
        bVar7 = true;
        goto LAB_004f3607;
      }
      psVar2 = &DAT_008004ae + iVar8;
      iVar8 = iVar8 + 1;
      sVar4 = *psVar2;
    }
    bVar7 = false;
LAB_004f3607:
    sVar3 = param_1[1];
    param_1 = param_1 + 1;
  } while( true );
}

