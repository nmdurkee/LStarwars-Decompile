/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66ed90; label: FUN_0066ed90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066ed90(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 int param_5)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 extraout_ST0_00;
  float10 fVar7;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_5 == 1) {
    local_60 = *param_3;
    local_5c = param_3[1];
    local_58 = (float)param_3[2];
    local_54 = 1.0;
    FUN_005c03e0(&local_60,&local_60,*param_2);
  }
  else {
    local_60 = *param_3;
    iVar4 = param_2[2];
    local_5c = param_3[1];
    local_50 = local_60;
    local_4c = local_5c;
    if (iVar4 == 0) {
      iVar3 = FUN_006e6b90();
      fVar6 = (float10)iVar3 / extraout_ST0_00;
      fVar7 = extraout_ST1;
    }
    else {
      iVar3 = FUN_006e6b90();
      fVar6 = (float10)iVar3 * (float10)0.125;
      fVar7 = extraout_ST0;
    }
    local_58 = (float)((float10)(float)param_3[2] -
                      (float10)(float)fVar6 * (float10)(float)param_2[3]);
    local_44 = (float)fVar7;
    local_54 = (float)fVar7;
    local_48 = local_58;
    if (iVar4 == 0) {
      pfVar1 = (float *)*param_2;
      pfVar2 = (float *)param_2[1];
      fVar7 = (float10)1 - (float10)(float)fVar6;
      iVar4 = FUN_006e6b90();
      pfVar5 = (float *)(&DAT_029899a0 + (iVar4 >> 1 & 0x7fff));
      local_40 = (float)(((float10)*pfVar5 * (float10)pfVar2[0x10] + extraout_ST0_01) *
                        ((float10)*pfVar1 * extraout_ST1_00 + fVar7 * (float10)*pfVar2));
      local_3c = (float)(((float10)*pfVar5 * (float10)pfVar2[0x10] + extraout_ST0_01) *
                        ((float10)pfVar1[1] * extraout_ST1_00 + (float10)pfVar2[1] * fVar7));
      local_38 = (float)(((float10)*pfVar5 * (float10)pfVar2[0x10] + extraout_ST0_01) *
                        ((float10)pfVar1[2] * extraout_ST1_00 + (float10)pfVar2[2] * fVar7));
      local_34 = (float)(((float10)*pfVar5 * (float10)pfVar2[0x10] + extraout_ST0_01) *
                        ((float10)pfVar1[3] * extraout_ST1_00 + (float10)pfVar2[3] * fVar7));
      local_30 = (float)(((float10)pfVar2[0x11] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[4] * extraout_ST1_00 + (float10)pfVar2[4] * fVar7));
      local_2c = (float)(((float10)pfVar2[0x11] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[5] * extraout_ST1_00 + (float10)pfVar2[5] * fVar7));
      local_28 = (float)(((float10)pfVar2[0x11] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[6] * extraout_ST1_00 + (float10)pfVar2[6] * fVar7));
      local_24 = (float)(((float10)pfVar2[0x11] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[7] * extraout_ST1_00 + (float10)pfVar2[7] * fVar7));
      local_20 = (float)(((float10)pfVar2[0x12] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[8] * extraout_ST1_00 + (float10)pfVar2[8] * fVar7));
      local_1c = (float)(((float10)pfVar2[0x12] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[9] * extraout_ST1_00 + (float10)pfVar2[9] * fVar7));
      local_18 = (float)(((float10)pfVar2[0x12] * (float10)*pfVar5 + extraout_ST0_01) *
                        ((float10)pfVar1[10] * extraout_ST1_00 + (float10)pfVar2[10] * fVar7));
      local_14 = (float)(((float10)pfVar1[0xb] * extraout_ST1_00 + (float10)pfVar2[0xb] * fVar7) *
                        ((float10)pfVar2[0x12] * (float10)*pfVar5 + extraout_ST0_01));
      local_10 = (float)((float10)pfVar2[0x14] * (float10)*pfVar5 +
                        (float10)pfVar1[0xc] * extraout_ST1_00 + (float10)pfVar2[0xc] * fVar7);
      local_c = (float)((float10)pfVar2[0x15] * (float10)*pfVar5 +
                       (float10)pfVar1[0xd] * extraout_ST1_00 + (float10)pfVar2[0xd] * fVar7);
      local_8 = (float)((float10)pfVar2[0x16] * (float10)*pfVar5 +
                       (float10)pfVar1[0xe] * extraout_ST1_00 + (float10)pfVar2[0xe] * fVar7);
      fVar7 = extraout_ST1_00 * (float10)pfVar1[0xf] + (float10)pfVar2[0xf] * fVar7;
    }
    else {
      iVar3 = FUN_006e6b90();
      pfVar5 = (float *)(iVar4 + iVar3 * -0x10);
      local_40 = *pfVar5;
      local_3c = pfVar5[1];
      local_38 = pfVar5[2];
      local_34 = pfVar5[3];
      local_30 = *(float *)((0xb - iVar3) * 0x10 + iVar4);
      local_2c = pfVar5[0x2d];
      local_28 = pfVar5[0x2e];
      local_24 = pfVar5[0x2f];
      local_20 = *(float *)((0x16 - iVar3) * 0x10 + iVar4);
      local_1c = pfVar5[0x59];
      local_18 = pfVar5[0x5a];
      local_14 = pfVar5[0x5b];
      local_10 = *(float *)((0x21 - iVar3) * 0x10 + iVar4);
      local_c = pfVar5[0x85];
      local_8 = pfVar5[0x86];
      fVar7 = (float10)pfVar5[0x87];
    }
    local_4 = (float)fVar7;
    FUN_005c03e0(&local_60,&local_60,&local_40);
  }
  *param_1 = local_60;
  param_1[1] = local_5c;
  param_1[2] = local_58;
  return;
}

