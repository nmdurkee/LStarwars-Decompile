/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4ab5a0; label: FUN_004ab5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

