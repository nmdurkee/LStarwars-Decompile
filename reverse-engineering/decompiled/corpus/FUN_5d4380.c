/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d4380; label: FUN_005d4380
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d4380(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float afStack_5c [22];
  
  if (DAT_0096e53c == 0) {
    puVar5 = &DAT_009736e8;
    puVar6 = &DAT_0097acd0;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  _DAT_009715a4 = *param_1;
  _DAT_009715a8 = param_1[1];
  _DAT_009715ac = param_1[2];
  iVar4 = 0;
  local_b8 = _DAT_0080bfac * _DAT_0097ace0 * _DAT_009715a8 +
             _DAT_0080bfa8 * DAT_0097acd0 * _DAT_009715a4 + _DAT_0097ad00 +
             _DAT_0080bfb0 * _DAT_0097acf0 * _DAT_009715ac;
  local_b4 = _DAT_0080bfb0 * _DAT_0097acf4 * _DAT_009715ac +
             _DAT_0080bfac * _DAT_0097ace4 * _DAT_009715a8 +
             DAT_0097acd4 * _DAT_009715a4 * _DAT_0080bfa8 + _DAT_0097ad04;
  local_b0 = _DAT_0080bfb0 * _DAT_0097acf8 * _DAT_009715ac +
             _DAT_0080bfac * _DAT_0097ace8 * _DAT_009715a8 +
             _DAT_0080bfa8 * _DAT_0097acd8 * _DAT_009715a4 + _DAT_0097ad08;
  local_ac = local_b8;
  local_a8 = local_b4;
  local_a4 = local_b0;
  do {
    fVar1 = *(float *)((int)&DAT_0080bfbc + iVar4) * _DAT_0097acf0 * _DAT_009715ac +
            *(float *)((int)&DAT_0080bfb8 + iVar4) * _DAT_0097ace0 * _DAT_009715a8 +
            *(float *)((int)&DAT_0080bfb4 + iVar4) * DAT_0097acd0 * _DAT_009715a4 + _DAT_0097ad00;
    *(float *)((int)afStack_5c + iVar4) = fVar1;
    fVar3 = *(float *)((int)&DAT_0080bfbc + iVar4) * _DAT_0097acf4 * _DAT_009715ac +
            *(float *)((int)&DAT_0080bfb8 + iVar4) * _DAT_0097ace4 * _DAT_009715a8 +
            *(float *)((int)&DAT_0080bfb4 + iVar4) * DAT_0097acd4 * _DAT_009715a4 + _DAT_0097ad04;
    *(float *)((int)afStack_5c + iVar4 + 4) = fVar3;
    fVar2 = *(float *)((int)&DAT_0080bfbc + iVar4) * _DAT_0097acf8 * _DAT_009715ac +
            *(float *)((int)&DAT_0080bfb8 + iVar4) * _DAT_0097ace8 * _DAT_009715a8 +
            *(float *)((int)&DAT_0080bfb4 + iVar4) * _DAT_0097acd8 * _DAT_009715a4 + _DAT_0097ad08;
    *(float *)((int)afStack_5c + iVar4 + 8) = fVar2;
    if (fVar1 < local_b8) {
      local_b8 = fVar1;
    }
    if (fVar3 < local_b4) {
      local_b4 = fVar3;
    }
    if (fVar2 < local_b0) {
      local_b0 = fVar2;
    }
    if (local_ac < fVar1) {
      local_ac = fVar1;
    }
    if (local_a8 < fVar3) {
      local_a8 = fVar3;
    }
    if (local_a4 < fVar2) {
      local_a4 = fVar2;
    }
    iVar4 = iVar4 + 0xc;
  } while (iVar4 < 0x54);
  _DAT_0096d9c4 = (local_ac + local_b8) * 0.5 - _DAT_009715a4 * 0.5;
  _DAT_0096d9c8 = (local_a8 + local_b4) * 0.5 - _DAT_009715a8 * 0.5;
  _DAT_0096d9cc = (local_a4 + local_b0) * 0.5 - _DAT_009715ac * 0.5;
  _DAT_00971584 = 1.0 / _DAT_009715a4;
  _DAT_00971588 = 1.0 / _DAT_009715a8;
  _DAT_0097158c = 1.0 / _DAT_009715ac;
  return;
}

