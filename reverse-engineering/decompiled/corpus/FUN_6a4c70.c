/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a4c70; label: FUN_006a4c70
 */

void FUN_006a4c70(int *param_1,int param_2,int *param_3,int param_4,int param_5)

{
  size_t _Size;
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float local_8c;
  int local_88;
  int local_84;
  int iStack_7c;
  int local_74;
  int iStack_70;
  
  local_88 = -99;
  local_84 = 1;
  _memset(param_1,0,0x34);
  param_1[9] = *param_3;
  fVar9 = (float10)FUN_006e9040();
  fVar10 = (float10)FUN_006e9040();
  FUN_006eafc0((double)((float10)(double)fVar9 / fVar10 + (float10)0.5));
  iVar3 = FUN_006e6b90();
  param_1[8] = iVar3;
  FUN_006e9040();
  iVar3 = FUN_006e6b90();
  param_1[7] = iVar3;
  FUN_006e9040();
  iVar4 = FUN_006e6b90();
  _Size = param_4 * 4;
  param_1[10] = (iVar4 - iVar3) + 1;
  pvVar5 = _malloc(_Size);
  param_1[4] = (int)pvVar5;
  pvVar5 = _malloc(_Size);
  param_1[5] = (int)pvVar5;
  pvVar5 = _malloc(_Size);
  param_1[6] = (int)pvVar5;
  param_1[0xc] = 0x3f800000;
  param_1[1] = param_2;
  *param_1 = param_4;
  param_1[0xb] = param_5;
  if (param_5 < 26000) {
    iVar3 = 0;
  }
  else if (param_5 < 38000) {
    iVar3 = 0x3f70a3d7;
  }
  else {
    if (param_5 < 0xb3b1) goto LAB_006a4ded;
    iVar3 = 0x3fa33333;
  }
  param_1[0xc] = iVar3;
LAB_006a4ded:
  iVar3 = 0;
  local_8c = 0.0;
  do {
    iVar8 = (int)local_8c + 1;
    fVar9 = (float10)FUN_006e8fac();
    FUN_006eafc0((double)(((fVar9 + fVar9) * (float10)param_4) / (float10)param_5 + (float10)0.5));
    iVar4 = FUN_006e6b90();
    fVar1 = (float)(&DAT_00811060)[(int)local_8c];
    if (iVar3 < iVar4) {
      fVar2 = ((float)(&DAT_00811064)[(int)local_8c] - fVar1) / (float)(iVar4 - iVar3);
      local_8c = fVar1;
      if (3 < iVar4 - iVar3) {
        iVar7 = iVar3 + 2;
        do {
          if (param_4 <= iVar3) goto LAB_006a4f7e;
          *(float *)(param_1[4] + iVar3 * 4) = local_8c + 100.0;
          if (param_4 <= iVar7 + -1) {
            iVar3 = iVar3 + 1;
            goto LAB_006a4f7e;
          }
          *(float *)(param_1[4] + 4 + iVar3 * 4) = fVar2 + local_8c + 100.0;
          local_8c = fVar2 + local_8c + fVar2;
          if (param_4 <= iVar7) {
            iVar3 = iVar3 + 2;
            goto LAB_006a4f7e;
          }
          *(float *)(param_1[4] + 8 + iVar3 * 4) = local_8c + 100.0;
          local_8c = local_8c + fVar2;
          if (param_4 <= iVar7 + 1) {
            iVar3 = iVar3 + 3;
            goto LAB_006a4f7e;
          }
          iVar3 = iVar3 + 4;
          iVar7 = iVar7 + 4;
          *(float *)(param_1[4] + -4 + iVar3 * 4) = local_8c + 100.0;
          local_8c = local_8c + fVar2;
        } while (iVar3 < iVar4 + -3);
      }
      while ((iVar3 < iVar4 && (iVar3 < param_4))) {
        iVar3 = iVar3 + 1;
        *(float *)(param_1[4] + -4 + iVar3 * 4) = local_8c + 100.0;
        local_8c = local_8c + fVar2;
      }
    }
LAB_006a4f7e:
    local_8c = (float)iVar8;
  } while (iVar8 < 0x57);
  local_8c = 0.0;
  if (0 < param_4) {
    iVar3 = param_5 / (param_4 * 2);
    local_74 = 0;
    do {
      fVar9 = (float10)FUN_006eb9e0();
      fVar10 = (float10)FUN_006eb9e0();
      iStack_70 = *(int *)(param_2 + 0x78) + local_88;
      fVar1 = (float)((float10)local_74 * (float10)9.999999747378752e-05 +
                     fVar10 * (float10)13.100000381469727 +
                     (float10)(double)(fVar9 * (float10)2.240000009536743));
      if (iStack_70 < (int)local_8c) {
        fVar2 = *(float *)(param_2 + 0x70);
        iStack_7c = iVar3 * local_88;
        do {
          fVar9 = (float10)FUN_006eb9e0();
          fVar10 = (float10)FUN_006eb9e0();
          if ((float10)(fVar1 - fVar2) <=
              (float10)iStack_7c * (float10)9.999999747378752e-05 +
              fVar10 * (float10)13.100000381469727 +
              (float10)(double)(fVar9 * (float10)2.240000009536743)) break;
          local_88 = local_88 + 1;
          iStack_7c = iStack_7c + iVar3;
          iStack_70 = iStack_70 + 1;
        } while (iStack_70 < (int)local_8c);
      }
      if (local_84 <= param_4) {
        iVar4 = *(int *)(param_2 + 0x7c);
        iStack_7c = iVar3 * local_84;
        do {
          if (iVar4 + (int)local_8c <= local_84) {
            fVar9 = (float10)FUN_006eb9e0();
            fVar10 = (float10)FUN_006eb9e0();
            if ((float10)*(float *)(param_2 + 0x74) + (float10)fVar1 <=
                (float10)iStack_7c * (float10)9.999999747378752e-05 +
                fVar10 * (float10)13.100000381469727 +
                (float10)(double)(fVar9 * (float10)2.240000009536743)) break;
          }
          iStack_7c = iStack_7c + iVar3;
          local_84 = local_84 + 1;
        } while (local_84 <= param_4);
      }
      local_74 = local_74 + iVar3;
      *(int *)(param_1[6] + (int)local_8c * 4) = local_88 * 0x10000 + -0x10001 + local_84;
      local_8c = (float)((int)local_8c + 1);
    } while ((int)local_8c < param_4);
  }
  fVar9 = (float10)0.5;
  iVar3 = 0;
  if (0 < param_4) {
    do {
      FUN_006e9040();
      uVar6 = FUN_006e6b90();
      *(undefined4 *)(param_1[5] + iVar3 * 4) = uVar6;
      iVar3 = iVar3 + 1;
      fVar9 = extraout_ST0;
    } while (iVar3 < param_4);
  }
  iVar3 = FUN_006a4070((float)((fVar9 * (float10)param_5) / (float10)param_4),param_4,
                       *(undefined4 *)(param_2 + 0x18));
  param_1[2] = iVar3;
  pvVar5 = _malloc(0xc);
  param_1[3] = (int)pvVar5;
  iVar3 = 0;
  do {
    pvVar5 = _malloc(param_4 * 4);
    *(void **)(iVar3 + param_1[3]) = pvVar5;
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0xc);
  iVar3 = 0;
  if (0 < param_4) {
    do {
      FUN_006e9040();
      iVar4 = FUN_006e6b90();
      iVar3 = iVar3 + 1;
      fVar1 = (float)(extraout_ST0_00 - (float10)iVar4);
      fVar2 = 1.0 - fVar1;
      *(float *)(*(int *)param_1[3] + -4 + iVar3 * 4) =
           *(float *)(param_1[1] + 0x88 + iVar4 * 4) * fVar1 +
           *(float *)(param_1[1] + 0x84 + iVar4 * 4) * fVar2;
      *(float *)(*(int *)(param_1[3] + 4) + -4 + iVar3 * 4) =
           *(float *)(param_1[1] + 0xcc + iVar4 * 4) * fVar1 +
           *(float *)(param_1[1] + 200 + iVar4 * 4) * fVar2;
      *(float *)(*(int *)(param_1[3] + 8) + -4 + iVar3 * 4) =
           fVar2 * *(float *)(param_1[1] + 0x10c + iVar4 * 4) +
           *(float *)(param_1[1] + 0x110 + iVar4 * 4) * fVar1;
    } while (iVar3 < param_4);
  }
  return;
}

