/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e2920; label: FUN_005e2920
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e2920(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  float local_294;
  float local_278;
  float local_274;
  float local_270;
  float local_268;
  float local_264;
  float local_260;
  undefined4 local_25c;
  float local_258;
  float local_254;
  float local_250;
  undefined4 local_24c;
  float local_248;
  float local_244;
  float local_240;
  undefined4 local_23c;
  float local_228;
  float local_224;
  float local_220;
  undefined4 local_21c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  
  if (((uint)*param_1 & 1) == 0) {
    if (DAT_00973ff0 < 0xfa) {
      *(int *)(DAT_00963f88 + DAT_00973ff0 * 4) = DAT_00973fec;
      *(undefined4 *)(DAT_0096e568 + DAT_00973ff0 * 4) = 4;
      DAT_00973ff0 = DAT_00973ff0 + 1;
    }
    local_228 = *param_1;
    local_224 = param_1[1];
    local_220 = param_1[2];
    local_21c = 0x3f800000;
    FUN_005c03e0(&local_278,&local_228,param_2);
    local_268 = param_1[3] + *param_1;
    local_264 = param_1[4] + param_1[1];
    local_260 = param_1[5] + param_1[2];
    local_25c = 0x3f800000;
    FUN_005c03e0(&local_268,&local_268,param_2);
    local_68 = local_268 - local_278;
    local_64 = local_264 - local_274;
    local_60 = local_260 - local_270;
    local_258 = param_1[6] + *param_1;
    local_254 = param_1[7] + param_1[1];
    local_250 = param_1[8] + param_1[2];
    local_24c = 0x3f800000;
    FUN_005c03e0(&local_258,&local_258,param_2);
    local_5c = local_258 - local_278;
    local_58 = local_254 - local_274;
    local_54 = local_250 - local_270;
    local_248 = param_1[10] + *param_1;
    local_244 = param_1[0xb] + param_1[1];
    local_240 = param_1[0xc] + param_1[2];
    local_23c = 0x3f800000;
    FUN_005c03e0(&local_248,&local_248,param_2);
    local_50 = local_248 - local_278;
    local_4c = local_244 - local_274;
    local_48 = local_240 - local_270;
    local_29c = local_68;
    local_298 = local_64;
    local_294 = local_60;
    FUN_005b3920(&local_2b0,&local_68,param_3);
    local_2b4 = local_2a8 * local_2a8 + local_2b0 * local_2b0 + local_2ac * local_2ac;
    if (0.0 < local_2b4) {
      fVar6 = (float10)FUN_005c0240(local_2b4);
      local_2a4 = (float)fVar6;
      if (local_2a4 == 0.0) {
        local_2b4 = 0.0;
      }
      else {
        local_2b4 = 1.0 / local_2a4;
      }
    }
    local_2b0 = local_2b0 * local_2b4;
    local_2ac = local_2ac * local_2b4;
    local_2a8 = local_2b4 * local_2a8;
    local_2a0 = local_294 * local_294 + local_29c * local_29c + local_298 * local_298;
    if (0.0 < local_2a0) {
      FUN_005c0240(local_2a0);
    }
    fVar2 = local_2a8 * local_54 + local_2b0 * local_5c + local_2ac * local_58;
    fVar1 = local_2a8 * local_48 + local_2b0 * local_50 + local_4c * local_2ac;
    local_2a4 = fVar2 * fVar2 + fVar1 * fVar1;
    fVar6 = (float10)FUN_005c0240(local_2a4);
    fVar1 = (float)fVar6;
    iVar5 = 0;
    local_2b0 = fVar1 * local_2b0;
    local_2ac = local_2ac * fVar1;
    fVar1 = fVar1 * local_2a8;
    do {
      switch(iVar5) {
      case 0:
        local_268 = local_2b0 + local_29c;
        local_264 = local_2ac + local_298;
        local_260 = fVar1 + local_294;
        local_258 = local_2b0 - local_29c;
        local_254 = local_2ac - local_298;
        local_250 = fVar1 - local_294;
        break;
      case 1:
        local_268 = local_2b0 - local_29c;
        local_264 = local_2ac - local_298;
        local_260 = fVar1 - local_294;
        local_258 = -local_29c - local_2b0;
        local_254 = -local_298 - local_2ac;
        local_250 = -local_294 - fVar1;
        break;
      case 2:
        local_268 = -local_29c - local_2b0;
        local_264 = -local_298 - local_2ac;
        local_260 = -local_294 - fVar1;
        local_258 = local_29c - local_2b0;
        local_254 = local_298 - local_2ac;
        local_250 = local_294 - fVar1;
        break;
      case 3:
        local_268 = local_29c - local_2b0;
        local_264 = local_298 - local_2ac;
        local_260 = local_294 - fVar1;
        local_258 = local_29c + local_2b0;
        local_254 = local_2ac + local_298;
        local_250 = fVar1 + local_294;
      }
      local_268 = local_278 + local_268;
      local_264 = local_274 + local_264;
      local_260 = local_270 + local_260;
      local_258 = local_258 + local_278;
      local_254 = local_274 + local_254;
      local_250 = local_270 + local_250;
      fVar2 = *param_3;
      fVar3 = param_3[1];
      fVar4 = param_3[2];
      *(float *)(DAT_00973fec * 0x10 + DAT_00963f94) = local_268;
      *(float *)(DAT_00973fec * 0x10 + 4 + DAT_00963f94) = local_264;
      *(float *)(DAT_00973fec * 0x10 + 8 + DAT_00963f94) = local_260;
      *(float *)((DAT_00973fec + 1) * 0x10 + DAT_00963f94) = local_268 + fVar2 * 5.0;
      *(float *)(DAT_00973fec * 0x10 + 0x14 + DAT_00963f94) = local_264 + fVar3 * 5.0;
      *(float *)(DAT_00973fec * 0x10 + 0x18 + DAT_00963f94) = local_260 + fVar4 * 5.0;
      *(float *)((DAT_00973fec + 2) * 0x10 + DAT_00963f94) = local_258 + fVar2 * 5.0;
      *(float *)(DAT_00973fec * 0x10 + 0x24 + DAT_00963f94) = local_254 + fVar3 * 5.0;
      *(float *)(DAT_00973fec * 0x10 + 0x28 + DAT_00963f94) = fVar4 * 5.0 + local_250;
      *(float *)((DAT_00973fec + 3) * 0x10 + DAT_00963f94) = local_258;
      *(float *)(DAT_00973fec * 0x10 + 0x34 + DAT_00963f94) = local_254;
      *(float *)(DAT_00973fec * 0x10 + 0x38 + DAT_00963f94) = local_250;
      *(undefined4 *)(DAT_00973fec * 0x10 + 0xc + DAT_00963f94) = 0xffffffff;
      *(undefined4 *)(DAT_00973fec * 0x10 + 0x1c + DAT_00963f94) = 0xffffffff;
      *(undefined4 *)(DAT_00973fec * 0x10 + 0x2c + DAT_00963f94) = 0xffffffff;
      *(undefined4 *)(DAT_00973fec * 0x10 + 0x3c + DAT_00963f94) = 0xffffffff;
      DAT_00973fec = DAT_00973fec + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    return;
  }
  if (DAT_00973ff0 < 0xfa) {
    *(int *)(DAT_00963f88 + DAT_00973ff0 * 4) = DAT_00973fec;
    *(undefined4 *)(DAT_0096e568 + DAT_00973ff0 * 4) = 10;
    DAT_00973ff0 = DAT_00973ff0 + 1;
  }
  local_228 = *param_1;
  local_224 = param_1[1];
  local_220 = param_1[2];
  local_21c = 0x3f800000;
  FUN_005c03e0(&local_278,&local_228,param_2);
  local_268 = param_1[3] + *param_1;
  local_264 = param_1[4] + param_1[1];
  local_260 = param_1[5] + param_1[2];
  local_25c = 0x3f800000;
  FUN_005c03e0(&local_268,&local_268,param_2);
  local_68 = local_268 - local_278;
  local_64 = local_264 - local_274;
  local_60 = local_260 - local_270;
  local_258 = param_1[6] + *param_1;
  local_254 = param_1[7] + param_1[1];
  local_250 = param_1[8] + param_1[2];
  local_24c = 0x3f800000;
  FUN_005c03e0(&local_258,&local_258,param_2);
  local_5c = local_258 - local_278;
  local_58 = local_254 - local_274;
  local_54 = local_250 - local_270;
  local_248 = param_1[10] + *param_1;
  local_244 = param_1[0xb] + param_1[1];
  local_240 = param_1[0xc] + param_1[2];
  local_23c = 0x3f800000;
  FUN_005c03e0(&local_248,&local_248,param_2);
  local_50 = local_248 - local_278;
  local_4c = local_244 - local_274;
  local_48 = local_240 - local_270;
  local_29c = local_68;
  local_298 = local_64;
  local_294 = local_60;
  FUN_005b3920(&local_2b0,&local_68,param_3);
  local_2b4 = local_2a8 * local_2a8 + local_2b0 * local_2b0 + local_2ac * local_2ac;
  if (0.0 < local_2b4) {
    fVar6 = (float10)FUN_005c0240(local_2b4);
    local_2a4 = (float)fVar6;
    if (local_2a4 == 0.0) {
      local_2b4 = 0.0;
    }
    else {
      local_2b4 = 1.0 / local_2a4;
    }
  }
  local_2b0 = local_2b0 * local_2b4;
  local_2ac = local_2ac * local_2b4;
  local_2a8 = local_2b4 * local_2a8;
  local_2a0 = local_294 * local_294 + local_29c * local_29c + local_298 * local_298;
  if (0.0 < local_2a0) {
    fVar6 = (float10)FUN_005c0240(local_2a0);
    if ((float)fVar6 != 0.0) {
      local_2a0 = 1.0 / (float)fVar6;
      goto LAB_005e2c1a;
    }
  }
  local_2a0 = 0.0;
LAB_005e2c1a:
  fVar2 = local_2a8 * local_54 + local_2b0 * local_5c + local_2ac * local_58;
  fVar1 = local_2a8 * local_48 + local_2b0 * local_50 + local_4c * local_2ac;
  local_2a4 = fVar2 * fVar2 + fVar1 * fVar1;
  fVar6 = (float10)FUN_005c0240(local_2a4);
  fVar1 = (float)fVar6;
  iVar5 = 0;
  do {
    _DAT_00971878 = _DAT_00971878 + 2;
    switch(iVar5) {
    case 0:
      local_268 = local_2b0 * fVar1 + local_29c;
      local_264 = local_2ac * fVar1 + local_298;
      local_260 = local_2a8 * fVar1 + local_294;
      local_258 = local_2b0 * fVar1 - local_29c;
      local_254 = local_2ac * fVar1 - local_298;
      local_250 = local_2a8 * fVar1 - local_294;
      break;
    case 1:
      local_268 = local_2b0 * fVar1 - local_29c;
      local_264 = local_2ac * fVar1 - local_298;
      local_260 = local_2a8 * fVar1 - local_294;
      local_258 = (local_2b0 * fVar1 * 0.707 - local_29c) - local_2a0 * local_29c * fVar1 * 0.707;
      local_254 = (local_2ac * fVar1 * 0.707 - local_298) - local_2a0 * local_298 * fVar1 * 0.707;
      local_250 = (local_2a8 * fVar1 * 0.707 - local_294) - local_294 * local_2a0 * fVar1 * 0.707;
      break;
    case 2:
      local_268 = (local_2b0 * fVar1 * 0.707 - local_29c) - local_2a0 * local_29c * fVar1 * 0.707;
      local_264 = (local_2ac * fVar1 * 0.707 - local_298) - local_2a0 * local_298 * fVar1 * 0.707;
      local_260 = (local_2a8 * fVar1 * 0.707 - local_294) - local_294 * local_2a0 * fVar1 * 0.707;
      local_258 = -local_29c - fVar1 * local_29c * local_2a0;
      local_254 = -local_298 - fVar1 * local_298 * local_2a0;
      local_250 = -local_294 - local_2a0 * fVar1 * local_294;
      break;
    case 3:
      local_268 = -local_29c - fVar1 * local_29c * local_2a0;
      local_264 = -local_298 - fVar1 * local_298 * local_2a0;
      local_260 = -local_294 - local_2a0 * fVar1 * local_294;
      local_258 = (-local_29c - local_2b0 * fVar1 * 0.707) - local_2a0 * local_29c * fVar1 * 0.707;
      local_254 = (-local_298 - local_2ac * fVar1 * 0.707) - local_2a0 * local_298 * fVar1 * 0.707;
      local_250 = (-local_294 - local_2a8 * fVar1 * 0.707) - local_2a0 * local_294 * fVar1 * 0.707;
      break;
    case 4:
      local_268 = (-local_29c - local_2b0 * fVar1 * 0.707) - local_2a0 * local_29c * fVar1 * 0.707;
      local_264 = (-local_298 - local_2ac * fVar1 * 0.707) - local_2a0 * local_298 * fVar1 * 0.707;
      local_260 = (-local_294 - local_2a8 * fVar1 * 0.707) - fVar1 * local_2a0 * local_294 * 0.707;
      local_258 = -local_29c - local_2b0 * fVar1;
      local_254 = -local_298 - local_2ac * fVar1;
      local_250 = -local_294 - local_2a8 * fVar1;
      break;
    case 5:
      local_268 = -local_29c - local_2b0 * fVar1;
      local_264 = -local_298 - local_2ac * fVar1;
      local_260 = -local_294 - local_2a8 * fVar1;
      local_258 = local_29c - local_2b0 * fVar1;
      local_254 = local_298 - local_2ac * fVar1;
      local_250 = local_294 - local_2a8 * fVar1;
      break;
    case 6:
      local_268 = local_29c - local_2b0 * fVar1;
      local_264 = local_298 - local_2ac * fVar1;
      local_260 = local_294 - local_2a8 * fVar1;
      local_258 = fVar1 * local_29c * local_2a0 * 0.707 + (local_29c - local_2b0 * fVar1 * 0.707);
      local_254 = fVar1 * local_298 * local_2a0 * 0.707 + (local_298 - local_2ac * fVar1 * 0.707);
      local_250 = local_2a0 * fVar1 * local_294 * 0.707 + (local_294 - local_2a8 * fVar1 * 0.707);
      break;
    case 7:
      local_258 = fVar1 * local_29c * local_2a0;
      local_268 = local_258 * 0.707 + (local_29c - local_2b0 * fVar1 * 0.707);
      local_254 = fVar1 * local_298 * local_2a0;
      local_264 = local_254 * 0.707 + (local_298 - local_2ac * fVar1 * 0.707);
      local_250 = local_2a0 * local_294 * fVar1;
      local_260 = local_250 * 0.707 + (local_294 - local_2a8 * fVar1 * 0.707);
      goto LAB_005e3205;
    case 8:
      fVar4 = fVar1 * local_29c * local_2a0;
      local_268 = fVar4 + local_29c;
      fVar2 = fVar1 * local_298 * local_2a0;
      local_264 = fVar2 + local_298;
      fVar3 = fVar1 * local_294 * local_2a0;
      local_260 = fVar3 + local_294;
      local_258 = fVar4 * 0.707 + local_2b0 * fVar1 * 0.707 + local_29c;
      local_254 = fVar2 * 0.707 + local_2ac * fVar1 * 0.707 + local_298;
      local_250 = fVar3 * 0.707 + local_2a8 * fVar1 * 0.707 + local_294;
      break;
    case 9:
      local_258 = local_2b0 * fVar1;
      local_268 = local_258 * 0.707 + local_29c + fVar1 * local_29c * local_2a0 * 0.707;
      local_254 = local_2ac * fVar1;
      local_264 = local_254 * 0.707 + local_298 + fVar1 * local_298 * local_2a0 * 0.707;
      local_250 = local_2a8 * fVar1;
      local_260 = local_250 * 0.707 + local_294 + fVar1 * local_294 * local_2a0 * 0.707;
LAB_005e3205:
      local_254 = local_254 + local_298;
      local_258 = local_29c + local_258;
      local_250 = local_250 + local_294;
    }
    local_268 = local_278 + local_268;
    local_264 = local_274 + local_264;
    local_260 = local_270 + local_260;
    local_258 = local_258 + local_278;
    local_254 = local_254 + local_274;
    local_250 = local_250 + local_270;
    fVar2 = *param_3;
    fVar3 = param_3[1];
    fVar4 = param_3[2];
    *(float *)(DAT_00973fec * 0x10 + DAT_00963f94) = local_268;
    *(float *)(DAT_00973fec * 0x10 + 4 + DAT_00963f94) = local_264;
    *(float *)(DAT_00973fec * 0x10 + 8 + DAT_00963f94) = local_260;
    *(float *)((DAT_00973fec + 1) * 0x10 + DAT_00963f94) = fVar2 * 5.0 + local_268;
    *(float *)(DAT_00973fec * 0x10 + 0x14 + DAT_00963f94) = fVar3 * 5.0 + local_264;
    *(float *)(DAT_00973fec * 0x10 + 0x18 + DAT_00963f94) = fVar4 * 5.0 + local_260;
    *(float *)((DAT_00973fec + 2) * 0x10 + DAT_00963f94) = local_258 + fVar2 * 5.0;
    *(float *)(DAT_00973fec * 0x10 + 0x24 + DAT_00963f94) = local_254 + fVar3 * 5.0;
    *(float *)(DAT_00973fec * 0x10 + 0x28 + DAT_00963f94) = local_250 + fVar4 * 5.0;
    *(float *)((DAT_00973fec + 3) * 0x10 + DAT_00963f94) = local_258;
    *(float *)(DAT_00973fec * 0x10 + 0x34 + DAT_00963f94) = local_254;
    *(float *)(DAT_00973fec * 0x10 + 0x38 + DAT_00963f94) = local_250;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0xc + DAT_00963f94) = 0xffffffff;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0x1c + DAT_00963f94) = 0xffffffff;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0x2c + DAT_00963f94) = 0xffffffff;
    *(undefined4 *)(DAT_00973fec * 0x10 + 0x3c + DAT_00963f94) = 0xffffffff;
    DAT_00973fec = DAT_00973fec + 4;
    iVar5 = iVar5 + 1;
    if (9 < iVar5) {
      return;
    }
  } while( true );
}

