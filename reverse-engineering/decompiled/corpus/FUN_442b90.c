/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442b90; label: FUN_00442b90
 */

float10 FUN_00442b90(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) && (param_3 != 0)) && (*(int *)(param_3 + 0x1b0) == param_5)) {
    return (float10)1;
  }
  return (float10)0;
}

