/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e7ad0; label: FUN_005e7ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e7ad0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char *in_ECX;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  if ((*in_ECX != '\0') && (in_ECX[1] != '\0')) {
    FUN_005c1a30();
    fVar1 = param_2 * local_50;
    fVar2 = local_40 * param_2;
    fVar3 = local_30 * param_2;
    fVar4 = local_4c * param_2;
    fVar5 = local_3c * param_2;
    fVar6 = local_2c * param_2;
    local_20 = local_48 * param_2;
    local_1c = local_38 * param_2;
    param_2 = param_2 * local_28;
    local_44 = 0x3f800000;
    local_34 = 0x3f800000;
    local_24 = 0x3f800000;
    local_14 = 0x3f800000;
    local_50 = ((fVar4 + *param_1) - fVar1) - local_20;
    local_4c = ((fVar5 + param_1[1]) - fVar2) - local_1c;
    local_48 = ((fVar6 + param_1[2]) - fVar3) - param_2;
    local_40 = *param_1 + fVar4 + fVar1 + local_20;
    local_3c = param_1[1] + fVar5 + fVar2 + local_1c;
    local_38 = param_1[2] + fVar6 + fVar3 + param_2;
    local_30 = (*param_1 - fVar4) + fVar1 + local_20;
    local_2c = (param_1[1] - fVar5) + fVar2 + local_1c;
    local_28 = (param_1[2] - fVar6) + fVar3 + param_2;
    local_20 = ((*param_1 - fVar4) - fVar1) - local_20;
    local_1c = ((param_1[1] - fVar5) - fVar2) - local_1c;
    local_18 = ((param_1[2] - fVar6) - fVar3) - param_2;
    FUN_005e7840(&local_50,&local_40,&local_30,&local_20);
  }
  return;
}

