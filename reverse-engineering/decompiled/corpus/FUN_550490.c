/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550490; label: FUN_00550490
 */

undefined4 FUN_00550490(float *param_1,int param_2,float param_3,float param_4,float *param_5)

{
  int iVar1;
  float *pfVar2;
  
  if (param_2 == 1) {
    pfVar2 = param_5;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar2 = *param_1;
      param_1 = param_1 + 1;
      pfVar2 = pfVar2 + 1;
    }
    *param_5 = -*param_5;
    param_5[4] = -param_5[4];
    param_5[8] = -param_5[8];
    param_5[0xc] = param_3 - (param_5[0xc] - param_3);
    return 1;
  }
  if (param_2 != 2) {
    if (param_2 != 3) {
      return 0;
    }
    pfVar2 = param_5;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar2 = *param_1;
      param_1 = param_1 + 1;
      pfVar2 = pfVar2 + 1;
    }
    param_5[2] = -param_5[2];
    param_5[6] = -param_5[6];
    param_5[10] = -param_5[10];
    param_5[0xe] = param_3 - (param_5[0xe] - param_3);
    return 1;
  }
  if (param_4 != 2e+06) {
    if (DAT_0093b0e0 != (code *)0x0) {
      iVar1 = (*DAT_0093b0e0)();
      if (iVar1 == 0) goto LAB_00550515;
    }
    param_3 = param_4;
  }
LAB_00550515:
  pfVar2 = param_5;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar2 = *param_1;
    param_1 = param_1 + 1;
    pfVar2 = pfVar2 + 1;
  }
  param_5[1] = -param_5[1];
  param_5[5] = -param_5[5];
  param_5[9] = -param_5[9];
  param_5[0xd] = param_3 - (param_5[0xd] - param_3);
  return 1;
}

