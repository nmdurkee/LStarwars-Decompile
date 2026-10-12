/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b7670; label: FUN_005b7670
 */

void FUN_005b7670(float *param_1,undefined4 param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  int iVar2;
  float10 extraout_ST0;
  
  FUN_006e6b90();
  iVar2 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[0x4000 - iVar2 >> 1 & 0x7fff];
  *param_1 = 1.0 / ((float)(extraout_ST0 / (float10)fVar1) * param_3);
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  param_1[5] = 1.0 / (float)(extraout_ST0 / (float10)fVar1);
  param_1[6] = 0.0;
  param_1[7] = 0.0;
  param_1[8] = 0.0;
  param_1[9] = 0.0;
  param_1[10] = param_5 / (param_5 - param_4);
  param_1[0xb] = 1.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = (-param_5 * param_4) / (param_5 - param_4);
  param_1[0xf] = 0.0;
  return;
}

