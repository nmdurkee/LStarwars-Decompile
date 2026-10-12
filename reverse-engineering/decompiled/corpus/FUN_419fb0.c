/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x419fb0; label: FUN_00419fb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00419fb0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_550 [340];
  
  iVar1 = FUN_00574e20();
  if (iVar1 == 0xd) {
    return;
  }
  if (iVar1 == 0xf) {
    return;
  }
  if (iVar1 == 0x10) {
    return;
  }
  if (iVar1 == 0x11) {
    return;
  }
  if (DAT_0087b51c != 0) {
    return;
  }
  if (DAT_007fac04 == 0) {
    return;
  }
  if (DAT_007f23a4 != -1) {
    return;
  }
  if (DAT_007f23a8 != -1) {
    return;
  }
  iVar1 = FUN_004feb90();
  if (iVar1 != 0) {
    return;
  }
  if (0xfd < DAT_009739b8) {
    return;
  }
  iVar1 = FUN_006e6b90();
  if (DAT_00924894 - DAT_00924890 < (int)(0x3ffU - iVar1 & 0xfffffc00)) {
    return;
  }
  iVar1 = 0;
  if ((((DAT_007f17d4 == -1) || (iVar2 = FUN_0062df80((int)DAT_007f17d4), iVar2 == 0)) ||
      (DAT_007f17c4 == -1)) || (iVar2 = FUN_0062df80((int)DAT_007f17c4), iVar2 != 0)) {
    if ((DAT_007f18fc == -1) || (iVar2 = FUN_0062df80((int)DAT_007f18fc), iVar2 != 0)) {
      if ((DAT_007f1a74 == -1) || (iVar2 = FUN_0062df80((int)DAT_007f1a74), iVar2 != 0)) {
        if ((DAT_007f18e4 != -1) && (iVar2 = FUN_0062df80((int)DAT_007f18e4), iVar2 == 0)) {
          local_550[0] = (int)DAT_007f18e4;
          goto LAB_0041a0a6;
        }
        if ((DAT_007f18e8 == -1) || (iVar2 = FUN_0062df80((int)DAT_007f18e8), iVar2 != 0)) {
          if ((DAT_007f1958 == -1) || (iVar2 = FUN_0062df80((int)DAT_007f1958), iVar2 != 0)) {
            if ((DAT_007f18d0 != -1) && (iVar2 = FUN_0062df80((int)DAT_007f18d0), iVar2 == 0)) {
              local_550[0] = (int)DAT_007f18d0;
              goto LAB_0041a0a6;
            }
            if ((DAT_007f18d4 == -1) || (iVar2 = FUN_0062df80((int)DAT_007f18d4), iVar2 != 0)) {
              if ((DAT_007f18c4 == -1) || (iVar2 = FUN_0062df80((int)DAT_007f18c4), iVar2 != 0)) {
                iVar2 = 0;
                if (DAT_0093b278 < 1) {
                  return;
                }
                iVar4 = 0;
                do {
                  if (((((iVar2 != DAT_007f1900) &&
                        ((*(uint *)(iVar4 + 4 + DAT_0093b274) & 0x4002000) == 0)) &&
                       (iVar3 = FUN_0062df80(iVar2), iVar3 == 0)) &&
                      (((int)((uint)*(ushort *)(iVar4 + 0x14 + DAT_0093b274) +
                             *(int *)(DAT_029130e4 + 0x2c)) <= *(int *)(DAT_029130e4 + 0x14) &&
                       (iVar3 = FUN_00594250(iVar2,0,0), iVar3 != -1)))) &&
                     (iVar3 = FUN_00594960(iVar2), iVar3 != 0)) {
                    local_550[iVar1] = iVar2;
                    iVar1 = iVar1 + 1;
                  }
                  iVar2 = iVar2 + 1;
                  iVar4 = iVar4 + 0x4c;
                } while (iVar2 < DAT_0093b278);
                if (iVar1 < 1) {
                  return;
                }
                if (1 < iVar1) {
                  iVar2 = FUN_0054fa60();
                  iVar2 = iVar2 / ((int)(0xffff / (longlong)iVar1) + 1);
                  goto LAB_0041a0ac;
                }
              }
              else {
                local_550[0] = (int)DAT_007f18c4;
              }
            }
            else {
              local_550[0] = (int)DAT_007f18d4;
            }
          }
          else {
            local_550[0] = (int)DAT_007f1958;
          }
        }
        else {
          local_550[0] = (int)DAT_007f18e8;
        }
      }
      else {
        local_550[0] = (int)DAT_007f1a74;
      }
    }
    else {
      local_550[0] = (int)DAT_007f18fc;
    }
  }
  else {
    local_550[0] = (int)DAT_007f17c4;
LAB_0041a0a6:
  }
  iVar2 = 0;
LAB_0041a0ac:
  DAT_007f23a4 = local_550[iVar2];
  _DAT_00855ecc = 0;
  FUN_004fecf0(FUN_00419e90,0,0,0);
  return;
}

