/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64c300; label: FUN_0064c300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064c300(undefined4 param_1,char param_2,int param_3,int param_4)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  float10 fVar11;
  int local_188;
  int local_184;
  int local_180;
  undefined1 local_17c [376];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_188;
  if (param_2 == '\0') {
    local_188 = 0;
  }
  else {
    local_188 = 1;
    while (*(int *)(&DAT_0292089c + local_188 * 4) != 0) {
      local_188 = local_188 + 1;
      if (7 < local_188) {
        __security_check_cookie(local_4 ^ (uint)&local_188);
        return;
      }
    }
    if (local_188 == -1) {
      __security_check_cookie(local_4 ^ (uint)&local_188);
      return;
    }
  }
  iVar3 = 0;
  iVar8 = 0;
  if (0 < param_4) {
    do {
      iVar10 = *(int *)(param_3 + iVar8 * 4);
      if (iVar10 != 0) {
        iVar4 = (&DAT_029208d0)[iVar3];
        while (iVar4 != 0) {
          if (0x1f < iVar3) goto LAB_0064c3d6;
          iVar3 = iVar3 + 1;
          iVar4 = (&DAT_029208d0)[iVar3];
        }
        if (iVar3 < 0x20) {
          (&DAT_029208d0)[iVar3] = iVar10;
          (&DAT_0291f688)[iVar3] = local_188;
        }
      }
LAB_0064c3d6:
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_4);
  }
  FUN_006211c0(1);
  iVar3 = FUN_00621270(param_1,0);
  if (iVar3 != 0) {
    FUN_006211b0(1);
    iVar3 = FUN_006217e0();
    local_180 = iVar3;
    if ((iVar3 < 1) || (0x10 < iVar3)) {
      FUN_006213e0();
    }
    else {
      iVar4 = FUN_006217e0();
      iVar10 = 0;
      iVar8 = 0;
      if (0x80 < DAT_02920a94 + iVar4) {
        iVar8 = DAT_02920a94 + iVar4 + -0x80;
        iVar4 = iVar4 - iVar8;
      }
      if (0 < iVar4) {
        do {
          local_184 = iVar4;
          pcVar5 = &DAT_02913a58 + iVar10 * 0x178;
          cVar1 = (&DAT_02913a58)[iVar10 * 0x178];
          while (cVar1 != '\0') {
            pcVar5 = pcVar5 + 0x178;
            iVar10 = iVar10 + 1;
            cVar1 = *pcVar5;
          }
          iVar3 = iVar10 * 0x178;
          FUN_0064ba10(&DAT_02913a58 + iVar3,local_180,local_188);
          if ((&DAT_02913a58)[iVar3] != '\0') {
            DAT_02920a94 = DAT_02920a94 + 1;
            (&DAT_02913b0a)[iVar3] = (undefined1)local_188;
            (&DAT_02913b0b)[iVar3] = param_2;
          }
          iVar4 = local_184 + -1;
        } while (local_184 + -1 != 0);
        local_184 = 0;
        iVar3 = local_180;
      }
      if (0 < iVar8) {
        do {
          FUN_0064ba10(local_17c,iVar3,local_188);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      iVar8 = FUN_006217e0();
      iVar3 = 0;
      if (0x28 < DAT_02920a98 + iVar8) {
        iVar8 = 0x28 - DAT_02920a98;
      }
      if (0 < iVar8) {
        do {
          local_184 = iVar8;
          piVar9 = &DAT_0291f7b4 + iVar3 * 0x1b;
          iVar8 = (&DAT_0291f7b4)[iVar3 * 0x1b];
          while (iVar8 != -1) {
            piVar9 = piVar9 + 0x1b;
            iVar3 = iVar3 + 1;
            iVar8 = *piVar9;
          }
          iVar10 = iVar3 * 0x6c;
          fVar11 = (float10)FUN_006217a0();
          (&DAT_0291f7a8)[iVar3 * 0x1b] = (float)fVar11;
          fVar11 = (float10)FUN_006217a0();
          (&DAT_0291f7ac)[iVar3 * 0x1b] = (float)fVar11;
          fVar11 = (float10)FUN_006217a0();
          (&DAT_0291f7b0)[iVar3 * 0x1b] = (float)fVar11;
          FUN_006216f0(&DAT_0291f7b8 + iVar10,0x10);
          iVar8 = local_188;
          uVar6 = FUN_0064b020(&DAT_0291f7b8 + iVar10,local_188);
          (&DAT_0291f7b4)[iVar3 * 0x1b] = uVar6;
          uVar2 = FUN_00621860();
          (&DAT_0291f7d8)[iVar3 * 0x36] = uVar2;
          uVar2 = FUN_00621860();
          (&DAT_0291f7d6)[iVar3 * 0x36] = uVar2;
          uVar2 = FUN_00621860();
          (&DAT_0291f7d4)[iVar3 * 0x36] = uVar2;
          if (local_180 < 0xb) {
            uVar2 = 0;
            (&DAT_0291f7ec)[iVar3 * 0x36] = 0;
          }
          else {
            uVar2 = FUN_00621860();
            (&DAT_0291f7ec)[iVar3 * 0x36] = uVar2;
            uVar2 = FUN_00621860();
          }
          iVar4 = (&DAT_0291f7b4)[iVar3 * 0x1b];
          (&DAT_0291f7ee)[iVar3 * 0x36] = uVar2;
          iVar7 = 0;
          (&DAT_0291f7da)[iVar10] = (char)iVar8;
          (&DAT_0291f7e4)[iVar10] = 0;
          piVar9 = &DAT_02913ba0 + iVar4 * 0x5e;
          do {
            if ((*piVar9 != -1) && ((&DAT_02913bb0)[iVar7 + iVar4 * 0x178] != '\0')) {
              (&DAT_0291f7e4)[iVar10] = 1;
              break;
            }
            iVar7 = iVar7 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar7 < 4);
          if (iVar4 != -1) {
            DAT_02920a98 = DAT_02920a98 + 1;
            FUN_0064ae50(iVar3,0);
            (&DAT_0291f7e5)[iVar10] = 1;
          }
          local_184 = local_184 + -1;
          iVar8 = local_184;
        } while (local_184 != 0);
      }
      FUN_006211b0(0);
      FUN_006213e0();
      FUN_00644000(0x3f800000);
      *(undefined4 *)(&DAT_0292089c + local_188 * 4) = 1;
      if (local_188 == 0) {
        _DAT_02913a2c = 1;
      }
      if (param_2 == '\0') {
        _DAT_0296292c = local_188;
      }
      else if (param_2 == '\x01') {
        _DAT_008109d0 = local_188;
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_188);
  return;
}

