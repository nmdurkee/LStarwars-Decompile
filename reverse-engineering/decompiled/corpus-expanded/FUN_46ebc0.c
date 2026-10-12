/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46ebc0; label: FUN_0046ebc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046ebc0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0xffffffff;
    param_2[2] = 0xffffffff;
  }
  return;
}

