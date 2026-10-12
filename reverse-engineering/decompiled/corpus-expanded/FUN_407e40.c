/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x407e40; label: FUN_00407e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00407e40(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0055f450();
  if (param_1 == 0) {
    return param_2;
  }
  if (((DAT_00876580 != 0) && (*(int *)(param_1 + 0x7f4) != 0)) &&
     (cVar1 = *(char *)(*(int *)(param_1 + 0x7f4) + 9), cVar1 != -1)) {
    return (int)cVar1;
  }
  iVar3 = (int)*(short *)(param_1 + 0x1064);
  if (iVar3 == DAT_007f1ab8) {
    return 0x2b;
  }
  if (iVar3 == DAT_007f19a4) {
    iVar3 = (uint)(*(char *)(param_1 + 0xe3a) != '\0') * 2 + 7;
    if ((iVar3 == 7) && (*(int *)(iVar2 + 0x128) == DAT_0087b210)) {
      return 8;
    }
  }
  else {
    if ((iVar3 != DAT_007f1a9c) && (iVar3 != DAT_007f1aa0)) {
      if ((iVar3 != DAT_007f1b34) && ((iVar3 != DAT_007f1b38 && (iVar3 != DAT_007f1b3c)))) {
        if (iVar3 == DAT_007f1aa4) {
          return 0x14;
        }
        if ((iVar3 == DAT_007f1a1c) || (iVar3 == DAT_007f195c)) {
          return 6;
        }
        if ((iVar3 == DAT_007f1948) || (iVar3 == DAT_007f19a8)) {
          return 10;
        }
        if ((iVar3 != DAT_007f18b4) && (iVar3 != DAT_007f1a24)) {
          if ((iVar3 == DAT_007f1970) ||
             ((((iVar3 == DAT_007f1a28 || (iVar3 == DAT_007f196c)) || (iVar3 == DAT_007f1964)) ||
              (iVar3 == DAT_007f1a2c)))) {
            if (iVar2 != 0) {
              if (*(int *)(iVar2 + 0x128) == DAT_0087b1d4) {
                return 0xd;
              }
              if (*(int *)(iVar2 + 0x128) == DAT_0087b0f8) {
                return 0xe;
              }
            }
            return 0xc;
          }
          if (((((iVar3 == DAT_007f1b00) || (iVar3 == DAT_007f1ad8)) ||
               ((iVar3 == DAT_007f1b04 || ((iVar3 == DAT_007f1adc || (iVar3 == DAT_007f1aec)))))) ||
              (iVar3 == DAT_007f1b08)) ||
             (((iVar3 == DAT_007f1b0c || (iVar3 == DAT_007f1ae4)) || (iVar3 == DAT_007f1ae0)))) {
            return 0x17;
          }
          if (iVar3 == DAT_007f1af0) {
            return (*(char *)(param_1 + 0xe3a) != '\0') + 0x15;
          }
          if ((iVar3 == DAT_007f19e4) || (iVar3 == DAT_007f19e8)) {
            if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
               ((*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af84 &&
                (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x12de) != '\0')))) {
              return 0x20;
            }
            return 0x21;
          }
          if (((iVar3 == DAT_007f17d0) || (iVar3 == DAT_007f17d4)) || (iVar3 == DAT_007f1aac)) {
            if (*(char *)(DAT_007f0e98 * 0x10 + 0xe + *(int *)(PTR_DAT_00802c54 + 0x2ac0)) == '\0')
            {
              return 0;
            }
            return 0x2a;
          }
          if (iVar3 == DAT_007f192c) {
            return 0x1d;
          }
          if (*(code **)(*(int *)(param_1 + 0x54) + 0x18) != FUN_004b30e0) {
            iVar2 = DAT_0093b284 + iVar3 * 0x120;
            if ((*(char *)(iVar2 + 0x116) == '\b') || (*(short *)(iVar2 + 0xec) == 0x16)) {
              return 2;
            }
            if (iVar3 != DAT_007f1950) {
              if ((iVar3 == DAT_007f1908) || (iVar3 == DAT_007f190c)) {
                return 0x1a;
              }
              if (iVar3 == DAT_007f1910) {
                return 3;
              }
              if (iVar3 == DAT_007f1914) {
                return 0x18;
              }
              if ((iVar3 == DAT_007f18f4) || (iVar3 == DAT_007f1920)) {
                return 4;
              }
              if (iVar3 == DAT_007f18f8) {
                return 0x19;
              }
              if ((iVar3 != DAT_007f1900) && (iVar3 != DAT_007f1acc)) {
                if (iVar3 == DAT_007f19b8) {
                  return 0;
                }
                if (iVar3 == DAT_007f19bc) {
                  return 0;
                }
                if (iVar3 == DAT_007f1924) {
                  iVar2 = FUN_0056e160(0x29);
                  return (-(uint)(iVar2 != 0) & 3) + 0x1b;
                }
                if (iVar3 != DAT_007f1928) {
                  if ((iVar3 == DAT_007f19f8) || (iVar3 == DAT_007f19fc)) {
                    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0dc) {
                      return 0x23;
                    }
                    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0e0) {
                      return 0x24;
                    }
                  }
                  else if ((iVar3 == DAT_007f1a00) || (iVar3 == DAT_007f1a04)) {
                    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0d4) {
                      return 0x25;
                    }
                    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0d8) {
                      return 0x26;
                    }
                  }
                  else {
                    if (iVar3 == DAT_007f1a34) {
                      return 0;
                    }
                    if (iVar3 == DAT_007f1a38) {
                      return 0;
                    }
                  }
                  return param_2;
                }
                iVar2 = FUN_0056e160(0x29);
                return (-(uint)(iVar2 != 0) & 3) + 0x1c;
              }
              return 0x11;
            }
          }
          return 0x14;
        }
      }
      return 0xb;
    }
    iVar3 = 0x22;
  }
  return iVar3;
}

