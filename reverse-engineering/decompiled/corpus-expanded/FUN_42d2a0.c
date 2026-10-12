/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42d2a0; label: FUN_0042d2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042d2a0(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 in_FPUControlWord;
  float10 fVar4;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  int local_28;
  undefined4 local_24;
  char *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_3c;
  local_24 = 0x6e6f6f47;
  local_20 = "PECTINGTAGEND";
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  sVar1 = FUN_00440030(0);
  if (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af48) {
    FUN_004f1f10(&local_24,"PenguinBox");
    sVar1 = DAT_007f1828;
  }
  local_28 = FUN_0054fa60();
  local_30 = (float)local_28 * 1.5259022e-05 * 100.0;
  if (50.0 <= local_30) {
    local_30 = local_30 - 50.0;
    if (local_30 < 50.0) {
      FUN_005b9ef0(&DAT_00802538);
      iVar2 = FUN_006e6b90();
      if (0 < 1 - iVar2) {
        local_28 = 1 - iVar2;
        do {
          fVar4 = (float10)FUN_005b9ef0(&DAT_00802538);
          local_30 = (float)CONCAT22(local_30._2_2_,in_FPUControlWord);
          local_2c = (float)(int)ROUND(fVar4 * (float10)65536.0);
          iVar2 = FUN_0043d890((int)sVar1,param_1 + 0x4c,(uint)local_2c & 0xffff,&local_24,0,0,1,0,0
                               ,0,0xffffffff);
          if (iVar2 == 0) {
            FUN_005b9ef0(&DAT_00802538);
            iVar2 = FUN_006e6b90();
            iVar2 = (iVar2 / 100) * 100;
            if (iVar2 < 100) {
              iVar2 = 100;
            }
            local_3c = DAT_00802500;
            local_38 = DAT_00802504;
            local_34 = DAT_00802508;
            FUN_005b35a0(&local_3c,&local_3c,*(undefined2 *)(param_1 + 0xee));
            FUN_005b3620(&local_3c,&local_3c,*(undefined2 *)(param_1 + 0xf0));
            uVar3 = FUN_0046c4f0(0,0,param_1 + 0x4c,&local_3c,0,0xffffffff,0x3fc00000,0x49f42400,0,1
                                 ,1);
            FUN_0046d270(iVar2,uVar3);
          }
          else {
            *(undefined4 *)(iVar2 + 0x102c) = 0;
            *(undefined4 *)(iVar2 + 0xff8) = 0;
            *(float *)(iVar2 + 0xa8) = *(float *)(*(int *)(iVar2 + 0x54) + 0x3c) * 0.0;
          }
          local_28 = local_28 + -1;
        } while (local_28 != 0);
        __security_check_cookie(local_4 ^ (uint)&local_3c);
        return;
      }
      goto LAB_0042d5de;
    }
    local_2c = local_30 - 50.0;
    if (local_2c < 0.0) goto LAB_0042d5de;
  }
  FUN_005b9ef0(&DAT_00802538);
  iVar2 = FUN_006e6b90();
  iVar2 = (iVar2 / 100) * 100;
  if (iVar2 < 100) {
    iVar2 = 100;
  }
  local_3c = DAT_00802500;
  local_38 = DAT_00802504;
  local_34 = DAT_00802508;
  FUN_005b35a0(&local_3c,&local_3c,*(undefined2 *)(param_1 + 0xee));
  FUN_005b3620(&local_3c,&local_3c,*(undefined2 *)(param_1 + 0xf0));
  uVar3 = FUN_0046c4f0(0,0,param_1 + 0x4c,&local_3c,0,0xffffffff,0x3fc00000,0x49f42400,0,1,1);
  FUN_0046d270(iVar2,uVar3);
LAB_0042d5de:
  __security_check_cookie(local_4 ^ (uint)&local_3c);
  return;
}

