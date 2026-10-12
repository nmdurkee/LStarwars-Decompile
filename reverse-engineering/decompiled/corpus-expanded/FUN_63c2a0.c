/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63c2a0; label: FUN_0063c2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063c2a0(float param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_c;
  float local_8;
  
  local_8 = -1.0;
  iVar5 = -1;
  iVar6 = (int)param_1;
  if ((param_1 == 0.0) && (iVar6 = DAT_0291396c, DAT_0291396c == 0)) {
    *param_2 = 0.0;
    *param_3 = 0.0;
    *param_4 = 0.0;
    return;
  }
  iVar4 = 0;
  iVar7 = iVar6 + 0xd4;
  do {
    if (*(int *)(iVar7 + -4) != 0) {
      fVar8 = (float10)FUN_005becc0(param_5,iVar7,0);
      fVar1 = (float)fVar8;
      if ((fVar1 < *(float *)(iVar7 + 0x1c) + *(float *)(iVar7 + 0x18)) &&
         ((local_8 < 0.0 || (fVar1 < local_8)))) {
        iVar5 = iVar4;
        local_8 = fVar1;
      }
    }
    iVar4 = iVar4 + 1;
    iVar7 = iVar7 + 0x24;
  } while (iVar4 < 0x20);
  if (iVar5 == -1) {
    local_c = *(float *)(iVar6 + 0x24);
    param_1 = *(float *)(iVar6 + 0x14);
    fVar1 = *(float *)(iVar6 + 0x1c);
  }
  else {
    iVar7 = iVar6 + iVar5 * 0x24;
    if (local_8 <= *(float *)(iVar6 + 0xec + iVar5 * 0x24)) {
      local_c = *(float *)(iVar7 + 0xe0);
      param_1 = *(float *)(iVar7 + 0xe4);
      fVar1 = *(float *)(iVar7 + 0xe8);
    }
    else {
      fVar1 = (local_8 - *(float *)(iVar7 + 0xec)) / *(float *)(iVar7 + 0xf0);
      fVar2 = 1.0 - fVar1;
      local_c = *(float *)(iVar7 + 0xe0) * fVar2 + *(float *)(iVar6 + 0x24) * fVar1;
      param_1 = *(float *)(iVar7 + 0xe4) * fVar2 + *(float *)(iVar6 + 0x14) * fVar1;
      fVar1 = fVar2 * *(float *)(iVar7 + 0xe8) + *(float *)(iVar6 + 0x1c) * fVar1;
    }
  }
  if (*(int *)(iVar6 + 0xb4) != 0) {
    *(float *)(iVar6 + 0x78) = local_c;
    *param_2 = local_c;
    *(float *)(iVar6 + 0x68) = param_1;
    *param_3 = param_1;
    *(float *)(iVar6 + 0x70) = fVar1;
    *param_4 = fVar1;
    *(undefined4 *)(iVar6 + 0xb4) = 0;
    return;
  }
  fVar2 = param_6 * *(float *)(iVar6 + 0xb8);
  if (local_c <= *(float *)(iVar6 + 0x78)) {
    if (local_c < *(float *)(iVar6 + 0x78)) {
      fVar3 = *(float *)(iVar6 + 0x78) - fVar2;
      if (local_c <= fVar3) goto LAB_0063c498;
      *(float *)(iVar6 + 0x78) = local_c;
    }
  }
  else {
    fVar3 = *(float *)(iVar6 + 0x78) + fVar2;
    if (fVar3 <= local_c) {
LAB_0063c498:
      *(float *)(iVar6 + 0x78) = fVar3;
    }
    else {
      *(float *)(iVar6 + 0x78) = local_c;
    }
  }
  if (fVar1 <= *(float *)(iVar6 + 0x70)) {
    if (fVar1 < *(float *)(iVar6 + 0x70)) {
      fVar3 = *(float *)(iVar6 + 0x70) - fVar2;
      if (fVar3 <= fVar1) goto LAB_0063c4e6;
      *(float *)(iVar6 + 0x70) = fVar1;
    }
  }
  else {
    fVar3 = *(float *)(iVar6 + 0x70) + fVar2;
    if (fVar1 <= fVar3) {
LAB_0063c4e6:
      *(float *)(iVar6 + 0x70) = fVar3;
    }
    else {
      *(float *)(iVar6 + 0x70) = fVar1;
    }
  }
  if (((*(int *)(iVar6 + 0xb0) == 0) && (*(int *)(iVar6 + 0xa8) == 0)) &&
     (*(int *)(iVar6 + 0xac) == 0)) {
    fVar1 = *(float *)(iVar6 + 0xc0) + *(float *)(iVar6 + 0x68);
    if (fVar1 < param_1 == (fVar1 == param_1)) {
      if (param_1 <= *(float *)(iVar6 + 0x68) - *(float *)(iVar6 + 0xc0)) {
        *(undefined4 *)(iVar6 + 0xac) = 1;
      }
    }
    else {
      *(undefined4 *)(iVar6 + 0xa8) = 1;
    }
  }
  iVar5 = *(int *)(iVar6 + 0xa8);
  if ((iVar5 != 0) || (fVar1 = param_1, *(int *)(iVar6 + 0xac) != 0)) {
    fVar2 = *(float *)(iVar6 + 0xbc) * param_6;
    if (iVar5 == 0) {
      fVar1 = param_1 - *(float *)(iVar6 + 0xc4);
      if ((fVar1 < *(float *)(iVar6 + 0xcc)) &&
         (fVar1 = param_1, *(float *)(iVar6 + 0xcc) <= param_1)) {
        fVar1 = *(float *)(iVar6 + 0xcc);
      }
    }
    else {
      fVar1 = *(float *)(iVar6 + 0xc4) + param_1;
      if ((*(float *)(iVar6 + 200) < fVar1) && (fVar1 = param_1, param_1 <= *(float *)(iVar6 + 200))
         ) {
        fVar1 = *(float *)(iVar6 + 200);
      }
    }
  }
  if (fVar1 <= *(float *)(iVar6 + 0x68)) {
    if (*(float *)(iVar6 + 0x68) <= fVar1) goto LAB_0063c698;
    fVar2 = *(float *)(iVar6 + 0x68) - fVar2;
    if (fVar2 < fVar1) {
      fVar2 = fVar1;
    }
  }
  else {
    fVar2 = fVar2 + *(float *)(iVar6 + 0x68);
    if (fVar1 < fVar2) {
      *(float *)(iVar6 + 0x68) = fVar1;
      goto LAB_0063c698;
    }
  }
  *(float *)(iVar6 + 0x68) = fVar2;
LAB_0063c698:
  if ((*(int *)(iVar6 + 0xb0) != 0) && (*(float *)(iVar6 + 0x68) == fVar1)) {
    *(undefined4 *)(iVar6 + 0xb0) = 0;
  }
  if (((iVar5 != 0) || (*(int *)(iVar6 + 0xac) != 0)) && (*(float *)(iVar6 + 0x68) == fVar1)) {
    *(undefined4 *)(iVar6 + 0xa8) = 0;
    *(undefined4 *)(iVar6 + 0xac) = 0;
    *(undefined4 *)(iVar6 + 0xb0) = 1;
  }
  *param_2 = *(float *)(iVar6 + 0x78);
  *param_3 = *(float *)(iVar6 + 0x68);
  *param_4 = *(float *)(iVar6 + 0x70);
  return;
}

