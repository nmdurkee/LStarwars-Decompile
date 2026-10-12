/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e4b00; label: FUN_005e4b00
 */

void FUN_005e4b00(int param_1)

{
  FUN_00601030(param_1);
  *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + 1;
  return;
}

