/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441890; label: FUN_00441890
 */

float10 FUN_00441890(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (*(int *)(**(int **)(param_3 + 0xd0) + 0xec0) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

