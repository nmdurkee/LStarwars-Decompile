/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41a5b0; label: FUN_0041a5b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0041a5b0(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *(int *)(*(int *)(param_2 + 0x54) + 0x24);
  bVar1 = *(byte *)(iVar5 + 0x11c);
  if (bVar1 == 0xff) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1 << (bVar1 & 0x1f);
  }
  bVar1 = *(byte *)(iVar5 + 0x115);
  if (bVar1 == 0xff) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1 << (bVar1 & 0x1f);
  }
  if (*(char *)(param_2 + 0x1082) != '\0') {
    param_1 = param_1 & ~uVar4;
  }
  iVar5 = *(int *)(param_2 + 0xcbc);
  if (iVar5 != 0) {
    if (*(short *)(param_2 + 0x1064) == DAT_007f17b8) {
      uVar2 = *(ushort *)(iVar5 + 0xc);
      if ((uVar2 & 4) == 0) {
        if ((uVar2 & 2) == 0) {
          if ((uVar2 & 8) == 0) {
            if ((uVar2 & 1) != 0) {
              param_1 = param_1 | _DAT_007f23d0;
              if ((param_1 & DAT_007f2418) == 0) {
                if ((param_1 & DAT_007f2424) == 0) {
                  if ((param_1 & DAT_007f2430) != 0) {
                    param_1 = ~DAT_007f2430 & param_1 | _DAT_007f2454;
                  }
                }
                else {
                  param_1 = ~DAT_007f2424 & param_1 | _DAT_007f2448;
                }
              }
              else {
                param_1 = ~DAT_007f2418 & param_1 | _DAT_007f243c;
              }
            }
          }
          else {
            uVar4 = (~uVar6 & param_1 | DAT_007f23c4 | _DAT_007f240c) & ~DAT_007f23dc |
                    _DAT_007f23e8;
            if ((uVar4 & DAT_007f24a8) == 0) {
              if ((uVar4 & DAT_007f24b4) != 0) {
                uVar4 = ~DAT_007f24b4 & uVar4 | _DAT_007f24cc;
              }
            }
            else {
              uVar4 = ~DAT_007f24a8 & uVar4 | _DAT_007f24c0;
            }
            param_1 = ~DAT_007f2484 & uVar4 | _DAT_007f2490;
            if ((param_1 & DAT_007f2418) == 0) {
              if ((param_1 & DAT_007f2424) == 0) {
                if ((param_1 & DAT_007f2430) != 0) {
                  param_1 = ~DAT_007f2430 & param_1 | _DAT_007f2478;
                }
              }
              else {
                param_1 = ~DAT_007f2424 & param_1 | _DAT_007f246c;
              }
            }
            else {
              param_1 = ~DAT_007f2418 & param_1 | _DAT_007f2460;
            }
          }
        }
        else {
          param_1 = param_1 & ~uVar6;
        }
      }
      else {
        uVar4 = (~uVar6 & param_1 | DAT_007f23b8) & ~DAT_007f23dc | _DAT_007f23f4;
        if ((uVar4 & DAT_007f24a8) == 0) {
          if ((uVar4 & DAT_007f24b4) != 0) {
            uVar4 = ~DAT_007f24b4 & uVar4 | _DAT_007f24e4;
          }
        }
        else {
          uVar4 = ~DAT_007f24a8 & uVar4 | _DAT_007f24d8;
        }
        param_1 = ~DAT_007f2484 & uVar4 | _DAT_007f249c;
      }
    }
    else if (*(short *)(param_2 + 0x1064) == DAT_007f180c) {
      uVar2 = *(ushort *)(iVar5 + 0xc);
      if ((uVar2 & 0x10) == 0) {
        if ((uVar2 & 0x40) == 0) {
          if ((uVar2 & 0x20) == 0) {
            if ((char)uVar2 < '\0') {
              param_1 = ~uVar6 & param_1 | _DAT_007f2514;
            }
          }
          else {
            param_1 = ~uVar6 & param_1 | _DAT_007f2508;
            if ((param_1 & DAT_007f2520) == 0) {
              if ((param_1 & DAT_007f252c) == 0) {
                if ((param_1 & DAT_007f2538) != 0) {
                  param_1 = ~DAT_007f2538 & param_1 | _DAT_007f255c;
                }
              }
              else {
                param_1 = ~DAT_007f252c & param_1 | _DAT_007f2550;
              }
            }
            else {
              param_1 = ~DAT_007f2520 & param_1 | _DAT_007f2544;
            }
          }
        }
        else {
          param_1 = ~uVar6 & param_1 | _DAT_007f24f0;
          if ((param_1 & DAT_007f2520) == 0) {
            if ((param_1 & DAT_007f252c) == 0) {
              if ((param_1 & DAT_007f2538) != 0) {
                param_1 = ~DAT_007f2538 & param_1 | _DAT_007f2580;
              }
            }
            else {
              param_1 = ~DAT_007f252c & param_1 | _DAT_007f2574;
            }
          }
          else {
            param_1 = ~DAT_007f2520 & param_1 | _DAT_007f2568;
          }
        }
      }
      else {
        param_1 = ~uVar4 & ~uVar6 & param_1 | _DAT_007f24fc;
        if ((param_1 & DAT_007f2520) == 0) {
          if ((param_1 & DAT_007f252c) == 0) {
            if ((param_1 & DAT_007f2538) != 0) {
              param_1 = ~DAT_007f2538 & param_1 | _DAT_007f25a4;
            }
          }
          else {
            param_1 = ~DAT_007f252c & param_1 | _DAT_007f2598;
          }
        }
        else {
          param_1 = ~DAT_007f2520 & param_1 | _DAT_007f258c;
        }
      }
    }
  }
  if (DAT_007f39e4 != 0) {
    sVar3 = *(short *)(param_2 + 0x1064);
    if (sVar3 == DAT_007f187c) {
      if (*(char *)(param_2 + 0x107f) < '\x02') {
        param_1 = param_1 & 0xffffffef;
      }
    }
    else if (sVar3 == DAT_007f18dc) {
      if ((*(uint *)(param_2 + 0xef0) & 0x200) == 0) {
        param_1 = param_1 | 0x40;
      }
      else {
        param_1 = param_1 | 0x20;
      }
    }
    else if ((DAT_00856980 == 0) ||
            ((uVar2 = DAT_0086e4f6, sVar3 != *(short *)(DAT_00856980 + 0x6c) &&
             (uVar2 = DAT_0086e52e, sVar3 != *(short *)(DAT_00856980 + 0x6e))))) {
      if ((sVar3 == DAT_007f18ec) && (iVar5 = FUN_0056e160(4), iVar5 != 0)) {
        param_1 = param_1 | 0xc0;
      }
    }
    else if ((*(byte *)(*(int *)(DAT_00856980 + 0x38) + 0x12 + (uint)uVar2 * 0x28) & 0x40) == 0) {
      param_1 = param_1 | uVar6;
    }
  }
  uVar6 = *(uint *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0xb0);
  if (((uVar6 != 0) && (*(int *)(param_2 + 0xcd0) != 0)) && (*(char *)(param_2 + 0x7b5) == ';')) {
    param_1 = param_1 & ~uVar6;
  }
  return param_1;
}

