/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x6091c0; label: FUN_006091c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006091c0(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_70;
  float local_68;
  float local_60;
  int local_54;
  float local_40;
  float local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_10;
  float local_c;
  
  local_28 = _DAT_0280a2a0;
  local_24 = _DAT_0280a2a0;
  iVar12 = 0;
  local_20 = _DAT_0280a2a8;
  local_1c = _DAT_0280a2a8;
  if (param_1 != 0) {
    DAT_028358a4 = DAT_00981c90;
  }
  if ((DAT_0280a298 != 0) && (DAT_028358a4 != 0)) {
    pfVar7 = (float *)FUN_006de8d0(0xc0);
    uVar8 = FUN_005d61c0();
    iVar9 = FUN_005d4300(1,2,0);
    iVar6 = DAT_02854d1c;
    iVar10 = DAT_0280a298;
    if (iVar9 != 0) {
      _DAT_0080e2b0 = 0x3b4ccccd;
      DAT_02854d1c = DAT_02854d1c + 1;
      _DAT_0080e2b4 = 0xbc124925;
      _DAT_02854d20 = 0xbf800000;
      *(undefined4 *)(&DAT_00981c50 + iVar6 * 4) = 0;
      _DAT_02854d24 = 0x3f800000;
      FUN_00607d70(0xc,5,iVar10);
      local_54 = 0;
      if (0 < DAT_028358a4) {
        pfVar1 = pfVar7 + 0x14;
        do {
          pfVar7[0x10] = *(float *)((int)&DAT_00986460 + iVar12);
          pfVar7[0x11] = *(float *)((int)&DAT_00986464 + iVar12);
          pfVar7[0x12] = *(float *)((int)&DAT_00986468 + iVar12);
          pfVar7[0x13] = 1.0;
          FUN_005c03e0(pfVar7 + 0x10,pfVar7 + 0x10,uVar8);
          *pfVar1 = *(float *)((int)&DAT_0098646c + iVar12);
          pfVar7[0x15] = *(float *)((int)&DAT_00986470 + iVar12);
          pfVar7[0x16] = *(float *)((int)&DAT_00986474 + iVar12);
          pfVar7[0x17] = 1.0;
          FUN_005c03e0(pfVar1,pfVar1,uVar8);
          fVar3 = pfVar7[0x13];
          if ((!NAN(fVar3) && 0.5 < fVar3 != (fVar3 == 0.5)) ||
             (fVar3 = pfVar7[0x17], !NAN(fVar3) && 0.5 < fVar3 != (fVar3 == 0.5))) {
            if (0.5 <= pfVar7[0x13]) {
              pfVar7[0x18] = *(float *)((int)&DAT_00986460 + iVar12);
              pfVar7[0x19] = *(float *)((int)&DAT_00986464 + iVar12);
              fVar3 = *(float *)((int)&DAT_00986468 + iVar12);
            }
            else {
              fVar3 = pfVar7[0x17] - 0.5;
              fVar4 = pfVar7[0x17] - pfVar7[0x13];
              pfVar7[0x18] = ((*(float *)((int)&DAT_00986460 + iVar12) -
                              *(float *)((int)&DAT_0098646c + iVar12)) * fVar3) / fVar4 +
                             *(float *)((int)&DAT_0098646c + iVar12);
              pfVar7[0x19] = ((*(float *)((int)&DAT_00986464 + iVar12) -
                              *(float *)((int)&DAT_00986470 + iVar12)) * fVar3) / fVar4 +
                             *(float *)((int)&DAT_00986470 + iVar12);
              fVar3 = ((*(float *)((int)&DAT_00986468 + iVar12) -
                       *(float *)((int)&DAT_00986474 + iVar12)) * fVar3) / fVar4 +
                      *(float *)((int)&DAT_00986474 + iVar12);
            }
            pfVar7[0x1a] = fVar3;
            pfVar7[0x1b] = 1.0;
            if (0.5 <= pfVar7[0x17]) {
              pfVar7[0x1c] = *(float *)((int)&DAT_0098646c + iVar12);
              pfVar7[0x1d] = *(float *)((int)&DAT_00986470 + iVar12);
              fVar3 = *(float *)((int)&DAT_00986474 + iVar12);
            }
            else {
              fVar3 = pfVar7[0x13] - 0.5;
              fVar4 = pfVar7[0x13] - pfVar7[0x17];
              pfVar7[0x1c] = ((*(float *)((int)&DAT_0098646c + iVar12) -
                              *(float *)((int)&DAT_00986460 + iVar12)) * fVar3) / fVar4 +
                             *(float *)((int)&DAT_00986460 + iVar12);
              pfVar7[0x1d] = ((*(float *)((int)&DAT_00986470 + iVar12) -
                              *(float *)((int)&DAT_00986464 + iVar12)) * fVar3) / fVar4 +
                             *(float *)((int)&DAT_00986464 + iVar12);
              fVar3 = ((*(float *)((int)&DAT_00986474 + iVar12) -
                       *(float *)((int)&DAT_00986468 + iVar12)) * fVar3) / fVar4 +
                      *(float *)((int)&DAT_00986468 + iVar12);
            }
            pfVar7[0x1e] = fVar3;
            pfVar7[0x1f] = 1.0;
            FUN_005c03e0(pfVar7 + 0x10,pfVar7 + 0x18,uVar8);
            FUN_005c03b0(pfVar7 + 0x10,pfVar7 + 0x10,1.0 / pfVar7[0x13]);
            FUN_005c03e0(pfVar1,pfVar7 + 0x1c,uVar8);
            FUN_005c03b0(pfVar1,pfVar1,1.0 / pfVar7[0x17]);
            local_40 = ((float)DAT_00973900 / 240.0) * (pfVar7[0x15] - pfVar7[0x11]);
            local_3c = pfVar7[0x10] - *pfVar1;
            local_38 = 0;
            FUN_005b3b30(&local_40,&local_40);
            local_40 = (((float)DAT_00973900 * 150.0) / 240.0) *
                       *(float *)((int)&DAT_00986484 + iVar12) * local_40;
            local_3c = *(float *)((int)&DAT_00986484 + iVar12) * 150.0 * local_3c;
            fVar3 = pfVar7[0x1c] - pfVar7[0x18];
            pfVar7[0x1c] = fVar3;
            fVar4 = pfVar7[0x1d] - pfVar7[0x19];
            pfVar7[0x1d] = fVar4;
            fVar5 = pfVar7[0x1e] - pfVar7[0x1a];
            pfVar7[0x1e] = fVar5;
            pfVar7[0x1f] = pfVar7[0x1f] - pfVar7[0x1b];
            fVar13 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
            if (0.0 < (float)fVar13) {
              pfVar7[0x28] = *(float *)((int)&DAT_00986478 + iVar12);
              pfVar7[0x29] = *(float *)((int)&DAT_0098647c + iVar12);
              fVar3 = *(float *)((int)&DAT_00986480 + iVar12);
              pfVar7[0x2a] = fVar3;
              fVar3 = pfVar7[0x28] * pfVar7[0x28] + pfVar7[0x29] * pfVar7[0x29] + fVar3 * fVar3;
              if (0.0 < fVar3) {
                fVar4 = *(float *)((int)&DAT_00986490 + iVar12);
                fVar14 = (float10)FUN_005c0240(fVar3);
                fVar3 = (float)((float10)fVar4 / fVar14);
              }
              pfVar7[0x28] = pfVar7[0x28] * fVar3;
              pfVar7[0x29] = pfVar7[0x29] * fVar3;
              pfVar7[0x2a] = fVar3 * pfVar7[0x2a];
              DAT_0080e6c8 = *(uint *)((int)&DAT_009864a0 + iVar12);
              local_70 = *(float *)((int)&DAT_00986488 + iVar12) / (float)fVar13;
              if (1.0 < local_70) {
                local_70 = 1.0;
              }
              local_10 = _DAT_0280a29c;
              pfVar2 = pfVar7 + 0x10;
              local_c = _DAT_0280a2a4;
              *pfVar2 = pfVar7[0x18];
              pfVar7[0x11] = pfVar7[0x19];
              pfVar7[0x12] = pfVar7[0x1a];
              pfVar7[0x13] = 1.0;
              FUN_005c03e0(pfVar2,pfVar2,uVar8);
              FUN_005c03b0(pfVar7 + 0x10,pfVar7 + 0x10,1.0 / pfVar7[0x13]);
              pfVar7[4] = pfVar7[0x10];
              pfVar7[5] = pfVar7[0x11];
              pfVar7[6] = pfVar7[0x12];
              pfVar7[0xc] = pfVar7[0x10];
              pfVar7[0xd] = pfVar7[0x11];
              pfVar7[0xe] = pfVar7[0x12];
              local_68 = 0.0;
              do {
                fVar13 = (float10)1;
                fVar3 = local_68 + local_70;
                if (fVar3 < 1.0) {
                  iVar10 = FUN_006e6b90();
                  pfVar2 = (float *)(&DAT_029899a0 + (iVar10 >> 1 & 0x7fff));
                  *pfVar1 = (float)((float10)pfVar7[0x28] * (float10)*pfVar2 +
                                   (float10)pfVar7[0x1c] * extraout_ST1 + (float10)pfVar7[0x18]);
                  pfVar7[0x15] = (float)((float10)pfVar7[0x29] * (float10)*pfVar2 +
                                        (float10)pfVar7[0x1d] * extraout_ST1 + (float10)pfVar7[0x19]
                                        );
                  pfVar7[0x16] = (float)((float10)*pfVar2 * (float10)pfVar7[0x2a] +
                                        (float10)pfVar7[0x1a] + (float10)pfVar7[0x1e] * extraout_ST1
                                        );
                  fVar13 = extraout_ST0;
                }
                else {
                  *pfVar1 = pfVar7[0x18] + pfVar7[0x1c];
                  pfVar7[0x15] = pfVar7[0x1d] + pfVar7[0x19];
                  pfVar7[0x16] = pfVar7[0x1a] + pfVar7[0x1e];
                  local_10 = ((_DAT_0280a29c - _DAT_0280a2a4) * (1.0 - local_68)) / local_70 +
                             _DAT_0280a2a4;
                }
                pfVar7[0x17] = (float)fVar13;
                FUN_005c03e0(pfVar1,pfVar1,uVar8);
                fVar4 = 1.0 / pfVar7[0x17];
                FUN_005c03b0(pfVar1,pfVar1,fVar4);
                if ((1.0 - local_70 * 1.5 <= local_68) || (DAT_0080e6c8 == 0)) {
                  local_60 = 0.0;
                  local_68 = 0.0;
                }
                else {
                  uVar11 = DAT_0080e6c8 * 0x24cd + 1;
                  DAT_0080e6c8 = uVar11 & 0xffff;
                  fVar5 = (float)(int)((uVar11 & 0xff) - 0x80);
                  local_60 = fVar4 * fVar5 * local_40 * *(float *)((int)&DAT_0098648c + iVar12);
                  local_68 = fVar4 * *(float *)((int)&DAT_0098648c + iVar12) * local_3c * fVar5;
                }
                local_34 = fVar4 * local_40;
                local_30 = fVar4 * local_3c;
                fVar4 = local_60 + (*pfVar1 - local_34);
                *pfVar7 = fVar4;
                fVar5 = local_68 + (pfVar7[0x15] - local_30);
                pfVar7[1] = fVar5;
                pfVar7[2] = pfVar7[0x16];
                pfVar7[8] = *pfVar1 + local_34 + local_60;
                pfVar7[9] = local_68 + pfVar7[0x15] + local_30;
                pfVar7[10] = pfVar7[0x16];
                if (((((-50.0 <= fVar4) || (50.0 <= pfVar7[4])) &&
                     ((fVar4 <= 700.0 || (pfVar7[4] <= 700.0)))) &&
                    ((-50.0 <= fVar5 || (-50.0 <= pfVar7[5])))) &&
                   ((fVar5 <= 530.0 || (pfVar7[5] <= 530.0)))) {
                  FUN_005f77d0();
                  iVar10 = *DAT_02854d10;
                  *(float *)(iVar10 + 0x10) = local_10;
                  *(undefined4 *)(iVar10 + 0x14) = local_28;
                  FUN_006009e0(*pfVar7,pfVar7[1],pfVar7[2]);
                  FUN_005f77d0();
                  iVar10 = *DAT_02854d10;
                  *(float *)(iVar10 + 0x10) = local_c;
                  *(undefined4 *)(iVar10 + 0x14) = local_24;
                  FUN_006009e0(pfVar7[4],pfVar7[5],pfVar7[6]);
                  FUN_005f77d0();
                  iVar10 = *DAT_02854d10;
                  *(float *)(iVar10 + 0x10) = local_10;
                  *(undefined4 *)(iVar10 + 0x14) = local_20;
                  FUN_006009e0(pfVar7[8],pfVar7[9],pfVar7[10]);
                  FUN_005f77d0();
                  iVar10 = *DAT_02854d10;
                  *(float *)(iVar10 + 0x10) = local_c;
                  *(undefined4 *)(iVar10 + 0x14) = local_24;
                  FUN_006009e0(pfVar7[4],pfVar7[5],pfVar7[6]);
                  FUN_005f77d0();
                  iVar10 = *DAT_02854d10;
                  *(float *)(iVar10 + 0x10) = local_c;
                  *(undefined4 *)(iVar10 + 0x14) = local_1c;
                  FUN_006009e0(pfVar7[0xc],pfVar7[0xd],pfVar7[0xe]);
                  FUN_005f77d0();
                  iVar10 = *DAT_02854d10;
                  *(float *)(iVar10 + 0x10) = local_10;
                  *(undefined4 *)(iVar10 + 0x14) = local_20;
                  FUN_006009e0(pfVar7[8],pfVar7[9],pfVar7[10]);
                }
                pfVar7[4] = *pfVar7;
                pfVar7[5] = pfVar7[1];
                pfVar7[6] = pfVar7[2];
                pfVar7[0xc] = pfVar7[8];
                pfVar7[0xd] = pfVar7[9];
                pfVar7[0xe] = pfVar7[10];
                local_68 = fVar3;
              } while (fVar3 < 1.0);
            }
          }
          local_54 = local_54 + 1;
          iVar12 = iVar12 + 0x44;
        } while (local_54 < DAT_028358a4);
      }
      *DAT_02854d18 = DAT_02854d14;
      DAT_02854d1c = DAT_02854d1c + -1;
      DAT_02854d14 = 0;
      FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
      thunk_FUN_005f3950(0);
      DAT_00981c90 = DAT_028358a4;
      DAT_028358a4 = 0;
      if (param_1 == 0) {
        _DAT_02854b44 = _DAT_02854b44 + 1;
      }
    }
    FUN_006de960();
    return;
  }
  DAT_00981c90 = 0;
  return;
}

