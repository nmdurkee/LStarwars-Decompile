/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5ba060; label: FUN_005ba060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ba060(float *param_1,int param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  uint uVar5;
  float local_14 [5];
  
  uVar5 = 0;
  fVar2 = 1.0 - param_3;
  fVar1 = 1.0 - param_4;
  local_14[1] = fVar2 * fVar2 * fVar2;
  local_14[2] = fVar2 * fVar2 * 3.0 * param_3;
  local_14[3] = fVar2 * 3.0 * param_3 * param_3;
  local_14[4] = param_3 * param_3 * param_3;
  *param_1 = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  pfVar4 = (float *)(param_2 + 0x38);
  do {
    iVar3 = uVar5 + 1;
    uVar5 = uVar5 + 1;
    fVar2 = local_14[iVar3] * fVar1 * fVar1 * fVar1;
    *param_1 = *param_1 + fVar2 * pfVar4[-0xe];
    param_1[1] = pfVar4[-0xd] * fVar2 + param_1[1];
    param_1[2] = fVar2 * pfVar4[-0xc] + param_1[2];
    fVar2 = local_14[uVar5] * fVar1 * fVar1 * 3.0 * param_4;
    *param_1 = *param_1 + fVar2 * pfVar4[-2];
    param_1[1] = pfVar4[-1] * fVar2 + param_1[1];
    param_1[2] = fVar2 * *pfVar4 + param_1[2];
    fVar2 = local_14[uVar5] * param_4 * param_4 * fVar1 * 3.0;
    *param_1 = *param_1 + fVar2 * pfVar4[10];
    param_1[1] = pfVar4[0xb] * fVar2 + param_1[1];
    param_1[2] = fVar2 * pfVar4[0xc] + param_1[2];
    fVar2 = local_14[uVar5] * param_4 * param_4 * param_4;
    *param_1 = *param_1 + fVar2 * pfVar4[0x16];
    param_1[1] = pfVar4[0x17] * fVar2 + param_1[1];
    param_1[2] = fVar2 * pfVar4[0x18] + param_1[2];
    pfVar4 = pfVar4 + 3;
  } while (uVar5 < 4);
  return;
}

