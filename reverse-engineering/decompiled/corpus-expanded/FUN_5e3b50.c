/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e3b50; label: FUN_005e3b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e3b50(float *param_1,undefined4 param_2,float *param_3)

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
  float fVar10;
  uint uVar11;
  float *pfVar12;
  uint uVar13;
  float10 fVar14;
  int local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_270;
  float local_26c;
  float local_268;
  float local_264;
  float local_260;
  float local_25c;
  float local_258;
  float local_254;
  float local_250;
  float local_240;
  float local_23c;
  float local_208;
  float local_204;
  float local_200;
  undefined4 local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  undefined4 local_1ec;
  float local_1e8;
  float local_1e4;
  float local_1e0;
  undefined4 local_1dc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  undefined4 local_1bc;
  
  local_1c8 = *param_1;
  local_1c4 = param_1[1];
  local_1c0 = param_1[2];
  local_1bc = 0x3f800000;
  FUN_005c03e0(&local_280,&local_1c8,param_2);
  local_208 = param_1[6] + *param_1;
  local_204 = param_1[7] + param_1[1];
  local_200 = param_1[8] + param_1[2];
  local_1fc = 0x3f800000;
  FUN_005c03e0(&local_208,&local_208,param_2);
  local_270 = local_208 - local_280;
  local_26c = local_204 - local_27c;
  local_268 = local_200 - local_278;
  local_1f8 = param_1[3] + *param_1;
  local_1f4 = param_1[4] + param_1[1];
  local_1f0 = param_1[5] + param_1[2];
  local_1ec = 0x3f800000;
  FUN_005c03e0(&local_1f8,&local_1f8,param_2);
  local_264 = local_1f8 - local_280;
  local_260 = local_1f4 - local_27c;
  local_25c = local_1f0 - local_278;
  local_1e8 = param_1[9] + *param_1;
  local_1e4 = param_1[10] + param_1[1];
  local_1e0 = param_1[0xb] + param_1[2];
  local_1dc = 0x3f800000;
  FUN_005c03e0(&local_1e8,&local_1e8,param_2);
  local_258 = local_1e8 - local_280;
  local_254 = local_1e4 - local_27c;
  local_250 = local_1e0 - local_278;
  fVar14 = (float10)FUN_005c0240(local_268 * local_268 +
                                 local_270 * local_270 + local_26c * local_26c);
  if ((float)fVar14 == 0.0) {
    local_240 = 0.0;
  }
  else {
    local_240 = 1.0 / (float)fVar14;
  }
  fVar14 = (float10)FUN_005c0240(local_25c * local_25c +
                                 local_264 * local_264 + local_260 * local_260);
  if ((float)fVar14 == 0.0) {
    local_23c = 0.0;
  }
  else {
    local_23c = 1.0 / (float)fVar14;
  }
  fVar14 = (float10)FUN_005c0240(local_250 * local_250 +
                                 local_258 * local_258 + local_254 * local_254);
  if ((float)fVar14 == 0.0) {
    fVar4 = 0.0;
  }
  else {
    fVar4 = 1.0 / (float)fVar14;
  }
  uVar13 = 1;
  if (DAT_00973ff0 < 0xfa) {
    *(int *)(DAT_00963f88 + DAT_00973ff0 * 4) = DAT_00973fec;
    *(undefined4 *)(DAT_0096e568 + DAT_00973ff0 * 4) = 8;
    DAT_00973ff0 = DAT_00973ff0 + 1;
  }
  pfVar12 = (float *)&DAT_009715b0;
  local_284 = 8;
  do {
    _DAT_00971878 = _DAT_00971878 + 2;
    uVar11 = uVar13 & 7;
    fVar6 = (pfVar12[2] * local_268 + *pfVar12 * local_270 + pfVar12[1] * local_26c) * local_240;
    fVar5 = (pfVar12[2] * local_25c + *pfVar12 * local_264 + pfVar12[1] * local_260) * local_23c;
    fVar2 = (pfVar12[2] * local_250 + *pfVar12 * local_258 + pfVar12[1] * local_254) * fVar4;
    fVar7 = ((float)(&DAT_009715b8)[uVar11 * 3] * local_268 +
            local_270 * (float)(&DAT_009715b0)[uVar11 * 3] +
            (float)(&DAT_009715b4)[uVar11 * 3] * local_26c) * local_240;
    fVar3 = ((float)(&DAT_009715b8)[uVar11 * 3] * local_25c +
            local_264 * (float)(&DAT_009715b0)[uVar11 * 3] +
            (float)(&DAT_009715b4)[uVar11 * 3] * local_260) * local_23c;
    fVar1 = ((float)(&DAT_009715b8)[uVar11 * 3] * local_250 +
            local_258 * (float)(&DAT_009715b0)[uVar11 * 3] +
            (float)(&DAT_009715b4)[uVar11 * 3] * local_254) * fVar4;
    fVar8 = local_280 + fVar2 * local_258 + fVar6 * local_270 + fVar5 * local_264;
    fVar9 = local_27c + fVar2 * local_254 + fVar6 * local_26c + fVar5 * local_260;
    fVar6 = local_278 + fVar2 * local_250 + fVar6 * local_268 + fVar5 * local_25c;
    fVar5 = local_280 + fVar1 * local_258 + fVar7 * local_270 + fVar3 * local_264;
    fVar10 = fVar1 * local_254 + fVar7 * local_26c + fVar3 * local_260 + local_27c;
    fVar7 = fVar1 * local_250 + fVar7 * local_268 + fVar3 * local_25c + local_278;
    fVar1 = *param_3;
    fVar2 = param_3[1];
    fVar3 = param_3[2];
    *(undefined4 *)(DAT_00973fec * 0x10 + 0xc + DAT_00963f94) = DAT_02854c00;
    *(float *)(DAT_00973fec * 0x10 + DAT_00963f94) = fVar8;
    *(float *)(DAT_00973fec * 0x10 + 4 + DAT_00963f94) = fVar9;
    *(float *)(DAT_00973fec * 0x10 + 8 + DAT_00963f94) = fVar6;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0x1c + DAT_00963f94) = DAT_02854c00;
    *(float *)((DAT_00973fec + 1) * 0x10 + DAT_00963f94) = fVar1 * 5.0 + fVar8;
    *(float *)(DAT_00973fec * 0x10 + 0x14 + DAT_00963f94) = fVar9 + fVar2 * 5.0;
    *(float *)(DAT_00973fec * 0x10 + 0x18 + DAT_00963f94) = fVar6 + fVar3 * 5.0;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0x2c + DAT_00963f94) = DAT_02854c00;
    *(float *)((DAT_00973fec + 2) * 0x10 + DAT_00963f94) = fVar5 + fVar1 * 5.0;
    *(float *)(DAT_00973fec * 0x10 + 0x24 + DAT_00963f94) = fVar2 * 5.0 + fVar10;
    *(float *)(DAT_00973fec * 0x10 + 0x28 + DAT_00963f94) = fVar3 * 5.0 + fVar7;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0x3c + DAT_00963f94) = DAT_02854c00;
    *(float *)((DAT_00973fec + 3) * 0x10 + DAT_00963f94) = fVar5;
    *(float *)(DAT_00973fec * 0x10 + 0x34 + DAT_00963f94) = fVar10;
    *(float *)(DAT_00973fec * 0x10 + 0x38 + DAT_00963f94) = fVar7;
    DAT_00973fec = DAT_00973fec + 4;
    pfVar12 = pfVar12 + 3;
    uVar13 = uVar13 + 1;
    local_284 = local_284 + -1;
  } while (local_284 != 0);
  return;
}

