/* Ghidra pseudocode, not original source.
 * ev_84daf39e48317c5610d39db166d0a8d3fb26fedafe51c8456603b097e41224df
 * Entry: 0x5ff100; label: FUN_005ff100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ff100(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = param_1;
  fVar1 = (float)DAT_00963e10;
  fVar3 = fVar1;
  if (fVar1 < param_1) {
    fVar3 = param_1;
  }
  param_1 = fVar3;
  _DAT_00963e38 = fVar1 + (float)DAT_00963e18 * 0.0625;
  _DAT_00963e30 = _DAT_00963e38;
  if ((param_1 < _DAT_00963e38) && (_DAT_00963e30 = fVar1, fVar1 < fVar2)) {
    _DAT_00963e30 = fVar2;
  }
  _DAT_00963e3c = (float)DAT_00963e14;
  param_1 = _DAT_00963e3c;
  if (_DAT_00963e3c < param_2) {
    param_1 = param_2;
  }
  fVar2 = _DAT_00963e3c + (float)DAT_00963e1c * 0.0625;
  _DAT_00963e34 = fVar2;
  if ((param_1 < fVar2) && (_DAT_00963e34 = _DAT_00963e3c, _DAT_00963e3c < param_2)) {
    _DAT_00963e34 = param_2;
  }
  param_1 = fVar1;
  if (fVar1 < param_3) {
    param_1 = param_3;
  }
  if ((param_1 < _DAT_00963e38) && (_DAT_00963e38 = fVar1, fVar1 < param_3)) {
    _DAT_00963e38 = param_3;
  }
  param_1 = _DAT_00963e3c;
  if (_DAT_00963e3c < param_4) {
    param_1 = param_4;
  }
  if (fVar2 <= param_1) {
    DAT_0095e674 = 1;
    _DAT_00963e3c = fVar2;
    return;
  }
  if (param_4 <= _DAT_00963e3c) {
    DAT_0095e674 = 1;
    return;
  }
  DAT_0095e674 = 1;
  _DAT_00963e3c = param_4;
  return;
}

