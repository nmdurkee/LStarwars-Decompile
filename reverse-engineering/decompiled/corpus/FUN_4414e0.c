/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x4414e0; label: FUN_004414e0
 */

float10 FUN_004414e0(void)

{
  int iVar1;
  int in_stack_00000010;
  
  if (((DAT_0093d810 != 0) && (*(char *)(DAT_0093d810 + 0x7b5) == '\v')) &&
     (*(int *)(DAT_0093d810 + 0x798) != 0)) {
    if (in_stack_00000010 == 0) goto LAB_00441516;
    iVar1 = FUN_004f8b10(*(int *)(DAT_0093d810 + 0x798) + 0x40,in_stack_00000010);
    if (iVar1 == 0) goto LAB_00441516;
  }
  if (((DAT_0093d814 != 0) && (*(char *)(DAT_0093d814 + 0x7b5) == '\v')) &&
     (*(int *)(DAT_0093d814 + 0x798) != 0)) {
    if (in_stack_00000010 != 0) {
      iVar1 = FUN_004f8b10(*(int *)(DAT_0093d814 + 0x798) + 0x40,in_stack_00000010);
      if (iVar1 != 0) goto LAB_0044154b;
    }
LAB_00441516:
    return (float10)1;
  }
LAB_0044154b:
  return (float10)0;
}

