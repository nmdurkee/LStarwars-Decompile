/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514aa0; label: FUN_00514aa0
 */

float10 FUN_00514aa0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    return (float10)(*(float *)(*(int *)(param_3 + 0xd0) + 0x60) - *(float *)(param_5 + 0x14));
  }
  return (float10)0;
}

