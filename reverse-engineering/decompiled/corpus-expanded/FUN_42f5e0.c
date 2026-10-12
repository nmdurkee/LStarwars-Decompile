/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42f5e0; label: FUN_0042f5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042f5e0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_50;
  float local_4c;
  float local_30;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  iVar5 = FUN_0055f450();
  if (*(char *)(param_1 + 0x7b5) == '+') {
    return;
  }
  if ((*(char *)(param_1 + 0x283) != -1) &&
     (((&DAT_0080364c)[*(char *)(param_1 + 0x283) * 0xc] & 1) != 0)) {
    return;
  }
  if (*(float *)(param_1 + 0x21c) == 2e+06) {
    return;
  }
  if (((DAT_0087b014 != 0) && (*(int *)(iVar5 + 300) == DAT_0087b014)) ||
     (*(int *)(iVar5 + 0x128) == DAT_0087b0a0)) {
    FUN_004db740(iVar5,param_1);
    return;
  }
  local_4c = 1.0;
  local_24 = 0.0;
  if (*(short *)(param_1 + 0x1064) == DAT_007f1940) {
    fVar1 = *(float *)(param_1 + 0x22c);
    local_50 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
    iVar6 = 0x66;
    fVar2 = 20.0;
  }
  else {
    if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afb4)) {
      fVar1 = *(float *)(param_1 + 0x22c);
      local_50 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
      iVar6 = 0x56;
      local_30 = 10.0;
      fVar2 = 100.0;
      local_24 = 3.0;
      goto LAB_0042f75c;
    }
    if ((DAT_0087b01c == 0) || (*(int *)(iVar5 + 300) != DAT_0087b01c)) {
      if (DAT_0087af78 == 0) {
        return;
      }
      if (*(int *)(iVar5 + 300) != DAT_0087af78) {
        return;
      }
    }
    fVar1 = *(float *)(param_1 + 0x22c);
    local_50 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
    iVar6 = 0x8d;
    fVar2 = _DAT_007f5dcc;
  }
  local_30 = 0.0;
LAB_0042f75c:
  if (*(int *)(iVar6 * 0x14 + *(int *)(*(int *)(iVar5 + 0x134) + 8)) != -1) {
    if (local_50 < 0.0 != (local_50 == 0.0)) {
      return;
    }
    if (0.0 < local_24) {
      local_4c = 1.0 - (*(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c)) *
                       (1.0 / local_24);
      if (local_4c < 0.0 != (local_4c == 0.0)) {
        return;
      }
      if (1.0 < local_4c) {
        local_4c = 1.0;
      }
    }
    local_50 = (fVar1 / local_50) * fVar2;
    if (local_50 < local_30) {
      local_50 = local_30;
    }
    fVar1 = *(float *)(param_1 + 0x5c);
    fVar2 = *(float *)(param_1 + 0x21c);
    fVar3 = *(float *)(param_1 + 100);
    local_20 = fVar1;
    local_1c = fVar2;
    local_18 = fVar3;
    if (*(float *)(param_1 + 0x218) != 2e+06) {
      local_20 = *(float *)(param_1 + 0x8c);
      local_1c = *(float *)(param_1 + 0x218);
      local_18 = *(float *)(param_1 + 0x94);
    }
    iVar7 = FUN_0062c350(local_50 * local_4c,_DAT_00925018);
    if (0 < iVar7) {
      do {
        iVar8 = FUN_0054fa60();
        fVar4 = (float)iVar8 * 1.5259022e-05;
        local_14 = (fVar1 - local_20) * fVar4 + local_20;
        local_10 = (fVar2 - local_1c) * fVar4 + local_1c;
        local_c = fVar4 * (fVar3 - local_18) + local_18;
        FUN_00684c90(*(undefined4 *)(*(int *)(*(int *)(iVar5 + 0x134) + 8) + iVar6 * 0x14),&local_14
                     ,1,0,0);
        iVar7 = iVar7 + -1;
      } while (0 < iVar7);
      return;
    }
  }
  return;
}

