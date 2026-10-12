/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514b60; label: FUN_00514b60
 */

float10 FUN_00514b60(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((*(byte *)(*(int *)(*(int *)(param_3 + 0xe4) + 4) + 0x166) & 1) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

