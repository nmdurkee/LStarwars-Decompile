/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x533100; label: FUN_00533100
 */

void FUN_00533100(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  int local_60;
  int local_5c;
  int local_58;
  float local_54;
  int aiStack_40 [16];
  
  iVar6 = 0;
  local_58 = 1;
  local_5c = 0;
  if ((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
     (iVar4 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20), iVar4 != 0)) {
    local_60 = *(int *)(iVar4 + 0xb0);
    iVar4 = FUN_004f1440(DAT_009238e4 + 0x4874);
    if (iVar4 != 0) {
      do {
        if (*(int *)(DAT_009238e4 + 0x4868) != iVar4) {
          if ((*(int *)(param_2 + 0xc) == 0) || (local_58 == *(int *)(param_2 + 0xc))) {
            local_54 = 3.4028235e+38;
            iVar6 = 0;
            iVar5 = FUN_004f1440(iVar4 + 0x18);
            if (iVar5 != 0) {
              do {
                iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
                fVar1 = *(float *)(iVar5 + 0x18) - *(float *)(iVar2 + 0x18);
                fVar3 = *(float *)(iVar5 + 0x20) - *(float *)(iVar2 + 0x20);
                fVar7 = (float10)FUN_005c0240(fVar1 * fVar1 + fVar3 * fVar3);
                fVar1 = (float)fVar7;
                if ((((fVar1 < *(float *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x24) +
                               *(float *)(iVar5 + 0x24)) &&
                     (iVar2 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20),
                     *(float *)(iVar2 + 0x28) + *(float *)(iVar2 + 0x1c) <=
                     *(float *)(iVar5 + 0x2c) + *(float *)(iVar5 + 0x1c))) &&
                    (*(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x1c) <=
                     *(float *)(iVar2 + 0x2c) + *(float *)(iVar2 + 0x1c))) && (fVar1 < local_54)) {
                  iVar6 = iVar5;
                  local_54 = fVar1;
                }
                iVar5 = FUN_004f1460(iVar4 + 0x18,iVar5);
              } while (iVar5 != 0);
              if ((iVar6 != 0) && (local_5c < 0x10)) {
                aiStack_40[local_5c] = iVar6;
                local_5c = local_5c + 1;
                if (local_60 == 0) {
                  local_60 = *(int *)(iVar6 + 0xb0);
                }
              }
            }
          }
          local_58 = local_58 + 1;
          iVar6 = local_5c;
        }
        iVar4 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar4);
      } while (iVar4 != 0);
      if (iVar6 != 0) {
        if ((*(int *)(param_2 + 0xc) == 0) || ((*(byte *)(param_2 + 0x11) & 1) != 0)) {
          if ((local_60 != 0) || (local_60 = FUN_00525b30(), local_60 != 0)) {
            if (*(int *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0xb0) == 0) {
              FUN_00525c80();
            }
            iVar4 = 0;
            if (0 < iVar6) {
              do {
                iVar6 = aiStack_40[iVar4];
                if ((*(int *)(iVar6 + 0xb0) != 0) && (*(int *)(iVar6 + 0xb0) != local_60)) {
                  FUN_00525c50();
                }
                if (*(int *)(iVar6 + 0xb0) != local_60) {
                  FUN_00525c80();
                }
                iVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
                *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar5 + 0x18);
                *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar5 + 0x1c);
                *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)(iVar5 + 0x20);
                iVar4 = iVar4 + 1;
                *(undefined4 *)(iVar6 + 0x24) =
                     *(undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x24);
                *(undefined4 *)(iVar6 + 0x28) =
                     *(undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x28);
                *(undefined4 *)(iVar6 + 0x2c) =
                     *(undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0x2c);
                iVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
                *(undefined4 *)(iVar6 + 0x98) = *(undefined4 *)(iVar5 + 0x98);
                *(undefined4 *)(iVar6 + 0x9c) = *(undefined4 *)(iVar5 + 0x9c);
                *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(iVar5 + 0xa0);
                iVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20);
                *(undefined4 *)(iVar6 + 0xa4) = *(undefined4 *)(iVar5 + 0xa4);
                *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(iVar5 + 0xa8);
                *(undefined4 *)(iVar6 + 0xac) = *(undefined4 *)(iVar5 + 0xac);
              } while (iVar4 < local_5c);
            }
          }
        }
        else if ((*(int *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0xb0) != 0) &&
                (iVar4 = 0, 0 < iVar6)) {
          do {
            if (*(int *)(aiStack_40[iVar4] + 0xb0) ==
                *(int *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0xb0)) {
              FUN_00525c50();
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < local_5c);
        }
      }
    }
  }
  if ((*(int *)(param_2 + 0xc) == 0) && (*(int *)(DAT_009238e4 + 4) != 0)) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}

