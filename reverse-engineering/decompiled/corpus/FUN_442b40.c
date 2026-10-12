/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442b40; label: FUN_00442b40
 */

float10 FUN_00442b40(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (*(char *)(**(int **)(param_3 + 0xd0) + 0x7b5) == '\x1f')) {
    return (float10)0;
  }
  return (float10)1;
}

