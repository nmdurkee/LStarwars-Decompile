/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a8b60; label: FUN_004a8b60
 */

void FUN_004a8b60(int param_1)

{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float local_c [2];
  float local_4;
  
  uVar4 = FUN_006e6b90();
  uVar5 = uVar4 & 0x80000001;
  bVar6 = uVar5 == 0;
  if ((int)uVar5 < 0) {
    bVar6 = (uVar5 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if ((bVar6) && ((float)(int)uVar4 != *(float *)(param_1 + 0x780))) {
    *(float *)(param_1 + 0x780) = (float)(int)uVar4;
    DAT_007fc140 = 0;
    do {
      fVar7 = (float10)FUN_005b9ef0(&DAT_00802538);
      if (fVar7 < (float10)0.5) {
        DAT_007fc140 = DAT_007fc140 | 1;
      }
      fVar7 = (float10)FUN_005b9ef0(&DAT_00802538);
      if (fVar7 < (float10)0.5) {
        DAT_007fc140 = DAT_007fc140 | 2;
      }
      fVar7 = (float10)FUN_005b9ef0(&DAT_00802538);
      if (fVar7 < (float10)0.5) {
        DAT_007fc140 = DAT_007fc140 | 4;
      }
    } while ((DAT_007fc140 & 5) == 0);
  }
  if ((DAT_007fc140 & 1) != 0) {
    uVar3 = FUN_00550070((uint)*(ushort *)(param_1 + 0x278),*(ushort *)(param_1 + 0x278) + 0x4000,
                         0x40400000);
    *(undefined2 *)(param_1 + 0x278) = uVar3;
  }
  if ((DAT_007fc140 & 2) != 0) {
    uVar3 = FUN_00550070((uint)*(ushort *)(param_1 + 0x27a),*(ushort *)(param_1 + 0x27a) + 0x4000,
                         0x40400000);
    *(undefined2 *)(param_1 + 0x27a) = uVar3;
  }
  if ((DAT_007fc140 & 4) != 0) {
    uVar3 = FUN_00550070((uint)*(ushort *)(param_1 + 0x27c),*(ushort *)(param_1 + 0x27c) + 0x4000,
                         0x40400000);
    *(undefined2 *)(param_1 + 0x27c) = uVar3;
  }
  fVar8 = (float10)FUN_005b3c50(param_1 + 0x80,param_1 + 0x748,local_c);
  fVar2 = local_4;
  fVar1 = local_c[0];
  fVar7 = (float10)1;
  fVar9 = fVar7 / (float10)((local_c[0] + 0.01) / (local_4 + 0.01));
  fVar8 = (float10)(float)((float10)75.0 / (fVar8 / (float10)6.0 + fVar7));
  local_c[0] = (float)(fVar8 * (fVar7 - fVar9));
  local_4 = (float)(fVar8 * fVar9);
  if (local_c[0] <= 100.0) {
    if (100.0 < local_4) {
      local_4 = 100.0;
    }
  }
  else {
    local_c[0] = 100.0;
  }
  if ((0.0 <= fVar1) || (local_c[0] <= 0.0)) {
    if ((0.0 < fVar1) && (local_c[0] < 0.0)) {
      local_c[0] = -local_c[0];
    }
  }
  else {
    local_c[0] = -local_c[0];
  }
  if ((0.0 <= fVar2) || (local_4 <= 0.0)) {
    if ((0.0 < fVar2) && (local_4 < 0.0)) {
      local_4 = -local_4;
    }
  }
  else {
    local_4 = -local_4;
  }
  *(float *)(param_1 + 0x200) = local_c[0];
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(float *)(param_1 + 0x208) = local_4;
  return;
}

