/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x442ec0; label: FUN_00442ec0
 */

float10 FUN_00442ec0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
      (*(char *)(*(int *)(param_3 + 0xd0) + 0x280) == -1)) && (*(char *)(param_3 + 0x138) == -1)) {
    return (float10)1;
  }
  return (float10)0;
}

