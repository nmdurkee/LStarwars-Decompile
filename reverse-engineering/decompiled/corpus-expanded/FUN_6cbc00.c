/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cbc00; label: FUN_006cbc00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cbc00(undefined4 *param_1)

{
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    FUN_006c94a0(param_1 + 2,0xff800000);
  }
  return;
}

