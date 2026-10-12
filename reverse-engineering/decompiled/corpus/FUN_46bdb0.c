/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46bdb0; label: FUN_0046bdb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046bdb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_d0 [5];
  float local_bc;
  float local_b8;
  float local_b4;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_9c;
  code *local_90;
  undefined4 local_88;
  code *local_84;
  code *local_7c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_2c;
  undefined4 local_10;
  
  iVar2 = FUN_0055f450();
  puVar4 = &DAT_00810210;
  puVar5 = local_d0;
  for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_d0[1] = param_1;
  local_d0[2] = param_2;
  local_bc = _DAT_007f8fcc * *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8) * 4.0;
  local_a8 = 0x79;
  local_b8 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8) * 4.0 * _DAT_007f8fe8;
  local_ac = *(int *)(iVar2 + 0x2ac0) + 0x790;
  local_b4 = _DAT_00950f5c;
  if (_DAT_00950f5c == 0.0) {
    local_2c = 0x40a00000;
  }
  else {
    local_84 = FUN_00571c50;
  }
  local_90 = FUN_0042cf20;
  local_48 = param_4;
  local_7c = FUN_004d3760;
  local_88 = 0;
  local_a4 = 0x256;
  if (_DAT_00950f5c == 0.0) {
    local_9c = &LAB_0046ba80;
  }
  local_44 = _DAT_00925018;
  local_10 = param_3;
  iVar2 = FUN_0064d270(local_d0);
  if (iVar2 != 0) {
    uVar1 = FUN_0054fa60();
    *(undefined2 *)(iVar2 + 0x13a) = uVar1;
    *(undefined1 *)(iVar2 + 0x206) = 3;
    *(float *)(iVar2 + 0x214) =
         *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8) * 4.0 * DAT_029919a0;
  }
  return;
}

