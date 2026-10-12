/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x521240; label: FUN_00521240
 */

void FUN_00521240(float *param_1,float *param_2,int param_3,undefined4 param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  pfVar1 = (float *)(&DAT_029899a0 + (param_3 + 0x4000 >> 1 & 0x7fff));
  pfVar2 = (float *)(&DAT_029899a0 + (param_3 >> 1 & 0x7fff));
  fVar11 = -*param_2 * *pfVar1;
  fVar8 = -param_2[2] * *pfVar2;
  fVar12 = fVar8 + fVar11;
  fVar7 = -param_2[2] * *pfVar1;
  fVar3 = *pfVar2 * -*param_2;
  fVar4 = fVar7 - fVar3;
  fVar10 = param_2[2] * *pfVar2;
  fVar11 = fVar10 + fVar11;
  fVar5 = *pfVar1 * param_2[2];
  fVar3 = fVar5 - fVar3;
  fVar9 = *param_2 * *pfVar1;
  fVar10 = fVar9 + fVar10;
  fVar6 = *param_2 * *pfVar2;
  fVar5 = fVar5 - fVar6;
  fVar9 = fVar9 + fVar8;
  fVar7 = fVar7 - fVar6;
  FUN_00512cc0(*param_1 + fVar12,param_1[1],fVar4 + param_1[2],*param_1 + fVar11,param_1[1],
               fVar3 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar11,param_1[1],fVar3 + param_1[2],*param_1 + fVar10,param_1[1],
               fVar5 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar10,param_1[1],fVar5 + param_1[2],*param_1 + fVar9,param_1[1],
               fVar7 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar9,param_1[1],fVar7 + param_1[2],*param_1 + fVar12,param_1[1],
               fVar4 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar12,param_1[1],fVar4 + param_1[2],*param_1 + fVar12,
               param_1[1] + param_2[1],fVar4 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar11,param_1[1],fVar3 + param_1[2],*param_1 + fVar11,
               param_1[1] + param_2[1],fVar3 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar10,param_1[1],fVar5 + param_1[2],*param_1 + fVar10,
               param_1[1] + param_2[1],fVar5 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar9,param_1[1],fVar7 + param_1[2],*param_1 + fVar9,
               param_1[1] + param_2[1],fVar7 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar12,param_1[1] + param_2[1],fVar4 + param_1[2],*param_1 + fVar11,
               param_1[1] + param_2[1],fVar3 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar11,param_1[1] + param_2[1],fVar3 + param_1[2],*param_1 + fVar10,
               param_1[1] + param_2[1],fVar5 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar10,param_1[1] + param_2[1],fVar5 + param_1[2],*param_1 + fVar9,
               param_1[1] + param_2[1],fVar7 + param_1[2],param_4);
  FUN_00512cc0(*param_1 + fVar9,param_1[1] + param_2[1],fVar7 + param_1[2],*param_1 + fVar12,
               param_1[1] + param_2[1],fVar4 + param_1[2],param_4);
  return;
}

