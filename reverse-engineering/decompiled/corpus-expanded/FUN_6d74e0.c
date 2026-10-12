/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d74e0; label: FUN_006d74e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d74e0(int param_1,undefined2 *param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined1 local_13c [4];
  undefined4 local_138;
  undefined2 local_134;
  short local_132;
  undefined2 uStack_130;
  short local_12e;
  undefined2 uStack_12c;
  undefined1 local_128 [16];
  undefined1 auStack_118 [4];
  undefined2 uStack_114;
  undefined2 uStack_110;
  undefined2 uStack_10c;
  undefined2 uStack_108;
  undefined2 uStack_104;
  undefined2 uStack_100;
  undefined2 uStack_fc;
  undefined2 uStack_f8;
  int iStack_f4;
  undefined1 auStack_e4 [128];
  undefined2 uStack_64;
  undefined2 uStack_60;
  undefined2 uStack_5c;
  undefined2 uStack_58;
  undefined2 uStack_54;
  undefined2 uStack_50;
  undefined2 uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_44;
  undefined2 uStack_40;
  undefined2 uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_10;
  undefined2 uStack_c;
  undefined2 uStack_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_13c;
  _memset(param_2,0,0x40);
  _memset(param_2 + 0x20,0,0x84);
  if ((-1 < param_1) && (3 < param_1 - 10U)) {
    if (param_1 < 4) {
      iVar2 = *(int *)(param_1 * 0x17c + 0x4e34 + in_ECX);
      iVar5 = param_1 * 0x17c + in_ECX;
      *(undefined1 *)(iVar5 + 0x4e5d) = 0;
      if ((iVar2 == 6) && (iVar2 = XInputGetState(param_1,local_13c), iVar2 == 0)) {
        if (*(char *)(iVar5 + 0x4e61) == '\0') {
          iVar2 = XInputGetCapabilities(param_1,1,local_128);
          *(bool *)(iVar5 + 0x4e61) = iVar2 == 0;
          if (iVar2 == 0) {
            FUN_006d47a0(local_128,iVar5 + 0x4e34);
          }
        }
        *(byte *)((int)param_2 + 0x47) = (byte)local_138 >> 4 & 1;
        bVar3 = (byte)local_138 >> 5 & 1;
        *(byte *)(param_2 + 0x23) = bVar3;
        *(byte *)(iVar5 + 0x4e5d) = bVar3;
        *(byte *)(param_2 + 0x60) = (byte)local_138 & 1;
        *(byte *)(param_2 + 0x61) = (byte)local_138 >> 1 & 1;
        *(byte *)((int)param_2 + 0xc1) = (byte)local_138 >> 3 & 1;
        *(byte *)((int)param_2 + 0xc3) = (byte)local_138 >> 2 & 1;
        *(byte *)((int)param_2 + 0x43) = (byte)(local_138 >> 0xf) & 1;
        *(byte *)((int)param_2 + 0x41) = (byte)(local_138 >> 0xd) & 1;
        *(byte *)(param_2 + 0x20) = (byte)(local_138 >> 0xc) & 1;
        *(byte *)((int)param_2 + 0x45) = (byte)(local_138 >> 9) & 1;
        *(byte *)(param_2 + 0x21) = (byte)(local_138 >> 0xe) & 1;
        *(byte *)(param_2 + 0x22) = local_138._1_1_ & 1;
        *(byte *)(param_2 + 0x24) = (byte)local_138 >> 6 & 1;
        *param_2 = local_134;
        *(byte *)((int)param_2 + 0x49) = (byte)local_138 >> 7;
        if (local_132 == -0x8000) {
          _local_132 = CONCAT22(uStack_130,0x8001);
        }
        param_2[1] = -(short)_local_132;
        param_2[3] = uStack_130;
        if (local_12e == -0x8000) {
          _local_12e = CONCAT22(uStack_12c,0x8001);
        }
        param_2[4] = -(short)_local_12e;
        param_2[7] = (ushort)local_138._3_1_ << 7;
        param_2[6] = (ushort)local_138._2_1_ << 7;
        FUN_006d4880(param_2,param_2 + 1);
        FUN_006d4880(param_2 + 3,param_2 + 4);
      }
    }
    else {
      iVar5 = in_ECX + param_1 * 0x17c;
      piVar1 = *(int **)(iVar5 + 0x4e38);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
        if (iVar2 < 0) {
          (**(code **)(*piVar1 + 0x1c))(piVar1);
        }
        else {
          iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,0x110,auStack_118);
          if (iVar2 == 0) {
            *param_2 = uStack_114;
            param_2[1] = uStack_110;
            param_2[3] = uStack_108;
            param_2[2] = uStack_10c;
            param_2[4] = uStack_104;
            param_2[6] = uStack_fc;
            param_2[5] = uStack_100;
            param_2[7] = uStack_f8;
            param_2[9] = uStack_60;
            param_2[8] = uStack_64;
            param_2[10] = uStack_5c;
            param_2[0xc] = uStack_54;
            param_2[0xb] = uStack_58;
            param_2[0xd] = uStack_50;
            param_2[0xf] = uStack_48;
            param_2[0xe] = uStack_4c;
            param_2[0x10] = uStack_44;
            param_2[0x12] = uStack_3c;
            param_2[0x11] = uStack_40;
            param_2[0x13] = uStack_38;
            param_2[0x15] = uStack_30;
            param_2[0x14] = uStack_34;
            param_2[0x16] = uStack_2c;
            param_2[0x18] = uStack_24;
            param_2[0x17] = uStack_28;
            param_2[0x19] = uStack_20;
            param_2[0x1b] = uStack_18;
            param_2[0x1a] = uStack_1c;
            param_2[0x1c] = uStack_14;
            param_2[0x1e] = uStack_c;
            param_2[0x1d] = uStack_10;
            param_2[0x1f] = uStack_8;
            FUN_004ef660(param_2 + 0x20,auStack_e4,(int)*(short *)(iVar5 + 0x4e4c));
            if (iStack_f4 < 0) {
              *(undefined1 *)((int)param_2 + 0xc3) = 0;
              *(undefined1 *)(param_2 + 0x61) = 0;
              *(undefined1 *)((int)param_2 + 0xc1) = 0;
              *(undefined1 *)(param_2 + 0x60) = 0;
            }
            else {
              iVar4 = iStack_f4 / 0x1194 + (iStack_f4 >> 0x1f);
              iVar5 = -(iStack_f4 >> 0x1f);
              iVar2 = iVar5 + iVar4;
              *(byte *)(param_2 + 0x60) = (&DAT_00825ef8)[iVar4 + iVar5] & 1;
              *(byte *)((int)param_2 + 0xc1) = (byte)(&DAT_00825ef8)[iVar2] >> 1 & 1;
              *(byte *)(param_2 + 0x61) = (byte)(&DAT_00825ef8)[iVar2] >> 2 & 1;
              *(byte *)((int)param_2 + 0xc3) = (byte)(&DAT_00825ef8)[iVar2] >> 3 & 1;
            }
          }
        }
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_13c);
  return;
}

