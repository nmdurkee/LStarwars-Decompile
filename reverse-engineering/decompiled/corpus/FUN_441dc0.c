/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441dc0; label: FUN_00441dc0
 */

float10 FUN_00441dc0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    return (float10)*(byte *)(**(int **)(param_3 + 0xd0) + 0xe32);
  }
  return (float10)0;
}

