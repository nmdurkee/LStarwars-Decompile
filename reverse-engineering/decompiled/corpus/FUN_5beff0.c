/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5beff0; label: FUN_005beff0
 */

undefined4
FUN_005beff0(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            float param_6,float *param_7)

{
  uint uVar1;
  uint uVar2;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_24 = *param_1 - param_6;
  local_20 = param_1[1] - param_6;
  local_1c = param_1[2] - param_6;
  local_30 = *param_2 + param_6;
  local_2c = param_2[1] + param_6;
  local_28 = param_6 + param_2[2];
  FUN_005b33c0(&local_c,param_4,param_3);
  uVar1 = FUN_005b9bf0(&local_c,&local_30,&local_24);
  if ((uVar1 == 0) && (param_7 == (float *)0x0)) {
    return 1;
  }
  FUN_005b33c0(&local_3c,param_5,param_3);
  uVar2 = FUN_005b9bf0(&local_3c,&local_30,&local_24);
  if ((uVar2 == 0) && (param_7 == (float *)0x0)) {
    return 1;
  }
  if ((uVar1 == 0) && (uVar2 == 0)) {
    if (param_7 == (float *)0x0) {
      return 1;
    }
    *param_7 = 0.0;
    param_7[1] = 0.0;
    param_7[2] = 0.0;
    return 1;
  }
  if ((uVar1 & uVar2) == 0) {
    local_18 = local_3c - local_c;
    local_14 = local_38 - local_8;
    local_10 = local_34 - local_4;
    FUN_005b3b30(&local_18,&local_18);
    if ((uVar1 & 1) == 0) {
      if (((((uVar1 & 8) != 0) &&
           (FUN_005b9c80(&local_3c,&local_c,&local_18,&local_24), local_38 < local_2c)) &&
          (local_20 < local_38)) && ((local_34 < local_28 && (local_1c < local_34)))) {
        if (param_7 == (float *)0x0) {
          return 1;
        }
        *param_7 = local_3c;
        param_7[1] = local_38;
        param_7[2] = local_34;
        return 1;
      }
    }
    else {
      FUN_005b9c80(&local_3c,&local_c,&local_18,&local_30);
      if (((local_38 < local_2c) && (local_20 < local_38)) &&
         ((local_34 < local_28 && (local_1c < local_34)))) {
        if (param_7 == (float *)0x0) {
          return 1;
        }
        *param_7 = local_3c;
        param_7[1] = local_38;
        param_7[2] = local_34;
        return 1;
      }
    }
    if ((uVar1 & 2) == 0) {
      if (((((uVar1 & 0x10) != 0) &&
           (FUN_005b9cd0(&local_3c,&local_c,&local_18,&local_20), local_3c < local_30)) &&
          (local_24 < local_3c)) && ((local_34 < local_28 && (local_1c < local_34)))) {
        if (param_7 == (float *)0x0) {
          return 1;
        }
        *param_7 = local_3c;
        param_7[1] = local_38;
        param_7[2] = local_34;
        return 1;
      }
    }
    else {
      FUN_005b9cd0(&local_3c,&local_c,&local_18,&local_2c);
      if (((local_3c < local_30) && (local_24 < local_3c)) &&
         ((local_34 < local_28 && (local_1c < local_34)))) {
        if (param_7 == (float *)0x0) {
          return 1;
        }
        *param_7 = local_3c;
        param_7[1] = local_38;
        param_7[2] = local_34;
        return 1;
      }
    }
    if ((uVar1 & 4) == 0) {
      if (((((uVar1 & 0x20) != 0) &&
           (FUN_005b9d20(&local_3c,&local_c,&local_18,&local_1c), local_3c < local_30)) &&
          (local_24 < local_3c)) && ((local_38 < local_2c && (local_20 < local_38)))) {
        if (param_7 == (float *)0x0) {
          return 1;
        }
        *param_7 = local_3c;
        param_7[1] = local_38;
        param_7[2] = local_34;
        return 1;
      }
    }
    else {
      FUN_005b9d20(&local_3c,&local_c,&local_18,&local_28);
      if (((local_3c < local_30) && (local_24 < local_3c)) &&
         ((local_38 < local_2c && (local_20 < local_38)))) {
        if (param_7 == (float *)0x0) {
          return 1;
        }
        *param_7 = local_3c;
        param_7[1] = local_38;
        param_7[2] = local_34;
        return 1;
      }
    }
  }
  return 0;
}

