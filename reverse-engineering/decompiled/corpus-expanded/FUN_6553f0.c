/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x6553f0; label: FUN_006553f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006553f0(int *param_1)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar5 = *param_1 * 0x330 + DAT_029620a4;
  sVar2 = *(short *)(iVar5 + 0x182);
  if ((sVar2 != 0) && (iVar7 = *(int *)(DAT_0296209c + sVar2 * 4), *(short *)(iVar5 + 0x180) != 0))
  {
    do {
    } while (DAT_02962058 != 0);
    iVar5 = *param_1;
    iVar9 = 0;
    DAT_02962058 = 1;
    if (0 < *(short *)(iVar5 * 0x330 + 0x180 + DAT_029620a4)) {
      do {
        FUN_00655250(*(undefined4 *)(DAT_029620a4 + 0x100 + (iVar5 * 0xcc + iVar9) * 4));
        **(undefined4 **)(DAT_02923198 + DAT_02947b70 * 4) =
             *(undefined4 *)(DAT_029620a4 + 0x100 + (*param_1 * 0xcc + iVar9) * 4);
        iVar5 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
        if (*(char *)(iVar7 + 0x2e) == '\a') {
          *(undefined4 *)(iVar5 + 8) = 9;
        }
        else {
          *(undefined4 *)(iVar5 + 8) = 2;
        }
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0xc) = 0;
        bVar10 = *(char *)(iVar7 + 0x2f1) == '\x04';
        uVar4 = _DAT_0296205c;
        if (bVar10) {
          uVar4 = _DAT_02962060;
        }
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 4) = uVar4;
        iVar8 = (&DAT_0292fbfc)[bVar10];
        iVar5 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
        piVar1 = &DAT_0292fbfc + bVar10;
        while ((iVar8 != 0 && (iVar3 = *piVar1, *(float *)(iVar3 + 4) < *(float *)(iVar5 + 4)))) {
          iVar8 = *(int *)(iVar3 + 0x10);
          piVar1 = (int *)(iVar3 + 0x10);
        }
        *(int *)(iVar5 + 0x10) = *piVar1;
        *piVar1 = iVar5;
        DAT_02947b70 = DAT_02947b70 + 1;
        iVar5 = *param_1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(short *)(iVar5 * 0x330 + 0x180 + DAT_029620a4));
    }
    iVar9 = 0;
    DAT_02962058 = 0;
    iVar5 = DAT_029620a4;
    if (0 < DAT_008108ec + DAT_008108e8) {
      iVar8 = 0;
      do {
        iVar3 = *param_1 * 0x330 + iVar5;
        iVar6 = DAT_02961fec + iVar8;
        if (*(int *)(DAT_02961fec + iVar8) == *(int *)(iVar3 + 0x100)) {
          if (*(char *)(iVar3 + 0x2f6) != '\0') {
            if ((&DAT_0292fd30)[*(char *)(iVar7 + 0x2f1)] == iVar6) {
              iVar5 = *(int *)(iVar6 + 0x5c);
              (&DAT_0292fd30)[*(char *)(iVar7 + 0x2f1)] = iVar5;
              if (iVar5 != 0) {
                *(undefined4 *)(iVar5 + 0x58) = 0;
              }
            }
            else if (*(int *)(iVar6 + 0x58) != 0) {
              *(undefined4 *)(*(int *)(iVar6 + 0x58) + 0x5c) = *(undefined4 *)(iVar6 + 0x5c);
              if (*(int *)(iVar6 + 0x5c) != 0) {
                *(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x58) = *(undefined4 *)(iVar6 + 0x58);
              }
            }
            *(undefined4 *)(iVar6 + 0x58) = 0;
            *(undefined4 *)(iVar6 + 0x5c) = 0;
          }
          *(undefined4 *)(iVar8 + DAT_02961fec) = 0;
          *(undefined4 *)(iVar8 + 4 + DAT_02961fec) = 0;
          iVar5 = DAT_029620a4;
        }
        iVar9 = iVar9 + 1;
        iVar8 = iVar8 + 100;
      } while (iVar9 < DAT_008108ec + DAT_008108e8);
    }
    iVar7 = *param_1;
    iVar9 = 0;
    if (0 < *(short *)(iVar7 * 0x330 + 0x180 + iVar5)) {
      do {
        *(undefined4 *)(iVar5 + 0x100 + (iVar7 * 0xcc + iVar9) * 4) = 0;
        iVar7 = *param_1;
        iVar9 = iVar9 + 1;
        iVar5 = DAT_029620a4;
      } while (iVar9 < *(short *)(iVar7 * 0x330 + 0x180 + DAT_029620a4));
    }
    *(undefined2 *)(*param_1 * 0x330 + 0x186 + iVar5) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x180 + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x18e + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x18c + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x188 + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x18a + DAT_029620a4) = 0;
  }
  return;
}

