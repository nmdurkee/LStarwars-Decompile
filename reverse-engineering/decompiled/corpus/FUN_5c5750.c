/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c5750; label: FUN_005c5750
 */

uint FUN_005c5750(float *param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  uint in_EAX;
  undefined2 extraout_var;
  undefined2 uVar6;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint local_164;
  uint local_160;
  uint local_15c;
  int local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  float local_128;
  int *local_124;
  float local_120 [7];
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  float local_e8;
  undefined4 local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  float local_d0;
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  float local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90;
  float local_8c;
  float local_80;
  float local_7c;
  float local_78;
  double local_68;
  undefined1 local_60 [8];
  float local_58;
  undefined1 local_50 [76];
  
  local_148 = 1e+06;
  local_154 = 1e+06;
  local_150 = -1e+06;
  local_14c = -1e+06;
  local_144 = 1e+06;
  if ((char)in_ECX[4] != '\0') {
    local_120[0] = *param_1;
    local_120[1] = (float)param_2[1];
    local_120[2] = param_1[2];
    local_120[3] = 1.0;
    local_120[4] = *param_1;
    local_120[5] = (float)param_2[1];
    local_120[6] = (float)param_2[2];
    local_104 = 0x3f800000;
    local_100 = *param_2;
    local_fc = param_2[1];
    local_f8 = param_2[2];
    local_f4 = 0x3f800000;
    local_f0 = *param_2;
    local_ec = param_2[1];
    local_e8 = param_1[2];
    local_e4 = 0x3f800000;
    local_e0 = *param_1;
    local_dc = param_1[1];
    local_d8 = param_1[2];
    local_d4 = 0x3f800000;
    local_d0 = *param_1;
    local_cc = param_1[1];
    local_c8 = param_2[2];
    local_c4 = 0x3f800000;
    local_c0 = *param_2;
    local_bc = param_1[1];
    local_b8 = param_2[2];
    local_b4 = 0x3f800000;
    local_b0 = *param_2;
    local_ac = param_1[1];
    local_a8 = param_1[2];
    local_a4 = 0x3f800000;
    local_124 = in_ECX;
    if (param_3 == 0) {
      FUN_005c19d0();
    }
    else {
      FUN_005c1240(local_50,param_3,in_ECX + 8);
    }
    iVar10 = 0;
    pfVar7 = local_120;
    do {
      FUN_005b3ec0(pfVar7,pfVar7,local_50);
      fVar1 = pfVar7[3];
      in_EAX = CONCAT22(extraout_var,
                        (ushort)(0.0 < fVar1) << 8 | (ushort)NAN(fVar1) << 10 |
                        (ushort)(fVar1 == 0.0) << 0xe);
      if (0.0 >= fVar1) goto LAB_005c5c24;
      fVar1 = *pfVar7 / pfVar7[3];
      *pfVar7 = fVar1;
      fVar3 = pfVar7[1] / pfVar7[3];
      pfVar7[1] = fVar3;
      pfVar7[2] = pfVar7[2] / pfVar7[3];
      if (fVar1 < local_148) {
        local_148 = fVar1;
      }
      if (fVar3 < local_154) {
        local_154 = fVar3;
      }
      if (local_150 < fVar1) {
        local_150 = fVar1;
      }
      if (local_14c < fVar3) {
        local_14c = fVar3;
      }
      if (pfVar7[3] < local_144) {
        local_144 = pfVar7[3];
      }
      iVar10 = iVar10 + 1;
      pfVar7 = pfVar7 + 4;
    } while (iVar10 != 8);
    in_EAX = in_ECX[3];
    local_160 = 100;
    if ((int)in_EAX < 0x65) {
      local_160 = in_EAX;
    }
    local_164 = 0;
    if (local_160 != 0) {
      do {
        in_EAX = *(uint *)(in_ECX[1] + local_164 * 4);
        if (in_EAX != 0xffffffff) {
          iVar10 = in_EAX * 0xa0 + *in_ECX;
          fVar1 = *(float *)(iVar10 + 0x94);
          fVar3 = local_144 - 2.0;
          uVar6 = (undefined2)(in_EAX >> 0x10);
          in_EAX = CONCAT22(uVar6,(ushort)(fVar3 < fVar1) << 8 |
                                  (ushort)(NAN(fVar3) || NAN(fVar1)) << 10 |
                                  (ushort)(fVar3 == fVar1) << 0xe);
          if (fVar3 < fVar1) break;
          fVar1 = *(float *)(iVar10 + 0x84);
          in_EAX = CONCAT22(uVar6,(ushort)(fVar1 < local_148) << 8 |
                                  (ushort)(NAN(fVar1) || NAN(local_148)) << 10 |
                                  (ushort)(fVar1 == local_148) << 0xe);
          if (fVar1 >= local_148) {
            fVar1 = *(float *)(iVar10 + 0x8c);
            in_EAX = CONCAT22(uVar6,(ushort)(fVar1 < local_154) << 8 |
                                    (ushort)(NAN(fVar1) || NAN(local_154)) << 10 |
                                    (ushort)(fVar1 == local_154) << 0xe);
            if (fVar1 >= local_154) {
              fVar1 = *(float *)(iVar10 + 0x80);
              in_EAX = CONCAT22(uVar6,(ushort)(fVar1 < local_150) << 8 |
                                      (ushort)(NAN(fVar1) || NAN(local_150)) << 10 |
                                      (ushort)(fVar1 == local_150) << 0xe);
              if (fVar1 < local_150 || (fVar1 == local_150) != 0) {
                fVar1 = *(float *)(iVar10 + 0x88);
                in_EAX = CONCAT22(uVar6,(ushort)(fVar1 < local_14c) << 8 |
                                        (ushort)(NAN(fVar1) || NAN(local_14c)) << 10 |
                                        (ushort)(fVar1 == local_14c) << 0xe);
                if (fVar1 < local_14c || (fVar1 == local_14c) != 0) {
                  local_80 = *(float *)(iVar10 + 0x50) - *(float *)(iVar10 + 0x40);
                  local_7c = *(float *)(iVar10 + 0x54) - *(float *)(iVar10 + 0x44);
                  local_78 = *(float *)(iVar10 + 0x58) - *(float *)(iVar10 + 0x48);
                  local_a0 = *(float *)(iVar10 + 0x60) - *(float *)(iVar10 + 0x40);
                  local_9c = *(float *)(iVar10 + 100) - *(float *)(iVar10 + 0x44);
                  local_98 = *(float *)(iVar10 + 0x68) - *(float *)(iVar10 + 0x48);
                  FUN_005b3920(local_60,&local_a0,&local_80);
                  bVar2 = local_58 <= 0.0;
                  local_15c = 1;
                  local_158 = 0;
                  iVar8 = 0x30;
                  local_68 = 0.0;
                  do {
                    local_134 = 0;
                    local_138 = 0;
                    uVar4 = local_15c & 0x80000003;
                    if ((int)uVar4 < 0) {
                      uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
                    }
                    iVar9 = local_158;
                    if (bVar2) {
                      uVar4 = 3 - uVar4;
                      iVar9 = iVar8;
                    }
                    iVar5 = (uVar4 + 4) * 0x10;
                    local_140 = *(float *)(iVar5 + 4 + iVar10) - *(float *)(iVar9 + 0x44 + iVar10);
                    local_13c = -(*(float *)(iVar5 + iVar10) - *(float *)(iVar9 + 0x40 + iVar10));
                    in_EAX = FUN_005b3b30(&local_140,&local_140);
                    iVar5 = 0;
                    local_134 = 0;
                    pfVar7 = local_120;
                    local_138 = 0;
                    do {
                      local_90 = *pfVar7 - *(float *)(iVar9 + 0x40 + iVar10);
                      local_8c = pfVar7[1] - *(float *)(iVar9 + 0x44 + iVar10);
                      local_128 = local_140 * local_90 + local_8c * local_13c + (float)local_68;
                      in_EAX = CONCAT22((short)(in_EAX >> 0x10),
                                        (ushort)(local_128 < 0.01) << 8 |
                                        (ushort)NAN(local_128) << 10 |
                                        (ushort)(local_128 == 0.01) << 0xe);
                      in_ECX = local_124;
                      if (local_128 < 0.01) goto LAB_005c5c13;
                      iVar5 = iVar5 + 1;
                      pfVar7 = pfVar7 + 4;
                    } while (iVar5 != 8);
                    local_158 = local_158 + 0x10;
                    local_15c = local_15c + 1;
                    iVar8 = iVar8 + -0x10;
                    if (iVar8 == -0x10) {
                      return CONCAT31((int3)(in_EAX >> 8),1);
                    }
                  } while( true );
                }
              }
            }
          }
        }
LAB_005c5c13:
        local_164 = local_164 + 1;
      } while (local_164 != local_160);
    }
  }
LAB_005c5c24:
  return in_EAX & 0xffffff00;
}

