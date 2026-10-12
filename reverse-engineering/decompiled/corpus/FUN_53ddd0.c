/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53ddd0; label: FUN_0053ddd0
 */

float10 FUN_0053ddd0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  
  fVar1 = (param_1[2] - param_2[2]) * param_3[2] +
          (*param_1 - *param_2) * *param_3 + (param_1[1] - param_2[1]) * param_3[1];
  return (float10)(fVar1 / ((param_1[2] - param_4[2]) * param_5[2] +
                            (*param_1 - *param_4) * *param_5 +
                            (param_1[1] - param_4[1]) * param_5[1] + fVar1));
}

