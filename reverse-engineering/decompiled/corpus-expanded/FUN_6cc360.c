/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cc360; label: FUN_006cc360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_006cc360(int param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 extraout_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  undefined4 local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8;
  undefined4 local_1e4;
  int local_1d8;
  int local_1d4;
  undefined1 local_1d0 [48];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  float local_190;
  float local_18c;
  float local_188;
  undefined4 local_184;
  float local_180;
  float local_17c;
  float local_178;
  undefined4 local_174;
  float local_170;
  float local_16c;
  float local_168;
  float local_160;
  float local_15c;
  float local_158;
  undefined4 local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_140;
  float local_13c;
  float local_138;
  float local_130;
  float local_12c;
  float local_128;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 local_d4;
  undefined1 local_d0 [64];
  undefined1 local_90 [64];
  undefined1 local_50 [76];
  
  FUN_006cb940(param_1,param_2);
  iVar3 = FUN_006ca2f0(&local_210);
  if (iVar3 == 0) {
    return false;
  }
  FUN_006c8760(0x10,DAT_02973abc,local_1d0,0);
  local_1d8 = FUN_006c4600(param_1,&local_210,&local_200,&local_170,local_1d0);
  _DAT_02973c1c = *(undefined4 *)(&DAT_0081f9b8 + local_1d8 * 4);
  if ((*(char *)(param_1 + 0x53) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) {
    for (param_2 = (undefined4 *)*param_2; param_2 != (undefined4 *)0x0;
        param_2 = (undefined4 *)*param_2) {
      FUN_006c8760(0x20,DAT_02973abc,local_1d0,0);
      switch(local_1d8) {
      case 1:
      case 2:
      case 3:
        FUN_006b7e60(&local_1f0);
        fVar4 = (float10)FUN_005c0240(local_1e8 * local_1e8 +
                                      local_1f0 * local_1f0 + local_1ec * local_1ec);
        fVar2 = _DAT_0081f9b4 * (float)fVar4;
        fVar1 = *(float *)(local_1d4 + 0x58) * local_1f8 +
                local_200 * *(float *)(local_1d4 + 0x50) + *(float *)(local_1d4 + 0x54) * local_1fc;
        if (fVar1 != 0.0) {
          FUN_005b3470(&local_200,&local_200,local_1d0);
          FUN_005b3b30(&local_200,&local_200);
          local_1f4 = 0x3f800000;
          local_138 = (fVar2 + fVar1) / fVar2 - 1.0;
          local_140 = local_138 * local_200;
          local_13c = local_1fc * local_138;
          local_138 = local_138 * local_1f8;
          local_1f0 = local_140 + 1.0;
          local_1ec = local_13c + 1.0;
          local_1e8 = local_138 + 1.0;
          local_1e4 = local_154;
          local_160 = local_1f0;
          local_15c = local_1ec;
          local_158 = local_1e8;
          FUN_006b8470(&local_1f0);
          local_d4 = 0x3f800000;
          local_210 = local_1a0;
          local_20c = local_19c;
          local_208 = local_198;
          local_204 = local_194;
          FUN_006b7f50(local_90);
LAB_006cc960:
          FUN_006b7df0();
          local_1a0 = local_210;
          local_19c = local_20c;
          local_198 = local_208;
          local_194 = local_204;
          FUN_006c87f0(0x20,DAT_02973abc,extraout_ECX,0);
        }
        break;
      case 4:
      case 5:
      case 6:
        FUN_006b7e60(&local_1f0);
        fVar4 = (float10)FUN_005c0240(local_1e8 * local_1e8 +
                                      local_1f0 * local_1f0 + local_1ec * local_1ec);
        fVar2 = (float)fVar4 * _DAT_0081f9b4;
        fVar1 = *(float *)(local_1d4 + 0x58) * local_168 +
                local_170 * *(float *)(local_1d4 + 0x50) + *(float *)(local_1d4 + 0x54) * local_16c
                + *(float *)(local_1d4 + 0x58) * local_1f8 +
                  local_200 * *(float *)(local_1d4 + 0x50) +
                  *(float *)(local_1d4 + 0x54) * local_1fc;
        if (fVar1 != 0.0) {
          FUN_005b3470(&local_200,&local_200,local_1d0);
          FUN_005b3b30(&local_200,&local_200);
          local_1f4 = 0x3f800000;
          local_118 = (fVar2 + fVar1) / fVar2 - 1.0;
          local_130 = local_118 * local_170;
          local_12c = local_16c * local_118;
          local_128 = local_168 * local_118;
          local_120 = local_200 * local_118;
          local_11c = local_1fc * local_118;
          local_118 = local_118 * local_1f8;
          local_150 = local_130 + local_120;
          local_14c = local_11c + local_12c;
          local_148 = local_118 + local_128;
          local_1f0 = local_150 + 1.0;
          local_1ec = local_14c + 1.0;
          local_1e8 = local_148 + 1.0;
          local_1e4 = local_184;
          local_190 = local_1f0;
          local_18c = local_1ec;
          local_188 = local_1e8;
          FUN_006b8470(&local_1f0);
          local_d4 = 0x3f800000;
          local_210 = local_1a0;
          local_20c = local_19c;
          local_208 = local_198;
          local_204 = local_194;
          FUN_006b7f50(local_d0);
          goto LAB_006cc960;
        }
        break;
      case 7:
        fVar4 = (float10)FUN_006b9750(1);
        fVar5 = (float10)FUN_006b9750(0);
        fVar6 = (float10)FUN_006b9750(2);
        fVar1 = (float)(fVar6 + (float10)(double)((float10)(float)fVar4 - fVar5));
        if (fVar1 != 0.0) {
          local_1f0 = fVar1 * 0.005 + 1.0;
          local_1e4 = local_174;
          local_1ec = local_1f0;
          local_1e8 = local_1f0;
          local_180 = local_1f0;
          local_17c = local_1f0;
          local_178 = local_1f0;
          FUN_006b8470(&local_1f0);
          local_d4 = 0x3f800000;
          local_210 = local_1a0;
          local_20c = local_19c;
          local_208 = local_198;
          local_204 = local_194;
          FUN_006b7f50(local_50);
          goto LAB_006cc960;
        }
      }
    }
  }
  return local_1d8 != 0;
}

