/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54b0b0; label: FUN_0054b0b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054b0b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  uint local_18;
  int local_14;
  int *local_10;
  int aiStack_8 [2];
  
  iVar4 = 0;
  if (param_1 == 0) {
    param_1 = FUN_0055f450();
  }
  iVar5 = 0;
  do {
    iVar1 = FUN_0054ae40(iVar5);
    aiStack_8[iVar5] = iVar1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  uVar2 = FUN_004f48e0(0);
  iVar5 = FUN_006d67a0(uVar2);
  local_18 = (uint)(iVar5 != 0);
  uVar2 = FUN_004f48e0(1);
  iVar5 = FUN_006d67a0(uVar2);
  if (iVar5 != 0) {
    local_18 = local_18 | 2;
  }
  local_14 = FUN_00427ec0();
  local_10 = &DAT_009253b0;
  do {
    iVar5 = *local_10;
    iVar1 = (&DAT_0093d7f0)[iVar4];
    if ((DAT_00926bd4 == (code *)0x0) || (iVar3 = (*DAT_00926bd4)(), iVar3 == 0)) {
      if ((aiStack_8[iVar4] == 0) || (aiStack_8[iVar4] == 1)) {
        if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) && (DAT_00855de0 == 0)) {
          FUN_0054ad40(iVar4,param_1);
        }
      }
      else if ((local_14 == 0) &&
              ((iVar1 == 0 ||
               (((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0 &&
                ((DAT_00802824 == -1 || (*(char *)(iVar1 + 0x7b5) != DAT_00802824)))))))) {
        if ((*(uint *)(iVar5 + 0x78) & DAT_00802274) == 0) {
          iVar5 = FUN_00574e20();
          if (iVar5 == -1) {
            iVar5 = FUN_006d6c40(1);
            if (local_18 == 0) {
              if ((((iVar5 != 0) || (iVar5 = FUN_006d6c40(0xe), iVar5 != 0)) ||
                  (iVar5 = FUN_006d6c40(0xc5), iVar5 != 0)) && ((&DAT_0093d7f0)[iVar4] != 0)) {
                bVar6 = (*(byte *)((&DAT_0093d7f0)[iVar4] + 0x1fc) & 0x80) == 0;
                goto LAB_0054b21f;
              }
            }
            else if (iVar5 != 0) {
              if (local_18 == 3) {
                _DAT_0087b718 = 1;
                goto LAB_0054b225;
              }
              bVar6 = (local_18 & 1 << ((byte)iVar4 & 0x1f)) == 0;
LAB_0054b21f:
              if (!bVar6) goto LAB_0054b225;
            }
          }
        }
        else {
LAB_0054b225:
          if (((((iVar1 != 0) && (DAT_0087658c == 0)) && (DAT_00951b80 == 0)) &&
              ((_DAT_00950780 == 0.0 && (DAT_0087b4d8 == 0)))) &&
             ((0.0 < _DAT_0092505c &&
              ((param_1 != 0 && (*(int *)(param_1 + 0x128) != DAT_00951b88)))))) {
            if (DAT_0093b328 == 0) {
              if (((&DAT_00921454)[DAT_00800944 * 0x70] == -1) && (DAT_00951c58 == 0)) {
                if (((DAT_00951be0 == 0) || (iVar5 = FUN_0057cf70(DAT_00951be8), iVar5 != 0)) &&
                   ((((DAT_00855de0 == 0 && (DAT_00921dec == 0)) && (_DAT_00921df4 <= 0.0)) &&
                    ((_DAT_00921df0 <= 0.0 && (DAT_00925068 != 0)))))) {
                  FUN_0055c120((*(int *)(iVar1 + 0xca4) + -0x9253b0) / 0x60);
                  local_14 = 1;
                  goto LAB_0054b3a2;
                }
                if (DAT_0093b328 != 0) goto LAB_0054b35c;
              }
              if (DAT_0093b32c == 0) goto LAB_0054b3a2;
            }
LAB_0054b35c:
            if ((DAT_00802af8 == -1) || (iVar4 == DAT_00802af8)) {
              FUN_0055c560(1);
              FUN_0055c600();
            }
          }
        }
      }
    }
LAB_0054b3a2:
    local_10 = local_10 + 0x18;
    iVar4 = iVar4 + 1;
    if (0x92546f < (int)local_10) {
      return;
    }
  } while( true );
}

