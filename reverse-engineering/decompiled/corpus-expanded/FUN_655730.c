/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x655730; label: FUN_00655730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00655730(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int local_4;
  
  do {
  } while (DAT_02962058 != 0);
  DAT_02962058 = 1;
  local_4 = 0;
  if (0 < DAT_008108ec + DAT_008108e8) {
    iVar6 = 0;
    iVar5 = DAT_02961fec;
    do {
      if ((*(int *)(iVar6 + 8 + iVar5) == 0) && (*(int *)(iVar6 + 4 + iVar5) == param_1)) {
        FUN_00655250(*(undefined4 *)(iVar6 + iVar5));
        **(undefined4 **)(DAT_02923198 + DAT_02947b70 * 4) = *(undefined4 *)(iVar6 + DAT_02961fec);
        iVar5 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
        if (*(char *)(param_1 + 0x2e) == '\a') {
          *(undefined4 *)(iVar5 + 8) = 9;
        }
        else {
          *(undefined4 *)(iVar5 + 8) = 2;
        }
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0xc) = 0;
        bVar7 = *(char *)(param_1 + 0x2f1) == '\x04';
        uVar4 = _DAT_0296205c;
        if (bVar7) {
          uVar4 = _DAT_02962060;
        }
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 4) = uVar4;
        iVar2 = (&DAT_0292fbfc)[bVar7];
        iVar5 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
        piVar1 = &DAT_0292fbfc + bVar7;
        while ((iVar2 != 0 && (iVar3 = *piVar1, *(float *)(iVar3 + 4) < *(float *)(iVar5 + 4)))) {
          iVar2 = *(int *)(iVar3 + 0x10);
          piVar1 = (int *)(iVar3 + 0x10);
        }
        *(int *)(iVar5 + 0x10) = *piVar1;
        *piVar1 = iVar5;
        DAT_02947b70 = DAT_02947b70 + 1;
        iVar5 = iVar6 + DAT_02961fec;
        if ((&DAT_0292fd30)[*(char *)(param_1 + 0x2f1)] == iVar5) {
          iVar2 = *(int *)(iVar5 + 0x5c);
          (&DAT_0292fd30)[*(char *)(param_1 + 0x2f1)] = iVar2;
          if (iVar2 != 0) {
            *(undefined4 *)(iVar2 + 0x58) = 0;
          }
        }
        else if (*(int *)(iVar5 + 0x58) != 0) {
          *(undefined4 *)(*(int *)(iVar5 + 0x58) + 0x5c) = *(undefined4 *)(iVar5 + 0x5c);
          if (*(int *)(iVar5 + 0x5c) != 0) {
            *(undefined4 *)(*(int *)(iVar5 + 0x5c) + 0x58) = *(undefined4 *)(iVar5 + 0x58);
          }
        }
        *(undefined4 *)(iVar5 + 0x58) = 0;
        *(undefined4 *)(iVar5 + 0x5c) = 0;
        *(undefined4 *)(iVar6 + DAT_02961fec) = 0;
        *(undefined4 *)(iVar6 + 4 + DAT_02961fec) = 0;
        iVar5 = DAT_02961fec;
      }
      local_4 = local_4 + 1;
      iVar6 = iVar6 + 100;
    } while (local_4 < DAT_008108ec + DAT_008108e8);
  }
  DAT_02962058 = 0;
  return;
}

