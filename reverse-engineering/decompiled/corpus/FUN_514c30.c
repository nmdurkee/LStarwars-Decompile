/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514c30; label: FUN_00514c30
 */

float10 FUN_00514c30(int param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_1 != 0)) &&
     (*(int *)(param_1 + 0x138c) != 0)) {
    fVar1 = (float10)FUN_005becc0(*(int *)(param_1 + 0x138c) + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,
                                  local_c);
    return fVar1;
  }
  return (float10)3.4028235e+38;
}

