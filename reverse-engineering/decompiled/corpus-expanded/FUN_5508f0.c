/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x5508f0; label: FUN_005508f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005508f0(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  float *pfVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  short *in_EAX;
  float *pfVar5;
  float *pfVar6;
  int in_EDX;
  float10 fVar7;
  float local_c;
  float local_8;
  
  puVar3 = param_2;
  if ((param_2 == (undefined2 *)0x0) && (param_3 == (undefined2 *)0x0)) {
    return;
  }
  pfVar6 = *(float **)(in_EAX + 4);
  param_2 = (undefined2 *)0x0;
  local_8 = 0.0;
  pfVar2 = pfVar6 + in_EDX * 3;
  local_c = 0.0;
  if (in_EDX + -1 < 0) {
    if (param_1 != 0) {
      iVar1 = *in_EAX * 3 + -3;
      goto LAB_00550943;
    }
  }
  else {
    iVar1 = (in_EDX + -1) * 3;
LAB_00550943:
    pfVar5 = pfVar6 + iVar1;
    if (pfVar5 != (float *)0x0) {
      local_c = (*pfVar2 - *pfVar5) + 0.0;
      local_8 = (pfVar2[1] - pfVar5[1]) + 0.0;
      param_2 = (undefined2 *)((pfVar2[2] - pfVar5[2]) + 0.0);
    }
  }
  iVar1 = in_EDX + 1;
  if (iVar1 < *in_EAX) {
LAB_0055097f:
    pfVar6 = pfVar6 + iVar1 * 3;
  }
  else if (param_1 == 0) {
    if (*in_EAX <= iVar1) goto LAB_005509b1;
    goto LAB_0055097f;
  }
  if (pfVar6 != (float *)0x0) {
    local_c = (*pfVar6 - *pfVar2) + local_c;
    local_8 = (pfVar6[1] - pfVar2[1]) + local_8;
    param_2 = (undefined2 *)((pfVar6[2] - pfVar2[2]) + (float)param_2);
  }
LAB_005509b1:
  if (puVar3 != (undefined2 *)0x0) {
    fVar7 = (float10)FUN_005c0240(local_c * local_c + (float)param_2 * (float)param_2);
    uVar4 = FUN_005be2d0(local_8,(float)fVar7);
    *puVar3 = uVar4;
  }
  if (param_3 != (undefined2 *)0x0) {
    uVar4 = FUN_005be2d0(local_c,param_2);
    *param_3 = uVar4;
  }
  return;
}

