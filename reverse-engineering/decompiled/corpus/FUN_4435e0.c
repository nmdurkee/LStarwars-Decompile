/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x4435e0; label: FUN_004435e0
 */

float10 FUN_004435e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(int *)(*piVar1 + 0xea4) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

