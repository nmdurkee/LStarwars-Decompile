/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x441470; label: FUN_00441470
 */

float10 FUN_00441470(void)

{
  int iVar1;
  int in_stack_00000010;
  
  if (((DAT_0093d810 != 0) && (*(char *)(DAT_0093d810 + 0x7b5) == 'a')) &&
     (*(int *)(DAT_0093d810 + 0x798) != 0)) {
    if (in_stack_00000010 == 0) goto LAB_004414a6;
    iVar1 = FUN_004f8b10(*(int *)(DAT_0093d810 + 0x798) + 0x40,in_stack_00000010);
    if (iVar1 == 0) goto LAB_004414a6;
  }
  if (((DAT_0093d814 != 0) && (*(char *)(DAT_0093d814 + 0x7b5) == 'a')) &&
     (*(int *)(DAT_0093d814 + 0x798) != 0)) {
    if (in_stack_00000010 != 0) {
      iVar1 = FUN_004f8b10(*(int *)(DAT_0093d814 + 0x798) + 0x40,in_stack_00000010);
      if (iVar1 != 0) goto LAB_004414db;
    }
LAB_004414a6:
    return (float10)1;
  }
LAB_004414db:
  return (float10)0;
}

