/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bce50; label: FUN_006bce50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bce50(float *param_1,float *param_2,float *param_3)

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
  float local_24;
  
  fVar1 = _DAT_0081f9b4 * _DAT_0081f9d8;
  param_2[0xc] = 0.0;
  param_2[0xd] = 0.0;
  param_2[0xe] = 0.0;
  param_2[0xf] = 1.0;
  param_2[8] = 0.0;
  param_2[9] = param_2[0xd];
  param_2[10] = param_2[0xe];
  param_2[0xb] = param_2[0xf];
  param_2[4] = 0.0;
  param_2[5] = param_2[9];
  param_2[6] = param_2[10];
  param_2[7] = param_2[0xb];
  param_2[0x1c] = 0.0;
  param_2[0x1d] = param_2[5];
  param_2[0x1e] = param_2[6];
  param_2[0x1f] = param_2[7];
  *param_2 = 0.0;
  param_2[1] = param_2[0x1d];
  param_2[2] = param_2[0x1e];
  param_2[3] = param_2[0x1f];
  param_2[4] = fVar1 + param_2[4];
  param_2[9] = param_2[9] + fVar1;
  param_2[0xe] = fVar1 + param_2[0xe];
  param_2[0x10] = (param_2[4] + param_2[8]) * 0.5;
  param_2[0x11] = (param_2[5] + param_2[9]) * 0.5;
  param_2[0x12] = (param_2[6] + param_2[10]) * 0.5;
  param_2[0x13] = local_24;
  param_2[0x14] = (param_2[0xc] + param_2[4]) * 0.5;
  param_2[0x15] = (param_2[0xd] + param_2[5]) * 0.5;
  param_2[0x16] = (param_2[0xe] + param_2[6]) * 0.5;
  param_2[0x17] = local_24;
  param_2[0x18] = (param_2[0xc] + param_2[8]) * 0.5;
  param_2[0x19] = (param_2[9] + param_2[0xd]) * 0.5;
  param_2[0x1a] = (param_2[10] + param_2[0xe]) * 0.5;
  param_2[0x1b] = local_24;
  if (param_3 != (float *)0x0) {
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_3[8];
    fVar4 = param_2[2];
    fVar5 = *param_2;
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[2];
    fVar9 = param_3[9];
    param_2[2] = param_2[2] * param_3[10] + param_3[2] * *param_2 + param_2[1] * param_3[6];
    *param_2 = fVar3 * fVar4 + param_2[1] * fVar2 + *param_2 * fVar1;
    param_2[1] = fVar8 * fVar9 + param_2[1] * fVar7 + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[6];
    fVar4 = param_3[8];
    fVar5 = param_2[4];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[6];
    fVar9 = param_3[9];
    param_2[6] = param_2[6] * param_3[10] + param_2[5] * param_3[6] + param_3[2] * param_2[4];
    param_2[4] = fVar3 * fVar4 + param_2[5] * fVar2 + param_2[4] * fVar1;
    param_2[5] = fVar8 * fVar9 + fVar7 * param_2[5] + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[10];
    fVar4 = param_3[8];
    fVar5 = param_2[8];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[10];
    fVar9 = param_3[9];
    param_2[10] = param_2[10] * param_3[10] + param_2[9] * param_3[6] + param_3[2] * param_2[8];
    param_2[8] = fVar3 * fVar4 + param_2[9] * fVar2 + param_2[8] * fVar1;
    param_2[9] = fVar8 * fVar9 + fVar7 * param_2[9] + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[0xe];
    fVar4 = param_3[8];
    fVar5 = param_2[0xc];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[0xe];
    fVar9 = param_3[9];
    param_2[0xe] = param_2[0xe] * param_3[10] +
                   param_2[0xd] * param_3[6] + param_3[2] * param_2[0xc];
    param_2[0xc] = fVar3 * fVar4 + param_2[0xd] * fVar2 + param_2[0xc] * fVar1;
    param_2[0xd] = fVar8 * fVar9 + fVar7 * param_2[0xd] + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[0x12];
    fVar4 = param_3[8];
    fVar5 = param_2[0x10];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[0x12];
    fVar9 = param_3[9];
    param_2[0x12] =
         param_2[0x12] * param_3[10] + param_2[0x11] * param_3[6] + param_3[2] * param_2[0x10];
    param_2[0x10] = fVar3 * fVar4 + param_2[0x11] * fVar2 + param_2[0x10] * fVar1;
    param_2[0x11] = fVar8 * fVar9 + fVar7 * param_2[0x11] + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[0x16];
    fVar4 = param_3[8];
    fVar5 = param_2[0x14];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[0x16];
    fVar9 = param_3[9];
    param_2[0x16] =
         param_2[0x16] * param_3[10] + param_2[0x15] * param_3[6] + param_3[2] * param_2[0x14];
    param_2[0x14] = fVar3 * fVar4 + param_2[0x15] * fVar2 + param_2[0x14] * fVar1;
    param_2[0x15] = fVar8 * fVar9 + fVar7 * param_2[0x15] + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[0x1a];
    fVar4 = param_3[8];
    fVar5 = param_2[0x18];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[0x1a];
    fVar9 = param_3[9];
    param_2[0x1a] =
         param_2[0x1a] * param_3[10] + param_2[0x19] * param_3[6] + param_3[2] * param_2[0x18];
    param_2[0x18] = fVar3 * fVar4 + param_2[0x19] * fVar2 + param_2[0x18] * fVar1;
    param_2[0x19] = fVar8 * fVar9 + fVar7 * param_2[0x19] + fVar5 * fVar6;
    fVar1 = *param_3;
    fVar2 = param_3[4];
    fVar3 = param_2[0x1e];
    fVar4 = param_3[8];
    fVar5 = param_2[0x1c];
    fVar6 = param_3[1];
    fVar7 = param_3[5];
    fVar8 = param_2[0x1e];
    fVar9 = param_3[9];
    param_2[0x1e] =
         param_2[0x1e] * param_3[10] + param_2[0x1d] * param_3[6] + param_3[2] * param_2[0x1c];
    param_2[0x1c] = fVar3 * fVar4 + param_2[0x1d] * fVar2 + param_2[0x1c] * fVar1;
    param_2[0x1d] = fVar8 * fVar9 + fVar7 * param_2[0x1d] + fVar5 * fVar6;
  }
  *param_2 = *param_1 + *param_2;
  param_2[1] = param_2[1] + param_1[1];
  param_2[2] = param_1[2] + param_2[2];
  param_2[4] = param_2[4] + *param_1;
  param_2[5] = param_2[5] + param_1[1];
  param_2[6] = param_2[6] + param_1[2];
  param_2[8] = param_2[8] + *param_1;
  param_2[9] = param_2[9] + param_1[1];
  param_2[10] = param_2[10] + param_1[2];
  param_2[0xc] = param_2[0xc] + *param_1;
  param_2[0xd] = param_2[0xd] + param_1[1];
  param_2[0xe] = param_2[0xe] + param_1[2];
  param_2[0x10] = param_2[0x10] + *param_1;
  param_2[0x11] = param_2[0x11] + param_1[1];
  param_2[0x12] = param_2[0x12] + param_1[2];
  param_2[0x14] = param_2[0x14] + *param_1;
  param_2[0x15] = param_2[0x15] + param_1[1];
  param_2[0x16] = param_2[0x16] + param_1[2];
  param_2[0x18] = param_2[0x18] + *param_1;
  param_2[0x19] = param_2[0x19] + param_1[1];
  param_2[0x1a] = param_2[0x1a] + param_1[2];
  param_2[0x1c] = param_2[0x1c] + *param_1;
  param_2[0x1d] = param_2[0x1d] + param_1[1];
  param_2[0x1e] = param_2[0x1e] + param_1[2];
  return;
}

