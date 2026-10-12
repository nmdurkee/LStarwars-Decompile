/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40fd80; label: FUN_0040fd80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040fd80(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  float local_60;
  float local_50;
  float local_48;
  float local_40;
  float local_38;
  
  local_50 = *param_1 - _DAT_00855e00;
  fVar1 = param_1[1];
  local_48 = param_1[2] - _DAT_00855e08;
  fVar2 = param_2[1];
  fVar5 = (float10)FUN_005c0240(local_50 * local_50 + 0.0 + local_48 * local_48);
  local_40 = _DAT_00855e20 - _DAT_00855e00;
  local_38 = _DAT_00855e28 - _DAT_00855e08;
  fVar6 = (float10)FUN_005c0240(local_40 * local_40 + 0.0 + local_38 * local_38);
  fVar4 = _DAT_00855e08;
  _DAT_00855df0 = (float)fVar6;
  if (_DAT_007f15e4 <= _DAT_00855df0) {
    if (_DAT_00855df0 <= _DAT_007f15e8) {
      local_60 = _DAT_00855df0;
    }
    else {
      local_60 = _DAT_007f15e8;
    }
  }
  else {
    local_60 = _DAT_007f15e4;
  }
  if ((float)fVar5 != 0.0) {
    fVar3 = (local_60 + _DAT_007f15ec * (_DAT_00855df0 - local_60)) / (float)fVar5;
    local_50 = fVar3 * local_50;
    local_48 = fVar3 * local_48;
  }
  *param_1 = _DAT_00855e00 + local_50;
  param_1[1] = fVar1;
  param_1[2] = fVar4 + local_48;
  fVar4 = _DAT_00855e08;
  fVar1 = _DAT_007f15f4;
  if (_DAT_00855df0 < local_60) {
    fVar1 = _DAT_007f15f0;
  }
  if (_DAT_00855df0 != 0.0) {
    fVar1 = ((_DAT_00855df0 - local_60) * fVar1 + local_60) / _DAT_00855df0;
    local_40 = fVar1 * local_40;
    local_38 = fVar1 * local_38;
  }
  *param_2 = _DAT_00855e00 + local_40;
  param_2[1] = fVar2;
  param_2[2] = fVar4 + local_38;
  return;
}

