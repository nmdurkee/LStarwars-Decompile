/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4badd0; label: FUN_004badd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004badd0(float param_1)

{
  float fVar1;
  
  if (param_1 == 0.0) {
    param_1 = 640.0;
    fVar1 = 448.0;
  }
  else {
    param_1 = _DAT_007fc3c4;
    fVar1 = _DAT_007fc3c8;
  }
  _DAT_0087b938 = 640.0 / (_DAT_007fc274 * (640.0 / param_1));
  _DAT_0087b998 = 224.0 / (_DAT_007fc278 * (224.0 / fVar1));
  return;
}

