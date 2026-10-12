/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46eaa0; label: FUN_0046eaa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0046eaa0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xfc);
  }
  return 0;
}

