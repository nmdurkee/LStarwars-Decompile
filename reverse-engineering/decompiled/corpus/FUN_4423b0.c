/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4423b0; label: FUN_004423b0
 */

/* WARNING: Removing unreachable block (ram,0x004423db) */

float10 FUN_004423b0(void)

{
  float10 fVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 == -1) {
    fVar1 = (float10)0;
  }
  else {
    fVar1 = (float10)(*(uint *)(in_stack_00000014 * 0x2e28 + 0x2800 + DAT_0087b2cc) & 1);
  }
  return fVar1;
}

