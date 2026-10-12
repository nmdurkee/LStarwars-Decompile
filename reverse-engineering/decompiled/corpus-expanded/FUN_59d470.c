/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59d470; label: FUN_0059d470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059d470(int param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float local_8;
  float local_4;
  
  if (DAT_0093b0d8 == 0) {
    fVar3 = (float10)1;
  }
  else {
    fVar3 = (float10)FUN_00547ab0(DAT_0093b0d8);
  }
  local_8 = (float)fVar3;
  local_4 = _DAT_009562a8;
  if (DAT_009562b4 == 0) {
    if (_DAT_00950780 == 0.0) {
      _DAT_009562a8 = _DAT_00925018 + _DAT_009562a8;
    }
    if (_DAT_009562b0 <= 0.0) {
      if ((*(uint *)(param_1 + 0x44) & DAT_008022a0) == 0) {
        if (_DAT_00805434 < _DAT_009562a8 != (_DAT_00805434 == _DAT_009562a8)) {
          _DAT_009562b0 = 0.001;
        }
      }
      else {
        _DAT_009562b0 = 0.001;
      }
    }
    else {
      _DAT_009562b0 = _DAT_00925018 + _DAT_009562b0;
      if (1.1 < _DAT_009562b0 == (_DAT_009562b0 == 1.1)) {
        if ((0.0 < _DAT_009562b8) &&
           (_DAT_009562b8 = _DAT_009562b8 - _DAT_00925018, _DAT_009562b8 < 0.0)) {
          _DAT_009562b8 = 0.0;
        }
      }
      else {
        DAT_009562b4 = 1;
        _DAT_009562b8 = 0.0;
        _DAT_009562a8 = 0.0;
      }
    }
    local_4 = _DAT_009562b8 * local_8;
    FUN_00547a30(local_4);
    return;
  }
  FUN_00547a30(0);
  _DAT_009562a8 = _DAT_00925018 + _DAT_009562a8;
  if (DAT_009562b4 == 1) {
    if ((local_4 < 0.1) && (0.1 <= _DAT_009562a8)) {
      FUN_00693fd0(0);
      FUN_00548e90();
      FUN_00652ad0();
    }
    fVar1 = _DAT_009562a8;
    if (1.0 <= _DAT_009562a8) {
      DAT_009562b4 = 2;
      FUN_00547930(0x2b,0,0,0);
      fVar1 = 1.0;
    }
  }
  else if (DAT_009562b4 == 2) {
    if (3.0 < _DAT_009562a8 != (_DAT_009562a8 == 3.0)) {
      DAT_009562b4 = 3;
      _DAT_009562a8 = 0.0;
    }
    local_8 = 1.0;
    fVar1 = local_8;
  }
  else {
    if (1.1 < _DAT_009562a8 != (_DAT_009562a8 == 1.1)) {
      DAT_00951b80 = DAT_00951b94;
      local_8 = 4.2039e-45;
      FUN_005b1220(&local_8,0);
    }
    fVar1 = 1.0 - _DAT_009562a8;
    if (1.0 - _DAT_009562a8 < 0.0) {
      local_8 = 0.0;
      fVar1 = local_8;
    }
  }
  local_8 = fVar1;
  iVar2 = FUN_006e6b90();
  _DAT_009562b8 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
  return;
}

