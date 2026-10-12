/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4280; label: FUN_005e4280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e4280(undefined4 *param_1,float *param_2,float *param_3,float *param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  undefined4 *puVar4;
  float local_40c;
  undefined4 auStack_400 [16];
  float local_3c0;
  float local_3bc;
  float local_3b8;
  undefined4 local_3b4;
  float local_3b0;
  float local_3ac;
  float local_3a8;
  undefined4 local_3a4;
  float local_3a0;
  float local_39c;
  float local_398;
  undefined4 local_394;
  float local_390;
  float local_38c;
  float local_388;
  undefined4 local_384;
  float local_340;
  float local_33c;
  float local_338;
  undefined4 local_334;
  
  puVar4 = auStack_400;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  for (fVar3 = param_3[3]; 0 < (int)fVar3; fVar3 = (float)((int)fVar3 + -1)) {
    local_3c0 = *param_2;
    local_3bc = param_2[1];
    local_3b8 = param_2[2];
    local_3b4 = 0x3f800000;
    FUN_005c0490(&local_3c0,&local_3c0,auStack_400);
    if (local_3b8 * param_4[2] + local_3bc * param_4[1] + local_3c0 * *param_4 <= 0.0) {
      if (DAT_00973ff0 < 0xfa) {
        *(int *)(DAT_00963f88 + DAT_00973ff0 * 4) = DAT_00973fec;
        *(float *)(DAT_0096e568 + DAT_00973ff0 * 4) = param_2[3];
        DAT_00973ff0 = DAT_00973ff0 + 1;
      }
      local_40c = param_2[3];
      if (0 < (int)local_40c) {
        pfVar2 = param_3;
        do {
          _DAT_00971878 = _DAT_00971878 + 6;
          local_3c0 = *pfVar2;
          local_3bc = pfVar2[1];
          local_3b8 = pfVar2[2];
          local_3b4 = 0x3f800000;
          FUN_005c03e0(&local_3c0,&local_3c0,auStack_400);
          if (local_40c == 1.4013e-45) {
            local_3b0 = *param_3;
            local_3ac = param_3[1];
            local_3a8 = param_3[2];
          }
          else {
            local_3b0 = pfVar2[4];
            local_3ac = pfVar2[5];
            local_3a8 = pfVar2[6];
          }
          local_3a4 = 0x3f800000;
          FUN_005c03e0(&local_3b0,&local_3b0,auStack_400);
          local_3a0 = local_3c0 + *param_4;
          local_39c = local_3bc + param_4[1];
          local_398 = local_3b8 + param_4[2];
          local_394 = 0x3f800000;
          local_390 = local_3b0 + *param_4;
          local_38c = local_3ac + param_4[1];
          local_388 = local_3a8 + param_4[2];
          local_384 = 0x3f800000;
          *(undefined4 *)(DAT_00973fec * 0x10 + 0xc + DAT_00963f94) = 0xffffffff;
          *(float *)(DAT_00973fec * 0x10 + DAT_00963f94) = local_3c0;
          *(float *)(DAT_00973fec * 0x10 + 4 + DAT_00963f94) = local_3bc;
          *(float *)(DAT_00973fec * 0x10 + 8 + DAT_00963f94) = local_3b8;
          *(undefined4 *)(DAT_00973fec * 0x10 + 0x1c + DAT_00963f94) = 0xffffffff;
          *(float *)((DAT_00973fec + 1) * 0x10 + DAT_00963f94) = local_3a0;
          *(float *)(DAT_00973fec * 0x10 + 0x14 + DAT_00963f94) = local_39c;
          *(float *)(DAT_00973fec * 0x10 + 0x18 + DAT_00963f94) = local_398;
          *(undefined4 *)(DAT_00973fec * 0x10 + 0x2c + DAT_00963f94) = 0xffffffff;
          *(float *)((DAT_00973fec + 2) * 0x10 + DAT_00963f94) = local_390;
          *(float *)(DAT_00973fec * 0x10 + 0x24 + DAT_00963f94) = local_38c;
          *(float *)(DAT_00973fec * 0x10 + 0x28 + DAT_00963f94) = local_388;
          *(undefined4 *)(DAT_00973fec * 0x10 + 0x3c + DAT_00963f94) = 0xffffffff;
          *(float *)((DAT_00973fec + 3) * 0x10 + DAT_00963f94) = local_3b0;
          *(float *)(DAT_00973fec * 0x10 + 0x34 + DAT_00963f94) = local_3ac;
          *(float *)(DAT_00973fec * 0x10 + 0x38 + DAT_00963f94) = local_3a8;
          DAT_00973fec = DAT_00973fec + 4;
          local_40c = (float)((int)local_40c + -1);
          pfVar2 = pfVar2 + 4;
        } while (0 < (int)local_40c);
      }
      local_340 = local_3b0;
      local_33c = local_3ac;
      local_338 = local_3a8;
      local_334 = local_3a4;
    }
    param_3 = param_3 + (int)param_2[3] * 4;
    param_2 = param_2 + 4;
  }
  return;
}

