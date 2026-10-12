/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x657a00; label: FUN_00657a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00657a00(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  iVar7 = 0;
  uVar2 = _DAT_02962064;
  iVar4 = DAT_0292fbfc;
  if (param_1 == 0) {
    for (; _DAT_0296205c = uVar2, iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
      *(float *)(iVar4 + 4) = *(float *)(iVar4 + 4) - 800.0;
      uVar2 = _DAT_0296205c;
    }
  }
  else {
    uVar2 = _DAT_02962068;
    iVar4 = DAT_0292fc00;
    if (param_1 == 1) {
      for (; _DAT_02962060 = uVar2, iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
        *(float *)(iVar4 + 4) = *(float *)(iVar4 + 4) - 800.0;
        uVar2 = _DAT_02962060;
      }
    }
  }
  local_8 = 0;
  iVar4 = DAT_029620a4;
  iVar6 = DAT_0296209c;
  if (0 < DAT_02962094) {
    do {
      iVar3 = *(int *)(iVar6 + *(short *)(iVar7 + 0x182 + iVar4) * 4);
      if (*(char *)(iVar3 + 0x2f1) == '\x04') {
        if (param_1 == 1) {
LAB_00657aad:
          cVar1 = *(char *)(iVar3 + 0x2e);
          *(float *)(iVar7 + 800 + iVar4) = *(float *)(iVar7 + 800 + iVar4) - 800.0;
          iVar8 = 0x20;
          *(float *)(iVar7 + 0x324 + DAT_029620a4) =
               *(float *)(iVar7 + 0x324 + DAT_029620a4) - 800.0;
          *(float *)(iVar7 + 0x1e0 + DAT_029620a4) =
               *(float *)(iVar7 + 0x1e0 + DAT_029620a4) - 800.0;
          *(float *)(iVar7 + 0x1dc + DAT_029620a4) =
               *(float *)(iVar7 + 0x1dc + DAT_029620a4) - 800.0;
          *(float *)(iVar7 + 0x1e4 + DAT_029620a4) =
               *(float *)(iVar7 + 0x1e4 + DAT_029620a4) - 800.0;
          iVar3 = iVar7 + 0x100;
          iVar4 = DAT_029620a4;
          do {
            if (*(int *)(iVar3 + iVar4) != 0) {
              iVar6 = 0;
              if (cVar1 == '\a') {
                do {
                  iVar5 = iVar6 + 0xc0;
                  *(float *)(iVar6 + 0x2c + *(int *)(iVar3 + iVar4)) =
                       *(float *)(iVar6 + 0x2c + *(int *)(iVar3 + iVar4)) - 800.0;
                  *(float *)(iVar6 + 0x4c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x4c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0x6c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x6c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0x8c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x8c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0xac + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0xac + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0xcc + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0xcc + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  iVar6 = iVar5;
                  iVar4 = DAT_029620a4;
                } while (iVar5 < 0x180);
              }
              else {
                do {
                  iVar5 = iVar6 + 0x100;
                  *(float *)(iVar6 + 0x2c + *(int *)(iVar3 + iVar4)) =
                       *(float *)(iVar6 + 0x2c + *(int *)(iVar3 + iVar4)) - 800.0;
                  *(float *)(iVar6 + 0x4c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x4c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0x6c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x6c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0x8c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x8c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0xac + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0xac + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0xcc + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0xcc + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0xec + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0xec + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  *(float *)(iVar6 + 0x10c + *(int *)(iVar3 + DAT_029620a4)) =
                       *(float *)(iVar6 + 0x10c + *(int *)(iVar3 + DAT_029620a4)) - 800.0;
                  iVar6 = iVar5;
                  iVar4 = DAT_029620a4;
                } while (iVar5 < 0x400);
              }
            }
            iVar3 = iVar3 + 4;
            iVar8 = iVar8 + -1;
            iVar6 = DAT_0296209c;
          } while (iVar8 != 0);
        }
      }
      else if (param_1 == 0) goto LAB_00657aad;
      local_8 = local_8 + 1;
      iVar7 = iVar7 + 0x330;
    } while (local_8 < DAT_02962094);
  }
  iVar4 = 1;
  if (1 < DAT_02962098) {
    do {
      if (*(int *)(iVar6 + iVar4 * 4) != 0) {
        if (*(char *)(*(int *)(iVar6 + iVar4 * 4) + 0x2f1) == '\x04') {
          if (param_1 == 1) {
LAB_00657d76:
            iVar7 = *(int *)(iVar6 + iVar4 * 4);
            *(float *)(iVar7 + 0x2ac) = *(float *)(iVar7 + 0x2ac) - 800.0;
            iVar7 = *(int *)(DAT_0296209c + iVar4 * 4);
            iVar6 = DAT_0296209c;
            if (*(int *)(iVar7 + 0x2a8) != 0) {
              iVar7 = *(int *)(iVar7 + 0x2a8);
              *(float *)(iVar7 + 0x14) = *(float *)(iVar7 + 0x14) - 800.0;
              iVar6 = DAT_0296209c;
            }
          }
        }
        else if (param_1 == 0) goto LAB_00657d76;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_02962098);
  }
  return;
}

