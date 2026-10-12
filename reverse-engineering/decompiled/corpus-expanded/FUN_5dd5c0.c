/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5dd5c0; label: FUN_005dd5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dd5c0(undefined4 *param_1,float *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar11;
  float10 fVar12;
  float local_40 [5];
  undefined4 local_2c;
  float local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *param_1;
  pfVar6 = (float *)&DAT_00806680;
  pfVar7 = local_40;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar7 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    pfVar7 = pfVar7 + 1;
  }
  local_c = 0;
  local_8 = param_1[2];
  local_40[0] = *param_2 * 0.5;
  local_2c = 0x3f800000;
  local_18 = param_2[2] * 0.5;
  fVar2 = 2.0 / (float)param_4;
  local_10 = uVar1;
  FUN_00607ec0(0xe,5,0,local_40);
  fVar8 = (float10)-1.0;
  if (param_3 < 0) {
    fVar11 = (float10)0;
    fVar12 = (float10)1;
  }
  else {
    fVar9 = (float10)(2.0 / (float)param_3);
    param_3 = param_3 + 1;
    fVar10 = fVar8;
    do {
      param_1 = (undefined4 *)(float)fVar10;
      FUN_005c1f70();
      fVar10 = (float10)(float)param_1;
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)param_1;
      pfVar6[1] = (float)extraout_ST1;
      *(float *)(*DAT_02854d10 + 8) = (float)fVar8;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      DAT_02854d14 = DAT_02854d14 + 1;
      fVar11 = extraout_ST1;
      fVar8 = (float10)FUN_005c1f70();
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar10;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = (float)extraout_ST1_00;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      DAT_02854d14 = DAT_02854d14 + 1;
      fVar10 = fVar9 + fVar10;
      param_3 = param_3 + -1;
      fVar12 = extraout_ST1_00;
    } while (param_3 != 0);
  }
  param_1 = (undefined4 *)(float)fVar8;
  iVar4 = 0;
  if (3 < param_4 + 1) {
    uVar5 = param_4 + 1U >> 2;
    iVar4 = uVar5 * 4;
    do {
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar8;
      pfVar6[1] = (float)fVar11;
      *(undefined4 **)(*DAT_02854d10 + 8) = param_1;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar12;
      pfVar6[1] = (float)fVar11;
      *(undefined4 **)(*DAT_02854d10 + 8) = param_1;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      fVar3 = (float)param_1 + fVar2;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar8;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = fVar3;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar12;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = fVar3;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      fVar3 = fVar3 + fVar2;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar8;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = fVar3;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar12;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = fVar3;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      fVar3 = fVar3 + fVar2;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar8;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = fVar3;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      DAT_02854d14 = DAT_02854d14 + 1;
      if (DAT_02854c31 == '\0') {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
      }
      else {
        *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
      }
      pfVar6 = (float *)*DAT_02854d10;
      *pfVar6 = (float)fVar12;
      pfVar6[1] = (float)fVar11;
      *(float *)(*DAT_02854d10 + 8) = fVar3;
      *DAT_02854d10 = *DAT_02854d10 + 0x18;
      param_1 = (undefined4 *)(fVar3 + fVar2);
      DAT_02854d14 = DAT_02854d14 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (param_4 < iVar4) {
    FUN_006009c0();
    return;
  }
  iVar4 = (param_4 - iVar4) + 1;
  do {
    if (DAT_02854c31 == '\0') {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
    }
    else {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
    }
    pfVar6 = (float *)*DAT_02854d10;
    *pfVar6 = (float)fVar8;
    pfVar6[1] = (float)fVar11;
    *(undefined4 **)(*DAT_02854d10 + 8) = param_1;
    *DAT_02854d10 = *DAT_02854d10 + 0x18;
    DAT_02854d14 = DAT_02854d14 + 1;
    if (DAT_02854c31 == '\0') {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff007f00;
    }
    else {
      *(undefined4 *)(*DAT_02854d10 + 0xc) = 0xff00ff00;
    }
    pfVar6 = (float *)*DAT_02854d10;
    *pfVar6 = (float)fVar12;
    pfVar6[1] = (float)fVar11;
    *(undefined4 **)(*DAT_02854d10 + 8) = param_1;
    *DAT_02854d10 = *DAT_02854d10 + 0x18;
    param_1 = (undefined4 *)((float)param_1 + fVar2);
    DAT_02854d14 = DAT_02854d14 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_006009c0();
  return;
}

