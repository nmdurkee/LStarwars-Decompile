/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d7d80; label: FUN_006d7d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d7d80(int param_1,undefined1 *param_2,int param_3,int param_4,int param_5,int *param_6)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  ushort *puVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 auStack_40 [3];
  char local_3d;
  int local_3c;
  uint local_38;
  char *local_34;
  int local_30;
  float local_2c;
  int local_28;
  int local_24;
  undefined1 *local_20;
  int local_1c;
  short local_18 [10];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_40;
  local_20 = param_2;
  local_24 = *param_6;
  local_30 = param_5;
  local_38 = 0;
  local_1c = in_ECX;
  if (*(float *)(in_ECX + 0x6570) == 0.0) {
    local_3c = 0x8000;
  }
  else {
    FUN_004f3bb0();
    local_3c = FUN_006e6b90();
    if (local_3c == 0) {
      local_3c = 1;
    }
  }
  if (((9 < param_1) && (param_1 < 0xe)) && (*(char *)(in_ECX + 0x67e0) != '\0')) {
    local_3c = 0x8000;
  }
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  local_28 = 0;
  if (0 < *(int *)(in_ECX + 0x67e4)) {
    fVar9 = (float10)256.0;
    fVar10 = (float10)-256.0;
    fVar11 = (float10)1;
    local_34 = (char *)(in_ECX + 0x67f0);
    puVar8 = (ushort *)(param_1 * 0x17c + 0x4f22 + in_ECX);
    do {
      iVar6 = local_30;
      iVar7 = (int)(short)puVar8[-0x3f];
      bVar4 = true;
      local_3d = '\0';
      if (-1 < iVar7) {
        cVar2 = (char)puVar8[-0x40];
        switch(cVar2) {
        case '\x01':
          if (param_3 != 0) {
            local_3d = *(char *)(iVar7 + 0x40 + param_4);
          }
          break;
        case '\x02':
        case '\x03':
          if (param_3 != 0) {
            iVar6 = (int)*(short *)(param_4 + iVar7 * 2);
            if (cVar2 == '\x03') {
              iVar6 = -iVar6;
            }
            if (0x7fff < iVar6) {
              iVar6 = 0x7fff;
            }
            if ((*local_34 == '\x02') || (*local_34 == '\x03')) {
              *puVar8 = (iVar6 < 1) - 1 & (ushort)iVar6;
            }
            else {
              *puVar8 = (-1 < iVar6) - 1 & (ushort)iVar6;
            }
            uVar5 = (int)(short)*puVar8 >> 0x1f;
            local_3d = *(int *)(in_ECX + 0x6568) < (int)(((int)(short)*puVar8 ^ uVar5) - uVar5);
LAB_006d8130:
            bVar4 = false;
          }
          break;
        case '\x04':
          local_3d = *(char *)(local_30 + 0x38 + iVar7);
          break;
        case '\x05':
        case '\x06':
          if (param_3 != 0) {
            if ((&DAT_0297513c)[iVar7] == '\0') {
              fVar9 = fVar10;
              iVar6 = FUN_006e6b90();
              if (cVar2 == '\x06') {
                iVar6 = -iVar6;
              }
              local_3d = 0 < iVar6;
              iVar6 = iVar6 * 8;
              fVar11 = extraout_ST0;
              fVar10 = extraout_ST1;
LAB_006d7ed3:
              if (iVar6 < 0x8000) {
                if (iVar6 < -0x7fff) {
                  iVar6 = -0x7fff;
                }
              }
              else {
                iVar6 = 0x7fff;
              }
            }
            else {
              if ((&DAT_0297513c)[iVar7] == '\x02') {
                if (fVar9 < (float10)*(float *)(local_30 + 0xc + iVar7 * 4)) {
                  *(float *)(local_30 + 0xc + iVar7 * 4) = (float)fVar9;
                }
                if ((float10)*(float *)(local_30 + 0xc + iVar7 * 4) < fVar10) {
                  *(float *)(local_30 + 0xc + iVar7 * 4) = (float)fVar10;
                }
                uVar5 = FUN_006e6b90();
                if ((int)((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f)) < 5) {
                  fVar11 = (float10)FUN_004f3bb0();
                  *(float *)(&DAT_029755b8 + iVar7 * 4) =
                       (float)(fVar11 + (float10)*(float *)(&DAT_029755b8 + iVar7 * 4));
                  fVar9 = (float10)1;
                  fVar10 = (float10)-256.0;
                  fVar11 = (float10)0;
                }
                else {
                  *(float *)(&DAT_029755b8 + iVar7 * 4) = (float)fVar11;
                  fVar10 = extraout_ST0_00;
                }
                if (0.5 < *(float *)(&DAT_029755b8 + iVar7 * 4)) {
                  local_2c = *(float *)(iVar6 + 0xc + iVar7 * 4);
                  fVar12 = (float10)local_2c;
                  if (fVar12 != fVar11) {
                    if ((fVar12 <= fVar11) || ((float10)128.0 <= fVar12)) {
                      if ((fVar11 <= fVar12) || (fVar12 <= (float10)-128.0)) {
                        local_2c = (float)(fVar12 - (float10)0.0078125 * fVar12);
                        *(float *)(iVar6 + 0xc + iVar7 * 4) = local_2c;
                      }
                      else {
                        local_2c = (float)(fVar12 + fVar9);
                        *(float *)(iVar6 + 0xc + iVar7 * 4) = local_2c;
                      }
                    }
                    else {
                      local_2c = (float)(fVar12 - fVar9);
                      *(float *)(iVar6 + 0xc + iVar7 * 4) = local_2c;
                    }
                  }
                }
              }
              fVar9 = fVar10;
              iVar6 = FUN_006e6b90();
              if ((char)puVar8[-0x40] == '\x06') {
                iVar6 = -iVar6;
              }
              fVar11 = extraout_ST0_01;
              fVar10 = extraout_ST1_00;
              if (0x1f < iVar6) {
                iVar6 = iVar6 + -0x1f;
LAB_006d8033:
                iVar6 = (iVar6 * 0x7f00) / 0x60;
                goto LAB_006d7ed3;
              }
              if (iVar6 < -0x20) {
                iVar6 = iVar6 + 0x20;
                goto LAB_006d8033;
              }
              iVar6 = 0;
            }
            if ((*local_34 == '\x02') || (*local_34 == '\x03')) {
              *puVar8 = (iVar6 < 1) - 1 & (ushort)iVar6;
            }
            else {
              *puVar8 = (-1 < iVar6) - 1 & (ushort)iVar6;
            }
            goto LAB_006d8130;
          }
          break;
        case '\a':
          if ((*(char *)(in_ECX + 0x4e12) == '\0') || (iVar7 != 1)) {
            local_3d = *(char *)(iVar7 + local_24);
          }
        }
        bVar3 = local_34[2];
        if (-1 < (char)bVar3) {
          if (local_3d == '\0') {
            if (!bVar4) {
              piVar1 = (int *)(in_ECX + 0x6568);
              if (*piVar1 < (int)(short)*puVar8) {
                local_38 = local_38 | 1 << (bVar3 & 0x1f);
                in_ECX = local_1c;
              }
              if ((int)(short)*puVar8 < -*piVar1) {
                local_38 = local_38 | 1 << (bVar3 & 0x1f);
              }
            }
          }
          else {
            local_38 = local_38 | 1 << (bVar3 & 0x1f);
          }
        }
      }
      if (-1 < local_34[1]) {
        if (bVar4) {
          if (local_3d == '\0') {
            iVar6 = (int)(short)*puVar8;
            if (iVar6 < 0) {
              iVar6 = iVar6 + local_3c;
              if (0 < iVar6) {
LAB_006d81e8:
                iVar6 = 0;
              }
            }
            else {
              iVar6 = iVar6 - local_3c;
              if (iVar6 < 0) goto LAB_006d81e8;
            }
          }
          else if ((*local_34 == '\x02') || (*local_34 == '\x03')) {
            iVar6 = (short)*puVar8 + local_3c;
            if (0x7fff < iVar6) {
              iVar6 = 0x7fff;
            }
          }
          else {
            iVar6 = (short)*puVar8 - local_3c;
            if (iVar6 < -0x8000) {
              iVar6 = -0x8000;
            }
          }
          *puVar8 = (ushort)iVar6;
        }
        local_18[local_34[1]] = local_18[local_34[1]] + *puVar8;
      }
      local_28 = local_28 + 1;
      local_34 = local_34 + 6;
      puVar8 = puVar8 + 2;
    } while (local_28 < *(int *)(in_ECX + 0x67e4));
  }
  local_20[1] = (char)((uint)(CONCAT22(local_18[2],local_18[1]) + 0x8000) >> 8);
  *local_20 = (char)((uint)(CONCAT22(local_18[1],local_18[0]) + 0x8000) >> 8);
  local_20[3] = (char)((uint)(CONCAT22(local_18[4],local_18[3]) + 0x8000) >> 8);
  local_20[2] = (char)((uint)(CONCAT22(local_18[3],local_18[2]) + 0x8000) >> 8);
  local_20[5] = (char)(CONCAT22(local_18[6],local_18[5]) >> 7);
  local_20[4] = (char)(CONCAT22(local_18[5],local_18[4]) >> 7);
  local_20[7] = (char)(CONCAT22(local_18[8],local_18[7]) >> 7);
  local_20[6] = (char)(CONCAT22(local_18[7],local_18[6]) >> 7);
  *(uint *)(local_20 + 8) = local_38;
  __security_check_cookie(local_4 ^ (uint)auStack_40);
  return;
}

