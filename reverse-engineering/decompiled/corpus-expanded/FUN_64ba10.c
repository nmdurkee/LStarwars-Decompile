/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64ba10; label: FUN_0064ba10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064ba10(char *param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  short *psVar9;
  undefined1 *puVar10;
  float10 fVar11;
  int local_18;
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_18;
  FUN_006216f0(param_1,0x10);
  if (param_2 < 6) {
    if (param_2 < 2) {
      param_1[0xa0] = '\0';
    }
    else {
      cVar1 = FUN_006218c0();
      param_1[0xa0] = cVar1;
    }
    param_1[0xa1] = -1;
    param_1[0xa2] = -1;
    param_1[0xa3] = -1;
    param_1[0xa4] = -1;
    param_1[0xa5] = -1;
    param_1[0xa6] = -1;
    param_1[0xa7] = -1;
  }
  else {
    iVar8 = 0;
    do {
      cVar1 = FUN_006218c0();
      param_1[iVar8 + 0xa0] = cVar1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
  }
  if (5 < param_2) {
    local_18 = 0;
    psVar9 = (short *)(param_1 + 0x90);
    pcVar7 = param_1;
    do {
      pcVar7 = pcVar7 + 0x10;
      FUN_006216f0(pcVar7,0x10);
      *psVar9 = -1;
      if (param_1[local_18 + 0xa0] == '\0') {
        iVar8 = 0;
        do {
          if ((&DAT_0291f688)[iVar8] == param_3) {
            sVar2 = FUN_006488e0(pcVar7,(&DAT_029208d0)[iVar8]);
            *psVar9 = sVar2;
          }
          if (*psVar9 != -1) {
            param_1[local_18 + 0xa8] = (char)iVar8;
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x20);
LAB_0064bb3e:
        if (*psVar9 == -1) goto LAB_0064bb44;
      }
      else {
        if (param_1[local_18 + 0xa0] == '\x01') {
          iVar8 = 0;
          do {
            if ((&DAT_0291f688)[iVar8] == 0) {
              sVar2 = FUN_006488e0(pcVar7,(&DAT_029208d0)[iVar8]);
              *psVar9 = sVar2;
            }
            if (*psVar9 != -1) {
              param_1[local_18 + 0xa8] = (char)iVar8;
              break;
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < 0x20);
          goto LAB_0064bb3e;
        }
LAB_0064bb44:
        if (*pcVar7 != '\0') {
          *psVar9 = 0x270e;
        }
      }
      local_18 = local_18 + 1;
      psVar9 = psVar9 + 1;
    } while (local_18 < 8);
    goto LAB_0064bc38;
  }
  pcVar7 = param_1 + 0x10;
  FUN_006216f0(pcVar7,0x10);
  cVar1 = param_1[0xa0];
  param_1[0x90] = -1;
  param_1[0x91] = -1;
  if (cVar1 == '\0') {
    iVar8 = 0;
    do {
      if ((&DAT_0291f688)[iVar8] == param_3) {
        uVar3 = FUN_006488e0(pcVar7,(&DAT_029208d0)[iVar8]);
        *(undefined2 *)(param_1 + 0x90) = uVar3;
      }
      if (*(short *)(param_1 + 0x90) != -1) goto LAB_0064bc16;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x20);
  }
  else if (cVar1 == '\x01') {
    iVar8 = 0;
    do {
      if ((&DAT_0291f688)[iVar8] == 0) {
        uVar3 = FUN_006488e0(pcVar7,(&DAT_029208d0)[iVar8]);
        *(undefined2 *)(param_1 + 0x90) = uVar3;
      }
      if (*(short *)(param_1 + 0x90) != -1) goto LAB_0064bc16;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x20);
  }
LAB_0064bc20:
  if ((*(short *)(param_1 + 0x90) == -1) && (*pcVar7 != '\0')) {
    param_1[0x90] = '\x0e';
    param_1[0x91] = '\'';
  }
LAB_0064bc38:
  param_1[0xb0] = '\0';
  if ((*(short *)(param_1 + 0x90) != -1) && (*(short *)(param_1 + 0x90) != 9999)) {
    param_1[0xb0] = '\x01';
  }
  if ((*(short *)(param_1 + 0x92) != -1) && (*(short *)(param_1 + 0x92) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if ((*(short *)(param_1 + 0x94) != -1) && (*(short *)(param_1 + 0x94) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if ((*(short *)(param_1 + 0x96) != -1) && (*(short *)(param_1 + 0x96) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if ((*(short *)(param_1 + 0x98) != -1) && (*(short *)(param_1 + 0x98) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if ((*(short *)(param_1 + 0x9a) != -1) && (*(short *)(param_1 + 0x9a) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if ((*(short *)(param_1 + 0x9c) != -1) && (*(short *)(param_1 + 0x9c) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if ((*(short *)(param_1 + 0x9e) != -1) && (*(short *)(param_1 + 0x9e) != 9999)) {
    param_1[0xb0] = param_1[0xb0] + '\x01';
  }
  if (param_2 < 6) {
    param_1[0xb1] = '\0';
  }
  else {
    cVar1 = FUN_006218c0();
    param_1[0xb1] = cVar1;
  }
  fVar11 = (float10)1;
  if (param_2 < 0x10) {
    *(float *)(param_1 + 0xb4) = (float)fVar11;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0xb4) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0xb8) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xbc) = (float)fVar11;
  if (param_2 < 0xe) {
    fVar11 = (float10)0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0xc0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xc4) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 200) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xcc) = (float)fVar11;
  if (param_2 < 8) {
    fVar11 = (float10)0.75;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0xd0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xd4) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xd8) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xdc) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xe0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xe4) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xe8) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xec) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xf0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xf4) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xf8) = (float)fVar11;
  if (param_2 < 0xd) {
    sVar2 = FUN_00621860();
    *(int *)(param_1 + 0xfc) = (int)sVar2;
    sVar2 = FUN_00621860();
    *(int *)(param_1 + 0x100) = (int)sVar2;
    sVar2 = FUN_00621860();
    *(int *)(param_1 + 0x104) = (int)sVar2;
    sVar2 = FUN_00621860();
    *(int *)(param_1 + 0x108) = (int)sVar2;
    sVar2 = FUN_00621860();
    *(int *)(param_1 + 0x10c) = (int)sVar2;
    sVar2 = FUN_00621860();
    *(int *)(param_1 + 0x110) = (int)sVar2;
  }
  else {
    uVar4 = FUN_006217e0();
    *(undefined4 *)(param_1 + 0xfc) = uVar4;
    uVar4 = FUN_006217e0();
    *(undefined4 *)(param_1 + 0x100) = uVar4;
    uVar4 = FUN_006217e0();
    *(undefined4 *)(param_1 + 0x104) = uVar4;
    uVar4 = FUN_006217e0();
    *(undefined4 *)(param_1 + 0x108) = uVar4;
    uVar4 = FUN_006217e0();
    *(undefined4 *)(param_1 + 0x10c) = uVar4;
    uVar4 = FUN_006217e0();
    *(undefined4 *)(param_1 + 0x110) = uVar4;
  }
  uVar5 = FUN_00621820();
  *(uint *)(param_1 + 0x114) = uVar5;
  if (*(short *)(param_1 + 0x90) == 9999) {
    *(uint *)(param_1 + 0x114) = uVar5 | 0x10;
  }
  if (param_2 < 9) {
    if (param_2 < 5) {
      if (param_2 < 3) {
        fVar11 = (float10)60.0;
        param_1[0x118] = -1;
        param_1[0x119] = -1;
        param_1[0x11a] = -1;
        param_1[0x11b] = -1;
        *(float *)(param_1 + 0x120) = (float)fVar11;
        param_1[0x11c] = -1;
        param_1[0x11d] = -1;
        param_1[0x11e] = -1;
        param_1[0x11f] = -1;
        param_1[0x128] = -1;
        param_1[0x129] = -1;
        param_1[0x12a] = -1;
        param_1[299] = -1;
      }
      else {
        param_1[0x118] = -1;
        param_1[0x119] = -1;
        param_1[0x11a] = -1;
        param_1[0x11b] = -1;
        param_1[0x11c] = -1;
        param_1[0x11d] = -1;
        param_1[0x11e] = -1;
        param_1[0x11f] = -1;
        param_1[0x128] = -1;
        param_1[0x129] = -1;
        param_1[0x12a] = -1;
        param_1[299] = -1;
        cVar1 = FUN_006218c0();
        FUN_006216f0(local_14,0x10);
        if (cVar1 == '\0') {
          if (DAT_008101b8 == -1) {
            uVar4 = FUN_00658570(local_14);
            *(undefined4 *)(param_1 + 0x118) = uVar4;
          }
          else {
            uVar4 = FUN_00658490(local_14,DAT_008101b8);
            *(undefined4 *)(param_1 + 0x118) = uVar4;
          }
        }
        else if (cVar1 == '\x01') {
          if (DAT_008101b8 == -1) {
            uVar4 = FUN_00658570(local_14);
          }
          else {
            uVar4 = FUN_00658490(local_14,DAT_008101b8);
          }
          *(undefined4 *)(param_1 + 0x128) = uVar4;
        }
        fVar11 = (float10)FUN_006217a0();
        *(float *)(param_1 + 0x120) = (float)fVar11;
        fVar11 = (float10)60.0;
      }
    }
    else {
      FUN_006216f0(local_14,0x10);
      if (DAT_008101b8 == -1) {
        uVar4 = FUN_00658570(local_14);
      }
      else {
        uVar4 = FUN_00658490(local_14,DAT_008101b8);
      }
      *(undefined4 *)(param_1 + 0x118) = uVar4;
      param_1[0x11c] = -1;
      param_1[0x11d] = -1;
      param_1[0x11e] = -1;
      param_1[0x11f] = -1;
      FUN_006216f0(local_14,0x10);
      if (DAT_008101b8 == -1) {
        uVar4 = FUN_00658570(local_14);
      }
      else {
        uVar4 = FUN_00658490(local_14,DAT_008101b8);
      }
      *(undefined4 *)(param_1 + 0x128) = uVar4;
      fVar11 = (float10)FUN_006217a0();
      *(float *)(param_1 + 0x120) = (float)fVar11;
      fVar11 = (float10)60.0;
    }
  }
  else {
    FUN_006216f0(local_14,0x10);
    if (DAT_008101b8 == -1) {
      uVar4 = FUN_00658570(local_14);
    }
    else {
      uVar4 = FUN_00658490(local_14,DAT_008101b8);
    }
    *(undefined4 *)(param_1 + 0x118) = uVar4;
    FUN_006216f0(local_14,0x10);
    if (DAT_008101b8 == -1) {
      uVar4 = FUN_00658570(local_14);
    }
    else {
      uVar4 = FUN_00658490(local_14,DAT_008101b8);
    }
    *(undefined4 *)(param_1 + 0x11c) = uVar4;
    FUN_006216f0(local_14,0x10);
    if (DAT_008101b8 == -1) {
      uVar4 = FUN_00658570(local_14);
    }
    else {
      uVar4 = FUN_00658490(local_14,DAT_008101b8);
    }
    *(undefined4 *)(param_1 + 0x128) = uVar4;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x120) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  iVar8 = -1;
  *(float *)(param_1 + 0x124) = (float)fVar11;
  if (param_2 < 4) {
    param_1[300] = -1;
    param_1[0x12d] = -1;
    param_1[0x12e] = -1;
    param_1[0x12f] = -1;
    param_1[0x144] = -1;
    param_1[0x145] = -1;
    param_1[0x146] = -1;
    param_1[0x147] = -1;
  }
  else {
    FUN_006216f0(local_14,0x10);
    if (DAT_008101b8 == -1) {
      uVar4 = FUN_00658570(local_14);
    }
    else {
      uVar4 = FUN_00658490(local_14,DAT_008101b8);
    }
    *(undefined4 *)(param_1 + 0x144) = uVar4;
    FUN_006216f0(local_14,0x10);
    if (DAT_008101b8 == -1) {
      uVar4 = FUN_00658570(local_14);
      *(undefined4 *)(param_1 + 300) = uVar4;
    }
    else {
      uVar4 = FUN_00658490(local_14,DAT_008101b8);
      *(undefined4 *)(param_1 + 300) = uVar4;
    }
  }
  if (param_2 < 0xc) {
    param_1[0x134] = '\0';
  }
  else {
    pcVar7 = param_1 + 0x134;
    FUN_006216f0(pcVar7,0x10);
    if ((pcVar7 != (char *)0x0) && (*pcVar7 != '\0')) {
      iVar8 = 0;
      puVar10 = &DAT_02913a58;
      do {
        iVar6 = FUN_004f8b80(pcVar7,puVar10,0x10);
        if (iVar6 == 0) goto LAB_0064c1f3;
        puVar10 = puVar10 + 0x178;
        iVar8 = iVar8 + 1;
      } while ((int)puVar10 < 0x291f658);
      iVar8 = -1;
    }
  }
LAB_0064c1f3:
  *(int *)(param_1 + 0x130) = iVar8;
  if (param_2 < 7) {
    iVar8 = 0;
    pcVar7 = param_1 + 0x148;
    do {
      pcVar7[0] = -1;
      pcVar7[1] = -1;
      pcVar7[2] = -1;
      pcVar7[3] = -1;
      param_1[iVar8 + 0x158] = '\0';
      iVar8 = iVar8 + 1;
      pcVar7 = pcVar7 + 4;
    } while (iVar8 < 4);
  }
  else {
    pcVar7 = param_1 + 0x148;
    iVar8 = 4;
    do {
      FUN_006216f0(local_14,0x10);
      uVar4 = FUN_00650e40(local_14,0x10);
      *(undefined4 *)pcVar7 = uVar4;
      pcVar7 = pcVar7 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    iVar8 = 0;
    do {
      cVar1 = FUN_006218c0();
      param_1[iVar8 + 0x158] = cVar1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  if (param_2 < 10) {
    fVar11 = (float10)25.0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x15c) = (float)fVar11;
  if (param_2 < 0xf) {
    param_1[0x160] = '\0';
    param_1[0x161] = '\0';
    param_1[0x162] = -0x80;
    param_1[0x163] = '?';
    param_1[0x164] = '\0';
    param_1[0x165] = '\0';
    param_1[0x166] = -0x80;
    param_1[0x167] = '?';
    param_1[0x168] = '\0';
    param_1[0x169] = '\0';
    param_1[0x16a] = -0x80;
    param_1[0x16b] = '?';
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x160) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x164) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x168) = (float)fVar11;
  }
  param_1[0x170] = '\0';
  param_1[0x171] = '\0';
  param_1[0x172] = -0x80;
  param_1[0x173] = '?';
  param_1[0x174] = '\0';
  param_1[0x175] = '\0';
  param_1[0x176] = '\0';
  param_1[0x177] = '\0';
  __security_check_cookie(local_4 ^ (uint)&local_18);
  return;
LAB_0064bc16:
  param_1[0xa8] = (char)iVar8;
  goto LAB_0064bc20;
}

