/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571ea0; label: FUN_00571ea0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571ea0(float *param_1,int param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 != 0) {
    FUN_0054fec0(param_2,0,0);
    *param_1 = DAT_00802500;
    iVar4 = DAT_008034b0 * 2;
    param_1[1] = DAT_00802504;
    param_1[2] = DAT_00802508;
    iVar4 = (int)(0xffff / (longlong)(((iVar4 + 1) * 0x10000) / 0x168)) + 1;
    iVar2 = FUN_0054fa60();
    iVar5 = DAT_008034b0 * 0x10000;
    iVar3 = FUN_0054fa60();
    iVar6 = DAT_008034b0 * 0x10000;
    FUN_005b3690(param_1,param_1,
                 DAT_0092b0c0 +
                 ((short)(iVar2 / iVar4) -
                 ((short)((ulonglong)((longlong)iVar5 * 0xb60b60b7) >> 0x28) -
                 ((short)(char)((char)(iVar5 / 0x1680000) + (char)(iVar5 >> 0x1f)) >> 0xf))));
    FUN_005b35a0(param_1,param_1,
                 DAT_0092b0c4 +
                 ((short)(iVar3 / iVar4) -
                 ((short)((ulonglong)((longlong)iVar6 * 0xb60b60b7) >> 0x28) -
                 ((short)(char)((char)(iVar6 / 0x1680000) + (char)(iVar6 >> 0x1f)) >> 0xf))));
    FUN_005b3830(param_1,param_1,param_3);
    return;
  }
  iVar4 = FUN_0054fa60();
  *param_1 = ((float)iVar4 * 1.5259022e-05 + (float)iVar4 * 1.5259022e-05) - 1.0;
  fVar1 = 0.0;
  if (_DAT_00950f5c != 0.0) {
    iVar4 = FUN_0054fa60();
    fVar1 = (float)iVar4 * 1.5259022e-05 + 1.0;
  }
  param_1[1] = fVar1;
  iVar4 = FUN_0054fa60();
  param_1[2] = ((float)iVar4 * 1.5259022e-05 + (float)iVar4 * 1.5259022e-05) - 1.0;
  FUN_005b3830(param_1,param_1,DAT_00950f60);
  return;
}

