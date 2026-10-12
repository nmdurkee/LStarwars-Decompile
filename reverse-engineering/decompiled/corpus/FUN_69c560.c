/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69c560; label: FUN_0069c560
 */

undefined4 FUN_0069c560(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x48) == 0) {
    return 0xffffff7d;
  }
  uVar1 = FUN_006a14a0();
  return uVar1;
}

