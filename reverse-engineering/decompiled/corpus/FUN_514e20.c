/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514e20; label: FUN_00514e20
 */

float10 FUN_00514e20(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  if ((((param_3 != 0) && (param_5 != 0)) && (param_1 != 0)) &&
     ((int)*(short *)(param_3 + 0x124) ==
      (param_5 - *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x7c)) / 0x5c)) {
    return (float10)1;
  }
  return (float10)0;
}

