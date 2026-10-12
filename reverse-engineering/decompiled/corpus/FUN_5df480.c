/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5df480; label: FUN_005df480
 */

void FUN_005df480(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int iVar7;
  float fVar8;
  float *pfVar9;
  float10 fVar10;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_ac;
  float local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_50 [19];
  
  local_a4 = *(int *)(*param_1 + 0x110);
  iVar1 = param_1[2];
  if (param_1[1] == 0) {
    if (iVar1 == 0) {
      pfVar6 = (float *)0x0;
    }
    else {
      pfVar6 = *(float **)(iVar1 + 0xc4);
      if ((pfVar6 == (float *)0xffffffff) || (pfVar6 == (float *)0x0)) {
        pfVar6 = (float *)(iVar1 + 0x40);
      }
    }
  }
  else {
    pfVar9 = *(float **)(param_1[1] + 0x40);
    pfVar6 = (float *)pfVar9[0x12];
    if (pfVar6 == (float *)0x0) {
      pfVar6 = pfVar9;
    }
  }
  pfVar9 = local_50;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *pfVar9 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    pfVar9 = pfVar9 + 1;
  }
  fVar2 = (*(float *)(iVar1 + 0x90) - *(float *)(iVar1 + 0x80)) * 0.5;
  fVar8 = (*(float *)(iVar1 + 0x94) - *(float *)(iVar1 + 0x84)) * 0.5;
  fVar3 = (*(float *)(iVar1 + 0x98) - *(float *)(iVar1 + 0x88)) * 0.5;
  local_c0 = (*(float *)(iVar1 + 0x90) + *(float *)(iVar1 + 0x80)) * 0.5;
  local_bc = (*(float *)(iVar1 + 0x94) + *(float *)(iVar1 + 0x84)) * 0.5;
  local_b8 = (*(float *)(iVar1 + 0x98) + *(float *)(iVar1 + 0x88)) * 0.5;
  local_90 = ABS(local_50[0]);
  local_8c = ABS(local_50[1]);
  local_88 = ABS(local_50[2]);
  FUN_005c1950();
  FUN_005c1950();
  fVar4 = fVar8 * local_80 + fVar2 * local_90 + fVar3 * local_70;
  fVar5 = local_6c * fVar3 + local_8c * fVar2 + local_7c * fVar8;
  fVar2 = fVar3 * local_68 + local_78 * fVar8 + local_88 * fVar2;
  local_ac = fVar4;
  FUN_005b30a0(&local_c0,&local_c0,local_50);
  local_a8 = fVar5 + local_ac + fVar2;
  fVar10 = (float10)FUN_005c0240(local_a8);
  local_b4 = (float)fVar10;
  pfVar6 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + *(int *)(local_a4 + 0x44));
  if ((*(uint *)(local_a4 + 0x74) & 0x4000) == 0) {
    local_a0 = local_c0 + local_ac;
    local_9c = local_bc + fVar5;
    fVar8 = fVar2 + local_b8;
    *pfVar6 = local_c0 - local_ac;
    pfVar6[1] = local_bc - fVar5;
    pfVar6[2] = local_b8 - fVar2;
    pfVar6[3] = local_c4;
    pfVar6 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + 0x10 + *(int *)(local_a4 + 0x44));
    *pfVar6 = local_a0;
    pfVar6[1] = local_9c;
    local_c4 = local_94;
    local_98 = fVar8;
  }
  else {
    *pfVar6 = local_c0;
    pfVar6[1] = local_bc;
    pfVar6[2] = local_b8;
    pfVar6[3] = local_b4;
    pfVar6 = (float *)(*(int *)(iVar1 + 0xc0) * 0x20 + 0x10 + *(int *)(local_a4 + 0x44));
    *pfVar6 = fVar4;
    pfVar6[1] = fVar5;
    fVar8 = fVar2;
  }
  pfVar6[2] = fVar8;
  pfVar6[3] = local_c4;
  thunk_FUN_005f7490(param_1,local_50);
  return;
}

