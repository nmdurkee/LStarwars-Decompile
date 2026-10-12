/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440b70; label: FUN_00440b70
 */

float10 FUN_00440b70(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  int *piVar1;
  
  if (((param_5 != 0) ||
      ((((param_3 != 0 && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
        (*piVar1 != 0)) && (param_5 = *piVar1, param_5 != 0)))) &&
     (*(char *)(param_5 + 0x7b5) == '\x1b')) {
    return (float10)1;
  }
  return (float10)0;
}

