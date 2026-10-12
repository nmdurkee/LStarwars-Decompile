/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e4840; label: FUN_005e4840
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e4840(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int local_2c;
  uint local_24;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  float local_c;
  float local_8;
  float local_4;
  
  bVar4 = false;
  _DAT_00971878 = 0;
  local_24 = 0xffffffff;
  local_2c = 1;
  local_14 = 0;
  if (0 < DAT_00973fe8) {
    pbVar7 = &DAT_00966717;
    do {
      iVar6 = 0;
      uVar5 = (uint)*pbVar7;
      if (uVar5 == local_24) {
        if (bVar4) goto LAB_005e49e5;
      }
      else {
        local_18 = 0x4b189680;
        local_1c = 0xcb189680;
        fVar1 = *(float *)(pbVar7 + -0xb);
        fVar3 = (*(float *)(pbVar7 + -0x2f) - DAT_00973720) *
                (*(float *)(pbVar7 + -0x2f) - DAT_00973720) +
                (*(float *)(pbVar7 + -0x37) - DAT_00973718) *
                (*(float *)(pbVar7 + -0x37) - DAT_00973718) +
                (*(float *)(pbVar7 + -0x33) - DAT_0097371c) *
                (*(float *)(pbVar7 + -0x33) - DAT_0097371c);
        local_24 = uVar5;
        if (fVar3 < *(float *)(pbVar7 + -7) * *(float *)(pbVar7 + -7)) {
          bVar4 = true;
          fVar2 = *(float *)(pbVar7 + -0x1b);
          if (NAN(fVar2) || 65536.0 < fVar2 == (fVar2 == 65536.0)) {
            local_c = *(float *)(pbVar7 + -0x1b);
            local_8 = *(float *)(pbVar7 + -0x17);
            local_4 = *(float *)(pbVar7 + -0x13);
            if (local_2c != 1) {
              local_2c = 1;
            }
            FUN_005e4740(&local_c);
            local_c = local_c * 4.0;
            local_8 = local_8 * 4.0;
            local_4 = local_4 * 4.0;
          }
          else {
            local_c = 0.0;
            local_8 = -1.0;
            local_4 = 0.0;
            FUN_005e4740(&local_c);
            local_8 = -4.0;
            if ((local_2c != 5) && (*(float *)(pbVar7 + -0x13) == 0.0)) {
              local_2c = 5;
            }
            local_18 = *(undefined4 *)(pbVar7 + -0x17);
            local_1c = *(undefined4 *)(pbVar7 + -0x13);
          }
          if (fVar1 * fVar1 < fVar3) {
            FUN_005c0240(fVar3);
          }
LAB_005e49e5:
          if ((*(int *)(pbVar7 + -0x23) != 0) && (pbVar7[-2] != 0)) {
            iVar8 = 0;
            do {
              FUN_005e2920(*(int *)(pbVar7 + -0x23) + iVar8,pbVar7 + -0x67,&local_c);
              iVar6 = iVar6 + 1;
              iVar8 = iVar8 + 0x40;
            } while (iVar6 < (int)(uint)pbVar7[-2]);
          }
          if ((*(int *)(pbVar7 + -0x27) != 0) && (iVar6 = 0, pbVar7[-3] != 0)) {
            iVar8 = 0;
            do {
              FUN_005e3b50(*(int *)(pbVar7 + -0x27) + iVar8,pbVar7 + -0x67,&local_c,local_18,
                           local_1c);
              iVar6 = iVar6 + 1;
              iVar8 = iVar8 + 0x30;
            } while (iVar6 < (int)(uint)pbVar7[-3]);
          }
          if ((*(int *)(pbVar7 + -0x1f) != 0) && (iVar6 = 0, pbVar7[-1] != 0)) {
            do {
              FUN_005e4280(pbVar7 + -0x67,**(undefined4 **)(pbVar7 + -0x1f),
                           (*(undefined4 **)(pbVar7 + -0x1f))[1],&local_c);
              iVar6 = iVar6 + 1;
            } while (iVar6 < (int)(uint)pbVar7[-1]);
          }
        }
        else {
          bVar4 = false;
        }
      }
      local_14 = local_14 + 1;
      pbVar7 = pbVar7 + 0x68;
    } while (local_14 < DAT_00973fe8);
  }
  return;
}

