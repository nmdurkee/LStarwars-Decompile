/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5bcab0; label: FUN_005bcab0
 */

void FUN_005bcab0(int param_1,float param_2,int param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  int local_8;
  int local_4;
  
  local_8 = 1;
  if (7 < param_1) {
    fVar2 = (float)param_1;
    local_4 = 3;
    do {
      if (param_2 < (float)local_8 / fVar2) goto LAB_005bcc07;
      if (param_2 < (float)(local_4 + -1) / fVar2) {
        local_8 = local_8 + 1;
        goto LAB_005bcc07;
      }
      if (param_2 < (float)local_4 / fVar2) {
        local_8 = local_8 + 2;
        goto LAB_005bcc07;
      }
      if (param_2 < (float)(local_4 + 1) / fVar2) {
        local_8 = local_8 + 3;
        goto LAB_005bcc07;
      }
      if (param_2 < (float)(local_4 + 2) / fVar2) {
        local_8 = local_8 + 4;
        goto LAB_005bcc07;
      }
      if (param_2 < (float)(local_4 + 3) / fVar2) {
        local_8 = local_8 + 5;
        goto LAB_005bcc07;
      }
      if (param_2 < (float)(local_4 + 4) / fVar2) {
        local_8 = local_8 + 6;
        goto LAB_005bcc07;
      }
      if (param_2 < (float)(local_4 + 5) / fVar2) {
        local_8 = local_8 + 7;
        goto LAB_005bcc07;
      }
      local_8 = local_8 + 8;
      local_4 = local_4 + 8;
    } while (local_8 <= param_1 + -7);
  }
  if (local_8 <= param_1) {
    do {
      if (param_2 < (float)local_8 / (float)param_1) break;
      local_8 = local_8 + 1;
    } while (local_8 <= param_1);
  }
LAB_005bcc07:
  pfVar1 = (float *)(param_3 + local_8 * 0xc);
  fVar2 = (float)param_1 * (param_2 - (float)(local_8 + -1) / (float)param_1);
  *param_4 = pfVar1[-3] + fVar2 * (*pfVar1 - pfVar1[-3]);
  param_4[1] = (pfVar1[1] - pfVar1[-2]) * fVar2 + pfVar1[-2];
  param_4[2] = 0.0;
  return;
}

