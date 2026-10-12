/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6360; label: FUN_005c6360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c6360(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = 0;
  if (0 < DAT_0097384c) {
    iVar4 = 0;
    iVar2 = DAT_0097384c;
    piVar3 = DAT_00973850;
    do {
      if (param_1 == *(int *)(iVar4 + (int)piVar3)) {
        FUN_005fbd40(iVar4 + (int)piVar3);
        piVar3 = DAT_00973850;
        if (DAT_0097384c != 0) {
          DAT_00973850 = (int *)FUN_004eef40(DAT_0097384c * 0x28 + -0x28,
                                             "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp"
                                             ,0xd0);
          iVar6 = 0;
          if (0 < DAT_0097384c) {
            iVar2 = 0;
            piVar1 = piVar3;
            do {
              if (param_1 != *piVar1) {
                piVar5 = piVar1;
                piVar7 = (int *)(iVar2 + (int)DAT_00973850);
                for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *piVar7 = *piVar5;
                  piVar5 = piVar5 + 1;
                  piVar7 = piVar7 + 1;
                }
                iVar2 = iVar2 + 0x28;
              }
              iVar6 = iVar6 + 1;
              piVar1 = piVar1 + 10;
            } while (iVar6 < DAT_0097384c);
          }
          if (piVar3 != (int *)0x0) {
            FUN_004ef280(piVar3,
                         "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",0xdf)
            ;
          }
          DAT_0097384c = DAT_0097384c + -1;
          return 1;
        }
        FUN_004ef280(DAT_00973850,
                     "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuinstsurfgeom_gen.cpp",200);
        piVar3 = (int *)0x0;
        iVar2 = 0;
        DAT_00973850 = (int *)0x0;
        DAT_0097384c = 0;
      }
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0x28;
    } while (iVar6 < iVar2);
  }
  return 0;
}

