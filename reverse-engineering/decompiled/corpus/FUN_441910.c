/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441910; label: FUN_00441910
 */

float10 FUN_00441910(void)

{
  float fVar1;
  int in_stack_00000014;
  
  if ((((DAT_0093d810 != 0) && (in_stack_00000014 != -1)) &&
      ((*(char *)(DAT_0093d810 + 0x281) != '\0' || (*(char *)(DAT_0093d810 + 0x282) != '\0')))) &&
     ((*(short *)(DAT_0093d810 + 0x27e) == in_stack_00000014 &&
      (fVar1 = *(float *)(*(int *)(*(short *)(DAT_0093d810 + 0x27e) * 0x6c + 0x40 +
                                  *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
      fVar1 < *(float *)(DAT_0093d810 + 0x60) != (fVar1 == *(float *)(DAT_0093d810 + 0x60)))))) {
    return (float10)1;
  }
  return (float10)0;
}

