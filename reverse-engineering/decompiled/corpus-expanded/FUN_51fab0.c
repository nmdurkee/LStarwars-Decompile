/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fab0; label: FUN_0051fab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051fab0(float *param_1,float param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float local_24;
  float local_20;
  float local_1c;
  
  iVar5 = 1;
  local_24 = *param_1;
  local_20 = param_1[1];
  local_1c = param_2 + param_1[2];
  if (param_5 < 1) {
    return;
  }
  do {
    fVar1 = param_1[1];
    iVar4 = (iVar5 << 0x10) / param_5;
    fVar3 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * param_2 + *param_1;
    fVar2 = param_2 * (float)(&DAT_029899a0)[iVar4 + 0x4000 >> 1 & 0x7fff] + param_1[2];
    FUN_00512cc0(local_24,local_20,local_1c,fVar3,fVar1,fVar2,param_3);
    iVar5 = iVar5 + 1;
    local_24 = fVar3;
    local_20 = fVar1;
    local_1c = fVar2;
  } while (iVar5 <= param_5);
  return;
}

