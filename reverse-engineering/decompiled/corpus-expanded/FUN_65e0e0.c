/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65e0e0; label: FUN_0065e0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0065e0e0(char param_1,int param_2)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  float *pfVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  float local_1068;
  float local_1064;
  float local_1060;
  float local_105c;
  undefined4 local_1058;
  int local_1054;
  int local_1050;
  int local_104c;
  int local_1048;
  int local_1044;
  int local_1040;
  float local_103c;
  float local_1038;
  float local_1034;
  float local_1030;
  float local_102c;
  float local_1028;
  float local_1024;
  int local_1020;
  int local_101c;
  undefined1 local_1018 [12];
  undefined1 local_100c [12];
  float local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x65e0ea;
  iVar5 = (int)param_1;
  if (((((&DAT_02920acc)[iVar5] != 0) && (*(int *)(&DAT_02961f54 + iVar5 * 4) != 0)) &&
      (local_1044 = *(int *)(&DAT_0292fce8 + iVar5 * 4), local_1044 != 0)) &&
     (((&DAT_029211a8)[iVar5] == 0 && (local_1040 = 0, 0 < DAT_02962a08)))) {
    iVar13 = 0;
    iVar5 = DAT_02962a14;
    do {
      local_1050 = *(int *)(iVar13 + 4 + iVar5);
      if (((local_1050 != 0) && (*(char *)(iVar13 + 0x24 + iVar5) == param_1)) && (0 < local_1050))
      {
        local_1030 = *(float *)(iVar13 + 0x44 + iVar5);
        local_104c = (int)*(char *)(iVar13 + 0x42 + iVar5);
        local_1048 = (int)*(char *)(iVar13 + 0x43 + iVar5);
        if (*(char *)(iVar13 + 0x27 + iVar5) == '\x01') {
          local_1048 = 0;
        }
        if (local_104c == 0) {
          local_1048 = 0;
        }
        local_1058 = *(undefined4 *)(iVar13 + 0x28 + iVar5);
        local_1054 = 0;
        if (0 < local_1050) {
          pfVar8 = local_1000 + 1;
          do {
            iVar12 = local_1054;
            if (*(char *)(iVar13 + 0x27 + iVar5) == '\x03') {
              pfVar6 = (float *)(DAT_02962a18 +
                                (*(short *)(iVar13 + 0x40 + iVar5) * DAT_02962a10 + local_1054) *
                                0x20);
              pfVar8[-1] = *pfVar6;
              *pfVar8 = pfVar6[1];
              fVar1 = pfVar6[2];
            }
            else {
              switch(*(undefined1 *)(iVar13 + 0x25 + iVar5)) {
              case 1:
                uVar7 = FUN_005b9e10(&local_1058);
                fVar15 = (float10)FUN_005b9d90(&local_1058);
                local_105c = (float)(fVar15 * (float10)*(float *)(iVar13 + 0x14 + DAT_02962a14));
                local_1064 = local_105c * (float)(&DAT_029899a0)[(int)(uVar7 & 0xffff) >> 1];
                local_1060 = 0.0;
                local_105c = local_105c *
                             (float)(&DAT_029899a0)[(int)((uVar7 & 0xffff) + 0x4000) >> 1 & 0x7fff];
                fVar15 = (float10)FUN_005c0240(local_1064 * local_1064 + local_105c * local_105c);
                pfVar8[2] = (float)fVar15;
                fVar1 = (float)fVar15 + 1.5;
                local_1064 = local_1064 * fVar1;
                local_105c = fVar1 * local_105c;
                FUN_005b3690(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x34 + DAT_02962a14));
                FUN_005b3620(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x36 + DAT_02962a14));
                break;
              case 2:
                uVar7 = FUN_005b9e10(&local_1058);
                fVar15 = (float10)FUN_005b9d90(&local_1058);
                local_105c = (float)(fVar15 * (float10)*(float *)(iVar13 + 0x14 + DAT_02962a14));
                local_1064 = local_105c * (float)(&DAT_029899a0)[(int)(uVar7 & 0xffff) >> 1];
                local_1060 = 0.0;
                local_105c = local_105c *
                             (float)(&DAT_029899a0)[(int)((uVar7 & 0xffff) + 0x4000) >> 1 & 0x7fff];
                fVar15 = (float10)FUN_005c0240(local_1064 * local_1064 + local_105c * local_105c);
                pfVar8[2] = (float)fVar15;
                FUN_005b3690(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x34 + DAT_02962a14));
                FUN_005b3620(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x36 + DAT_02962a14));
                break;
              case 3:
                fVar15 = (float10)FUN_005b9d90(&local_1058);
                local_1064 = (float)(((fVar15 + fVar15) - (float10)1.0) *
                                    (float10)*(float *)(iVar13 + 0x14 + DAT_02962a14));
                local_1060 = 0.0;
                fVar15 = (float10)FUN_005b9d90(&local_1058);
                local_105c = (float)(((fVar15 + fVar15) - (float10)1.0) *
                                    (float10)*(float *)(iVar13 + 0x14 + DAT_02962a14));
                fVar15 = (float10)FUN_005c0240(local_1064 * local_1064 + local_105c * local_105c);
                pfVar8[2] = (float)fVar15;
                FUN_005b3690(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x34 + DAT_02962a14));
                FUN_005b3620(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x36 + DAT_02962a14));
                break;
              case 4:
                FUN_005c0240((float)local_1050);
                iVar5 = FUN_006e6b90();
                iVar12 = (iVar5 + -1 + local_1050) / iVar5;
                fVar1 = *(float *)(iVar13 + 0x14 + DAT_02962a14);
                fVar1 = fVar1 + fVar1;
                local_101c = local_1054 / iVar12;
                local_1020 = local_1054 % iVar12;
                local_1064 = (fVar1 / (float)(iVar5 + -1)) * (float)local_101c -
                             *(float *)(iVar13 + 0x14 + DAT_02962a14);
                local_1060 = 0.0;
                local_105c = (float)local_1020 * (fVar1 / (float)(iVar12 + -1)) -
                             *(float *)(iVar13 + 0x14 + DAT_02962a14);
                fVar15 = (float10)FUN_005c0240(local_1064 * local_1064 + local_105c * local_105c);
                pfVar8[2] = (float)fVar15;
                FUN_005b3690(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x34 + DAT_02962a14));
                FUN_005b3620(&local_1064,&local_1064,(int)*(short *)(iVar13 + 0x36 + DAT_02962a14));
                iVar12 = local_1054;
                break;
              default:
                goto switchD_0065e203_default;
              }
              pfVar8[-1] = local_1064;
              *pfVar8 = local_1060;
              iVar5 = DAT_02962a14;
              fVar1 = local_105c;
            }
            pfVar8[1] = fVar1;
switchD_0065e203_default:
            cVar2 = *(char *)(iVar13 + 0x27 + iVar5);
            pfVar8[-1] = *(float *)(iVar13 + 8 + iVar5) + pfVar8[-1];
            *pfVar8 = *(float *)(iVar13 + 0xc + iVar5) + *pfVar8;
            pfVar8[1] = *(float *)(iVar13 + 0x10 + iVar5) + pfVar8[1];
            if (cVar2 == '\x03') {
              local_1068 = (*(float *)(iVar13 + 0x30 + iVar5) - *(float *)(iVar13 + 0x2c + iVar5)) *
                           *(float *)((*(short *)(iVar13 + 0x40 + iVar5) * DAT_02962a10 + iVar12) *
                                      0x20 + 0xc + DAT_02962a18);
LAB_0065e6f3:
              local_1068 = local_1068 + *(float *)(iVar13 + 0x2c + iVar5);
              goto LAB_0065e6f7;
            }
            switch(*(undefined1 *)(iVar13 + 0x26 + iVar5)) {
            case 1:
              fVar15 = (float10)FUN_005b9d90(&local_1058);
              fVar1 = (((1.2 - pfVar8[2] * 1.25) +
                       (float)(fVar15 - (float10)0.25) * (float)(fVar15 - (float10)0.25)) / 1.7625)
                      * *(float *)(iVar13 + 0x30 + DAT_02962a14);
              pfVar8[2] = fVar1;
              iVar5 = DAT_02962a14;
              if (fVar1 < *(float *)(iVar13 + 0x2c + DAT_02962a14)) {
                local_1068 = *(float *)(iVar13 + 0x2c + DAT_02962a14);
                goto LAB_0065e6f7;
              }
              break;
            case 2:
              pfVar6 = (float *)(iVar13 + 0x2c + iVar5);
              fVar15 = (float10)FUN_005b9d90(&local_1058);
              local_1068 = (float)(((float10)*(float *)(iVar13 + 0x30 + DAT_02962a14) -
                                   (float10)*pfVar6) * fVar15) + *pfVar6;
              iVar12 = local_1054;
              iVar5 = DAT_02962a14;
              goto LAB_0065e6f7;
            case 3:
              if (*(float *)(iVar13 + 0x14 + iVar5) <= pfVar8[2]) {
                fVar1 = *(float *)(iVar13 + 0x14 + iVar5);
              }
              else {
                fVar1 = pfVar8[2];
              }
              local_1068 = *(float *)(iVar13 + 0x30 + iVar5) -
                           (fVar1 / *(float *)(iVar13 + 0x14 + iVar5)) *
                           (*(float *)(iVar13 + 0x30 + iVar5) - *(float *)(iVar13 + 0x2c + iVar5));
LAB_0065e6f7:
              pfVar8[2] = local_1068;
              break;
            case 4:
              iVar14 = FUN_006e6b90();
              local_1068 = (*(float *)(iVar13 + 0x30 + iVar5) - *(float *)(iVar13 + 0x2c + iVar5)) *
                           (float)(&DAT_029899a0)[0x4000 - iVar14 >> 1 & 0x7fff];
              goto LAB_0065e6f3;
            }
            local_1054 = iVar12 + 1;
            pfVar8 = pfVar8 + 4;
          } while (local_1054 < local_1050);
        }
        iVar12 = 0;
        local_1058 = *(undefined4 *)(iVar13 + 0x28 + iVar5);
        local_1054 = 0;
        if (0 < local_1050) {
          pfVar8 = local_1000 + 1;
          iVar14 = local_1044;
          do {
            local_102c = pfVar8[2];
            local_103c = pfVar8[-1];
            local_1038 = *pfVar8;
            local_1034 = pfVar8[1];
            local_1028 = local_102c;
            local_1024 = local_102c;
            if (*(char *)(iVar13 + 0x27 + iVar5) == '\x03') {
              if ((local_104c != 0) && (param_2 != 0)) {
                puVar9 = (undefined4 *)FUN_005456c0(local_1018,&local_103c);
                uVar11 = puVar9[1];
                uVar3 = puVar9[2];
                puVar10 = (undefined4 *)(*(int *)(iVar13 + 0x4c + DAT_02962a14) + iVar12);
                *puVar10 = *puVar9;
                puVar10[1] = uVar11;
                puVar10[2] = uVar3;
              }
              FUN_005b44e0(iVar14);
              iVar5 = local_1054;
              FUN_005b5160(iVar14,(int)*(short *)((*(short *)(iVar13 + 0x40 + DAT_02962a14) *
                                                   DAT_02962a10 + local_1054) * 0x20 + 0x10 +
                                                 DAT_02962a18));
              FUN_005b4f70(iVar14,(int)*(short *)((*(short *)(iVar13 + 0x40 + DAT_02962a14) *
                                                   DAT_02962a10 + iVar5) * 0x20 + 0x12 +
                                                 DAT_02962a18));
              if (local_1048 != 0) {
                uVar11 = FUN_006e6b90();
                FUN_005b5160(iVar14,uVar11);
                uVar11 = FUN_006e6b90();
                FUN_005b4cf0(iVar14,uVar11);
              }
              FUN_005b4a50(iVar14,&local_102c);
              if (local_104c != 0) {
                local_1038 = *(float *)(*(int *)(iVar13 + 0x4c + DAT_02962a14) + 4 + iVar12) +
                             local_1030;
              }
              FUN_005b4900(iVar14,&local_103c);
            }
            else {
              if ((local_104c != 0) && (param_2 != 0)) {
                puVar9 = (undefined4 *)FUN_005456c0(local_100c,&local_103c);
                uVar11 = puVar9[1];
                uVar3 = puVar9[2];
                puVar10 = (undefined4 *)(*(int *)(iVar13 + 0x4c + DAT_02962a14) + iVar12);
                *puVar10 = *puVar9;
                puVar10[1] = uVar11;
                puVar10[2] = uVar3;
              }
              FUN_005b44e0(iVar14);
              uVar4 = FUN_005b9e10(&local_1058);
              FUN_005b5060(iVar14,uVar4);
              if (local_1048 != 0) {
                uVar11 = FUN_006e6b90();
                FUN_005b5160(iVar14,uVar11);
                uVar11 = FUN_006e6b90();
                FUN_005b4cf0(iVar14,uVar11);
              }
              FUN_005b4a50(iVar14,&local_102c);
              if (local_104c != 0) {
                local_1038 = *(float *)(*(int *)(iVar13 + 0x4c + DAT_02962a14) + 4 + iVar12) +
                             local_1030;
              }
              FUN_005b4900(iVar14,&local_103c);
              if (*(char *)(iVar13 + 0x27 + DAT_02962a14) == '\x01') {
                *(float *)(iVar14 + 0x3c) = *(float *)(iVar13 + 0x18 + DAT_02962a14) * pfVar8[2];
              }
            }
            pfVar8 = pfVar8 + 4;
            local_1054 = local_1054 + 1;
            iVar14 = iVar14 + 0x40;
            iVar12 = iVar12 + 0xc;
            iVar5 = DAT_02962a14;
          } while (local_1054 < local_1050);
        }
        *(int *)(iVar13 + 0x48 + iVar5) = local_1044;
        local_1044 = local_1044 + local_1050 * 0x40;
        iVar5 = DAT_02962a14;
      }
      local_1040 = local_1040 + 1;
      iVar13 = iVar13 + 0x50;
    } while (local_1040 < DAT_02962a08);
  }
  return;
}

