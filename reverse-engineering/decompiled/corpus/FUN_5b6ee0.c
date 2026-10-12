/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b6ee0; label: FUN_005b6ee0
 */

void FUN_005b6ee0(int param_1,float param_2,float param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(&DAT_029899a0)[param_1 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_1 + 0x4000 >> 1 & 0x7fff];
  *param_4 = param_2 * fVar2 - param_3 * fVar1;
  *param_5 = fVar2 * param_3 + fVar1 * param_2;
  return;
}

