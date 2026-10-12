/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x623fc0; label: FUN_00623fc0
 */

void FUN_00623fc0(undefined4 *param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  float local_a8 [9];
  float local_84;
  undefined4 local_80;
  undefined4 local_70;
  float local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_4c;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_a8[0] = -1.0;
  local_a8[1] = -1.0;
  local_a8[2] = 1.0;
  local_a8[4] = 1.0;
  local_a8[5] = 1.0;
  puVar2 = &DAT_009736e8;
  puVar4 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  local_a8[7] = 1.0;
  local_a8[3] = -1.0;
  local_a8[6] = -1.0;
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  uVar5 = 0;
  local_80 = 0;
  local_70 = param_3;
  local_5c = 0;
  local_4c = param_3;
  uVar3 = 2;
  do {
    local_a8[8] = local_a8[(uVar5 & 3) * 2] * param_2;
    local_84 = local_a8[uVar3 - 1 & 7] * param_2;
    local_64 = local_a8[uVar3 & 7] * param_2;
    local_60 = param_2 * local_a8[uVar3 + 1 & 7];
    FUN_00623d40(local_a8 + 8);
    uVar3 = uVar3 + 2;
    uVar5 = uVar5 + 1;
  } while ((int)uVar3 < 10);
  return;
}

