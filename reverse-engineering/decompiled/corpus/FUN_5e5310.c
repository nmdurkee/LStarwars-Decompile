/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5310; label: FUN_005e5310
 */

undefined4 FUN_005e5310(int param_1)

{
  if (param_1 < 1) {
    return 0;
  }
  return *(undefined4 *)(DAT_0097157c + -4 + param_1 * 4);
}

