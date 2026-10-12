/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b79d0; label: FUN_005b79d0
 */

void FUN_005b79d0(float *param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7)

{
  *param_1 = 2.0 / (param_3 - param_2);
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  param_1[5] = 2.0 / (param_5 - param_4);
  param_1[6] = 0.0;
  param_1[7] = 0.0;
  param_1[8] = 0.0;
  param_1[9] = 0.0;
  param_1[10] = 2.0 / (param_7 - param_6);
  param_1[0xb] = 0.0;
  param_1[0xc] = (param_2 + param_3) / (param_2 - param_3);
  param_1[0xd] = (param_4 + param_5) / (param_4 - param_5);
  param_1[0xe] = (param_7 + param_6) / (param_6 - param_7);
  param_1[0xf] = 1.0;
  return;
}

