/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67be60; label: FUN_0067be60
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

