/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5dc690; label: FUN_005dc690
 */

void FUN_005dc690(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 fVar11;
  int local_c;
  
  FUN_00607ec0(0xf,5,param_4,param_1);
  iVar6 = param_3 / 2;
  local_c = iVar6;
  if (0 < iVar6) {
    do {
      FUN_006e6b90();
      FUN_006e6b90();
      if (-1 < param_3) {
        iVar5 = param_3 + 1;
        do {
          iVar4 = FUN_006e6b90();
          fVar1 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
          if (DAT_02854c31 == '\0') {
            *(uint *)(*DAT_02854d10 + 0xc) =
                 ((int)param_2 >> 0x11 & 0x7fU) +
                 (param_2 & 0xfe) * 0x8000 + (param_2 & 0xff000000) + ((int)param_2 >> 1 & 0x7f00U);
          }
          else {
            *(uint *)(*DAT_02854d10 + 0xc) =
                 (param_2 & 0xff00) +
                 (param_2 & 0xff) * 0x10000 + (param_2 & 0xff000000) + (param_2 >> 0x10 & 0xff);
          }
          fVar9 = extraout_ST1;
          iVar4 = FUN_006e6b90();
          fVar2 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
          pfVar3 = (float *)*DAT_02854d10;
          *pfVar3 = (float)((float10)fVar1 * fVar9);
          pfVar3[1] = fVar2;
          *(float *)(*DAT_02854d10 + 8) = (float)((float10)fVar1 * extraout_ST1_00);
          *DAT_02854d10 = *DAT_02854d10 + 0x18;
          DAT_02854d14 = DAT_02854d14 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  FUN_006009c0();
  if (1 < iVar6) {
    local_c = iVar6 + -1;
    do {
      FUN_006e6b90();
      iVar6 = FUN_006e6b90();
      fVar1 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
      FUN_00607ec0(0xf,5,param_4,param_1);
      if (-1 < param_3) {
        fVar7 = (float10)fVar1;
        fVar8 = (float10)(65536.0 / (float)param_3);
        iVar6 = param_3 + 1;
        fVar9 = (float10)16384.0;
        do {
          if (DAT_02854c31 == '\0') {
            *(uint *)(*DAT_02854d10 + 0xc) =
                 ((int)param_2 >> 0x11 & 0x7fU) +
                 (param_2 & 0xfe) * 0x8000 + (param_2 & 0xff000000) + ((int)param_2 >> 1 & 0x7f00U);
          }
          else {
            *(uint *)(*DAT_02854d10 + 0xc) =
                 (param_2 & 0xff00) +
                 (param_2 & 0xff) * 0x10000 + (param_2 & 0xff000000) + (param_2 >> 0x10 & 0xff);
          }
          fVar11 = fVar8;
          iVar5 = FUN_006e6b90();
          pfVar3 = (float *)*DAT_02854d10;
          fVar10 = (float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] * fVar7;
          fVar8 = extraout_ST1_01;
          fVar7 = fVar9;
          iVar5 = FUN_006e6b90();
          *pfVar3 = (float)((float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] * fVar11);
          pfVar3[1] = (float)fVar7;
          *(float *)(*DAT_02854d10 + 8) = (float)fVar10;
          *DAT_02854d10 = *DAT_02854d10 + 0x18;
          DAT_02854d14 = DAT_02854d14 + 1;
          iVar6 = iVar6 + -1;
          fVar9 = extraout_ST1_02;
        } while (iVar6 != 0);
      }
      FUN_006009c0();
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}

