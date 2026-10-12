/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x4417a0; label: FUN_004417a0
 */

float10 FUN_004417a0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) || ((param_3 != 0 && (param_5 = *(int *)(param_3 + 0xd0), param_5 != 0)))) &&
     (*(char *)(param_5 + 0x288) != '\0')) {
    return (float10)1;
  }
  return (float10)0;
}

