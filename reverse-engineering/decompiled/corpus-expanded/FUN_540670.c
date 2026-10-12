/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x540670; label: FUN_00540670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00540670(undefined4 *param_1,int param_2,undefined4 param_3,int *param_4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float local_30 [3];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18 [3];
  float local_c [3];
  
  local_24 = *param_1;
  local_1c = param_1[2];
  local_20 = 0;
  iVar5 = *(char *)(param_2 + 1) * 0x13c + *param_4;
  iVar2 = *(short *)(param_2 + 0x28) * 0xc;
  pfVar3 = (float *)(*(int *)(*(int *)(iVar5 + 4) + 8) + iVar2);
  local_30[0] = (*pfVar3 - pfVar3[-3]) * *(float *)(param_2 + 4) + pfVar3[-3];
  local_30[1] = 0.0;
  local_30[2] = (pfVar3[2] - pfVar3[-1]) * *(float *)(param_2 + 4) + pfVar3[-1];
  if ((*(byte *)(iVar5 + 0x68) & 1) == 0) {
    iVar5 = *(int *)(*(int *)(iVar5 + 0x10) + 8);
    iVar4 = iVar5 + iVar2;
    local_c[0] = (*(float *)(iVar5 + iVar2) - *(float *)(iVar4 + -0xc)) * *(float *)(param_2 + 4) +
                 *(float *)(iVar4 + -0xc);
    local_c[1] = 0.0;
    local_c[2] = (*(float *)(iVar4 + 8) - *(float *)(iVar4 + -4)) * *(float *)(param_2 + 4) +
                 *(float *)(iVar4 + -4);
    fVar6 = (float10)FUN_005b3c50(&local_24,local_30,0);
    pfVar3 = local_c;
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar5 + 8) + 8);
    iVar4 = iVar5 + iVar2;
    local_18[0] = (*(float *)(iVar5 + iVar2) - *(float *)(iVar4 + -0xc)) * *(float *)(param_2 + 4) +
                  *(float *)(iVar4 + -0xc);
    local_18[1] = 0.0;
    local_18[2] = (*(float *)(iVar4 + 8) - *(float *)(iVar4 + -4)) * *(float *)(param_2 + 4) +
                  *(float *)(iVar4 + -4);
    fVar6 = (float10)FUN_005b3c50(&local_24,local_30,0);
    pfVar3 = local_18;
  }
  fVar7 = (float10)FUN_005b3c50(&local_24,pfVar3,0);
  fVar1 = (float)fVar7;
  if ((float)fVar6 < fVar1) {
    fVar1 = (float)fVar6;
  }
  if (fVar1 <= 0.0) {
    return (float10)0.0;
  }
  fVar6 = (float10)FUN_005c0240(fVar1);
  return (float10)(float)fVar6;
}

