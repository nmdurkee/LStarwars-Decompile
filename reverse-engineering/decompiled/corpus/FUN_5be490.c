/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5be490; label: FUN_005be490
 */

float10 FUN_005be490(float param_1,float param_2)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = 0.0;
  if (param_1 == 0.0) {
    if (param_2 < 0.0) {
      fVar1 = 32768.0;
    }
    return (float10)fVar1;
  }
  if (param_2 == 0.0) {
    if (param_1 < 0.0) {
      return (float10)-16384.0;
    }
    return (float10)16384.0;
  }
  if (0.0 <= param_1) {
    if (param_2 < 0.0) {
      fVar2 = (float10)FUN_005be1c0(param_1,-param_2);
      return (float10)(float)((float10)32768.0 - fVar2);
    }
    fVar2 = (float10)FUN_005be1c0(param_1,param_2);
    return fVar2;
  }
  if (param_2 < 0.0) {
    fVar2 = (float10)FUN_005be1c0(-param_1,-param_2);
    return (float10)(float)(fVar2 - (float10)32768.0);
  }
  fVar2 = (float10)FUN_005be1c0(-param_1,param_2);
  return -fVar2;
}

