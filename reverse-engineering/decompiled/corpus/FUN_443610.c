/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443610; label: FUN_00443610
 */

float10 FUN_00443610(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  float10 fVar2;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(int *)(*piVar1 + 0xea4) != 0)) {
    fVar2 = (float10)FUN_005becc0(*(int *)(*piVar1 + 0xea4) + 0x5c,piVar1 + 0x17,0);
    return fVar2;
  }
  return (float10)(float)0x4e6e6b28;
}

