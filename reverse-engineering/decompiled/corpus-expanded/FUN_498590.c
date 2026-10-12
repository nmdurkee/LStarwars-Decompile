/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x498590; label: FUN_00498590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00498590(float param_1,float *param_2)

{
  short *psVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  bool bVar8;
  float10 fVar9;
  float local_c;
  float local_8;
  
  iVar7 = (int)param_1;
  if (*(float *)((int)param_1 + 0x1028) == 1e+09) {
    if (*(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa8) == 0.0) {
      psVar1 = (short *)((int)param_1 + 0x1064);
      param_1 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x28);
      if (((*psVar1 == DAT_007f1948) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) &&
         (DAT_009253a4 != 0)) {
        param_1 = param_1 * 0.5;
      }
    }
    else {
      param_1 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa8);
    }
  }
  else {
    param_1 = *(float *)((int)param_1 + 0x1028);
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) {
    if (((((DAT_009253a4 == 0) && (*(char *)(iVar7 + 0x280) != -1)) &&
         (*(int *)(iVar7 + 0xe64) == 0)) &&
        ((DAT_0093d7f0 != 0 && (*(int *)(DAT_0093d7f0 + 0xcd0) != 0)))) &&
       ((*(short *)(DAT_0093d7f0 + 0x1064) == DAT_007f1948 &&
        ((DAT_0093d7f4 != 0 && (*(int *)(DAT_0093d7f4 + 0xcd0) != 0)))))) {
      bVar8 = *(short *)(DAT_0093d7f4 + 0x1064) == DAT_007f1948;
LAB_004986fd:
      if (bVar8) goto LAB_00498703;
    }
  }
  else if (((((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0) && (DAT_0093d7f0 != 0)) &&
           (((*(uint *)(*(int *)(DAT_0093d7f0 + 0x54) + 4) & 0x2000) != 0 &&
            (((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0 ||
             (*(char *)(DAT_0093d7f0 + 0x7b5) == '$')))))) &&
          ((DAT_0093d7f4 != 0 && ((*(uint *)(*(int *)(DAT_0093d7f4 + 0x54) + 4) & 0x2000) != 0)))) {
    if ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0) {
      bVar8 = *(char *)(DAT_0093d7f4 + 0x7b5) == '$';
      goto LAB_004986fd;
    }
LAB_00498703:
    fVar2 = *(float *)(DAT_0093d7f4 + 0x1e0);
    fVar3 = *(float *)(DAT_0093d7f0 + 0x1e0);
    fVar4 = *(float *)(DAT_0093d7f4 + 0x1dc) + *(float *)(DAT_0093d7f0 + 0x1dc);
    fVar5 = fVar4 * fVar4;
    fVar6 = fVar4 * 3.0 * fVar4 * 3.0;
    fVar9 = (float10)FUN_005b3cf0(DAT_0093d7f0 + 0x5c,DAT_0093d7f4 + 0x5c,0);
    fVar4 = (float)fVar9;
    if (fVar5 <= fVar4) {
      if (fVar6 <= fVar4) {
        local_c = 0.0;
      }
      else {
        local_c = 1.0 - (fVar4 - fVar5) / (fVar6 - fVar5);
      }
    }
    else {
      local_c = 1.0;
    }
    local_c = local_c * (fVar2 + fVar3) * 0.6;
    fVar2 = param_1 - local_c;
    if (local_c <= fVar2) {
      local_8 = 0.0;
    }
    else {
      local_8 = local_c - fVar2;
    }
    if (iVar7 == DAT_0093d7f0) {
      param_1 = local_c + param_1;
      if (param_2 != (float *)0x0) {
        *param_2 = local_c;
        param_1 = local_8 + param_1;
        goto LAB_00498858;
      }
    }
    else {
      param_1 = fVar2;
      if (param_2 != (float *)0x0) {
        *param_2 = -local_c;
        param_1 = local_8 + fVar2;
        goto LAB_00498858;
      }
    }
    param_1 = local_8 + param_1;
    goto LAB_00498858;
  }
  if (param_2 != (float *)0x0) {
    *param_2 = 0.0;
  }
LAB_00498858:
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1dc) &&
     (((&DAT_0080364c)[*(char *)(iVar7 + 0x283) * 0xc] & 1) != 0)) {
    DAT_0087b8e0 = 1;
    return (float10)0;
  }
  DAT_0087b8e0 = 0;
  return (float10)param_1;
}

