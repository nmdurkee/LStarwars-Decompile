/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x674b30; label: FUN_00674b30
 */

undefined4 FUN_00674b30(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float10 fVar9;
  float local_44;
  int local_40;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20 [3];
  float local_14;
  float local_c;
  
  local_28 = 0;
  iVar7 = 0;
  if (DAT_02924ab8 == 0) {
    return 0;
  }
  local_40 = 0;
  iVar5 = DAT_0292186c;
  iVar6 = DAT_0292fb50;
  if (0 < DAT_02924ab8) {
    do {
      if ((ABS(*(float *)(iVar5 + 0x1c) - *(float *)(iVar7 + iVar6)) < 64.0) &&
         (ABS(*(float *)(iVar5 + 0x24) - *(float *)(iVar7 + 8 + iVar6)) < 64.0)) {
        local_2c = *(float *)(iVar7 + 0x18 + iVar6) - *(float *)(iVar7 + 8 + iVar6);
        local_24 = *(float *)(iVar7 + iVar6) - *(float *)(iVar7 + 0x10 + iVar6);
        FUN_005b3b30(&local_2c,&local_2c);
        iVar6 = DAT_0292fb50;
        iVar5 = DAT_0292186c;
        fVar1 = (local_24 *
                 ((*(float *)(DAT_0292186c + 0x30) + *(float *)(DAT_0292186c + 0x24)) -
                 *(float *)(iVar7 + 8 + DAT_0292fb50)) +
                local_2c *
                ((*(float *)(DAT_0292186c + 0x28) + *(float *)(DAT_0292186c + 0x1c)) -
                *(float *)(iVar7 + DAT_0292fb50))) - *(float *)(DAT_0292186c + 0x50);
        fVar2 = ((*(float *)(DAT_0292186c + 0x1c) - *(float *)(iVar7 + DAT_0292fb50)) * local_2c +
                (*(float *)(DAT_0292186c + 0x24) - *(float *)(iVar7 + 8 + DAT_0292fb50)) * local_24)
                - *(float *)(DAT_0292186c + 0x50);
        if (((fVar1 < 0.0) || (fVar2 < 0.0)) && (-*(float *)(DAT_0292186c + 0x50) < fVar2)) {
          local_20[0] = *(float *)(iVar7 + 0x10 + DAT_0292fb50) - *(float *)(iVar7 + DAT_0292fb50);
          local_20[2] = *(float *)(iVar7 + 0x18 + DAT_0292fb50) -
                        *(float *)(iVar7 + 8 + DAT_0292fb50);
          if (0.0 <= fVar2) {
            local_44 = fVar2 / (fVar2 - fVar1);
            local_14 = (*(float *)(DAT_0292186c + 0x1c) + local_44 * *(float *)(DAT_0292186c + 0x28)
                       ) - *(float *)(DAT_0292186c + 0x50) * local_2c;
            local_c = *(float *)(DAT_0292186c + 0x24) + *(float *)(DAT_0292186c + 0x30) * local_44;
            fVar1 = *(float *)(DAT_0292186c + 0x50);
          }
          else {
            local_14 = (*(float *)(DAT_0292186c + 0x1c) - fVar2 * local_2c) -
                       *(float *)(DAT_0292186c + 0x50) * local_2c;
            local_c = *(float *)(DAT_0292186c + 0x24) - fVar2 * local_24;
            fVar1 = *(float *)(DAT_0292186c + 0x50);
            local_44 = fVar2;
          }
          local_c = local_c - fVar1 * local_24;
          fVar1 = local_20[2] * (local_c - *(float *)(iVar7 + 8 + DAT_0292fb50)) +
                  local_20[0] * (local_14 - *(float *)(iVar7 + DAT_0292fb50));
          if (((!NAN(fVar1) && -5e-05 < fVar1 != (fVar1 == -5e-05)) &&
              (-5e-05 <= -local_20[0] * (local_14 - *(float *)(iVar7 + 0x10 + DAT_0292fb50)) -
                         (local_c - *(float *)(iVar7 + 0x18 + DAT_0292fb50)) * local_20[2])) &&
             (local_44 < *(float *)(DAT_0292186c + 0x98))) {
            if (fVar2 <= 0.0) {
              *(undefined1 *)(DAT_0292186c + 0x88) = 0x11;
            }
            else {
              *(undefined1 *)(DAT_0292186c + 0x88) = 1;
            }
            *(float *)(iVar5 + 0x98) = local_44;
            DAT_0292125e = 1;
            *(float *)(iVar5 + 0xa8) = local_2c;
            *(undefined4 *)(iVar5 + 0xac) = local_28;
            *(undefined2 *)(iVar5 + 0x6c) = 0xffff;
            *(float *)(iVar5 + 0xb0) = local_24;
            *(undefined1 *)(iVar5 + 0x35) = 4;
            *(undefined4 *)(iVar5 + 0x90) = 0;
            DAT_02924b40 = *(undefined1 *)(iVar7 + 0xc + iVar6);
            DAT_02924b41 = *(undefined1 *)(iVar7 + 0xd + iVar6);
          }
        }
        if (((ABS(*(float *)(iVar7 + iVar6) - *(float *)(iVar5 + 0x1c)) < 64.0) &&
            (ABS(*(float *)(iVar7 + 8 + iVar6) - *(float *)(iVar5 + 0x24)) < 64.0)) &&
           (fVar1 = *(float *)(iVar7 + 8 + iVar6) - *(float *)(iVar5 + 0x24),
           fVar2 = *(float *)(iVar7 + iVar6) - *(float *)(iVar5 + 0x1c),
           fVar3 = *(float *)(iVar5 + 0x50) + 0.005 + *(float *)(iVar5 + 0x3c),
           fVar2 * fVar2 + fVar1 * fVar1 < fVar3 * fVar3)) {
          local_20[0] = *(float *)(iVar5 + 0x28);
          local_20[1] = 0.0;
          local_20[2] = *(float *)(iVar5 + 0x30);
          FUN_005b3b30(local_20,local_20);
          pfVar8 = (float *)(iVar7 + 8 + DAT_0292fb50);
          fVar1 = local_20[0] * (*(float *)(iVar7 + DAT_0292fb50) - *(float *)(DAT_0292186c + 0x1c))
                  + local_20[2] * (*pfVar8 - *(float *)(DAT_0292186c + 0x24));
          if (fVar1 < 0.0) {
LAB_006750c5:
            fVar1 = *pfVar8 - *(float *)(DAT_0292186c + 0x24);
            fVar2 = *(float *)(iVar7 + DAT_0292fb50) - *(float *)(DAT_0292186c + 0x1c);
            fVar2 = fVar2 * fVar2 + fVar1 * fVar1;
            fVar1 = *(float *)(DAT_0292186c + 0x50);
LAB_00675107:
            fVar1 = (fVar1 + 0.0005) * (fVar1 + 0.0005);
            iVar5 = DAT_0292186c;
            iVar6 = DAT_0292fb50;
            if (fVar2 < fVar1 == (fVar2 == fVar1)) goto LAB_006751dc;
            local_2c = *(float *)(DAT_0292186c + 0x1c) - *(float *)(iVar7 + DAT_0292fb50);
            local_24 = *(float *)(DAT_0292186c + 0x24) - *pfVar8;
            FUN_005b3b30(&local_2c,&local_2c);
            *(undefined1 *)(DAT_0292186c + 0x88) = 0x11;
            fVar9 = (float10)FUN_005c0240(fVar2);
            fVar9 = (fVar9 - (float10)*(float *)(DAT_0292186c + 0x50)) -
                    (float10)0.0005000000237487257;
            iVar5 = DAT_0292186c;
          }
          else {
            local_14 = *(float *)(DAT_0292186c + 0x1c) + fVar1 * local_20[0];
            local_c = *(float *)(DAT_0292186c + 0x24) + fVar1 * local_20[2];
            fVar2 = *(float *)(DAT_0292186c + 0x50) + 0.0005;
            fVar3 = *(float *)(iVar7 + DAT_0292fb50) - local_14;
            if (fVar2 * fVar2 < fVar3 * fVar3 + (*pfVar8 - local_c) * (*pfVar8 - local_c)) {
              fVar1 = *pfVar8 - *(float *)(DAT_0292186c + 0x24);
              fVar2 = *(float *)(iVar7 + DAT_0292fb50) - *(float *)(DAT_0292186c + 0x1c);
              fVar2 = fVar2 * fVar2 + fVar1 * fVar1;
              fVar1 = *(float *)(DAT_0292186c + 0x50);
              goto LAB_00675107;
            }
            fVar2 = *(float *)(iVar7 + DAT_0292fb50) - local_14;
            fVar9 = (float10)FUN_005c0240((*(float *)(DAT_0292186c + 0x50) *
                                           *(float *)(DAT_0292186c + 0x50) - fVar2 * fVar2) -
                                          (*pfVar8 - local_c) * (*pfVar8 - local_c));
            fVar1 = (float)((float10)fVar1 - fVar9);
            if ((fVar1 < -0.0005) ||
               (*(float *)(DAT_0292186c + 0x28) * *(float *)(DAT_0292186c + 0x28) +
                *(float *)(DAT_0292186c + 0x30) * *(float *)(DAT_0292186c + 0x30) < fVar1 * fVar1))
            {
              pfVar8 = (float *)(iVar7 + 8 + DAT_0292fb50);
              goto LAB_006750c5;
            }
            fVar9 = (float10)FUN_005c0240(*(float *)(DAT_0292186c + 0x28) *
                                          *(float *)(DAT_0292186c + 0x28) +
                                          *(float *)(DAT_0292186c + 0x30) *
                                          *(float *)(DAT_0292186c + 0x30));
            fVar9 = (float10)FUN_0064fde0(fVar1,(float)fVar9);
            local_44 = (float)fVar9;
            if (local_44 < 0.0) {
              local_44 = 0.0;
            }
            iVar5 = DAT_0292186c;
            iVar6 = DAT_0292fb50;
            if (*(float *)(DAT_0292186c + 0x98) <= local_44) goto LAB_006751dc;
            local_2c = (fVar1 * local_20[0] + *(float *)(DAT_0292186c + 0x1c)) -
                       *(float *)(iVar7 + DAT_0292fb50);
            local_24 = (fVar1 * local_20[2] + *(float *)(DAT_0292186c + 0x24)) -
                       *(float *)(iVar7 + 8 + DAT_0292fb50);
            FUN_005b3b30(&local_2c,&local_2c);
            iVar5 = DAT_0292186c;
            fVar9 = (float10)local_44;
            *(undefined1 *)(DAT_0292186c + 0x88) = 1;
          }
          iVar6 = DAT_0292fb50;
          *(float *)(iVar5 + 0x98) = (float)fVar9;
          DAT_0292125e = 1;
          *(float *)(iVar5 + 0xa8) = local_2c;
          *(undefined4 *)(iVar5 + 0xac) = local_28;
          *(float *)(iVar5 + 0xb0) = local_24;
          *(undefined1 *)(iVar5 + 0x35) = 4;
          *(undefined2 *)(iVar5 + 0x6c) = 0xffff;
          *(undefined4 *)(iVar5 + 0x90) = 0;
          DAT_02924b40 = *(undefined1 *)(iVar7 + 0xc + iVar6);
          DAT_02924b41 = *(undefined1 *)(iVar7 + 0xd + iVar6);
        }
      }
LAB_006751dc:
      local_40 = local_40 + 2;
      iVar7 = iVar7 + 0x20;
    } while (local_40 < DAT_02924ab8);
  }
  *(undefined4 *)(iVar5 + 0x9c) = *(undefined4 *)(iVar5 + 0x98);
  if (0.0 <= *(float *)(iVar5 + 0x98)) {
    uVar4 = FUN_006e6b90();
    return uVar4;
  }
  *(undefined4 *)(iVar5 + 0x98) = 0;
  uVar4 = FUN_006e6b90();
  return uVar4;
}

