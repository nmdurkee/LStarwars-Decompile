/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x5149b0; label: FUN_005149b0
 */

float FUN_005149b0(undefined4 param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_4;
  
  local_4 = 1.0;
  if (param_2 != 0) {
    iVar1 = FUN_004f1ff0(param_2);
    if (iVar1 != 0) {
      fVar2 = (float10)FUN_004f28e0(param_2);
      local_4 = (float)fVar2;
    }
  }
  return local_4;
}

