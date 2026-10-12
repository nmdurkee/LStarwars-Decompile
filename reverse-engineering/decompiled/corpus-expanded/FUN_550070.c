/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550070; label: FUN_00550070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00550070(ushort param_1,ushort param_2,float param_3)

{
  uint uVar1;
  
  param_3 = _DAT_00925018 * param_3;
  if (1.0 < param_3) {
    param_3 = 1.0;
  }
  uVar1 = (uint)param_1;
  _param_1 = param_2 - uVar1;
  if (_param_1 < 0x8001) {
    if (_param_1 < -0x8000) {
      _param_1 = _param_1 + 0x10000;
    }
  }
  else {
    _param_1 = _param_1 + -0x10000;
  }
  return (int)ROUND((float)_param_1 * param_3 + (float)uVar1) & 0xffff;
}

