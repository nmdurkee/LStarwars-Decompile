/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e6e60; label: FUN_005e6e60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e6e60(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 char param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  float local_e8;
  float local_e4;
  undefined1 local_e0 [220];
  
  FUN_005c2760();
  local_fc = 0;
  if (0 < param_6) {
    do {
      iVar2 = param_2;
      iVar3 = param_1;
      if (local_fc == 0) {
LAB_005e6e93:
        if (param_7 == '\0') goto LAB_005e6ece;
        local_10c = local_fc + param_4;
        iVar4 = param_3;
      }
      else {
        if (param_7 != '\0') {
          iVar2 = local_fc + -1 + param_4;
          iVar3 = param_3;
          goto LAB_005e6e93;
        }
        iVar3 = (param_4 + local_fc) * 0x30 + -0x30 + param_3;
        iVar2 = 0;
LAB_005e6ece:
        iVar4 = (local_fc + param_4) * 0x30 + param_3;
        local_10c = 0;
      }
      if (0 < param_5) {
        local_f4 = param_5;
        do {
          FUN_005f7c60(iVar3,iVar2,&local_108,&local_104);
          FUN_005f7c60(iVar4,local_10c,&local_f8,&local_100);
          FUN_005c4b10(local_108,local_104,local_e0,0x3f800000);
          local_f0 = 0x3f800000;
          local_ec = 0x3f800000;
          local_e8 = _DAT_0097ade4 / (float)local_108;
          local_e4 = _DAT_0097ade4 / (float)local_104;
          FUN_00605b60(DAT_00973830,0,iVar4,local_10c);
          FUN_005f8bf0(DAT_00973830);
          FUN_005fa2f0(0,0,local_f8,local_100);
          FUN_005f7ed0(iVar3,2,2);
          if ((local_f8 < local_108) || (local_100 < local_104)) {
            uVar6 = 2;
            uVar5 = 2;
          }
          else {
            uVar6 = 1;
            uVar5 = 1;
          }
          FUN_005f7d00(iVar3,uVar5,uVar6,1);
          FUN_005f7cc0(iVar3,iVar2,iVar2);
          if ((iVar3 != 0) &&
             ((piVar1 = (int *)FUN_005f8460(iVar3), DAT_0097f9b8 != *piVar1 ||
              (DAT_0097f9bc != piVar1[1])))) {
            uVar5 = FUN_005f8460(iVar3);
            FUN_005fa540(0,uVar5);
          }
          FUN_005f8550(iVar3,0);
          FUN_006e5750(0xa0,local_e0,0xd);
          FUN_006e5750(0xad,&local_f0,1);
          FUN_005fb550();
          FUN_005f8ba0(0,1);
          local_f4 = local_f4 + -1;
          iVar2 = local_10c;
          iVar3 = iVar4;
        } while (local_f4 != 0);
      }
      local_fc = local_fc + 1;
    } while (local_fc < param_6);
  }
  return;
}

