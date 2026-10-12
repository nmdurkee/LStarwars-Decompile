/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b0c20; label: FUN_006b0c20
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x006b0e4c) */
/* WARNING: Removing unreachable block (ram,0x006b0ec0) */

uint FUN_006b0c20(float param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int aiStack_50 [2];
  undefined1 auStack_48 [4];
  undefined4 uStack_44;
  float *pfStack_28;
  float local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  float local_14;
  float local_10;
  float local_8;
  
  fVar1 = *(float *)(in_EAX + 0xc);
  iVar11 = *(int *)(in_EAX + 4);
  local_1c = 0;
  uStack_44 = 0x6b0c4d;
  iVar3 = iVar11 * -4;
  iVar5 = *(int *)(in_EAX + 0x9c) / 2;
  local_18 = 2;
  if (1 < iVar5) {
    local_18 = iVar5;
  }
  local_14 = *(float *)((int)param_1 + 0x3c) - (float)(iVar5 + -2);
  if (local_14 < 0.0) {
    local_14 = 0.0;
  }
  if (*(float *)((int)param_1 + 0x3c) < local_14) {
    local_14 = *(float *)((int)param_1 + 0x3c);
  }
  fVar4 = local_14;
  iVar5 = 0;
  if (3 < iVar11) {
    iVar9 = (iVar11 - 4U >> 2) + 1;
    iVar5 = iVar9 * 4;
    pfVar6 = (float *)(&stack0xffffffc4 + iVar3);
    pfVar7 = (float *)(param_2 + 0xc);
    do {
      pfVar6[-1] = *(float *)((int)pfVar6 +
                             *(int *)(in_EAX + 0x24) + -(int)(&stack0xffffffc0 + iVar3) + -4) *
                   pfVar7[-3];
      *pfVar6 = *(float *)((param_2 - (int)(&stack0xffffffc0 + iVar3)) + (int)pfVar6) *
                *(float *)((int)pfVar6 + *(int *)(in_EAX + 0x24) + -(int)(&stack0xffffffc0 + iVar3))
      ;
      iVar9 = iVar9 + -1;
      pfVar6[1] = *(float *)((int)pfVar6 +
                            *(int *)(in_EAX + 0x24) + (4 - (int)(&stack0xffffffc0 + iVar3))) *
                  pfVar7[-1];
      pfVar6[2] = *(float *)((int)pfVar6 +
                            *(int *)(in_EAX + 0x24) + (8 - (int)(&stack0xffffffc0 + iVar3))) *
                  *pfVar7;
      pfVar6 = pfVar6 + 4;
      pfVar7 = pfVar7 + 4;
    } while (iVar9 != 0);
  }
  if (iVar5 < iVar11) {
    pfVar6 = (float *)(&stack0xffffffc0 + iVar5 * 4 + iVar3);
    do {
      iVar9 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      *pfVar6 = *(float *)(*(int *)(in_EAX + 0x24) + iVar9) *
                *(float *)((int)pfVar6 + (param_2 - (int)(&stack0xffffffc0 + iVar3)));
      pfVar6 = pfVar6 + 1;
    } while (iVar5 < iVar11);
  }
  (&uStack_44)[-iVar11] = &stack0xffffffc0 + iVar3;
  *(undefined1 **)(auStack_48 + iVar3) = &stack0xffffffc0 + iVar3;
  aiStack_50[1 - iVar11] = in_EAX + 0x10;
  aiStack_50[-iVar11] = 0x6b0d79;
  FUN_006b0070();
  iVar5 = *(int *)(param_4 + 0x8c);
  fVar2 = *(float *)(&stack0xffffffc4 + iVar3) * 0.7 * *(float *)(&stack0xffffffc4 + iVar3) +
          *(float *)(&stack0xffffffc0 + iVar3) * *(float *)(&stack0xffffffc0 + iVar3) +
          *(float *)(&stack0xffffffc8 + iVar3) * 0.2 * *(float *)(&stack0xffffffc8 + iVar3);
  if (iVar5 == 0) {
    local_8 = fVar2 + *(float *)(param_4 + 0x88);
    *(float *)(param_4 + 0x84) = local_8;
    *(float *)(param_4 + 0x88) = fVar2;
  }
  else {
    local_8 = *(float *)(param_4 + 0x84) + fVar2;
    *(float *)(param_4 + 0x84) = local_8;
    *(float *)(param_4 + 0x88) = fVar2 + *(float *)(param_4 + 0x88);
  }
  *(float *)(param_4 + 0x84) = *(float *)(param_4 + 0x84) - *(float *)(param_4 + 0x48 + iVar5 * 4);
  *(float *)(param_4 + 0x48 + iVar5 * 4) = fVar2;
  *(int *)(param_4 + 0x8c) = *(int *)(param_4 + 0x8c) + 1;
  if (0xe < *(int *)(param_4 + 0x8c)) {
    *(undefined4 *)(param_4 + 0x8c) = 0;
  }
  iVar5 = 0;
  local_8 = ((float)(int)ABS(local_8 * 0.0625) * 7.1771143e-07 - 764.6162) * 0.5 - 15.0;
  if (0 < iVar11 / 2) {
    do {
      local_10 = ((float)(int)ABS(*(float *)(&stack0xffffffc0 + iVar5 * 4 + iVar3) *
                                  *(float *)(&stack0xffffffc0 + iVar5 * 4 + iVar3) +
                                  *(float *)(&stack0xffffffc4 + iVar5 * 4 + iVar3) *
                                  *(float *)(&stack0xffffffc4 + iVar5 * 4 + iVar3)) * 7.1771143e-07
                 - 764.6162) * 0.5;
      if (local_10 < local_8) {
        local_10 = local_8;
      }
      if (local_10 < fVar1) {
        local_10 = fVar1;
      }
      *(float *)(&stack0xffffffc0 + (iVar5 >> 1) * 4 + iVar3) = local_10;
      iVar5 = iVar5 + 2;
      local_8 = local_8 - 8.0;
    } while (iVar5 < iVar11 / 2);
  }
  pfStack_28 = (float *)((int)param_1 + 0x20);
  local_20 = (int *)(param_4 + 0x44);
  local_14 = 0.0;
  piVar10 = (int *)(param_3 + 8);
  do {
    iVar5 = piVar10[-1];
    local_10 = 0.0;
    iVar11 = 0;
    if (3 < iVar5) {
      iVar9 = (iVar5 - 4U >> 2) + 1;
      iVar11 = iVar9 * 4;
      pfVar6 = (float *)(*piVar10 + 8);
      pfVar7 = (float *)(&stack0xffffffc8 + piVar10[-2] * 4 + iVar3);
      do {
        iVar9 = iVar9 + -1;
        local_10 = pfVar7[1] * pfVar6[1] +
                   *pfVar6 * *pfVar7 + pfVar7[-1] * pfVar6[-1] + pfVar7[-2] * pfVar6[-2] + local_10;
        pfVar6 = pfVar6 + 4;
        pfVar7 = pfVar7 + 4;
      } while (iVar9 != 0);
    }
    if (iVar11 < iVar5) {
      pfVar6 = (float *)(&stack0xffffffc0 + (piVar10[-2] + iVar11) * 4 + iVar3);
      iVar5 = iVar5 - iVar11;
      pfVar7 = (float *)(*piVar10 + iVar11 * 4);
      do {
        fVar1 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        iVar5 = iVar5 + -1;
        local_10 = fVar1 * *pfVar7 + local_10;
        pfVar7 = pfVar7 + 1;
      } while (iVar5 != 0);
    }
    fVar1 = (float)piVar10[1] * local_10;
    iVar11 = *local_20 + -1;
    local_8 = -99999.0;
    param_1 = 99999.0;
    if (iVar11 < 0) {
      iVar11 = *local_20 + 0x10;
    }
    fVar2 = *(float *)(param_4 + ((int)local_14 + iVar11) * 4);
    pfVar6 = (float *)(param_4 + ((int)local_14 + iVar11) * 4);
    local_24 = fVar1;
    if (fVar1 <= fVar2) {
      local_24 = *pfVar6;
    }
    local_10 = fVar1;
    if (fVar2 <= fVar1) {
      local_10 = *pfVar6;
    }
    iVar5 = 0;
    if (3 < local_18) {
      iVar9 = (local_18 - 4U >> 2) + 1;
      iVar5 = iVar9 * 4;
      do {
        iVar8 = iVar11 + -1;
        pfVar7 = pfVar6 + -1;
        if (iVar8 < 0) {
          iVar8 = iVar11 + 0x10;
          pfVar7 = pfVar6 + 0x10;
        }
        if (local_8 <= *pfVar7) {
          local_8 = *pfVar7;
        }
        if (*pfVar7 <= param_1) {
          param_1 = *pfVar7;
        }
        iVar11 = iVar8 + -1;
        pfVar6 = pfVar7 + -1;
        if (iVar11 < 0) {
          iVar11 = iVar8 + 0x10;
          pfVar6 = pfVar7 + 0x10;
        }
        if (local_8 <= *pfVar6) {
          local_8 = *pfVar6;
        }
        if (*pfVar6 <= param_1) {
          param_1 = *pfVar6;
        }
        iVar8 = iVar11 + -1;
        pfVar7 = pfVar6 + -1;
        if (iVar8 < 0) {
          iVar8 = iVar11 + 0x10;
          pfVar7 = pfVar6 + 0x10;
        }
        if (local_8 <= *pfVar7) {
          local_8 = *pfVar7;
        }
        if (*pfVar7 <= param_1) {
          param_1 = *pfVar7;
        }
        iVar11 = iVar8 + -1;
        pfVar6 = pfVar7 + -1;
        if (iVar11 < 0) {
          iVar11 = iVar8 + 0x10;
          pfVar6 = pfVar7 + 0x10;
        }
        if (local_8 <= *pfVar6) {
          local_8 = *pfVar6;
        }
        if (*pfVar6 <= param_1) {
          param_1 = *pfVar6;
        }
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    if (iVar5 < local_18) {
      iVar5 = local_18 - iVar5;
      pfVar6 = (float *)(param_4 + ((int)local_14 + iVar11) * 4);
      do {
        iVar9 = iVar11 + -1;
        pfVar7 = pfVar6 + -1;
        if (iVar9 < 0) {
          iVar9 = iVar11 + 0x10;
          pfVar7 = pfVar6 + 0x10;
        }
        if (local_8 <= *pfVar7) {
          local_8 = *pfVar7;
        }
        if (*pfVar7 <= param_1) {
          param_1 = *pfVar7;
        }
        iVar5 = iVar5 + -1;
        iVar11 = iVar9;
        pfVar6 = pfVar7;
      } while (iVar5 != 0);
    }
    *(float *)(param_4 + (*local_20 + (int)local_14) * 4) = fVar1;
    *local_20 = *local_20 + 1;
    if (0x10 < *local_20) {
      *local_20 = 0;
    }
    if (pfStack_28[-7] + fVar4 < local_24 - local_8) {
      local_1c = local_1c | 5;
    }
    if (local_10 - param_1 < *pfStack_28 - fVar4) {
      local_1c = local_1c | 2;
    }
    local_14 = (float)((int)local_14 + 0x24);
    local_20 = local_20 + 0x24;
    pfStack_28 = pfStack_28 + 1;
    piVar10 = piVar10 + 4;
  } while ((int)local_14 < 0xfc);
  return local_1c;
}

