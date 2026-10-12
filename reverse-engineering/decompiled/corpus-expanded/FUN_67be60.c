/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67be60; label: FUN_0067be60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067be60(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  DAT_02921838 = param_1;
  DAT_02947c60 = 2;
  iVar1 = FUN_006e6b90();
  local_c = (&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
  local_8 = 0;
  iVar1 = FUN_006e6b90();
  local_4 = -(float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
  FUN_0067ab50(&local_c,param_2);
  return;
}

