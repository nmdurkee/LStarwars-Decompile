/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f4b90; label: FUN_005f4b90
 */

void FUN_005f4b90(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  byte local_22;
  char local_21;
  float local_20;
  int local_1c;
  float local_18;
  int local_14;
  int local_10;
  int local_c;
  float local_8;
  float local_4;
  
  local_1c = *(int *)(param_1 + 0x50);
  local_20 = 0.0;
  local_10 = *(int *)(param_1 + 0x110);
  if (*(int *)(param_1 + 0x54) != 0) {
    iVar5 = *(int *)(param_1 + 0x4c);
    if ((*(int *)(param_1 + 0x1e0) != 0) && (*(int *)(*(int *)(param_1 + 0x1e0) + -4) < 2)) {
      *(undefined4 *)(param_1 + 0x1e0) = 0;
    }
    local_c = 0;
    if (0 < *(short *)(param_1 + 0x48)) {
      do {
        if ((int)(uint)*(ushort *)(iVar5 + 0x5c) < (int)*(short *)(param_1 + 0x4a)) {
          iVar6 = (uint)*(ushort *)(iVar5 + 0x5e) * 0xd0 + *(int *)(local_10 + 0x70);
          local_14 = 0;
          uVar3 = *(uint *)(iVar5 + 0x50);
          if ((uVar3 >> 0x16 == 0) || (*(int *)(param_1 + 0x1e0) == 0)) {
            if ((*(byte *)(iVar6 + 0xb8) & 2) == 0) goto LAB_005f4ecf;
          }
          else {
            local_14 = *(int *)(param_1 + 0x1e0) + -0xc + (uVar3 >> 0x16) * 0xc;
          }
          iVar4 = *(int *)(*(int *)(param_1 + 0x54) + (uint)*(ushort *)(iVar5 + 0x5c) * 4);
          if (iVar4 == 0) {
            if (local_14 == 0) goto LAB_005f4ecf;
            fVar7 = (float10)*(ushort *)(local_14 + 2);
          }
          else {
            fVar7 = (float10)FUN_005ca4b0(iVar4);
          }
          local_18 = (float)fVar7;
          if (local_18 != 0.0) {
            if ((uVar3 & 1) == 0) {
              local_20 = *(float *)(iVar5 + 0x4c);
            }
            else {
              local_8 = *(float *)(iVar5 + 0x40) * param_2 + *(float *)(iVar5 + 0x4c);
              *(float *)(iVar5 + 0x4c) = local_8;
              if (((uVar3 & 4) != 0) &&
                 (*(float *)(iVar5 + 0x44) < local_8 != (*(float *)(iVar5 + 0x44) == local_8))) {
                *(uint *)(iVar5 + 0x50) = uVar3 & 0xfffffffb;
                *(float *)(iVar5 + 0x4c) = local_8 - (*(float *)(iVar5 + 0x44) - 1.0);
              }
              uVar3 = *(uint *)(iVar5 + 0x50);
              local_4 = local_8;
              if ((uVar3 & 4) == 0) {
                fVar1 = *(float *)(iVar5 + 0x48) + local_18;
                local_20 = local_18;
                if (*(float *)(iVar5 + 0x4c) < fVar1) {
                  if (*(float *)(iVar5 + 0x4c) <= local_18) {
                    if (1.0 <= *(float *)(iVar5 + 0x4c)) {
                      local_20 = *(float *)(iVar5 + 0x4c);
                    }
                    else {
                      *(undefined4 *)(iVar5 + 0x4c) = 0x3f800000;
                      local_20 = 1.0;
                      *(uint *)(iVar5 + 0x50) = uVar3 & 0xfffffffe;
                    }
                  }
                }
                else if ((uVar3 & 8) == 0) {
                  *(uint *)(iVar5 + 0x50) = uVar3 & 0xfffffffe;
                  *(float *)(iVar5 + 0x4c) = local_18;
                }
                else {
                  local_20 = (*(float *)(iVar5 + 0x4c) - 1.0) / (fVar1 - 1.0);
                  fVar7 = (float10)FUN_005b7cc0(local_20);
                  local_4 = *(float *)(iVar5 + 0x4c) -
                            (float)fVar7 * ((local_18 + *(float *)(iVar5 + 0x48)) - 1.0);
                  *(float *)(iVar5 + 0x4c) = local_4;
                  local_20 = local_4;
                }
                uVar3 = *(uint *)(iVar5 + 0x50);
                if ((uVar3 & 2) != 0) {
                  local_20 = (local_18 + 1.0) - local_20;
                }
              }
            }
            if (*(float *)(iVar5 + 0x58) != local_20) {
              if (local_14 != 0) {
                local_22 = (byte)(uVar3 >> 0xe);
                iVar2 = FUN_005da480(local_14,&local_22,&local_21,local_20);
                *(uint *)(iVar5 + 0x50) = (uint)local_22 << 0xe | uVar3 & 0xffc03fff;
                if (iVar2 != 0) {
                  if (*(ushort *)(iVar5 + 0x5e) != 0xffff) {
                    iVar6 = (uint)*(ushort *)(iVar5 + 0x5e) * 0xd0 + *(int *)(local_10 + 0x70);
                    if (local_21 == '\0') {
                      *(uint *)(iVar6 + 0xb8) = *(uint *)(iVar6 + 0xb8) & 0xfffffffd;
                      *(float *)(iVar5 + 0x58) = local_20;
                      iVar4 = 0;
                      goto LAB_005f4ea1;
                    }
                    *(uint *)(iVar6 + 0xb8) = *(uint *)(iVar6 + 0xb8) | 2;
                  }
                  if (local_21 == '\0') {
                    iVar4 = 0;
                    *(float *)(iVar5 + 0x58) = local_20;
                    goto LAB_005f4ea1;
                  }
                }
              }
              if (iVar4 != 0) {
                FUN_005ea390(iVar4,0,local_20,local_1c);
              }
              *(float *)(iVar5 + 0x58) = local_20;
            }
LAB_005f4ea1:
            if (iVar4 != 0) {
              FUN_005c19d0();
              *(float *)(iVar5 + 0x30) = *(float *)(iVar6 + 0x70) + *(float *)(iVar5 + 0x30);
              *(float *)(iVar5 + 0x34) = *(float *)(iVar6 + 0x74) + *(float *)(iVar5 + 0x34);
              *(float *)(iVar5 + 0x38) = *(float *)(iVar6 + 0x78) + *(float *)(iVar5 + 0x38);
            }
          }
        }
LAB_005f4ecf:
        local_1c = local_1c + 0x40;
        local_c = local_c + 1;
        iVar5 = iVar5 + 0x60;
      } while (local_c < *(short *)(param_1 + 0x48));
    }
  }
  return;
}

