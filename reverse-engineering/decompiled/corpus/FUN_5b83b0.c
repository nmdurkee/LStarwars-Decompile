/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b83b0; label: FUN_005b83b0
 */

void FUN_005b83b0(float *param_1,float *param_2)

{
  if (param_1[3] * param_2[3] +
      param_1[2] * param_2[2] + *param_1 * *param_2 + param_1[1] * param_2[1] < 0.0) {
    *param_2 = -*param_2;
    param_2[1] = -param_2[1];
    param_2[2] = -param_2[2];
    param_2[3] = -param_2[3];
  }
  return;
}

