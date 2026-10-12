/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46eb50; label: FUN_0046eb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_0046eb50(int param_1)

{
  return *(byte *)(param_1 + 0x62) & 1;
}

