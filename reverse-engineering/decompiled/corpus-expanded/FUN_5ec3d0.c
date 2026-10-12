/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ec3d0; label: FUN_005ec3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ec3d0(float *param_1,float *param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar6;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST1;
  float10 fVar7;
  float10 extraout_ST1_00;
  
  fVar2 = _DAT_0080b6d8 * ((float)param_3 / 65535.0);
  fVar1 = ((float)(int)param_4 / 65535.0) * _DAT_0080b6dc;
  fVar5 = (float10)FUN_005b9d90(&param_4);
  fVar3 = (float)DAT_0097390c;
  if (DAT_0097390c < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  param_4 = (fVar3 * fVar1 +
            (float)(fVar5 * (float10)3.1419999599456787 + fVar5 * (float10)3.1419999599456787)) *
            2.3;
  iVar4 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[0x4000 - iVar4 >> 1 & 0x7fff];
  param_4 = (float)(extraout_ST1 * (float10)4.400000095367432);
  fVar5 = extraout_ST0;
  iVar4 = FUN_006e6b90();
  fVar6 = (float10)0.25;
  fVar7 = (float10)(float)(&DAT_029899a0)[0x4000 - iVar4 >> 1 & 0x7fff] * fVar6;
  param_4 = (float)(fVar5 * (float10)2.0999999046325684);
  fVar5 = extraout_ST0_00;
  iVar4 = FUN_006e6b90();
  param_4 = (float)((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * fVar6);
  fVar6 = extraout_ST0_01;
  FUN_006e6b90();
  param_4 = (float)(fVar5 * (float10)4.199999809265137);
  iVar4 = FUN_006e6b90();
  *param_1 = (float)((float10)fVar2 *
                    (extraout_ST1_00 +
                    (float10)(float)(extraout_ST0_02 *
                                    (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff])));
  param_4 = (float)(fVar6 * (float10)1.100000023841858);
  iVar4 = FUN_006e6b90();
  *param_2 = (float)(((float10)(float)(&DAT_029899a0)[0x4000 - iVar4 >> 1 & 0x7fff] +
                      (float10)(fVar1 * 0.5) + (float10)(float)fVar7) * extraout_ST0_03);
  return;
}

