/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575f50; label: FUN_00575f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00575f50(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  float10 fVar7;
  int local_64;
  int local_58;
  int local_50;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((*(char *)(param_2 + 0x28b) == '\0') &&
     ((((DAT_00802828 == -1 || (*(char *)(param_2 + 0x7b5) != DAT_00802828)) && (DAT_00951b80 == 0))
      && ((local_64 = *(int *)(PTR_DAT_00802c54 + 0x4698), local_64 != 0 &&
          ((*(uint *)(param_2 + 0x1f8) & 0x40000) == 0)))))) {
    if ((DAT_0093d7f0 == 0) ||
       ((((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0 || (DAT_0093d7f4 == 0)) ||
        (bVar3 = true, (*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)))) {
      bVar3 = false;
    }
    local_58 = 0;
    local_44 = (*(float *)(param_2 + 0xff4) + *(float *)(param_2 + 0xff0)) *
               *(float *)(param_2 + 0xa8) * 0.5;
    local_3c = *(float *)(param_2 + 0x8c);
    local_38 = local_44 + *(float *)(param_2 + 0x90);
    local_34 = *(float *)(param_2 + 0x94);
    local_48 = *(float *)(param_2 + 0x5c);
    local_44 = local_44 + *(float *)(param_2 + 0x60);
    local_40 = *(float *)(param_2 + 100);
    if (0 < *(int *)(PTR_DAT_00802c54 + 0x469c)) {
      iVar6 = local_64 + 0xd4;
      puVar5 = PTR_DAT_00802c54;
      do {
        if ((((*(byte *)(iVar6 + 0x21) & 4) == 0) && (*(char *)(iVar6 + 0x23) == '\0')) &&
           ((iVar4 = FUN_0058a900(0), iVar4 == 0 ||
            (puVar5 = PTR_DAT_00802c54, (int)*(short *)(iVar6 + 0x1c) == *(int *)(param_1 + 0x11c)))
           )) {
          FUN_005b3800(local_18,&local_3c,iVar6);
          FUN_005b3800(local_c,&local_48,iVar6);
          fVar7 = (float10)FUN_005b39e0(iVar6 + 0x10,local_18);
          fVar1 = (float)fVar7;
          fVar7 = (float10)FUN_005b39e0(iVar6 + 0x10,local_c);
          fVar2 = (float)fVar7;
          if ((0.0 <= fVar1) || (fVar2 < 0.0)) {
            puVar5 = PTR_DAT_00802c54;
            if (((*(byte *)(iVar6 + 0x21) & 1) != 0) || ((fVar1 < 0.0 || (0.0 <= fVar2))))
            goto LAB_0057623a;
            local_50 = 2;
          }
          else {
            local_50 = 1;
          }
          fVar1 = ABS(fVar1) / (ABS(fVar2) + ABS(fVar1));
          local_24 = fVar1 * (local_48 - local_3c) + local_3c;
          local_20 = local_38 + fVar1 * (local_44 - local_38);
          local_1c = local_34 + (local_40 - local_34) * fVar1;
          iVar4 = FUN_005bf770(&local_24,iVar6 + -0x30,iVar6 + -0x24,iVar6 + -0xc,iVar6 + 0x3c);
          if ((iVar4 != 0) ||
             (iVar4 = FUN_005bf770(&local_24,iVar6 + -0x24,iVar6 + -0x18,iVar6 + -0xc,iVar6 + 0x3c),
             puVar5 = PTR_DAT_00802c54, iVar4 != 0)) {
            if (((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) &&
               (((*(byte *)(local_64 + 0xf5) & 0x10) == 0 || (bVar3)))) {
              FUN_00575c20(param_1,local_64,1);
              return;
            }
            if (_DAT_0298c448 <= ABS(*(float *)(local_64 + 0xe8))) {
              return;
            }
            *(undefined4 *)(param_2 + 0x5c) = *(undefined4 *)(param_2 + 0x8c);
            *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(param_2 + 0x90);
            *(undefined4 *)(param_2 + 100) = *(undefined4 *)(param_2 + 0x94);
            local_30 = *(float *)(local_64 + 0xe4);
            local_2c = *(undefined4 *)(local_64 + 0xe8);
            local_28 = *(float *)(local_64 + 0xec);
            if (local_50 == 2) {
              FUN_005b3620(&local_30,&local_30,0x8000);
            }
            *(float *)(param_2 + 0x200) = *(float *)(param_2 + 0x200) - local_30 * 10.0;
            *(float *)(param_2 + 0x208) = *(float *)(param_2 + 0x208) - local_28 * 10.0;
            return;
          }
        }
LAB_0057623a:
        local_64 = local_64 + 0x128;
        local_58 = local_58 + 1;
        iVar6 = iVar6 + 0x128;
        if (*(int *)(puVar5 + 0x469c) <= local_58) {
          return;
        }
      } while( true );
    }
  }
  return;
}

