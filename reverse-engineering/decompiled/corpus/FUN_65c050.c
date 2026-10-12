/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65c050; label: FUN_0065c050
 */

void FUN_0065c050(float param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  float local_6c [10];
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  local_6c[0] = 1.0;
  local_6c[1] = 0.0;
  local_6c[2] = 0.0;
  local_6c[3] = 0.0;
  iVar1 = 0;
  local_6c[5] = 0.0;
  local_6c[6] = 0.0;
  local_6c[7] = 0.0;
  local_6c[4] = 1.0;
  local_6c[8] = 1.0;
  do {
    local_30 = param_5;
    local_c = param_5;
    local_6c[9] = param_1 + local_6c[iVar1] * param_4;
    local_44 = param_2 + local_6c[iVar1 + 1] * param_4;
    local_40 = param_3 + local_6c[iVar1 + 2] * param_4;
    local_24 = param_1 - local_6c[iVar1] * param_4;
    local_20 = param_2 - local_6c[iVar1 + 1] * param_4;
    local_1c = param_3 - local_6c[iVar1 + 2] * param_4;
    FUN_005dbed0(local_6c + 9,param_6,0);
    iVar1 = iVar1 + 3;
  } while (iVar1 < 9);
  return;
}

