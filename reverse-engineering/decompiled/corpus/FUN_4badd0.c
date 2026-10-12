/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4badd0; label: FUN_004badd0
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

