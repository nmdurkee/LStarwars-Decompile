/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443650; label: FUN_00443650
 */

float10 FUN_00443650(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((*(byte *)(*(int *)(param_3 + 0xd0) + 0xe24) & 1) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

