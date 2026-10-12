/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53de40; label: FUN_0053de40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0053de40(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  
  iVar1 = FUN_005be2d0(*param_3 - *param_2,param_3[2] - param_2[2]);
  return (float10)ABS((param_1[2] - param_2[2]) * (float)(&DAT_029899a0)[(-iVar1 & 0xffffU) >> 1] +
                      (*param_1 - *param_2) *
                      (float)(&DAT_029899a0)[(int)((-iVar1 & 0xffffU) + 0x4000) >> 1 & 0x7fff]);
}

