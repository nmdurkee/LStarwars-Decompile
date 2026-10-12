/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46cd40; label: FUN_0046cd40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046cd40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5
                 )

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_d0 [5];
  float local_bc;
  float local_b8;
  float local_b4;
  int local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined1 *local_94;
  code *local_90;
  undefined1 *local_84;
  code *local_80;
  undefined4 local_48;
  undefined4 local_44;
  float local_10;
  
  iVar1 = FUN_0055f450();
  iVar3 = (int)*(short *)(&DAT_007f8e08 + param_1 * 0x38);
  if ((&DAT_007f8e05)[param_1 * 0x38] != '\0') {
    iVar2 = FUN_0054fa60();
    iVar3 = iVar3 + iVar2 / ((int)(0xffff / (ulonglong)
                                            (longlong)
                                            (int)(uint)(byte)(&DAT_007f8e05)[param_1 * 0x38]) + 1);
  }
  if (*(char *)(*(int *)(iVar1 + 0x2ac0) + 0xe + iVar3 * 0x10) != '\0') {
    puVar4 = &DAT_00810210;
    puVar5 = local_d0;
    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    local_d0[1] = param_2;
    local_d0[2] = param_3;
    local_bc = param_5 * (float)(&DAT_007f8e0c)[param_1 * 0xe];
    local_b4 = _DAT_00950f5c;
    local_ac = *(int *)(iVar1 + 0x2ac0) + iVar3 * 0x10;
    local_a4 = 0x56;
    if ((iVar3 < 0xd5) || (0xd8 < iVar3)) {
      if ((iVar3 < 199) || (0xca < iVar3)) {
        if ((iVar3 < 0xd5) || (0xd8 < iVar3)) {
          local_80 = FUN_0046cb50;
        }
        else {
          local_a4 = 0x256;
          local_a0 = &LAB_0046ba50;
        }
      }
      else {
        local_a4 = 0x256;
        local_a0 = &LAB_0046ba20;
      }
    }
    else {
      local_a4 = 0x256;
    }
    local_48 = param_4;
    local_90 = FUN_0042cf20;
    local_44 = _DAT_00925018;
    local_84 = &LAB_0046cc30;
    local_94 = &LAB_0046b910;
    local_10 = param_5;
    local_b8 = local_bc;
    local_a8 = iVar3;
    iVar1 = FUN_0064d270(local_d0);
    if ((iVar1 != 0) && (*(undefined4 *)(iVar1 + 0x100) = 0x41f00000, local_b4 == 0.0)) {
      *(undefined1 **)(iVar1 + 0x1b0) = &LAB_0046ba80;
      iVar3 = FUN_0054fa60();
      *(float *)(iVar1 + 0x104) = (float)iVar3 * 1.5259022e-05 + 4.0;
    }
  }
  return;
}

