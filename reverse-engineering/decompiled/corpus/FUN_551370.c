/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x551370; label: FUN_00551370
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

