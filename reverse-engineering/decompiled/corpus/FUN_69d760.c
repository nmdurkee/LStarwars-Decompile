/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69d760; label: FUN_0069d760
 */

undefined8 FUN_0069d760(int param_1)

{
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffffffffffff7d;
  }
  return *(undefined8 *)(param_1 + 0x50);
}

