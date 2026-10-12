/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x656e50; label: FUN_00656e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00656e50(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 extraout_ECX;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  
  iVar3 = (int)param_2;
  FUN_0064ff80();
  FUN_005b4900(extraout_ECX,(int)param_2 + 400);
  fVar1 = *(float *)((int)param_1 + 0x20) + *(float *)((int)param_1 + 0x1c);
  local_58 = ABS(*(float *)((int)param_1 + 100)) * fVar1 +
             *(float *)((int)param_1 + 0x4c) * *(float *)((int)param_1 + 0xa4) +
             *(float *)((int)param_1 + 0x58);
  local_54 = ABS(*(float *)((int)param_1 + 0x68)) * fVar1 +
             (*(float *)((int)param_1 + 0x50) + ABS(*(float *)((int)param_1 + 0x48))) *
             *(float *)((int)param_1 + 0xa4) + *(float *)((int)param_1 + 0x5c);
  local_50 = *(float *)((int)param_1 + 0x54) * *(float *)((int)param_1 + 0xa4) +
             ABS(*(float *)((int)param_1 + 0x6c)) * fVar1 + *(float *)((int)param_1 + 0x60);
  FUN_005b3200(&local_58,&local_58,(int)param_2 + 0x80);
  if (local_58 < 0.0) {
    local_58 = -local_58;
  }
  if (local_54 < 0.0) {
    local_54 = -local_54;
  }
  if (local_50 < 0.0) {
    local_50 = -local_50;
  }
  fVar1 = *(float *)((int)param_1 + 0x14c) * 0.0001;
  local_58 = fVar1 + local_58 + 0.2;
  local_54 = fVar1 + local_54 + 0.2;
  local_50 = local_50 + fVar1 + 0.2;
  local_4c = -local_58;
  local_48 = -local_54;
  local_44 = -local_50;
  if (*(float *)((int)param_1 + 0xa0) <= 0.0) {
    if (*(float *)((int)param_1 + 0xa0) < 0.0) {
      local_48 = *(float *)((int)param_1 + 0xa4) * *(float *)((int)param_1 + 0xa0) *
                 *(float *)((int)param_1 + 0xa4) + local_48;
    }
  }
  else {
    local_54 = *(float *)((int)param_1 + 0xa4) * *(float *)((int)param_1 + 0xa0) *
               *(float *)((int)param_1 + 0xa4) + local_54;
  }
  param_2 = local_50;
  if (local_50 < local_58) {
    param_2 = local_58;
  }
  fVar1 = -local_48;
  param_1 = fVar1;
  if (fVar1 < local_54) {
    param_1 = local_54;
  }
  if (param_2 <= param_1) {
    fVar2 = local_54;
    if (local_54 <= fVar1) goto LAB_006570b4;
  }
  else {
    fVar1 = local_58;
    fVar2 = local_50;
    if (local_50 < local_58) goto LAB_006570b4;
  }
  fVar1 = fVar2;
LAB_006570b4:
  *(float *)(iVar3 + 0x300) = fVar1;
  *(float *)(iVar3 + 0x304) = local_4c;
  *(float *)(iVar3 + 0x308) = local_48;
  *(float *)(iVar3 + 0x310) = local_58;
  *(float *)(iVar3 + 0x30c) = local_44;
  *(float *)(iVar3 + 0x314) = local_54;
  *(float *)(iVar3 + 0x318) = local_50;
  FUN_0064ff80();
  return;
}

