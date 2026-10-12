/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442dc0; label: FUN_00442dc0
 */

float10 FUN_00442dc0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && ((*(uint *)(param_3 + 0x1e8) & 0x400000) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

