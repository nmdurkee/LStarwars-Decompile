/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440ca0; label: FUN_00440ca0
 */

float10 FUN_00440ca0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     (*(char *)(*(int *)(param_3 + 0xd0) + 0x280) != -1)) {
    return (float10)1;
  }
  return (float10)0;
}

