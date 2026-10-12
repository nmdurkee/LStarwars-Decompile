/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x684790; label: FUN_00684790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00684790(int param_1,float param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int extraout_ECX;
  int iVar6;
  int extraout_EDX;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  float10 fVar13;
  float local_20;
  float local_1c;
  int local_18;
  char local_14 [12];
  undefined1 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20;
  if (param_1 < 1) {
    __security_check_cookie(local_4 ^ (uint)&local_20);
    return;
  }
  if (((DAT_02962098 < param_1) || (*(int *)(DAT_0296209c + param_1 * 4) == 0)) ||
     ((iVar6 = *(int *)(DAT_0296209c + param_1 * 4), *(float *)(iVar6 + 0x420) != 1.0 &&
      (param_1 = *(int *)(iVar6 + 0x424), *(int *)(DAT_0296209c + param_1 * 4) == 0)))) {
    __security_check_cookie(local_4 ^ (uint)&local_20);
    return;
  }
  iVar6 = 0;
  if (param_2 == 1.0) {
    iVar6 = param_1;
  }
  if (param_2 < 0.01) {
    param_2 = 0.01;
  }
  if (iVar6 != 0) {
    __security_check_cookie(local_4 ^ (uint)&local_20);
    return;
  }
  iVar8 = 0;
  iVar6 = DAT_0296209c;
  if (0 < DAT_008108f8) {
    iVar5 = 0;
    iVar9 = 0;
    iVar10 = DAT_029620ac;
    do {
      if ((*(int *)(iVar5 + iVar10) == param_1) && (param_2 == *(float *)(iVar5 + 8 + iVar10))) {
        iVar9 = *(int *)(iVar5 + 4 + iVar10);
      }
      if (iVar9 != 0) {
        if ((*(int *)(iVar6 + iVar9 * 4) != 0) &&
           (*(int *)(*(int *)(iVar6 + iVar9 * 4) + 0x424) == *(int *)(iVar5 + iVar10))) break;
        *(undefined4 *)(iVar5 + 8 + iVar10) = 0;
        iVar9 = 0;
        iVar6 = DAT_0296209c;
        iVar10 = DAT_029620ac;
      }
      iVar8 = iVar8 + 1;
      iVar5 = iVar5 + 0xc;
    } while (iVar8 < DAT_008108f8);
    if (iVar9 != 0) goto LAB_00684bad;
  }
  iVar8 = DAT_02962098;
  local_20 = param_2 / *(float *)(*(int *)(iVar6 + param_1 * 4) + 0x420);
  if (local_20 < 1.0 == (local_20 == 1.0)) {
    local_20 = local_20 - 1.0;
  }
  else {
    local_20 = 1.0 - local_20;
  }
  iVar9 = 1;
  local_1c = local_20;
  local_18 = param_1;
  if (1 < DAT_02962098) {
    do {
      if ((*(int *)(iVar6 + iVar9 * 4) != 0) &&
         (iVar10 = *(int *)(iVar6 + iVar9 * 4), *(int *)(iVar10 + 0x424) == param_1)) {
        fVar13 = (float10)FUN_0064fde0(param_2,*(undefined4 *)(iVar10 + 0x420));
        local_20 = (float)fVar13;
        if (local_20 < 1.0 == (local_20 == 1.0)) {
          local_20 = local_20 - 1.0;
        }
        else {
          local_20 = 1.0 - local_20;
        }
        iVar9 = extraout_ECX;
        iVar6 = extraout_EDX;
        if (local_20 < local_1c) {
          local_1c = local_20;
          local_18 = extraout_ECX;
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar8);
  }
  if ((local_18 == 0) || (0.1 <= local_1c)) {
    iVar9 = 1;
    if (iVar8 < 2) {
LAB_006849b9:
      __security_check_cookie(local_4 ^ (uint)&local_20);
      return;
    }
    while (*(int *)(iVar6 + iVar9 * 4) != 0) {
      iVar9 = iVar9 + 1;
      if (iVar8 <= iVar9) goto LAB_006849b9;
    }
    *(int *)(iVar6 + iVar9 * 4) = iVar9 * 0x428 + DAT_029620a0;
    puVar11 = *(undefined4 **)(DAT_0296209c + param_1 * 4);
    puVar12 = *(undefined4 **)(DAT_0296209c + iVar9 * 4);
    for (iVar6 = 0x10a; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    *(undefined4 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x2a8) = 0;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3d0) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3d2) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3d4) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3d6) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3d8) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3da) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3dc) = 0xffff;
    *(undefined2 *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x3de) = 0xffff;
    FUN_006580e0(iVar9,param_2);
    iVar6 = *(int *)(DAT_0296209c + iVar9 * 4);
    uVar3 = _DAT_0296205c;
    if (*(char *)(iVar6 + 0x2f1) == '\x04') {
      uVar3 = _DAT_02962060;
    }
    *(undefined4 *)(iVar6 + 0x2ac) = uVar3;
    *(float *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x420) = param_2;
    *(int *)(*(int *)(DAT_0296209c + iVar9 * 4) + 0x424) = param_1;
    pcVar2 = *(char **)(DAT_0296209c + param_1 * 4);
    pcVar4 = pcVar2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((uint)((int)pcVar4 - (int)(pcVar2 + 1)) < 0xd) {
      _sprintf(*(char **)(DAT_0296209c + iVar9 * 4),"%s%03d",pcVar2,iVar9);
    }
    else {
      _sprintf(local_14,"%s",pcVar2);
      local_8 = 0;
      _sprintf(*(char **)(DAT_0296209c + iVar9 * 4),"%s%03d",local_14,iVar9);
    }
    DAT_02962a24 = DAT_02962a24 + 1;
    iVar6 = 0;
    if (0 < DAT_008108f8) {
      pfVar7 = (float *)(DAT_029620ac + 8);
      do {
        if (*pfVar7 == 0.0) {
          iVar6 = iVar6 * 0xc;
          *(int *)(iVar6 + DAT_029620ac) = param_1;
          *(float *)(iVar6 + 8 + DAT_029620ac) = param_2;
          *(int *)(iVar6 + 4 + DAT_029620ac) = iVar9;
          break;
        }
        iVar6 = iVar6 + 1;
        pfVar7 = pfVar7 + 3;
      } while (iVar6 < DAT_008108f8);
    }
    if (iVar9 == 0) goto LAB_006849b9;
  }
LAB_00684bad:
  __security_check_cookie(local_4 ^ (uint)&local_20);
  return;
}

