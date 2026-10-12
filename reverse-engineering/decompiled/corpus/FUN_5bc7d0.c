/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5bc7d0; label: FUN_005bc7d0
 */

void FUN_005bc7d0(int param_1,float param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  
  if (0 < param_1) {
    pfVar4 = param_3 + param_1 * 3;
    local_20 = 1;
    local_18 = *param_3 + (*param_3 - param_3[3]) * 0.1;
    local_14 = (param_3[1] - param_3[4]) * 0.1 + param_3[1];
    local_c = (*pfVar4 - pfVar4[-3]) * 0.1 + *pfVar4;
    local_8 = (pfVar4[1] - pfVar4[-2]) * 0.1 + pfVar4[1];
    if (7 < param_1) {
      fVar1 = (float)param_1;
      local_1c = 3;
      do {
        if (param_2 < (float)local_20 / fVar1) goto LAB_005bc97d;
        if (param_2 < (float)(local_1c + -1) / fVar1) {
          local_20 = local_20 + 1;
          goto LAB_005bc97d;
        }
        if (param_2 < (float)local_1c / fVar1) {
          local_20 = local_20 + 2;
          goto LAB_005bc97d;
        }
        if (param_2 < (float)(local_1c + 1) / fVar1) {
          local_20 = local_20 + 3;
          goto LAB_005bc97d;
        }
        if (param_2 < (float)(local_1c + 2) / fVar1) {
          local_20 = local_20 + 4;
          goto LAB_005bc97d;
        }
        if (param_2 < (float)(local_1c + 3) / fVar1) {
          local_20 = local_20 + 5;
          goto LAB_005bc97d;
        }
        if (param_2 < (float)(local_1c + 4) / fVar1) {
          local_20 = local_20 + 6;
          goto LAB_005bc97d;
        }
        if (param_2 < (float)(local_1c + 5) / fVar1) {
          local_20 = local_20 + 7;
          goto LAB_005bc97d;
        }
        local_20 = local_20 + 8;
        local_1c = local_1c + 8;
      } while (local_20 <= param_1 + -7);
    }
    if (local_20 <= param_1) {
      do {
        if (param_2 < (float)local_20 / (float)param_1) break;
        local_20 = local_20 + 1;
      } while (local_20 <= param_1);
    }
LAB_005bc97d:
    fVar1 = (float)param_1 * (param_2 - (float)(local_20 + -1) / (float)param_1);
    if (local_20 == 1) {
      pfVar4 = &local_18;
    }
    else {
      pfVar4 = param_3 + local_20 * 3 + -6;
    }
    param_3 = param_3 + local_20 * 3;
    pfVar3 = &local_c;
    if (local_20 < param_1) {
      pfVar3 = param_3 + 3;
    }
    fVar2 = fVar1 * fVar1;
    *param_4 = ((*pfVar3 + ((param_3[-3] * 3.0 - *pfVar4) - *param_3 * 3.0)) * fVar1 * fVar2 +
               param_3[-3] * 2.0 + (*param_3 - *pfVar4) * fVar1 +
               ((*param_3 * 4.0 + (*pfVar4 * 2.0 - param_3[-3] * 5.0)) - *pfVar3) * fVar2) * 0.5;
    param_4[1] = ((param_3[1] - pfVar4[1]) * fVar1 + param_3[-2] * 2.0 +
                  ((param_3[1] * 4.0 + (pfVar4[1] * 2.0 - param_3[-2] * 5.0)) - pfVar3[1]) * fVar2 +
                 fVar1 * fVar2 * (pfVar3[1] + ((param_3[-2] * 3.0 - pfVar4[1]) - param_3[1] * 3.0)))
                 * 0.5;
    param_4[2] = 0.0;
  }
  return;
}

