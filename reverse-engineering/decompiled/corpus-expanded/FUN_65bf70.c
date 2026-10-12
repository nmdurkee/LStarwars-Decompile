/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65bf70; label: FUN_0065bf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065bf70(float param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  float local_78 [13];
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  local_78[0] = 1.0;
  local_78[1] = 1.0;
  local_78[2] = 1.0;
  local_78[3] = -1.0;
  iVar1 = 0;
  local_78[7] = -1.0;
  local_78[9] = -1.0;
  local_78[10] = -1.0;
  local_78[4] = 1.0;
  local_78[5] = 1.0;
  local_78[6] = 1.0;
  local_78[8] = 1.0;
  local_78[0xb] = 1.0;
  do {
    local_30 = param_5;
    local_c = param_5;
    local_78[0xc] = param_1 + local_78[iVar1] * param_4;
    local_44 = param_2 + local_78[iVar1 + 1] * param_4;
    local_40 = param_3 + local_78[iVar1 + 2] * param_4;
    local_24 = param_1 - local_78[iVar1] * param_4;
    local_20 = param_2 - local_78[iVar1 + 1] * param_4;
    local_1c = param_3 - local_78[iVar1 + 2] * param_4;
    FUN_005dbed0(local_78 + 0xc,param_6,0);
    iVar1 = iVar1 + 3;
  } while (iVar1 < 0xc);
  return;
}

