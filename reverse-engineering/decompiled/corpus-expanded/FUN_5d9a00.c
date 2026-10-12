/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9a00; label: FUN_005d9a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d9a00(float *param_1,float *param_2,undefined2 param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int local_10;
  
  iVar9 = FUN_005d9140();
  *(float *)(iVar9 + 0x84) = *param_1;
  *(float *)(iVar9 + 0x88) = param_1[1];
  *(float *)(iVar9 + 0x8c) = param_1[2];
  *(float *)(iVar9 + 0x90) = *param_2;
  *(float *)(iVar9 + 0x94) = param_2[1];
  iVar8 = DAT_0096e564;
  fVar4 = param_2[2];
  *(undefined2 *)(iVar9 + 0x9e) = param_3;
  *(float *)(iVar9 + 0x98) = fVar4;
  pfVar5 = *(float **)(iVar9 + 0x80);
  local_10 = (int)(longlong)ROUND(*(float *)(iVar8 + 0x40) * 0.5 * 10430.378);
  fVar6 = (float)(&DAT_029899a0)[local_10 >> 1 & 0x7fff] /
          (float)(&DAT_029899a0)[local_10 + 0x4000 >> 1 & 0x7fff];
  fVar7 = fVar6 / *(float *)(iVar8 + 0x44);
  fVar3 = fVar6 * param_1[1];
  fVar10 = (float10)FUN_005c0240(fVar3 * fVar3 + 1.0);
  fVar4 = (float)((float10)1 / fVar10);
  pfVar5[8] = 0.0;
  pfVar5[9] = fVar4;
  pfVar5[10] = -fVar3 * fVar4;
  pfVar5[0xb] = 0.0;
  fVar4 = param_2[1];
  fVar10 = (float10)(fVar4 * fVar6);
  fVar10 = (float10)FUN_005c0240((float)(fVar10 * fVar10 + (float10)1));
  fVar3 = (float)((float10)1 / fVar10);
  pfVar5[0xc] = 0.0;
  pfVar5[0xd] = -fVar3;
  pfVar5[0xe] = fVar3 * fVar4 * fVar6;
  pfVar5[0xf] = 0.0;
  fVar3 = *param_2 * fVar7;
  fVar10 = (float10)fVar3;
  fVar10 = (float10)FUN_005c0240((float)(fVar10 * fVar10 + (float10)1));
  fVar4 = (float)((float10)1 / fVar10);
  *pfVar5 = -fVar4;
  pfVar5[1] = 0.0;
  pfVar5[2] = fVar3 * fVar4;
  pfVar5[3] = 0.0;
  fVar7 = *param_1 * fVar7;
  fVar10 = (float10)fVar7;
  fVar10 = (float10)FUN_005c0240((float)(fVar10 * fVar10 + (float10)1));
  pfVar1 = pfVar5 + 4;
  *pfVar1 = (float)((float10)1 / fVar10);
  pfVar5[5] = 0.0;
  pfVar5[6] = -fVar7 * (float)((float10)1 / fVar10);
  pfVar5[7] = 0.0;
  fVar6 = _DAT_0095fbb0;
  fVar3 = _DAT_0095fbac;
  fVar4 = _DAT_0095fba8;
  FUN_005b3f50(pfVar5,pfVar5,&DAT_0095fb78);
  pfVar5[3] = -(pfVar5[2] * fVar6 + *pfVar5 * fVar4 + pfVar5[1] * fVar3);
  FUN_005b3f50(pfVar1,pfVar1,&DAT_0095fb78);
  pfVar2 = pfVar5 + 8;
  pfVar5[7] = -(pfVar5[6] * fVar6 + *pfVar1 * fVar4 + pfVar5[5] * fVar3);
  FUN_005b3f50(pfVar2,pfVar2,&DAT_0095fb78);
  pfVar1 = pfVar5 + 0xc;
  pfVar5[0xb] = -(pfVar5[10] * fVar6 + fVar4 * *pfVar2 + pfVar5[9] * fVar3);
  FUN_005b3f50(pfVar1,pfVar1,&DAT_0095fb78);
  pfVar5[0xf] = -(pfVar5[0xe] * fVar6 + pfVar5[0xd] * fVar3 + *pfVar1 * fVar4);
  FUN_005d9850();
  return;
}

