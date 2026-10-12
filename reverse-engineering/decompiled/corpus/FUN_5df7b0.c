/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5df7b0; label: FUN_005df7b0
 */

float10 FUN_005df7b0(float param_1,float param_2,float param_3)

{
  float10 fVar1;
  float10 fVar2;
  float local_8;
  
  if (param_3 <= param_2) {
    local_8 = 0.0;
    if (param_1 <= param_3 * param_3) goto LAB_005df86a;
    fVar1 = (float10)FUN_005c0240(param_1);
    fVar2 = (float10)1;
    fVar1 = (float10)(float)((fVar1 - (float10)param_3) / ((float10)param_2 - (float10)param_3));
    if (fVar1 <= fVar2) {
      return fVar1;
    }
  }
  else {
    local_8 = 1.0;
    if (param_1 <= param_2 * param_2) {
LAB_005df86a:
      return (float10)local_8;
    }
    fVar1 = (float10)FUN_005c0240(param_1);
    fVar2 = (float10)0;
    fVar1 = (float10)(float)(((float10)param_3 - fVar1) / ((float10)param_3 - (float10)param_2));
    if (fVar2 <= fVar1) {
      return fVar1;
    }
  }
  return (float10)(float)fVar2;
}

