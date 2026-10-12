/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46eb30; label: FUN_0046eb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0046eb30(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x40;
  }
  return 0;
}

