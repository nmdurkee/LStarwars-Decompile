/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550f10; label: FUN_00550f10
 */

float10 FUN_00550f10(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  
  iVar1 = FUN_005be2d0(*param_3 - *param_2,param_3[2] - param_2[2]);
  return (float10)ABS((param_1[2] - param_2[2]) * (float)(&DAT_029899a0)[(-iVar1 & 0xffffU) >> 1] +
                      (*param_1 - *param_2) *
                      (float)(&DAT_029899a0)[(int)((-iVar1 & 0xffffU) + 0x4000) >> 1 & 0x7fff]);
}

