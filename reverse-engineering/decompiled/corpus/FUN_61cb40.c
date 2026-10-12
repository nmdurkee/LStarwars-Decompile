/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61cb40; label: FUN_0061cb40
 */

void FUN_0061cb40(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float local_18;
  int local_c;
  int local_8;
  
  if (DAT_0080f594 != 0) {
    local_c = 0;
    iVar1 = FUN_006e6b90();
    local_18 = 0.0;
    local_8 = param_5 - iVar1;
    do {
      iVar1 = FUN_006e6b90();
      FUN_005bd100(param_1,(float)(extraout_ST0 * (float10)*(float *)(param_1 + 0x4c) *
                                  (float10)*(float *)(param_1 + 0x44)),2);
      iVar2 = FUN_006e6b90();
      if (DAT_02912eb8 == 0) {
        FUN_005db5b0((local_c + param_2) * 0x10,(local_8 + param_3) * 8,(iVar1 + param_2) * 0x10,
                     ((param_5 - iVar2) + param_3) * 8,param_6,DAT_02900c70);
      }
      local_18 = local_18 + 0.01;
      local_c = iVar1;
      local_8 = param_5 - iVar2;
    } while (local_18 < 1.0 != (local_18 == 1.0));
  }
  if (DAT_02912f28 != 0) {
    local_18 = 1.4013e-45;
    do {
      if (DAT_02912f2c != 0) {
        FUN_005bd100(param_1,(float)(int)local_18 / 100.0,DAT_0080fb74);
      }
      iVar1 = FUN_006e6b90();
      FUN_005bd100(param_1,(float)extraout_ST0_00,DAT_0080fb70);
      iVar2 = FUN_006e6b90();
      iVar3 = FUN_006e6b90();
      if (DAT_02912eb8 == 0) {
        FUN_005db5b0((iVar1 + param_2) * 0x10,((param_3 - iVar2) + param_5) * 8,
                     (iVar1 + param_2) * 0x10,((param_3 - iVar3) + param_5) * 8,0x80000080,
                     DAT_02900c70);
      }
      local_18 = (float)((int)local_18 + 1);
    } while ((int)local_18 < 100);
  }
  return;
}

