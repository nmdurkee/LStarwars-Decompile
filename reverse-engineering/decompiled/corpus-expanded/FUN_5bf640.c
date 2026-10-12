/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bf640; label: FUN_005bf640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bf640(undefined4 *param_1,int *param_2,undefined4 *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  fVar1 = *param_4;
  fVar2 = param_4[1];
  fVar3 = param_4[2];
  fVar4 = param_4[3];
  param_4 = (float *)((fVar3 * fVar1 - fVar2 * fVar4) * -2.0);
  if (-1.0 <= (float)param_4) {
    fVar5 = 1.0;
    if ((float)param_4 <= 1.0) goto LAB_005bf6aa;
  }
  else {
    fVar5 = -1.0;
  }
  param_4 = (float *)fVar5;
LAB_005bf6aa:
  sVar6 = FUN_005b2e20(param_4);
  *param_2 = (int)sVar6;
  dVar9 = (double)(fVar4 * fVar4);
  dVar8 = (double)(fVar1 * fVar1);
  dVar10 = (double)(fVar2 * fVar2);
  dVar11 = (double)(fVar3 * fVar3);
  fVar5 = fVar1 * fVar4 + fVar3 * fVar2;
  uVar7 = FUN_005be2d0(fVar5 + fVar5,
                       ((fVar4 * fVar4 - fVar1 * fVar1) - fVar2 * fVar2) + fVar3 * fVar3,dVar8,dVar9
                       ,dVar10,dVar11);
  *param_1 = uVar7;
  fVar1 = fVar2 * fVar1 + fVar4 * fVar3;
  uVar7 = FUN_005be2d0(fVar1 + fVar1,
                       (float)((((float10)dVar8 + (float10)dVar9) - (float10)dVar10) -
                              (float10)dVar11));
  *param_3 = uVar7;
  return;
}

