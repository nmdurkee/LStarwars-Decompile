/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440850; label: FUN_00440850
 */

float10 FUN_00440850(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     ((*(byte *)(**(int **)(param_3 + 0xd0) + 0xeec) & 4) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

