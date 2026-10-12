/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554ac0; label: FUN_00554ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00554ac0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int unaff_ESI;
  int local_14;
  short local_4;
  
  if (((((unaff_ESI != 0) && (iVar3 = *(int *)(unaff_ESI + 0x68), iVar3 != 0)) &&
       (iVar4 = *(int *)(unaff_ESI + 0x6c), iVar4 != 0)) &&
      ((*(int *)(iVar4 + 0x10) != 0 && (param_1 != -1)))) &&
     (uVar5 = *(uint *)(unaff_ESI + 0x84), (uVar5 & 0x40) == 0)) {
    fVar1 = *(float *)(*(int *)(iVar4 + 0x10) + 0x54);
    if ((((uVar5 & 2) == 0) || ((uVar5 & 4) != 0)) && (((uVar5 & 2) != 0 || ((uVar5 & 4) == 0)))) {
      local_14 = -1;
    }
    else {
      local_14 = 1;
    }
    fVar6 = (*(float *)(iVar4 + 0x1c) - *(float *)(iVar4 + 0x18)) + 1.0;
    if (*(char *)(unaff_ESI + 0xa4) == '\x01') {
      fVar7 = 1.0;
    }
    else {
      fVar7 = (*(float *)(unaff_ESI + 0x2e0 + param_1 * 4) - 1.0) / (fVar6 - 1.0);
    }
    fVar2 = *(float *)(unaff_ESI + 0x78);
    fVar8 = ABS((fVar1 * *(float *)(unaff_ESI + 0x78) * 60.0) / fVar6);
    fVar9 = ABS(fVar7 - *(float *)(unaff_ESI + 0x70));
    if (fVar9 < 0.001) {
      FUN_005a1170(iVar3);
      FUN_005a1270(*(undefined4 *)(unaff_ESI + 0x68),fVar7);
      local_4 = (short)(int)ROUND(((fVar7 * 100.0 *
                                    ((ABS(fVar6 / (fVar1 * fVar2 * 60.0)) * 30.0) / fVar6) *
                                    (fVar6 / 100.0) * 65536.0) / 360.0) * (float)local_14);
      *(short *)(unaff_ESI + 0x7c) = local_4 + *(short *)(unaff_ESI + 0x82);
      return;
    }
    if (fVar7 < *(float *)(unaff_ESI + 0x70)) {
      FUN_005a1030(iVar3,0xbe800000,1);
      local_4 = (short)(int)ROUND(fVar9 * fVar8 * 5461.0 * (float)local_14);
      *(short *)(unaff_ESI + 0x7c) = *(short *)(unaff_ESI + 0x7c) - local_4;
      return;
    }
    if (*(float *)(unaff_ESI + 0x70) < fVar7) {
      FUN_005a1030(iVar3,0x3e800000,1);
      local_4 = (short)(int)ROUND(fVar9 * fVar8 * 5461.0 * (float)local_14);
      *(short *)(unaff_ESI + 0x7c) = *(short *)(unaff_ESI + 0x7c) + local_4;
    }
  }
  return;
}

