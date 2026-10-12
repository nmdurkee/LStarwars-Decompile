/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604a80; label: FUN_00604a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00604a80(float *param_1,undefined4 param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar3 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
  param_5 = param_5 / (param_5 - param_4);
  _memset(param_1,0,0x40);
  *param_1 = (fVar1 / fVar2) * param_3;
  param_1[5] = fVar1 / fVar2;
  param_1[10] = param_5;
  param_1[0xb] = 1.0;
  param_1[0xe] = -param_5 * param_4;
  DAT_0080b748 = DAT_0080b748 * _DAT_028492f8;
  _DAT_0080b75c = _DAT_0080b75c * _DAT_00981c48;
  _DAT_0080b768 = _DAT_00992294;
  _DAT_0080b76c = _DAT_00981c94;
  return;
}

