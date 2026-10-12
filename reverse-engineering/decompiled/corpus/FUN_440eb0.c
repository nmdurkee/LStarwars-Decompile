/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440eb0; label: FUN_00440eb0
 */

float10 FUN_00440eb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((*(byte *)(*(int *)(param_3 + 0xd0) + 0x1f8) & 4) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

