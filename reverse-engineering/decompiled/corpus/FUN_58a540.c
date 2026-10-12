/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58a540; label: FUN_0058a540
 */

void FUN_0058a540(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  int local_38;
  uint local_34 [6];
  undefined4 local_1c;
  byte local_18;
  byte local_16;
  byte local_15;
  undefined2 auStack_14 [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_38;
  iVar2 = FUN_004fc860(param_1);
  if (iVar2 == 0) {
    FUN_0058a510(param_1);
  }
  else {
    _memset(local_34,0,0x30);
    local_16 = local_16 | 1;
    local_34[0] = *param_2 + 3 & 0xfffffffc;
    *param_2 = local_34[0];
    local_1c = param_4;
    if (local_18 < 0x14) {
      puVar6 = (ushort *)(local_34[0] + 0x10);
      do {
        iVar3 = FUN_004fc5b0(iVar2);
        if (iVar3 == 0) break;
        FUN_004f7fb0(iVar2);
        iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"party");
        if (iVar3 == 0) {
          while ((local_15 < 8 && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0))) {
            local_38 = FUN_0055b1c0(*(undefined4 *)(iVar2 + 0x510));
            if (local_38 != -1) {
              auStack_14[local_15] = (short)local_38;
              local_15 = local_15 + 1;
            }
          }
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"pickups");
          if (iVar3 == 0) {
            iVar3 = FUN_004f7fb0(iVar2);
            if (iVar3 != 0) {
              iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_007622ac);
              if (iVar3 == 0) {
                local_16 = local_16 | 1;
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_00758e24);
                if (iVar3 == 0) {
                  local_16 = local_16 & 0xfe;
                }
              }
            }
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"mission");
            if (iVar3 == 0) {
              puVar6[-8] = 0xffff;
              puVar6[-7] = 0xffff;
              puVar6[-6] = 0xffff;
              puVar6[-0xffffffff00000004] = 0x86a0;
              puVar6[-0xffffffff00000003] = 1;
              puVar6[-0xffffffff00000002] = 0x86a0;
              puVar6[-0xffffffff00000001] = 1;
              puVar6[-5] = 0xffff;
              *puVar6 = 0xb4;
              *(byte *)(puVar6 + 1) = local_18;
              iVar3 = FUN_004f7fb0(iVar2);
              while (iVar3 != 0) {
                iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_00763670);
                if (iVar3 == 0) {
                  iVar3 = FUN_004f7fb0(iVar2);
                  if (iVar3 != 0) {
                    uVar1 = FUN_0055b1c0(*(undefined4 *)(iVar2 + 0x510));
                    puVar6[-8] = uVar1;
                  }
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"in_level");
                  if (iVar3 == 0) {
                    iVar3 = FUN_004f7fb0(iVar2);
                    if ((iVar3 != 0) &&
                       (iVar3 = FUN_00578da0(*(undefined4 *)(iVar2 + 0x510),&local_38), iVar3 != 0))
                    {
                      puVar6[-7] = (ushort)local_38;
                    }
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_00757ca8);
                    if (iVar3 == 0) {
                      uVar1 = FUN_004f9e70(iVar2);
                      *puVar6 = uVar1;
                      if (uVar1 < 3) {
                        *puVar6 = 3;
                      }
                    }
                    else {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"bounty");
                      if (iVar3 == 0) {
                        uVar4 = FUN_004f9e70(iVar2);
                        *(undefined4 *)(puVar6 + -4) = uVar4;
                        uVar4 = FUN_004f9e70(iVar2);
                        *(undefined4 *)(puVar6 + -2) = uVar4;
                      }
                      else {
                        iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"name_id");
                        if (iVar3 == 0) {
                          uVar1 = FUN_004f9e70(iVar2);
                          puVar6[-6] = uVar1;
                        }
                        else {
                          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"text_id");
                          if (iVar3 == 0) {
                            uVar1 = FUN_004f9e70(iVar2);
                            puVar6[-5] = uVar1;
                          }
                        }
                      }
                    }
                  }
                }
                iVar3 = FUN_004f7fb0(iVar2);
              }
              if ((puVar6[-8] != 0xffff) && (puVar6[-7] != 0xffff)) {
                local_18 = local_18 + 1;
                puVar6 = puVar6 + 0xc;
                *param_2 = *param_2 + 0x18;
              }
            }
          }
        }
      } while (local_18 < 0x14);
    }
    FUN_004fa300(iVar2);
    if (local_18 != 0) {
      uVar5 = *param_2 + 3 & 0xfffffffc;
      *param_2 = uVar5;
      FUN_004ef660(uVar5,local_34,0x30);
      *param_2 = *param_2 + 0x33 & 0xfffffffc;
      __security_check_cookie(local_4 ^ (uint)&local_38);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_38);
  return;
}

