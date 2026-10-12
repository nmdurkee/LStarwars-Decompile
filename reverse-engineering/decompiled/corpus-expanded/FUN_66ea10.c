/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66ea10; label: FUN_0066ea10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066ea10(float *param_1,float param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float10 fVar8;
  float local_30;
  float local_2c;
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x7000;
  do {
    iVar6 = local_1c;
    if (3 < local_20) {
      iVar6 = local_18 + 0x1000;
    }
    fVar4 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * param_2;
    if (local_20 < 3) {
      fVar3 = (float)(&DAT_029899a0)[local_1c + 0x1000 >> 1 & 0x7fff];
    }
    else {
      fVar3 = (float)(&DAT_029899a0)[local_18 >> 1 & 0x7fff];
    }
    fVar3 = param_2 * fVar3;
    fVar8 = (float10)FUN_005c0240(param_2 * param_2 - fVar4 * fVar4);
    local_30 = (float)(fVar8 * (float10)param_3);
    fVar8 = (float10)FUN_005c0240(param_2 * param_2 - fVar3 * fVar3);
    local_2c = (float)(fVar8 * (float10)param_3);
    if (4 < local_20) {
      local_30 = -local_30;
    }
    if (3 < local_20) {
      local_2c = -local_2c;
    }
    fVar5 = param_1[1] + param_2 * param_3;
    local_30 = local_30 + fVar5;
    iVar6 = 0x4000;
    do {
      uVar7 = iVar6 + -0x4000 >> 1 & 0x7fff;
      pfVar2 = (float *)(&DAT_029899a0 + (iVar6 >> 1 & 0x7fff));
      FUN_005dc050(fVar4 * *pfVar2 + *param_1,local_30,
                   param_1[2] + fVar4 * (float)(&DAT_029899a0)[uVar7],fVar3 * *pfVar2 + *param_1,
                   fVar5 + local_2c,param_1[2] + fVar3 * (float)(&DAT_029899a0)[uVar7],param_4);
      FUN_005dc050(fVar4 * *pfVar2 + *param_1,local_30,
                   (float)(&DAT_029899a0)[uVar7] * fVar4 + param_1[2],
                   (float)(&DAT_029899a0)[iVar6 + 0x800 >> 1 & 0x7fff] * fVar4 + *param_1,local_30,
                   param_1[2] + fVar4 * (float)(&DAT_029899a0)[iVar6 + -0x3800 >> 1 & 0x7fff],
                   param_4);
      iVar1 = iVar6 + -0x3800;
      iVar6 = iVar6 + 0x800;
    } while (iVar1 < 0x10000);
    local_20 = local_20 + 1;
    local_1c = local_1c + 0x1000;
    local_18 = local_18 + -0x1000;
  } while (-0x1000 < local_18);
  return;
}

