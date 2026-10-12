/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b7a70; label: FUN_005b7a70
 */

void FUN_005b7a70(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_1[10];
  fVar2 = -param_1[0xe] / fVar1;
  if (param_7 != (float *)0x0) {
    *param_7 = (fVar2 * fVar1) / (fVar1 - 1.0);
  }
  if (param_2 != (float *)0x0) {
    *param_2 = ((-1.0 - param_1[8]) * fVar2) / *param_1;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = ((1.0 - param_1[8]) * fVar2) / *param_1;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = ((-1.0 - param_1[9]) * fVar2) / param_1[5];
  }
  if (param_5 != (float *)0x0) {
    *param_5 = (fVar2 * (1.0 - param_1[9])) / param_1[5];
  }
  if (param_6 == (float *)0x0) {
    return;
  }
  *param_6 = fVar2;
  return;
}

