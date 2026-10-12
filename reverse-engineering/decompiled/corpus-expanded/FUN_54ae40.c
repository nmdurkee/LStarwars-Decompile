/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54ae40; label: FUN_0054ae40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0054ae40(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = param_1 * 0x60;
  iVar1 = (&DAT_009253b0)[param_1 * 0x18];
  iVar6 = FUN_0055f450();
  if ((DAT_00926bd4 == (code *)0x0) || (iVar7 = (*DAT_00926bd4)(), iVar7 == 0)) {
    if ((DAT_00926bd0 == 0) &&
       ((((iVar6 != 0 && (iVar6 = *(int *)(iVar6 + 0x128), iVar6 != 0)) && (iVar6 != DAT_00951b88))
        && ((iVar6 != DAT_00951b9c && ((*(uint *)(iVar6 + 100) & 0x400) == 0)))))) {
      iVar6 = 1;
      if (((param_1 < DAT_0093d818) && ((&DAT_0093d7f0)[param_1] != 0)) &&
         (iVar6 = 2, (*(byte *)((&DAT_0093d7f0)[param_1] + 0x1fc) & 0x80) == 0)) {
        iVar6 = 3;
      }
    }
    else {
      iVar6 = 2;
    }
  }
  else {
    iVar6 = 1;
  }
  (&DAT_009253bc)[param_1 * 0x18] = 0;
  (&DAT_009253c0)[param_1 * 0x18] = 0;
  *(undefined4 *)(&DAT_009253c8 + iVar8) = 0;
  *(undefined4 *)(&DAT_009253cc + iVar8) = 0;
  (&DAT_009253b4)[param_1 * 0x18] = 0;
  (&DAT_009253b8)[param_1 * 0x18] = 0;
  if ((iVar1 == 0) || (iVar7 = FUN_006d6020(iVar1,0), iVar7 == 0)) {
    if (iVar6 != 1) {
      return 0;
    }
  }
  else if (iVar6 != 1) {
    if (iVar6 != 3) {
      (&DAT_009253bc)[param_1 * 0x18] = 0;
      fVar5 = (float)*(byte *)(iVar1 + 0x92) - 127.5;
      if (-85.0 <= fVar5) {
        if (85.0 < fVar5) {
          (&DAT_009253bc)[param_1 * 0x18] = DAT_0080229c;
        }
      }
      else {
        (&DAT_009253bc)[param_1 * 0x18] = DAT_00802298;
      }
      uVar4 = DAT_00802290;
      fVar5 = (float)*(byte *)(iVar1 + 0x93) - 127.5;
      if (-85.0 <= fVar5) {
        if (85.0 < fVar5) {
          (&DAT_009253bc)[param_1 * 0x18] = (&DAT_009253bc)[param_1 * 0x18] | DAT_00802294;
        }
      }
      else {
        (&DAT_009253bc)[param_1 * 0x18] = (&DAT_009253bc)[param_1 * 0x18] | DAT_00802290;
      }
      uVar2 = (&DAT_009253bc)[param_1 * 0x18];
      uVar3 = *(uint *)(&DAT_009253c4 + iVar8);
      *(uint *)(&DAT_009253c4 + iVar8) = uVar2;
      (&DAT_009253c0)[param_1 * 0x18] = (uVar3 ^ uVar2) & uVar2;
      *(undefined4 *)(&DAT_009253c8 + iVar8) = 0;
      fVar5 = (float)*(byte *)(iVar1 + 0x90) - 127.5;
      if (-85.0 <= fVar5) {
        if (85.0 < fVar5) {
          *(undefined4 *)(&DAT_009253c8 + iVar8) = DAT_0080229c;
        }
      }
      else {
        *(undefined4 *)(&DAT_009253c8 + iVar8) = DAT_00802298;
      }
      fVar5 = (float)*(byte *)(iVar1 + 0x91) - 127.5;
      if (-85.0 <= fVar5) {
        if (85.0 < fVar5) {
          *(uint *)(&DAT_009253c8 + iVar8) = *(uint *)(&DAT_009253c8 + iVar8) | DAT_00802294;
        }
      }
      else {
        *(uint *)(&DAT_009253c8 + iVar8) = *(uint *)(&DAT_009253c8 + iVar8) | uVar4;
      }
      uVar4 = *(uint *)(&DAT_009253c8 + iVar8);
      *(uint *)(&DAT_009253cc + iVar8) = (*(uint *)(&DAT_009253d0 + iVar8) ^ uVar4) & uVar4;
      _DAT_00926bcc = (&DAT_009253b0)[param_1 * 0x18];
      *(uint *)(&DAT_009253d0 + iVar8) = uVar4;
      (&DAT_009253d4)[iVar8] = 1;
      (&DAT_009253b4)[param_1 * 0x18] = *(undefined4 *)(iVar1 + 0x70);
      (&DAT_009253b8)[param_1 * 0x18] = *(undefined4 *)(iVar1 + 0x78);
      return iVar6;
    }
    (&DAT_009253b8)[param_1 * 0x18] =
         (&DAT_009253b8)[param_1 * 0x18] | *(uint *)(iVar1 + 0x78) & DAT_00802274;
  }
  return iVar6;
}

