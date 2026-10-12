/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440e50; label: FUN_00440e50
 */

float10 FUN_00440e50(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((*(byte *)(*(int *)(param_3 + 0xd0) + 0x1f8) & 5) == 0)) {
    return (float10)1;
  }
  return (float10)0;
}

