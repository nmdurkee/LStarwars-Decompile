/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b65a0; label: FUN_005b65a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b65a0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  
  fVar3 = param_1[2] * param_1[2] + *param_1 * *param_1 + param_1[1] * param_1[1];
  fVar2 = param_1[6] * param_1[6] + param_1[4] * param_1[4] + param_1[5] * param_1[5];
  fVar1 = param_1[10] * param_1[10] + param_1[8] * param_1[8] + param_1[9] * param_1[9];
  fVar4 = param_2[2] * param_2[2] + *param_2 * *param_2 + param_2[1] * param_2[1];
  fVar5 = 0.0;
  if ((fVar1 != 0.0) && (fVar4 != 0.0)) {
    fVar5 = fVar1 / fVar4;
  }
  fVar6 = (float10)FUN_005c0240(fVar5);
  fVar1 = (float)fVar6;
  param_1[8] = fVar1 * *param_2;
  param_1[9] = param_2[1] * fVar1;
  param_1[10] = fVar1 * param_2[2];
  if (0.8660254 < ABS(param_1[6] * param_1[10] + param_1[4] * param_1[8] + param_1[5] * param_1[9]))
  {
    param_1[4] = param_1[9] * param_1[2] - param_1[10] * param_1[1];
    param_1[5] = param_1[10] * *param_1 - param_1[2] * param_1[8];
    param_1[6] = param_1[1] * param_1[8] - param_1[9] * *param_1;
    fVar1 = param_1[6] * param_1[6] + param_1[4] * param_1[4] + param_1[5] * param_1[5];
    fVar4 = 0.0;
    if ((fVar2 != 0.0) && (fVar1 != 0.0)) {
      fVar4 = fVar2 / fVar1;
    }
    fVar6 = (float10)FUN_005c0240(fVar4);
    fVar2 = (float)fVar6;
    param_1[4] = fVar2 * param_1[4];
    param_1[5] = fVar2 * param_1[5];
    param_1[6] = fVar2 * param_1[6];
    fVar2 = param_1[8] * param_1[6] - param_1[4] * param_1[10];
    fVar1 = param_1[4] * param_1[9] - param_1[8] * param_1[5];
    *param_1 = param_1[5] * param_1[10] - param_1[6] * param_1[9];
    param_1[1] = fVar2;
    param_1[2] = fVar1;
    fVar2 = fVar1 * fVar1 + *param_1 * *param_1 + fVar2 * fVar2;
    fVar1 = 0.0;
    if ((fVar3 != 0.0) && (fVar2 != 0.0)) {
      fVar1 = fVar3 / fVar2;
    }
    fVar6 = (float10)FUN_005c0240(fVar1);
    fVar3 = (float)fVar6;
    *param_1 = fVar3 * *param_1;
    param_1[1] = fVar3 * param_1[1];
    param_1[2] = fVar3 * param_1[2];
    return;
  }
  fVar1 = param_1[6] * param_1[8] - param_1[4] * param_1[10];
  fVar4 = param_1[9] * param_1[4] - param_1[8] * param_1[5];
  *param_1 = param_1[5] * param_1[10] - param_1[6] * param_1[9];
  param_1[1] = fVar1;
  param_1[2] = fVar4;
  fVar1 = fVar4 * fVar4 + *param_1 * *param_1 + fVar1 * fVar1;
  fVar4 = 0.0;
  if ((fVar3 != 0.0) && (fVar1 != 0.0)) {
    fVar4 = fVar3 / fVar1;
  }
  fVar6 = (float10)FUN_005c0240(fVar4);
  fVar3 = (float)fVar6;
  fVar1 = fVar3 * *param_1;
  *param_1 = fVar1;
  fVar4 = fVar3 * param_1[1];
  param_1[1] = fVar4;
  fVar3 = param_1[2] * fVar3;
  param_1[2] = fVar3;
  param_1[4] = fVar3 * param_1[9] - param_1[10] * fVar4;
  param_1[5] = fVar1 * param_1[10] - param_1[8] * fVar3;
  param_1[6] = param_1[8] * fVar4 - param_1[9] * fVar1;
  fVar3 = param_1[6] * param_1[6] + param_1[4] * param_1[4] + param_1[5] * param_1[5];
  fVar1 = 0.0;
  if ((fVar2 != 0.0) && (fVar3 != 0.0)) {
    fVar1 = fVar2 / fVar3;
  }
  fVar6 = (float10)FUN_005c0240(fVar1);
  fVar3 = (float)fVar6;
  param_1[4] = fVar3 * param_1[4];
  param_1[5] = fVar3 * param_1[5];
  param_1[6] = fVar3 * param_1[6];
  return;
}

