/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x498d40; label: FUN_00498d40
 */

float10 FUN_00498d40(int param_1)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float local_24;
  float local_18;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = FUN_0055f450();
  if (*(int **)(iVar5 + 0x2988) == (int *)0x0) {
    return (float10)0;
  }
  if (*(char *)(param_1 + 0x671) == -1) {
    return (float10)0;
  }
  iVar5 = *(char *)(param_1 + 0x671) * 0x13c + **(int **)(iVar5 + 0x2988);
  if (1 < *(byte *)(param_1 + 0x69a)) {
    return (float10)0;
  }
  fVar1 = *(float *)(iVar5 + 0x74);
  uVar3 = *(ushort *)(iVar5 + 0x68);
  fVar2 = *(float *)(iVar5 + 0x78);
  fVar9 = (float10)0;
  local_18 = (float)fVar9;
  if ((uVar3 & 2) != 0) {
    if (*(char *)(param_1 + 0x107a) != '\x04') {
      fVar8 = (float10)fVar1;
      if ((fVar9 < fVar8) && (fVar9 < (float10)fVar2)) {
        fVar1 = *(float *)(param_1 + 0x67c) - *(float *)(param_1 + 0x60);
        fVar9 = (float10)fVar1;
        if (fVar8 * fVar8 < fVar9 * fVar9 != (fVar8 * fVar8 == fVar9 * fVar9)) {
          fVar1 = (float)(((float10)ABS(fVar1) - fVar8) / ((float10)fVar2 - fVar8));
          *(float *)(param_1 + 0xf1c) =
               (float)((float10)*(float *)(param_1 + 0xf1c) +
                      (float10)fVar1 *
                      fVar9 * (float10)*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c))
          ;
          return (float10)fVar1;
        }
      }
      fVar9 = (float10)local_18;
    }
    return fVar9;
  }
  fVar8 = (float10)fVar1;
  if ((fVar9 < fVar8) && (fVar9 < (float10)fVar2)) {
    if ((uVar3 & 4) == 0) {
      FUN_005b3800(&local_c,param_1 + 0x678,param_1 + 0x5c);
      fVar4 = local_8 * local_8 + local_c * local_c;
    }
    else {
      local_c = *(float *)(param_1 + 0x678) - *(float *)(param_1 + 0x5c);
      local_8 = (float)fVar9;
      local_4 = *(float *)(param_1 + 0x680) - *(float *)(param_1 + 100);
      fVar4 = local_c * local_c;
    }
    fVar4 = fVar4 + local_4 * local_4;
    if ((float)(fVar8 * fVar8) < fVar4 != ((float)(fVar8 * fVar8) == fVar4)) {
      fVar9 = (float10)FUN_005c0240(fVar4);
      local_24 = (float)((fVar9 - (float10)fVar1) / ((float10)fVar2 - (float10)fVar1));
      if (local_24 <= 3.0) {
        if (NAN(local_24) || 0.0 < local_24 == (local_24 == 0.0)) goto LAB_004990bc;
      }
      else {
        local_24 = 3.0;
      }
      if (((uVar3 & 4) == 0) && (*(float *)(iVar5 + 0x7c) != 1.0)) {
        if (*(char *)(param_1 + 0x107a) == '\x04') {
          FUN_005b3470(&local_c,&local_c,param_1 + 0xc04);
          local_8 = (1.0 / *(float *)(iVar5 + 0x7c)) * local_8;
          FUN_005b3200(&local_c,&local_c,param_1 + 0xc04);
        }
        else {
          iVar6 = FUN_00550040(0,*(undefined2 *)(param_1 + 0x694));
          iVar7 = FUN_00550040(0,*(undefined2 *)(param_1 + 0x696));
          FUN_005b3620(&local_c,&local_c,-iVar7);
          FUN_005b35a0(&local_c,&local_c,-iVar6);
          local_8 = (1.0 / *(float *)(iVar5 + 0x7c)) * local_8;
          FUN_005b35a0(&local_c,&local_c,iVar6);
          FUN_005b3620(&local_c,&local_c,iVar7);
        }
      }
      fVar9 = (float10)FUN_005c0240(fVar4);
      fVar1 = (float)((float10)1 / fVar9);
      if ((uVar3 & 4) == 0) {
        local_8 = fVar1 * local_8;
      }
      fVar2 = local_24 * *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
      *(float *)(param_1 + 0xf18) = fVar2 * fVar1 * local_c + *(float *)(param_1 + 0xf18);
      if ((uVar3 & 4) == 0) {
        *(float *)(param_1 + 0xf1c) = fVar2 * local_8 + *(float *)(param_1 + 0xf1c);
      }
      *(float *)(param_1 + 0xf20) = fVar2 * fVar1 * local_4 + *(float *)(param_1 + 0xf20);
      local_18 = local_24;
    }
LAB_004990bc:
    if ((uVar3 & 4) == 0) goto LAB_00499146;
  }
  if (((*(byte *)(iVar5 + 0x68) & 8) != 0) &&
     (*(float *)(param_1 + 0x67c) < *(float *)(param_1 + 0x60) !=
      (*(float *)(param_1 + 0x67c) == *(float *)(param_1 + 0x60)))) {
    iVar5 = *(int *)(param_1 + 0x54);
    fVar1 = *(float *)(iVar5 + 0x3c) * *(float *)(iVar5 + 0x30) * 3.0 + *(float *)(param_1 + 0x67c);
    if (fVar1 <= *(float *)(param_1 + 0x60)) {
      fVar1 = 1.0;
    }
    else {
      fVar1 = (*(float *)(param_1 + 0x60) - *(float *)(param_1 + 0x67c)) /
              (fVar1 - *(float *)(param_1 + 0x67c));
    }
    *(float *)(param_1 + 0xf1c) =
         *(float *)(param_1 + 0xf1c) - *(float *)(*(int *)(iVar5 + 0x24) + 0x1c) * fVar1;
  }
LAB_00499146:
  return (float10)local_18;
}

