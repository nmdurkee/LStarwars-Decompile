/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x541e60; label: FUN_00541e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00541e60(int *param_1,float *param_2,int param_3,int param_4,int param_5,int param_6,int param_7
            ,float *param_8,float *param_9,float *param_10,float *param_11,float *param_12,
            float *param_13,float *param_14)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  float fVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  float10 fVar16;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  int local_58;
  float local_54 [6];
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  float local_c;
  float local_4;
  
  local_a8 = 0.0;
  local_a4 = 0.0;
  local_a0 = 0.0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  local_5c = 0.0;
  local_60 = 0.0;
  local_64 = 0.0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  if (0 < param_6) {
    iVar13 = param_4 - param_5;
    iVar12 = param_6;
    do {
      FUN_005b37d0(&local_64,&local_64,iVar13 + param_5);
      FUN_005b37d0(&local_1c,&local_1c,param_5);
      param_5 = param_5 + 0xc;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  local_20 = (float)param_6;
  local_9c = 1.0 / local_20;
  FUN_005b3830(&local_64,&local_64,local_9c);
  FUN_005b3830(&local_1c,&local_1c,local_9c);
  if ((param_6 == 2) && (param_3 == 0)) {
    FUN_005405f0(param_9,param_4,param_4 + 0xc,param_2);
  }
  else {
    *param_9 = local_64;
    param_9[1] = local_60;
    param_9[2] = local_5c;
  }
  FUN_00541bc0(param_1,&local_64,(int)*(char *)(param_7 + 1),(int)*(short *)(param_7 + 2),param_7);
  if (*(char *)(param_7 + 1) == -1) {
    *param_8 = *param_2;
    param_8[1] = param_2[1];
    param_8[2] = param_2[2];
    return 0;
  }
  param_8[2] = 0.0;
  local_58 = 0;
  param_8[1] = 0.0;
  *param_8 = 0.0;
  local_54[5] = 0.0;
  local_54[4] = 0.0;
  local_54[3] = 0.0;
  if (param_10 != (float *)0x0) {
    *param_10 = 0.0;
  }
  if (param_11 != (float *)0x0) {
    *param_11 = 0.0;
  }
  if (param_12 != (float *)0x0) {
    *param_12 = 0.0;
  }
  if (param_13 != (float *)0x0) {
    *param_13 = 0.0;
  }
  if (param_14 != (float *)0x0) {
    *param_14 = 0.0;
  }
  local_8c = 0.0;
  local_88 = 0.0;
  local_78 = 0.0;
  local_3c = 0;
  if (0 < DAT_029838e4) {
    do {
      iVar13 = local_3c;
      iVar12 = local_3c * 0x38;
      if (param_3 == 0) {
LAB_005420df:
        iVar14 = (char)(&DAT_02983901)[iVar12] * 0x13c + *param_1;
        if ((*(byte *)(iVar14 + 0x68) & 0x80) == 0) {
          local_98 = (float)(&DAT_02983914)[local_3c * 0xe];
          local_94 = (float)(&DAT_02983918)[local_3c * 0xe];
          local_90 = (float)(&DAT_0298391c)[local_3c * 0xe];
        }
        else {
          local_2c = 0x3f800000;
          local_34 = 0x3f800000;
          local_28 = 0;
          local_24 = 0;
          local_38 = 0;
          local_30 = 0;
          FUN_005b3800(&local_a8,&local_64,&DAT_02983908 + local_3c * 0xe);
          FUN_005b35a0(&local_2c,&local_2c,(&DAT_02983920)[iVar13 * 0x1c]);
          FUN_005b3620(&local_2c,&local_2c,(&DAT_02983922)[iVar13 * 0x1c]);
          FUN_005b35a0(&local_38,&local_38,(&DAT_02983920)[iVar13 * 0x1c]);
          FUN_005b3620(&local_38,&local_38,(&DAT_02983922)[iVar13 * 0x1c]);
          fVar15 = (float10)FUN_005b39e0(&local_a8,&local_2c);
          fVar16 = (float10)FUN_005b39e0(&local_a8,&local_38);
          fVar2 = *(float *)(iVar14 + 0xa0);
          FUN_005b3830(&local_2c,&local_2c,*(float *)(iVar14 + 0x9c) * (float)fVar15);
          FUN_005b3830(&local_38,&local_38,fVar2 * (float)fVar16);
          FUN_005b37d0(&local_98,&local_2c,&local_38);
          FUN_005b37d0(&local_98,&local_98,&DAT_02983914 + iVar13 * 0xe);
        }
        if (*(float *)(iVar14 + 0xb4) != 0.0) {
          local_a4 = 0.0;
          local_a8 = 0.0;
          local_a0 = 1.0;
          FUN_005b35a0(&local_a8,&local_a8,(&DAT_02983920)[iVar13 * 0x1c]);
          FUN_005b3620(&local_a8,&local_a8,(&DAT_02983922)[iVar13 * 0x1c]);
          local_9c = *(float *)(iVar14 + 0xb4);
          local_98 = local_9c * local_a8 + local_98;
          local_94 = local_9c * local_a4 + local_94;
          local_90 = local_9c * local_a0 + local_90;
        }
        if (*(int *)(iVar14 + 0x24) == 0) {
          fVar2 = *(float *)(iVar14 + 0xa4);
LAB_005424dd:
          if ((fVar2 != 0.0) && ((*(byte *)(iVar14 + 0x68) & 0x80) == 0)) {
            local_84 = (local_64 - (float)(&DAT_02983908)[iVar13 * 0xe]) * fVar2;
            local_7c = (local_5c - (float)(&DAT_02983910)[iVar13 * 0xe]) * fVar2;
            if ((*(int *)(iVar14 + 0x18) != 0) || (*(int *)(iVar14 + 0x1c) != 0)) {
              fVar15 = (float10)FUN_005c0240(local_84 * local_84 + local_7c * local_7c);
              local_54[0] = 1.0;
              local_54[2] = 0.0;
              local_54[1] = 0.0;
              FUN_005b3620(local_54,local_54,(&DAT_02983926)[iVar13 * 0x1c]);
              if (0.0 <= local_84 * local_54[0] + local_7c * local_54[2]) {
                iVar11 = *(int *)(iVar14 + 0x1c);
              }
              else {
                iVar11 = *(int *)(iVar14 + 0x18);
              }
              if (iVar11 != 0) {
                FUN_0053e810(&local_a8,iVar11,(int)(short)(&DAT_02983902)[iVar13 * 0x1c],
                             (int)(short)(&DAT_02983928)[iVar13 * 0x1c],
                             (&DAT_02983904)[iVar13 * 0xe]);
                local_c = local_a8 - (float)(&DAT_02983914)[iVar13 * 0xe];
                local_4 = local_a0 - (float)(&DAT_0298391c)[iVar13 * 0xe];
                fVar16 = (float10)FUN_005c0240(local_c * local_c + local_4 * local_4);
                if ((float)fVar16 < (float)fVar15) {
                  local_9c = (float)fVar16 / (float)fVar15;
                  local_84 = local_9c * local_84;
                  local_7c = local_9c * local_7c;
                }
              }
            }
            local_98 = local_84 + local_98;
            local_90 = local_7c + local_90;
          }
        }
        else {
          iVar11 = *(int *)(*(int *)(iVar14 + 0x24) + 8);
          fVar2 = (float)(&DAT_02983904)[iVar13 * 0xe];
          pfVar8 = (float *)(iVar11 + (short)(&DAT_02983902)[iVar13 * 0x1c] * 0xc);
          pfVar1 = (float *)(iVar11 + (short)(&DAT_02983928)[iVar13 * 0x1c] * 0xc);
          local_a8 = *pfVar8 + fVar2 * (*pfVar1 - *pfVar8);
          local_a4 = (pfVar1[1] - pfVar8[1]) * fVar2 + pfVar8[1];
          local_a0 = (pfVar1[2] - pfVar8[2]) * fVar2 + pfVar8[2];
          local_54[0] = 1.0;
          local_54[2] = 0.0;
          local_54[1] = 0.0;
          FUN_005b3620(local_54,local_54,(&DAT_02983926)[iVar13 * 0x1c]);
          iVar11 = *(int *)(*(int *)(iVar14 + 4) + 8);
          pfVar8 = (float *)(iVar11 + (short)(&DAT_02983902)[iVar13 * 0x1c] * 0xc);
          pfVar1 = (float *)(iVar11 + (short)(&DAT_02983928)[iVar13 * 0x1c] * 0xc);
          fVar3 = (local_a0 - (float)(&DAT_02983910)[iVar13 * 0xe]) * local_54[2];
          fVar7 = (local_a8 - (float)(&DAT_02983908)[iVar13 * 0xe]) * local_54[0];
          fVar2 = (float)(&DAT_02983904)[iVar13 * 0xe];
          local_a8 = *pfVar8 + fVar2 * (*pfVar1 - *pfVar8);
          local_a4 = (pfVar1[1] - pfVar8[1]) * fVar2 + pfVar8[1];
          local_a0 = (pfVar1[2] - pfVar8[2]) * fVar2 + pfVar8[2];
          local_84 = local_a8 - (float)(&DAT_02983908)[iVar13 * 0xe];
          local_7c = local_a0 - (float)(&DAT_02983910)[iVar13 * 0xe];
          fVar15 = (float10)FUN_005c0240(local_84 * local_84 + local_7c * local_7c);
          iVar11 = *(int *)(*(int *)(iVar14 + 8) + 8);
          fVar2 = (float)(&DAT_02983904)[iVar13 * 0xe];
          pfVar8 = (float *)(iVar11 + (short)(&DAT_02983902)[iVar13 * 0x1c] * 0xc);
          pfVar1 = (float *)(iVar11 + (short)(&DAT_02983928)[iVar13 * 0x1c] * 0xc);
          local_a8 = *pfVar8 + fVar2 * (*pfVar1 - *pfVar8);
          local_a4 = (pfVar1[1] - pfVar8[1]) * fVar2 + pfVar8[1];
          local_a0 = (pfVar1[2] - pfVar8[2]) * fVar2 + pfVar8[2];
          local_84 = local_a8 - (float)(&DAT_02983908)[iVar13 * 0xe];
          local_7c = local_a0 - (float)(&DAT_02983910)[iVar13 * 0xe];
          fVar16 = (float10)FUN_005c0240(local_84 * local_84 + local_7c * local_7c);
          fVar2 = (float)(fVar16 + (float10)(float)fVar15) * 0.5;
          if (0.0 < fVar2) {
            fVar2 = ((fVar7 + fVar3) / fVar2) * local_9c;
            goto LAB_005424dd;
          }
        }
        if ((*(float *)(iVar14 + 0xa0) != 0.0) && ((*(byte *)(iVar14 + 0x68) & 0x80) == 0)) {
          local_94 = (local_60 - (float)(&DAT_0298390c)[iVar13 * 0xe]) * *(float *)(iVar14 + 0xa0) +
                     local_94;
        }
        if ((((*(float *)(iVar14 + 0xb8) <= 0.0) && (*(float *)(iVar14 + 0xbc) <= 0.0)) &&
            (*(float *)(iVar14 + 0xc0) <= 0.0)) ||
           (((*(float *)(iVar14 + 0xa8) == 0.0 && (*(float *)(iVar14 + 0xac) == 0.0)) &&
            (*(float *)(iVar14 + 0xb0) == 0.0)))) {
          if (*(float *)(iVar14 + 0xac) != 0.0) {
            local_b0 = 0.0;
            iVar11 = 0;
            if (3 < param_6) {
              iVar10 = (param_6 - 4U >> 2) + 1;
              iVar11 = iVar10 * 4;
              pfVar8 = (float *)(param_4 + 0x10);
              do {
                iVar10 = iVar10 + -1;
                local_b0 = pfVar8[-3] + local_b0 + *(float *)(iVar14 + 0xac) + *pfVar8 +
                           *(float *)(iVar14 + 0xac) + pfVar8[3] + *(float *)(iVar14 + 0xac) +
                           pfVar8[6] + *(float *)(iVar14 + 0xac);
                pfVar8 = pfVar8 + 0xc;
              } while (iVar10 != 0);
            }
            if (iVar11 < param_6) {
              iVar10 = param_6 - iVar11;
              pfVar8 = (float *)(param_4 + 4 + iVar11 * 0xc);
              do {
                iVar10 = iVar10 + -1;
                local_b0 = local_b0 + *pfVar8 + *(float *)(iVar14 + 0xac);
                pfVar8 = pfVar8 + 3;
              } while (iVar10 != 0);
            }
            local_94 = local_b0 / local_20;
            if ((*(byte *)(iVar14 + 0x68) & 0x20) != 0) {
              if ((float)(&DAT_02983918)[iVar13 * 0xe] <= local_94) {
                if ((*(int *)((char)(&DAT_02983901)[iVar12] * 0x13c + 0x14 + *param_1) != 0) &&
                   ((float)(&DAT_0298390c)[iVar13 * 0xe] < local_94)) {
                  local_94 = (float)(&DAT_0298390c)[iVar13 * 0xe];
                }
              }
              else {
                local_94 = (float)(&DAT_02983918)[iVar13 * 0xe];
              }
            }
          }
        }
        else {
          FUN_005b37d0(&local_a8,&local_1c,iVar14 + 0xa8);
          fVar2 = local_a8;
          if (*(float *)(iVar14 + 0xb8) < 1.0) {
            fVar2 = local_98 + *(float *)(iVar14 + 0xb8) * (local_a8 - local_98);
          }
          local_ac = local_a4;
          if (*(float *)(iVar14 + 0xbc) < 1.0) {
            local_ac = local_94 + *(float *)(iVar14 + 0xbc) * (local_a4 - local_94);
          }
          fVar3 = local_a0;
          if (*(float *)(iVar14 + 0xc0) < 1.0) {
            fVar3 = local_90 + *(float *)(iVar14 + 0xc0) * (local_a0 - local_90);
          }
          local_98 = fVar2;
          local_94 = local_ac;
          local_90 = fVar3;
          if ((*(byte *)(iVar14 + 0x68) & 0x20) != 0) {
            if ((float)(&DAT_02983918)[iVar13 * 0xe] <= local_ac) {
              if ((*(int *)((char)(&DAT_02983901)[iVar12] * 0x13c + 0x14 + *param_1) != 0) &&
                 ((float)(&DAT_0298390c)[iVar13 * 0xe] < local_ac)) {
                local_ac = (float)(&DAT_0298390c)[iVar13 * 0xe];
              }
            }
            else {
              local_ac = (float)(&DAT_02983918)[iVar13 * 0xe];
            }
            local_94 = local_ac;
          }
        }
        if (*(float *)(iVar14 + 0xc4) == 0.0) {
          if (*(float *)(iVar14 + 200) != 0.0) {
            local_98 = local_98 + *(float *)(iVar14 + 200) * (*param_9 - local_98);
            local_94 = local_94 + *(float *)(iVar14 + 200) * (param_9[1] - local_94);
            local_90 = local_90 + *(float *)(iVar14 + 200) * (param_9[2] - local_90);
          }
        }
        else {
          if ((*(ushort *)(iVar14 + 0x68) & 0x2000) == 0) {
            FUN_005b3800(&local_a8,param_9,&local_98);
          }
          else {
            local_a8 = *param_9 - local_98;
            local_a4 = 0.0;
            local_a0 = param_9[2] - local_90;
          }
          FUN_005b3b30(&local_a8,&local_a8);
          local_98 = *param_9 - *(float *)(iVar14 + 0xc4) * local_a8;
          local_90 = param_9[2] - *(float *)(iVar14 + 0xc4) * local_a0;
          if ((*(ushort *)(iVar14 + 0x68) & 0x2000) == 0) {
            local_94 = param_9[1] - *(float *)(iVar14 + 0xc4) * local_a4;
          }
        }
        if (((*(float *)(iVar14 + 0x88) == 1.0) && (*(float *)(iVar14 + 0x8c) == 1.0)) &&
           (*(char *)(iVar14 + 0x6d) == '\0')) {
          FUN_005b37d0(local_54 + 3,local_54 + 3,param_9);
        }
        else {
          if (*(int *)(iVar14 + 0x20) == 0) {
            local_70 = 0.0;
            local_74 = 0.0;
            fVar15 = (float10)FUN_005becc0(&local_98,param_9,0);
            local_6c = (float)fVar15;
            iVar12 = FUN_0053f830(iVar14,(int)(short)(&DAT_02983902)[iVar13 * 0x1c],&local_10,
                                  &local_68);
            if (iVar12 == 0) {
              FUN_005b35a0(&local_74,&local_74,(&DAT_02983920)[iVar13 * 0x1c]);
              uVar9 = (uint)(ushort)(&DAT_02983922)[iVar13 * 0x1c];
            }
            else {
              local_ac = (float)((uint)*(ushort *)(*(int *)(iVar14 + 0x38) + (int)local_68 * 4) -
                                (uint)*(ushort *)(*(int *)(iVar14 + 0x38) + local_10 * 4));
              if ((int)local_ac < 0x8001) {
                if ((int)local_ac < -0x8000) {
                  local_ac = (float)((int)local_ac + 0x10000);
                }
              }
              else {
                local_ac = (float)((int)local_ac + -0x10000);
              }
              iVar12 = *(int *)(iVar14 + 0x38);
              fVar2 = (float)(int)local_ac;
              local_ac = (float)((uint)*(ushort *)(iVar12 + 2 + (int)local_68 * 4) -
                                (uint)*(ushort *)(iVar12 + 2 + local_10 * 4));
              if ((int)local_ac < 0x8001) {
                if ((int)local_ac < -0x8000) {
                  local_ac = (float)((int)local_ac + 0x10000);
                }
              }
              else {
                local_ac = (float)((int)local_ac + -0x10000);
              }
              uVar6 = *(ushort *)(*(int *)(iVar14 + 0x38) + 2 + local_10 * 4);
              fVar3 = (float)(&DAT_02983904)[iVar13 * 0xe];
              FUN_005b35a0(&local_74,&local_74,
                           (int)ROUND((float)*(ushort *)(iVar12 + local_10 * 4) +
                                      fVar2 * (float)(&DAT_02983904)[iVar13 * 0xe]) & 0xffff);
              uVar9 = ((int)ROUND((float)uVar6 + (float)(int)local_ac * fVar3) & 0xffffU) - 0x1555;
            }
            FUN_005b3620(&local_74,&local_74,uVar9);
            FUN_005b37d0(&local_74,&local_74,&local_98);
          }
          else {
            iVar12 = *(int *)(*(int *)(iVar14 + 0x20) + 8);
            fVar2 = (float)(&DAT_02983904)[iVar13 * 0xe];
            pfVar8 = (float *)(iVar12 + (short)(&DAT_02983902)[iVar13 * 0x1c] * 0xc);
            pfVar1 = (float *)(iVar12 + (short)(&DAT_02983928)[iVar13 * 0x1c] * 0xc);
            local_74 = *pfVar8 + fVar2 * (*pfVar1 - *pfVar8);
            local_70 = (pfVar1[1] - pfVar8[1]) * fVar2 + pfVar8[1];
            local_6c = (pfVar1[2] - pfVar8[2]) * fVar2 + pfVar8[2];
          }
          local_54[3] = local_74 + *(float *)(iVar14 + 0x88) * (*param_9 - local_74) + local_54[3];
          local_54[4] = local_70 + *(float *)(iVar14 + 0x8c) * (param_9[1] - local_70) + local_54[4]
          ;
          local_54[5] = local_6c + *(float *)(iVar14 + 0x88) * (param_9[2] - local_6c) + local_54[5]
          ;
        }
        FUN_005b37d0(param_8,param_8,&local_98);
        if (param_10 != (float *)0x0) {
          *param_10 = *(float *)(iVar14 + 0xf4) + *param_10;
        }
        if (param_11 != (float *)0x0) {
          *param_11 = *(float *)(iVar14 + 0x90) + *param_11;
        }
        if (param_12 != (float *)0x0) {
          *param_12 = *(float *)(iVar14 + 0x94) + *param_12;
        }
        if (param_13 != (float *)0x0) {
          *param_13 = *(float *)(iVar14 + 0xd8) + *param_13;
        }
        local_58 = local_58 + 1;
        local_8c = *(float *)(iVar14 + 0xcc) + local_8c;
        local_88 = *(float *)(iVar14 + 0xd0) + local_88;
        local_78 = *(float *)(iVar14 + 0xd4) + local_78;
      }
      else {
        bVar4 = (&DAT_02983901)[iVar12];
        if ((bVar4 == *(byte *)(param_7 + 1)) ||
           ((*(uint *)(*param_1 + 0xdc +
                      ((char)*(byte *)(param_7 + 1) * 0x4f +
                      ((int)((int)(char)bVar4 + ((int)(char)bVar4 >> 0x1f & 0x1fU)) >> 5)) * 4) &
            1 << (bVar4 & 0x1f)) == 0)) goto LAB_005420df;
      }
      local_3c = local_3c + 1;
    } while (local_3c < DAT_029838e4);
    if (0 < local_58) {
      local_9c = 1.0 / (float)local_58;
      FUN_005b3830(param_8,param_8,local_9c);
      if (param_10 != (float *)0x0) {
        *param_10 = local_9c * *param_10;
      }
      if (param_11 != (float *)0x0) {
        *param_11 = *param_11 * local_9c;
      }
      if (param_12 != (float *)0x0) {
        *param_12 = *param_12 * local_9c;
      }
      if (param_13 != (float *)0x0) {
        *param_13 = *param_13 * local_9c;
      }
      local_8c = local_8c * local_9c;
      local_88 = local_88 * local_9c;
      if (param_14 != (float *)0x0) {
        *param_14 = local_88 * local_9c;
      }
      FUN_005b3830(param_9,local_54 + 3,local_9c);
      local_78 = local_78 * local_9c;
    }
    if (0.0 < local_78) {
      fVar15 = (float10)FUN_00673820(param_8,0,0x40a00000,0xffffffff);
      if (((float)fVar15 != 2e+06) && (fVar2 = (float)fVar15 + local_78, param_8[1] < fVar2)) {
        param_8[1] = fVar2;
      }
    }
  }
  if (param_6 == 1) {
    if (local_8c != 0.0) {
      fVar15 = (float10)FUN_005becc0(param_9,param_8,&local_a8);
      local_9c = (float)fVar15;
      if (1.0 < local_9c) {
        FUN_005b3b30(&local_a8,&local_a8);
        local_b0 = local_8c;
        if (local_9c - local_8c < 1.0) {
          local_b0 = local_9c - 1.0;
        }
        goto LAB_00542f60;
      }
    }
  }
  else if ((param_6 == 2) && (local_88 != 0.0)) {
    cVar5 = *(char *)(param_7 + 1);
    if ((cVar5 != -1) &&
       (uVar6 = *(ushort *)(cVar5 * 0x13c + 0x68 + *param_1), (uVar6 & 0x400) != 0)) {
      if ((uVar6 & 0x4000) == 0) {
        fVar15 = (float10)FUN_005bed80(param_4,param_4 + 0xc,0);
        local_b0 = (float)fVar15;
      }
      else {
        local_68 = *(float *)(param_4 + 4) - *(float *)(param_4 + 0x10);
        local_b0 = ABS(local_68);
      }
      local_b0 = -local_88 * local_b0;
      fVar15 = (float10)FUN_005bed80(param_9,param_8,&local_a8);
      local_9c = (float)fVar15;
      FUN_005b3b30(&local_a8,&local_a8);
      if (local_9c - local_b0 < 1.0) {
        local_b0 = local_9c - 1.0;
      }
      *param_8 = local_b0 * local_a8 + *param_8;
      param_8[2] = local_b0 * local_a0 + param_8[2];
      return 1;
    }
    if ((*(ushort *)(cVar5 * 0x13c + 0x68 + *param_1) & 0x4000) == 0) {
      fVar15 = (float10)FUN_005becc0(param_4,param_4 + 0xc,0);
      local_b0 = (float)fVar15;
    }
    else {
      local_68 = *(float *)(param_4 + 4) - *(float *)(param_4 + 0x10);
      local_b0 = ABS(local_68);
    }
    local_b0 = -local_88 * local_b0;
    fVar15 = (float10)FUN_005becc0(param_9,param_8,&local_a8);
    local_9c = (float)fVar15;
    FUN_005b3b30(&local_a8,&local_a8);
    if (local_9c - local_b0 < 1.0) {
      local_b0 = local_9c - 1.0;
    }
LAB_00542f60:
    *param_8 = local_b0 * local_a8 + *param_8;
    param_8[1] = local_b0 * local_a4 + param_8[1];
    param_8[2] = local_b0 * local_a0 + param_8[2];
    return 1;
  }
  return 1;
}

