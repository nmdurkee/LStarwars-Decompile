/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4b00; label: FUN_005e4b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e4b00(int param_1)

{
  FUN_00601030(param_1);
  *(short *)(param_1 + 0x2c0) = *(short *)(param_1 + 0x2c0) + 1;
  return;
}

