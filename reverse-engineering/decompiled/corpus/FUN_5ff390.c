/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5ff390; label: FUN_005ff390
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ff390(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_28;
  int local_24;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_0095e674 == 0) {
    return;
  }
  _DAT_028492f8 = 1.0;
  _DAT_00992294 = 0.0;
  _DAT_00981c94 = 0.0;
  local_8 = DAT_00963e20;
  _DAT_00981c48 = 1.0;
  local_4 = DAT_00963e24;
  iVar1 = DAT_00963e10 + DAT_00963e18;
  iVar3 = DAT_00973900 * 0x10;
  iVar4 = DAT_00973904 * 0x10;
  iVar2 = DAT_00963e14 + DAT_00963e1c;
  local_24 = DAT_00963e1c;
  local_28 = DAT_00963e18;
  if ((((-1 < iVar1) && (DAT_00963e10 < iVar3)) && (-1 < iVar2)) && (DAT_00963e14 < iVar4)) {
    local_18 = DAT_00963e10;
    if (DAT_00963e10 < 0) {
      local_18 = 0;
      local_28 = iVar1;
    }
    if (iVar3 < iVar1) {
      local_28 = local_28 + (iVar3 - iVar1);
    }
    local_14 = DAT_00963e14;
    if (DAT_00963e14 < 0) {
      local_14 = 0;
      local_24 = iVar2;
    }
    if (iVar4 < iVar2) {
      local_24 = local_24 + (iVar4 - iVar2);
    }
    if ((0 < local_28) && (0 < local_24)) {
      _DAT_028492f8 = (float)DAT_00963e18 / (float)local_28;
      _DAT_00981c48 = (float)DAT_00963e1c / (float)local_24;
      _DAT_00992294 = (float)(DAT_00963e18 - local_28) / (float)local_28;
      _DAT_00981c94 = -(float)(DAT_00963e1c - local_24) / (float)local_24;
      if (DAT_00963e10 < 0) {
        _DAT_00992294 = -_DAT_00992294;
      }
      if (DAT_00963e14 < 0) {
        _DAT_00981c94 = -_DAT_00981c94;
      }
      goto LAB_005ff54b;
    }
  }
  local_24 = 0;
  local_28 = 0;
  local_14 = 0;
  local_18 = 0;
LAB_005ff54b:
  local_c = local_24 >> 4;
  local_10 = local_28 >> 4;
  local_18 = local_18 >> 4;
  local_14 = local_14 >> 4;
  DAT_0095e674 = 0;
  FUN_006e57b0(&local_18);
  FUN_005b44e0(&DAT_0080ba68);
  FUN_005ff2d0();
  if ((_DAT_00963e30 == 0.0) && (_DAT_00963e38 == 1.0)) {
    _DAT_00963e40 = 1.0;
    _DAT_00963e48 = (float)DAT_00963e18 * 1.5258789e-05;
  }
  else {
    _DAT_00963e40 = 1.0 / (_DAT_00963e38 - _DAT_00963e30);
    _DAT_00963e48 = _DAT_00963e40;
  }
  if ((_DAT_00963e34 == 0.0) && (_DAT_00963e3c == 1.0)) {
    _DAT_00963e44 = 1.0;
    _DAT_00963e4c = (float)DAT_00963e1c * 1.5258789e-05;
    return;
  }
  _DAT_00963e4c = 1.0 / (_DAT_00963e3c - _DAT_00963e34);
  _DAT_00963e44 = _DAT_00963e4c;
  return;
}

