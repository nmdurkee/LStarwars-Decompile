/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x551370; label: FUN_00551370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00551370(undefined4 param_1,undefined4 param_2,float param_3)

{
  float *in_ECX;
  float *in_EDX;
  float10 fVar1;
  
  if (in_ECX[2] < 0.0) {
    *in_EDX = 0.0;
    fVar1 = (float10)FUN_005bed80();
    return fVar1;
  }
  if (param_3 < in_ECX[2]) {
    *in_EDX = 1.0;
    fVar1 = (float10)FUN_005bed80(param_2);
    return fVar1;
  }
  *in_EDX = in_ECX[2] / param_3;
  return (float10)ABS(*in_ECX);
}

