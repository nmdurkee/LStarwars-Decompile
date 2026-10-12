/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4426a0; label: FUN_004426a0
 */

float10 FUN_004426a0(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) && (*(int *)(in_stack_00000014 + 4) != 0)) {
    iVar1 = FUN_00500210(*(int *)(in_stack_00000014 + 4));
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

