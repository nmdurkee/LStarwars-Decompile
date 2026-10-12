/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65c380; label: FUN_0065c380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065c380(float *param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_0065c160(param_1,param_2 - param_3,param_2 - param_3,param_5,param_6,0,0);
  FUN_0065c160(param_1,param_2 + param_3,param_2 + param_3,param_5,param_6,0,0);
  local_c = *param_1;
  local_4 = param_1[2];
  local_8 = param_1[1] - param_4;
  FUN_0065c160(&local_c,param_2,param_2,param_5,param_6,0,0);
  local_c = *param_1;
  local_4 = param_1[2];
  local_8 = param_1[1] + param_4;
  FUN_0065c160(&local_c,param_2,param_2,param_5,param_6,0,0);
  iVar2 = 0;
  do {
    local_8 = param_1[1];
    iVar1 = (iVar2 << 0x10) / 10;
    local_c = *param_1 + param_2 * (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
    local_4 = param_2 * (float)(&DAT_029899a0)[iVar1 + 0x4000 >> 1 & 0x7fff] + param_1[2];
    FUN_0065c160(&local_c,param_4,param_3,param_5,param_6,0x4000,iVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xb);
  return;
}

