/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a70c0; label: FUN_006a70c0
 */

float10 FUN_006a70c0(float param_1,float param_2)

{
  float10 fVar1;
  
  if (param_1 <= 0.0) {
    if (param_2 < 0.0) {
      fVar1 = (float10)FUN_006e9530();
      return (float10)(float)-fVar1;
    }
    if (param_2 < -param_1) {
      fVar1 = (float10)FUN_006e9530();
      return (float10)(float)-fVar1;
    }
    fVar1 = (float10)FUN_006e9530();
    return (float10)(float)fVar1;
  }
  if (0.0 < param_2) {
    fVar1 = (float10)FUN_006e9530();
    return (float10)(float)fVar1;
  }
  if (-param_2 < param_1) {
    fVar1 = (float10)FUN_006e9530();
    return (float10)(float)fVar1;
  }
  fVar1 = (float10)FUN_006e9530();
  return (float10)(float)-fVar1;
}

