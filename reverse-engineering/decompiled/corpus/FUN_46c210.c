/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c210; label: FUN_0046c210
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046c210(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined2 local_d4;
  undefined4 local_d0 [5];
  float local_bc;
  float local_b8;
  float local_b4;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_9c;
  code *local_94;
  code *local_90;
  code *local_88;
  code *local_84;
  code *local_7c;
  undefined4 local_48;
  undefined4 local_44;
  float local_10;
  
  iVar1 = FUN_0055f450();
  puVar3 = &DAT_00810210;
  puVar4 = local_d0;
  for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_b4 = _DAT_00950f5c;
  local_d0[1] = param_1;
  local_d0[2] = param_2;
  local_a8 = 0xd0;
  local_ac = *(int *)(iVar1 + 0x2ac0) + 0xd00;
  local_48 = param_4;
  local_90 = FUN_0042cf20;
  local_88 = FUN_0046c100;
  local_94 = FUN_0046c050;
  local_a4 = 0x256;
  local_84 = FUN_00571c50;
  local_7c = FUN_0046c1b0;
  if (_DAT_00950f5c == 0.0) {
    local_9c = &LAB_0046ba80;
  }
  local_44 = _DAT_00925018;
  local_10 = param_3;
  local_bc = param_3 * _DAT_007f9004;
  local_b8 = param_3 * _DAT_007f9004;
  iVar1 = FUN_0064d270(local_d0);
  if (iVar1 != 0) {
    fVar5 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
    local_d4 = (undefined2)(int)ROUND(fVar5 * (float10)0.25 * (float10)65536.0);
    *(undefined2 *)(iVar1 + 0x13a) = local_d4;
  }
  return;
}

