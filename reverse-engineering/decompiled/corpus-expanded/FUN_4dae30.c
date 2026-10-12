/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dae30; label: FUN_004dae30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dae30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((DAT_00882a70 != 2) || (*(float *)(DAT_00882a6c + 0xb004) <= 1.0)) || (DAT_00882a78 == 0))
  goto switchD_004dae77_default;
  switch(DAT_0087aa21) {
  case 0:
    if (_DAT_007ffd2c < *(float *)(PTR_DAT_008021b4 + 0x2c)) {
      FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"ep1_podrace_mushroom0",1);
      DAT_0087aa21 = 1;
    }
    break;
  case 1:
    if ((DAT_00882a74 != 0) && ((*(uint *)(*(int *)(DAT_00882a74 + 4) + 0x88) & 0x1000) != 0)) {
      FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"EP1_PODRACE_MUSHROOM1",1);
      _DAT_007ffd3c = _DAT_007ffd34;
      DAT_0087aa21 = 2;
    }
    break;
  case 2:
    _DAT_007ffd3c = _DAT_007ffd3c - _DAT_00925018;
    if (0.0 <= _DAT_007ffd3c) {
      if (_DAT_007ffd30 < *(float *)(PTR_DAT_008021b4 + 0x2c)) {
        DAT_0087aa21 = 3;
      }
      break;
    }
    FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"EP1_PODRACE_MUSHROOM2",1);
    DAT_00882900 = DAT_00882900 + 1;
    if (((0 < DAT_00882904) && (DAT_00882900 % DAT_00882904 == 0)) &&
       (_DAT_007ffd34 = _DAT_007ffd40 + _DAT_007ffd34, _DAT_007ffd38 < _DAT_007ffd34)) {
      _DAT_007ffd34 = _DAT_007ffd38;
    }
    goto LAB_004dafee;
  case 3:
    iVar1 = FUN_005cfac0(&DAT_0087aad8);
    if (iVar1 == 0) break;
    uVar2 = FUN_005d0330(&DAT_0087aad8);
    iVar1 = FUN_005d03c0(&DAT_0087aad8,uVar2);
    if (iVar1 != 0) break;
LAB_004dafee:
    DAT_0087aa21 = 4;
  }
switchD_004dae77_default:
  FUN_004da8c0(param_1);
  FUN_004da6c0(_DAT_00925018);
  FUN_004d9fa0(param_1,_DAT_00925018);
  if ((((DAT_00882a70 == 1) && (DAT_0087aa20 == '\0')) && (DAT_0087b014 != 0)) &&
     (((&DAT_0086e0f5)[(uint)*(byte *)(DAT_0087b014 + 0x7c) * 0xc] == '\0' &&
      (3.0 < _DAT_0092505c != (_DAT_0092505c == 3.0))))) {
    FUN_00576960(0x27e);
    DAT_0087aa20 = '\x01';
  }
  return;
}

