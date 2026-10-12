/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49b330; label: FUN_0049b330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b330(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  short sVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  int local_4;
  
  iVar9 = *(int *)(PTR_DAT_00802c54 + 300);
  if (iVar9 != 0) {
    if (iVar9 == DAT_0087af84) {
      return;
    }
    if (iVar9 == DAT_0087af5c) {
      return;
    }
  }
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (cVar1 == '*') {
    fVar3 = *(float *)(param_1 + 0x784) * 0.5;
    fVar4 = fVar3 * 0.5 + fVar3;
    if ((*(uint *)(param_1 + 0xe24) & 4) != 0) {
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffffb;
      *(float *)(param_1 + 0x77c) =
           *(float *)(param_1 + 0x784) -
           (float)(int)*(short *)(param_1 + 0xe1a) * 6.1035156e-05 * fVar3 * 0.5;
    }
    fVar5 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar5;
    if (fVar5 <= 0.0) {
      iVar9 = FUN_00552020(param_1 + 0x80,
                           *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x40),0,0,0);
      iVar10 = FUN_00552020(param_1 + 0x80,
                            *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x44),0,0,1);
      if ((iVar9 == 0) && (iVar10 == 0)) {
        *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffffd;
        sVar7 = *(short *)(param_1 + 0x58) + -0x8000;
        *(short *)(param_1 + 0x27a) = sVar7;
        *(short *)(param_1 + 0x5a) = sVar7;
        *(short *)(param_1 + 0x58) = sVar7;
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        if ((*(char **)(param_1 + 0xcc4) != (char *)0x0) &&
           (iVar9 = 0, **(char **)(param_1 + 0xcc4) != '\0')) {
          iVar10 = 0x28;
          do {
            piVar13 = (int *)(iVar10 + -0x14 + *(int *)(param_1 + 0xcc4));
            *piVar13 = *piVar13 + 0x8000;
            piVar13 = (int *)(*(int *)(param_1 + 0xcc4) + iVar10);
            iVar9 = iVar9 + 1;
            *piVar13 = 0x8000 - *piVar13;
            iVar10 = iVar10 + 4;
          } while (iVar9 < (int)(uint)**(byte **)(param_1 + 0xcc4));
        }
        *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffffb;
        *(undefined4 *)(param_1 + 0xdc8) = 0x3f800000;
        *(undefined2 *)(param_1 + 0xe1a) = 0;
        *(undefined2 *)(param_1 + 0xe18) = 0;
        *(undefined2 *)(param_1 + 0xe1c) = 0;
        return;
      }
      *(float *)(param_1 + 0x77c) = _DAT_00925018;
      return;
    }
    if (fVar4 < fVar5 != (fVar4 == fVar5)) {
      uVar8 = FUN_006e6b90();
      *(undefined2 *)(param_1 + 0xe1a) = uVar8;
      return;
    }
    if (fVar5 < fVar3) {
      return;
    }
    FUN_006e6b90();
    uVar8 = FUN_006e6b90();
    *(undefined2 *)(param_1 + 0xe1a) = uVar8;
    return;
  }
  if ((cVar1 != -1) && (cVar1 != '6')) {
    return;
  }
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = FUN_0041a4d0(param_1);
  }
  if (((*(char *)(param_1 + 0x7b5) != '6') || (*(short *)(param_1 + 0xe1a) < 0)) ||
     (local_4 = 1, 0x4000 < *(short *)(param_1 + 0xe1a))) {
    local_4 = 0;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) || (0.0 < *(float *)(param_1 + 0xd48))) {
LAB_0049b6a1:
    if ((*(char *)(param_1 + 0xe3c) != '\0') && (iVar9 != 0)) {
      cVar1 = *(char *)(iVar9 + 0x7b5);
      if (cVar1 == '*') {
        return;
      }
      if (cVar1 == '6') {
        return;
      }
      if (cVar1 == ':') {
        return;
      }
    }
  }
  else if (*(char *)(param_1 + 0xe3c) != '\0') {
    if (((*(char *)(param_1 + 0x7b5) != '6') || (local_4 != 0)) &&
       ((iVar9 != 0 && (*(char *)(iVar9 + 0xe3c) != '\0')))) {
      iVar10 = FUN_0040e690(iVar9);
      iVar11 = FUN_0040e690(param_1);
      if (iVar11 != iVar10) {
        if ((*(char *)(iVar9 + 0x7b5) == '*') &&
           (fVar3 = *(float *)(iVar9 + 0x784) * 0.75,
           fVar3 < *(float *)(iVar9 + 0x77c) != (fVar3 == *(float *)(iVar9 + 0x77c)))) {
          return;
        }
        FUN_0049ad40(param_1);
        return;
      }
    }
    goto LAB_0049b6a1;
  }
  bVar6 = false;
  if (((*(byte *)(param_1 + 0xe24) & 2) == 0) &&
     ((param_2 == 0 || (*(char *)(param_1 + 0x7b5) != -1)))) {
    if ((((*(uint *)(param_1 + 0xef0) & 0x20000000) != 0) ||
        (iVar9 = FUN_0055cdf0(param_1), iVar9 != 0)) && (0.0 < *(float *)(param_3 + 0x28))) {
      uVar8 = FUN_0054b3d0(param_1,param_3);
      if ((*(char *)(param_1 + 0xe3c) != '\0') && (*(float *)(param_1 + 0xd48) <= 0.0)) {
        uVar2 = *(undefined2 *)(param_1 + 0x696);
        uVar12 = FUN_00550040(uVar2,*(undefined2 *)(param_1 + 0x5a));
        if ((int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f)) < 0x4001) {
          uVar12 = FUN_00550040(uVar2,uVar8);
          if (0x6000 < (int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f))) {
            bVar6 = true;
          }
        }
        else {
          uVar12 = FUN_00550040(uVar2,uVar8);
          if ((int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f)) < 0x2000) {
            bVar6 = true;
          }
        }
      }
      FUN_0049b2b0(local_4);
      if (bVar6) goto LAB_0049b7c9;
    }
    return;
  }
LAB_0049b7c9:
  FUN_0049ad40(param_1);
  return;
}

