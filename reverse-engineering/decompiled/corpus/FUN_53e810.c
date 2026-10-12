/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53e810; label: FUN_0053e810
 */

void FUN_0053e810(float *param_1,int param_2,int param_3,int param_4,float param_5)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 8);
  pfVar1 = (float *)(iVar3 + param_3 * 0xc);
  iVar2 = iVar3 + param_4 * 0xc;
  *param_1 = *pfVar1 + param_5 * (*(float *)(iVar3 + param_4 * 0xc) - *pfVar1);
  param_1[1] = (*(float *)(iVar2 + 4) - pfVar1[1]) * param_5 + pfVar1[1];
  param_1[2] = (*(float *)(iVar2 + 8) - pfVar1[2]) * param_5 + pfVar1[2];
  return;
}

