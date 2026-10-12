/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46d270; label: FUN_0046d270
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d270(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,int param_8,float param_9,undefined4 param_10
                 ,int param_11,int param_12,uint param_13)

{
  char *pcVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int aiStackY_40010 [65515];
  undefined4 local_3c;
  float local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte local_14 [4];
  int local_10 [2];
  undefined2 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_3c;
  local_3c = param_5;
  local_30 = param_6;
  local_1c = param_11;
  iVar5 = FUN_0055f450();
  local_38 = DAT_00950f60;
  local_18 = iVar5;
  FUN_00475850(local_14);
  if ((local_14[0] & 0x10) != 0) {
    param_3 = 0;
    param_1 = 0;
  }
  iVar6 = *(int *)(iVar5 + 300);
  if ((iVar6 != 0) && ((*(ushort *)(iVar6 + 0x7a) & 0x104) == 4)) {
    param_12 = 0;
  }
  if ((*(uint *)(*(int *)(iVar5 + 0x128) + 100) & 0x80000) == 0) {
    if ((iVar6 == 0) || ((*(ushort *)(iVar6 + 0x7a) & 0x100) == 0)) {
      local_34 = -(uint)(param_8 != -1) & param_13;
    }
    else {
      iVar5 = FUN_0054fa60();
      param_8 = (int)(iVar5 + (iVar5 >> 0x1f & 0x7fffU)) >> 0xf;
      local_34 = 1;
    }
  }
  else {
    local_34 = 1;
    if (param_8 == -1) {
      if (DAT_0093d814 == 0) {
        if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
          param_8 = 1;
        }
        else {
          param_8 = 0;
        }
      }
      else {
        iVar5 = FUN_0054fa60();
        param_8 = (int)(iVar5 + (iVar5 >> 0x1f & 0x7fffU)) >> 0xf;
      }
    }
  }
  if ((DAT_00856c08 != 0) || (iVar5 = FUN_0058a900(0), iVar5 != 0)) {
    param_1 = 0;
  }
  if (param_9 == 1.0) {
    param_9 = param_9 * local_38;
  }
  local_10[0] = 0;
  local_10[1] = 0;
  local_8 = 0;
  if (DAT_00951b50 != 0) goto LAB_0046d761;
  if (0 < param_1 % 10) {
    param_1 = param_1 - param_1 % 10;
  }
  if (param_1 < 0x7d001) {
    if (0 < param_1) goto LAB_0046d419;
  }
  else {
    param_1 = 0x7d000;
LAB_0046d419:
    FUN_00681f40("CoinsLand",param_5);
  }
  iVar5 = param_1;
  if (param_12 == 0) {
    if (0 < param_1) {
      pbVar9 = &DAT_007f902b;
      do {
        iVar6 = iVar5 - (uint)*(ushort *)(&DAT_007f8e0a + (uint)*pbVar9 * 0x38);
        if (-1 < iVar6) {
          pcVar1 = (char *)((int)local_10 + (uint)*pbVar9);
          cVar8 = *pcVar1;
          do {
            iVar5 = iVar6;
            cVar8 = cVar8 + '\x01';
            iVar6 = iVar5 - (uint)*(ushort *)(&DAT_007f8e0a + (uint)*pbVar9 * 0x38);
          } while (-1 < iVar6);
          *pcVar1 = cVar8;
        }
        pbVar9 = pbVar9 + -1;
      } while (0 < iVar5);
    }
  }
  else {
    for (; 0 < iVar5; iVar5 = iVar5 - (uint)uVar2) {
      do {
        iVar6 = FUN_0054fa60();
        uVar2 = *(ushort *)
                 (&DAT_007f8e0a +
                 (uint)(byte)(&DAT_007f9028)[(int)(iVar6 + (iVar6 >> 0x1f & 0x3fffU)) >> 0xe] * 0x38
                 );
      } while ((int)(iVar5 - (uint)uVar2) < 0);
      pcVar1 = (char *)((int)local_10 +
                       (uint)(byte)(&DAT_007f9028)[(int)(iVar6 + (iVar6 >> 0x1f & 0x3fffU)) >> 0xe])
      ;
      *pcVar1 = *pcVar1 + '\x01';
    }
  }
  if ((param_8 != 0) && (param_8 != 1)) {
    param_8 = -1;
  }
  if (local_34 == 0) {
    iVar5 = 0;
    do {
      uVar3 = local_3c;
      uVar10 = (uint)(byte)(&DAT_007f9028)[iVar5];
      if (*(char *)((int)local_10 + uVar10) != '\0') {
        uVar11 = (uint)*(byte *)((int)local_10 + uVar10);
        do {
          FUN_00571ea0(&local_2c,local_30,param_9);
          FUN_0046cd40(uVar10,uVar3,&local_2c,param_10,local_38);
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  else {
    if (0 < param_1) {
      _DAT_0087b94c = _DAT_008033a8 + 1.0;
    }
    FUN_0046cf10(param_1,local_3c,param_8,param_9,local_1c,param_12);
  }
  uVar3 = local_3c;
  iVar5 = 0;
  if (((((param_2 < 1) || (DAT_00951288 == 0)) || (DAT_0093d7f0 == 0)) ||
      (((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0 || (DAT_0093d7f4 == 0)))) ||
     ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
    local_20 = 0;
  }
  else {
    param_2 = 2;
    local_20 = 1;
  }
  if (0 < param_2) {
    do {
      if (local_34 == 0) {
        FUN_00571ea0(&local_2c,local_30,param_9);
      }
      else {
        local_2c = DAT_0093b0cc;
        local_28 = DAT_0093b0d0;
        local_24 = DAT_0093b0d4;
      }
      if (local_20 == 0) {
        iVar6 = local_1c;
        if (local_1c == 0) {
          iVar7 = 0;
          if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
            local_10[0] = DAT_0093d7f0;
            iVar7 = 1;
          }
          if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
            local_10[iVar7] = DAT_0093d7f4;
            iVar7 = iVar7 + 1;
          }
          iVar6 = 0;
          if (iVar7 != 0) {
            if (iVar7 == 1) {
              iVar6 = 0;
            }
            else {
              iVar6 = FUN_0054fa60();
              iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 0x7fffU)) >> 0xf;
            }
            iVar6 = local_10[iVar6];
          }
        }
      }
      else {
        iVar6 = DAT_0093d7f4;
        if (iVar5 == 0) {
          iVar6 = DAT_0093d7f0;
        }
      }
      FUN_0046bf10(iVar6,uVar3,&local_2c,local_38,param_10);
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
  }
  uVar4 = local_30;
  uVar3 = local_3c;
  if (0 < param_3) {
    do {
      FUN_00571ea0(&local_2c,uVar4,param_9);
      FUN_0046bdb0(uVar3,&local_2c,local_38,param_10);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  uVar4 = local_30;
  uVar3 = local_3c;
  if (((*(uint *)(*(int *)(local_18 + 0x128) + 100) & 0x80000) == 0) && (0 < param_4)) {
    do {
      FUN_00571ea0(&local_2c,uVar4,param_9);
      FUN_0046c210(uVar3,&local_2c,local_38,param_10);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
LAB_0046d761:
  __security_check_cookie(local_4 ^ (uint)&local_3c);
  return;
}

