/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ed910; label: FUN_004ed910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ed910(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = DAT_0088aaf0;
  if ((DAT_0087a7f0 != 0) && (DAT_0088aad0 == 4)) {
    if (*(int *)(DAT_0087a7f0 + 0xcd0) == 0) {
      if (DAT_0088aaec != 0) {
        DAT_0088aaec = 0;
        *(undefined4 *)(param_1 + 0x50cc) = 0;
        *(undefined4 *)(param_1 + 0x50d0) = 0;
      }
    }
    else {
      bVar5 = DAT_0088aaec == 0;
      *(undefined4 *)(param_1 + 0x50cc) = 4;
      *(int **)(param_1 + 0x50d0) = &DAT_0088a638;
      uVar4 = DAT_0088aaf0;
      if (bVar5) {
        DAT_0088aaec = 1;
      }
      if (DAT_0088aaf0 == 0) {
        if ((*(byte *)(DAT_0087a7f0 + 0xeec) & 8) != 0) {
          *(uint *)(DAT_0087a7f0 + 0xeec) = *(uint *)(DAT_0087a7f0 + 0xeec) & 0xfffffff7;
        }
      }
      else if (-1 < *(char *)(DAT_0087a7f0 + 0xe3f)) {
        DAT_0088aaf0 = DAT_0088aaf0 - 1;
        FUN_005cfc00(&DAT_0087aad8 + DAT_0088aaf0 * 3,1);
        FUN_005cfc00(&DAT_0087ab38 + DAT_0088aaf0 * 0xc,0);
        bVar1 = *(byte *)(*DAT_0087a96c + 0x62);
        uVar4 = DAT_0088aaf0;
        if ((bVar1 & 2) != 0) {
          *(byte *)(*DAT_0087a96c + 0x62) = bVar1 & 0xfd;
          uVar4 = DAT_0088aaf0;
        }
      }
    }
    if (DAT_0088aaf4 == 0) {
      if (((uVar4 < 8) && (DAT_0087a96c != (int *)0x0)) &&
         (iVar2 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,0,0), iVar2 != 0)) {
        _DAT_0088aaf8 = 0.0;
        DAT_0088aaf4 = 1;
      }
    }
    else {
      _DAT_0088aaf8 = _DAT_0088aaf8 - _DAT_00925018;
      if (_DAT_0088aaf8 <= 0.0) {
        *(uint *)(DAT_0087a7f0 + 0xeec) = *(uint *)(DAT_0087a7f0 + 0xeec) | 8;
        FUN_005cfc00(&DAT_0087aad8 + uVar4 * 3,0);
        FUN_005cfc00(&DAT_0087ab38 + DAT_0088aaf0 * 0xc,1);
        uVar3 = FUN_005cf9e0(&DAT_0087ab38 + DAT_0088aaf0 * 0xc);
        FUN_00681f40("imp_c3po_magnet_drop",uVar3);
        DAT_0088aaf0 = DAT_0088aaf0 + 1;
        if (DAT_0088aaf0 == 8) {
          DAT_0088aaf4 = 0;
          uVar3 = FUN_005cf9e0(&DAT_0087ab98);
          FUN_00681f40("env_magnet_on",uVar3);
        }
        else {
          _DAT_0088aaf8 = 0.25;
        }
      }
    }
  }
  if (DAT_0088a598 == 0) {
    if ((DAT_0088a638 == 0) || ((*(uint *)(DAT_0088a638 + 0x94) & 0x4000) != 0)) {
      uVar3 = FUN_005cf9e0(&DAT_0087ab98);
      FUN_00681f40("ffield",uVar3);
    }
    else {
      uVar3 = FUN_005cf9e0(&DAT_0087ab98);
      FUN_00681f40("ffieldoff",uVar3);
      DAT_0088a598 = 1;
    }
  }
  if (DAT_0088a59c == 0) {
    if ((DAT_0088a63c != 0) && ((*(uint *)(DAT_0088a63c + 0x94) & 0x4000) == 0)) {
      uVar3 = FUN_005cf9e0(&DAT_0087aba4);
      FUN_00681f40("ffieldoff",uVar3);
      DAT_0088a59c = 1;
      return;
    }
    uVar3 = FUN_005cf9e0(&DAT_0087aba4);
    FUN_00681f40("ffield",uVar3);
  }
  return;
}

