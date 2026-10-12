/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x522e30; label: FUN_00522e30
 */

void FUN_00522e30(undefined4 param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  short sVar4;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar5;
  float local_60 [2];
  float local_58;
  float afStack_54 [2];
  float fStack_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  pfVar1 = (float *)(unaff_ESI + 0x18);
  pfVar2 = (float *)(unaff_EDI + 0x18);
  fVar5 = (float10)FUN_005bed80(pfVar2,pfVar1,local_60);
  fVar3 = (float)fVar5;
  if (0.0 < fVar3) {
    local_60[0] = local_60[0] / fVar3;
    local_58 = local_58 / fVar3;
  }
  if (*(float *)(unaff_ESI + 0x24) == *(float *)(unaff_EDI + 0x24)) {
    local_48 = *pfVar2 + local_58 * *(float *)(unaff_EDI + 0x24);
    local_40 = *(float *)(unaff_EDI + 0x20) - local_60[0] * *(float *)(unaff_EDI + 0x24);
    local_30 = param_1;
    local_c = param_1;
    local_24 = *pfVar1 + *(float *)(unaff_ESI + 0x24) * local_58;
    local_1c = *(float *)(unaff_ESI + 0x20) - *(float *)(unaff_ESI + 0x24) * local_60[0];
    local_44 = *(float *)(unaff_EDI + 0x28) + *(float *)(unaff_EDI + 0x1c);
    local_20 = *(float *)(unaff_ESI + 0x28) + *(float *)(unaff_ESI + 0x1c);
    FUN_00512b00(&local_48,0,0);
    local_44 = *(float *)(unaff_EDI + 0x2c) + *(float *)(unaff_EDI + 0x1c);
    local_20 = *(float *)(unaff_ESI + 0x2c) + *(float *)(unaff_ESI + 0x1c);
    FUN_00512b00(&local_48,0,0);
    local_48 = *pfVar2 - local_58 * *(float *)(unaff_EDI + 0x24);
    local_40 = *(float *)(unaff_EDI + 0x20) + local_60[0] * *(float *)(unaff_EDI + 0x24);
    local_24 = *pfVar1 - *(float *)(unaff_ESI + 0x24) * local_58;
    local_30 = param_1;
    local_c = param_1;
    local_1c = local_60[0] * *(float *)(unaff_ESI + 0x24) + *(float *)(unaff_ESI + 0x20);
    local_44 = *(float *)(unaff_EDI + 0x28) + *(float *)(unaff_EDI + 0x1c);
    local_20 = *(float *)(unaff_ESI + 0x28) + *(float *)(unaff_ESI + 0x1c);
    FUN_00512b00(&local_48,0,0);
    local_44 = *(float *)(unaff_EDI + 0x2c) + *(float *)(unaff_EDI + 0x1c);
    local_20 = *(float *)(unaff_ESI + 0x2c) + *(float *)(unaff_ESI + 0x1c);
    FUN_00512b00(&local_48,0,0);
    return;
  }
  sVar4 = FUN_00512900((*(float *)(unaff_ESI + 0x24) - *(float *)(unaff_EDI + 0x24)) / fVar3);
  FUN_005b3620(afStack_54,local_60,(int)(short)(0x4000 - sVar4));
  local_48 = *pfVar2 + afStack_54[0] * *(float *)(unaff_EDI + 0x24);
  local_40 = *(float *)(unaff_EDI + 0x20) + fStack_4c * *(float *)(unaff_EDI + 0x24);
  local_30 = param_1;
  local_c = param_1;
  local_24 = *pfVar1 + *(float *)(unaff_ESI + 0x24) * afStack_54[0];
  local_1c = fStack_4c * *(float *)(unaff_ESI + 0x24) + *(float *)(unaff_ESI + 0x20);
  local_44 = *(float *)(unaff_EDI + 0x28) + *(float *)(unaff_EDI + 0x1c);
  local_20 = *(float *)(unaff_ESI + 0x28) + *(float *)(unaff_ESI + 0x1c);
  FUN_00512b00(&local_48,0,0);
  local_44 = *(float *)(unaff_EDI + 0x2c) + *(float *)(unaff_EDI + 0x1c);
  local_20 = *(float *)(unaff_ESI + 0x2c) + *(float *)(unaff_ESI + 0x1c);
  FUN_00512b00(&local_48,0,0);
  FUN_005b3620(afStack_54,local_60,-(int)(short)(0x4000 - sVar4));
  local_48 = *pfVar2 + afStack_54[0] * *(float *)(unaff_EDI + 0x24);
  local_40 = *(float *)(unaff_EDI + 0x20) + fStack_4c * *(float *)(unaff_EDI + 0x24);
  local_30 = param_1;
  local_c = param_1;
  local_24 = *pfVar1 + *(float *)(unaff_ESI + 0x24) * afStack_54[0];
  local_1c = fStack_4c * *(float *)(unaff_ESI + 0x24) + *(float *)(unaff_ESI + 0x20);
  local_44 = *(float *)(unaff_EDI + 0x28) + *(float *)(unaff_EDI + 0x1c);
  local_20 = *(float *)(unaff_ESI + 0x28) + *(float *)(unaff_ESI + 0x1c);
  FUN_00512b00(&local_48,0,0);
  local_44 = *(float *)(unaff_EDI + 0x2c) + *(float *)(unaff_EDI + 0x1c);
  local_20 = *(float *)(unaff_ESI + 0x2c) + *(float *)(unaff_ESI + 0x1c);
  FUN_00512b00(&local_48,0,0);
  return;
}

