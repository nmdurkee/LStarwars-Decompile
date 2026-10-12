/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab5a0; label: FUN_004ab5a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ab5a0(int param_1,int param_2,int param_3)

{
  float fVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) goto LAB_004ab5db;
  }
  else {
    FUN_00438230(0,param_1,1,0,0,1);
  }
  FUN_0054aae0(param_1,0x3f333333);
LAB_004ab5db:
  fVar1 = *(float *)(param_1 + 0xc44) * 0.5;
  *(float *)(param_1 + 0xc44) = fVar1;
  if (fVar1 < _DAT_007fc17c) {
    *(float *)(param_1 + 0xc44) = _DAT_007fc17c;
    return;
  }
  return;
}

