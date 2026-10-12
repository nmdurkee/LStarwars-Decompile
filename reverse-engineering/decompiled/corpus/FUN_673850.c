/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x673850; label: FUN_00673850
 */

undefined4 FUN_00673850(int param_1,int param_2,uint *param_3,uint param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  float *extraout_EDX;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar6 = (param_1 * 3 + 0x3f) * 4;
  if ((((((*(float *)(iVar6 + DAT_0292186c) <= *(float *)(DAT_0292186c + 0x50)) ||
         (*(float *)(DAT_0292186c + (param_2 * 3 + 0x3f) * 4) <= *(float *)(DAT_0292186c + 0x50)))
        && ((fVar3 = -*(float *)(DAT_0292186c + 0x50), fVar3 <= *(float *)(iVar6 + DAT_0292186c) ||
            (fVar3 <= *(float *)(DAT_0292186c + (param_2 * 3 + 0x3f) * 4))))) &&
       ((param_1 = param_1 * 0xc,
        *(float *)(param_1 + 0x100 + DAT_0292186c) <= *(float *)(DAT_0292186c + 0x50) ||
        (*(float *)(DAT_0292186c + 0x100 + param_2 * 0xc) <= *(float *)(DAT_0292186c + 0x50))))) &&
      ((fVar3 <= *(float *)(param_1 + 0x100 + DAT_0292186c) ||
       (fVar3 <= *(float *)(DAT_0292186c + 0x100 + param_2 * 0xc))))) &&
     ((pfVar1 = (float *)(param_1 + 0x104 + DAT_0292186c),
      fVar3 <= *(float *)(param_1 + 0x104 + DAT_0292186c) ||
      (fVar3 <= *(float *)(DAT_0292186c + 0x104 + param_2 * 0xc))))) {
    fVar3 = *(float *)(DAT_0292186c + 0x4c) + *(float *)(DAT_0292186c + 0x50);
    if ((fVar3 < *pfVar1) && (fVar3 < *(float *)(DAT_0292186c + 0x104 + param_2 * 0xc))) {
      *param_3 = *param_3 & param_4;
      return 0;
    }
    iVar5 = (param_2 * 3 + 0x3f) * 4;
    local_30 = *(float *)(DAT_0292186c + iVar5) - *(float *)(iVar6 + DAT_0292186c);
    param_2 = param_2 * 0xc;
    local_2c = *(float *)(param_2 + 0x100 + DAT_0292186c) -
               *(float *)(param_1 + 0x100 + DAT_0292186c);
    fVar3 = local_30 * local_30 + local_2c * local_2c;
    if (1e-12 <= fVar3) {
      fVar7 = *(float *)(iVar6 + DAT_0292186c) * local_2c -
              *(float *)(param_1 + 0x100 + DAT_0292186c) * local_30;
      if (*(float *)(DAT_0292186c + 0x54) * fVar3 < fVar7 * fVar7) {
        *param_3 = *param_3 & param_4;
        return 0;
      }
      fVar8 = (float10)FUN_0064fde0(fVar7,fVar3);
      local_28 = *(float *)(param_2 + 0x104 + extraout_ECX) - *pfVar1;
      fVar9 = (float10)FUN_005c0240(local_28 * local_28 + fVar3);
      fVar10 = (float10)FUN_0064fde0(0x3f800000,(float)fVar9);
      fVar3 = (float)fVar10;
      local_30 = fVar3 * local_30;
      local_2c = fVar3 * local_2c;
      local_28 = fVar3 * local_28;
      local_24 = -local_2c;
      local_c = -*(float *)(iVar6 + DAT_0292186c);
      local_8 = -*(float *)(param_1 + 0x100 + DAT_0292186c);
      local_4 = -*(float *)(param_1 + 0x104 + DAT_0292186c);
      local_20 = local_30;
      FUN_005b3920(&local_c,&local_c,&local_30);
      fVar10 = (float10)FUN_0064fde0(local_24 * local_c + local_8 * local_20,
                                     local_24 * local_24 + local_20 * local_20);
      local_18 = local_20 * local_28;
      local_14 = -(local_24 * local_28);
      local_10 = local_2c * local_24 - local_20 * local_30;
      fVar11 = (float10)FUN_005c0240(local_10 * local_10 + local_18 * local_18 + local_14 * local_14
                                    );
      fVar11 = (float10)FUN_0064fde0(local_10,(float)fVar11);
      local_10 = (float)fVar11;
      fVar8 = (float10)FUN_005c0240(*(float *)(DAT_0292186c + 0x54) -
                                    (float)(fVar8 * (float10)fVar7),local_10);
      fVar8 = (float10)FUN_0064fde0((float)fVar8);
      fVar3 = (float)fVar8;
      if (0.0 <= fVar3) {
        fVar3 = (float)-fVar10 - fVar3;
      }
      else {
        fVar3 = fVar3 + (float)-fVar10;
      }
      if ((0.0 <= fVar3) && (fVar3 <= *(float *)(DAT_0292186c + 0x4c))) {
        pfVar1 = (float *)(param_1 + 0x104 + DAT_0292186c);
        fVar7 = (fVar3 - *pfVar1) * local_28 +
                -*(float *)(param_1 + 0x100 + DAT_0292186c) * local_2c +
                -*(float *)(iVar6 + DAT_0292186c) * local_30;
        if ((0.0 <= fVar7) && (fVar7 <= (float)fVar9)) {
          fVar8 = (float10)FUN_0064fde0(fVar3,*(undefined4 *)(DAT_0292186c + 0x4c));
          if ((float10)*(float *)(extraout_ECX_00 + 0x98) <= fVar8) {
            *param_3 = *param_3 & param_4;
            return 0;
          }
          *(undefined1 *)(extraout_ECX_00 + 0x88) = 2;
          fVar8 = (float10)FUN_0064fde0(fVar3,*(undefined4 *)(extraout_ECX_00 + 0x4c));
          *(float *)(extraout_ECX_01 + 0x98) = (float)fVar8;
          *(float *)(extraout_ECX_01 + 0xa8) =
               -(fVar7 * local_30 + *(float *)(iVar6 + extraout_ECX_01));
          *(float *)(extraout_ECX_01 + 0xac) = -(fVar7 * local_2c + *extraout_EDX);
          *(float *)(extraout_ECX_01 + 0xb0) = fVar3 - (*pfVar1 + local_28 * fVar7);
          *param_3 = *param_3 & param_4;
          return 1;
        }
      }
      pfVar1 = (float *)(param_1 + 0x104 + DAT_0292186c);
      fVar3 = -*(float *)(DAT_0292186c + 0x50);
      if (((fVar3 < *pfVar1 != (fVar3 == *pfVar1)) ||
          (fVar3 <= *(float *)(param_2 + 0x104 + DAT_0292186c))) &&
         ((*pfVar1 <= *(float *)(DAT_0292186c + 0x50) ||
          (*(float *)(param_2 + 0x104 + DAT_0292186c) <= *(float *)(DAT_0292186c + 0x50))))) {
        pfVar2 = (float *)(param_1 + 0x100 + DAT_0292186c);
        fVar3 = (-local_30 * *(float *)(iVar6 + DAT_0292186c) - local_2c * *pfVar2) -
                *pfVar1 * local_28;
        if ((0.0 <= fVar3) &&
           (fVar3 <= (*(float *)(param_2 + 0x104 + DAT_0292186c) - *pfVar1) * local_28 +
                     (*(float *)(param_2 + 0x100 + DAT_0292186c) - *pfVar2) * local_2c +
                     (*(float *)(DAT_0292186c + iVar5) - *(float *)(iVar6 + DAT_0292186c)) *
                     local_30)) {
          local_30 = *(float *)(iVar6 + DAT_0292186c) + fVar3 * local_30;
          local_2c = *pfVar2 + fVar3 * local_2c;
          local_28 = local_28 * fVar3 + *pfVar1;
          fVar3 = local_28 * local_28 + local_30 * local_30 + local_2c * local_2c;
          if (fVar3 < *(float *)(DAT_0292186c + 0x54)) {
            fVar8 = (float10)FUN_005c0240(fVar3);
            iVar6 = DAT_0292186c;
            fVar3 = (float)fVar8;
            if (fVar3 - *(float *)(DAT_0292186c + 0x50) < *(float *)(DAT_0292186c + 0x98)) {
              FUN_0066f9a0(&local_30,&local_24);
              iVar5 = *(int *)(iVar6 + 0x94);
              if (*(float *)(iVar5 + 0x50) * local_1c +
                  *(float *)(iVar5 + 0x48) * local_24 + *(float *)(iVar5 + 0x4c) * local_20 < 0.0) {
                *(undefined1 *)(iVar6 + 0x88) = 0x12;
                *(float *)(iVar6 + 0x98) = fVar3 - *(float *)(iVar6 + 0x50);
                fVar3 = 1.0 / fVar3;
                *(float *)(iVar6 + 0xa8) = fVar3 * -local_30;
                *(float *)(iVar6 + 0xac) = -local_2c * fVar3;
                *(float *)(iVar6 + 0xb0) = -local_28 * fVar3;
                return 1;
              }
            }
          }
        }
      }
    }
    else if ((((*pfVar1 <= 0.0) &&
              (fVar3 = *(float *)(param_2 + 0x104 + DAT_0292186c),
              !NAN(fVar3) && 0.0 < fVar3 != (fVar3 == 0.0))) ||
             ((fVar3 = *pfVar1, !NAN(fVar3) && 0.0 < fVar3 != (fVar3 == 0.0) &&
              (*(float *)(param_2 + 0x104 + DAT_0292186c) <= 0.0)))) &&
            (fVar3 = *(float *)(param_2 + 0x100 + DAT_0292186c),
            fVar3 = fVar3 * fVar3 +
                    *(float *)(DAT_0292186c + iVar5) * *(float *)(DAT_0292186c + iVar5),
            fVar3 <= *(float *)(DAT_0292186c + 0x54))) {
      fVar8 = (float10)FUN_005c0240(fVar3);
      iVar6 = DAT_0292186c;
      fVar3 = (float)fVar8;
      if (fVar3 - *(float *)(DAT_0292186c + 0x50) < *(float *)(DAT_0292186c + 0x98)) {
        local_24 = -*(float *)(DAT_0292186c + iVar5);
        local_20 = -*(float *)(param_2 + 0x100 + DAT_0292186c);
        local_1c = 0.0;
        FUN_0066f9a0(&local_24,&local_24);
        iVar4 = *(int *)(iVar6 + 0x94);
        if (0.0 < *(float *)(iVar4 + 0x50) * local_1c +
                  *(float *)(iVar4 + 0x48) * local_24 + *(float *)(iVar4 + 0x4c) * local_20) {
          *(float *)(iVar6 + 0x98) = fVar3 - *(float *)(iVar6 + 0x50);
          fVar8 = (float10)FUN_0064fde0(0x3f800000,fVar3);
          *(undefined1 *)(iVar6 + 0x88) = 0x12;
          *(float *)(iVar6 + 0xa8) = (float)fVar8 * -*(float *)(iVar6 + iVar5);
          *(float *)(iVar6 + 0xac) = -*(float *)(param_2 + 0x100 + iVar6) * (float)fVar8;
          *(undefined4 *)(iVar6 + 0xb0) = 0;
          return 1;
        }
      }
    }
    return 0;
  }
  *param_3 = *param_3 & param_4;
  return 0;
}

