/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ebeb0; label: FUN_005ebeb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ebeb0(float *param_1,float param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float10 fVar8;
  float local_28;
  float local_24;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x7000;
  do {
    iVar6 = local_14;
    if (3 < local_18) {
      iVar6 = local_10 + 0x1000;
    }
    fVar5 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * param_2;
    if (local_18 < 3) {
      fVar3 = (float)(&DAT_029899a0)[local_14 + 0x1000 >> 1 & 0x7fff];
    }
    else {
      fVar3 = (float)(&DAT_029899a0)[local_10 >> 1 & 0x7fff];
    }
    fVar3 = param_2 * fVar3;
    fVar8 = (float10)FUN_005c0240(param_2 * param_2 - fVar5 * fVar5);
    local_28 = (float)(fVar8 * (float10)param_4);
    fVar8 = (float10)FUN_005c0240(param_2 * param_2 - fVar3 * fVar3);
    local_24 = (float)(fVar8 * (float10)param_4);
    if (4 < local_18) {
      local_28 = -local_28;
    }
    if (3 < local_18) {
      local_24 = -local_24;
    }
    local_28 = local_28 + param_1[1];
    fVar4 = param_1[1];
    iVar6 = 0x4000;
    do {
      uVar7 = iVar6 + -0x4000 >> 1 & 0x7fff;
      pfVar2 = (float *)(&DAT_029899a0 + (iVar6 >> 1 & 0x7fff));
      FUN_005dc050(fVar5 * *pfVar2 + *param_1,local_28,
                   param_1[2] + fVar5 * (float)(&DAT_029899a0)[uVar7],fVar3 * *pfVar2 + *param_1,
                   local_24 + fVar4,param_1[2] + fVar3 * (float)(&DAT_029899a0)[uVar7],param_3);
      FUN_005dc050(fVar5 * *pfVar2 + *param_1,local_28,
                   (float)(&DAT_029899a0)[uVar7] * fVar5 + param_1[2],
                   (float)(&DAT_029899a0)[iVar6 + 0x800 >> 1 & 0x7fff] * fVar5 + *param_1,local_28,
                   param_1[2] + fVar5 * (float)(&DAT_029899a0)[iVar6 + -0x3800 >> 1 & 0x7fff],
                   param_3);
      iVar1 = iVar6 + -0x3800;
      iVar6 = iVar6 + 0x800;
    } while (iVar1 < 0x10000);
    local_18 = local_18 + 1;
    local_14 = local_14 + 0x1000;
    local_10 = local_10 + -0x1000;
  } while (-0x1000 < local_10);
  return;
}

