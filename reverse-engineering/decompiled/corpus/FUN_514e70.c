/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514e70; label: FUN_00514e70
 */

float10 FUN_00514e70(int param_1)

{
  int in_stack_00000014;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x138c) != 0)) && (in_stack_00000014 != 0)) &&
     ((int)*(short *)(*(int *)(*(int *)(param_1 + 0x138c) + 4) + 0x124) ==
      (in_stack_00000014 - *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x7c)) / 0x5c)) {
    return (float10)1;
  }
  return (float10)0;
}

