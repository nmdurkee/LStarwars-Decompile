/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c6150; label: FUN_005c6150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c6150(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar1 = FUN_005fbb40();
  iVar4 = DAT_00973850;
  if (iVar1 == 0) {
    return 0;
  }
  if (((param_1 == (int *)0x0) || (*param_1 != 1)) || (iVar1 = param_1[1], iVar1 == 0)) {
    return 0;
  }
  iVar7 = 0;
  if (iVar1 == 0) {
    return 0;
  }
  piVar2 = (int *)(param_1[3] + 4);
  do {
    iVar7 = iVar7 + *piVar2;
    piVar2 = piVar2 + 0x1e;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (iVar7 != 0) {
    DAT_00973850 = FUN_004eef40((DAT_0097384c * 5 + 5) * 8,
                                "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp"
                                ,0x7c);
    iVar1 = 0;
    if (0 < DAT_0097384c) {
      iVar3 = 0;
      do {
        puVar8 = (undefined4 *)(iVar3 + iVar4);
        puVar9 = (undefined4 *)(iVar3 + DAT_00973850);
        for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + 0x28;
      } while (iVar1 < DAT_0097384c);
    }
    if (iVar4 != 0) {
      FUN_004ef280(iVar4,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",0x81)
      ;
    }
    DAT_0097384c = DAT_0097384c + 1;
    puVar8 = (undefined4 *)(DAT_00973850 + -0x28 + DAT_0097384c * 0x28);
    *puVar8 = param_1;
    puVar8[1] = iVar7;
    puVar8[8] = 0;
    puVar8[2] = 0;
    puVar8[4] = 0;
    iVar4 = FUN_005fbb50(puVar8,iVar7);
    if (iVar4 != 0) {
      uVar5 = FUN_004eef40(iVar7 * 0xc,
                           "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",
                           0x91);
      puVar8[3] = uVar5;
      iVar4 = 0;
      if (0 < iVar7) {
        iVar1 = 0;
        do {
          *(int *)(iVar1 + puVar8[3]) = iVar4;
          iVar4 = iVar4 + 1;
          iVar1 = iVar1 + 0xc;
        } while (iVar4 < iVar7);
      }
      iVar4 = param_1[2];
      iVar1 = 0;
      if (iVar4 != 0) {
        piVar2 = (int *)(param_1[4] + 4);
        do {
          if (iVar1 < *piVar2) {
            iVar1 = *piVar2;
          }
          piVar2 = piVar2 + 7;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      if ((DAT_00973854 < iVar1) || (DAT_00973858 == 0)) {
        DAT_00973854 = iVar1;
        iVar4 = FUN_004eef40((iVar1 + 2) * 0x40,
                             "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",
                             0x9d);
        DAT_00973858 = iVar4 + 0x7fU & 0xffffff00;
        if (DAT_00973858 == 0) {
          DAT_00973854 = -1;
        }
      }
      if (iVar7 < DAT_0097385c) {
        if (DAT_00973860 != 0) {
          return 1;
        }
      }
      else if (DAT_00973860 != 0) {
        FUN_004ef280(DAT_00973860,
                     "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",0xaa);
      }
      DAT_0097385c = iVar7;
      iVar4 = FUN_004eef40(iVar7 * 0x50 + 0x80,
                           "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",
                           0xae);
      DAT_00973860 = iVar4 + 0x7fU & 0xffffff00;
      if (DAT_00973860 == 0) {
        DAT_0097385c = -1;
      }
      return 1;
    }
    return 0;
  }
  return 0;
}

