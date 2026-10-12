/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x684ee0; label: FUN_00684ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00684ee0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if ((((param_2 != -1) && (param_2 != 0)) && (param_2 < DAT_02962098)) &&
     ((iVar9 = *(int *)(DAT_0296209c + param_2 * 4), iVar9 != 0 && (*(char *)(iVar9 + 0x13) == '\0')
      ))) {
    iVar3 = *param_1;
    if (iVar3 == -1) {
      iVar4 = FUN_006550b0();
      *param_1 = iVar4;
    }
    iVar4 = *param_1;
    if (iVar4 != -1) {
      fVar1 = _DAT_0296205c;
      if (*(char *)(iVar9 + 0x2f1) == '\x04') {
        fVar1 = _DAT_02962060;
      }
      iVar8 = iVar4 * 0x330;
      *(short *)(iVar8 + 0x182 + DAT_029620a4) = (short)param_2;
      *(undefined1 *)(iVar8 + 0x184 + DAT_029620a4) = 0;
      FUN_00655da0(iVar4,*(undefined4 *)(iVar9 + 0x18));
      *(undefined **)(iVar8 + 0x1c0 + DAT_029620a4) = (&PTR_FUN_00810910)[*(char *)(iVar9 + 0x2c)];
      *(undefined4 *)(iVar8 + 0x1c4 + DAT_029620a4) =
           *(undefined4 *)(&DAT_00810944 + *(char *)(iVar9 + 0x2d) * 4);
      *(undefined4 *)(iVar8 + 0x1d4 + DAT_029620a4) = 0;
      *(undefined2 *)(iVar8 + 0x1d0 + DAT_029620a4) = 0;
      *(undefined2 *)(iVar8 + 0x1d2 + DAT_029620a4) = 0;
      *(undefined2 *)(iVar8 + 0x2c8 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x2cc + DAT_029620a4) = 0;
      iVar5 = 0;
      iVar7 = iVar8;
      if ('\0' < *(char *)(*(int *)(DAT_0296209c + param_2 * 4) + 0x2f0)) {
        do {
          *(undefined4 *)(iVar7 + 0x200 + DAT_029620a4) = 0xbf800000;
          iVar5 = iVar5 + 1;
          iVar7 = iVar7 + 0x1c;
        } while (iVar5 < *(char *)(*(int *)(DAT_0296209c + param_2 * 4) + 0x2f0));
      }
      *(undefined4 *)(iVar8 + 0x19c + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1a0 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1a4 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1a8 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1ac + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1b0 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1b4 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1b8 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x1bc + DAT_029620a4) = 0;
      *(undefined2 *)(iVar8 + 0x2f2 + DAT_029620a4) = 0xffff;
      *(undefined1 *)(iVar8 + 0x1da + DAT_029620a4) = 7;
      *(undefined4 *)(iVar8 + 0x2fc + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x300 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x31c + DAT_029620a4) = 0x497423f0;
      *(undefined1 *)(iVar8 + 0x2f5 + DAT_029620a4) = 0;
      *(float *)(iVar8 + 800 + DAT_029620a4) = fVar1;
      *(undefined1 *)(iVar8 + 0x2f9 + DAT_029620a4) = 1;
      *(undefined4 *)(iVar8 + 0x32c + DAT_029620a4) = 0;
      *(undefined1 *)(iVar8 + 0x2fa + DAT_029620a4) = 0;
      if (*(float *)(iVar8 + 0x1e4 + DAT_029620a4) < fVar1) {
        fVar1 = *(float *)(iVar8 + 0x1e4 + DAT_029620a4);
      }
      *(float *)(iVar8 + 0x324 + DAT_029620a4) = fVar1;
      *(undefined2 *)(iVar8 + 0x1d8 + DAT_029620a4) = 0;
      cVar2 = *(char *)(iVar9 + 0x2e);
      if (cVar2 == '\x02') {
        *(undefined2 *)(iVar8 + 0x328 + DAT_029620a4) = 50000;
      }
      else if (cVar2 == '\x03') {
        *(undefined2 *)(iVar8 + 0x328 + DAT_029620a4) = 40000;
      }
      else if (cVar2 == '\a') {
        *(undefined2 *)(iVar8 + 0x328 + DAT_029620a4) = 20000;
      }
      else {
        *(undefined2 *)(iVar8 + 0x328 + DAT_029620a4) = 30000;
      }
      iVar7 = iVar8 + 0x2e8;
      piVar6 = (int *)(iVar9 + 0x3e4);
      iVar9 = 4;
      do {
        *(undefined2 *)(iVar7 + DAT_029620a4) = 9999;
        if (piVar6[-1] != -1) {
          if ((*piVar6 == 4) || (*piVar6 == 3)) {
            *(undefined2 *)(iVar7 + DAT_029620a4) = 1;
          }
          *(undefined1 *)(iVar8 + 0x2f5 + DAT_029620a4) = 1;
        }
        iVar7 = iVar7 + 2;
        piVar6 = piVar6 + 3;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      FUN_00655940(iVar4,param_3,param_4,param_5);
      FUN_006846a0(iVar4,0,0,0);
      FUN_00684640(iVar4,0,0);
      FUN_00655ba0(iVar4,0,0,0,0x3f666666);
      *(undefined4 *)(iVar8 + 0x2d0 + DAT_029620a4) = 0;
      *(undefined4 *)(iVar8 + 0x2d4 + DAT_029620a4) = 0xffffffff;
      *(undefined4 *)(iVar8 + 0x2d8 + DAT_029620a4) = 0;
      if (iVar3 == -1) {
        iVar8 = DAT_029620a4 + iVar8;
        if (DAT_029620a8 != 0) {
          *(int *)(DAT_029620a8 + 0x1cc) = iVar8;
        }
        *(int *)(iVar8 + 0x1c8) = DAT_029620a8;
        DAT_029620a8 = iVar8;
      }
    }
  }
  return;
}

