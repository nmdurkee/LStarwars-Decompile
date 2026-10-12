/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46bf10; label: FUN_0046bf10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046bf10(int param_1,undefined4 param_2,undefined4 param_3,float param_4,undefined4 param_5
                 )

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_d0 [4];
  int local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_9c;
  code *local_90;
  code *local_88;
  code *local_84;
  code *local_7c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_2c;
  float local_10;
  
  iVar2 = FUN_0055f450();
  if (param_1 != 0) {
    puVar4 = &DAT_00810210;
    puVar5 = local_d0;
    for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    local_bc = param_4 * _DAT_007f8f24;
    local_b4 = _DAT_00950f5c;
    local_d0[1] = param_2;
    local_d0[2] = param_3;
    local_a8 = 0xcb;
    local_ac = *(int *)(iVar2 + 0x2ac0) + 0xcb0;
    local_48 = param_5;
    local_90 = FUN_0042cf20;
    local_88 = FUN_00570c00;
    local_a4 = 0x256;
    if ((*(uint *)(*(int *)(iVar2 + 0x128) + 100) & 0x80000) == 0) {
      local_84 = FUN_00571c50;
      local_7c = FUN_00571c80;
      if (_DAT_00950f5c == 0.0) {
        local_9c = (code *)&LAB_0046ba80;
      }
    }
    else {
      local_9c = FUN_0046bbd0;
      local_2c = _DAT_007f903c;
      local_c0 = param_1;
      local_7c = (code *)&LAB_0046bcd0;
      local_a4 = 0x656;
    }
    local_44 = _DAT_00925018;
    local_10 = param_4;
    local_b8 = local_bc;
    iVar2 = FUN_0064d270(local_d0);
    if (iVar2 != 0) {
      uVar1 = FUN_0054fa60();
      *(undefined2 *)(iVar2 + 0x13a) = uVar1;
    }
  }
  return;
}

