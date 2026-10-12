/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x442660; label: FUN_00442660
 */

float10 FUN_00442660(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 0) && (*(int *)(in_stack_00000014 + 4) != 0)) &&
     ((*(byte *)(*(int *)(in_stack_00000014 + 4) + 0x88) & 2) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

