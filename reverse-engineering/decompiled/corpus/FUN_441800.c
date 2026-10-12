/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441800; label: FUN_00441800
 */

float10 FUN_00441800(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if ((param_5 == 0) &&
     (((param_3 == 0 || (*(int **)(param_3 + 0xd0) == (int *)0x0)) ||
      (param_5 = **(int **)(param_3 + 0xd0), param_5 == 0)))) {
    return (float10)0;
  }
  return (float10)*(float *)(param_5 + 0xf10);
}

