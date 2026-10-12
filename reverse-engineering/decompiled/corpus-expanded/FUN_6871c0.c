/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x6871c0; label: FUN_006871c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006871c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    FUN_00620ef0(param_1);
  }
  iVar1 = DAT_02962010;
  if ((*(uint *)(param_1 + 0x70) & 0x100) != 0) {
    if ((DAT_02924af8 == 0) && ((*(byte *)(param_1 + 0x78) & 0x80) != 0)) {
      if (DAT_02961f7c == 0) {
        if ((DAT_02923194 != -1) && (DAT_02962010 != -1)) {
          DAT_02961f7c = 1;
          DAT_0292fd08 = -1;
LAB_00687245:
          FUN_006594c0(0xbf800000);
          goto LAB_00687262;
        }
      }
      else {
        DAT_02961f7c = 0;
      }
    }
    else if (DAT_02961f7c != 0) {
      if (DAT_0292fd08 == -1) goto LAB_00687245;
      if (((*(byte *)(param_1 + 0x78) & 8) != 0) &&
         (DAT_0292fd08 = DAT_0292fd08 + 1, DAT_0292fd08 == (&DAT_0292fe1c)[DAT_02962010 * 0xb5])) {
        DAT_0292fd08 = 0;
      }
      if ((*(byte *)(param_1 + 0x78) & 2) == 0) {
LAB_00687262:
        iVar1 = DAT_02962010;
        if (DAT_0292fd08 == -1) goto LAB_006875c5;
      }
      else {
        DAT_0292fd08 = DAT_0292fd08 + -1;
        if (DAT_0292fd08 == -1) {
          DAT_0292fd08 = (&DAT_0292fe1c)[DAT_02962010 * 0xb5] + -1;
          goto LAB_00687262;
        }
      }
      FUN_005da860(local_18,DAT_02962114,DAT_02923194);
      uVar2 = FUN_005cf9c0(local_18);
      FUN_005b37d0(local_c,uVar2,&DAT_0292ff14 + DAT_02962010 * 0xb5 + DAT_0292fd08 * 3);
      FUN_00620f10(local_c);
      iVar1 = DAT_02962010 * 0x16a + DAT_0292fd08;
      DAT_0296210c = (int)(short)(&DAT_0292ff74)[iVar1];
      DAT_02962110 = (int)(short)(&DAT_0292ff84)[iVar1];
      DAT_02924ac8 = (&DAT_0292feb4)[DAT_02962010 * 0xb5 + DAT_0292fd08];
      iVar1 = DAT_02962010;
      goto LAB_006875c5;
    }
    if ((*(uint *)(param_1 + 0x78) & 0x10) != 0) {
      if (DAT_02924af8 == 0) {
        if (DAT_02923194 != -1) {
          if (DAT_02962010 != -1) {
            DAT_02924af8 = 1;
            DAT_02920aa8 = -1;
            goto LAB_006873d2;
          }
          goto LAB_0068733a;
        }
LAB_0068754e:
        FUN_00659350(0xbf800000);
LAB_0068756c:
        iVar1 = DAT_02962010;
        if (DAT_02923194 == -1) goto LAB_006875c5;
      }
      else {
        DAT_02924af8 = 0;
LAB_0068733a:
        if (DAT_02923194 == -1) goto LAB_0068754e;
        if ((*(byte *)(param_1 + 0x78) & 8) != 0) {
          DAT_02923194 = DAT_02923194 + 1;
          iVar1 = FUN_005da840(DAT_02962114);
          if (DAT_02923194 == iVar1) {
            DAT_02923194 = 0;
          }
        }
        if ((*(byte *)(param_1 + 0x78) & 2) == 0) goto LAB_0068756c;
        DAT_02923194 = DAT_02923194 + -1;
        if (DAT_02923194 == -1) {
          iVar1 = FUN_005da840(DAT_02962114);
          DAT_02923194 = iVar1 + -1;
          goto LAB_0068756c;
        }
      }
      FUN_005da860(local_c,DAT_02962114,DAT_02923194);
      uVar2 = FUN_005cf9c0(local_c);
      FUN_00620f10(uVar2);
      DAT_02962010 = -1;
      iVar1 = 0;
      piVar3 = &DAT_0292fe18;
      do {
        if (*piVar3 == DAT_02923194) goto LAB_006875c5;
        piVar3 = piVar3 + 0xb5;
        iVar1 = iVar1 + 1;
      } while ((int)piVar3 < 0x293b318);
      goto LAB_0068767c;
    }
    if (DAT_02924af8 == 0) goto LAB_0068733a;
    if (DAT_02920aa8 == -1) {
LAB_006873d2:
      FUN_00659650(0xbf800000);
LAB_006873f5:
      iVar1 = DAT_02962010;
      if (DAT_02920aa8 == -1) goto LAB_006875c5;
    }
    else {
      if (((*(uint *)(param_1 + 0x78) & 8) != 0) &&
         (DAT_02920aa8 = DAT_02920aa8 + 1, DAT_02920aa8 == (&DAT_0292fe20)[DAT_02962010 * 0xb5])) {
        DAT_02920aa8 = 0;
      }
      if ((*(byte *)(param_1 + 0x78) & 2) == 0) goto LAB_006873f5;
      DAT_02920aa8 = DAT_02920aa8 + -1;
      if (DAT_02920aa8 == -1) {
        DAT_02920aa8 = (&DAT_0292fe20)[DAT_02962010 * 0xb5] + -1;
        goto LAB_006873f5;
      }
    }
    FUN_005da860(local_c,DAT_02962114,DAT_02923194);
    uVar2 = FUN_005cf9c0(local_c);
    FUN_005b37d0(local_18,uVar2,&DAT_02930078 + DAT_02920aa8 * 0xc + DAT_02962010 * 0x2d4);
    FUN_00620f10(local_18);
    DAT_02924afc = (&DAT_02930018)[DAT_02962010 * 0xb5 + DAT_02920aa8];
    iVar1 = DAT_02962010;
  }
LAB_006875c5:
  DAT_02962010 = iVar1;
  if ((DAT_02962010 != -1) && (iVar1 = 0, 0 < (int)(&DAT_0292fe1c)[DAT_02962010 * 0xb5])) {
    iVar6 = 0;
    iVar5 = DAT_02962010;
    do {
      if ((((&DAT_0292feb4)[iVar5 * 0xb5 + iVar1] == -1) ||
          (*(int *)(DAT_0296209c + (&DAT_0292feb4)[iVar5 * 0xb5 + iVar1] * 4) == 0)) &&
         ((&DAT_0292fe34)[iVar5 * 0x2d4 + iVar6] != '\0')) {
        iVar4 = FUN_00658330(&DAT_0292fe34 + iVar5 * 0x2d4 + iVar6,0,0);
        iVar5 = DAT_02962010;
        (&DAT_0292feb4)[DAT_02962010 * 0xb5 + iVar1] = iVar4;
        if (iVar4 == -1) {
          FUN_00659a30(iVar5,iVar1);
          iVar1 = iVar1 + -1;
          iVar6 = iVar6 + -0x10;
          iVar5 = DAT_02962010;
        }
      }
      iVar1 = iVar1 + 1;
      iVar6 = iVar6 + 0x10;
    } while (iVar1 < (int)(&DAT_0292fe1c)[iVar5 * 0xb5]);
  }
LAB_0068767c:
  FUN_00620fa0(&DAT_0292fda8,&DAT_02921198,&DAT_0292fb6c);
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
      DAT_029620d0 = DAT_029620d4;
    }
    if ((*(byte *)(param_1 + 0x78) & 0x40) != 0) {
      if (DAT_02961f7c == 0) {
        if (DAT_02924af8 == 0) {
          if ((DAT_02923194 != -1) && (DAT_02962010 == -1)) {
            DAT_02962010 = FUN_00686fc0(DAT_02923194);
          }
        }
        else {
          FUN_00687120(&DAT_0292fda8);
        }
      }
      else {
        FUN_00659990(&DAT_0292fda8);
      }
    }
    if ((*(byte *)(param_1 + 0x70) & 0x20) != 0) {
      if (DAT_02961f7c == 0) {
        if ((DAT_02924af8 != 0) && (DAT_02920aa8 != -1)) {
          FUN_00659810(DAT_02920aa8,&DAT_0292fda8);
        }
      }
      else if (DAT_0292fd08 != -1) {
        FUN_00659910(DAT_0292fd08,&DAT_0292fda8);
      }
    }
    if ((*(byte *)(param_1 + 0x78) & 0x10) != 0) {
      if (DAT_02961f7c == 0) {
        if (DAT_02924af8 == 0) {
          if (DAT_02962010 != -1) {
            if ((&DAT_0292fe18)[DAT_02962010 * 0xb5] != -1) {
              (&DAT_0292fe18)[DAT_02962010 * 0xb5] = 0xffffffff;
            }
            DAT_02962108 = DAT_02962108 + -1;
          }
          DAT_02962010 = 0xffffffff;
          DAT_02923194 = 0xffffffff;
          return;
        }
        if (DAT_02920aa8 == -1) {
          return;
        }
        FUN_00659860(DAT_02962010,DAT_02920aa8);
        DAT_02920aa8 = -1;
      }
      else if (DAT_0292fd08 != -1) {
        FUN_00659a30(DAT_02962010,DAT_0292fd08);
        DAT_0292fd08 = -1;
      }
    }
  }
  if (DAT_02961f7c != 0) {
    DAT_02962110 = DAT_02962110 + (uint)*(byte *)(param_1 + 0x94);
    DAT_02962110 = DAT_02962110 - (uint)*(byte *)(param_1 + 0x95);
    iVar1 = DAT_0296210c + (uint)*(byte *)(param_1 + 0x96);
    if (0 < iVar1) {
      iVar1 = 0;
    }
    DAT_0296210c = iVar1 - (uint)*(byte *)(param_1 + 0x97);
    if (DAT_0296210c < -0x8000) {
      DAT_0296210c = -0x8000;
    }
  }
  return;
}

