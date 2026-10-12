/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65c160; label: FUN_0065c160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065c160(float *param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = 0.0;
  local_8 = 0.0;
  local_4 = param_3;
  if (param_6 != 0) {
    FUN_005b3690(&local_c,&local_c,param_6);
  }
  if (param_7 != 0) {
    FUN_005b3620(&local_c,&local_c,param_7);
  }
  local_c = *param_1 + local_c;
  iVar5 = 1;
  local_8 = local_8 + param_1[1];
  local_4 = param_1[2] + local_4;
  do {
    fVar4 = local_4;
    fVar3 = local_8;
    fVar2 = local_c;
    iVar1 = (iVar5 << 0x10) / 10;
    local_c = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * param_2;
    local_8 = 0.0;
    local_4 = (float)(&DAT_029899a0)[iVar1 + 0x4000 >> 1 & 0x7fff] * param_3;
    if (param_6 != 0) {
      FUN_005b3690(&local_c,&local_c,param_6);
    }
    if (param_7 != 0) {
      FUN_005b3620(&local_c,&local_c,param_7);
    }
    local_c = *param_1 + local_c;
    local_8 = local_8 + param_1[1];
    local_4 = param_1[2] + local_4;
    FUN_005dc050(fVar2,fVar3,fVar4,local_c,local_8,local_4,param_4);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xb);
  return;
}

