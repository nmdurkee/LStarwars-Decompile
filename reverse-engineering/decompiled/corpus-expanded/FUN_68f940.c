/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x68f940; label: FUN_0068f940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068f940(uint *param_1,float *param_2,char *param_3,undefined2 param_4,float param_5,
                 float param_6,float param_7,int param_8,int param_9,undefined4 param_10)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  float local_14;
  float local_10;
  
  DAT_02947bd8 = 0;
  DAT_02947bd9 = 0;
  DAT_02947bda = 0;
  DAT_02947bdb = 0;
  _DAT_0292125c = 0;
  DAT_0292fb68 = 0xffffffff;
  DAT_0292fdc8 = 0xffffffff;
  DAT_02947d88 = 0;
  DAT_0292125e = 0;
  DAT_02921834 = 0;
  _DAT_02921258 = 0;
  DAT_02961fdc = 0xffff;
  if (DAT_0292fc68 == (int *)0x0) {
    DAT_02962b38 = 0;
    return;
  }
  iVar6 = 0;
  _DAT_02947b68 = 0.0;
  piVar8 = DAT_0292fc68 + 0x66;
  do {
    if ((char *)*piVar8 == param_3) {
      DAT_02947c74 = DAT_0292fc68 + (iVar6 * 3 + 0x33) * 2;
      goto LAB_0068f9d5;
    }
    iVar6 = iVar6 + 1;
    piVar8 = piVar8 + 6;
  } while (iVar6 < 0x40);
  DAT_02947c74 = (int *)0x0;
LAB_0068f9d5:
  DAT_02948edc = 0;
  puVar7 = (uint *)FUN_006de8d0(0x948);
  puVar7[0x17] = (uint)param_7;
  DAT_0292186c = puVar7;
  puVar7[0x18] = (uint)(param_7 * param_7);
  if (param_7 == 0.0) {
    local_10 = 0.0;
  }
  else {
    local_10 = 1.0 / param_7;
  }
  fVar3 = 0.0;
  puVar7[0x19] = (uint)local_10;
  puVar7[0x1a] = (uint)(local_10 * local_10);
  puVar7[0x14] = (uint)param_6;
  if (param_6 != 0.0) {
    fVar3 = 1.0 / param_6;
  }
  puVar7[0x16] = (uint)fVar3;
  DAT_02961fdc = 0xffff;
  puVar7[0x15] = (uint)(param_6 * param_6);
  uVar2 = *param_1;
  puVar7[7] = uVar2;
  puVar7[1] = uVar2;
  fVar3 = param_6 * param_7 + (float)param_1[1];
  puVar7[8] = (uint)fVar3;
  puVar7[2] = (uint)fVar3;
  uVar2 = param_1[2];
  puVar7[9] = uVar2;
  puVar7[3] = uVar2;
  fVar3 = *param_2;
  puVar7[10] = (uint)fVar3;
  puVar7[4] = (uint)fVar3;
  fVar3 = param_2[1];
  puVar7[0xb] = (uint)fVar3;
  puVar7[5] = (uint)fVar3;
  fVar3 = param_2[2];
  *puVar7 = *puVar7 & 0xfffffffe;
  puVar7[0xc] = (uint)fVar3;
  puVar7[6] = (uint)fVar3;
  puVar7[0xe] = (uint)param_5;
  puVar7[0x28] = 0x3ba3d70a;
  *(undefined2 *)((int)puVar7 + 0x36) = param_4;
  puVar7[0x10] = (uint)param_3;
  puVar7[0x29] = 0x36a7c5ac;
  *(undefined1 *)(puVar7 + 0xd) = 0;
  FUN_00675f60(1,param_10,-(param_9 != 0) & 0x40);
  puVar7 = DAT_0292186c;
  if ((((param_3[1] != '\0') && (ABS(*param_2) < param_5)) && (ABS(param_2[1]) < param_5)) &&
     ((ABS(param_2[2]) < param_5 && (DAT_0292119c == 0)))) {
    FUN_006de960();
    _DAT_02921258 = _DAT_02921258 | 2;
    DAT_0292fdb8 = 0;
    DAT_0292fdbc = 0x3f800000;
    DAT_02947c60 = 0;
    DAT_02962b38 = 0;
    DAT_0292fdc0 = 0;
    return;
  }
  DAT_0292186c[8] = (uint)((float)DAT_0292186c[0x19] * (float)DAT_0292186c[8]);
  puVar7[0xb] = (uint)((float)puVar7[0x19] * (float)puVar7[0xb]);
  *param_3 = '\0';
  param_3[1] = '\0';
  local_10 = (float)FUN_0068ee40(6,param_2);
  do {
    FUN_0066f8f0();
    FUN_00675240();
    FUN_00678410();
    FUN_0067a3b0();
    puVar7 = DAT_0292186c;
    if ((((byte)DAT_0292186c[0x22] < 0x11) || ((short)DAT_0292186c[0x1b] == -1)) ||
       (*(int *)(*DAT_0292fc68 + 0x2c + (short)DAT_0292186c[0x1b] * 0x38) != 1)) {
LAB_0068fcd4:
      puVar7 = DAT_0292186c;
      local_10 = (float)((int)local_10 + -1);
      if (((char)DAT_0292186c[0x22] != '\0') && (-1 < (short)DAT_0292186c[0x1b])) {
        DAT_0292fdb8 = DAT_0292186c[0x2d];
        DAT_0292fdbc = DAT_0292186c[0x2e];
        DAT_0292fdc0 = DAT_0292186c[0x2f];
        uVar2 = DAT_0292186c[0x24];
        if (uVar2 == 0) {
          local_14 = 0.707;
        }
        else {
          local_14 = *(float *)(uVar2 + 0x50) * (float)DAT_0292186c[0x2c] +
                     *(float *)(uVar2 + 0x48) * (float)DAT_0292186c[0x2a] +
                     *(float *)(uVar2 + 0x4c) * (float)DAT_0292186c[0x2b];
        }
        iVar6 = (short)DAT_0292186c[0x1b] * 0x38;
        if (*(int *)(*DAT_0292fc68 + 0x2c + iVar6) == 1) {
          if ((((byte)DAT_0292186c[0x22] & 0xf) < 2) || (0.95 <= local_14)) {
            local_14 = 0.707;
          }
          else {
            local_14 = 0.98;
          }
        }
        else if (*(char *)((int)DAT_0292186c + 0x35) == '\0') {
          local_14 = -1.1;
        }
        else {
          local_14 = 1.1;
        }
        if (_DAT_02947c0c != 0.0) {
          local_14 = _DAT_02947c0c;
        }
        if ((DAT_0292186c[0x22] & 0xf) != 1) {
          local_14 = 0.707;
        }
        if (((uVar2 != 0) && (-1 < (short)DAT_0292186c[0x1b])) &&
           ((*(byte *)(uVar2 + 99) & 0x7c) == 4)) {
          DAT_0292186c[7] = (uint)((float)DAT_0292186c[7] + (float)DAT_0292186c[0x2a] * 0.001);
          puVar7[9] = (uint)((float)puVar7[0x2c] * 0.001 + (float)puVar7[9]);
          local_14 = 1.1;
        }
        if ((local_14 < (float)puVar7[0x2e] != (local_14 == (float)puVar7[0x2e])) &&
           (iVar6 = *DAT_0292fc68 + iVar6, *(int *)(iVar6 + 0x2c) == 1)) {
          puVar1 = (uint *)(*(short *)(iVar6 + 0x30) * 0x6c + 0x4c + DAT_0292fc68[0x1a]);
          *puVar1 = *puVar1 | 2;
        }
      }
      if (DAT_02947c60 == 0) {
        FUN_006786f0(param_1,param_2,param_3);
      }
      else {
        iVar6 = FUN_0067ac40();
        puVar7 = DAT_0292186c;
        if (iVar6 != 0) {
          FUN_006786f0(param_1,param_2,param_3);
          puVar7 = DAT_0292186c;
        }
      }
      _DAT_02947b5c = (float)puVar7[7] - (float)puVar7[0x2a] * (float)puVar7[0x14];
      _DAT_02947b60 =
           ((float)puVar7[8] - (float)puVar7[0x2b] * (float)puVar7[0x14]) * (float)puVar7[0x17];
      _DAT_02947b64 = (float)puVar7[9] - (float)puVar7[0x2c] * (float)puVar7[0x14];
      _DAT_02947b68 = (float)(byte)puVar7[0x22];
    }
    else {
      local_10 = (float)((int)local_10 + -1);
      FUN_00678340();
      fVar3 = (float)puVar7[7];
      fVar4 = (float)puVar7[8];
      fVar5 = (float)puVar7[9];
      iVar6 = FUN_00679310(param_2);
      if ((iVar6 != 0) ||
         (((puVar7 = DAT_0292186c, (float)DAT_0292186c[7] == fVar3 &&
           ((float)DAT_0292186c[8] == fVar4)) && ((float)DAT_0292186c[9] == fVar5))))
      goto LAB_0068fcd4;
    }
    if ((char)puVar7[0x22] == '\0') goto LAB_0068ffe5;
    _DAT_0292125c = 2 - (ushort)(puVar7[0x24] != 0);
    _DAT_02920d70 = (float)puVar7[7] - (float)puVar7[0x2a] * (float)puVar7[0x14];
    _DAT_02920d74 =
         ((float)puVar7[8] - (float)puVar7[0x2b] * (float)puVar7[0x14]) * (float)puVar7[0x17];
    _DAT_02920d78 = (float)puVar7[9] - (float)puVar7[0x2c] * (float)puVar7[0x14];
    _DAT_02948ea0 = puVar7[0x2d];
    _DAT_02948ea4 = puVar7[0x2e];
    _DAT_02948ea8 = puVar7[0x2f];
    if ((char)puVar7[0x22] == '\0') goto LAB_0068ffe5;
  } while ((0 < (int)local_10) &&
          (fVar3 = (float)puVar7[0x2b] * (float)puVar7[0x2b] +
                   (float)puVar7[0x2a] * (float)puVar7[0x2a] +
                   (float)puVar7[0x2c] * (float)puVar7[0x2c], fVar3 < 1.5 != (fVar3 == 1.5)));
  if ((char)puVar7[0x22] == '\0') {
LAB_0068ffe5:
    if ((((3 < (int)local_10) && (*param_3 == '\0')) && (param_3[1] == '\0')) && (param_8 != 0)) {
      puVar7[7] = *param_1;
      puVar7[8] = (uint)((float)puVar7[0x19] * (float)param_1[1] + (float)puVar7[0x14] + 0.003);
      puVar7[9] = param_1[2];
      puVar7[10] = 0;
      puVar7[0xb] = 0xbbe56042;
      puVar7[0xc] = 0;
      FUN_0066f8f0();
      FUN_00675240();
      if (((char)DAT_0292186c[0x22] != '\0') &&
         (((short)DAT_0292186c[0x1b] < 0 || ((*(byte *)(DAT_0292186c[0x24] + 99) & 0x7c) != 4)))) {
        FUN_00678410();
        puVar7 = DAT_0292186c;
        DAT_0292fdb8 = DAT_0292186c[0x2d];
        DAT_0292fdbc = DAT_0292186c[0x2e];
        DAT_0292fdc0 = DAT_0292186c[0x2f];
        DAT_0292186c[4] = (uint)*param_2;
        puVar7[5] = (uint)param_2[1];
        puVar7[6] = (uint)param_2[2];
        FUN_006786f0(param_1,param_2,param_3);
        *param_1 = puVar7[7];
        param_1[1] = (uint)((float)puVar7[8] * (float)puVar7[0x17] -
                           (float)puVar7[0x14] * (float)puVar7[0x17]);
        param_1[2] = puVar7[9];
        *param_2 = (float)puVar7[4];
        param_2[1] = (float)puVar7[5];
        param_2[2] = (float)puVar7[6];
      }
    }
  }
  else {
    *param_1 = puVar7[7];
    param_1[1] = (uint)((float)puVar7[8] * (float)puVar7[0x17] -
                       (float)puVar7[0x14] * (float)puVar7[0x17]);
    param_1[2] = puVar7[9];
  }
  FUN_006de960();
  DAT_02947c60 = 0;
  DAT_02962b38 = 0;
  return;
}

