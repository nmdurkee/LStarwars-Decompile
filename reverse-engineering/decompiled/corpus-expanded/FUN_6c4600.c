/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c4600; label: FUN_006c4600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006c4600(int param_1,undefined4 param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int in_ECX;
  float10 fVar11;
  float local_a0;
  int local_9c;
  undefined1 *local_98;
  int local_94;
  undefined1 local_90 [16];
  undefined1 local_80 [124];
  
  *param_3 = 0.0;
  param_3[1] = 0.0;
  param_3[2] = 0.0;
  param_3[3] = 1.0;
  *param_4 = 0.0;
  param_4[1] = 0.0;
  param_4[2] = 0.0;
  local_94 = 0;
  param_4[3] = 1.0;
  FUN_006bce50(param_2,local_90,param_5);
  local_98 = local_80;
  local_a0 = 3.4028235e+38;
  local_9c = 1;
  do {
    fVar11 = (float10)FUN_006c0a10(param_1 + 0x20,param_1 + 0x30,local_98,0);
    fVar1 = (float)fVar11;
    fVar2 = _DAT_0081f9e0;
    if (local_9c < 4) {
      fVar2 = _DAT_0081f9dc;
    }
    if ((fVar1 < _DAT_0081f9b4 * fVar2) && (fVar1 < local_a0)) {
      local_94 = local_9c;
      local_a0 = fVar1;
    }
    local_98 = local_98 + 0x10;
    local_9c = local_9c + 1;
  } while (local_9c < 8);
  switch(local_94) {
  case 1:
    *param_3 = 1.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    param_3[3] = 1.0;
    break;
  case 2:
    *param_3 = 0.0;
    param_3[1] = 1.0;
    param_3[3] = 1.0;
    param_3[2] = 0.0;
    break;
  case 3:
    *param_3 = 0.0;
    param_3[1] = 0.0;
    param_3[2] = 1.0;
    param_3[3] = 1.0;
    break;
  case 4:
    *param_3 = 1.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    param_3[3] = 1.0;
    *param_4 = 0.0;
    param_4[2] = 0.0;
    param_4[1] = 1.0;
    param_4[3] = 1.0;
    break;
  case 5:
    *param_3 = 1.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    param_3[3] = 1.0;
    *param_4 = 0.0;
    param_4[1] = 0.0;
    param_4[2] = 1.0;
    param_4[3] = 1.0;
    break;
  case 6:
  case 7:
    *param_3 = 0.0;
    param_3[1] = 1.0;
    param_3[3] = 1.0;
    param_3[2] = 0.0;
    *param_4 = 0.0;
    param_4[1] = 0.0;
    param_4[2] = 1.0;
    param_4[3] = 1.0;
  }
  if (param_5 != (float *)0x0) {
    fVar1 = param_5[4];
    fVar2 = *param_5;
    fVar3 = param_3[2];
    fVar4 = param_5[8];
    fVar5 = param_5[5];
    fVar6 = *param_3;
    fVar7 = param_5[1];
    fVar8 = param_5[9];
    fVar9 = param_3[2];
    param_3[2] = param_3[2] * param_5[10] + *param_3 * param_5[2] + param_5[6] * param_3[1];
    *param_3 = fVar3 * fVar4 + *param_3 * fVar2 + fVar1 * param_3[1];
    param_3[1] = fVar8 * fVar9 + fVar6 * fVar7 + fVar5 * param_3[1];
    fVar1 = *param_5;
    fVar2 = param_5[4];
    fVar3 = param_5[8];
    fVar4 = param_4[2];
    fVar5 = param_5[5];
    fVar6 = *param_4;
    fVar7 = param_5[1];
    fVar8 = param_5[9];
    fVar9 = param_4[2];
    param_4[2] = param_4[2] * param_5[10] + param_5[6] * param_4[1] + *param_4 * param_5[2];
    *param_4 = fVar3 * fVar4 + param_4[1] * fVar2 + *param_4 * fVar1;
    param_4[1] = fVar8 * fVar9 + fVar6 * fVar7 + param_4[1] * fVar5;
    FUN_005b3b30(param_3,param_3);
    param_3[3] = 1.0;
    FUN_005b3b30(param_4,param_4);
    param_4[3] = 1.0;
  }
  if ((*(char *)(param_1 + 0x7b) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) {
    *(int *)(in_ECX + 0x18) = local_94;
    *(float *)(in_ECX + 0x20) = *param_3;
    *(float *)(in_ECX + 0x24) = param_3[1];
    *(float *)(in_ECX + 0x28) = param_3[2];
    *(float *)(in_ECX + 0x2c) = param_3[3];
    *(float *)(in_ECX + 0x30) = *param_4;
    *(float *)(in_ECX + 0x34) = param_4[1];
    *(float *)(in_ECX + 0x38) = param_4[2];
    *(float *)(in_ECX + 0x3c) = param_4[3];
    return local_94;
  }
  if ((*(char *)(param_1 + 0x53) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) {
    iVar10 = *(int *)(in_ECX + 0x18);
    *param_3 = *(float *)(in_ECX + 0x20);
    param_3[1] = *(float *)(in_ECX + 0x24);
    param_3[2] = *(float *)(in_ECX + 0x28);
    param_3[3] = *(float *)(in_ECX + 0x2c);
    *param_4 = *(float *)(in_ECX + 0x30);
    param_4[1] = *(float *)(in_ECX + 0x34);
    param_4[2] = *(float *)(in_ECX + 0x38);
    param_4[3] = *(float *)(in_ECX + 0x3c);
    return iVar10;
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0x3f800000;
  return local_94;
}

