/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524900; label: FUN_00524900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00524900(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *local_2004;
  int local_2000;
  int local_1ffc;
  int local_1ff8;
  undefined4 local_1ff4;
  undefined4 local_1ff0;
  undefined4 local_1fec;
  undefined4 local_1fe8;
  byte local_1fe4 [8160];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2004;
  local_1ff4 = param_1;
  local_1ff8 = param_3;
  local_1fe4[0] = 0;
  local_1fe4[1] = 0;
  local_1fe4[2] = 0;
  local_1fe4[3] = 0;
  local_1fe4[4] = 0;
  local_1fe4[5] = 0;
  local_1fe4[6] = 0;
  local_1fe4[7] = 0;
  local_1fe4[8] = 0;
  local_1fe4[9] = 0;
  local_1fe4[10] = 0;
  local_1fe4[0xb] = 0;
  local_1fe4[0xc] = 0;
  local_1fe4[0xd] = 0;
  local_1fe4[0xe] = 0;
  local_1fe4[0xf] = 0;
  local_1fe4[0x10] = 0;
  local_1fe4[0x11] = 0;
  local_1fe4[0x12] = 0;
  local_1fe4[0x13] = 0;
  local_1fe4[0x14] = 0;
  local_1fe4[0x15] = 0;
  local_1fe4[0x16] = 0;
  local_1fe4[0x17] = 0;
  local_1fe4[0x18] = 0;
  local_1fe4[0x19] = 0;
  local_1fe4[0x1a] = 0;
  local_1fe4[0x1b] = 0;
  local_1fe4[0x1c] = 0;
  local_1fe4[0x1d] = 0;
  local_1fe4[0x1e] = 0;
  local_1fe4[0x1f] = 0;
  _memset(local_1fe4 + 0x20,0,0x1fc0);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  if ((param_3 != 0) && (local_2000 = FUN_004f1440(param_3 + 0x18), local_2000 != 0)) {
    do {
      uVar5 = (uint)*(short *)(local_2000 + 0x90);
      local_2004 = (int *)(local_2000 + 0x30);
      local_1ffc = 8;
      do {
        iVar2 = local_2000;
        if (*local_2004 != 0) {
          uVar6 = (uint)*(short *)(*local_2004 + 0x90);
          bVar1 = local_1fe4[((int)(uVar6 + ((int)uVar6 >> 0x1f & 7U)) >> 3) + uVar5 * 0x20];
          uVar4 = uVar6 & 0x80000007;
          if ((int)uVar4 < 0) {
            uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
          }
          if ((bVar1 & (byte)(1 << ((byte)uVar4 & 0x1f))) == 0) {
            local_1fe4[((int)(uVar6 + ((int)uVar6 >> 0x1f & 7U)) >> 3) + uVar5 * 0x20] =
                 '\x01' << ((byte)uVar4 & 0x1f) | bVar1;
            uVar4 = uVar5 & 0x80000007;
            if ((int)uVar4 < 0) {
              uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
            }
            local_1fe4[uVar6 * 0x20 + ((int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3)] =
                 local_1fe4[uVar6 * 0x20 + ((int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3)] |
                 '\x01' << ((byte)uVar4 & 0x1f);
            iVar3 = FUN_005245c0(*local_2004,&local_1fe8,&local_1ff0,param_4);
            if (iVar3 != 0) {
              param_2[4] = local_1fe8;
              param_2[5] = local_1ff0;
              *param_2 = 1;
              param_2[1] = local_1ff8;
              param_2[6] = local_1fec;
              param_2[2] = iVar2;
              param_2[3] = *local_2004;
            }
          }
        }
        local_2004 = local_2004 + 3;
        local_1ffc = local_1ffc + -1;
      } while (local_1ffc != 0);
      local_2000 = FUN_004f1460(local_1ff8 + 0x18,local_2000);
    } while (local_2000 != 0);
    local_2000 = 0;
  }
  __security_check_cookie(local_4 ^ (uint)&local_2004);
  return;
}

