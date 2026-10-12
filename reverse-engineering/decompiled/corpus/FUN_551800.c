/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x551800; label: FUN_00551800
 */

undefined4 FUN_00551800(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_3 - *param_1;
  fVar2 = param_3[2] - param_1[2];
  fVar3 = fVar2 * param_2[2] + fVar1 * *param_2;
  if ((0.0 <= fVar3) && ((fVar1 * fVar1 + fVar2 * fVar2) - fVar3 * fVar3 <= param_4)) {
    return 1;
  }
  return 0;
}

