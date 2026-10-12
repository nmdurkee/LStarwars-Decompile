/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8dd0; label: FUN_005a8dd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a8dd0(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  float *pfVar2;
  short *psVar3;
  float fVar4;
  undefined2 uVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  float10 fVar14;
  uint local_4c;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  float local_3c;
  int local_38;
  int local_34;
  int local_30;
  float local_2c;
  float local_24;
  undefined4 local_20 [2];
  undefined4 local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4c;
  local_48 = DAT_0093b0cc;
  local_44 = DAT_0093b0d0;
  local_40 = DAT_0093b0d4;
  DAT_0095df2c = param_4;
  if (param_1 == 0) {
    _DAT_0095df48 = 0x42f00000;
    __security_check_cookie(local_4 ^ (uint)&local_4c);
    return;
  }
  DAT_0095df38 = param_2;
  if (*(int *)(param_1 + 0x5040) == 0) {
    uVar6 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x5040) = uVar6;
    *(uint *)(param_1 + 0x104) = param_2 * 0x54 + uVar6;
  }
  if (*(int *)(param_1 + 0x503c) == 0) {
    *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    if (0 < param_2) {
      iVar8 = 0;
      iVar11 = param_2;
      do {
        *(undefined4 *)(param_1 + 0x503c) = *(undefined4 *)(param_1 + 0x104);
        *(undefined4 *)(*(int *)(param_1 + 0x5040) + 0x40 + iVar8) =
             *(undefined4 *)(param_1 + 0x104);
        *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + param_3 * 0x20;
        iVar8 = iVar8 + 0x54;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  }
  iVar11 = 0;
  if (*(int *)(param_1 + 0x5044) == 0) {
    uVar6 = *(int *)(param_1 + 0x104) + 0x3fU & 0xffffffc0;
    *(uint *)(param_1 + 0x5044) = uVar6;
    *(uint *)(param_1 + 0x104) = param_2 * param_3 * 0xc0 + uVar6;
  }
  if (0 < param_2) {
    iVar9 = 0;
    iVar8 = param_2;
    do {
      puVar1 = (uint *)(*(int *)(param_1 + 0x5040) + 0x18 + iVar9);
      *puVar1 = *puVar1 & 0xfe3fffff;
      iVar9 = iVar9 + 0x54;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    if (0 < param_2) {
      local_38 = 0;
      local_30 = 0x95df3b;
      do {
        puVar12 = (undefined4 *)(*(int *)(param_1 + 0x5040) + local_38);
        puVar12[0xc] = 0x49f42400;
        *(undefined1 *)(puVar12 + 7) = (undefined1)param_3;
        iVar8 = iVar11 + 1;
        puVar12[6] = puVar12[6] ^
                     ((int)*(char *)(iVar11 + 1 + local_30) << 0x19 ^ puVar12[6]) & 0x2000000U;
        puVar12[0xd] = (int)*(short *)(&DAT_0095df34 + ((uint)puVar12[6] >> 0x19 & 1) * 2);
        local_34 = iVar8;
        local_4c = FUN_0054fa60();
        puVar12[10] = (float)(int)local_4c * 0.00015259022 + 4.0;
        _sprintf(local_14,"group%d",iVar8);
        pbVar7 = (byte *)FUN_005b2110(*(undefined4 *)(param_1 + 0x13c),local_14);
        puVar12[0xf] = pbVar7;
        if (pbVar7 == (byte *)0x0) {
          puVar12[8] = puVar12[8] & 0xfffffffb;
          iVar11 = iVar8;
        }
        else {
          puVar12[8] = puVar12[8] | 4;
          puVar12[6] = (iVar11 + (iVar11 / 5) * 3 & 7U) << 0xd | (*pbVar7 & 7) << 0x16 |
                       puVar12[6] & 0xfe3f1fff;
          *puVar12 = **(undefined4 **)(pbVar7 + 8);
          puVar12[1] = *(undefined4 *)(*(int *)(pbVar7 + 8) + 8);
          puVar12[0xe] = *(undefined4 *)(pbVar7 + 8);
          local_4c = (uint)(*(byte *)(puVar12 + 7) >> 2);
          puVar12[8] = puVar12[8] | 1;
          puVar12[3] = (float)local_4c * 0.875;
          puVar12[4] = 0x40600000;
          if (DAT_0095df2c == 0) {
            uVar5 = FUN_0054fa60();
            *(undefined2 *)(puVar12 + 5) = uVar5;
            iVar11 = FUN_0054fa60();
            puVar12[6] = puVar12[6] ^ (iVar11 / 0x5556 ^ puVar12[6]) & 0xfU;
          }
          else {
            FUN_005b3800(local_20,*(int *)(pbVar7 + 8),*(int *)(pbVar7 + 8) + 0xc);
            uVar5 = FUN_005be2d0(local_20[0],local_18);
            *(undefined2 *)(puVar12 + 5) = uVar5;
            puVar12[6] = puVar12[6] & 0xfffffff1 | 1;
          }
          FUN_005a8960();
          uVar6 = puVar12[6];
          uVar10 = uVar6 & 0xf;
          if (uVar10 == 0) {
LAB_005a90dd:
            puVar12[6] = uVar6 & 0xffffff3f | 0x30;
          }
          else if (uVar10 == 1) {
            puVar12[6] = uVar6 & 0xffffff0f;
            local_4c = FUN_0054fa60();
            puVar12[9] = (float)(int)local_4c * 0.00015259022;
          }
          else if (uVar10 == 2) goto LAB_005a90dd;
          puVar12[6] = puVar12[6] & 0xffffff3f | 0x30;
          local_48 = *(undefined4 *)puVar12[0xe];
          local_40 = *(undefined4 *)(puVar12[0xe] + 8);
          local_44 = 10.0;
          fVar14 = (float10)FUN_005506f0(0,&local_48,0x40a00000,0xffffffff);
          puVar12[0xc] = (float)fVar14;
          if ((float)fVar14 == 2e+06) {
            psVar3 = (short *)puVar12[0xf];
            iVar11 = 0;
            puVar12[0xc] = 0;
            if (0 < *psVar3) {
              iVar8 = 0;
              do {
                pfVar2 = (float *)(*(int *)(psVar3 + 4) + 4 + iVar8);
                iVar11 = iVar11 + 1;
                iVar8 = iVar8 + 0xc;
                puVar12[0xc] = *pfVar2 + (float)puVar12[0xc];
              } while (iVar11 < *(short *)puVar12[0xf]);
            }
            fVar4 = (float)puVar12[0xc] / (float)(int)*psVar3;
          }
          else {
            fVar4 = 2e+06;
          }
          puVar12[0xc] = fVar4;
          local_44 = (float)puVar12[0xc];
          local_4c = 0;
          if (*(char *)(puVar12 + 7) != '\0') {
            iVar11 = 0;
            do {
              uVar6 = local_4c;
              iVar8 = FUN_0054fa60();
              pbVar7 = (byte *)(puVar12[0x10] + 1 + iVar11);
              *pbVar7 = *pbVar7 ^ (((((char)(iVar8 / 0x5556) + (char)(iVar8 >> 0x1f)) -
                                    (char)((longlong)iVar8 * 0x2fffa001 >> 0x3f)) + '\x01') * '\x10'
                                  ^ *pbVar7) & 0x30;
              pbVar7 = (byte *)(puVar12[0x10] + 1 + iVar11);
              *pbVar7 = *pbVar7 & 0xf3;
              *(undefined1 *)(puVar12[0x10] + 3 + iVar11) = 6;
              if (((byte)puVar12[6] & 0xf) == 1) {
                *(undefined4 *)(puVar12[0x10] + 8 + iVar11) = 0;
              }
              else {
                local_3c = (1.0 / (float)*(byte *)(puVar12 + 7)) * (float)(int)local_4c;
                *(float *)(puVar12[0x10] + 8 + iVar11) = local_3c;
                *(undefined2 *)(puVar12[0x10] + 4 + iVar11) = *(undefined2 *)(puVar12 + 5);
              }
              *(float *)(puVar12[0x10] + iVar11 + 0x14) =
                   *(float *)(puVar12[0x10] + 0xc + iVar11) + *(float *)puVar12[0xe];
              local_48 = *(undefined4 *)(puVar12[0x10] + 0x14 + iVar11);
              *(float *)(puVar12[0x10] + iVar11 + 0x1c) =
                   *(float *)(puVar12[0xe] + 8) + *(float *)(puVar12[0x10] + iVar11 + 0x10);
              local_40 = *(undefined4 *)(puVar12[0x10] + 0x1c + iVar11);
              if ((float)puVar12[0xc] == 2e+06) {
                local_44 = 10.0;
                fVar14 = (float10)FUN_005506f0(0,&local_48,0x40a00000,0xffffffff);
                local_44 = (float)fVar14;
              }
              *(float *)(puVar12[0x10] + 0x18 + iVar11) = local_44;
              local_4c = uVar6 + 1;
              iVar11 = iVar11 + 0x20;
            } while ((int)local_4c < (int)(uint)*(byte *)(puVar12 + 7));
          }
          puVar13 = (undefined1 *)puVar12[0x10];
          uVar6 = 0;
          iVar11 = local_34;
          if (*(char *)(puVar12 + 7) != '\0') {
            do {
              *puVar13 = (char)uVar6;
              iVar11 = (uVar6 & 0xff) * 0x20 + puVar12[0x10];
              local_2c = *(float *)(puVar13 + 0x14) -
                         (*(float *)(iVar11 + 0xc) + *(float *)puVar12[0xe]);
              local_24 = *(float *)(puVar13 + 0x1c) -
                         (((float *)puVar12[0xe])[2] + *(float *)(iVar11 + 0x10));
              uVar5 = FUN_005be2d0(local_2c,local_24);
              *(undefined2 *)(puVar12[0x10] + 6) = uVar5;
              uVar6 = uVar6 + 1;
              puVar13 = puVar13 + 0x20;
              iVar11 = local_34;
            } while ((int)uVar6 < (int)(uint)*(byte *)(puVar12 + 7));
          }
        }
        local_38 = local_38 + 0x54;
      } while (iVar11 < DAT_0095df38);
    }
  }
  _DAT_0095df48 = 0x42f00000;
  __security_check_cookie(local_4 ^ (uint)&local_4c);
  return;
}

