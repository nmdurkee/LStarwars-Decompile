/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440dc0; label: FUN_00440dc0
 */

float10 FUN_00440dc0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int *piVar1;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xe4), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (*(short *)(*piVar1 + 0x1064) == param_5)) {
    return (float10)1;
  }
  return (float10)0;
}

