/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c82c0; label: FUN_005c82c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c82c0(float *param_1,int param_2,int param_3)

{
  bool bVar1;
  float *pfVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float *pfVar8;
  int local_94;
  int *local_90;
  int local_8c;
  float local_88;
  int local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  int local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  char acStack_1c [8];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&local_94;
  local_68 = -_DAT_0080bf7c;
  local_70 = local_68 * *param_1;
  local_54 = param_3;
  local_84 = param_2;
  local_94 = 0;
  local_6c = param_1[1] * local_68;
  local_8c = 0;
  local_90 = &DAT_00806ba4;
  pfVar8 = (float *)(param_3 + 8);
  local_68 = local_68 * param_1[2];
  do {
    piVar4 = local_90;
    iVar3 = local_90[1] * 0x10 + local_84;
    local_50 = *(float *)(local_90[1] * 0x10 + local_84) -
               *(float *)(local_90[-1] * 0x10 + local_84);
    pfVar6 = (float *)(local_90[-1] * 0x10 + local_84);
    pfVar2 = (float *)(*local_90 * 0x10 + local_84);
    local_4c = *(float *)(iVar3 + 4) - pfVar6[1];
    local_48 = *(float *)(iVar3 + 8) - pfVar6[2];
    local_40 = *pfVar2 - *pfVar6;
    local_3c = pfVar2[1] - pfVar6[1];
    local_38 = pfVar2[2] - pfVar6[2];
    FUN_005b3920(&local_30,&local_40,&local_50);
    local_88 = local_28 * local_68 + local_30 * local_70 + local_2c * local_6c;
    bVar1 = 0.0 < local_88 != (local_88 == 0.0);
    acStack_1c[local_8c] = !NAN(local_88) && bVar1;
    if (NAN(local_88) || !bVar1) {
      pfVar2 = pfVar8 + -2;
      local_80 = -local_30;
      local_7c = -local_2c;
      local_78 = -local_28;
      *pfVar2 = local_80;
      pfVar8[-1] = local_7c;
      *pfVar8 = local_78;
      pfVar8[1] = 0.0;
      FUN_005b3b30(pfVar2,pfVar2);
      local_94 = local_94 + 1;
      pfVar8[1] = 1.0;
      local_88 = *pfVar8 * pfVar6[2] + *pfVar2 * *pfVar6 + pfVar8[-1] * pfVar6[1];
      pfVar8[1] = -local_88;
      piVar4 = local_90;
      pfVar8 = pfVar8 + 4;
    }
    local_8c = local_8c + 1;
    local_90 = piVar4 + 4;
  } while ((int)local_90 < 0x806c04);
  iVar5 = 0;
  iVar3 = local_94;
  do {
    if (8 < iVar3) break;
    if (acStack_1c[*(int *)((int)&DAT_00806c60 + iVar5)] !=
        acStack_1c[*(int *)((int)&DAT_00806c64 + iVar5)]) {
      iVar3 = *(int *)((int)&DAT_00806c00 + iVar5) * 0x10;
      iVar7 = iVar3 + local_84;
      local_80 = *(float *)(iVar3 + local_84) + local_70;
      local_7c = *(float *)(iVar7 + 4) + local_6c;
      local_78 = *(float *)(iVar7 + 8) + local_68;
      FUN_005c7fa0();
      iVar3 = local_94 + 1;
      local_94 = iVar3;
    }
    iVar5 = iVar5 + 8;
  } while (iVar5 < 0x60);
  __security_check_cookie(local_14 ^ (uint)&local_94);
  return;
}

